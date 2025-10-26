#ifndef BN_SPRITE_ITEMS_HSV_H
#define BN_SPRITE_ITEMS_HSV_H

#include "bn_sprite_item.h"

//{{BLOCK(hsv_bn_gfx)

//======================================================================
//
//	hsv_bn_gfx, 64x64@8, 
//	+ palette 128 entries, not compressed
//	+ 64 tiles Metatiled by 8x8 not compressed
//	Total size: 256 + 4096 = 4352
//
//	Time-stamp: 2025-10-03, 13:14:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_HSV_BN_GFX_H
#define GRIT_HSV_BN_GFX_H

#define hsv_bn_gfxTilesLen 4096
extern const bn::tile hsv_bn_gfxTiles[128];

#define hsv_bn_gfxPalLen 256
extern const bn::color hsv_bn_gfxPal[128];

#endif // GRIT_HSV_BN_GFX_H

//}}BLOCK(hsv_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item hsv(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(hsv_bn_gfxTiles, 128), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(hsv_bn_gfxPal, 128), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

