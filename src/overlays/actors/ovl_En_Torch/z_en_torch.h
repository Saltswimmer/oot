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
    s32 funcIndex;
    s32 primIdx;
    s32 envIdx;
    s32 directionHeld;
    s32 vecIdx;
} EffectsDebugger; // size = 0x014C

typedef struct {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3f velocity;
    /* 0x18 */ Vec3f accel;
    /* 0x2C */ s16 scale;
    /* 0x2E */ s16 scaleStep;
    /* 0x30 */ s16 sclaeStepDecay;
    /* 0x32 */ s16 life;
} Blast; // size = 0x34

typedef struct {
    /* 0x00 */ Actor* actor;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f velocity;
    /* 0x1C */ Vec3f accel;
    /* 0x28 */ Color_RGBA8 primColor;
    /* 0x2C */ Color_RGBA8 envColor;
    /* 0x30 */ s16 scale;
    /* 0x32 */ s16 scaleStep;
    /* 0x34 */ u8 updateMode;
} Spark; // size = 0x38

typedef struct {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3f velocity;
    /* 0x18 */ Vec3f accel;
    /* 0x24 */ s16 scale;
    /* 0x26 */ s16 scaleStep;
    /* 0x28 */ s16 alpha;
    /* 0x2A */ s16 fadeDelay;
    /* 0x2C */ s32 life;
} Dfire; // size = 0x

typedef struct {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3f velocity;
    /* 0x18 */ Vec3f accel;
    /* 0x24 */ Color_RGBA8 primColor;
    /* 0x28 */ Color_RGBA8 envColor;
    /* 0x2C */ s16 alphaStep;
    /* 0x2E */ s16 scale;
    /* 0x30 */ s32 life;
    /* 0x34 */ s16 rotSpeed;
    /* 0x36 */ s16 yaw;
    /* 0x38 */ u8 updateMode;
} Kira; // size = 0x3C

typedef struct {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3f velocity;
    /* 0x18 */ Vec3f accel;
    /* 0x24 */ s16 scale;
    /* 0x26 */ u8 unk_26;
    /* 0x28 */ Actor* actor;
    /* 0x2C */ u8 unk_2C;
} Flash; // size = 0x30

typedef struct {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3f velocity;
    /* 0x18 */ Vec3f accel;
    /* 0x24 */ s16 scale;
    /* 0x26 */ s16 scaleStep;
    /* 0x28 */ Color_RGB8 primColor;
    /* 0x2A */ u8 alpha;
    /* 0x2C */ Color_RGB8 envColor;
    /* 0x30 */ s16 alphaStep;
    /* 0x34 */ s32 life;
    /* 0x38 */ f32 randPosScale;
    /* 0x3C */ s32 num;
    /* 0x40 */ u8 drawMode;
} DeadDd; // size = 0x44

typedef struct {
    /* 0x00 */ Actor* actor;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 scale;
    /* 0x14 */ Vec3f velocity;
    /* 0x20 */ Vec3f accel;
    /* 0x2C */ Color_RGBA8 primColor;
    /* 0x30 */ Color_RGBA8 envColor;
    /* 0x34 */ s32 life;
    /* 0x38 */ s16 type;
} EnIce; // size = 0x3C

#define L_HELD (CHECK_PAD(globalCtx->state.input[2].cur, L_TRIG))
#define Z_HELD (CHECK_PAD(globalCtx->state.input[2].cur, Z_TRIG))
#define R_HELD (CHECK_PAD(globalCtx->state.input[2].cur, R_TRIG))

#define A_PRESSSED (CHECK_PAD(globalCtx->state.input[2].press, A_BUTTON))
#define B_PRESSSED (CHECK_PAD(globalCtx->state.input[2].press, B_BUTTON))

#define DUP_PRESSED (CHECK_PAD(globalCtx->state.input[2].press, U_JPAD))
#define DRIGHT_PRESSED (CHECK_PAD(globalCtx->state.input[2].press, R_JPAD))
#define DDOWN_PRESSED (CHECK_PAD(globalCtx->state.input[2].press, D_JPAD))
#define DLEFT_PRESSED (CHECK_PAD(globalCtx->state.input[2].press, L_JPAD))

#define CUP_PRESSED (CHECK_PAD(globalCtx->state.input[2].press, U_CBUTTONS))
#define CRIGHT_PRESSED (CHECK_PAD(globalCtx->state.input[2].press, R_CBUTTONS))
#define CDOWN_PRESSED (CHECK_PAD(globalCtx->state.input[2].press, D_CBUTTONS))
#define CLEFT_PRESSED (CHECK_PAD(globalCtx->state.input[2].press, L_CBUTTONS))

#define R_PRESSED (CHECK_PAD(globalCtx->state.input[2].press, R_TRIG))

typedef enum {
    ARG_0,
    ARG_1,
    ARG_2,
    ARG_3,
    ARG_4,
    ARG_5,
    ARG_6,
    ARG_7,
    ARG_8,
    ARG_9,
    ARG_10,
    ARG_11,
    ARG_12,
    ARG_13,
    ARG_14,
    ARG_15
} FxArgs;

/*
char* effectNames[] = {
    "Effect_Ss_Dust",      "Effect_Ss_KiraKira",  "Effect_Ss_Bomb",       "Effect_Ss_Bomb2",
    "Effect_Ss_Blast",     "Effect_Ss_G_Spk",     "Effect_Ss_D_Fire",     "Effect_Ss_Bubble",
    "Effect_Ss_G_Ripple",  "Effect_Ss_G_Splash",  "Effect_Ss_G_Magma",    "Effect_Ss_G_Fire",
    "Effect_Ss_Lightning", "Effect_Ss_Dt_Bubble", "Effect_Ss_Hahen",      "Effect_Ss_Stick",
    "Effect_Ss_Sibuki",    "Effect_Ss_Sibuki2",   "Effect_Ss_G_Magma2",   "Effect_Ss_Stone1",
    "Effect_Ss_HitMark",   "Effect_Ss_Fhg_Flash", "Effect_Ss_K_Fire",     "Effect_Ss_Solder_Srch_Ball",
    "Effect_Ss_Kakera",    "Effect_Ss_Ice_Piece", "Effect_Ss_En_Ice",     "Effect_Ss_Fire_Tail",
    "Effect_Ss_En_Fire",   "Effect_Ss_Extra",     "Effect_Ss_Fcircle",    "Effect_Ss_Dead_Db",
    "Effect_Ss_Dead_Dd",   "Effect_Ss_Dead_Ds",   "Effect_Ss_Dead_Sound", "Effect_Ss_Ice_Smoke",
};
*/

extern const ActorInit En_Torch_InitVars;

#endif
