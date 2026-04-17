#include "zeropose.hpp"

// was zero pose toggled just now?
// no, so it is false
bool zeroPoseAPressed = false;
int zeroPoseAState = 0;

// setting zeroing starting position (poseA) state for toggle output to off
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
                // we are currently not zeroing starting pose (poseA) so it's false
                zeroingPoseA = false;
                break;

            // pose zeroed
            case 1:
                // we are currently zeroing starting pose (poseA) so it's true
                zeroingPoseA = true;
                
                // zeroing pose
                chassis.setPose(0, 0, 0);

                // open file in append mode
                FILE* raw_file = fopen("/usd/raw_poses.txt", "a");

                // if file is valid
                if (raw_file != NULL) {
                    // write that file is zeroed (primitive)
                    fprintf(raw_file, "ZEROED POSE\n");
                    fclose(raw_file);
                }

                // open file in append mode
                FILE* m2_file = fopen("/usd/m2pose_poses.txt", "a");
                
                // if file is valid
                if (m2_file != NULL) {
                    // write code for zero position (advanced)
                    fprintf(m2_file, "chassis.setPose(0, 0, 0);\n");
                    fclose(m2_file);
                }
                
                // set poseA to (0, 0, 0)
                PoseA = chassis.getPose();

                // to set zeroingPoseAState returner to false in the switch case
                zeroPoseAState = 0;
                break;
        }
    }
}