#ifndef BN_AFFINE_BG_ITEMS_LOGO_H
#define BN_AFFINE_BG_ITEMS_LOGO_H

#include "bn_affine_bg_item.h"

//{{BLOCK(logo_bn_gfx)

//======================================================================
//
//	logo_bn_gfx, 256x256@8, 
//	+ palette 16 entries, not compressed
//	+ 229 tiles (t reduced) not compressed
//	+ affine map, not compressed, 32x32 
//	Total size: 32 + 14656 + 1024 = 15712
//
//	Time-stamp: 2025-10-22, 13:03:05
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_LOGO_BN_GFX_H
#define GRIT_LOGO_BN_GFX_H

#define logo_bn_gfxTilesLen 14656
extern const bn::tile logo_bn_gfxTiles[458];

#define logo_bn_gfxMapLen 1024
extern const bn::affine_bg_map_cell logo_bn_gfxMap[1024];

#define logo_bn_gfxPalLen 32
extern const bn::color logo_bn_gfxPal[16];

#endif // GRIT_LOGO_BN_GFX_H

//}}BLOCK(logo_bn_gfx)

namespace bn::affine_bg_items
{
    constexpr inline affine_bg_item logo(
            affine_bg_tiles_item(span<const tile>(logo_bn_gfxTiles, 458), compression_type::NONE), 
            bg_palette_item(span<const color>(logo_bn_gfxPal, 16), bpp_mode::BPP_8, compression_type::NONE),
            affine_bg_map_item(logo_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

