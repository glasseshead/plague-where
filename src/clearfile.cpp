#include "lemlib/api.hpp" // IWYU pragma: keep
#include "objects.hpp"
#include "clearfile.hpp"

// was clear file toggled just now?
// no, so it is false
bool clearFilePressed = false;
int clearFileState = 0;

// setting clearing file state for toggle output to off
bool clearingFile = false;

void updateClearFile() {
    // state = 0: not clearing
    // state = 1: clearing

    // if clear file control is pressed
    if (controller.get_digital(CONTROL_clearFile)) {
        if (!clearFilePressed) {
            // if toggled to not clearing, turn it to clearing
            if(clearFileState == 0) {
                clearFileState = 1;
            }

            // if toggled to clearing, turn it to not clearing
            else {
                clearFileState = 0;
            }
        }
        // clear file was just toggled now
        clearFilePressed = true;

    } 
    // clear file was not toggled just now
    else {
        clearFilePressed = false;
    }
}

void runClearFile() {
    while (true) {
        // based on our clear file state, we toggle it to zero or to stay
        switch (clearFileState) {
            // file not clearing
            case 0:
                // we are currently not clearing file so it's false
                clearingFile = false;
                break;

            // file clearing
            case 1:
                // we are currently clearing file so it's true
                clearingFile = true;

                // open file in append mode
                FILE* raw_file = fopen("/usd/raw_poses.txt", "w");

                // if file is valid
                if (raw_file != NULL) {
                    // clear file by close method
                    fclose(raw_file);
                }

                // open file in append mode
                FILE* m2_file = fopen("/usd/m2pose_poses.txt", "w");

                // if file is valid
                if (m2_file != NULL) {
                    // clear file by close method
                    fclose(m2_file);
                }

                // to set clearFileState returner to false in the switch case
                clearFileState = 0;
                break;
        }
    }
}