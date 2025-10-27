#ifndef MENU_SCENES_H
#define MENU_SCENES_H

#include "menu_button.h"

namespace MAIN_MENU_SCENE {
    constexpr Button buttons[] = {
        {{0, 0}, {0, 0}, 1, "Start Game", GAME_MENU_SELECT, false},
        {{1, 0}, {50, 0}, 1, "Settings", SETTINGS, false},
        {{2, 0}, {100, 0}, 1, "Credits", CREDITS, false}
    };
    constexpr unsigned int button_count = 3;
}

namespace SETTINGS_SCENE {
    constexpr Button buttons[] = {
        {{0, 0}, {0, 0}, 1, "Themes", THEMES, false},
        {{1, 0}, {50, 0}, 1, "Back", MAIN_MENU, false}
    };
    constexpr unsigned int button_count = 2;
}


#endif
