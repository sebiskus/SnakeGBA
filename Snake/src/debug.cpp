#include "debug.h"

void debug_wait_for_input(){
    while(!bn::keypad::l_pressed() || !bn::keypad::r_pressed()){
        bn::core::update();
    }
}