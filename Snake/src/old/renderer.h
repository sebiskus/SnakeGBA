// Korrigierte renderer.h
#ifndef RENDERER_H
#define RENDERER_H

#include "bn_core.h"
#include "bn_sprite_ptr.h"
#include "bn_vector.h"
#include "bn_sprite_palette_ptr.h"
#include "bn_color.h"
#include "map.h"
#include "color_palette.h"

class Renderer {
private:
    static constexpr int TILE_SIZE = 8;
    
    // Sprite Vektor für alle Map-Tiles
    bn::vector<bn::sprite_ptr, 160> map_sprites; // 16x10 = 160 tiles maximum
    
    // Geteilte Paletten für verschiedene Tile-Typen
    bn::optional<bn::sprite_palette_ptr> wall_palette;
    bn::optional<bn::sprite_palette_ptr> snake_palette;
    bn::optional<bn::sprite_palette_ptr> apple_palette;
    
    // Aktuelle Theme-Referenz
    const theme* current_theme;
    
    // Private Hilfsfunktionen
    bn::color convert_rgb_to_bn_color(const rgb& color);
    void create_palettes();
    void clear_all_sprites();

public:
    Renderer();
    void initialize();
    void render_map(const Map& map);
    void set_theme(const theme& new_theme);
    void update_display();
};

#endif
