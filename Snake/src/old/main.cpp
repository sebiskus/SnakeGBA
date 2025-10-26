/*
* GBA Snake
* created by: @sebiskus
* made with Butano
*/

#include "bn_core.h"
#include "bn_log.h"

#include "player.h"
#include "map.h"
#include "game.h"
#include "renderer.h"

#include "bn_display.h"
#include "bn_sprite_ptr.h"
#include "bn_keypad.h"

#include "bn_sprite_font.h"
#include "bn_sprite_text_generator.h" //generiert Text aus der gegebenen sprite_font

#include "common_variable_8x16_sprite_font.h"


GAME_STATE switch_game_state = MENU;

void startup_text_generator(Game& game){
    bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);

    bn::vector<bn::sprite_ptr, 16> text_sprites;

    text_generator.generate(-6 * 16, -68, "Snake GBA", text_sprites);
    text_generator.generate(-6 * 16, -28, "(Press A to start)", text_sprites);

    wait_for_input();
    switch_game_state = INITIALIZE;
}

void debug_log(Game game, Map game_map){
    BN_LOG("Current game state: ", switch_game_state);
}




int main()
{
    bn::core::init();

    Player player;
    Game game;
    Renderer renderer;
    Map game_map;
    SCANNER scanner;
    
    while(true) 
    {

        //debug_log(game, game_map);
        bn::core::update();
        game.current_game_state = switch_game_state;

        switch(game.current_game_state) {
            case MENU: {
            startup_text_generator(game);
            break;
            }

            case STOP: {
            player.reset_player(player);
            Map& game_map = selectMap(0);
            renderer.reset_renderer(renderer);
            switch_game_state = MENU;
            break;
            }

            case RUNNING: {
                /*
                - Spieler Position updatem
                - Scanner vergleicht neue Position mit der aktuellen Karte
                -> Konflikt? Game State updaten
                -> Apfel? Länge anpassen
                -> Nichts? weitermachen!
                - Karte aktualisieren
                - Visuel rendern
                */
            
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
        
           BN_LOG("SCANNER: ", scanner);

            //if (bn::keypad::start_held()) {player.pause();}

            break;
            }

            case PAUSE: {
            break;
            }

            case INITIALIZE: {
            Map& game_map = selectMap(0);
            player.start(2, game_map);
            switch_game_state = RUNNING;
            scanner = SAFE_AREA;

            break;
            }

            default:
            break;

        }
    }
    
    return 0;
}