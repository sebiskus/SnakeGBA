#ifndef BN_SPRITE_PALETTE_ITEMS_CAVEGIRL_ALT_H
#define BN_SPRITE_PALETTE_ITEMS_CAVEGIRL_ALT_H

#include "bn_sprite_palette_item.h"

//{{BLOCK(cavegirl_alt_bn_gfx)

//======================================================================
//
//	cavegirl_alt_bn_gfx, 8x8@4, 
//	+ palette 16 entries, not compressed
//	Total size: 32 = 32
//
//	Time-stamp: 2025-09-26, 22:53:46
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CAVEGIRL_ALT_BN_GFX_H
#define GRIT_CAVEGIRL_ALT_BN_GFX_H

#define cavegirl_alt_bn_gfxPalLen 32
extern const bn::color cavegirl_alt_bn_gfxPal[16];

#endif // GRIT_CAVEGIRL_ALT_BN_GFX_H

//}}BLOCK(cavegirl_alt_bn_gfx)

namespace bn::sprite_palette_items
{
    constexpr inline sprite_palette_item cavegirl_alt(span<const color>(cavegirl_alt_bn_gfxPal, 16), 
            bpp_mode::BPP_4, compression_type::NONE);
}

#endif

