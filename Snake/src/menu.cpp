#include "menu.h"
#include "text.h"
#include "color_palette.h"


void Menu::show_bg() {
    _bg = bn::affine_bg_items::game_bg.create_bg(0, 0);
    _snake_sprite = bn::sprite_items::snake_artwork.create_sprite(100, -50);
    _snake_sprite->set_scale(1.6);        // 70% Größe
    _snake_sprite->set_z_order(-10);      // Ganz vorne
    _snake_sprite->put_above();           // Über allem anderen
}

void Menu::show_startup() {
    _startup_sprites.clear();
    _tg.generate(-120, -30, "by @sebiskus", _startup_sprites);
    _tg.generate(-120, -18, "made with Butano", _startup_sprites);

    //_tg.generate(-120, 14, "Support both projects with a coffee!", _startup_sprites);

    _tg_small.generate(-100, 68, build, _startup_sprites);
}


// Hauptmenü
void Menu::show_menu(int speed, bn::string<20> theme_name) {
    Button button;
    clear_sprites(); // Sprites zurücksetzen vor neuer Erstellung
    
    _tg.generate(-96, -28, game_title, _menu_sprites);
    _tg_small.generate(-96, -8, "(Press A to start)", _menu_sprites);
    _tg_small.generate(-96, 12, "left/right: switch theme", _menu_sprites);
    _tg_small.generate(-96, 22, "up/down: adjust speed", _menu_sprites);
    _tg_small.generate(-96, 32, "select:  reset speed", _menu_sprites);

    
    // Speed-Text 
    bn::string<32> speed_text;
    bn::ostringstream string_stream(speed_text);
    string_stream << "current speed: " << speed;
    _tg_small.generate(-96, 72, speed_text, _menu_sprites);

    bn::string<52> theme_text;
    bn::ostringstream string_stream_theme(theme_text);

    string_stream_theme << "theme: " << theme_name;
    _tg_small.generate(-96, 62, theme_text, _menu_sprites_theme);

}

void Menu::update() {
    if(_bg) {
        _bg->set_priority(3);
        // Kontinuierliches Scrolling nach rechts
        // Bei 256x256 loopt es automatisch
        _bg->set_x(_bg->x() + 0.4);
    }
}



// Gesamtes Menü resetten
void Menu::clear() {
    clear_sprites();
    _bg.reset();
    _snake_sprite.reset();
}
// Nur Sprites resetten
void Menu::clear_sprites() {
    _menu_sprites_theme.clear();
    _menu_sprites.clear();
    _startup_sprites.clear();
}
