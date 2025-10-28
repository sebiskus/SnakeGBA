//Das wird benutzt um custom designs für das Spiel zu entwickeln

#ifndef COLOR_PALETTE_H
#define COLOR_PALETTE_H

#include "bn_string.h"

struct rgb {
    int red;
    int green;
    int blue;
};


struct theme {
    bn::string<20> name = "theme";

    int id;
    rgb background; //wird nicht genutzt
    rgb font;
    bn::string<50> description = "-";
    //hier evtl. ein enum-tag für missionen
};

extern const theme basic;
extern const theme inverted;
extern const theme terminal;
extern const theme bsod;
extern const theme special_theme_1;
extern const theme special_theme_2;
extern const theme pink;
extern const theme debug;


theme switch_theme(int theme_id);
bn::string<20> get_theme_name(int theme_id);
#endif
