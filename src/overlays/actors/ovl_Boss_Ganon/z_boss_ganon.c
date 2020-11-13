#include "z_boss_ganon.h"
#include "overlays/actors/ovl_En_Ganon_Mant/z_en_ganon_mant.h"
#include "overlays/actors/ovl_En_Zl3/z_en_zl3.h"

#define FLAGS 0x00000035

#define THIS ((BossGanon*)thisx)

void BossGanon_Init(Actor* thisx, GlobalContext* globalCtx);
void BossGanon_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BossGanon_Update(Actor* thisx, GlobalContext* globalCtx);
void BossGanon_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808E1EB4(Actor* thisx, GlobalContext* globalCtx); // update
void func_808E2544(Actor* thisx, GlobalContext* globalCtx); // update
void func_808E1034(Actor* thisx, GlobalContext* globalCtx); // update
void func_808E229C(Actor* thisx, GlobalContext* globalCtx); // draw
void func_808E324C(Actor* thisx, GlobalContext* globalCtx); // draw
void func_808E1B54(Actor* thisx, GlobalContext* globalCtx); // draw

// action functions
void func_808D779C(BossGanon* this, GlobalContext* globalCtx);
void func_808D90F8(BossGanon* this, GlobalContext* globalCtx);
void func_808D7918(BossGanon* this, GlobalContext* globalCtx);
void func_808D933C(BossGanon* this, GlobalContext* globalCtx);

/*
const ActorInit Boss_Ganon_InitVars = {
    ACTOR_BOSS_GANON,
    ACTORTYPE_BOSS,
    FLAGS,
    OBJECT_GANON,
    sizeof(BossGanon),
    (ActorFunc)BossGanon_Init,
    (ActorFunc)BossGanon_Destroy,
    (ActorFunc)BossGanon_Update,
    (ActorFunc)BossGanon_Draw,
};
*/
// data
extern InitChainEntry D_808E4C84[];
extern ColliderCylinderInit D_808E4C00;
extern ColliderCylinderInit D_808E4C2C;

typedef struct {
    /* 0x00 */ Vec3s eye;
    /* 0x06 */ Vec3s at;
} CutsceneCameraPosition;

extern CutsceneCameraPosition D_808E4C94[];

// CutsceneCameraPosition D_808E4C94[] = {
//     { { 0, 40, 0 }, { 0, 50, 430 } },
//     { { -20, 30, 400 }, { 10, 55, 440 } },
//     { { 0, 60, 300 }, { 0, 273, -150 } },
//     { { 0, 180, -260 }, { 0, 155, -300 } },
//     { { -30, 60, 440 }, { 20, 25, 390 } },
//     { { -50, 140, -360 }, { 50, 92, -390 } },
//     { { -10, 264, -121 }, { 5, 266, -160 } },
//     { { -13, 200, -310 }, { 0, 125, -410 } },
//     { { 0, 40, -50 }, { 0, 35, 230 } },
//     { { 0, 140, -250 }, { 0, 115, -570 } },
//     { { -410, 150, -130 }, { 50, 155, -170 } },
//     { { 0, 130, -230 }, { 0, 125, -2000 } },
//     { { -2, 147, -293 }, { -200, 345, -2000 } },
// };

// bss
extern EnGanonMant* sCape; // D_808F93C0
// D_808F93C4
// D_808F93C8
// D_808F93CC
extern BossGanon* sGanondorf; // D_808F93D0
extern EnZl3* sZelda;         // D_808F93D4

typedef struct {
    /* 0x00 */ s8 unk_00;
    /* 0x01 */ s8 unk_01;
    /* 0x04 */ f32 unk_04; // prob vec3f
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10; // prob vec3f
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ char unk_28[0x6];
    /* 0x2E */ s16 unk_2E;
    /* 0x30 */ char unk_30[0x4];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ char unk_38[0x4];
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ char unk_40[0xC];
} GanondorfEffect; // size = 0x4C

extern GanondorfEffect sCustomEffects[200];

// segments
extern u8 D_0600CF00[]; // title card texture
extern SkeletonHeader D_060114E8;
extern AnimationHeader D_06005FFC;
extern AnimationHeader D_060089F8;
extern AnimationHeader D_0600EA00;
extern AnimationHeader D_06004F64;
extern AnimationHeader D_06006AF4;
extern AnimationHeader D_06004304;
extern AnimationHeader D_06001F58;
extern AnimationHeader D_06003018;
extern AnimationHeader D_06007268;
extern AnimationHeader D_06007A64;
extern AnimationHeader D_06008A88;

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D6870.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D69B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D6AAC.s")

void func_808D6BF0(GlobalContext* globalCtx, f32 arg1, s32 arg2);
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D6BF0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D6CBC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D6D60.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D6E54.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D6F3C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D7034.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D70F0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D712C.s")

void BossGanon_Init(Actor* thisx, GlobalContext* globalCtx2) {
    s16 i;
    GlobalContext* globalCtx = globalCtx2;
    BossGanon* this = THIS;
    s32 cond;
    f32 xDistFromPlayer;
    f32 yDistFromPlayer;
    f32 zDistFromPlayer;
    Player* player = PLAYER;

    if (thisx->params < 0x64) {
        Flags_SetSwitch(globalCtx, 0x14);
        globalCtx->customActorEffects = sCustomEffects;

        for (i = 0; i < ARRAY_COUNT(sCustomEffects); i++) {
            sCustomEffects[i].unk_00 = 0;
        }

        sGanondorf = this;
        thisx->colChkInfo.health = 40;
        Actor_ProcessInitChain(thisx, D_808E4C84);
        ActorShape_Init(&thisx->shape, 0, NULL, 0);
        Actor_SetScale(thisx, 0.01f);
        SkelAnime_InitSV(globalCtx, &this->skelAnime, &D_060114E8, NULL, NULL, NULL, 0);
        Collider_InitCylinder(globalCtx, &this->collider);
        Collider_SetCylinder(globalCtx, &this->collider, thisx, &D_808E4C00);

        if (thisx->params != 1) {
            // fight intro
            func_808D779C(this, globalCtx);
            this->organAlpha = 255;
        } else {
            // tower collapse
            cond = Flags_GetSwitch(globalCtx, 0x37) &&
                   ((globalCtx->sceneNum == SCENE_GANON_DEMO) || (globalCtx->sceneNum == SCENE_GANON_FINAL) ||
                    (globalCtx->sceneNum == SCENE_GANON_SONOGO) || (globalCtx->sceneNum == SCENE_GANONTIKA_SONOGO));

            if (!cond) {
                func_808D90F8(this, globalCtx);
            } else {
                Actor_Kill(thisx);
                return;
            }

            func_808D90F8(this, globalCtx);
        }

        sCape = (EnGanonMant*)Actor_SpawnAsChild(&globalCtx->actorCtx, thisx, globalCtx, ACTOR_EN_GANON_MANT, 0.0f,
                                                 0.0f, 0.0f, 0, 0, 0, 1);
        Actor_ChangeType(globalCtx, &globalCtx->actorCtx, thisx, ACTORTYPE_BOSS);
    } else {
        thisx->flags &= ~1;
        this->unk_1CC = 255.0f;

        if (thisx->params >= 0xC8) {
            if (thisx->params == 0x12C) {
                thisx->update = func_808E1034;
                thisx->draw = func_808E1B54;
                this->unk_1A8 = 2;
            } else if (thisx->params == 0x190) {
                thisx->update = func_808E1034;
                thisx->draw = func_808E1B54;
                this->unk_1A8 = 1;
            } else if (thisx->params >= 0x104) {
                thisx->update = func_808E2544;
                thisx->draw = func_808E324C;
                this->unk_1C2 = 0xA;
                this->unk_1A2 = 520 + (-thisx->params * 2);

                for (i = 0; i < ARRAY_COUNT(this->unk_2EC); i++) {
                    this->unk_2EC[i] = thisx->posRot.pos;
                }

                this->unk_1B8 = 3;
                Collider_InitCylinder(globalCtx, &this->collider);
                Collider_SetCylinder(globalCtx, &this->collider, thisx, &D_808E4C2C);
            } else if (thisx->params >= 0xFA) {
                thisx->update = func_808E2544;
                thisx->draw = func_808E324C;
                this->unk_1A2 = Math_Rand_ZeroFloat(10000.0f);

                for (i = 0; i < ARRAY_COUNT(this->unk_2EC); i++) {
                    this->unk_2EC[i] = thisx->posRot.pos;
                }

                this->unk_1CC = 0;
            } else {
                thisx->update = func_808E1EB4;
                thisx->draw = func_808E229C;
                if (1) {}
                thisx->speedXZ = 11.0f;

                if (thisx->params == 0xC8) {
                    this->unk_1B6 = 7;
                } else {
                    this->unk_1B6 = (s16)Math_Rand_ZeroFloat(3.0f) + 3;
                }

                for (i = 0; i < ARRAY_COUNT(this->unk_2EC); i++) {
                    this->unk_2EC[i].y = 5000.0f;
                }
            }
        } else {
            thisx->update = func_808E1034;
            thisx->draw = func_808E1B54;
            thisx->speedXZ = 12.0f;

            xDistFromPlayer = player->actor.posRot.pos.x - thisx->posRot.pos.x;
            yDistFromPlayer = (player->actor.posRot.pos.y + 30.0f) - thisx->posRot.pos.y;
            zDistFromPlayer = player->actor.posRot.pos.z - thisx->posRot.pos.z;

            thisx->posRot.rot.y = atan2s(zDistFromPlayer, xDistFromPlayer);
            thisx->posRot.rot.x = atan2s(sqrtf(SQ(xDistFromPlayer) + SQ(zDistFromPlayer)), yDistFromPlayer);

            if (Math_Rand_ZeroOne() < 0) {
                thisx->posRot.rot.y += (s16)Math_Rand_CenteredFloat(5000.0f);
                thisx->posRot.rot.x += (s16)Math_Rand_CenteredFloat(5000.0f);
            }

            this->unk_1B8 = 3;
            Collider_InitCylinder(globalCtx, &this->collider);
            Collider_SetCylinder(globalCtx, &this->collider, thisx, &D_808E4C2C);
        }
    }
}

void BossGanon_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BossGanon* this = THIS;

    if ((this->actor.params < 0xC8) || (this->actor.params > 0x103)) {
        Collider_DestroyCylinder(globalCtx, &this->collider);
    }

    if (this->actor.params < 0x64) {
        SkelAnime_Free(&this->skelAnime, globalCtx);
    }
}

void func_808D779C(BossGanon* this, GlobalContext* globalCtx) {
    s32 pad;
    s32 anim2BankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_GANON_ANIME2);

    if (anim2BankIndex < 0) {
        Actor_Kill(&this->actor);
        return;
    }

    if (Object_IsLoaded(&globalCtx->objectCtx, anim2BankIndex)) {
        this->actionFunc = func_808D7918;
        this->unk_198 = 1;
        this->anim2BankIndex = anim2BankIndex;
        gSegments[6] = VIRTUAL_TO_PHYSICAL(globalCtx->objectCtx.status[anim2BankIndex].segment);
        SkelAnime_ChangeAnimTransitionRepeat(&this->skelAnime, &D_06005FFC, 0.0f);
    } else {
        this->actionFunc = func_808D779C;
    }
}

// set intro cs camera position
void func_808D787C(BossGanon* this, u8 camPosIndex) {
    CutsceneCameraPosition* camPos = &D_808E4C94[camPosIndex];

    this->csCamEye.x = camPos->eye.x;
    this->csCamEye.y = camPos->eye.y;
    this->csCamEye.z = camPos->eye.z;

    this->csCamAt.x = camPos->at.x;
    this->csCamAt.y = camPos->at.y;
    this->csCamAt.z = camPos->at.z;
}

//#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D7918.s")
void func_808D7918(BossGanon* this, GlobalContext* globalCtx) {
    u8 zoomOut;
    Player* player;
    f32 temp_f2;
    f32 temp_f8;
    f32 temp_f10;
    Camera* gameplayCam;

    zoomOut = false;
    player = PLAYER;
    gSegments[6] = VIRTUAL_TO_PHYSICAL(globalCtx->objectCtx.status[this->anim2BankIndex].segment);
    sCape->unk_16B0 = -2.0f;
    sCape->unk_16B4 = 0.25f;
    sCape->unk_16B8 = -1.0f;
    sCape->unk_16D0 = 0.0f;
    this->csTimer++;
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);

    switch (this->introCsState) {
        case 0:
            player->actor.posRot.pos.x = 0.0f;
            player->actor.posRot.pos.y = 0.0f;
            player->actor.posRot.pos.z = 430.0f;

            this->actor.posRot.pos.x = 0.0f;
            this->actor.posRot.pos.y = 112.0f;
            this->actor.posRot.pos.z = -333.0f;

            this->actor.shape.rot.y = 0;
            this->actor.shape.unk_08 = -7000.0f;

            func_80064520(globalCtx, &globalCtx->csCtx);
            func_8002DF54(globalCtx, this, 8); // set player csMode
            this->csCamIndex = Gameplay_CreateSubCamera(globalCtx);
            Gameplay_ChangeCameraStatus(globalCtx, 0, 1);                // set main cam to wait
            Gameplay_ChangeCameraStatus(globalCtx, this->csCamIndex, 7); // set cs Cam to active
            this->csCamFov = 60.0f;

            if (gSaveContext.eventChkInf[7] & 0x100) {
                // watched cutscene already, skip most of it
                this->introCsState = 17;
                this->csTimer = 0;
                player->actor.posRot.pos.z = 20.0f;
                this->unk_71A = 0;
                SkelAnime_ChangeAnimTransitionRepeat(&this->skelAnime, &D_060089F8, -5.0f);
                this->unk_1CC = 1000.0f;
                func_808D787C(this, 11);
                this->unk_198 = 2;
                this->unk_1BA = 0x6E;
                gSaveContext.healthAccumulator = 0x140;
                Audio_SetBGM(NA_BGM_STOP);
            } else {
                this->unk_71A = 1;
                func_808D787C(this, 0);
                this->introCsState = 1;
                sZelda = Actor_SpawnAsChild(&globalCtx->actorCtx, &this->actor, globalCtx, ACTOR_EN_ZL3, 0.0f, 220.0f,
                                            -150.0f, 0, 0, 0, 0x2000);
            }

            Actor_SpawnAsChild(&globalCtx->actorCtx, &this->actor, globalCtx, ACTOR_EN_GANON_ORGAN, 0.0f, 0.0f, 0.0f, 0,
                               0, 0, 1);
            sCape->unk_16AC = 57.0f;
        case 1:
            this->unk_1A0 = 3;
            if (this->csTimer == 70) {
                this->introCsState = 2;
                this->csTimer = 0;
            }
            break;
        case 2:
            func_808D787C(this, 1);

            if (this->csTimer == 10) {
                func_8002DF54(globalCtx, this, 5);
            }

            if (this->csTimer == 13) {
                func_8002F7DC(&player->actor, (player->ageProperties->unk_92 + NA_SE_VO_LI_SURPRISE));
            }

            if (this->csTimer == 35) {
                this->introCsState = 3;
                this->csTimer = 0;
                this->csCamEye.x = 0.0f;
                this->csCamEye.y = 60.0f;
                this->csCamEye.z = 300.0f;
                this->csCamAt.x = 0.0f;
                this->unk_704 = 1.2566371f;
            }
        case 3:
            this->unk_1A0 = 0;
            globalCtx->envCtx.unk_D8 = 0.0f;
            this->csCamAt.y = (sinf(this->unk_704) * 300.0f) + this->csCamEye.y;
            this->csCamAt.z = (cosf(this->unk_704) * -300.0f) + this->csCamEye.z;
            Math_SmoothScaleMaxF(&this->unk_704, 0.25f, 0.05f, this->csCamAtMaxStep.y);
            Math_SmoothScaleMaxF(&this->csCamAtMaxStep.y, 0.01f, 1.0f, 0.0001f);

            if (this->csTimer == 200) {
                func_8002DF54(globalCtx, this, 8);
                this->introCsState = 4;
                func_808D787C(this, 2);
                this->csTimer = 0;
            }
        case 4:
            if ((this->csTimer == 0) || (this->csTimer == 10) || (this->csTimer == 20)) {
                this->csCamEye.y += 68.0f;
                this->csCamEye.z -= 142.0f;
            }

            if (this->csTimer >= 20) {
                this->unk_1A0 = 4;
            } else {
                this->unk_1A0 = 0x23;
            }

            if (this->csTimer == 60) {
                func_808D787C(this, 1);
                this->introCsState = 5;
                this->csTimer = 0;
            }
            break;
        case 5:
            this->unk_1A0 = 5;

            if (this->csTimer < 50) {
                globalCtx->envCtx.unk_D8 = 1.0f;
            }

            if (this->csTimer == 10) {
                func_8002DF54(globalCtx, this, 0x4B);
            }

            if (this->csTimer == 70) {
                func_808D787C(this, 3);
                this->introCsState = 6;
                this->csTimer = 0;
                this->unk_1A0 = 3;
            }
            break;
        case 6:
            this->unk_1A0 = 3;

            if (this->csTimer == 30) {
                this->introCsState = 7;
                this->csTimer = 0;
                func_808D787C(this, 4);
                this->unk_1AE = 0;
                this->unk_1E0 = 10.0f;
                this->unk_1D4 = 255.0f;
                this->unk_1D8 = 0.0f;
                this->unk_1DC = 100.0f;
                func_80078884(NA_SE_EV_TRIFORCE_MARK);
                globalCtx->envCtx.unk_D8 = 0.0f;
            }
        case 7:
            this->unk_1A0 = 6;
            Math_SmoothScaleMaxF(&this->unk_1D8, 255.0f, 1.0f, 10.0f);
            Math_SmoothScaleMaxF(&this->unk_1E0, 0.4f, 1.0f, 0.3f);
            Math_SmoothScaleMaxF(&this->unk_1D4, 170.0f, 1.0f, 2.55f);
            Math_SmoothScaleMaxF(&this->unk_1DC, 200.0f, 1.0f, 3.0f);

            if (this->csTimer >= 30) {
                this->unk_1A0 = 0x41;
            }

            if (this->csTimer == 30) {
                globalCtx->envCtx.unk_D8 = 1.0f;
            }

            func_808D787C(this, 4);
            this->csCamEye.x += 5.0f;
            this->csCamEye.z -= 10.0f; // += negative?
            this->csCamAt.x += 18.0f;

            if (this->csTimer == 60) {
                this->introCsState = 8;
                this->csTimer = 0;
            }
            break;
        case 8:
            this->unk_1A0 = 3;
            func_808D787C(this, 5);

            if (this->csTimer == 30) {
                this->introCsState = 9;
                this->csTimer = 0;
                func_8002DF54(globalCtx, this, 8);
                sZelda->unk_3C8 = 0;
                this->unk_1AE = 1;
                this->unk_1E0 = 10.0f;
                this->unk_1D4 = 255.0f;
                this->unk_1D8 = 0.0f;
                this->unk_1DC = 100.0f;
                func_80078884(NA_SE_EV_TRIFORCE_MARK);
                globalCtx->envCtx.unk_D8 = 0.0f;
            }
        case 9:
            this->unk_1A0 = 7;
            func_808D787C(this, 6);
            Math_SmoothScaleMaxF(&this->unk_1D8, 255.0f, 1.0f, 10.0f);
            Math_SmoothScaleMaxF(&this->unk_1E0, 0.4f, 1.0f, 0.3f);
            Math_SmoothScaleMaxF(&this->unk_1D4, 170.0f, 1.0f, 2.55f);
            Math_SmoothScaleMaxF(&this->unk_1DC, 200.0f, 1.0f, 3.0f);

            if (this->csTimer == 30) {
                sZelda->unk_3C8 = 1;
            }

            if (this->csTimer >= 32) {
                this->unk_1A0 = 0x4B;
            }

            if (this->csTimer == 32) {
                globalCtx->envCtx.unk_D8 = 1.0f;
            }

            if (this->csTimer == 50) {
                this->introCsState = 10;
                this->csTimer = 0;
            }
            break;
        case 10:
            this->unk_1A0 = 3;
            func_808D787C(this, 7);

            if (this->csTimer == 40) {
                this->introCsState = 11;
                this->csTimer = 0;
                this->unk_1D8 = 0.0f;
            }
            break;
        case 11:
            this->unk_1A0 = 3;
            func_808D787C(this, 8);
            player->actor.posRot.pos.z = 20.0f;

            if (this->csTimer == 0x14) {
                func_8002DF54(globalCtx, this, 0x17);
                Interface_ChangeAlpha(11); // show hearts only
            }

            if (this->csTimer == 25) {
                gSaveContext.healthAccumulator = 0x140;
            }

            if (this->csTimer == 100) {
                Interface_ChangeAlpha(1);
            }

            if (this->csTimer == 120) {
                this->introCsState = 12;
                this->csTimer = 0;
            }
            break;
        case 12:
            this->unk_1A0 = 3;
            func_808D787C(this, 9);

            if (this->csTimer == 30) {
                Audio_SetBGM(0x100100FF);
                this->unk_1CC = SkelAnime_GetFrameCount(&D_06004F64.genericHeader);
                SkelAnime_ChangeAnimTransitionStop(&this->skelAnime, &D_06004F64, -5.0f);
            }

            if ((this->csTimer > 30) && func_800A56C8(&this->skelAnime, this->unk_1CC)) {
                SkelAnime_ChangeAnimTransitionRepeat(&this->skelAnime, &D_06006AF4, 0.0f);
                this->unk_1CC = 1000.0f;
            }

            if (this->csTimer == 80) {
                func_8010B680(globalCtx, 0x70C8, NULL);
            }

            if ((this->csTimer >= 0xB5) && (func_8010BDBC(&globalCtx->msgCtx) == 0)) {
                this->introCsState = 15;
                this->csTimer = 0;
                this->unk_71A = 0;
            }
            break;
        case 15:
            this->unk_1A0 = 0;
            globalCtx->envCtx.unk_D8 = 0.0f;
            func_808D787C(this, 10);

            if (this->csTimer == 30) {
                func_8010B680(globalCtx, 0x70C9, NULL);
            }

            if ((this->csTimer > 100) && (func_8010BDBC(&globalCtx->msgCtx) == 0)) {
                this->introCsState = 16;
                this->csTimer = 0;
                func_808D787C(this, 11);
                this->unk_198 = 2;
                sZelda->unk_3C8 = 2;
                this->unk_1BA = 0x6E;
                this->unk_1A0 = 3;
            }
            break;
        case 16:
            this->unk_1A0 = 3;

            if (this->csTimer <= 20) {
                if (this->csTimer == 20) {
                    SkelAnime_ChangeAnimTransitionStop(&this->skelAnime, &D_06004304, -5.0f);
                    this->unk_1CC = SkelAnime_GetFrameCount(&D_06004304.genericHeader);
                }
            } else if (func_800A56C8(&this->skelAnime, this->unk_1CC)) {
                func_8010B680(globalCtx, 0x70CA, NULL);
                SkelAnime_ChangeAnimTransitionRepeat(&this->skelAnime, &D_060089F8, -5.0f);
                this->unk_1CC = 1000.0f;
            }

            if ((this->csTimer > 100) && (func_8010BDBC(&globalCtx->msgCtx) == 0)) {
                this->introCsState = 17;
                this->csTimer = 0;
            }
            break;
        case 17:
            this->unk_1A0 = 3;

            if (this->csTimer == 20) {
                SkelAnime_ChangeAnimTransitionStop(&this->skelAnime, &D_06001F58, -5.0f);
                this->unk_1CC = SkelAnime_GetFrameCount(&D_06001F58.genericHeader);
            }

            if (this->csTimer > 10) {
                if (this->csTimer == 62) {
                    sCape->unk_16BC = 20.0f;
                }

                if (this->csTimer == 57) {
                    Audio_PlayActorSound2(this, NA_SE_EV_GANON_MANTLE);
                }

                Math_SmoothScaleMaxF(&this->csCamFov, 110.0f, 0.1f, this->csCamMaxStepScale * 2.0f);
                Math_SmoothScaleMaxF(&this->csCamEye.z, -290.0f, 0.1f, this->csCamMaxStepScale * 2.4f);
                Math_SmoothScaleMaxF(&this->csCamMaxStepScale, 0.75f, 1.0f, 0.05f);

                if (this->csTimer == 70) {
                    this->introCsState = 18;
                    this->csTimer = 0;
                    this->csCamFov = 60.0f;
                    func_808D787C(this, 12);
                    func_8010B680(globalCtx, 0x70CB, NULL);
                }
            }
            break;
        case 18:
            this->unk_1A0 = 3;
            func_808D787C(this, 12);
            this->csCamEye.y -= 6.0f; // += negative?
            this->csCamEye.z += 6.0f;

            if (func_800A56C8(&this->skelAnime, this->unk_1CC - 5.0f)) {
                SkelAnime_ChangeAnimTransitionRepeat(&this->skelAnime, &D_06003018, -5.0f);
                this->unk_1CC = 1000.0f;
            }

            if ((this->csTimer > 50) && (func_8010BDBC(&globalCtx->msgCtx) == 0)) {
                this->introCsState = 19;
                this->csTimer = 0;
                func_8010B680(globalCtx, 0x70CC, NULL);
                SkelAnime_ChangeAnimTransitionStop(&this->skelAnime, &D_06007268, -5.0f);
                this->unk_1AE = 2;
                this->unk_1E0 = 10.0f;
                this->unk_1D4 = 255.0f;
                this->unk_1D8 = 0.0f;
                this->unk_1DC = 100.0f;
                globalCtx->envCtx.unk_D8 = 0.0f;
            }
        case 19:
            this->unk_1A0 = 8;

            if (this->csTimer >= 60) {
                this->unk_1A0 = 9;

                if (this->csTimer == 60) {
                    globalCtx->envCtx.unk_D8 = 1.0f;
                }
            }

            func_808D787C(this, 12);
            this->csCamEye.y -= 6.0f; // += negative?
            this->csCamEye.z += 6.0f;

            if (this->csTimer >= 30) {
                if (this->csTimer == 30) {
                    func_80078884(NA_SE_EV_TRIFORCE_MARK);
                }

                Math_SmoothScaleMaxF(&this->unk_1D8, 255.0f, 1.0f, 10.0f);
                Math_SmoothScaleMaxF(&this->unk_1E0, 0.6f, 1.0f, 0.3f);
                Math_SmoothScaleMaxF(&this->unk_1D4, 170.0f, 1.0f, 2.55f);
                Math_SmoothScaleMaxF(&this->unk_1DC, 200.0f, 1.0f, 3.0f);
            }

            if (this->csTimer == 17) {
                SkelAnime_ChangeAnimTransitionRepeat(&this->skelAnime, &D_06007A64, -5.0f);
            }

            if ((this->csTimer > 80) && (func_8010BDBC(&globalCtx->msgCtx) == 0)) {
                this->csCamTargetEye.x = this->csCamEye.x - 50.0f;
                this->csCamTargetEye.y = this->csCamEye.y - 100.0f;
                this->introCsState = 20;
                this->csTimer = 0;
                this->csCamTargetEye.z = this->csCamEye.z + 400.0f;
                this->csCamTargetAt.x = this->csCamAt.x + 400.0f;
                this->csCamEyeMaxStep.z = 400.0f;
                this->csCamAtMaxStep.x = 400.0f;
                this->csCamEyeMaxStep.y = 100.0f;
                this->csCamEyeMaxStep.x = 50.0f;
                this->csCamMaxStepScale = 0.0f;
                this->csCamTargetAt.y = this->csCamAt.y;
                this->csCamTargetAt.z = this->csCamAt.z;
                this->unk_1E4 = 0.0f;
                this->csCamMovementScale = 0.2f;
                this->unk_1E8 = 0.1f;
                Audio_PlayActorSound2(this, NA_SE_EN_GANON_DARKWAVE);
            }
            break;
        case 20:
            this->unk_1A0 = 0xA;
            zoomOut = true;
            Math_SmoothScaleMaxF(&this->csCamMaxStepScale, 0.15f, 1.0f, 0.015f);

            if (this->csTimer <= 40) {
                Math_SmoothScaleMaxF(this + 0x1E4, 255.0f, 1.0f, 6.5f);
                Math_SmoothScaleMaxF(this + 0x1E8, 0.2f, 1.0f, 0.025f);
            }

            if (this->csTimer > 20) {
                Audio_PlayActorSound2(this, NA_SE_EN_GANON_DARKWAVE_M - SFX_FLAG);
            }

            if (this->csTimer >= 20) {
                func_808D6BF0(globalCtx, 700.0f, 2);
                func_808D6BF0(globalCtx, 700.0f, 2);
            }

            if (this->csTimer == 30) {
                func_8002DF54(globalCtx, this, 0x4A);
            }

            if (this->csTimer > 50) {
                this->introCsState = 21;
                this->csTimer = 0;
                this->unk_1D8 = 0.0f;
                this->unk_1E8 = 0.16f;
                goto skip_sound;
            }
        case 21:
            this->unk_1A0 = 0xB;
            Audio_PlayActorSound2(&this->actor, NA_SE_EN_GANON_DARKWAVE_M - SFX_FLAG);
            func_808D6BF0(globalCtx, 700.0f, 2);
            func_808D6BF0(globalCtx, 700.0f, 2);
        skip_sound:
            this->csCamEye.x = -30.0f;
            this->csCamEye.y = 37.0f;
            this->csCamEye.z = -30.0f;

            this->csCamAt.x = -10.0f;
            this->csCamAt.y = 45.0f;
            this->csCamAt.z = 0.0f;

            if (this->csTimer == 13) {
                func_8010B680(globalCtx, 0x70CD, NULL);
            }

            if ((this->csTimer > 120) && (func_8010BDBC(&globalCtx->msgCtx) == 0)) {
                this->introCsState = 22;
                this->csTimer = 0;
                this->unk_1BA = 0x1E;
                this->organAlpha = 254;
                this->csCamAt.x = this->unk_1FC.x - 10.0f;
                this->csCamAt.y = this->unk_1FC.y + 30.0f;
                this->csCamAt.z = this->unk_1FC.z;
                this->unk_1E4 = 255.0f;
                this->unk_1E8 = 0.2f;
            }
        case 22:
            if (this->csTimer > 30) {
                this->unk_1A0 = 0;
            } else {
                this->unk_1A0 = 0xC;
            }

            Math_SmoothDownscaleMaxF(&this->unk_1E4, 1.0f, 10.0f);
            this->csCamEye.x = -30.0f;
            this->csCamEye.y = 137.0f;
            this->csCamEye.z = -110.0f;
            Math_SmoothScaleMaxF(&this->csCamAt.y, this->unk_1FC.y + 30.0f, 0.1f, 20.0f);
            Math_SmoothScaleMaxF(&this->csCamAt.x, this->unk_1FC.x - 10.0f, 0.1f, 5.0f);

            if (this->csTimer == 20) {
                func_808D712C(this, globalCtx, OBJECT_GANON_ANIME1);
                SkelAnime_ChangeAnimTransitionStop(&this->skelAnime, &D_06008A88, 0.0f);
                SkelAnime_FrameUpdateMatrix(&this->skelAnime);
                this->actor.shape.unk_08 = 0.0f;
                sCape->unk_16C4 = 18.0f;
                Audio_PlayActorSound2(this, NA_SE_EV_GANON_MANTLE);
                this->unk_198 = 0;
                Audio_SetBGM(0x64);
            }

            if (this->csTimer == 50) {
                gSegments[6] = VIRTUAL_TO_PHYSICAL(
                    globalCtx->objectCtx.status[Object_GetIndex(&globalCtx->objectCtx, OBJECT_GANON)].segment);

                if (!(gSaveContext.eventChkInf[7] & 0x100)) {
                    TitleCard_InitBossName(globalCtx, &globalCtx->actorCtx.titleCtx, SEGMENTED_TO_VIRTUAL(D_0600CF00),
                                           0xA0, 0xB4, 0x80, 0x28);
                }

                gSaveContext.eventChkInf[7] |= 0x100;
            }

            if (this->csTimer >= 20) {
                this->unk_199 = 1;
                Audio_PlayActorSound2(this, NA_SE_EN_GANON_FLOAT - SFX_FLAG);
                Math_SmoothScaleMaxF(&this->actor.posRot.pos.y, 228.0f, 0.05f, 2.0f);
                Math_SmoothScaleMaxF(&this->actor.posRot.pos.z, -230.0f, 0.05f, 4.0f);
                sCape->unk_16B0 = -3.0f;
                sCape->unk_16B4 = 0.25f;
                sCape->unk_16B8 = -3.0f;
                temp_f2 =
                    this->unk_1C8 *
                    Math_Sins(((((((this->csTimer * 4) - this->csTimer) * 0x10) - this->csTimer) * 8) - this->csTimer) *
                              4) *
                    0.04f;
                temp_f10 = this->actor.posRot.pos.y + temp_f2;
                this->actor.velocity.y = temp_f2;
                this->actor.posRot.pos.y = temp_f10;
                temp_f2 = this->unk_1C8 *
                          Math_Coss(((((this->csTimer * 8) - this->csTimer) << 5) + this->csTimer) * 8) * 0.5f;
                temp_f8 = temp_f2 - this->actor.pos4.x;
                this->actor.posRot.pos.x = temp_f2;
                this->actor.velocity.x = temp_f8;
                Math_SmoothScaleMaxF(&this->unk_1C8, 50.0f, 1.0f, 1.0f);
            }

            if (this->csTimer > 30) {
                this->organAlpha -= 5;

                if (this->organAlpha < 0) {
                    this->organAlpha = 0;
                }
            }

            if (this->csTimer == 120) {
                gameplayCam = Gameplay_GetCamera(globalCtx, 0);
                gameplayCam->eye = this->csCamEye;
                gameplayCam->eyeNext = this->csCamEye;
                gameplayCam->at = this->csCamAt;
                func_800C08AC(globalCtx, this->csCamIndex, 0);
                this->introCsState = this->csCamIndex = 0;
                func_80064534(globalCtx, &globalCtx->csCtx);
                func_8002DF54(globalCtx, this, 7);
                func_808DBAF0(this, globalCtx);
            }

            if (sZelda != NULL) {
                sZelda->actor.posRot.pos.x = 0.0f;
                sZelda->actor.posRot.pos.y = 350.0f;
                sZelda->actor.posRot.pos.z = 0.0f;
            }
    }

    if (this->csCamIndex != 0) {
        if (zoomOut) {
            Math_SmoothScaleMaxF(&this->csCamEye.x, this->csCamTargetEye.x, this->csCamMovementScale,
                                 this->csCamEyeMaxStep.x * this->csCamMaxStepScale);
            Math_SmoothScaleMaxF(&this->csCamEye.y, this->csCamTargetEye.y, this->csCamMovementScale,
                                 this->csCamEyeMaxStep.y * this->csCamMaxStepScale);
            Math_SmoothScaleMaxF(&this->csCamEye.z, this->csCamTargetEye.z, this->csCamMovementScale,
                                 this->csCamEyeMaxStep.z * this->csCamMaxStepScale);

            Math_SmoothScaleMaxF(&this->csCamAt.x, this->csCamTargetAt.x, this->csCamMovementScale,
                                 this->csCamAtMaxStep.x * this->csCamMaxStepScale);
            Math_SmoothScaleMaxF(&this->csCamAt.y, this->csCamTargetAt.y, this->csCamMovementScale,
                                 this->csCamAtMaxStep.y * this->csCamMaxStepScale);
            Math_SmoothScaleMaxF(&this->csCamAt.z, this->csCamTargetAt.z, this->csCamMovementScale,
                                 this->csCamAtMaxStep.z * this->csCamMaxStepScale);
        }

        func_800C04D8(globalCtx, this->csCamIndex, &this->csCamAt, &this->csCamEye);
        func_800C0704(globalCtx, this->csCamIndex, this->csCamFov);
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D9018.s")

// tower collapse
void func_808D90F8(BossGanon* this, GlobalContext* globalCtx) {
    s32 pad;
    s32 anim2BankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_GANON_ANIME2);

    if (Object_IsLoaded(&globalCtx->objectCtx, anim2BankIndex)) {
        this->anim2BankIndex = anim2BankIndex;
        gSegments[6] = VIRTUAL_TO_PHYSICAL(globalCtx->objectCtx.status[anim2BankIndex].segment);
        SkelAnime_ChangeAnimTransitionStop(&this->skelAnime, &D_0600EA00, 0.0f);
        this->unk_1CC = SkelAnime_GetFrameCount(&D_0600EA00.genericHeader);
        this->actionFunc = func_808D933C;
        this->csTimer = 0;
        this->introCsState = 0x64;
        this->unk_198 = 1;
        gSaveContext.magic = gSaveContext.unk_13F4;
        gSaveContext.health = gSaveContext.healthCapacity;
    } else {
        this->actionFunc = func_808D90F8;
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D91F8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D933C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DACE8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DAD20.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DB278.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DB2E8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DBAF0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DBB78.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DBEC4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DBF30.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DC0E8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DC14C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DC420.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DC4DC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DC66C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DC75C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DC9B4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DCB7C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DD0E8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DD14C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DD20C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/BossGanon_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DE734.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DE988.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DED30.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DED4C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DEE70.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DF25C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DF4F0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DFBD0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DFFC8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808E0254.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808E06FC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808E0A3C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/BossGanon_Draw.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808E0F4C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808E1034.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808E1B54.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808E1EB4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808E229C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808E2544.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808E324C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808E3564.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808E3D84.s")
