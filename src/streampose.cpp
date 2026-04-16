#include "streampose.hpp"
#include "zeropose.hpp"
#include "capturepoint.hpp"
#include "clearfile.hpp"
#include "updatepose.hpp"

void streamPose() {
    while (true) {
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

        std::cout << "         Toggles          " << std::endl;
		std::cout << "--------------------------" << std::endl;

		std::cout << "zeroing poseA: " << (zeroingPoseA ? "true" : "false") << std::endl;
		std::cout << "clearing file: " << (clearingFile ? "true" : "false") << std::endl;
		std::cout << "capturing poseB (primitive): " << (capturingPoint ? "true" : "false") << std::endl;
		std::cout << "capturing poseB (advanced): " << (advancedCapturingPoint ? "true" : "false") << std::endl;
    }
}