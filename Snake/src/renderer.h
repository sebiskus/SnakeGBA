#ifndef RENDERER_H
#define RENDERER_H

#include "bn_core.h"
#include "bn_vector.h"
#include "bn_sstream.h"
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

    void hide_bg();
    void show_bg();
    void shutdown_bg();

    void clear_sprites();
    void clear_all_tiles();

};

#endif
