#ifndef BN_REGULAR_BG_ITEMS_THEMES_H
#define BN_REGULAR_BG_ITEMS_THEMES_H

#include "bn_regular_bg_item.h"

//{{BLOCK(themes_bn_gfx)

//======================================================================
//
//	themes_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 15 tiles (t|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 480 + 2048 = 2560
//
//	Time-stamp: 2025-10-03, 13:14:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_THEMES_BN_GFX_H
#define GRIT_THEMES_BN_GFX_H

#define themes_bn_gfxTilesLen 480
extern const bn::tile themes_bn_gfxTiles[15];

#define themes_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell themes_bn_gfxMap[1024];

#define themes_bn_gfxPalLen 32
extern const bn::color themes_bn_gfxPal[16];

#endif // GRIT_THEMES_BN_GFX_H

//}}BLOCK(themes_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item themes(
            regular_bg_tiles_item(span<const tile>(themes_bn_gfxTiles, 15), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(themes_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(themes_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

