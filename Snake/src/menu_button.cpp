#include "menu_button.h"

void create_button(
    _pos button_id,
    _pos button_position,           
    int size,                       
    char button_label[16],   
    SCENE signal
    ) {
        Button button = {button_id, button_position, size, *button_label, signal, false};
        buttons.push_back(button);
    }

void clear_buttons() { buttons.clear(); }