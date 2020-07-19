#include <ultra64.h>
#include <global.h>
#include "overlays/effects/ovl_Effect_Ss_Blast/z_eff_ss_blast.h"
#include "overlays/effects/ovl_Effect_Ss_G_Spk/z_eff_ss_g_spk.h"
#include "overlays/effects/ovl_Effect_Ss_Solder_Srch_Ball/z_eff_ss_solder_srch_ball.h"
#include "overlays/effects/ovl_Effect_Ss_Fhg_Flash/z_eff_ss_fhg_flash.h"
#include "overlays/effects/ovl_Effect_Ss_Dead_Sound/z_eff_ss_dead_sound.h"

extern Color_RGBA8 D_801158DC;
extern Color_RGBA8 D_801158E0;
extern Color_RGBA8 D_801158E4;
extern Color_RGBA8 D_801158E8;
extern Color_RGBA8 D_801158F4;
extern Color_RGBA8 D_801158F8;
// sEmptyVec
extern Vec3f D_801158C0; // empty vector that seems to be used as a dummy when a specific field isnt needed

// Draw utility for some G effects
#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80027F80.s")

// EffectSsDust Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_800281E8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002829C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80028304.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002836C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_800283D4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002843C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_800284A4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80028510.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002857C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_800285EC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002865C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_800286CC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002873C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_800287AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002881C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80028858.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80028894.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80028990.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80028A54.s")

// EffectSsKiraKira Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80028B18.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80028B74.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80028BB0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80028CEC.s")

// EffectSsBomb Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80028DC4.s")

// EffectSsBomb2 Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80028E1C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80028E84.s")

void EffectSsBlast_Spawn(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* envColor,
                         Color_RGBA8* primColor, s16 radius, s16 radiusStep, s16 radiusStepDecr, s16 life) {
    EffectSsBlastParams initParams;

    Math_Vec3f_Copy(&initParams.pos, pos);
    Math_Vec3f_Copy(&initParams.velocity, velocity);
    Math_Vec3f_Copy(&initParams.accel, accel);
    Color_RGBA8_Copy(&initParams.envColor, envColor);
    Color_RGBA8_Copy(&initParams.primColor, primColor);
    initParams.radius = radius;
    initParams.radiusStep = radiusStep;
    initParams.radiusStepDecr = radiusStepDecr;
    initParams.life = life;
    EffectSs_Spawn(globalCtx, 4, 128, &initParams);
}

void func_80028F84(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 radius, s16 radiusStep,
                   s16 life) {
    EffectSsBlast_Spawn(globalCtx, pos, velocity, accel, &D_801158DC, &D_801158E0, radius, radiusStep, 35, life);
}

void func_80028FD8(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* envColor,
                   Color_RGBA8* primColor, s16 life) {
    EffectSsBlast_Spawn(globalCtx, pos, velocity, accel, envColor, primColor, 100, 375, 35, life);
}

void func_80029024(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel) {
    func_80028FD8(globalCtx, pos, velocity, accel, &D_801158E4, &D_801158E8, 10);
}

// EffectSsGSpk Spawn Functions

void func_80029060(GlobalContext* globalCtx, Actor* actor, Vec3f* pos, Vec3f* velocity, Vec3f* accel,
                   Color_RGBA8* envColor, Color_RGBA8* primColor, s16 scale, s16 scaleStep) {
    EffectSsGSpkInitParams initParams;

    Math_Vec3f_Copy(&initParams.pos, pos);
    Math_Vec3f_Copy(&initParams.velocity, velocity);
    Math_Vec3f_Copy(&initParams.accel, accel);
    Color_RGBA8_Copy(&initParams.primColor, envColor);
    Color_RGBA8_Copy(&initParams.envColor, primColor);
    initParams.actor = actor;
    initParams.scale = scale;
    initParams.scaleStep = scaleStep;
    initParams.updateMode = 0;
    EffectSs_Spawn(globalCtx, 5, 128, &initParams);
}

void func_800290F0(GlobalContext* globalCtx, Actor* actor, Vec3f* pos, Vec3f* velocity, Vec3f* accel,
                   Color_RGBA8* envColor, Color_RGBA8* primColor, s16 scale, s16 scaleStep) {
    EffectSsGSpkInitParams initParams;

    Math_Vec3f_Copy(&initParams.pos, pos);
    Math_Vec3f_Copy(&initParams.velocity, velocity);
    Math_Vec3f_Copy(&initParams.accel, accel);
    Color_RGBA8_Copy(&initParams.primColor, envColor);
    Color_RGBA8_Copy(&initParams.envColor, primColor);
    initParams.actor = actor;
    initParams.scale = scale;
    initParams.scaleStep = scaleStep;
    initParams.updateMode = 1;
    EffectSs_Spawn(globalCtx, 5, 128, &initParams);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80029184.s")

// unused
void func_800291D8(GlobalContext* globalCtx, Actor* actor, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale,
                   s16 scaleStep) {
    Color_RGBA8 envColor = D_801158F4;  // probably inline when data is migrated
    Color_RGBA8 primColor = D_801158F8; // probably inline when data is migrated
    s32 randOffset;

    randOffset = (Math_Rand_ZeroOne() * 20.0f) - 10.0f;

    envColor.r += randOffset;
    envColor.g += randOffset;
    envColor.b += randOffset;
    envColor.a += randOffset;
    primColor.r += randOffset;
    primColor.g += randOffset;
    primColor.b += randOffset;
    primColor.a += randOffset;

    func_80029060(globalCtx, actor, pos, velocity, accel, &envColor, &primColor, scale, scaleStep);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_800292DC.s")

// EffectSsDFire Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80029320.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_800293A0.s")

// EffectSsBubble Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_800293E4.s")

// EffectSsGRipple Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80029444.s")

// EffectSsGSplash Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002949C.s")

// EffectSsGMagma Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80029530.s")

// EffectSsGFire Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80029568.s")

// EffectSsLightning Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_800295A0.s")

// EffectSsDtBubble Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80029618.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80029694.s")

// EffectSsHahen Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80029724.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_800297A4.s")

// EffectSsStick Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_800298EC.s")

// EffectSsSibuki Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002993C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_800299AC.s")

// EffectSsSibuki2 Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80029B30.s")

// EffectSsGMagma2 Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80029B90.s")

// EffectSsStone1 Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80029C00.s")

// EffectSsHitMark Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80029C50.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80029CA4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80029CC8.s")

void EffectSsFhgFlash_Spawn(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 arg4, u8 arg5) {
    EffectSsFhgFlashInitParams initParams;

    Math_Vec3f_Copy(&initParams.pos, pos);
    Math_Vec3f_Copy(&initParams.velocity, velocity);
    Math_Vec3f_Copy(&initParams.accel, accel);
    initParams.unk_24 = arg4;
    initParams.unk_26 = arg5;
    initParams.unk_2C = 0;

    EffectSs_Spawn(globalCtx, EFFECT_SS_FHG_FLASH, 128, &initParams);
}

void EffectSsFhgFlash_Spawn2(GlobalContext* globalCtx, Actor* arg1, Vec3f* pos, s16 arg3, u8 arg4) {
    EffectSsFhgFlashInitParams initParams;

    initParams.unk_28 = arg1;
    Math_Vec3f_Copy(&initParams.pos, pos);
    initParams.unk_24 = arg3;
    initParams.unk_26 = arg4;
    initParams.unk_2C = 1;
    EffectSs_Spawn(globalCtx, EFFECT_SS_FHG_FLASH, 128, &initParams);
}

// EffectSsKFire Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80029DBC.s")

void EffectSsSolderSrchBall_Spawn(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 arg4,
                                  s16* linkDetected) {
    EffectSsSolderSrchBallInitParams initParams;

    Math_Vec3f_Copy(&initParams.pos, pos);
    Math_Vec3f_Copy(&initParams.velocity, velocity);
    Math_Vec3f_Copy(&initParams.accel, accel);
    initParams.unk_24 = arg4;
    initParams.linkDetected = linkDetected;

    EffectSs_Spawn(globalCtx, EFFECT_SS_SOLDER_SRCH_BALL, 128, &initParams);
}

// EffectSsKakera Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80029E8C.s")

// EffectSsIcePiece Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80029F44.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_80029FAC.s")

// EffectSsEnIce Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002A140.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002A1DC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002A2A4.s")

// EffectSsFireTail Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002A32C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002A3C4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002A484.s")

// EffectSsEnFire Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002A4D4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002A54C.s")

// EffectSsExtra Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002A5F4.s")

// EffectSsFCircle Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002A65C.s")

// EffectSsDeadBb Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002A6B8.s")

// EffectSsDeadDd Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002A770.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002A824.s")

// EffectSsDeadDs Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002A894.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002A90C.s")

void EffectSsDeadSound_SpawnImpl(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, u16 sfxId,
                                 s16 lowerPriority, s16 repeatMode, s32 life) {
    EffectSsDeadSoundInitParams initParams;

    Math_Vec3f_Copy(&initParams.pos, pos);
    Math_Vec3f_Copy(&initParams.velocity, velocity);
    Math_Vec3f_Copy(&initParams.accel, accel);
    initParams.sfxId = sfxId;
    initParams.lowerPriority = lowerPriority;
    initParams.repeatMode = repeatMode;
    initParams.life = life;

    if (!lowerPriority) {
        EffectSs_Spawn(globalCtx, EFFECT_SS_DEAD_SOUND, 100, &initParams);
    } else {
        EffectSs_Spawn(globalCtx, EFFECT_SS_DEAD_SOUND, 127, &initParams);
    }
}

void EffectSsDeadSound_Spawn(GlobalContext* globalCtx, Vec3f* pos, u16 sfxId, s16 lowerPriority, s16 repeatMode,
                             s32 life) {
    EffectSsDeadSound_SpawnImpl(globalCtx, pos, &D_801158C0, &D_801158C0, sfxId, lowerPriority, repeatMode, life);
}

// EffectSsIceSmoke Spawn Functions

#pragma GLOBAL_ASM("asm/non_matchings/code/z_effect_soft_sprite_old_init/func_8002AA44.s")
