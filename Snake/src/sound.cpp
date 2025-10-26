#include "sound.h"

void play_sound(SOUND_EFFECT sound_effect) {
    switch (sound_effect)
    {
    case GAME_OVER:
        bn::sound_items::game_over.play();
        break;
    case SNAKE_EATING:
        bn::sound_items::snake_eating.play();
        break;
    case BUTTON_PRESS:
        bn::sound_items::button_press.play();
        break;
    default:
        break;
    }
}

void loop_music(bn::sound_handle *loop_handle){
    #ifndef DEBUG //damit mir die Musik beim Debuggen nicht auf die Nerven geht :)
        if(!(*loop_handle).active()) {                                  
                    *loop_handle = bn::sound::play(bn::sound_items::menu_music, 1);
                }
    #endif
}