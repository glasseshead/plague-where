#pragma once
#include "main.h"
#include "objects.hpp"
#include <iostream>
#include <fstream>

// initialize primitive capture point variables
extern bool primitiveCapturePointPressed;
extern int primitiveCapturePointState;

// initializing primitive capturing point state for toggle output
extern bool primitveCapturingPoint;

// initialize advanced capture point variables
extern bool advancedCapturingPoint;
extern int advancedCapturePointState;

// initializing advanced capturing point state for toggle output
extern bool advancedCapturingPoint;

// initializing update and run functions for capture point
void updatePrimitiveCapturePoint();
void runPrimitiveCapturePoint();

void updateAdvancedCapturePoint();
void runAdvancedCapturePoint();