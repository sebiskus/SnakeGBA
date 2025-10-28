#ifndef DEBUG_H
#define DEBUG_H

#include "bn_core.h"
#include "bn_keypad.h"

/*
*   Header dient dazu da um global debug Funktionen auszuführen.
*   -> Zum Debuggen: DEBUG Flag auskommentieren
*/


//#define DEBUG

inline int debug_val;

void debug_wait_for_input();
void debug_set_val(int &val);

#endif
