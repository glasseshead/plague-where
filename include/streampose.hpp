#pragma once
#include "main.h"
#include "objects.hpp"

// intake state
extern int intakeState;

// pose variables
extern lemlib::Pose PoseA;
extern lemlib::Pose PoseB;
extern lemlib::Pose poseD;

// pose pos variables
extern double startPoseX;
extern double startPoseY;
extern double startPoseThetaRad;
extern double startPoseThetaDeg;

extern double currPoseX;
extern double currPoseY;
extern double currPoseThetaRad;
extern double currPoseThetaDeg;

extern double diffPoseX;
extern double diffPoseY;
extern double diffPoseThetaRad;
extern double diffPoseThetaDeg;

// distance error
extern double distanceError;

// heading error
extern double headingError;

// initializing update function for pose
void updatePose();