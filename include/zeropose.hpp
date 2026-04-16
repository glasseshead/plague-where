#pragma once
#include "main.h"
#include "objects.hpp"

extern bool zeroPoseAPressed;
extern int zeroPoseAState;
extern bool zeroingPoseA;

// initializing update and run functions for zero pose
void updateZeroPoseA();
void runZeroPose();