#ifndef BN_SPRITE_ITEMS_APPLE_SQUARE_H
#define BN_SPRITE_ITEMS_APPLE_SQUARE_H

#include "bn_sprite_item.h"

//{{BLOCK(apple_square_bn_gfx)

//======================================================================
//
//	apple_square_bn_gfx, 8x8@8, 
//	+ palette 32 entries, not compressed
//	+ 1 tiles not compressed
//	Total size: 64 + 64 = 128
//
//	Time-stamp: 2025-10-03, 13:14:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_APPLE_SQUARE_BN_GFX_H
#define GRIT_APPLE_SQUARE_BN_GFX_H

#define apple_square_bn_gfxTilesLen 64
extern const bn::tile apple_square_bn_gfxTiles[2];

#define apple_square_bn_gfxPalLen 64
extern const bn::color apple_square_bn_gfxPal[32];

#endif // GRIT_APPLE_SQUARE_BN_GFX_H

//}}BLOCK(apple_square_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item apple_square(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(apple_square_bn_gfxTiles, 2), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(apple_square_bn_gfxPal, 32), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

