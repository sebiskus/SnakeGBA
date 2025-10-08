/*
* GBA Snake
* created by: @sebiskus
* made with Butano https://github.com/GValiente/butano
*/

#include "bn_core.h"
#include "game.h"

int main() {

    bn::core::init();
    Game game;
    initialize_random_seed();

    while (1) {
        game.run();
    }
    return 0;
}

