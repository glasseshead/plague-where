#include "objects.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "pros/adi.hpp"
#include "pros/misc.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

// TODO: Configure your pose data accuracy.
// Defaults to 3
std::int32_t poseDataAcc = 3;

// TODO: Configure your ports based on your robot.
std::int8_t LEFT_MG_0 = 0;
std::int8_t LEFT_MG_1 = 0;
std::int8_t LEFT_MG_2 = 0;
std::int8_t LEFT_MG_3 = 0;

std::int8_t RIGHT_MG_0 = 0;
std::int8_t RIGHT_MG_1 = 0;
std::int8_t RIGHT_MG_2 = 0;
std::int8_t RIGHT_MG_3 = 0;

std::int8_t INTAKE_MOTOR = 0;
std::int8_t SCORE_MOTOR = 0;

std::int8_t IMU_SENSOR = 0;

// TODO: Configure your controls to your preference.
// Default Controls:
// zeroPoseA = L1;
// clearFile = L2;
// capturePointPrimitive = R1;
// capturePointAdvanced = R2;

// controls mapping
pros::controller_digital_e_t CONTROL_zeroPoseA = pros::E_CONTROLLER_DIGITAL_L1;
pros::controller_digital_e_t CONTROL_clearFile = pros::E_CONTROLLER_DIGITAL_L2;
pros::controller_digital_e_t CONTROL_capturePoint = pros::E_CONTROLLER_DIGITAL_R1;
pros::controller_digital_e_t CONTROL_advancedCapturePoint = pros::E_CONTROLLER_DIGITAL_R2;

// motor groups (3WD)
pros::MotorGroup left_mg({LEFT_MG_0, LEFT_MG_1, LEFT_MG_2}, pros::v5::MotorGears::blue);
pros::MotorGroup right_mg({RIGHT_MG_0, RIGHT_MG_1, RIGHT_MG_2}, pros::v5::MotorGears::blue);

// motor groups (4WD)
// pros::MotorGroup left_mg({LEFT_MG_0, LEFT_MG_1, LEFT_MG_2, LEFT_MG_3}, pros::v5::MotorGears::blue);
// pros::MotorGroup right_mg({RIGHT_MG_0, RIGHT_MG_1, RIGHT_MG_2, RIGHT_MG_3}, pros::v5::MotorGears::blue);

// imu mapping
pros::Imu imu(IMU_SENSOR);

// pose data

// calibrate poses
lemlib::Pose PoseA(0, 0, 0);
lemlib::Pose PoseB(0, 0, 0);

// reset all pose values
double startPoseX = 0;
double startPoseY = 0;
double startPoseThetaRad = 0;
double startPoseThetaDeg = 0;

double currPoseX = 0;
double currPoseY = 0;
double currPoseThetaRad = 0;
double currPoseThetaDeg = 0;

double diffPoseX = 0;
double diffPoseY = 0;
double diffPoseThetaRad = 0;
double diffPoseThetaDeg = 0;

// reset misc values
double distanceError = 0;
double headingError = 0;

// TODO: Configure your drivetrain settings.
// drivetrain mapping
lemlib::Drivetrain drivetrain(&left_mg,
                              // left motor group

                              &right_mg, 
                              // right motor group

                              0,
                              // track width 

                              lemlib::Omniwheel::NEW_4,
                              // wheel type 

                              0, 
                              // drivetrain rpm

                              0
                              // horizontal drift
);

// TODO: Configure your tracking wheel settings.
// tracking wheel mapping
lemlib::TrackingWheel vertical_tracking_wheel(
    &left_mg,
    // motor/encoder

    lemlib::Omniwheel::NEW_2,
    // wheel type

    0,
    // offset

    0
    // drivetrain rpm
);

// tracking wheel mapping
lemlib::TrackingWheel horizontal_tracking_wheel(
    &right_mg,
    // motor/encoder
    
    lemlib::Omniwheel::NEW_2,
    // wheel type
    
    0,
    // offset

    0
    // drivetrain rpm
);

// odom sensors
lemlib::OdomSensors sensors(&vertical_tracking_wheel, 
                            // vertical tracking wheel 1

                            nullptr, 
                            // vertical tracking wheel 2

                            &horizontal_tracking_wheel, 
                            // horizontal tracking wheel 1

                            nullptr, 
                            // horizontal tracking wheel 2

                            &imu 
                            // inertia sensor
);

// TODO: Configure your lateral and angular controllers.
// lateral controller settings
lemlib::ControllerSettings lateral_controller(2, 
                                              // proportional gain (kP)
                                              0, 
                                              // integral gain (kI)

                                              10, 
                                              // derivative gain (kD)

                                              0, 
                                              // antiwindup

                                              0, 
                                              // small error range (in)

                                              0, 
                                              // small error range timeout (ms)

                                              0, 
                                              // large error range (in)

                                              0, 
                                              // large error range timeout (ms)

                                              0 
                                              // maximum acceleration (slew)
);

// angular controller settings
lemlib::ControllerSettings angular_controller(2, 
                                              // proportional gain (kP)

                                              0, 
                                              // integral gain (kI)

                                              10, 
                                              // derivative gain (kD)

                                              3, 
                                              // anti windup

                                              1, 
                                              // small error range (degrees)

                                              100, 
                                              // small error range timeout (ms)

                                              3, 
                                              // large error range (degrees)

                                              500, 
                                              // large error range timeout (ms)

                                              0 
                                              // maximum acceleration (slew)
);

// chassis mapping
lemlib::Chassis chassis(drivetrain, 
                        // drivetrain

                        lateral_controller, 
                        // lateral PID

                        angular_controller, 
                        // angular PID

                        sensors 
                        // odom
);
