#ifndef BN_SPRITE_ITEMS_SNAKE_ARTWORK_H
#define BN_SPRITE_ITEMS_SNAKE_ARTWORK_H

#include "bn_sprite_item.h"

//{{BLOCK(snake_artwork_bn_gfx)

//======================================================================
//
//	snake_artwork_bn_gfx, 64x64@8, 
//	+ palette 240 entries, not compressed
//	+ 64 tiles Metatiled by 8x8 not compressed
//	Total size: 480 + 4096 = 4576
//
//	Time-stamp: 2025-10-03, 13:14:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SNAKE_ARTWORK_BN_GFX_H
#define GRIT_SNAKE_ARTWORK_BN_GFX_H

#define snake_artwork_bn_gfxTilesLen 4096
extern const bn::tile snake_artwork_bn_gfxTiles[128];

#define snake_artwork_bn_gfxPalLen 480
extern const bn::color snake_artwork_bn_gfxPal[240];

#endif // GRIT_SNAKE_ARTWORK_BN_GFX_H

//}}BLOCK(snake_artwork_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item snake_artwork(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(snake_artwork_bn_gfxTiles, 128), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(snake_artwork_bn_gfxPal, 240), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

