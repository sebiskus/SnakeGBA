#ifndef MENU_H
#define MENU_H

#include "debug.h"

#include "bn_sprite_text_generator.h"
#include "bn_vector.h"
#include "bn_sprite_ptr.h"
#include "bn_optional.h"
#include "bn_sstream.h"  // Für bn::ostringstream
#include "bn_string.h"   // Für bn::string

#include "graphics.h"
#include "menu_button.h"
#include "menu_scene_switcher.h"


class Menu {
private:

    bn::sprite_text_generator tg{common::variable_8x16_sprite_font};
    bn::sprite_text_generator tg_small{common::variable_8x8_sprite_font};
    
    bn::vector<bn::sprite_ptr, 32> startup_sprites;
    bn::vector<bn::sprite_ptr, 32> menu_sprites;
    bn::vector<bn::sprite_ptr, 32> menu_sprites_theme;


    bn::optional<bn::affine_bg_ptr> bg;
    bn::optional<bn::regular_bg_ptr> credits_picture;
    bn::optional<bn::sprite_ptr> snake_sprite;  // Sprite für Snake Artwork

public:

    void initialize_menu();

    void show_bg();
    
    void show_snake();
    void rotate_snake(); //TODO

/*
Szenen:
/Boot
    /Menu
        /Intro (1x)
            /Main
            /Themes
            /Leaderboard
            /Settings
                /Audio
                /Accessebility
                /Language
                /Data
            /Credits
    /Game
        /Pause
*/
    void scene_startup();

    void scene_menu_intro();
    void scene_menu_main(int speed, bn::string<20> theme_name);
    void scene_menu_credits();
    void scene_menu_themes();

    void update();
    void clear();           // Vollständiges Reset
    void clear_sprites();   // Nur Sprites zurücksetzen
    void credits_test();
};

#endif
