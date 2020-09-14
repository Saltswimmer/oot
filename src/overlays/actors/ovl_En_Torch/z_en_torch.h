#ifndef _Z_EN_TORCH_H_
#define _Z_EN_TORCH_H_

#include <ultra64.h>
#include <global.h>

struct EffectsDebugger;

typedef void (*EffectsDebuggerFunc)(struct EffectsDebugger*, struct GlobalContext*, GfxPrint*);

typedef struct EffectsDebugger {
    /* 0x0000 */ Actor actor;
    EffectsDebuggerFunc func;
    s32 effectIndex;
} EffectsDebugger; // size = 0x014C

extern const ActorInit En_Torch_InitVars;

#endif
