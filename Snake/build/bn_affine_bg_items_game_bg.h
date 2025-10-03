#ifndef BN_AFFINE_BG_ITEMS_GAME_BG_H
#define BN_AFFINE_BG_ITEMS_GAME_BG_H

#include "bn_affine_bg_item.h"

//{{BLOCK(game_bg_bn_gfx)

//======================================================================
//
//	game_bg_bn_gfx, 256x256@8, 
//	+ palette 16 entries, not compressed
//	+ 3 tiles (t reduced) not compressed
//	+ affine map, not compressed, 32x32 
//	Total size: 32 + 192 + 1024 = 1248
//
//	Time-stamp: 2025-10-03, 13:14:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GAME_BG_BN_GFX_H
#define GRIT_GAME_BG_BN_GFX_H

#define game_bg_bn_gfxTilesLen 192
extern const bn::tile game_bg_bn_gfxTiles[6];

#define game_bg_bn_gfxMapLen 1024
extern const bn::affine_bg_map_cell game_bg_bn_gfxMap[1024];

#define game_bg_bn_gfxPalLen 32
extern const bn::color game_bg_bn_gfxPal[16];

#endif // GRIT_GAME_BG_BN_GFX_H

//}}BLOCK(game_bg_bn_gfx)

namespace bn::affine_bg_items
{
    constexpr inline affine_bg_item game_bg(
            affine_bg_tiles_item(span<const tile>(game_bg_bn_gfxTiles, 6), compression_type::NONE), 
            bg_palette_item(span<const color>(game_bg_bn_gfxPal, 16), bpp_mode::BPP_8, compression_type::NONE),
            affine_bg_map_item(game_bg_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

