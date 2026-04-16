#include "zeropose.hpp"

// was zero pose toggled just now?
// no, so it is false
bool zeroPoseAPressed = false;
int zeroPoseAState = 0;
bool zeroingPoseA = false;

void updateZeroPoseA() {
    // state = 0: down
    // state = 1: up

    // if matchloader control is pressed
    if (controller.get_digital(CONTROL_zeroPoseA)) {
        if (!zeroPoseAPressed) {
            // if pose is toggled to not zeroing, turn it to zeroing
            if(zeroPoseAState == 0) {
                zeroPoseAState = 1;
            }

            // if pose is toggled to is zeroeing, turn it to not zeroeing
            else {
                zeroPoseAState = 0;
            }
        }
        // zero pose was just toggled now
        zeroPoseAPressed = true;

    } 
    // zero pose was not toggled just now
    else {
        zeroPoseAPressed = false;
    }
}

void runZeroPose() {
    while (true) {
        // based on our zero pose state, we toggle it to zero or to stay
        switch (zeroPoseAState) {
            // pose not zeroed
            case 0:
                zeroingPoseA = false;
            // pose zeroed
            case 1:
                zeroingPoseA = true;
                chassis.setPose(0, 0, 0);
                std::ofstream outputFile("raw_poses.txt");
                outputFile << "ZEROED POSE" << currPoseX << std::endl;
                outputFile.close();
                PoseA = chassis.getPose();
        }
    }
}