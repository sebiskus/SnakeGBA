#ifndef MENU_H
#define MENU_H

#include "bn_sprite_text_generator.h"
#include "bn_vector.h"
#include "bn_sprite_ptr.h"
#include "bn_optional.h"
#include "bn_affine_bg_ptr.h"
#include "bn_sstream.h"  // Für bn::ostringstream
#include "bn_string.h"   // Für bn::string

#include "graphics.h"


class Menu {
private:

    bn::sprite_text_generator _tg{common::variable_8x16_sprite_font};
    bn::sprite_text_generator _tg_small{common::variable_8x8_sprite_font};
    
    bn::vector<bn::sprite_ptr, 32> _startup_sprites;
    bn::vector<bn::sprite_ptr, 32> _menu_sprites;
    bn::vector<bn::sprite_ptr, 32> _menu_sprites_theme;


    bn::optional<bn::affine_bg_ptr> _bg;
    bn::optional<bn::sprite_ptr> _snake_sprite;  // Sprite für Snake Artwork

public:

    void initialize_menu();

    void show_bg();
    void show_menu(int speed, bn::string<20> theme_name);
    void show_startup();
    void update();
    void clear();           // Vollständiges Reset
    void clear_sprites();   // Nur Sprites zurücksetzen
};

#endif
