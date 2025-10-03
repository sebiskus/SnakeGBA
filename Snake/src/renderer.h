#ifndef RENDERER_H
#define RENDERER_H


#include "bn_core.h"
#include "bn_display.h"
#include "bn_vector.h"
#include "bn_sstream.h"

#include "bn_color.h"
#include "bn_sprites.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_actions.h"
#include "bn_sprite_palettes.h"
#include "bn_sprite_palette_ptr.h"
#include "bn_backdrop.h"

#include "map.h"
#include "color_palette.h"
#include "graphics.h"

#include "bn_sprite_font.h"
#include "bn_sprite_text_generator.h"

/*
TODO
- Custom Themes
- Switch/Case wechselt die ptr durch

*/

const int offset_x_score = -100;
const int offset_x_map = 30;
const int render_cycles = 4;

class Renderer {
    private:
    bn::sprite_text_generator _text_generator{common::variable_8x8_sprite_font};
    bn::vector<bn::sprite_ptr, 16> ui_sprites;  // Für Score/Time Text

    public:

    int renderer_scaler = 1;
    bn::vector<bn::sprite_ptr, 160> squares; //Maximale Map Größe 16x10

    //TODO
    theme current_theme = basic;
    bn::color color = bn::color(1,1,1); 

    Renderer();
    ~Renderer(){}

    void apply_theme(theme& current_theme, theme new_theme) {
        current_theme = new_theme;
    }
    void adjust_scaler(int& renderer_scaler, int multiplication) {
            renderer_scaler = multiplication;
    }

    void update_score(int score_value);
    void clear_sprites();

    bn::color rgb_to_bn_color(const rgb& color);


    void map_renderer(Map& map, 
        int renderer_scaler, 
        bn::vector<bn::sprite_ptr, 160>& squares, 
        theme current_theme);
    void reset_renderer(Renderer& renderer) {
        renderer = Renderer();
        bn::backdrop::set_color(bn::color(0, 0, 0));
    };
    
};


#endif