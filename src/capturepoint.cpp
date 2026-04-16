#include "lemlib/api.hpp" // IWYU pragma: keep
#include "objects.hpp"
#include "capturepoint.hpp"

// was clear file toggled just now?
// no, so it is false
bool capturePointPressed = false;
int capturePointState = 0;
bool capturingPoint = false;

bool advancedCapturePointPressed = false;
int advancedCapturePointState = 0;
bool advancedCapturingPoint = false;

void updateCapturePoint() {
    // state = 0: not capturing
    // state = 1: capturing

    // if capture point control is pressed
    if (controller.get_digital(CONTROL_capturePoint)) {
        if (!capturePointPressed) {
            // if toggled to not capturing, turn it to capturing
            if(capturePointState == 0) {
                capturePointState = 1;
            }

            // if toggled to capturing, turn it to not capturing
            else {
                capturePointState = 0;
            }
        }
        // capture point to file was just toggled now
        capturePointPressed = true;

    } 
    // capture point to file was not toggled just now
    else {
        capturePointPressed = false;
    }
}

void updateAdvancedCapturePoint() {
    // state = 0: not capturing
    // state = 1: capturing

    // if capture point control is pressed
    if (controller.get_digital(CONTROL_advancedCapturePoint)) {
        if (!advancedCapturePointPressed) {
            // if toggled to not capturing, turn it to capturing
            if(advancedCapturePointState == 0) {
                advancedCapturePointState = 1;
            }

            // if toggled to capturing, turn it to not capturing
            else {
                advancedCapturePointState = 0;
            }
        }
        // capture point to file was just toggled now
        advancedCapturePointPressed = true;

    } 
    // capture point to file was not toggled just now
    else {
        advancedCapturePointPressed = false;
    }
}

void runCapturePoint() {
    while (true) {
        // based on our capture point state, we toggle it to on or off
        switch (capturePointState) {
            // point not capturing
            case 0:
                capturingPoint = false;
            // point capturing
            case 1:
                capturingPoint = true;
                std::ofstream outputFile("raw_poses.txt");
                outputFile << "x: " << currPoseX
                           << " y: " << currPoseY
                           << " theta (rad): " << currPoseThetaRad
                           << " theta (deg): " << currPoseThetaDeg
                           << std::endl;
                outputFile.close();
                capturePointState = 0;
        }
    }
}

void runAdvancedCapturePoint() {
    while (true) {
        // based on our capture point state, we toggle it to on or off
        switch (advancedCapturePointState) {
            // point not capturing
            case 0:
                advancedCapturingPoint = false;
            // point capturing
            case 1:
                advancedCapturingPoint = true;
                std::ofstream outputFile("raw_poses.txt");
                outputFile << "chassis.moveToPose(" << currPoseX
                           << " ,  " << currPoseY
                           << " , " << currPoseThetaDeg
                           << " , TIMEOUT);"
                           << std::endl;
                outputFile.close();
                advancedCapturePointState = 0;
        }
    }
}