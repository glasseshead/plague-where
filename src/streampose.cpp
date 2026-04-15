#include "streampose.hpp"

// calibrate poses
lemlib::Pose PoseA(0, 0, 0);
lemlib::Pose PoseB(0, 0, 0);

// reset all pose values
double startPoseX = 0;
double startPoseY = 0;
double startPoseThetaRad = 0;
double startPoseThetaDeg = 0;

double currPoseX = 0;
double currPoseY = 0;
double currPoseThetaRad = 0;
double currPoseThetaDeg = 0;

double diffPoseX = 0;
double diffPoseY = 0;
double diffPoseThetaRad = 0;
double diffPoseThetaDeg = 0;

// reset misc values
double distanceError = 0;
double headingError = 0;

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