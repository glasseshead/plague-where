#pragma once
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/adi.hpp"

// drivetrain and chassis
extern lemlib::Drivetrain drivetrain;
extern lemlib::Chassis chassis;

// controller
extern pros::Controller controller;

// drive motor groups
extern pros::MotorGroup left_mg;
extern pros::MotorGroup right_mg;

// odom sensors
extern lemlib::OdomSensors sensors;

// lateral and angular controls
extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;

// pose data accuracy
extern std::int32_t poseDataAcc;

// controls
extern pros::controller_digital_e_t CONTROL_zeroPoseA;
extern pros::controller_digital_e_t CONTROL_clearFile;
extern pros::controller_digital_e_t CONTROL_capturePoint;

// drivetrain motor ports
extern std::int8_t LEFT_MG_0;
extern std::int8_t LEFT_MG_1;
extern std::int8_t LEFT_MG_2;
extern std::int8_t LEFT_MG_3;

extern std::int8_t RIGHT_MG_0;
extern std::int8_t RIGHT_MG_1;
extern std::int8_t RIGHT_MG_2;
extern std::int8_t RIGHT_MG_3;

// imu port
extern std::int8_t IMU;

// pose variables
extern lemlib::Pose PoseA;
extern lemlib::Pose PoseB;
extern lemlib::Pose poseD;

// pose pos variables
extern double startPoseX;
extern double startPoseY;
extern double startPoseThetaRad;
extern double startPoseThetaDeg;

extern double currPoseX;
extern double currPoseY;
extern double currPoseThetaRad;
extern double currPoseThetaDeg;

extern double diffPoseX;
extern double diffPoseY;
extern double diffPoseThetaRad;
extern double diffPoseThetaDeg;

// distance error
extern double distanceError;

// heading error
extern double headingError;