/*
* GBA Snake
* created by: @sebiskus
* made with Butano https://github.com/GValiente/butano
*/

#include "bn_core.h"
#include "bn_log.h"
#include "game.h"

int main() {
    bn::core::init();

    Game game;
    initialize_random_seed();
    bool log = false;

    if (bn::keypad::select_held()) { log = true; }

    while (1) {
        game.run();
        if (log) {
            BN_LOG("Current game state: ", game.switch_game_state);
        }
    }
    return 0;
}

