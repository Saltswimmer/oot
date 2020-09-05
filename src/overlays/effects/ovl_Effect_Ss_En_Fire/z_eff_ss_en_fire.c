/*
 * File: z_eff_ss_en_fire.c
 * Overlay: ovl_Effect_Ss_En_Fire
 * Description:
 */

#include "z_eff_ss_en_fire.h"

typedef enum {
    /* 0x00 */ SS_EN_FIRE_0,
    /* 0x01 */ SS_EN_FIRE_1,
    /* 0x02 */ SS_EN_FIRE_2,
    /* 0x03 */ SS_EN_FIRE_3,
    /* 0x04 */ SS_EN_FIRE_4,
    /* 0x05 */ SS_EN_FIRE_5,
    /* 0x06 */ SS_EN_FIRE_6,
    /* 0x07 */ SS_EN_FIRE_7,
    /* 0x08 */ SS_EN_FIRE_8,
    /* 0x09 */ SS_EN_FIRE_9
} EffectSsEnFireRegs;

u32 EffectSsEnFire_Init(GlobalContext* globalCtx, u32 index, EffectSs* this, void* initParamsx);
void func_809A2D28(GlobalContext* globalCtx, u32 index, EffectSs* this);
void func_809A3060(GlobalContext* globalCtx, u32 index, EffectSs* this);

EffectSsInit Effect_Ss_En_Fire_InitVars = {
    EFFECT_SS_EN_FIRE,
    EffectSsEnFire_Init,
};

extern Gfx D_0404D5A0[];
extern Gfx D_0404D4E0[];

u32 EffectSsEnFire_Init(GlobalContext* globalCtx, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsEnFireInitParams* initParams = (EffectSsEnFireInitParams*)initParamsx;
    Vec3f zeroVecSrc = { 0.0f, 0.0f, 0.0f };
    Vec3f zeroVec;

    this->pos = initParams->pos;
    zeroVec = zeroVecSrc;
    this->accel = zeroVec;
    this->velocity = zeroVec;
    this->life = 20;
    this->regs[SS_EN_FIRE_2] = this->life;
    this->actor = initParams->actor;

    this->regs[SS_EN_FIRE_9] = Math_Rand_ZeroOne() * 20.0f;
    this->draw = func_809A2D28;
    this->update = func_809A3060;
    this->regs[SS_EN_FIRE_3] = -15;

    if (initParams->reg7 < 0) {
        this->regs[SS_EN_FIRE_5] =
            Math_Vec3f_Yaw(&initParams->actor->posRot, &initParams->pos) - initParams->actor->shape.rot.y;
        this->regs[SS_EN_FIRE_4] =
            Math_Vec3f_Pitch(&initParams->actor->posRot, &initParams->pos) - initParams->actor->shape.rot.x;
        this->vec.z = Math_Vec3f_DistXYZ(&initParams->pos, &initParams->actor->posRot);
    }

    this->regs[SS_EN_FIRE_0] = initParams->unk_10;

    if ((initParams->unk_12 & 0x8000) != 0) {
        this->regs[SS_EN_FIRE_1] = initParams->unk_10;
    } else {
        this->regs[SS_EN_FIRE_1] = 0;
    }

    this->regs[SS_EN_FIRE_6] = initParams->unk_12 & 0x7FFF;
    this->regs[SS_EN_FIRE_7] = initParams->reg7;
    this->regs[SS_EN_FIRE_8] = initParams->reg8;

    return 1;
}

void func_809A2D28(GlobalContext* globalCtx, u32 index, EffectSs* this) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    f32 scale;
    s16 cam;
    s32 pad[3];
    s16 redGreen;

    OPEN_DISPS(gfxCtx, "../z_eff_en_fire.c", 169);

    Matrix_Translate(this->pos.x, this->pos.y, this->pos.z, MTXMODE_NEW);
    cam = (func_8005A9F4(ACTIVE_CAM) + 0x8000);
    Matrix_RotateY(((cam)) * 0.0000958738f, MTXMODE_APPLY);

    scale = Math_Sins((this->life * 0x333)) * (this->regs[SS_EN_FIRE_1] * 0.00005f);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    gSPMatrix(oGfxCtx->polyXlu.p++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_eff_en_fire.c", 180),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    redGreen = ((this->life - 5));

    if (redGreen < 0) {
        redGreen = 0;
    }

    func_80093D84(globalCtx->state.gfxCtx);
    gDPSetEnvColor(oGfxCtx->polyXlu.p++, redGreen * 12.7f, 0, 0, 0);
    gDPSetPrimColor(oGfxCtx->polyXlu.p++, 0, 0x80, redGreen * 12.7f, redGreen * 12.7f, 0, 255);
    gSPSegment(oGfxCtx->polyXlu.p++, 0x08, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, 0,
                                      ((this->regs[SS_EN_FIRE_9]) * -0x14) & 0x1FF, 0x20, 0x80));

    if (((this->regs[SS_EN_FIRE_8] & 0x7FFF) != 0) || (this->life < 18)) {
        gSPDisplayList(oGfxCtx->polyXlu.p++, D_0404D5A0);
    } else {
        gSPDisplayList(oGfxCtx->polyXlu.p++, D_0404D4E0);
    }

    CLOSE_DISPS(gfxCtx, "../z_eff_en_fire.c", 213);
}


typedef struct {
    /* 0x000 */ Actor actor;
    /* 0x14C */ Vec3f fireTable[10];
} FireActorF;

typedef struct {
    /* 0x000 */ Actor actor;
    /* 0x14C */ Vec3s fireTable[10];
} FireActorS;

void func_809A3060(GlobalContext* globalCtx, u32 index, EffectSs* this) {

    this->regs[SS_EN_FIRE_9]++;

    if (this->actor != NULL) {
        if (this->actor->dmgEffectTimer >= 22) {
            this->life++;
        }
        if (this->actor->update != NULL) {
            Math_SmoothScaleMaxMinS(&this->regs[SS_EN_FIRE_1], this->regs[SS_EN_FIRE_0], 1,
                                    this->regs[SS_EN_FIRE_0] >> 3, 0);

            if (this->regs[SS_EN_FIRE_7] < 0) {
                Matrix_Translate(this->actor->posRot.pos.x, this->actor->posRot.pos.y, this->actor->posRot.pos.z,
                                 MTXMODE_NEW);
                Matrix_RotateY((this->regs[SS_EN_FIRE_5] + this->actor->shape.rot.y) * 0.0000958738f, MTXMODE_APPLY);
                Matrix_RotateX((this->regs[SS_EN_FIRE_4] + this->actor->shape.rot.x) * 0.0000958738f, MTXMODE_APPLY);
                Matrix_MultVec3f(&this->vec, &this->pos);
            } else {
                if ((this->regs[SS_EN_FIRE_8] & 0x8000)) {
                    this->pos.x = ((FireActorS*)this->actor)->fireTable[this->regs[SS_EN_FIRE_7]].x;
                    this->pos.y = ((FireActorS*)this->actor)->fireTable[this->regs[SS_EN_FIRE_7]].y;
                    this->pos.z = ((FireActorS*)this->actor)->fireTable[this->regs[SS_EN_FIRE_7]].z;
                } else {
                    this->pos.x = ((FireActorF*)this->actor)->fireTable[this->regs[SS_EN_FIRE_7]].x;
                    this->pos.y = ((FireActorF*)this->actor)->fireTable[this->regs[SS_EN_FIRE_7]].y;
                    this->pos.z = ((FireActorF*)this->actor)->fireTable[this->regs[SS_EN_FIRE_7]].z;
                }
            }
        } else if (this->regs[SS_EN_FIRE_6] != 0) {
            this->life = 0;
        } else {
            this->actor = NULL;
        }
    }
}
