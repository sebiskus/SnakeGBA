#include "renderer.h"

#include "bn_backdrop.h"
#include "bn_optional.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_tiles_ptr.h"
#include "bn_regular_bg_map_ptr.h"
#include "bn_regular_bg_map_cell_info.h"
#include "bn_bg_palette_ptr.h"
 

namespace {

constexpr int BG_COLS = 32;
constexpr int BG_ROWS = 32;

// 128x128 BMP => 128/8 = 16 Tiles pro Reihe
constexpr int TILES_PER_ROW = 16;

bool s_inited = false;
bn::optional<bn::regular_bg_tiles_ptr> s_tiles;
bn::optional<bn::bg_palette_ptr>       s_palette;
bn::optional<bn::regular_bg_map_ptr>   s_bg_map;
bn::optional<bn::regular_bg_ptr>       s_bg;

inline int theme_row_from_id(int id) {
    return id > 0 ? (id - 1) : 0;
}

inline int background_index_for(const theme& t) {
    const int row_base = theme_row_from_id(t.id) * TILES_PER_ROW;
    return row_base + 4; // Spalte 4 = background
}

} // namespace

Renderer::Renderer() {
    renderer_scaler = 1;
    current_theme = basic;
    color = bn::color(16, 16, 16);

    bn::backdrop::set_color(bn::color(0, 0, 0));

    if(!s_inited) {
        // Tiles & Palette direkt aus themes.bmp
        s_tiles   = bn::regular_bg_tiles_items::themes.create_tiles();
        s_palette = bn::bg_palette_items::themes.create_palette();

        // 32x32 Map im VRAM + BG erzeugen
        s_bg_map = bn::regular_bg_map_ptr::allocate(bn::size(BG_COLS, BG_ROWS), *s_tiles, *s_palette);
        s_bg     = bn::regular_bg_ptr::create(*s_bg_map);
        s_bg->set_position(offset_x_map, 0);

        // Initial komplett leeren
        clear_all_tiles();

        s_inited = true;
    }
}

Renderer::~Renderer() = default;

void Renderer::apply_theme(theme& current, theme new_theme) {
    current = new_theme;
    // Sofort alles auf Background der neuen Zeile setzen:
    clear_all_tiles();
}

void Renderer::adjust_scaler(int& scaler, int mul) {
    scaler *= mul;
    if(scaler < 1) {
        scaler = 1;
    }
}

void Renderer::clear_sprites() {
    ui_sprites.clear();
}

void Renderer::clear_all_tiles() {
    if(!s_bg_map) {
        return;
    }
    if(auto vram_opt = s_bg_map->vram()) {
        auto vram = vram_opt.value();
        const int bg_idx = background_index_for(current_theme);
        for(int i = 0; i < BG_COLS * BG_ROWS; ++i) {
            bn::regular_bg_map_cell_info info(vram[i]);
            info.set_tile_index(bg_idx);
            vram[i] = info.cell();
        }
    }
    ui_sprites.clear();
}

void Renderer::draw_map(Map& map) {
    if(!s_bg_map) {
        return;
    }
    auto vram_opt = s_bg_map->vram();
    if(!vram_opt) {
        return;
    }
    auto vram = vram_opt.value();

    // ZWINGEND: vor jedem Frame erst die gesamte 32x32-Map löschen,
    // damit alte Snake-Positionen verschwinden.
    clear_all_tiles();

    // Spielfeld (16x10) mittig in die 32x32-Map
    const int start_col = 8;   // (32 - 16) / 2
    const int start_row = 11;  // (32 - 10) / 2

    const int row_base   = theme_row_from_id(current_theme.id) * TILES_PER_ROW;
    const int bg_index   = row_base + 4; // background
    const int floor_idx  = row_base + 0; // floor (nur falls genutzt)
    const int wall_idx   = row_base + 1; // border
    const int snake_idx  = row_base + 2; // snake
    const int apple_idx  = row_base + 3; // apple

    // map.cpp: 0 = safe area, 1 = border, 2 = player/snake, 3 = apple
    // Wir rendern strikt aus Map: jede Zelle wird genau 1x gesetzt.
    for(int y = 0; y < y_size; ++y) {
        const int row = start_row + y;
        const int base = row * BG_COLS;

        for(int x = 0; x < x_size; ++x) {
            const int col = start_col + x;
            const int idx = base + col;

            const int v = map[y][x];

            int tile_index = bg_index; // default: safe area
            if(v == 1) {
                tile_index = wall_idx;
            } else if(v == 2) {
                tile_index = snake_idx;
            } else if(v == 3) {
                tile_index = apple_idx;
            } else if(v == 4) {
                tile_index = floor_idx;
            }

            bn::regular_bg_map_cell_info info(vram[idx]);
            info.set_tile_index(tile_index);
            vram[idx] = info.cell();
        }
    }
}

void Renderer::render() {
    // optional
}

void Renderer::hide_bg() {
    if(s_bg) {
        s_bg->set_visible(false); // BG unsichtbar schalten
    }
}

void Renderer::show_bg() {
    if(s_bg) {
        s_bg->set_visible(true);  // BG wieder sichtbar schalten
    }
}

void Renderer::shutdown_bg() {
    // Optional: komplettes Freigeben, falls eine „harte“ Rückkehr ins Menü gewünscht ist
    if(s_bg)      { s_bg.reset(); }
    if(s_bg_map)  { s_bg_map.reset(); }
    if(s_palette) { s_palette.reset(); }
    if(s_tiles)   { s_tiles.reset(); }
    s_inited = false;
}

/* Text Renderer */
void Renderer::update_score(int score_value) {
    clear_sprites();
    bn::string<32> score_text;
    bn::ostringstream score_stream(score_text);
    score_stream << "Score: " << score_value;
    _text_generator.generate(offset_x_text, -6, score_text, ui_sprites);
    _text_generator.generate(offset_x_text, 6, "select: stop", ui_sprites);
}