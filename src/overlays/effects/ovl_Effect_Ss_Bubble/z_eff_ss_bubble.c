/*
 * File: z_eff_ss_bubble.c
 * Overlay: ovl_Effect_Ss_Bubble
 * Description: Bubble
 */

#include "z_eff_ss_bubble.h"

typedef enum {
    /* 0x00 */ SS_BUBBLE_SCALE
} EffectSsBubbleRegs;

u32 EffectSsBubble_Init(GlobalContext* globalCtx, u32 index, EffectSs* this, void* initParamsx);
void EffectSsBubble_Draw(GlobalContext* globalCtx, u32 index, EffectSs* this);
void EffectSsBubble_Update(GlobalContext* globalCtx, u32 index, EffectSs* this);

EffectSsInit Effect_Ss_Bubble_InitVars = {
    EFFECT_SS_BUBBLE,
    EffectSsBubble_Init,
};

extern Gfx D_04055DB0[];
extern Gfx D_04055EB0[];
extern Gfx D_0401A160[];

u32 EffectSsBubble_Init(GlobalContext* globalCtx, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsBubbleInitParams* initParams = (EffectSsBubbleInitParams*)initParamsx;

    this->displayList = SEGMENTED_TO_VIRTUAL(Math_Rand_ZeroOne() < 0.5f ? D_04055DB0 : D_04055EB0);
    this->pos.x = ((Math_Rand_ZeroOne() - 0.5f) * initParams->xzPosRandScale) + initParams->pos.x;
    this->pos.y =
        (((Math_Rand_ZeroOne() - 0.5f) * initParams->yPosRandScale) + initParams->yPosOffset) + initParams->pos.y;
    this->pos.z = ((Math_Rand_ZeroOne() - 0.5f) * initParams->xzPosRandScale) + initParams->pos.z;
    Math_Vec3f_Copy(&this->unk_2C, &this->pos);
    this->life = 1;
    this->regs[SS_BUBBLE_SCALE] = (((Math_Rand_ZeroOne() * 0.5f) + 1.0f) * initParams->scale) * 100;
    this->draw = EffectSsBubble_Draw;
    this->update = EffectSsBubble_Update;

    return 1;
}

void EffectSsBubble_Draw(GlobalContext* globalCtx, u32 index, EffectSs* this) {
    GraphicsContext* localGfxCtx;
    f32 scale;
    GraphicsContext* gfxCtx;
    Gfx* dispRefs[4];

    localGfxCtx = globalCtx->state.gfxCtx;
    scale = this->regs[SS_BUBBLE_SCALE] / 100.0f;

    gfxCtx = localGfxCtx;
    Graph_OpenDisps(dispRefs, localGfxCtx, "../z_eff_ss_bubble.c", 154);

    Matrix_Translate(this->pos.x, this->pos.y, this->pos.z, MTXMODE_NEW);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    gSPMatrix(gfxCtx->polyOpa.p++, Matrix_NewMtx(gfxCtx, "../z_eff_ss_bubble.c", 167),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    func_80093D18(gfxCtx);
    gDPSetPrimColor(gfxCtx->polyOpa.p++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfxCtx->polyOpa.p++, 150, 150, 150, 0);
    gSPSegment(gfxCtx->polyOpa.p++, 0x08, this->displayList);
    gSPDisplayList(gfxCtx->polyOpa.p++, SEGMENTED_TO_VIRTUAL(D_0401A160));

    Graph_CloseDisps(dispRefs, localGfxCtx, "../z_eff_ss_bubble.c", 179);
}

void EffectSsBubble_Update(GlobalContext* globalCtx, u32 index, EffectSs* this) {
    WaterBox* waterBox;
    f32 waterSurfaceY;
    Vec3f ripplePos;

    waterSurfaceY = this->pos.y;

    // kill bubble if its out of range of a water box
    if (!func_8004213C(globalCtx, &globalCtx->colCtx, this->pos.x, this->pos.z, &waterSurfaceY, &waterBox)) {
        this->life = -1;
        return;
    }

    if (waterSurfaceY < this->pos.y) {
        ripplePos.x = this->pos.x;
        ripplePos.y = waterSurfaceY;
        ripplePos.z = this->pos.z;
        EffectSsGRipple_Spawn(globalCtx, &ripplePos, 0, 0x50, 0);
        this->life = -1;
    } else {
        this->life++;
        this->pos.x = ((Math_Rand_ZeroOne() * 0.5f) - 0.25f) + this->unk_2C.x;
        this->accel.y = (Math_Rand_ZeroOne() - 0.3f) * 0.2f;
        this->pos.z = ((Math_Rand_ZeroOne() * 0.5f) - 0.25f) + this->unk_2C.z;
    }
}
