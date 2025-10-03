#include "renderer.h"

Renderer::Renderer() {
    this->renderer_scaler = 1;
    this->current_theme = basic;
    this->color = bn::color(16,16,16);
    bn::backdrop::set_color(bn::color(0, 0, 0));
}

void create_solid_background() {
    bn::color background_color = bn::color(0, 7, 18);
    bn::backdrop::set_color(background_color);
}

// Score anzeigen lassen
void Renderer::update_score(int score_value) {
    clear_sprites();

    bn::string<32> score_text;
    bn::ostringstream score_stream(score_text);

    score_stream << "Score: " << score_value;
    _text_generator.generate(offset_x_score, 0, score_text, ui_sprites);
}


/*
Eigentlicher Game Renderer:
Idee: Snake spielt sich auf einer Matrix Map ab. Der Renderer Visualisiert das Spiel auf dem GBA.
dabei werden die Koordinaten der Matrixpunkte genommen und die Tiles werden auf den Positionen
gezeichnet (also Index 1|2 = in 8|16 px rendern bei 8x8 Sprites)

Rendert die Map step by step:
- Garbage löschen
- Hintergrund rendern
- Koordinaten berechnen
- Aus Map Kopie alle Tiles nach und nach rendern
*/
void Renderer::map_renderer(Map& map, int renderer_scaler, bn::vector<bn::sprite_ptr, 160>& squares, theme current_theme) {
    squares.clear();

    bn::backdrop::set_color(bn::color(0, 7, 16)); // #00479A
    
    int tile_size = 8 * renderer_scaler;
    int start_x = -(x_size * tile_size) / 2 + tile_size / 2  + offset_x_map;
    int start_y = -(y_size * tile_size) / 2 + tile_size / 2;
    
    for(int y = 0; y < y_size; y++) {
        for(int x = 0; x < x_size; x++) {
            int tile_type = map[y][x];
            
            if(tile_type == 0) continue;
            
            int sprite_x = start_x + (x * tile_size);
            int sprite_y = start_y + (y * tile_size);
            
            switch(tile_type) {
                case 1: // Wall
                    squares.push_back(bn::sprite_items::wall_square.create_sprite(sprite_x, sprite_y));
                    break;
                case 2: // Snake
                    squares.push_back(bn::sprite_items::snake_square.create_sprite(sprite_x, sprite_y));
                    break;
                case 3: // Apple
                    squares.push_back(bn::sprite_items::apple_square.create_sprite(sprite_x, sprite_y));
                    break;
                default:
                squares.push_back(bn::sprite_items::square.create_sprite(sprite_x, sprite_y));
                    break;
            }
        }
    }
}

void Renderer::clear_sprites() {
    ui_sprites.clear();
}
