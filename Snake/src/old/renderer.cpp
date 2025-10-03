//Idee: Snake spielt sich auf einer Matrix Map ab. Der Renderer Visualisiert das Spiel auf dem GBA.
// dabei werden die Koordinaten der Matrixpunkte genommen und die Tiles werden auf den Positionen
// gezeichnet (also Index 1|2 = 16|32 in pixel bei 4x4 Tiles pro Array-Element)


#include "renderer.h"
#include "bn_sprite_items_square.h" // Die schwarze 8x8 square.bmp
#include "bn_color.h"
#include "bn_math.h"

Renderer::Renderer() : current_theme(&basic) {
    initialize();
}

void Renderer::initialize() {
    map_sprites.clear();
    create_palettes();
}

bn::color Renderer::convert_rgb_to_bn_color(const rgb& color) {
    // RGB-Werte von 0-255 auf GBA-Format (5-Bit pro Kanal) konvertieren
    int r = bn::min(31, (color.red * 31) / 255);
    int g = bn::min(31, (color.green * 31) / 255);
    int b = bn::min(31, (color.blue * 31) / 255);
    
    return bn::color(r, g, b);
}

void Renderer::create_palettes() {
    // Nur 3 Paletten erstellen statt für jeden Sprite eine neue
    wall_palette = bn::sprite_items::square.palette_item().create_new_palette();
    snake_palette = bn::sprite_items::square.palette_item().create_new_palette();
    apple_palette = bn::sprite_items::square.palette_item().create_new_palette();
    
    // Farben entsprechend dem aktuellen Theme setzen
    if (wall_palette.has_value()) {
        wall_palette->set_color(1, convert_rgb_to_bn_color(current_theme->wall));
    }
    if (snake_palette.has_value()) {
        snake_palette->set_color(1, convert_rgb_to_bn_color(current_theme->snake));
    }
    if (apple_palette.has_value()) {
        apple_palette->set_color(1, convert_rgb_to_bn_color(current_theme->apple));
    }
}

void Renderer::clear_all_sprites() {
    map_sprites.clear();
}

void Renderer::render_map(const Map& map) {
    clear_all_sprites();
    
    // Zentrier-Offset berechnen für 8x8 Tiles
    const int screen_center_x = 120; // GBA Bildschirmbreite / 2
    const int screen_center_y = 80;  // GBA Bildschirmhöhe / 2
    const int map_pixel_width = x_size * TILE_SIZE;
    const int map_pixel_height = y_size * TILE_SIZE;
    const int offset_x = -(map_pixel_width / 2);
    const int offset_y = -(map_pixel_height / 2);
    
    // Durch das gesamte Map-Array iterieren
    for (int map_y = 0; map_y < y_size; map_y++) {
        for (int map_x = 0; map_x < x_size; map_x++) {
            int tile_value = map[map_y][map_x];
            
            // Skip empty/floor tiles (Wert 0) - diese werden nicht gerendert
            if (tile_value == FLOOR_TILE) {
                continue;
            }
            
            // Bildschirmposition berechnen (relativ zur Bildschirmmitte)
            int screen_x = offset_x + (map_x * TILE_SIZE);
            int screen_y = offset_y + (map_y * TILE_SIZE);
            
            // Square-Sprite erstellen und positionieren
            if (map_sprites.size() < map_sprites.max_size()) {
                auto sprite = bn::sprite_items::square.create_sprite(screen_x, screen_y);
                
                // Geteilte Palette basierend auf Tile-Typ zuweisen
                switch (tile_value) {
                    case WALL_TILE:
                        if (wall_palette.has_value()) {
                            sprite.set_palette(*wall_palette);
                        }
                        break;
                    case SNAKE_TILE:
                        if (snake_palette.has_value()) {
                            sprite.set_palette(*snake_palette);
                        }
                        break;
                    case APPLE_TILE:
                        if (apple_palette.has_value()) {
                            sprite.set_palette(*apple_palette);
                        }
                        break;
                }
                
                map_sprites.push_back(bn::move(sprite));
            }
        }
    }
}

void Renderer::set_theme(const theme& new_theme) {
    current_theme = &new_theme;
    
    // Bestehende Paletten-Farben aktualisieren
    if (wall_palette.has_value()) {
        wall_palette->set_color(1, convert_rgb_to_bn_color(current_theme->wall));
    }
    if (snake_palette.has_value()) {
        snake_palette->set_color(1, convert_rgb_to_bn_color(current_theme->snake));
    }
    if (apple_palette.has_value()) {
        apple_palette->set_color(1, convert_rgb_to_bn_color(current_theme->apple));
    }
}

void Renderer::update_display() {
    // Butano behandelt automatisches Rendering der Sprites
}
