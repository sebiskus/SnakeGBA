#ifndef GAME_H
#define GAME_H

#include "bn_core.h"
#include "bn_log.h"
#include "bn_optional.h"

#include "player.h"
#include "map.h"
#include "game.h"
#include "renderer.h"
#include "game_state.h"
#include "menu.h"
#include "controls.h"
#include "color_palette.h"

#include "graphics.h" //globale Header File mit allen Grafiken und so      
#include "debug.h"  

#include "bn_display.h"
#include "bn_sprite_ptr.h"
#include "bn_keypad.h"

#include "bn_sprite_font.h"
#include "bn_sprite_text_generator.h" //generiert Text aus der gegebenen sprite_font


class Game {
    Player player;
    Renderer renderer;
    SCANNER scanner;
    theme current_theme;
    Controls controls;

    bool startup;
    


    public:
    Menu menu;
    Map game_map;
    GAME_STATE current_game_state;
    GAME_STATE switch_game_state;

    unsigned int speed;
    unsigned int theme_id;

    bn::sound_handle menu_music = bn::sound::play(bn::sound_items::menu_music, 0);

    bn::sound_handle *loop_handle; //hier machen glaub Pointer keinen Sinn... und vllt bn::optional<>

    Game();

    void set_current_game_state(GAME_STATE game_state);
    void startup_sequence();

    void run_menu();
    void initialize_game();
    void stop_game();
    void run();
    void run_game();
    void pause_game();

    /*delay time in seconds. */
    void delay(double time);
    void wait_for_input_menu();

    void timer();

    void adjust_theme_id();

    /* Speed Funktionen */
    void adjust_speed();
    void increase_speed() {speed++;};
    void reset_speed() {speed = 2;};
    void decrease_speed() {speed--;};

    void run_debug();

};

#endif
