#ifndef BN_SPRITE_ITEMS_REAL_MADRID_H
#define BN_SPRITE_ITEMS_REAL_MADRID_H

#include "bn_sprite_item.h"

//{{BLOCK(real_madrid_bn_gfx)

//======================================================================
//
//	real_madrid_bn_gfx, 64x64@8, 
//	+ palette 256 entries, not compressed
//	+ 64 tiles Metatiled by 8x8 not compressed
//	Total size: 512 + 4096 = 4608
//
//	Time-stamp: 2025-10-03, 13:14:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_REAL_MADRID_BN_GFX_H
#define GRIT_REAL_MADRID_BN_GFX_H

#define real_madrid_bn_gfxTilesLen 4096
extern const bn::tile real_madrid_bn_gfxTiles[128];

#define real_madrid_bn_gfxPalLen 512
extern const bn::color real_madrid_bn_gfxPal[256];

#endif // GRIT_REAL_MADRID_BN_GFX_H

//}}BLOCK(real_madrid_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item real_madrid(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(real_madrid_bn_gfxTiles, 128), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(real_madrid_bn_gfxPal, 256), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

