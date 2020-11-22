#ifndef _Z_EN_GANON_MANT_H_
#define _Z_EN_GANON_MANT_H_

#include "ultra64.h"
#include "global.h"

struct EnGanonMant;

typedef struct EnGanonMant {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ char unk_14C[0x1560];
    /* 0x16AC */ f32 unk_16AC;
    /* 0x16B0 */ f32 unk_16B0;
    /* 0x16B4 */ f32 unk_16B4;
    /* 0x16B8 */ f32 unk_16B8;
    /* 0x16BC */ f32 unk_16BC;
    /* 0x16C0 */ f32 unk_16C0;
    /* 0x16C4 */ f32 unk_16C4;
    /* 0x16C8 */ f32 unk_16C8;
    /* 0x16CC */ char unk_16CC[0x4];
    /* 0x16D0 */ f32 unk_16D0;
    /* 0x16D4 */ char unk_16D4[0x30];
    /* 0x1704 */ u8 unk_1704;
    // 3 bytes, might be pad
} EnGanonMant; // size = 0x1708

extern const ActorInit En_Ganon_Mant_InitVars;

#endif
