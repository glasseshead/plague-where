#include "updatepose.hpp"

void updatePose() {
    // current Pose
    PoseB = chassis.getPose();

    // set values for start Poses A
    startPoseX = PoseA.x;
    startPoseY = PoseA.y;
    startPoseThetaRad = PoseA.theta;
    startPoseThetaDeg = PoseA.theta * 180.0 / M_PI;

    // set values for current Poses B
    currPoseX = PoseB.x;
    currPoseY = PoseB.y;
    currPoseThetaRad = PoseB.theta;
    currPoseThetaDeg = PoseB.theta * 180.0 / M_PI;

    // difference Pose
    lemlib::Pose PoseD = PoseA - PoseB;
    currPoseX = PoseD.x;
    currPoseY = PoseD.y;
    currPoseThetaRad = PoseD.theta;
    currPoseThetaDeg = PoseD.theta * 180.0 / M_PI;

    // distance error
    distanceError = PoseA.distance(PoseB);

    // heading error
    headingError = PoseA.theta - PoseB.theta;

    while (headingError > M_PI) {
        headingError -= 2 * M_PI;
    }

    while (headingError < -M_PI) {
        headingError += 2 * M_PI;
    }
}