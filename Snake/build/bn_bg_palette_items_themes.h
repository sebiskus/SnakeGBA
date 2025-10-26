#ifndef BN_BG_PALETTE_ITEMS_THEMES_H
#define BN_BG_PALETTE_ITEMS_THEMES_H

#include "bn_bg_palette_item.h"

//{{BLOCK(themes_bn_gfx)

//======================================================================
//
//	themes_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	Total size: 32 = 32
//
//	Time-stamp: 2025-10-07, 15:48:25
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_THEMES_BN_GFX_H
#define GRIT_THEMES_BN_GFX_H

#define themes_bn_gfxPalLen 32
extern const bn::color themes_bn_gfxPal[16];

#endif // GRIT_THEMES_BN_GFX_H

//}}BLOCK(themes_bn_gfx)

namespace bn::bg_palette_items
{
    constexpr inline bg_palette_item themes(span<const color>(themes_bn_gfxPal, 16), 
            bpp_mode::BPP_8, compression_type::NONE);
}

#endif

