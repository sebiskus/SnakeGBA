//Das wird benutzt um custom designs für das Spiel zu entwickeln

#ifndef COLOR_PALETTE_H
#define COLOR_PALETTE_H

#include "bn_string.h"

struct rgb {
    int red;
    int green;
    int blue;
};

//TODO

struct theme {
    bn::string<20> name = "theme";
   // rgb floor;
   // rgb wall;
   // rgb snake;
   // rgb apple;
    int id;
    rgb background;
    rgb font;
    bn::string<50> description = "-";
    //hier evtl. ein enum-tag für missionen
};

// Theme-Deklarationen (extern)
extern const theme basic;
extern const theme inverted;
extern const theme terminal;
extern const theme bsod;
extern const theme rm;
extern const theme hka_kickerz;
extern const theme pink;
extern const theme debug;

#endif
