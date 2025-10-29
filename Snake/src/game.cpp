#include "game.h"

Game::Game(){
    this->speed = 2;
    this->startup = true;
    this->theme_id = 0;
    this->loop_handle = &menu_music;
    this->current_game_state, this->switch_game_state = MENU;
    renderer.hide_bg();
}

void Game::run() {

    #ifdef DEBUG
    startup = false;
    BN_LOG("Current game state: ", switch_game_state);
    #endif

    current_game_state = switch_game_state;

    while (startup) { 
        startup_sequence();
        bn::core::update();
    }

    switch(current_game_state) {
        case MENU: {
            run_menu();
            break;
        }
        case INITIALIZE: {       //Hier wird die Runde initialisiert
            initialize_game();
            break;
        }
        case RUNNING: {
            run_game();
            break;
        }
        case PAUSE: {
            pause_game();
            break;
        }
        case STOP: {
            stop_game();
            break;
        }
        case _DEBUG: {          //optional zum Debuggen
            //switched nach a drücken hierhin
            run_game();
            pause_game();
            break;
        }
        default:
            break;
    }
    bn::core::update();
}




/* Hilfsfunktionen für Game::run(); */

void Game::startup_sequence(){
    menu.scene_startup();
    bn::sound_items::button_press.play();
    delay(2);
    loop_handle->stop();
    startup = false;
}

void Game::delay(double time){
    int frames = 60 * time;
    for (int i = 0; i < frames; i++) {
        bn::core::update();
    }
}

void Game::adjust_speed(){
    if (bn::keypad::up_pressed() && speed < 10) {
            increase_speed();
        } else if (bn::keypad::select_pressed()) {
            reset_speed();
        } else if (bn::keypad::down_pressed() && speed > 1) {
            decrease_speed();
        } 
}

void Game::adjust_theme_id(){
    if (bn::keypad::left_pressed() && theme_id > 0)     { theme_id--; }
    if (bn::keypad::right_pressed() && theme_id < 7)    { theme_id++; }
}

/*
if it ain't broke don't fix it :)
*/
void Game::wait_for_input_menu(){
    if (scene::intro == true) {
        while(!bn::keypad::a_pressed()){
            loop_music(loop_handle);
            menu.scene_menu_intro();
            menu.update();
            bn::core::update();
        }
    }

    menu.clear_logo();

    bn::sound_items::start.play();
    scene::intro = false;
    
    while(!bn::keypad::start_pressed()){
        loop_music(loop_handle);
        adjust_speed();
        adjust_theme_id();
        current_theme = switch_theme(theme_id);
        bn::string<20> theme_name = get_theme_name(theme_id);

        //menu.scene_menu_intro();
        menu.scene_menu_main(speed, theme_name);

        menu.update();
        bn::core::update();
    }
    bn::sound_items::start.play();
}

void Game::run_menu(){
    menu.show_bg();
    loop_music(loop_handle);
    wait_for_input_menu();
    menu.clear();
    switch_game_state = INITIALIZE;
    #ifdef DEBUG
    switch_game_state = _DEBUG;
    #endif
}


void Game::initialize_game(){
    initialize_random_seed();
    loop_handle->stop();    
    controls.clear();
    Map& game_map = selectMap(0);
    player.start(speed, game_map);
    renderer.update_score(player.get_snake_body().size());
    renderer.load_palette();
    renderer.apply_theme(renderer.current_theme, current_theme);
    renderer.show_bg();           
    renderer.clear_all_tiles();
    renderer.draw_map(game_map);
    switch_game_state = RUNNING;
    delay(0.5);
}

void Game::run_game(){
    if (!bn::keypad::start_held()){
        controls.update_per_frame(player.get_direction());
        DIRECTION eff_dir = controls.peek_effective_direction(player.get_direction());

        SCANNER next_scan = player.check_next_position(game_map, eff_dir);
        player.update(next_scan, controls);

        SCANNER current_scanner = player.front_scanner(game_map, switch_game_state, player.get_snake_body());

        update_map(game_map, 0, player.get_snake_body());

        renderer.draw_map(game_map);
        renderer.update_score(player.get_snake_body().size());

        if (bn::keypad::select_held() || current_scanner == BORDER || current_scanner == PLAYER) {
            switch_game_state = STOP;
        }
    } else { switch_game_state = PAUSE; }
}

void Game::stop_game(){
    controls.clear();
    renderer.clear_all_tiles();
    renderer.hide_bg();
    renderer.unload_palette();
    player.reset_player(player);                
    switch_game_state = MENU;
    reset_speed();
    Map& game_map = selectMap(0);
}

void Game::pause_game() {
    bn::sound_items::button_press.play();
    delay(0.5);
    while (!bn::keypad::start_pressed()) { bn::core::update(); }
    bn::sound_items::button_press.play();
    switch_game_state = RUNNING;
    delay(0.5);
}