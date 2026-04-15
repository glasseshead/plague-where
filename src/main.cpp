#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "objects.hpp"
#include "tasks.hpp"
#include "streampose.hpp"

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;

	if (pressed) {
		pros::lcd::set_text(2, "Center Button is Pressed");
	} 

	else {
		pros::lcd::clear_line(2);
	}
}

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "plague? where?");

	pros::lcd::register_btn1_cb(on_center_button);

	initTasks();
}

void disabled() {

}

void competition_initialize() {
	lemlib::init();

	// zero the current pose
	chassis.setPose(0, 0, 0);
	poseA = chassis.getPose();
}

void autonomous() {
}

void opcontrol() {
	while (true) {
		updatePose();

		// ANSI escape code for cls
		// endl for better real time logging
		std::cout << "\033[H";

		// each pose data comes with 3 decimal precision default. 
		// if you want to, you can tune it in objects.cpp
		std::cout << std::fixed << std::setprecision(poseDataAcc);

		std::cout << "        Start Pose        " << std::endl;
		std::cout << "--------------------------" << std::endl;

		std::cout << "x: " << startPoseX
         		  << ", y: " << startPoseY
          		  << ", theta (radians): " << startPoseThetaRad
          		  << ", theta (degrees): " << startPoseThetaDeg
        		  << std::endl;

		std::cout << "       Current Pose       " << std::endl;
		std::cout << "--------------------------" << std::endl;

		std::cout << "x: " << currPoseX
         		  << ", y: " << currPoseY
          		  << ", theta (radians): " << currPoseThetaRad
          		  << ", theta (degrees): " << currPoseThetaDeg
        		  << std::endl;

		std::cout << "        Difference        " << std::endl;
		std::cout << "--------------------------" << std::endl;

		std::cout << "x: " << diffPoseX
         		  << ", y: " << diffPoseY
          		  << ", theta (radians): " << diffPoseThetaRad
          		  << ", theta (degrees): " << diffPoseThetaDeg
        		  << std::endl;
		
		std::cout << "     Additional Data      " << std::endl;
		std::cout << "--------------------------" << std::endl;

		std::cout << "distance error: " << distanceError << std::endl;
		std::cout << "heading error: " << headingError << std::endl;

		// standard wait 10 ms
		pros::delay(10);  
	}
}