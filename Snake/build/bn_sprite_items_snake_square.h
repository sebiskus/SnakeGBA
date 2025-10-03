#ifndef BN_SPRITE_ITEMS_SNAKE_SQUARE_H
#define BN_SPRITE_ITEMS_SNAKE_SQUARE_H

#include "bn_sprite_item.h"

//{{BLOCK(snake_square_bn_gfx)

//======================================================================
//
//	snake_square_bn_gfx, 8x8@8, 
//	+ palette 32 entries, not compressed
//	+ 1 tiles not compressed
//	Total size: 64 + 64 = 128
//
//	Time-stamp: 2025-10-03, 13:14:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SNAKE_SQUARE_BN_GFX_H
#define GRIT_SNAKE_SQUARE_BN_GFX_H

#define snake_square_bn_gfxTilesLen 64
extern const bn::tile snake_square_bn_gfxTiles[2];

#define snake_square_bn_gfxPalLen 64
extern const bn::color snake_square_bn_gfxPal[32];

#endif // GRIT_SNAKE_SQUARE_BN_GFX_H

//}}BLOCK(snake_square_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item snake_square(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(snake_square_bn_gfxTiles, 2), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(snake_square_bn_gfxPal, 32), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

