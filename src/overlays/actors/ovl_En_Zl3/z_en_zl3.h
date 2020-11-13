#ifndef _Z_EN_ZL3_H_
#define _Z_EN_ZL3_H_

#include "ultra64.h"
#include "global.h"

struct EnZl3;

typedef struct EnZl3 {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ char unk_14C[0x27C];
    /* 0x03C8 */ u8 unk_3C8;
    /* 0x03C9 */ char unk_3C9[0x57];
} EnZl3; // size = 0x0420

extern const ActorInit En_Zl3_InitVars;

#endif
