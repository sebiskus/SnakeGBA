#include "menu_button.h"

#include "bn_sprite_tiles_items_buttons.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_palette_ptr.h"

int focus_pointer = 1;
bn::vector<Button, 8> buttons;

Button::Button(){
    this->position = {0,0};
    this->size = 1;
    this->text = "text";
    this->signal = VOID;
    this->focussed = is_button_focussed(buttons.size());
}

Button::Button(_pos position, 
        int size, 
        bn::string<10> text,
        SCENE signal
    ) {
        this->position = position;
        this->size = size;
        this->text = text;
        this->signal = signal;
        this->focussed = is_button_focussed(buttons.size());
    }
/*
button_pair Button::initialize_button() {
    // Erstes Sprite-Tile-Set (Index 0)
    return button_sprites = {bn::sprite_tiles_items::buttons.create_tiles(0),
                                bn::sprite_tiles_items::buttons.create_tiles(1)};

};

*/

bool Button::is_button_focussed(int button_size){
    if (focus_pointer == button_size) {return true;}
    return false;
}


