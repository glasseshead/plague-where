#include "streampose.hpp"

void updatePose() {
    lemlib::update();

    // current pose
    poseB = chassis.getPose();

    // set values for start poses A
    startPoseX = poseA.x;
    startPoseY = poseA.y;
    startPoseThetaRad = poseA.theta;
    startPoseThetaDeg = poseA.theta * 180.0 / M_PI;

    // set values for current poses B
    currPoseX = poseB.x;
    currPoseY = poseB.y;
    currPoseThetaRad = poseB.theta;
    currPoseThetaDeg = poseB.theta * 180.0 / M_PI;

    // difference pose
    lemlib::Pose poseD = poseA - poseB;
    currPoseX = poseD.x;
    currPoseY = poseD.y;
    currPoseThetaRad = poseD.theta;
    currPoseThetaDeg = poseD.theta * 180.0 / M_PI;

    // distance error
    distanceError = poseA.distance(poseB);

    // heading error
    headingError = poseA.theta - poseB.theta;

    while (headingError > M_PI) {
        headingError -= 2 * M_PI;
    }

    while (headingError < -M_PI) {
        headingError += 2 * M_PI;
    }
}