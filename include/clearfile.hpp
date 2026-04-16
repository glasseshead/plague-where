#pragma once
#include "main.h"
#include "objects.hpp"
#include <iostream>
#include <fstream>

extern bool clearFilePressed;
extern int clearFileState;
extern bool clearingFile;

// initializing update and run functions for clear file
void updateClearFile();
void runClearFile();