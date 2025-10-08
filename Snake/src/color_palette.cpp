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
    "Für diejenigen, die Blind werden wollen"
};
const theme terminal {
    "Terminal",
    3,
    {0,0,0},
    {15,15,15},
    "sudo rm -fr /"
};
const theme bsod {
    "Blue Screen of Death",
    4,
    {0,0,0},
    {15,15,15},
    "Ein Fehler ist aufgetreten"
};
const theme rm {
    "Real Madrid",
    5,
    {0,0,0},
    {15,15,15},
    "CR7"
};
const theme hka_kickerz {
    "HKA Kickerz",
    6,
    {2,2,2},
    {15,15,15},
    "..."
};
const theme pink {
    "Pink",
    7,
    {0,0,0},
    {15,15,15},
    "Ziemlich pink."
};
const theme debug {
    "debug_theme",
    8,
    {0,0,0},
    {15,15,15},
    "description"
};
theme themes[] = {basic, inverted, terminal, bsod, rm, hka_kickerz, pink, debug};

theme switch_theme(int theme_id) {
    return themes[theme_id];
}
bn::string<20> get_theme_name(int theme_id) {
    return themes[theme_id].name;
}

//TODO: Individuelle Designs für iOS Anwendung. Wird im save File geschrieben und der
// Code der iOS App liest beim Update die File und wendet neue Designs an
