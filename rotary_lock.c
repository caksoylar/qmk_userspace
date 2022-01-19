#include "rotary_lock.h"

__attribute__((weak)) void emit_passphrase_secret(void) {}

void update_dial(bool direction) {
    const static uint8_t combo[]         = COMBINATION;
    const static size_t  combo_len       = sizeof(combo);
    static bool          direction_to_go = START_CW;
    static uint8_t       state = 0, clicks = 0, grace = 0;

    if (direction == direction_to_go) {              // correct direction
        if (++clicks == combo[state] - TOLERANCE) {  // increment clicks and check if dialed enough
            clicks = grace  = 0;
            direction_to_go = !direction_to_go;  // flip direction
            if (++state == combo_len) {          // increment state then check if we are at the end
                state           = 0;             // reset to start
                direction_to_go = START_CW;
                emit_passphrase_secret();
            }
        }
    } else {                                           // wrong direction so fail, except...
        if (clicks != 0 || ++grace > 2 * TOLERANCE) {  // a few extra ticks just after changing direction is acceptable
            state = clicks = grace = 0;                // reset to start
            direction_to_go        = true;
        }
    }
}
