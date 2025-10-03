#include <iostream>

enum Palette {
    //DEFAULT (black/white)
    TERMINAL,
    LIGHT_MODE,
    REAL_MADRID,
    HKA_KICKERZ, //GOAT
    BSOD,
};

struct Color {
    int r; //bis 255
    int b;
    int g;
};

struct PaletteColors {
    Color primaryColor;
    Color secondaryColor;
    Color Background;
    Color font;
    Color apple;
    Color snake;
};

PaletteColors paletteSwitcher (Palette palette) {
    switch(palette) {
        case TERMINAL:
            return PaletteColors {

            };
            break;
        default:
            return PaletteColors {

            };
            break;
    }
}