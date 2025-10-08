#ifndef BN_SOUND_ITEMS_INFO_H
#define BN_SOUND_ITEMS_INFO_H

#include "bn_span.h"
#include "bn_sound_item.h"
#include "bn_string_view.h"

namespace bn::sound_items_info
{
    constexpr inline pair<sound_item, string_view> array[] = {
        make_pair(sound_item(0), string_view("button_press")),
        make_pair(sound_item(1), string_view("game_over")),
        make_pair(sound_item(2), string_view("menu_music")),
        make_pair(sound_item(3), string_view("snake_eating")),
        make_pair(sound_item(4), string_view("start")),
    };

    constexpr inline span<const pair<sound_item, string_view>> span(array);
}

#endif

