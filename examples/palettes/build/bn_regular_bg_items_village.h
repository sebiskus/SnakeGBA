#ifndef BN_REGULAR_BG_ITEMS_VILLAGE_H
#define BN_REGULAR_BG_ITEMS_VILLAGE_H

#include "bn_regular_bg_item.h"

//{{BLOCK(village_bn_gfx)

//======================================================================
//
//	village_bn_gfx, 256x256@8, 
//	+ palette 80 entries, not compressed
//	+ 248 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 160 + 15872 + 2048 = 18080
//
//	Time-stamp: 2025-09-26, 22:53:46
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_VILLAGE_BN_GFX_H
#define GRIT_VILLAGE_BN_GFX_H

#define village_bn_gfxTilesLen 15872
extern const bn::tile village_bn_gfxTiles[496];

#define village_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell village_bn_gfxMap[1024];

#define village_bn_gfxPalLen 160
extern const bn::color village_bn_gfxPal[80];

#endif // GRIT_VILLAGE_BN_GFX_H

//}}BLOCK(village_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item village(
            regular_bg_tiles_item(span<const tile>(village_bn_gfxTiles, 496), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(village_bn_gfxPal, 80), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(village_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

