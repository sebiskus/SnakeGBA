#include "color_palette.h"

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
    {0,0,0},
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
    "title",
    8,
    {0,0,0},
    {15,15,15},
    "description"
};

//TODO: Individuelle Designs für iOS Anwendung. Wird im save File geschrieben und der
// Code der iOS App liest beim Update die File und wendet neue Designs an
