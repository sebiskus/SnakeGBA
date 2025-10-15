#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H

#include "bn_vector.h"
#include "bn_optional.h"

#include "bn_sprite_tiles.h"
#include "bn_sprite_tiles_item.h"
#include "bn_sprite_tiles_ptr.h"


/* 
Button Schnittstelle 
- Generiere Button Objekte mit Position, Größe, Text, bool_on/off, scene_switch Signal
*/

struct _pos { //TODO: hab irgendwas verkackt mit pos. Das irgendwann ersetzen
    int x;
    int y;
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

/*
Idee: Button tragen deren Position (X|Y).
Es gibt einen globalen Zeiger focus_pointer. Seine Start-Position wird bei jedem Menü neu definiert.
> ein is_focused() prüft von jedem aktiven Button seine derzeitige ID/Position und vergleicht die mit focus_pointer
> Wenn Übereinstimmung: Wird auf einem Button *currently_focussed_button gesichert und auf focussed gestellt
*/

typedef struct {
    _pos button_id;                 //ist die x|y Position, allerdings simpler. statt sowas wie -100|0 => 0|2
    _pos button_position;           
    int size;                       //Größe von dem Button
    char button_label[16];   
    SCENE signal;                   //führt die jeweilige Aktion aus
    bool isFocussed;                //Ändert sein Sprite

} Button;

extern _pos focus_pointer;
extern Button *currently_focussed_button;
extern bn::vector<Button, 10> buttons;

bool is_button_focussed(_pos focus_pointer); //oder set_focus() für void

void create_button(
    _pos button_id,
    _pos button_position,           
    int size,                       
    char button_label[16],   
    SCENE signal
    );

void display_button();
void clear_buttons();


#endif