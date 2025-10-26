#ifndef BN_REGULAR_BG_TILES_ITEMS_THEMES_H
#define BN_REGULAR_BG_TILES_ITEMS_THEMES_H

#include "bn_regular_bg_tiles_item.h"
#include "bn_bg_palette_item.h"

//{{BLOCK(themes_bn_gfx)

//======================================================================
//
//	themes_bn_gfx, 128x128@8, 
//	+ palette 16 entries, not compressed
//	+ 256 tiles not compressed
//	Total size: 32 + 16384 = 16416
//
//	Time-stamp: 2025-10-24, 09:57:11
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_THEMES_BN_GFX_H
#define GRIT_THEMES_BN_GFX_H

#define themes_bn_gfxTilesLen 16384
extern const bn::tile themes_bn_gfxTiles[512];

#define themes_bn_gfxPalLen 32
extern const bn::color themes_bn_gfxPal[16];

#endif // GRIT_THEMES_BN_GFX_H

//}}BLOCK(themes_bn_gfx)

namespace bn::regular_bg_tiles_items
{
    constexpr inline regular_bg_tiles_item themes(
            span<const tile>(themes_bn_gfxTiles, 512), bpp_mode::BPP_8, compression_type::NONE);

    constexpr inline bg_palette_item themes_palette(span<const color>(themes_bn_gfxPal, 16), 
            bpp_mode::BPP_8, compression_type::NONE);
}

#endif

