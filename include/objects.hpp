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
extern pros::controller_digital_e_t scoreControl;
extern pros::controller_digital_e_t outtakeControl;
extern pros::controller_digital_e_t intakeControl;
extern pros::controller_digital_e_t descoreControl;
extern pros::controller_digital_e_t matchloaderControl;
extern pros::controller_digital_e_t midGoalControl;
extern pros::controller_digital_e_t trapdoorControl;

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