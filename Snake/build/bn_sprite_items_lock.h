#ifndef BN_SPRITE_ITEMS_LOCK_H
#define BN_SPRITE_ITEMS_LOCK_H

#include "bn_sprite_item.h"

//{{BLOCK(lock_bn_gfx)

//======================================================================
//
//	lock_bn_gfx, 64x64@8, 
//	+ palette 160 entries, not compressed
//	+ 64 tiles Metatiled by 8x8 not compressed
//	Total size: 320 + 4096 = 4416
//
//	Time-stamp: 2025-10-03, 13:14:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_LOCK_BN_GFX_H
#define GRIT_LOCK_BN_GFX_H

#define lock_bn_gfxTilesLen 4096
extern const bn::tile lock_bn_gfxTiles[128];

#define lock_bn_gfxPalLen 320
extern const bn::color lock_bn_gfxPal[160];

#endif // GRIT_LOCK_BN_GFX_H

//}}BLOCK(lock_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item lock(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(lock_bn_gfxTiles, 128), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(lock_bn_gfxPal, 160), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

