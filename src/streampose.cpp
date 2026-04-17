#include "streampose.hpp"
#include "zeropose.hpp"
#include "capturepoint.hpp"
#include "clearfile.hpp"
#include "updatepose.hpp"

// because stream pose is only to acquire values,
// it has no values of its own. therefore there is
// no need to set new variables.

void streamPose() {
    while (true) {
        // Plague? Where? indicator
        pros::lcd::set_text(0, "Plague? Where?");

        // Start pose
        pros::lcd::set_text(
            1,
            // Starting pose x (poseA x)
            "Sx:" + std::to_string(startPoseX) +
            // Starting pose y (poseA y)
            " Sy:" + std::to_string(startPoseY) +
            // Starting pose theta (poseA theta)
            " St:" + std::to_string(startPoseThetaDeg)
        );

        // Current pose
        pros::lcd::set_text(
            2,
            // Current pose x (poseB x)
            "Cx:" + std::to_string(currPoseX) +
            // Current pose y (poseB y)
            " Cy:" + std::to_string(currPoseY) +
            // Current pose theta (poseB theta)
            " Ct:" + std::to_string(currPoseThetaDeg)
        );

        // Difference
        pros::lcd::set_text(
            3,
            // Delta pose x (poseD x)
            "Dx:" + std::to_string(diffPoseX) +
            // Delta pose y (poseD y)
            " Dy:" + std::to_string(diffPoseY) +
            // Delta pose theta (poseD theta)
            " Dt:" + std::to_string(diffPoseThetaDeg)
        );

		// Errors
        pros::lcd::set_text(
            4,
            // Distance error
            " dErr:" + std::to_string(distanceError) +
            // Heading error
            " hErr:" + std::to_string(headingError)
        );

        // Toggles
        pros::lcd::set_text(
            5,
            // Zero Pose A toggle indicator
            std::string("ZpA") + (zeroingPoseA ? "1" : "0") +
            // Clear File toggle indicator
            " Clr:" + (clearingFile ? "1" : "0") +
            // Capture Point (Primitive) toggle indicator
            " CpP:" + (primitveCapturingPoint ? "1" : "0") +
            // Capture Point (Advanced) toggle indicator
            " CpA:" + (advancedCapturingPoint ? "1" : "0")
        );
    }
}