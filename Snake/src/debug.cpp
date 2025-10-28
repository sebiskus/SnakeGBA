#include "debug.h"


void debug_wait_for_input(){
    while(!bn::keypad::l_pressed() || !bn::keypad::r_pressed()){
        bn::core::update();
    }
}

void debug_set_val(int &val) {
    if(bn::keypad::up_pressed()) {
        val++;
    }
    if(bn::keypad::down_pressed()) {
        val--;
    }
    if(bn::keypad::left_pressed()) {
        val -= 50;
    }
    if(bn::keypad::right_pressed()) {
        val += 50;
    }
}
