/* 
Button Schnittstelle 
- Generiere Button Objekte mit Position, Größe, Text, bool_on/off, scene_switch Signal
*/

#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H

#include "menu.h"
#include "bn_vector.h"

#include "bn_sprite_tiles.h"
#include "bn_sprite_tiles_item.h"
#include "bn_sprite_tiles_ptr.h"


//Struct 

struct _pos {
    int x;
    int y;
};

struct button_pair {
    bn::sprite_tiles_ptr button_inactive;
    bn::sprite_tiles_ptr button_active;
};

enum SCENE {
    VOID,

    MAIN_MENU,

    GAME_MENU_SELECT,
    GAME_MENU_LEADERBOARD,

    THEMES,
    SETTINGS,
    CREDITS
};

class Button {
    private:
    int focus_pointer = 0;
    int size;
    _pos position;
    bn::string<10> text;
    SCENE signal;
    bool focussed;

    public:
    Button();
    Button(_pos position, 
        int size, 
        bn::string<10> text,
        SCENE signal
    );
    
    bool is_button_focussed(int button_size);

    //button_pair initialize_button();
};

#endif