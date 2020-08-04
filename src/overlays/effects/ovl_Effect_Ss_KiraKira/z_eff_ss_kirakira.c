/*
 * File: z_eff_ss_kirakira.c
 * Overlay: ovl_Effect_Ss_KiraKira
 * Description: Sparkles
 */

#include "z_eff_ss_kirakira.h"

typedef enum {
    /* 0x00 */ SS_KIRAKIRA_YAW_STEP,
    /* 0x01 */ SS_KIRAKIRA_YAW,
    /* 0x02 */ SS_KIRAKIRA_PRIM_R,
    /* 0x03 */ SS_KIRAKIRA_PRIM_G,
    /* 0x04 */ SS_KIRAKIRA_PRIM_B,
    /* 0x05 */ SS_KIRAKIRA_PRIM_A,
    /* 0x06 */ SS_KIRAKIRA_ENV_R,
    /* 0x07 */ SS_KIRAKIRA_ENV_G,
    /* 0x08 */ SS_KIRAKIRA_ENV_B,
    /* 0x09 */ SS_KIRAKIRA_ENV_A,
    /* 0x0A */ SS_KIRAKIRA_A,
    /* 0x0B */ SS_KIRAKIRA_SCALE,
    /* 0x0C */ SS_KIRAKIRA_C
} EffectSsKiraKiraRegs;

u32 EffectSsKiraKira_Init(GlobalContext* globalCtx, u32 index, EffectSs* this, void* initParamsx);
void func_809AA9AC(GlobalContext* globalCtx, u32 index, EffectSs* this);
void func_809AABF0(GlobalContext* globalCtx, u32 index, EffectSs* this);
void func_809AACAC(GlobalContext* globalCtx, u32 index, EffectSs* this);
void func_809AAD6C(GlobalContext* globalCtx, u32 index, EffectSs* this);

EffectSsInit Effect_Ss_KiraKira_InitVars = {
    EFFECT_SS_KIRAKIRA,
    EffectSsKiraKira_Init,
};

extern Gfx D_04037880[];

u32 EffectSsKiraKira_Init(GlobalContext* globalCtx, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsKiraKiraInitParams* initParams = (EffectSsKiraKiraInitParams*)initParamsx;

    this->pos = initParams->pos;
    this->velocity = initParams->velocity;
    this->accel = initParams->accel;

    if ((this->life = initParams->life) < 0) {
        this->life = -this->life;
        this->displayList = SEGMENTED_TO_VIRTUAL(D_04037880);
        this->update = func_809AAD6C;
        this->regs[SS_KIRAKIRA_ENV_A] = initParams->scale;
        this->regs[SS_KIRAKIRA_SCALE] = 0;
    } else {
        this->displayList = SEGMENTED_TO_VIRTUAL(D_04037880);

        if (initParams->unk_38 == 0) {
            this->update = func_809AABF0;
        } else {
            this->update = func_809AACAC;
        }

        this->regs[SS_KIRAKIRA_ENV_A] = initParams->envColor.a;
        this->regs[SS_KIRAKIRA_SCALE] = initParams->scale;
    }

    this->draw = func_809AA9AC;
    this->regs[SS_KIRAKIRA_YAW_STEP] = initParams->unk_34;
    this->regs[SS_KIRAKIRA_YAW] = initParams->unk_36;
    this->regs[SS_KIRAKIRA_PRIM_R] = initParams->primColor.r;
    this->regs[SS_KIRAKIRA_PRIM_G] = initParams->primColor.g;
    this->regs[SS_KIRAKIRA_PRIM_B] = initParams->primColor.b;
    this->regs[SS_KIRAKIRA_PRIM_A] = initParams->primColor.a;
    this->regs[SS_KIRAKIRA_ENV_R] = initParams->envColor.r;
    this->regs[SS_KIRAKIRA_ENV_G] = initParams->envColor.g;
    this->regs[SS_KIRAKIRA_ENV_B] = initParams->envColor.b;
    this->regs[SS_KIRAKIRA_A] = initParams->unk_2C;
    this->regs[SS_KIRAKIRA_C] = initParams->life;

    return 1;
}

void func_809AA9AC(GlobalContext* globalCtx, u32 index, EffectSs* this) {
    GraphicsContext* localGfxCtx;
    f32 scale;
    s32 pad2;
    MtxF mtxTrans;
    MtxF mtxRotY;
    MtxF mtxScale;
    MtxF mtxPersTrans;
    MtxF mtxRotYPersTrans;
    MtxF mtxResult;
    Mtx* mtx;
    GraphicsContext* gfxCtx;
    Gfx* dispRefs[4];

    scale = this->regs[SS_KIRAKIRA_SCALE] / 10000.0f;
    localGfxCtx = globalCtx->state.gfxCtx;

    gfxCtx = localGfxCtx;
    Graph_OpenDisps(&dispRefs, localGfxCtx, "../z_eff_ss_kirakira.c", 257);

    func_800A7A24(&mtxTrans, this->pos.x, this->pos.y, this->pos.z);
    func_800A7704(&mtxRotY, 0, 0, this->regs[SS_KIRAKIRA_YAW]);
    func_800A76A4(&mtxScale, scale, scale, 1.0f);
    func_800A6FA0(&mtxTrans, &globalCtx->mf_11DA0, &mtxPersTrans);
    func_800A6FA0(&mtxPersTrans, &mtxRotY, &mtxRotYPersTrans);
    func_800A6FA0(&mtxRotYPersTrans, &mtxScale, &mtxResult);
    gSPMatrix(gfxCtx->polyXlu.p++, &gMtxClear, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    
    mtx = func_800A7E70(gfxCtx, &mtxResult);

    if (mtx != NULL) {
        gSPMatrix(gfxCtx->polyXlu.p++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        func_80093C14(gfxCtx);
        gDPSetPrimColor(gfxCtx->polyXlu.p++, 0x80, 0x80, this->regs[SS_KIRAKIRA_PRIM_R], this->regs[SS_KIRAKIRA_PRIM_G],
                        this->regs[SS_KIRAKIRA_PRIM_B],
                        (((s8) ((55.0f / this->regs[SS_KIRAKIRA_C]) * this->life) + 200)));
        gDPSetEnvColor(gfxCtx->polyXlu.p++, this->regs[SS_KIRAKIRA_ENV_R], this->regs[SS_KIRAKIRA_ENV_G],
                       this->regs[SS_KIRAKIRA_ENV_B], this->regs[SS_KIRAKIRA_ENV_A]);
        gSPDisplayList(gfxCtx->polyXlu.p++, this->displayList);
    }
    
    Graph_CloseDisps(&dispRefs, localGfxCtx, "../z_eff_ss_kirakira.c", 301);
}

void func_809AABF0(GlobalContext* globalCtx, u32 index, EffectSs* this) {
    this->accel.x = (Math_Rand_ZeroOne() * 0.4f) - 0.2f;
    this->accel.z = (Math_Rand_ZeroOne() * 0.4f) - 0.2f;
    this->regs[SS_KIRAKIRA_ENV_A] += this->regs[SS_KIRAKIRA_A];

    if (this->regs[SS_KIRAKIRA_ENV_A] < 0) {
        this->regs[SS_KIRAKIRA_ENV_A] = 0;
        this->regs[SS_KIRAKIRA_A] = -this->regs[SS_KIRAKIRA_A];
    } else {
        if (this->regs[SS_KIRAKIRA_ENV_A] >= 256) {
            this->regs[SS_KIRAKIRA_ENV_A] = 255;
            this->regs[SS_KIRAKIRA_A] = -this->regs[SS_KIRAKIRA_A];
        }
    }

    this->regs[SS_KIRAKIRA_YAW] += this->regs[SS_KIRAKIRA_YAW_STEP];
}

void func_809AACAC(GlobalContext* globalCtx, u32 index, EffectSs* this) {
    this->velocity.x *= 0.95f;
    this->velocity.z *= 0.95f;
    this->accel.x = Math_Rand_CenteredFloat(0.2f);
    this->accel.z = Math_Rand_CenteredFloat(0.2f);
    this->regs[SS_KIRAKIRA_ENV_A] += this->regs[SS_KIRAKIRA_A];

    if (this->regs[SS_KIRAKIRA_ENV_A] < 0) {
        this->regs[SS_KIRAKIRA_ENV_A] = 0;
        this->regs[SS_KIRAKIRA_A] = -this->regs[SS_KIRAKIRA_A];
    } else {
        if (this->regs[SS_KIRAKIRA_ENV_A] >= 256) {
            this->regs[SS_KIRAKIRA_ENV_A] = 255;
            this->regs[SS_KIRAKIRA_A] = -this->regs[SS_KIRAKIRA_A];
        }
    }

    this->regs[SS_KIRAKIRA_YAW] += this->regs[SS_KIRAKIRA_YAW_STEP];
}

void func_809AAD6C(GlobalContext* globalCtx, u32 index, EffectSs* this) {
    this->regs[SS_KIRAKIRA_SCALE] =
        this->regs[SS_KIRAKIRA_ENV_A] * Math_Sins((32768.0f / this->regs[SS_KIRAKIRA_C]) * this->life);
}
