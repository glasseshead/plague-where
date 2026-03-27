#include "trapdoor.hpp"
#include "score.hpp"

// reset trapdoor values

// was trapdoor toggled just now?
// no, so it is false
bool trapdoorPressed = false;
int trapdoorState = 0;

void updateTrapdoor() {
    // state = 0: down
    // state = 1: up

    // if trapdoor control is pressed
    if (controller.get_digital(trapdoorControl)) {
        if (!trapdoorPressed) {
            // if trapdoor is down put it up
            if(trapdoorState == 0) {
                trapdoorState = 1;
            }

            // if trapdoor is up put it down
            else {
                trapdoorState = 0;
            }
        }
        // trapdoor was just toggled just now
        trapdoorPressed = true;

    } 
    // trapdoor was not toggled just now
    else {
        trapdoorPressed = false;
    }
}

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