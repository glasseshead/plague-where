#pragma once
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/adi.hpp"

// intake motor
extern pros::Motor intake;

// score motor
extern pros::Motor score;

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

// descore piston
extern pros::adi::AnalogOut descorePiston;

// mid goal piston
extern pros::adi::AnalogOut midGoalPiston;

// matchloader pistons
extern pros::adi::AnalogOut matchLoaderPistons;

// trapdoor piston
extern pros::adi::AnalogOut trapdoorPiston;

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

// intake motor port
extern std::int8_t INTAKE_MOTOR;

// score motor port
extern std::int8_t SCORE_MOTOR;

// descore piston port
extern char DESCORE_PISTON;

// mid goal piston port
extern char MID_GOAL_PISTON;

// trapdoor piston port
extern char TRAPDOOR_PISTON;

// matchloader pistons port
extern char MATCHLOADER_PISTONS;

// imu port
extern std::int8_t IMU;