#include "color_palette.h"
#include "bn_keypad.h"

// Theme-Definitionen
const theme basic {
    "basic",
    1,
    {0,0,0}, //schwarz
    {15,15,15}, //weiß
    "Standard-Theme"
};
const theme inverted {
    "Invertiert",
    2,
    {15,15,15},
    {0,0,0},
    "Light-Mode"
};
const theme terminal {
    "Terminal",
    3,
    {0,0,0},
    {15,15,15},
    "sudo rm -fr /"
};
const theme bsod {
    "BSOD",
    4,
    {0,0,0},
    {15,15,15},
    "Your GBA ran into a problem and needs to restart"
};
const theme special_theme_1 {
    "Special Theme 1",
    5,
    {0,0,0},
    {15,15,15},
    "RM"
};
const theme special_theme_2 {
    "Special Theme 2",
    6,
    {2,2,2},
    {15,15,15},
    "Kickerz"
};
const theme pink {
    "Pink",
    7,
    {0,0,0},
    {15,15,15},
    "pretty pink"
};
const theme debug {
    "debug_theme",
    8,
    {0,0,0},
    {15,15,15},
    "description"
};
theme themes[] = {basic, inverted, terminal, bsod, special_theme_1, special_theme_2, pink, debug};

theme switch_theme(int theme_id) {
    return themes[theme_id];
}
bn::string<20> get_theme_name(int theme_id) {
    return themes[theme_id].name;
}

//TODO: Individuelle Designs für iOS Anwendung. Wird im save File geschrieben und der
// Code der iOS App liest beim Update die File und wendet neue Designs an
