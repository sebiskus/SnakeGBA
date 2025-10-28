#include "menu.h"
#include "text.h"
#include "color_palette.h"

void Menu::show_bg() {
    bg = bn::affine_bg_items::game_bg.create_bg(0, 0);
    bg->set_priority(3);
}
void Menu::show_logo() {
    logo = bn::affine_bg_items::logo.create_bg(-64, -30);
    logo->set_scale(0.4);
    logo->set_wrapping_enabled(false);
    
}

void Menu::show_snake() {
    snake_sprite = bn::sprite_items::snake_artwork.create_sprite(100, -50);
    snake_sprite->set_scale(1.6);        // 70% Größe
    snake_sprite->set_z_order(-10);      // Ganz vorne
    snake_sprite->put_above();           // Über allem anderen
}

/* Menu Szenen */

void Menu::scene_startup() {
    startup_sprites.clear();
    tg.generate(-100, -20, "by @sebiskus", startup_sprites);
    tg.generate(-100, -8, "made with Butano", startup_sprites);
    tg_small.generate(-100, 68, build, startup_sprites);
}

void Menu::scene_menu_intro() {
    clear_sprites();
    show_snake();
    tg.generate(-96, 0, game_title, menu_sprites);
    tg.generate(-96, 40, "(Press a button)", menu_sprites);
}

#ifndef DEBUG
// Hauptmenü
void Menu::scene_menu_main(int speed, bn::string<20> theme_name) {
    clear_sprites(); // Sprites zurücksetzen vor neuer Erstellung
    
    tg.generate(-96, -28, "MENU", menu_sprites);
    tg_small.generate(-96, 8, "(Press START to start the game)", menu_sprites);
    tg_small.generate(-96, 22, "left/right: switch theme", menu_sprites);
    tg_small.generate(-96, 32, "up/down: adjust speed", menu_sprites);
    tg_small.generate(-96, 42, "select:  reset speed", menu_sprites);

    
    // Speed-Text 
    bn::string<32> speed_text;
    bn::ostringstream string_stream(speed_text);
    string_stream << "current speed: " << speed;
    tg_small.generate(-96, 72, speed_text, menu_sprites);

    bn::string<52> theme_text;
    bn::ostringstream string_stream_theme(theme_text);

    string_stream_theme << "theme: " << theme_name;
    tg_small.generate(-96, 62, theme_text, menu_sprites_theme);

    show_snake();
}
#else
void Menu::scene_menu_main(int speed, bn::string<20> theme_name) {
    clear_sprites(); // Sprites zurücksetzen vor neuer Erstellung

    show_logo();

    
    tg.generate(-96, -28, game_title, menu_sprites);
    tg_small.generate(-96, -8, "DEBUG (Press A to start)", menu_sprites);

    bn::string<52> debug_text;
    bn::ostringstream string_stream_theme(debug_text);

    string_stream_theme << "val: " << debug_val;
    tg_small.generate(-96, 62, debug_text, menu_sprites_theme);

}
#endif

void Menu::update() {
    if(bg) {
        bg->set_x(bg->x() + 0.4);
    }
    
    #ifdef DEBUG
    debug_set_val(debug_val);
    #endif
}


// Gesamtes Menü resetten
void Menu::clear() {
    clear_sprites();
    clear_logo();
    bg.reset();
    snake_sprite.reset();
}
// Nur Sprites resetten
void Menu::clear_sprites() {
    menu_sprites_theme.clear();
    menu_sprites.clear();
    startup_sprites.clear();
}
void Menu::clear_logo() { logo.reset(); }

void Menu::credits_test() {
        //credits_picture = bn::regular_bg_items::credits_picture.create_bg(0,0);
    }