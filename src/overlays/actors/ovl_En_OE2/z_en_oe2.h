#ifndef _Z_EN_OE2_H_
#define _Z_EN_OE2_H_

#include "ultra64.h"
#include "global.h"

struct Santa;

typedef void (*SantaActionFunc)(struct Santa*, GlobalContext*);

typedef struct Santa {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ SantaActionFunc actionFunc;
    Vec3s jointTable[18];
    Vec3s morphTable[18];
    ColliderCylinder collider;
    struct_80034A14_arg1 limbAngle;
} Santa; // size = 0x0194

extern const ActorInit En_OE2_InitVars;

#endif
