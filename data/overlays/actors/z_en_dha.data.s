.include "macro.inc"

 # assembler directives
 .set noat      # allow manual use of $at
 .set noreorder # don't insert nops after branches
 .set gp=64     # allow use of 64-bit general purposee registers

.section .data

glabel En_Dha_InitVars
 .word 0x00A50500, 0x00000015, 0x00A60000, 0x00000360
.word EnDha_Init
.word EnDha_Destroy
.word EnDha_Update
.word EnDha_Draw
glabel D_809ED650
 .word 0x00F20000, 0x00000000, 0xF2F2F400, 0x00000000, 0x00000000, 0x0000F2F4, 0xF2F4F8F4, 0x0000F400
glabel D_809ED670
 .word 0x00000000, 0x00000000, 0x00000000, 0xFFCFFFFF, 0x00000000, 0x00010000, 0x01000000, 0x00000000, 0x000C0064, 0x00000000, 0x00000000, 0x00000000, 0xFFCFFFFF, 0x00000000, 0x00010100, 0x02000C80, 0x00000000, 0x000A0064, 0x00000000, 0x00000000, 0x00000000, 0xFFCFFFFF, 0x00000000, 0x00010100, 0x030004B0, 0x00000000, 0x000A0064, 0x00000000, 0x00000000, 0x00000000, 0xFFCFFFFF, 0x00000000, 0x00010000, 0x04000A8C, 0x00000000, 0x000A0064, 0x00000000, 0x00000000, 0x00000000, 0xFFCFFFFF, 0x00000000, 0x00010100, 0x050004B0, 0x00000000, 0x000A0064
glabel D_809ED724
 .word 0x06000919, 0x10000000, 0x00000005
.word D_809ED670
glabel D_809ED734
 .word 0x8917002E, 0xB04C07D0, 0x4850000A
glabel D_809ED740
 .word 0x00000000, 0x00000000, 0x00000000
glabel D_809ED74C
 .word 0x00000000, 0x00000000, 0x425C0000
glabel D_809ED758
 .word 0x00000000, 0x00000000, 0xC2580000
glabel D_809ED764
 .word 0x44898000, 0x00000000, 0x00000000
glabel D_809ED770
 .word 0x00000000, 0x00000000, 0x00000000, 0x00000000
