#ifndef _Z_EN_OE2_H_
#define _Z_EN_OE2_H_

#include "ultra64.h"
#include "global.h"

struct EnOE2;

typedef void (*EnOE2ActionFunc)(struct EnOE2*, GlobalContext*);

typedef struct EnOE2 {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    Vec3s jointTable[39];
    Vec3s morphTable[39];
    s16 blinkTimer;
    u8 eyeIndex;
    ColliderCylinder collider;
    struct_80034A14_arg1 angleThing;
    /* 0x0190 */ EnOE2ActionFunc actionFunc;
} EnOE2; // size = 0x0194

extern const ActorInit En_OE2_InitVars;

#endif
