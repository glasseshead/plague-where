#include "lemlib/api.hpp" // IWYU pragma: keep
#include "objects.hpp"
#include "capturepoint.hpp"

// was primitive capture point toggled just now?
// no, so it is false
bool primitiveCapturePointPressed = false;
int primitiveCapturePointState = 0;

// setting primitive capturing point state for toggle output to off
bool primitveCapturingPoint = false;

// was advanced capture point toggled just now?
// no, so it is false
bool advancedCapturingPoint = false;
int advancedCapturePointState = 0;

// setting advanced capturing point state for toggle output to off
bool advancedCapturingPoint = false;

void updatePrimitiveCapturePoint() {
    // state = 0: not capturing (primitive)
    // state = 1: capturing (primitive)

    // if capture point control is pressed
    if (controller.get_digital(CONTROL_capturePoint)) {
        if (!primitiveCapturePointPressed) {
            // if toggled to not capturing, turn it to capturing
            if(primitiveCapturePointState == 0) {
                primitiveCapturePointState = 1;
            }

            // if toggled to capturing, turn it to not capturing
            else {
                primitiveCapturePointState = 0;
            }
        }
        // capture point to file was just toggled now
        primitiveCapturePointPressed = true;

    } 
    // capture point to file was not toggled just now
    else {
        primitiveCapturePointPressed = false;
    }
}

void updateAdvancedCapturePoint() {
    // state = 0: not capturing (advanced)
    // state = 1: capturing (advanced)

    // if capture point control is pressed
    if (controller.get_digital(CONTROL_advancedCapturePoint)) {
        if (!advancedCapturingPoint) {
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
        advancedCapturingPoint = true;

    } 
    // capture point to file was not toggled just now
    else {
        advancedCapturingPoint = false;
    }
}

void runPrimitiveCapturePoint() {
    while (true) {
        // based on our capture point state, we toggle it to on or off
        switch (primitiveCapturePointState) {
            // point not capturing
            case 0:
                // we are currently not capturing point so it's false
                primitveCapturingPoint = false;
                break;

            // point capturing
            case 1:
                // we are currently capturing point so it's true
                primitveCapturingPoint = true;

                // open file in append mode
                FILE* usd_file_write = fopen("/usd/raw_poses.txt", "a");

                // if file is valid
                if (usd_file_write != NULL) {
                    // f-string
                    fprintf(usd_file_write,
                        "x: %f y: %f theta (rad): %f theta (deg): %f\n",
                        currPoseX,
                        currPoseY,
                        currPoseThetaRad,
                        currPoseThetaDeg
                    );

                    fclose(usd_file_write);
                }

                // to set primitveCapturingPointState returner to false in the switch case
                primitiveCapturePointState = 0;
                break;
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
                break;

            // point capturing
            case 1:
                // we are currently caputring point so it's true
                advancedCapturingPoint = true;

                // open file in append mode
                FILE* usd_file_write = fopen("/usd/m2pose_poses.txt", "a");

                // if file is valid
                if (usd_file_write != NULL) {
                    // f-string
                    fprintf(usd_file_write,
                        "chassis.moveToPose(%f , %f , %f , TIMEOUT);\n",
                        currPoseX,
                        currPoseY,
                        currPoseThetaDeg
                    );

                    fclose(usd_file_write);
                }

                // to set primitveCapturingPointState returner to false in the switch case
                advancedCapturePointState = 0;
                break;
        }
    }
}