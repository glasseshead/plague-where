#include "lemlib/api.hpp" // IWYU pragma: keep
#include "tasks.hpp"
#include "streampose.hpp"
#include "updatepose.hpp"
#include "zeropose.hpp"
#include "clearfile.hpp"

void initTasks() {
    pros::Task streamPoseTask(streamPose, "stream pose task");
    pros::Task runZeroPoseTask(runZeroPose, "zero pose task");
    pros::Task runClearFileTask(runClearFile, "clear file task");
}