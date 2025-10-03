#include "menu.h"
#include "text.h"

void Menu::show_bg() {
    // Haupthintergrund (scrollend)
    _bg = bn::affine_bg_items::game_bg.create_bg(0, 0);
    
    // Snake Artwork als 64x64 Sprite rechts positioniert
    _snake_sprite = bn::sprite_items::snake_artwork.create_sprite(100, -50);
    //_rm_sprite = bn::sprite_items::real_madrid.create_sprite(100, -50);
    
    if (_snake_sprite) {
        _snake_sprite->set_scale(1.6);        // 70% Größe
        _snake_sprite->set_z_order(-10);      // Ganz vorne
        _snake_sprite->put_above();           // Über allem anderen
    }
}



void Menu::show_startup() {
    _startup_sprites.clear();
    _tg.generate(-100, -10, "von Basti", _startup_sprites);
    _tg.generate(-100, 0, "an Pius", _startup_sprites);
    _tg_small.generate(-100, 68, build, _startup_sprites);
}


// Neue Funktion für Speed-Anzeige
void Menu::show_menu(int speed) {
    clear_sprites(); // Sprites zurücksetzen vor neuer Erstellung
    
    _tg.generate(-96, -28, "Snake GBA", _menu_sprites);
    _tg_small.generate(-96, 14, "(Press A to start)", _menu_sprites);
    _tg_small.generate(-96, 28, "select: increase speed", _menu_sprites);
    _tg_small.generate(-96, 38, "start:  reset speed value", _menu_sprites);

    
    // Speed-Text erstellen mit ostringstream
    bn::string<32> speed_text;
    bn::ostringstream string_stream(speed_text);
    string_stream << "current speed: " << speed;
    
    _tg_small.generate(-96, 62, speed_text, _menu_sprites);
}

void Menu::update() {
    if(_bg) {
        _bg->set_priority(3);
        // Kontinuierliches Scrolling nach rechts
        // Bei 256x256 loopt es automatisch
        _bg->set_x(_bg->x() + 0.4);
    }
}

// Vollständiges Reset (ursprüngliche clear-Funktion)
void Menu::clear() {
    _menu_sprites.clear();
    _startup_sprites.clear();
    _bg.reset();
    _snake_sprite.reset();
}
// Nur Sprites zurücksetzen - verhindert Überfüllung
void Menu::clear_sprites() {
    _menu_sprites.clear();
    _startup_sprites.clear();
}
