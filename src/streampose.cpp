#include "streampose.hpp"
#include "zeropose.hpp"
#include "capturepoint.hpp"
#include "clearfile.hpp"
#include "updatepose.hpp"

void streamPose() {
    while (true) {
        pros::lcd::set_text(0, "Plague? Where?");

        // Start pose
        pros::lcd::set_text(
            1,
            "Sx:" + std::to_string(startPoseX) +
            " Sy:" + std::to_string(startPoseY) +
            " St:" + std::to_string(startPoseThetaDeg)
        );

        // Current pose
        pros::lcd::set_text(
            2,
            "Cx:" + std::to_string(currPoseX) +
            " Cy:" + std::to_string(currPoseY) +
            " Ct:" + std::to_string(currPoseThetaDeg)
        );

        // Difference
        pros::lcd::set_text(
            3,
            "Dx:" + std::to_string(diffPoseX) +
            " Dy:" + std::to_string(diffPoseY) +
            " Dt:" + std::to_string(diffPoseThetaDeg)
        );

		// Errors
        pros::lcd::set_text(
            4,
            " dErr:" + std::to_string(distanceError) +
            " hErr:" + std::to_string(headingError)
        );

        // Toggles
        pros::lcd::set_text(
            5,
            std::string("ZpA") + (zeroingPoseA ? "1" : "0") +
            " Clr:" + (clearingFile ? "1" : "0") +
            " CpP:" + (capturingPoint ? "1" : "0") +
            " CpA:" + (advancedCapturingPoint ? "1" : "0")
        );

        pros::delay(50);
    }
}