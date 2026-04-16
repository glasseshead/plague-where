#pragma once
#include "main.h"
#include "objects.hpp"
#include <iostream>
#include <fstream>

extern bool capturePointPressed;
extern int capturePointState;
extern bool capturingPoint;

extern bool advancedCapturePointPressed;
extern int advancedCapturePointState;
extern bool advancedCapturingPoint;

// initializing update and run functions for capture point
void updateCapturePoint();
void runCapturePoint();
void updateAdvancedCapturePoint();
void runAdvancedCapturePoint();