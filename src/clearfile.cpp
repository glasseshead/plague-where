#include "lemlib/api.hpp" // IWYU pragma: keep
#include "objects.hpp"
#include "clearfile.hpp"

// was clear file toggled just now?
// no, so it is false
bool clearFilePressed = false;
int clearFileState = 0;
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
                clearingFile = false;
            // file clearing
            case 1:
                clearingFile = true;
                std::ofstream outputFile("raw_poses.txt", std::ios::trunc); 
                outputFile.close();
                clearFileState = 0;
        }
    }
}