#ifndef RENDERER_H
#define RENDERER_H

#include "bn_core.h"
#include "bn_vector.h"
#include "bn_sstream.h"
#include "bn_backdrop.h"
#include "bn_optional.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_tiles_ptr.h"
#include "bn_regular_bg_map_ptr.h"
#include "bn_regular_bg_map_cell_info.h"
#include "bn_bg_palette_ptr.h"

#include "bn_color.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"

#include "map.h"
#include "color_palette.h"
#include "graphics.h"

/* Padding hinzufügen zwischen Map und Text */
constexpr int offset_x_text = -100;
constexpr int offset_x_map   = 30;

class Renderer
{
private:
    bn::sprite_text_generator _text_generator{common::variable_8x8_sprite_font};
    bn::vector<bn::sprite_ptr, 64> ui_sprites;

    bool s_inited = false;

    bn::optional<bn::regular_bg_tiles_ptr> s_tiles;
    bn::optional<bn::bg_palette_ptr>       s_palette, s_old_palette;
    bn::optional<bn::regular_bg_map_ptr>   s_bg_map;
    bn::optional<bn::regular_bg_ptr>       s_bg;

    int BG_COLS = 32;
    int BG_ROWS = 32;

public:
    theme current_theme = basic; //default
    bn::color color = bn::color(16, 16, 16);

    Renderer();
    ~Renderer();

    /* Score-Text renderer */
    void update_score(int score_value);

    /* Theme wechseln */
    void apply_theme(theme& current, theme new_theme);

    void draw_map(Map& map);

    void render();

    void save_current_palette();
    void load_palette();    //Palette vom Renderer laden
    void unload_palette();  //Ursprüngliche Palette zurück in den Speicher laden

    void hide_bg();
    void show_bg();
    void shutdown_bg();

    void clear_sprites();
    void clear_all_tiles();

};

#endif
