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

    bool startup;
    int speed;


    public:
    Menu menu;
    Map game_map;
    GAME_STATE current_game_state = MENU;
    GAME_STATE switch_game_state = MENU;


    Game();

    void set_current_game_state(GAME_STATE game_state);
    void startup_sequence();
    void run();
    void launchMenu();

    /*delay time in seconds. */
    void delay(double time);

    void timer();

    //Debug functions

    void wait_for_input();
    void increase_speed() {speed++;};
    void reset_speed() {speed = 1;};
    
};

#endif