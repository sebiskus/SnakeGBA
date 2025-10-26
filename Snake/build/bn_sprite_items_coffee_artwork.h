#ifndef BN_SPRITE_ITEMS_COFFEE_ARTWORK_H
#define BN_SPRITE_ITEMS_COFFEE_ARTWORK_H

#include "bn_sprite_item.h"

//{{BLOCK(coffee_artwork_bn_gfx)

//======================================================================
//
//	coffee_artwork_bn_gfx, 64x64@8, 
//	+ palette 256 entries, not compressed
//	+ 64 tiles Metatiled by 8x8 not compressed
//	Total size: 512 + 4096 = 4608
//
//	Time-stamp: 2025-10-03, 13:14:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_COFFEE_ARTWORK_BN_GFX_H
#define GRIT_COFFEE_ARTWORK_BN_GFX_H

#define coffee_artwork_bn_gfxTilesLen 4096
extern const bn::tile coffee_artwork_bn_gfxTiles[128];

#define coffee_artwork_bn_gfxPalLen 512
extern const bn::color coffee_artwork_bn_gfxPal[256];

#endif // GRIT_COFFEE_ARTWORK_BN_GFX_H

//}}BLOCK(coffee_artwork_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item coffee_artwork(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(coffee_artwork_bn_gfxTiles, 128), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(coffee_artwork_bn_gfxPal, 256), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

