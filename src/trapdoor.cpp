#include "trapdoor.hpp"
#include "score.hpp"

void runTrapdoor() {
    while (true) {
        // based on our current scoring state, we toggle it on or off
        switch (scoreState) {
            // trapdoor closed (intaking)
            case 0:
                trapdoorPiston.set_value(false);
            // trapdoor opened (scoring)
            case 1:
                trapdoorPiston.set_value(true);
        }
    }
}