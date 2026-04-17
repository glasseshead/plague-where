#pragma once
#include "main.h"
#include "objects.hpp"
#include <iostream>
#include <fstream>

// initializing clear file variables
extern bool clearFilePressed;
extern int clearFileState;

// initializing clearing file state for toggle output
extern bool clearingFile;

// initializing update and run functions for clear file
void updateClearFile();
void runClearFile();