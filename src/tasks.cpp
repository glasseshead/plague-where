#include "lemlib/api.hpp" // IWYU pragma: keep
#include "tasks.hpp"
#include "streampose.hpp"
#include "updatepose.hpp"
#include "zeropose.hpp"
#include "clearfile.hpp"
#include "capturepoint.hpp"

void initTasks() {
    pros::Task streamPoseTask(streamPose, "stream pose task");
    pros::Task runZeroPoseTask(runZeroPose, "zero pose task");
    pros::Task runClearFileTask(runClearFile, "clear file task");
    pros::Task runCapturePointTask(runCapturePoint, "run capture point task");
    pros::Task runAdvancedCapturePointTask(runAdvancedCapturePoint, "run capture point task");
}