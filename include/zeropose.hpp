#pragma once
#include "main.h"
#include "objects.hpp"
#include <fstream>

// initialize zero starting pose (poseA) variables
extern bool zeroPoseAPressed;
extern int zeroPoseAState;

// initializing zeroing starting pose (poseA) state for toggle output
extern bool zeroingPoseA;

// initializing update and run functions for zero starting pose (poseA)
void updateZeroPoseA();
void runZeroPose();