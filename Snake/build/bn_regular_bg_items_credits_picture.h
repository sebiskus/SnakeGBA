#ifndef BN_REGULAR_BG_ITEMS_CREDITS_PICTURE_H
#define BN_REGULAR_BG_ITEMS_CREDITS_PICTURE_H

#include "bn_regular_bg_item.h"

//{{BLOCK(credits_picture_bn_gfx)

//======================================================================
//
//	credits_picture_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 55 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 1760 + 2048 = 3840
//
//	Time-stamp: 2025-10-16, 13:06:07
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CREDITS_PICTURE_BN_GFX_H
#define GRIT_CREDITS_PICTURE_BN_GFX_H

#define credits_picture_bn_gfxTilesLen 1760
extern const bn::tile credits_picture_bn_gfxTiles[55];

#define credits_picture_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell credits_picture_bn_gfxMap[1024];

#define credits_picture_bn_gfxPalLen 32
extern const bn::color credits_picture_bn_gfxPal[16];

#endif // GRIT_CREDITS_PICTURE_BN_GFX_H

//}}BLOCK(credits_picture_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item credits_picture(
            regular_bg_tiles_item(span<const tile>(credits_picture_bn_gfxTiles, 55), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(credits_picture_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(credits_picture_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

