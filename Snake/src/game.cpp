#include "game.h"

Game::Game(){
    this->speed = 1;
    this->startup = true;
}


void Game::run() {
    bn::core::update();
    current_game_state = switch_game_state;

    while (startup) { 
        startup_sequence();
        bn::core::update();
    }

        switch(current_game_state) {
            case MENU: {
            menu.show_menu();
            menu.show_bg();
            wait_for_input();
            menu.clear();
            switch_game_state = INITIALIZE;
            break;
            }

            case STOP: {
            player.reset_player(player);
            renderer.reset_renderer(renderer);

            reset_speed();
            reset_random_seed(); // Neuen Seed für nächstes Spiel

            Map& game_map = selectMap(0);

            switch_game_state = MENU;
            break;
            }

            case RUNNING: {
            
            SCANNER next_scanner = player.check_next_position(game_map);
            player.update(next_scanner);
            SCANNER current_scanner = player.front_scanner(game_map, switch_game_state, player.get_snake_body());


            if (bn::keypad::select_held() || current_scanner == BORDER || current_scanner == PLAYER) {
                switch_game_state = STOP;
            }

            update_map(game_map, 0, player.get_snake_body());

            renderer.map_renderer(game_map, 1, renderer.squares, basic);
            renderer.update_score(player.get_snake_body().size());

            /* Temporär. Danach Game Over state programmieren */

            //if (bn::keypad::start_held()) {player.pause();}

            break;
            }

            case PAUSE: {
            break;
            }

            case INITIALIZE: {
            initialize_random_seed(); // Seed beim Spielstart initialisieren
            Map& game_map = selectMap(0);
            player.start(speed, game_map);
            switch_game_state = RUNNING;
            scanner = SAFE_AREA;

            break;
            }

            default:
            break;

        }

}

void Game::startup_sequence(){
    menu.show_startup();
    
    // Animation für 2 Sekunden laufen lassen
    int frames = 120; // 2 Sekunden bei 60 FPS
    for (int i = 0; i < frames; i++) {
        menu.update(); // Background-Scroll aktualisieren
        bn::core::update();
    }
    
    startup = false;
}


void Game::launchMenu(){
    // Menu-Logik hier implementieren  
}

void Game::delay(double time){
    int frames = 60 * time;
    for (int i = 0; i < frames; i++) {
        bn::core::update();
    }
}

void Game::wait_for_input(){
    while(!bn::keypad::a_held()){
        if (bn::keypad::select_pressed()) {
            increase_speed();
        }
        if (bn::keypad::start_pressed()) {
            reset_speed();
        }
        menu.show_menu_with_speed(speed);
        menu.update();
        bn::core::update();
    }
}