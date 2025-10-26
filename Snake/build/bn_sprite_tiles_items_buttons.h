#ifndef BN_SPRITE_TILES_ITEMS_BUTTONS_H
#define BN_SPRITE_TILES_ITEMS_BUTTONS_H

#include "bn_sprite_tiles_item.h"
#include "bn_sprite_shape_size.h"

//{{BLOCK(buttons_bn_gfx)

//======================================================================
//
//	buttons_bn_gfx, 64x64@8, 
//	+ 64 tiles Metatiled by 4x1 not compressed
//	Total size: 4096 = 4096
//
//	Time-stamp: 2025-10-07, 11:51:17
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BUTTONS_BN_GFX_H
#define GRIT_BUTTONS_BN_GFX_H

#define buttons_bn_gfxTilesLen 4096
extern const bn::tile buttons_bn_gfxTiles[128];

#endif // GRIT_BUTTONS_BN_GFX_H

//}}BLOCK(buttons_bn_gfx)

namespace bn::sprite_tiles_items
{
    constexpr inline sprite_tiles_item buttons(span<const tile>(buttons_bn_gfxTiles, 128), 
            bpp_mode::BPP_8, compression_type::NONE, 16);

    constexpr inline sprite_shape_size buttons_shape_size(sprite_shape::WIDE, sprite_size::NORMAL);
}

#endif

