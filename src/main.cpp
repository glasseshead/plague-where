#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "objects.hpp"
#include "tasks.hpp"
#include "streampose.hpp"
#include "updatepose.hpp"
#include "zeropose.hpp"

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
	chassis.calibrate();

	// zero the current pose
	chassis.setPose(0, 0, 0);
	PoseA = chassis.getPose();
}

void autonomous() {
}

void opcontrol() {
	while (true) {
		updatePose();
		updateZeroPoseA();

		// for those who aren't familiar with aircraft controls:
		// throttle is forward power
		// rudder is your yaw/turn
		int throttle = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rudder = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // standard movement
        chassis.arcade(throttle, rudder);

		// standard wait 10 ms
		pros::delay(10);  
	}
}