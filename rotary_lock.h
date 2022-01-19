#pragma once
#include QMK_KEYBOARD_H

#if (__has_include("secrets.h") && !defined(NO_SECRETS))
#    include "secrets.h"
#else
#    define COMBINATION \
        { 1 }
#    define START_CW true
#endif

#define TOLERANCE 3

void update_dial(bool direction);
