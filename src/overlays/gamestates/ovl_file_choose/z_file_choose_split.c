#include "ultra64.h"
#include "global.h"

s32 D_80811BB0[] = { 0xFFA20048, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFFDA0048, 0x00000000, 0x07000000, 0xFFFFFFFF,
                     0xFFA20038, 0x00000000, 0x00000200, 0xFFFFFFFF, 0xFFDA0038, 0x00000000, 0x07000200, 0xFFFFFFFF,
                     0xFFA0FFD0, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFFCCFFD0, 0x00000000, 0x05800000, 0xFFFFFFFF,
                     0xFFA0FFC0, 0x00000000, 0x00000200, 0xFFFFFFFF, 0xFFCCFFC0, 0x00000000, 0x05800200, 0xFFFFFFFF,
                     0xFFD0FFD0, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFFFCFFD0, 0x00000000, 0x05800000, 0xFFFFFFFF,
                     0xFFD0FFC0, 0x00000000, 0x00000200, 0xFFFFFFFF, 0xFFFCFFC0, 0x00000000, 0x05800200, 0xFFFFFFFF,
                     0x0000FFD0, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x001CFFD0, 0x00000000, 0x03800000, 0xFFFFFFFF,
                     0x0000FFC0, 0x00000000, 0x00000200, 0xFFFFFFFF, 0x001CFFC0, 0x00000000, 0x03800200, 0xFFFFFFFF,
                     0x0020FFD0, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x003CFFD0, 0x00000000, 0x03800000, 0xFFFFFFFF,
                     0x0020FFC0, 0x00000000, 0x00000200, 0xFFFFFFFF, 0x003CFFC0, 0x00000000, 0x03800200, 0xFFFFFFFF,
                     0x0040FFD0, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x006CFFD0, 0x00000000, 0x05800000, 0xFFFFFFFF,
                     0x0040FFC0, 0x00000000, 0x00000200, 0xFFFFFFFF, 0x006CFFC0, 0x00000000, 0x05800200, 0xFFFFFFFF };
s32 D_80811D30[] = { 0xFFA20048, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00220048, 0x00000000, 0x10000000, 0xFFFFFFFF,
                     0xFFA20038, 0x00000000, 0x00000200, 0xFFFFFFFF, 0x00220038, 0x00000000, 0x10000200, 0xFFFFFFFF,
                     0xFF9C002C, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFFDC002C, 0x00000000, 0x08000000, 0xFFFFFFFF,
                     0xFF9C001C, 0x00000000, 0x00000200, 0xFFFFFFFF, 0xFFDC001C, 0x00000000, 0x08000200, 0xFFFFFFFF,
                     0xFF9C0004, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFFDC0004, 0x00000000, 0x08000000, 0xFFFFFFFF,
                     0xFF9CFFF4, 0x00000000, 0x00000200, 0xFFFFFFFF, 0xFFDCFFF4, 0x00000000, 0x08000200, 0xFFFFFFFF,
                     0xFF9CFFDC, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x001CFFDC, 0x00000000, 0x10000000, 0xFFFFFFFF,
                     0xFF9CFFCC, 0x00000000, 0x00000200, 0xFFFFFFFF, 0x001CFFCC, 0x00000000, 0x10000200, 0xFFFFFFFF };
s32 D_80811E30[] = { 0xFFA20048, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00220048, 0x00000000, 0x10000000, 0xFFFFFFFF,
                     0xFFA20038, 0x00000000, 0x00000200, 0xFFFFFFFF, 0x00220038, 0x00000000, 0x10000200, 0xFFFFFFFF,
                     0xFF9C002C, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFFDC002C, 0x00000000, 0x08000000, 0xFFFFFFFF,
                     0xFF9C001C, 0x00000000, 0x00000200, 0xFFFFFFFF, 0xFFDC001C, 0x00000000, 0x08000200, 0xFFFFFFFF,
                     0xFF9C0004, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x002C0004, 0x00000000, 0x12000000, 0xFFFFFFFF,
                     0xFF9CFFF4, 0x00000000, 0x00000200, 0xFFFFFFFF, 0x002CFFF4, 0x00000000, 0x12000200, 0xFFFFFFFF,
                     0xFF9CFFDC, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x001CFFDC, 0x00000000, 0x10000000, 0xFFFFFFFF,
                     0xFF9CFFCC, 0x00000000, 0x00000200, 0xFFFFFFFF, 0x001CFFCC, 0x00000000, 0x10000200, 0xFFFFFFFF };
s32 D_80811F30[] = { 0xFF9C001A, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFFCC001A, 0x00000000, 0x06000000, 0xFFFFFFFF,
                     0xFF9C000A, 0x00000000, 0x00000200, 0xFFFFFFFF, 0xFFCC000A, 0x00000000, 0x06000200, 0xFFFFFFFF,
                     0xFFD0001A, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x0000001A, 0x00000000, 0x06000000, 0xFFFFFFFF,
                     0xFFD0000A, 0x00000000, 0x00000200, 0xFFFFFFFF, 0x0000000A, 0x00000000, 0x06000200, 0xFFFFFFFF,
                     0x0004001A, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x0034001A, 0x00000000, 0x06000000, 0xFFFFFFFF,
                     0x0004000A, 0x00000000, 0x00000200, 0xFFFFFFFF, 0x0034000A, 0x00000000, 0x06000200, 0xFFFFFFFF,
                     0x0038001A, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x0068001A, 0x00000000, 0x06000000, 0xFFFFFFFF,
                     0x0038000A, 0x00000000, 0x00000200, 0xFFFFFFFF, 0x0068000A, 0x00000000, 0x06000200, 0xFFFFFFFF,
                     0xFF9CFFF2, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFFCCFFF2, 0x00000000, 0x06000000, 0xFFFFFFFF,
                     0xFF9CFFE2, 0x00000000, 0x00000200, 0xFFFFFFFF, 0xFFCCFFE2, 0x00000000, 0x06000200, 0xFFFFFFFF,
                     0xFFD0FFF2, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x0000FFF2, 0x00000000, 0x06000000, 0xFFFFFFFF,
                     0xFFD0FFE2, 0x00000000, 0x00000200, 0xFFFFFFFF, 0x0000FFE2, 0x00000000, 0x06000200, 0xFFFFFFFF,
                     0xFF9CFFCA, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFFFCFFCA, 0x00000000, 0x0C000000, 0xFFFFFFFF,
                     0xFF9CFFBA, 0x00000000, 0x00000200, 0xFFFFFFFF, 0xFFFCFFBA, 0x00000000, 0x0C000200, 0xFFFFFFFF,
                     0xFFFCFFCA, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x005CFFCA, 0x00000000, 0x0C000000, 0xFFFFFFFF,
                     0xFFFCFFBA, 0x00000000, 0x00000200, 0xFFFFFFFF, 0x005CFFBA, 0x00000000, 0x0C000200, 0xFFFFFFFF };
s32 D_80812130[] = { 0xFF9C001A, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFFCC001A, 0x00000000, 0x06000000, 0xFFFFFFFF,
                     0xFF9C000A, 0x00000000, 0x00000200, 0xFFFFFFFF, 0xFFCC000A, 0x00000000, 0x06000200, 0xFFFFFFFF,
                     0xFFD0001A, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x0000001A, 0x00000000, 0x06000000, 0xFFFFFFFF,
                     0xFFD0000A, 0x00000000, 0x00000200, 0xFFFFFFFF, 0x0000000A, 0x00000000, 0x06000200, 0xFFFFFFFF,
                     0x0004001A, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x0034001A, 0x00000000, 0x06000000, 0xFFFFFFFF,
                     0x0004000A, 0x00000000, 0x00000200, 0xFFFFFFFF, 0x0034000A, 0x00000000, 0x06000200, 0xFFFFFFFF,
                     0x0038001A, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x0068001A, 0x00000000, 0x06000000, 0xFFFFFFFF,
                     0x0038000A, 0x00000000, 0x00000200, 0xFFFFFFFF, 0x0068000A, 0x00000000, 0x06000200, 0xFFFFFFFF,
                     0xFF9CFFF2, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFFECFFF2, 0x00000000, 0x0A000000, 0xFFFFFFFF,
                     0xFF9CFFE2, 0x00000000, 0x00000200, 0xFFFFFFFF, 0xFFECFFE2, 0x00000000, 0x0A000200, 0xFFFFFFFF,
                     0xFFF0FFF2, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x0040FFF2, 0x00000000, 0x0A000000, 0xFFFFFFFF,
                     0xFFF0FFE2, 0x00000000, 0x00000200, 0xFFFFFFFF, 0x0040FFE2, 0x00000000, 0x0A000200, 0xFFFFFFFF,
                     0xFF9CFFCA, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFFFCFFCA, 0x00000000, 0x0C000000, 0xFFFFFFFF,
                     0xFF9CFFBA, 0x00000000, 0x00000200, 0xFFFFFFFF, 0xFFFCFFBA, 0x00000000, 0x0C000200, 0xFFFFFFFF,
                     0xFFFCFFCA, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x005CFFCA, 0x00000000, 0x0C000000, 0xFFFFFFFF,
                     0xFFFCFFBA, 0x00000000, 0x00000200, 0xFFFFFFFF, 0x005CFFBA, 0x00000000, 0x0C000200, 0xFFFFFFFF };
s32 D_80812330[] = { 0xFF9C001C, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x009C001C, 0x00000000, 0x20000000, 0xFFFFFFFF,
                     0xFF9C001A, 0x00000000, 0x00000040, 0xFFFFFFFF, 0x009C001A, 0x00000000, 0x20000040, 0xFFFFFFFF };
s32 D_80812370[] = { 0xFF9CFFF4, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x009CFFF4, 0x00000000, 0x20000000, 0xFFFFFFFF,
                     0xFF9CFFF2, 0x00000000, 0x00000040, 0xFFFFFFFF, 0x009CFFF2, 0x00000000, 0x20000040, 0xFFFFFFFF };
s32 D_808123B0[] = { 0xFF9CFFCC, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x009CFFCC, 0x00000000, 0x20000000, 0xFFFFFFFF,
                     0xFF9CFFCA, 0x00000000, 0x00000040, 0xFFFFFFFF, 0x009CFFCA, 0x00000000, 0x20000040, 0xFFFFFFFF };
s32 D_808123F0[] = { 0x000A000B, 0x000C000D, 0x000E000F, 0x00100011, 0x00120013, 0x00140015, 0x00160017, 0x00180019,
                     0x001A001B, 0x001C001D, 0x001E001F, 0x00200021, 0x00220023, 0x00240025, 0x00260027, 0x00280029,
                     0x002A002B, 0x002C002D, 0x002E002F, 0x00300031, 0x00320033, 0x00340035, 0x00360037, 0x00380039,
                     0x003A003B, 0x003C003D, 0x00010002, 0x00030004, 0x00050006, 0x00070008, 0x00090000, 0x0040003F,
                     0x003E0000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_80812480[] = { 0xFFD0FFD0, 0xFFD0FFE8, 0xFFE80000 };
s32 D_8081248C[] = { 0x0000FFD0, 0xFFD0FFC0, 0x0010FFD0, 0xFFC0FFC0, 0x00200000 };
s32 D_808124A0[] = { 0x000F0000 };
s32 D_808124A4[] = { 0xFFC8FFD8, 0xFFE80000 };
s32 D_808124AC[] = { 0x00000010, 0x00200000, 0x00000000, 0x00000000, 0x00000000 };

s16 D_80813800;

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80803D40.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80803ED8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80804248.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_808043D8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_808044A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80804858.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80804924.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80804A50.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80804C74.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80804CD0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80804ED8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080510C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_808051C8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80805318.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80805434.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80805524.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80805824.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080595C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80805B2C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80805EB8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80806180.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080625C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80806444.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_808064F4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80806710.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_808068F0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_808069B4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80806C20.s")