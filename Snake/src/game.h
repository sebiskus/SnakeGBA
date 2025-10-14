#ifndef GAME_H
#define GAME_H

#include "bn_core.h"
#include "bn_log.h"

#include "player.h"
#include "map.h"
#include "game.h"
#include "renderer.h"
#include "game_state.h"
#include "menu.h"
#include "controls.h"
#include "color_palette.h"

#include "bn_sound.h"          
#include "bn_sound_items.h"
#include "bn_optional.h"        

#include "bn_sound_items.h"

#include "bn_display.h"
#include "bn_sprite_ptr.h"
#include "bn_keypad.h"

#include "bn_sprite_font.h"
#include "bn_sprite_text_generator.h" //generiert Text aus der gegebenen sprite_font

#include "common_variable_8x16_sprite_font.h"

class Game {
    Player player;
    Renderer renderer;
    SCANNER scanner;
    theme current_theme;
    Controls controls;

    bool startup;
    unsigned int speed;
    unsigned int theme_id;


    public:
    Menu menu;
    Map game_map;
    GAME_STATE current_game_state = MENU;
    GAME_STATE switch_game_state = MENU;

    bn::sound_handle loop_handle = bn::sound::play(bn::sound_items::menu_music, 0);

    Game();

    void set_current_game_state(GAME_STATE game_state);
    void startup_sequence();

    void run_menu();
    void initialize_game();
    void stop_game();
    void run();
    void run_game();

    /*delay time in seconds. */
    void delay(double time);
    void wait_for_input_menu();
    void wait_for_input();

    void timer();

    void adjust_theme_id();

    /* Speed Funktionen */
    void adjust_speed();
    void increase_speed() {speed++;};
    void reset_speed() {speed = 2;};
    void decrease_speed() {speed--;};

    void loop_music(){
        if(!loop_handle.active()) {                                  
                    loop_handle = bn::sound::play(bn::sound_items::menu_music, 1);
                }
    }
};

#endif