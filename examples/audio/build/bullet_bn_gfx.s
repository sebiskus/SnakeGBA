
@{{BLOCK(bullet_bn_gfx)

@=======================================================================
@
@	bullet_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles Metatiled by 2x2 not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2025-07-20, 10:26:37
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global bullet_bn_gfxTiles		@ 128 unsigned chars
	.hidden bullet_bn_gfxTiles
bullet_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00000000,0xCC000000,0xBBC00000,0x55BC0000,0x445BC000,0xD45BC000
	.word 0x00000000,0x00000000,0x00000000,0x000000CC,0x00000CBB,0x0000CB55,0x000CB544,0x000CB54D
	.word 0xD45BC000,0x445BC000,0x55BC0000,0xBBC00000,0xCC000000,0x00000000,0x00000000,0x00000000
	.word 0x000CB54D,0x000CB544,0x0000CB55,0x00000CBB,0x000000CC,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global bullet_bn_gfxPal		@ 32 unsigned chars
	.hidden bullet_bn_gfxPal
bullet_bn_gfxPal:
	.hword 0x03E0,0x0000,0x20D6,0x28FB,0x1B9F,0x1ADF,0x3AFF,0x32BF
	.hword 0x6BDF,0x157F,0x2A5F,0x19FF,0x197F,0x7FFF,0x001F,0x001F

@}}BLOCK(bullet_bn_gfx)
