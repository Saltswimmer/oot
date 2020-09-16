
#include "z_en_torch.h"
#include <alloca.h>

// replaces line 55 in spot00_room_0.c
// { ACTOR_EN_OWL, 4284, 182, 7877, 0, 0, 0, 0x004C }, //0x00000A24
// with
// { ACTOR_EN_TORCH, 100, 80, 1580, 0, 0, 0, 0 }

#define FLAGS 0x00000030

#define THIS ((EffectsDebugger*)thisx)

#define SPAWN_EFFECT globalCtx->state.frames % sRate == 0

void EffectsDebugger_Init(Actor* thisx, GlobalContext* globalCtx);
void EffectsDebugger_Update(Actor* thisx, GlobalContext* globalCtx);

void EffectsDebugger_SetupDeadDd(EffectsDebugger* this, GlobalContext* globalCtx, GfxPrint* printer);
void EffectsDebugger_SetupKira(EffectsDebugger* this, GlobalContext* globalCtx, GfxPrint* printer);
void EffectsDebugger_SetupBlast(EffectsDebugger* this, GlobalContext* globalCtx, GfxPrint* printer);
void EffectsDebugger_SetupSpark(EffectsDebugger* this, GlobalContext* globalCtx, GfxPrint* printer);
void EffectsDebugger_SetupDfire(EffectsDebugger* this, GlobalContext* globalCtx, GfxPrint* printer);
void EffectsDebugger_SetupFlash(EffectsDebugger* this, GlobalContext* globalCtx, GfxPrint* printer);

EffectsDebuggerFunc setupFuncs[] = {
    EffectsDebugger_SetupDeadDd, EffectsDebugger_SetupFlash, EffectsDebugger_SetupKira,
    EffectsDebugger_SetupBlast,  EffectsDebugger_SetupSpark,
};

const ActorInit En_Torch_InitVars = {
    ACTOR_EN_TORCH,
    ACTORTYPE_EXPLOSIVES, // ACTORTYPE_EXPLOSIVES
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EffectsDebugger),
    (ActorFunc)EffectsDebugger_Init,
    NULL,
    (ActorFunc)EffectsDebugger_Update,
    NULL,
};

static Vec3f sZeroVec = { 0.0f, 0.0f, 0.0f };

typedef struct {
    char* name;
    Color_RGBA8 color;
} FxColors;

FxColors fxColors[] = {
    { "red", { 245, 70, 65, 255 } },     { "orange", { 250, 160, 60, 255 } },     { "yellow", { 250, 250, 60, 255 } },
    { "green", { 70, 250, 60, 255 } },   { "light blue", { 60, 230, 250, 255 } }, { "blue", { 50, 80, 255, 255 } },
    { "purple", { 190, 50, 255, 255 } }, { "white", { 255, 255, 255, 255 } },     { "black", { 0, 0, 0, 255 } },
    { "gray", { 120, 120, 120, 255 } },
};

char* effectNames[] = {
    "Effect_Ss_KiraKira", "Effect_Ss_Blast", "Effect_Ss_G_Spk",
    //"Effect_Ss_D_Fire",
};

static s32 sRate;
static Color_RGBA8 primColor;
static Color_RGBA8 envColor;
static Vec3f velocity;
static Vec3f accel;

// effect params
Blast blast;
Spark spark;
Dfire dfire;
Kira kira;
Flash flash;
DeadDd deaddd;

void EffectsDebugger_UpdateFuncIndex(EffectsDebugger* this, GlobalContext* globalCtx, char* funcArray, s32 size) {
    if (!this->directionHeld) {
        if (globalCtx->state.input[2].cur.in.x > 7) {
            this->directionHeld = true;
            this->funcIndex++;
            if (this->funcIndex == size) {
                this->funcIndex = 0;
            }
        } else if (globalCtx->state.input[2].cur.in.x < -7) {
            this->directionHeld = true;
            this->funcIndex--;
            if (this->funcIndex == -1) {
                this->funcIndex = size - 1;
            }
        }
    }
}
void EffectsDebugger_UpdateArg8(GlobalContext* globalCtx, GfxPrint* printer, s32 argNum, s8* field, char* name,
                                s32 amount) {
    switch (argNum) {
        case ARG_0:
            if (L_HELD && DUP_PRESSED) {
                *field -= amount;
            } else if (DUP_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 5);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 5);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_1:
            if (L_HELD && DRIGHT_PRESSED) {
                *field -= amount;
            } else if (DRIGHT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 6);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 6);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_2:
            if (L_HELD && DDOWN_PRESSED) {
                *field -= amount;
            } else if (DDOWN_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 7);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 7);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_3:
            if (L_HELD && DLEFT_PRESSED) {
                *field -= amount;
            } else if (DLEFT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 8);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 8);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_4:
            if (L_HELD && CUP_PRESSED) {
                *field -= amount;
            } else if (CUP_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 9);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 9);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_5:
            if (L_HELD && CRIGHT_PRESSED) {
                *field -= amount;
            } else if (CRIGHT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 10);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 10);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_6:
            if (L_HELD && CDOWN_PRESSED) {
                *field -= amount;
            } else if (CDOWN_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 11);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 11);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_7:
            if (L_HELD && CLEFT_PRESSED) {
                *field -= amount;
            } else if (CLEFT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 12);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 12);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_8:
            if (Z_HELD && L_HELD && DUP_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && DUP_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 13);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 13);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_9:
            if (Z_HELD && L_HELD && DRIGHT_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && DRIGHT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 14);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 14);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_10:
            if (Z_HELD && L_HELD && DDOWN_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && DDOWN_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 15);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 15);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_11:
            if (Z_HELD && L_HELD && DLEFT_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && DLEFT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 16);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 16);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_12:
            if (Z_HELD && L_HELD && CUP_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && CUP_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 17);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 17);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_13:
            if (Z_HELD && L_HELD && CRIGHT_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && CRIGHT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 18);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 18);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_14:
            if (Z_HELD && L_HELD && CDOWN_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && CDOWN_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 19);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 19);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_15:
            if (Z_HELD && L_HELD && CLEFT_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && CLEFT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 20);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 20);
            GfxPrint_Printf(printer, "%d", *field);
            break;
    }
}
void EffectsDebugger_UpdateArg16(GlobalContext* globalCtx, GfxPrint* printer, s32 argNum, s16* field, char* name,
                                 s32 amount) {
    switch (argNum) {
        case ARG_0:
            if (L_HELD && DUP_PRESSED) {
                *field -= amount;
            } else if (DUP_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 5);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 5);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_1:
            if (L_HELD && DRIGHT_PRESSED) {
                *field -= amount;
            } else if (DRIGHT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 6);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 6);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_2:
            if (L_HELD && DDOWN_PRESSED) {
                *field -= amount;
            } else if (DDOWN_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 7);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 7);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_3:
            if (L_HELD && DLEFT_PRESSED) {
                *field -= amount;
            } else if (DLEFT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 8);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 8);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_4:
            if (L_HELD && CUP_PRESSED) {
                *field -= amount;
            } else if (CUP_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 9);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 9);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_5:
            if (L_HELD && CRIGHT_PRESSED) {
                *field -= amount;
            } else if (CRIGHT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 10);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 10);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_6:
            if (L_HELD && CDOWN_PRESSED) {
                *field -= amount;
            } else if (CDOWN_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 11);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 11);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_7:
            if (L_HELD && CLEFT_PRESSED) {
                *field -= amount;
            } else if (CLEFT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 12);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 12);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_8:
            if (Z_HELD && L_HELD && DUP_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && DUP_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 13);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 13);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_9:
            if (Z_HELD && L_HELD && DRIGHT_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && DRIGHT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 14);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 14);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_10:
            if (Z_HELD && L_HELD && DDOWN_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && DDOWN_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 15);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 15);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_11:
            if (Z_HELD && L_HELD && DLEFT_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && DLEFT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 16);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 16);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_12:
            if (Z_HELD && L_HELD && CUP_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && CUP_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 17);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 17);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_13:
            if (Z_HELD && L_HELD && CRIGHT_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && CRIGHT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 18);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 18);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_14:
            if (Z_HELD && L_HELD && CDOWN_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && CDOWN_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 19);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 19);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_15:
            if (Z_HELD && L_HELD && CLEFT_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && CLEFT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 20);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 20);
            GfxPrint_Printf(printer, "%d", *field);
            break;
    }
}
void EffectsDebugger_UpdateArg32(GlobalContext* globalCtx, GfxPrint* printer, s32 argNum, s32* field, char* name,
                                 s32 amount) {
    switch (argNum) {
        case ARG_0:
            if (L_HELD && DUP_PRESSED) {
                *field -= amount;
            } else if (DUP_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 5);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 5);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_1:
            if (L_HELD && DRIGHT_PRESSED) {
                *field -= amount;
            } else if (DRIGHT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 6);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 6);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_2:
            if (L_HELD && DDOWN_PRESSED) {
                *field -= amount;
            } else if (DDOWN_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 7);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 7);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_3:
            if (L_HELD && DLEFT_PRESSED) {
                *field -= amount;
            } else if (DLEFT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 8);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 8);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_4:
            if (L_HELD && CUP_PRESSED) {
                *field -= amount;
            } else if (CUP_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 9);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 9);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_5:
            if (L_HELD && CRIGHT_PRESSED) {
                *field -= amount;
            } else if (CRIGHT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 10);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 10);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_6:
            if (L_HELD && CDOWN_PRESSED) {
                *field -= amount;
            } else if (CDOWN_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 11);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 11);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_7:
            if (L_HELD && CLEFT_PRESSED) {
                *field -= amount;
            } else if (CLEFT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 12);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 12);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_8:
            if (Z_HELD && L_HELD && DUP_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && DUP_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 13);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 13);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_9:
            if (Z_HELD && L_HELD && DRIGHT_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && DRIGHT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 14);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 14);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_10:
            if (Z_HELD && L_HELD && DDOWN_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && DDOWN_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 15);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 15);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_11:
            if (Z_HELD && L_HELD && DLEFT_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && DLEFT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 16);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 16);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_12:
            if (Z_HELD && L_HELD && CUP_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && CUP_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 17);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 17);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_13:
            if (Z_HELD && L_HELD && CRIGHT_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && CRIGHT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 18);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 18);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_14:
            if (Z_HELD && L_HELD && CDOWN_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && CDOWN_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 19);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 19);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_15:
            if (Z_HELD && L_HELD && CLEFT_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && CLEFT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 20);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 20);
            GfxPrint_Printf(printer, "%d", *field);
            break;
    }
}
void EffectsDebugger_UpdateArgF(GlobalContext* globalCtx, GfxPrint* printer, s32 argNum, f32* field, char* name,
                                f32 amount) {
    switch (argNum) {
        case ARG_0:
            if (L_HELD && DUP_PRESSED) {
                *field -= amount;
            } else if (DUP_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 5);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 5);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_1:
            if (L_HELD && DRIGHT_PRESSED) {
                *field -= amount;
            } else if (DRIGHT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 6);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 6);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_2:
            if (L_HELD && DDOWN_PRESSED) {
                *field -= amount;
            } else if (DDOWN_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 7);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 7);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_3:
            if (L_HELD && DLEFT_PRESSED) {
                *field -= amount;
            } else if (DLEFT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 8);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 8);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_4:
            if (L_HELD && CUP_PRESSED) {
                *field -= amount;
            } else if (CUP_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 9);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 9);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_5:
            if (L_HELD && CRIGHT_PRESSED) {
                *field -= amount;
            } else if (CRIGHT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 10);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 10);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_6:
            if (L_HELD && CDOWN_PRESSED) {
                *field -= amount;
            } else if (CDOWN_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 11);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 11);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_7:
            if (L_HELD && CLEFT_PRESSED) {
                *field -= amount;
            } else if (CLEFT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 12);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 12);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_8:
            if (Z_HELD && L_HELD && DUP_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && DUP_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 13);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 13);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_9:
            if (Z_HELD && L_HELD && DRIGHT_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && DRIGHT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 14);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 14);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_10:
            if (Z_HELD && L_HELD && DDOWN_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && DDOWN_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 15);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 15);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_11:
            if (Z_HELD && L_HELD && DLEFT_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && DLEFT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 16);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 16);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_12:
            if (Z_HELD && L_HELD && CUP_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && CUP_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 17);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 17);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_13:
            if (Z_HELD && L_HELD && CRIGHT_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && CRIGHT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 18);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 18);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_14:
            if (Z_HELD && L_HELD && CDOWN_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && CDOWN_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 19);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 19);
            GfxPrint_Printf(printer, "%d", *field);
            break;
        case ARG_15:
            if (Z_HELD && L_HELD && CLEFT_PRESSED) {
                *field -= amount;
            } else if (Z_HELD && CLEFT_PRESSED) {
                *field += amount;
            }
            GfxPrint_SetPos(printer, 1, 20);
            GfxPrint_Printf(printer, "%s:", name);
            GfxPrint_SetPos(printer, strlen(name) + 2, 20);
            GfxPrint_Printf(printer, "%d", *field);
            break;
    }
}

void EffectsDebugger_Init(Actor* thisx, GlobalContext* globalCtx) {
    EffectsDebugger* this = THIS;
    sRate = 10;
    this->effectIndex = 0;
    this->directionHeld = false;
    this->func = setupFuncs[0];
    velocity.x = velocity.y = velocity.z = 0.0f;
    accel.x = accel.y = accel.z = 0.0f;
    this->primIdx = 7;
    this->vecIdx = 0;
}

char* deadddFuncs[] = { "func_8002A770", "func_8002A824" };

void EffectsDebugger_DeadDd(EffectsDebugger* this, GlobalContext* globalCtx, GfxPrint* printer) {
    s32 size = ARRAY_COUNT(deadddFuncs);
    EffectsDebugger_UpdateFuncIndex(this, globalCtx, deadddFuncs, size);

    GfxPrint_SetPos(printer, 1, 3);
    GfxPrint_Printf(printer, "%s", deadddFuncs[this->funcIndex]);

    switch (this->funcIndex) {
        case 0:
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_0, &deaddd.scale, "scale", 10);
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_1, &deaddd.scaleStep, "scaleStep", 1);
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_2, &deaddd.alphaStep, "alphaStep", 1);
            EffectsDebugger_UpdateArg32(globalCtx, printer, ARG_3, &deaddd.life, "life", 1);
            if (SPAWN_EFFECT) {
                func_8002A770(globalCtx, &deaddd.pos, &velocity, &accel, deaddd.scale, deaddd.scaleStep, 0, 0, 255, 255,
                              255, 255, 255, deaddd.alphaStep, deaddd.life);
            }
            break;
        case 1:
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_0, &deaddd.scale, "scale", 10);
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_1, &deaddd.scaleStep, "scaleStep", 1);
            EffectsDebugger_UpdateArgF(globalCtx, printer, ARG_2, &deaddd.randPosScale, "randPosScale", 1.0f);
            EffectsDebugger_UpdateArg32(globalCtx, printer, ARG_3, &deaddd.num, "num", 1);
            EffectsDebugger_UpdateArg32(globalCtx, printer, ARG_4, &deaddd.life, "life", 1);
            if (SPAWN_EFFECT) {
                func_8002A824(globalCtx, &deaddd.pos, deaddd.scale, deaddd.scaleStep, deaddd.randPosScale, deaddd.num,
                              deaddd.life);
            }
            break;
    }
}

void EffectsDebugger_SetupDeadDd(EffectsDebugger* this, GlobalContext* globalCtx, GfxPrint* printer) {
    deaddd.pos = this->actor.posRot.pos;
    deaddd.velocity = velocity;
    deaddd.accel = accel;
    deaddd.scale = 0x96;
    deaddd.scaleStep = -0x19;
    deaddd.alphaStep = 0x10;
    deaddd.life = 0x14;
    deaddd.randPosScale = 0.0f;
    deaddd.num = 0;
    this->func = EffectsDebugger_DeadDd;
}

char* flashFuncs[] = { "func_80029CF0_type0", "func_80029D5C_type1" };

void EffectsDebugger_Flash(EffectsDebugger* this, GlobalContext* globalCtx, GfxPrint* printer) {
    s32 size = ARRAY_COUNT(flashFuncs);
    EffectsDebugger_UpdateFuncIndex(this, globalCtx, flashFuncs, size);

    GfxPrint_SetPos(printer, 1, 3);
    GfxPrint_Printf(printer, "%s", flashFuncs[this->funcIndex]);

    switch (this->funcIndex) {
        case 0:
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_0, &flash.scale, "scale", 10);
            EffectsDebugger_UpdateArg8(globalCtx, printer, ARG_1, &flash.unk_26, "unk_26", 1);
            if (SPAWN_EFFECT) {
                func_80029CF0(globalCtx, &flash.pos, &velocity, &accel, flash.scale, flash.unk_26);
            }
            break;
        case 1:
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_0, &flash.scale, "scale", 10);
            EffectsDebugger_UpdateArg8(globalCtx, printer, ARG_1, &flash.unk_26, "unk_26", 1);
            if (SPAWN_EFFECT) {
                func_80029D5C(globalCtx, PLAYER, &flash.pos, flash.scale, flash.unk_26);
            }
            break;
    }
}

void EffectsDebugger_SetupFlash(EffectsDebugger* this, GlobalContext* globalCtx, GfxPrint* printer) {
    flash.pos = this->actor.posRot.pos;
    flash.scale = 1000;
    flash.unk_26 = 0;
    this->funcIndex = 0;
    Object_Spawn(&globalCtx->objectCtx, OBJECT_FHG);
    this->func = EffectsDebugger_Flash;
}

char* kiraFuncs[] = { "SpawnSmallYellow", "SpawnSmall", "func_80028BB0", "func_80028CEC" };

void EffectsDebugger_Kira(EffectsDebugger* this, GlobalContext* globalCtx, GfxPrint* printer) {
    s32 size = ARRAY_COUNT(kiraFuncs);
    EffectsDebugger_UpdateFuncIndex(this, globalCtx, kiraFuncs, size);

    GfxPrint_SetPos(printer, 1, 3);
    GfxPrint_Printf(printer, "%s", kiraFuncs[this->funcIndex]);

    switch (this->funcIndex) {
        case 0:
            if (SPAWN_EFFECT) {
                EffectSsKiraKira_SpawnSmallYellow(globalCtx, &kira.pos, &velocity, &accel);
            }
            break;
        case 1:
            if (SPAWN_EFFECT) {
                EffectSsKiraKira_SpawnSmall(globalCtx, &kira.pos, &velocity, &accel, &primColor, &envColor);
            }
            break;
        case 2:
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_0, &kira.scale, "scale", 100);
            EffectsDebugger_UpdateArg32(globalCtx, printer, ARG_1, &kira.life, "life", 1);
            if (SPAWN_EFFECT) {
                func_80028BB0(globalCtx, &kira.pos, &velocity, &accel, &primColor, &envColor, kira.scale, kira.life);
            }
            break;
        case 3:
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_0, &kira.scale, "scale", 100);
            EffectsDebugger_UpdateArg32(globalCtx, printer, ARG_1, &kira.life, "life", 1);
            if (SPAWN_EFFECT) {
                func_80028CEC(globalCtx, &kira.pos, &velocity, &accel, &primColor, &envColor, kira.scale, kira.life);
            }
            break;
    }
}

void EffectsDebugger_SetupKira(EffectsDebugger* this, GlobalContext* globalCtx, GfxPrint* printer) {
    kira.pos = this->actor.posRot.pos;
    kira.scale = 1000;
    kira.life = 16;
    this->funcIndex = 0;
    this->func = EffectsDebugger_Kira;
}

char* dfireFuncs[] = { "EffectSsDFire_Spawn", "func_800293A0" };

void EffectsDebugger_Dfire(EffectsDebugger* this, GlobalContext* globalCtx, GfxPrint* printer) {
    s32 size = ARRAY_COUNT(dfireFuncs);
    EffectsDebugger_UpdateFuncIndex(this, globalCtx, dfireFuncs, size);

    GfxPrint_SetPos(printer, 1, 3);
    GfxPrint_Printf(printer, "%s", dfireFuncs[this->funcIndex]);

    switch (this->funcIndex) {
        case 0:
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_0, &dfire.scale, "scale", 1);
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_1, &dfire.scaleStep, "scaleStep", 1);
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_2, &dfire.alpha, "alpha", 10);
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_3, &dfire.fadeDelay, "fadeDelay", 10);
            EffectsDebugger_UpdateArg32(globalCtx, printer, ARG_4, &dfire.life, "life", 10);
            if (SPAWN_EFFECT) {
                EffectSsDFire_Spawn(globalCtx, &dfire.pos, &velocity, &accel, dfire.scale, dfire.scaleStep, dfire.alpha,
                                    dfire.fadeDelay, dfire.life);
            }
            break;
    }
}

void EffectsDebugger_SetupDfire(EffectsDebugger* this, GlobalContext* globalCtx, GfxPrint* printer) {
    dfire.pos = this->actor.posRot.pos;
    dfire.scale = 100;
    dfire.scaleStep = 35;
    dfire.alpha = 255;
    dfire.fadeDelay = 10;
    dfire.life = 50;
    this->funcIndex = 0;
    Object_Spawn(&globalCtx->objectCtx, OBJECT_DODONGO);
    this->func = EffectsDebugger_Dfire;
}

char* sparkFuncs[] = { "func_80029060_mode0", "func_80029060_mode1", "func_80029184", "func_800291D8",
                       "func_800292DC" };

void EffectsDebugger_Spark(EffectsDebugger* this, GlobalContext* globalCtx, GfxPrint* printer) {
    s32 size = ARRAY_COUNT(sparkFuncs);
    EffectsDebugger_UpdateFuncIndex(this, globalCtx, sparkFuncs, size);

    GfxPrint_SetPos(printer, 1, 3);
    GfxPrint_Printf(printer, "%s", sparkFuncs[this->funcIndex]);

    switch (this->funcIndex) {
        case 0:
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_0, &spark.scale, "scale", 1);
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_1, &spark.scaleStep, "scaleStep", 1);
            if (SPAWN_EFFECT) {
                func_80029060(globalCtx, spark.actor, &spark.pos, &velocity, &accel, &primColor, &envColor, spark.scale,
                              spark.scaleStep);
            }
            break;
        case 1:
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_0, &spark.scale, "scale", 1);
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_1, &spark.scaleStep, "scaleStep", 1);
            if (SPAWN_EFFECT) {
                func_80029060(globalCtx, spark.actor, &spark.pos, &velocity, &accel, &primColor, &envColor, spark.scale,
                              spark.scaleStep);
            }
            break;
        case 2:
            if (SPAWN_EFFECT) {
                func_80029184(globalCtx, spark.actor, &spark.pos, &velocity, &accel);
            }
            break;
        case 3:
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_0, &spark.scale, "scale", 1);
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_1, &spark.scaleStep, "scaleStep", 1);
            if (SPAWN_EFFECT) {
                func_800291D8(globalCtx, spark.actor, &spark.pos, &velocity, &accel, spark.scale, spark.scaleStep);
            }
            break;
        case 4:
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_0, &spark.scale, "scale", 1);
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_1, &spark.scaleStep, "scaleStep", 1);
            if (SPAWN_EFFECT) {
                func_800292DC(globalCtx, spark.actor, &spark.pos, &velocity, &accel, &primColor, &envColor);
            }
            break;
    }
}

void EffectsDebugger_SetupSpark(EffectsDebugger* this, GlobalContext* globalCtx, GfxPrint* printer) {
    spark.pos = this->actor.posRot.pos;
    spark.actor = this;
    spark.scale = 100;
    spark.scaleStep = 5;
    spark.updateMode = 0;
    this->funcIndex = 0;
    this->func = EffectsDebugger_Spark;
}

char* blastFuncs[] = { "EffectSsBlast_Spawn", "func_80028F84", "func_80028FD8", "func_80029024" };

void EffectsDebugger_Blast(EffectsDebugger* this, GlobalContext* globalCtx, GfxPrint* printer) {
    s32 size = ARRAY_COUNT(blastFuncs);
    EffectsDebugger_UpdateFuncIndex(this, globalCtx, blastFuncs, size);

    GfxPrint_SetPos(printer, 1, 3);
    GfxPrint_Printf(printer, "%s", blastFuncs[this->funcIndex]);

    switch (this->funcIndex) {
        case 0:
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_0, &blast.scale, "scale", 10);
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_1, &blast.scaleStep, "scaleStep", 10);
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_2, &blast.sclaeStepDecay, "sclaeStepDecay", 10);
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_3, &blast.life, "life", 1);
            if (SPAWN_EFFECT) {
                EffectSsBlast_Spawn(globalCtx, &blast.pos, &velocity, &accel, &primColor, &envColor, blast.scale,
                                    blast.scaleStep, blast.sclaeStepDecay, blast.life);
            }
            break;
        case 1:
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_0, &blast.scale, "scale", 10);
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_1, &blast.scaleStep, "scaleStep", 10);
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_2, &blast.life, "life", 1);
            if (SPAWN_EFFECT) {
                func_80028F84(globalCtx, &blast.pos, &velocity, &accel, blast.scale, blast.scaleStep, blast.life);
            }
            break;
        case 2:
            EffectsDebugger_UpdateArg16(globalCtx, printer, ARG_0, &blast.life, "life", 1);
            if (SPAWN_EFFECT) {
                func_80028FD8(globalCtx, &blast.pos, &velocity, &accel, &primColor, &envColor, blast.life);
            }
            break;
        case 3:
            if (SPAWN_EFFECT) {
                func_80029024(globalCtx, &blast.pos, &velocity, &accel);
            }
            break;
    }
}

void EffectsDebugger_SetupBlast(EffectsDebugger* this, GlobalContext* globalCtx, GfxPrint* printer) {
    blast.pos = this->actor.posRot.pos;
    blast.scale = 100;
    blast.scaleStep = 375;
    blast.sclaeStepDecay = 35;
    blast.life = 10;
    this->funcIndex = 0;
    this->func = EffectsDebugger_Blast;
}

void EffectsDebugger_Update(Actor* thisx, GlobalContext* globalCtx) {
    EffectsDebugger* this = THIS;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    GfxPrint* printer;

    Interface_ChangeAlpha(0);
    gSaveContext.dayTime = 0x8000;
    gSaveContext.naviTimer = 0;

    printer = alloca(sizeof(GfxPrint));
    GfxPrint_Init(printer);
    GfxPrint_Open(printer, gfxCtx->polyOpa.p);

    GfxPrint_SetPos(printer, 1, 1);
    GfxPrint_SetColor(printer, 255, 255, 255, 255);
    GfxPrint_Printf(printer, "%s", effectNames[this->effectIndex]);

    if (this->directionHeld) {
        if ((globalCtx->state.input[2].cur.in.x < 7) && (globalCtx->state.input[2].cur.in.x > -7) &&
            (globalCtx->state.input[2].cur.in.y < 7) && (globalCtx->state.input[2].cur.in.y > -7)) {
            this->directionHeld = false;
        }
    }

    if (!this->directionHeld) {
        if (globalCtx->state.input[2].cur.in.y > 7) {
            this->directionHeld = true;
            this->effectIndex++;
            if (this->effectIndex == ARRAY_COUNT(effectNames)) {
                this->effectIndex = 0;
            }
            this->func = setupFuncs[this->effectIndex];
        } else if (globalCtx->state.input[2].cur.in.y < -7) {
            this->directionHeld = true;
            this->effectIndex--;
            if (this->effectIndex == -1) {
                this->effectIndex = ARRAY_COUNT(effectNames) - 1;
            }
            this->func = setupFuncs[this->effectIndex];
        }
    }

    if (R_PRESSED) {
        this->vecIdx++;
        if (this->vecIdx == 3) {
            this->vecIdx = 0;
        }
    }

    if (Z_HELD && DUP_PRESSED) {
        if (this->vecIdx == 0) {
            velocity.x += 0.1f;
        }
        if (this->vecIdx == 1) {
            velocity.y += 0.1f;
        }
        if (this->vecIdx == 2) {
            velocity.z += 0.1f;
        }
    }

    if (Z_HELD && DDOWN_PRESSED) {
        if (this->vecIdx == 0) {
            velocity.x -= 0.1f;
        }
        if (this->vecIdx == 1) {
            velocity.y -= 0.1f;
        }
        if (this->vecIdx == 2) {
            velocity.z -= 0.1f;
        }
    }

    if (Z_HELD && CUP_PRESSED) {
        if (this->vecIdx == 0) {
            accel.x += 0.1f;
        }
        if (this->vecIdx == 1) {
            accel.y += 0.1f;
        }
        if (this->vecIdx == 2) {
            accel.z += 0.1f;
        }
    }

    if (Z_HELD && CDOWN_PRESSED) {
        if (this->vecIdx == 0) {
            accel.x -= 0.1f;
        }
        if (this->vecIdx == 1) {
            accel.y -= 0.1f;
        }
        if (this->vecIdx == 2) {
            accel.z -= 0.1f;
        }
    }
    GfxPrint_SetPos(printer, 11, 25);
    GfxPrint_Printf(printer, "vel   x: %.2f y: %.2f z: %.2f", velocity.x, velocity.y, velocity.z);
    GfxPrint_SetPos(printer, 11, 26);
    GfxPrint_Printf(printer, "accel x: %.2f y: %.2f z: %.2f", accel.x, accel.y, accel.z);
    GfxPrint_SetPos(printer, 11, 27);
    GfxPrint_Printf(printer, "vec:");
    GfxPrint_SetPos(printer, 16, 27);
    if (this->vecIdx == 0) {
        GfxPrint_Printf(printer, "x");
    }
    if (this->vecIdx == 1) {
        GfxPrint_Printf(printer, "y");
    }
    if (this->vecIdx == 2) {
        GfxPrint_Printf(printer, "z");
    }

    if (L_HELD && A_PRESSSED) {
        this->primIdx--;
        if (this->primIdx == -1) {
            this->primIdx = ARRAY_COUNT(fxColors) - 1;
        }
    } else if (L_HELD && B_PRESSSED) {
        this->envIdx--;
        if (this->envIdx == -1) {
            this->envIdx = ARRAY_COUNT(fxColors) - 1;
        }
    } else if (A_PRESSSED) {
        this->primIdx++;
        if (this->primIdx == ARRAY_COUNT(fxColors)) {
            this->primIdx = 0;
        }
    } else if (B_PRESSSED) {
        this->envIdx++;
        if (this->envIdx == ARRAY_COUNT(fxColors)) {
            this->envIdx = 0;
        }
    }

    if (R_HELD && CUP_PRESSED) {
        sRate++;
    } else if (R_HELD && CDOWN_PRESSED) {
        sRate--;
        if (sRate == 0) {
            sRate = 1;
        }
    }
    GfxPrint_SetPos(printer, 20, 4);
    GfxPrint_SetColor(printer, 255, 255, 255, 255);
    GfxPrint_Printf(printer, "rate: %d", sRate);

    primColor = fxColors[this->primIdx].color;
    envColor = fxColors[this->envIdx].color;

    GfxPrint_SetPos(printer, 20, 1);
    GfxPrint_Printf(printer, "prim:");
    GfxPrint_SetPos(printer, 20, 2);
    GfxPrint_Printf(printer, "env:");

    GfxPrint_SetPos(printer, 25, 1);
    GfxPrint_SetColor(printer, fxColors[this->primIdx].color.r, fxColors[this->primIdx].color.g,
                      fxColors[this->primIdx].color.b, 255);
    GfxPrint_Printf(printer, "%s", fxColors[this->primIdx].name);

    GfxPrint_SetPos(printer, 25, 2);
    GfxPrint_SetColor(printer, fxColors[this->envIdx].color.r, fxColors[this->envIdx].color.g,
                      fxColors[this->envIdx].color.b, 255);
    GfxPrint_Printf(printer, "%s", fxColors[this->envIdx].name);

    GfxPrint_SetColor(printer, 255, 255, 255, 255);

    this->func(this, globalCtx, printer);

    gfxCtx->polyOpa.p = GfxPrint_Close(printer);
    GfxPrint_Destroy(printer);
}
