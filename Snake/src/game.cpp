#include "game.h"

Game::Game(){
    this->speed = 2;
    this->startup = true;
    this->theme_id = 0;
    renderer.hide_bg();
}

void Game::run() {
    bn::core::update();
    current_game_state = switch_game_state;

    #ifdef DEBUG
    startup = false;
    BN_LOG("Current game state: ", switch_game_state);
    #endif

    while (startup) { 
        startup_sequence();
        bn::core::update();
    }

    switch(current_game_state) {
        case INITIALIZE: { //Hier wird die Runde initialisiert
            initialize_game();
            break;
        }
            case MENU: {
                run_menu();
                break;
            }

            case STOP: {
                stop_game();
                break;
            }

            case RUNNING: {
                run_game();
                break;
                }

        case PAUSE: {
            break;
        }
        case _DEBUG: {
            break;
        }
        default:
            break;
    }
}




/* Hilfsfunktionen für Game::run(); */

void Game::startup_sequence(){
    menu.show_startup();
    bn::sound_items::button_press.play();
    delay(2);
    loop_handle.stop();
    startup = false;
}

void Game::delay(double time){
    int frames = 60 * time;
    for (int i = 0; i < frames; i++) {
        bn::core::update();
    }
}

void Game::adjust_speed(){
    if (bn::keypad::up_pressed() && speed < 12) {
            increase_speed();
        } else if (bn::keypad::select_pressed()) {
            reset_speed();
        } else if (bn::keypad::down_pressed() && speed > 1) {
            decrease_speed();
        } 
}

void Game::adjust_theme_id(){
    if (bn::keypad::left_pressed()) {
        if (this->theme_id > 0) {
            this->theme_id--;
        }
    } else if (bn::keypad::right_pressed()) {
        if (this->theme_id < 7) {
            this->theme_id++;
        }
    }
}

void Game::wait_for_input_menu(){
    while(!bn::keypad::a_pressed()){
        loop_music();
        adjust_speed();
        adjust_theme_id();
        current_theme = switch_theme(theme_id);
        bn::string<20> theme_name = get_theme_name(theme_id);
        menu.show_menu(speed, theme_name);
        menu.update();
        bn::core::update();
    }
    bn::sound_items::start.play();
}

void Game::wait_for_input(){
    while(!bn::keypad::b_pressed()){
        bn::core::update();
    }
}

void Game::run_menu(){
    menu.show_bg();
    loop_music();
    wait_for_input_menu();
    menu.clear();
    switch_game_state = INITIALIZE;
    #ifdef DEBUG
    switch_game_state = _DEBUG;
    #endif
}


void Game::initialize_game(){
    initialize_random_seed(); // Seed beim Spielstart initialisieren

    loop_handle.stop();
            
    controls.clear();
    Map& game_map = selectMap(0);
    player.start(speed, game_map);

    // einmal initial rendern
    renderer.apply_theme(renderer.current_theme, current_theme);
    renderer.show_bg();           
    renderer.clear_all_tiles();
    renderer.draw_map(game_map);
    renderer.update_score(player.get_snake_body().size());
    switch_game_state = RUNNING;
}

void Game::run_game(){

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

    bn::core::update();

    //if (bn::keypad::start_held()) {player.pause();}
}

void Game::stop_game(){
    controls.clear();
    renderer.clear_all_tiles();
    renderer.hide_bg();         // BG ausblenden (oder renderer.shutdown_bg(); für Freigabe)
    player.reset_player(player);                
    switch_game_state = MENU;
    reset_speed();
    Map& game_map = selectMap(0);
}