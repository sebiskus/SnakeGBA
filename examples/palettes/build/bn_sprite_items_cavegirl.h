#ifndef BN_SPRITE_ITEMS_CAVEGIRL_H
#define BN_SPRITE_ITEMS_CAVEGIRL_H

#include "bn_sprite_item.h"

//{{BLOCK(cavegirl_bn_gfx)

//======================================================================
//
//	cavegirl_bn_gfx, 64x64@4, 
//	+ palette 16 entries, not compressed
//	+ 64 tiles Metatiled by 8x8 not compressed
//	Total size: 32 + 2048 = 2080
//
//	Time-stamp: 2025-09-26, 22:53:46
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CAVEGIRL_BN_GFX_H
#define GRIT_CAVEGIRL_BN_GFX_H

#define cavegirl_bn_gfxTilesLen 2048
extern const bn::tile cavegirl_bn_gfxTiles[64];

#define cavegirl_bn_gfxPalLen 32
extern const bn::color cavegirl_bn_gfxPal[16];

#endif // GRIT_CAVEGIRL_BN_GFX_H

//}}BLOCK(cavegirl_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item cavegirl(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(cavegirl_bn_gfxTiles, 64), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(cavegirl_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

