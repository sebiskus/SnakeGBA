#ifndef SOUND_H
#define SOUND_H

#include "bn_sound.h"
#include "bn_sound_items.h"

#include "debug.h"

enum SOUND_EFFECT {
    BUTTON_PRESS,
    GAME_OVER,
    SNAKE_EATING,
    START
};

void play_sound(SOUND_EFFECT sound_effect);

void loop_music(bn::sound_handle *loop_handle);

#endif