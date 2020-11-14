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
void func_808DBB78(BossGanon* this, GlobalContext* globalCtx); // start fight

void func_808DBF30(BossGanon* this, GlobalContext* globalCtx); // spawn light ball
void func_808DC14C(BossGanon* this, GlobalContext* globalCtx); // throw light ball

void func_808DAD20(BossGanon* this, GlobalContext* globalCtx); // pound the floor

void func_808DB2E8(BossGanon* this, GlobalContext* globalCtx); // charge up thing

// setup action?
void func_808DBAF0(BossGanon* this, GlobalContext* globalCtx); // wait
void func_808DACE8(BossGanon* this, GlobalContext* globalCtx); // pound the floor

void func_808DBEC4(BossGanon* this, GlobalContext* globalCtx); // spawn light ball
void func_808DC0E8(BossGanon* this, GlobalContext* globalCtx); // throw light ball

void func_808DB278(BossGanon* this, GlobalContext* globalCtx); // charge up

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
extern AnimationHeader* D_808E4D38[];
extern s16 D_808E4D40[];
extern Vec3f D_808E4C6C; // zeroVec?

typedef struct {
    /* 0x00 */ Vec3s eye;
    /* 0x06 */ Vec3s at;
} CutsceneCameraPosition; // size = 0x12

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
extern AnimationHeader D_06009A14;
extern AnimationHeader D_0600AA24;
extern AnimationHeader D_0600738C;
extern AnimationHeader D_06009A14;
extern AnimationHeader D_06002D2C;
extern AnimationHeader D_0600343C;
extern AnimationHeader D_06001B0C;
extern AnimationHeader D_06001FF8;
extern AnimationHeader D_06000540;
extern AnimationHeader D_06000FE8;
extern AnimationHeader D_06001440;
// extern AnimationHeader ;
// extern AnimationHeader ;
// extern AnimationHeader ;
// extern AnimationHeader ;
// extern AnimationHeader ;
// extern AnimationHeader ;
// extern AnimationHeader ;

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D6870.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D69B0.s")

// names of the vectors are just a guess
void func_808D6AAC(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, f32 arg4, f32 arg5, s16 arg6);
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D6AAC.s")

void func_808D6BF0(GlobalContext* globalCtx, f32 arg1, s32 arg2);
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D6BF0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D6CBC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D6D60.s")

void func_808D6E54(GlobalContext* globalCtx, Vec3f* pos, f32 arg2, f32 arg3, s16 arg4);
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D6E54.s")

void func_808D6F3C(GlobalContext* globalCtx, Vec3f* pos, f32 arg2, f32 arg3);
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D6F3C.s")

void func_808D7034(GlobalContext* globalCtx, Vec3f* pos, f32 arg2);
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D7034.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D70F0.s")

void func_808D712C(BossGanon* this, GlobalContext* globalCtx, s32 objectId) {
    this->animBankIndex = Object_GetIndex(&globalCtx->objectCtx, objectId);
    gSegments[6] = VIRTUAL_TO_PHYSICAL(globalCtx->objectCtx.status[this->animBankIndex].segment);
}

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
        this->animationLength = 255.0f;

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
                // charge attack light ball (0x104 - 0x109)
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

                this->animationLength = 0;
            } else {
                thisx->update = func_808E1EB4;
                thisx->draw = func_808E229C;
                if (1) {}
                thisx->speedXZ = 11.0f;

                if (thisx->params == 0xC8) {
                    this->actionTimer = 7;
                } else {
                    this->actionTimer = (s16)Math_Rand_ZeroFloat(3.0f) + 3;
                }

                for (i = 0; i < ARRAY_COUNT(this->unk_2EC); i++) {
                    this->unk_2EC[i].y = 5000.0f;
                }
            }
        } else {
            // light ball ( anything from 0x64 - 0xC7)
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
    s32 animBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_GANON_ANIME2);

    if (animBankIndex < 0) {
        Actor_Kill(&this->actor);
        return;
    }

    if (Object_IsLoaded(&globalCtx->objectCtx, animBankIndex)) {
        this->actionFunc = func_808D7918;
        this->unk_198 = 1;
        this->animBankIndex = animBankIndex;
        gSegments[6] = VIRTUAL_TO_PHYSICAL(globalCtx->objectCtx.status[animBankIndex].segment);
        SkelAnime_ChangeAnimTransitionRepeat(&this->skelAnime, &D_06005FFC, 0.0f);
    } else {
        this->actionFunc = func_808D779C;
    }
}

// set intro cs camera position
void BossGanon_SetIntroCsCamera(BossGanon* this, u8 camPosIndex) {
    CutsceneCameraPosition* camPos = &D_808E4C94[camPosIndex];

    this->csCamEye.x = camPos->eye.x;
    this->csCamEye.y = camPos->eye.y;
    this->csCamEye.z = camPos->eye.z;

    this->csCamAt.x = camPos->at.x;
    this->csCamAt.y = camPos->at.y;
    this->csCamAt.z = camPos->at.z;
}

void func_808D7918(BossGanon* this, GlobalContext* globalCtx) {
    u8 moveCam;
    Player* player;
    s32 pad;
    f32 sin;
    f32 cos;
    Camera* gameplayCam;

    moveCam = false;
    player = PLAYER;
    gSegments[6] = VIRTUAL_TO_PHYSICAL(globalCtx->objectCtx.status[this->animBankIndex].segment);
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

            this->actor.shape.unk_08 = -7000.0f;
            this->actor.shape.rot.y = 0;

            func_80064520(globalCtx, &globalCtx->csCtx);
            func_8002DF54(globalCtx, &this->actor, 8);
            this->csCamIndex = Gameplay_CreateSubCamera(globalCtx);
            Gameplay_ChangeCameraStatus(globalCtx, 0, 1);
            Gameplay_ChangeCameraStatus(globalCtx, this->csCamIndex, 7);
            this->csCamFov = 60.0f;

            if (gSaveContext.eventChkInf[7] & 0x100) {
                // watched cutscene already, skip most of it
                this->introCsState = 17;
                this->csTimer = 0;
                player->actor.posRot.pos.z = 20.0f;
                this->unk_71A = 0;
                SkelAnime_ChangeAnimTransitionRepeat(&this->skelAnime, &D_060089F8, -5.0f);
                this->animationLength = 1000.0f;
                BossGanon_SetIntroCsCamera(this, 11);
                this->unk_198 = 2;
                this->unk_1BA = 0x6E;
                gSaveContext.healthAccumulator = 0x140;
                Audio_SetBGM(NA_BGM_STOP);
            } else {
                this->unk_71A = 1;
                BossGanon_SetIntroCsCamera(this, 0);
                this->introCsState = 1;
                sZelda = (EnZl3*)Actor_SpawnAsChild(&globalCtx->actorCtx, &this->actor, globalCtx, ACTOR_EN_ZL3, 0.0f,
                                                    220.0f, -150.0f, 0, 0, 0, 0x2000);
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
            BossGanon_SetIntroCsCamera(this, 1);

            if (this->csTimer == 10) {
                func_8002DF54(globalCtx, &this->actor, 5);
            }

            if (this->csTimer == 13) {
                func_8002F7DC(&player->actor, (player->ageProperties->unk_92 + NA_SE_VO_LI_SURPRISE));
            }

            if (this->csTimer != 35) {
                break;
            }

            this->introCsState = 3;
            this->csTimer = 0;
            this->csCamEye.x = 0.0f;
            this->csCamEye.y = 60.0f;
            this->csCamEye.z = 300.0f;
            this->csCamAt.x = 0.0f;
            this->unk_704 = 1.2566371f;
        case 3:
            this->unk_1A0 = 0;
            globalCtx->envCtx.unk_D8 = 0.0f;
            this->csCamAt.y = (sinf(this->unk_704) * 300.0f) + this->csCamEye.y;
            this->csCamAt.z = (cosf(this->unk_704) * -300.0f) + this->csCamEye.z;
            Math_SmoothScaleMaxF(&this->unk_704, 0.25f, 0.05f, this->csCamAtMaxStep.y);
            Math_SmoothScaleMaxF(&this->csCamAtMaxStep.y, 0.01f, 1.0f, 0.0001f);

            if (this->csTimer != 200) {
                break;
            }

            func_8002DF54(globalCtx, &this->actor, 8);
            this->introCsState = 4;
            BossGanon_SetIntroCsCamera(this, 2);
            this->csTimer = 0;
        case 4: // 14E0
            if ((this->csTimer == 0) || (this->csTimer == 10) || (this->csTimer == 20)) {
                this->csCamEye.y += 68.0f;
                this->csCamEye.z -= 142.0f;
            }

            if (this->csTimer >= 20) {
                this->unk_1A0 = 4;
            } else {
                this->unk_1A0 = 35;
            }

            if (this->csTimer == 60) {
                BossGanon_SetIntroCsCamera(this, 1);
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
                func_8002DF54(globalCtx, &this->actor, 0x4B);
            }

            if (this->csTimer == 70) {
                BossGanon_SetIntroCsCamera(this, 3);
                this->introCsState = 6;
                this->csTimer = 0;
                this->unk_1A0 = 3;
            }
            break;
        case 6:
            this->unk_1A0 = 3;

            if (this->csTimer != 30) {
                break;
            }

            this->introCsState = 7;
            this->csTimer = 0;
            BossGanon_SetIntroCsCamera(this, 4);
            this->unk_1AE = 0;
            this->unk_1E0 = 10.0f;
            this->unk_1D8 = 0.0f;
            this->unk_1D4 = 255.0f;
            this->unk_1DC = 100.0f;
            func_80078884(NA_SE_EV_TRIFORCE_MARK);
            globalCtx->envCtx.unk_D8 = 0.0f;
        case 7: // 165C
            this->unk_1A0 = 6;
            // fade in links triforce
            Math_SmoothScaleMaxF(&this->unk_1D8, 255.0f, 1.0f, 10.0f);
            Math_SmoothScaleMaxF(&this->unk_1E0, 0.4f, 1.0f, 0.3f);
            Math_SmoothScaleMaxF(&this->unk_1D4, 170.0f, 1.0f, 2.55f);
            Math_SmoothScaleMaxF(&this->unk_1DC, 200.0f, 1.0f, 3.0f);

            if (this->csTimer >= 30) {
                this->unk_1A0 = 65;
            }

            if (this->csTimer == 30) {
                globalCtx->envCtx.unk_D8 = 1.0f;
            }

            BossGanon_SetIntroCsCamera(this, 4);
            this->csCamEye.x += 5.0f;
            this->csCamEye.z += -10.0f;
            this->csCamAt.x += 18.0f;

            if (this->csTimer == 60) {
                this->introCsState = 8;
                this->csTimer = 0;
            }
            break;
        case 8:
            this->unk_1A0 = 3;
            BossGanon_SetIntroCsCamera(this, 5);

            if (this->csTimer != 30) {
                break;
            }

            this->introCsState = 9;
            this->csTimer = 0;
            func_8002DF54(globalCtx, &this->actor, 8);
            sZelda->unk_3C8 = 0;
            this->unk_1AE = 1;
            this->unk_1E0 = 10.0f;
            this->unk_1D8 = 0.0f;
            this->unk_1D4 = 255.0f;
            this->unk_1DC = 100.0f;
            func_80078884(NA_SE_EV_TRIFORCE_MARK);
            globalCtx->envCtx.unk_D8 = 0.0f;
        case 9:
            this->unk_1A0 = 7;
            BossGanon_SetIntroCsCamera(this, 6);
            // fade in zeldas triforce
            Math_SmoothScaleMaxF(&this->unk_1D8, 255.0f, 1.0f, 10.0f);
            Math_SmoothScaleMaxF(&this->unk_1E0, 0.4f, 1.0f, 0.3f);
            Math_SmoothScaleMaxF(&this->unk_1D4, 170.0f, 1.0f, 2.55f);
            Math_SmoothScaleMaxF(&this->unk_1DC, 200.0f, 1.0f, 3.0f);

            if (this->csTimer == 30) {
                sZelda->unk_3C8 = 1;
            }

            if (this->csTimer >= 32) {
                this->unk_1A0 = 75;
            }

            if (this->csTimer == 32) {
                globalCtx->envCtx.unk_D8 = 1.0f;
            }

            if (this->csTimer == 50) {
                this->introCsState = 10;
                this->csTimer = 0;
            }
            break;
        case 10: // top view of playing the organ
            this->unk_1A0 = 3;
            BossGanon_SetIntroCsCamera(this, 7);

            if (this->csTimer == 40) {
                this->introCsState = 11;
                this->csTimer = 0;
                this->unk_1D8 = 0.0f;
            }
            break;
        case 11: // link is healed
            this->unk_1A0 = 3;
            BossGanon_SetIntroCsCamera(this, 8);
            player->actor.posRot.pos.z = 20.0f;

            if (this->csTimer == 20) {
                func_8002DF54(globalCtx, &this->actor, 0x17);
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
        case 12: // first dialouge, back facing link
            this->unk_1A0 = 3;
            BossGanon_SetIntroCsCamera(this, 9);

            if (this->csTimer == 30) {
                Audio_SetBGM(0x100100FF);
                this->animationLength = SkelAnime_GetFrameCount(&D_06004F64.genericHeader);
                SkelAnime_ChangeAnimTransitionStop(&this->skelAnime, &D_06004F64, -5.0f);
            }

            if ((this->csTimer > 30) && func_800A56C8(&this->skelAnime, this->animationLength)) {
                SkelAnime_ChangeAnimTransitionRepeat(&this->skelAnime, &D_06006AF4, 0.0f);
                this->animationLength = 1000.0f;
            }

            if (this->csTimer == 80) {
                func_8010B680(globalCtx, 0x70C8, NULL);
            }

            if ((this->csTimer > 180) && (func_8010BDBC(&globalCtx->msgCtx) == 0)) {
                this->introCsState = 15;
                this->csTimer = 0;
                this->unk_71A = 0;
            }
            break;
        case 15: // side view of all 3 of them
            this->unk_1A0 = 0;
            globalCtx->envCtx.unk_D8 = 0.0f;
            BossGanon_SetIntroCsCamera(this, 10);

            if (this->csTimer == 30) {
                func_8010B680(globalCtx, 0x70C9, NULL);
            }

            if ((this->csTimer > 100) && (func_8010BDBC(&globalCtx->msgCtx) == 0)) {
                this->introCsState = 16;
                this->csTimer = 0;
                BossGanon_SetIntroCsCamera(this, 11);
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
                    this->animationLength = SkelAnime_GetFrameCount(&D_06004304.genericHeader);
                }
            } else if (func_800A56C8(&this->skelAnime, this->animationLength)) {
                func_8010B680(globalCtx, 0x70CA, NULL);
                SkelAnime_ChangeAnimTransitionRepeat(&this->skelAnime, &D_060089F8, -5.0f);
                this->animationLength = 1000.0f;
            }

            if ((this->csTimer > 100) && (func_8010BDBC(&globalCtx->msgCtx) == 0)) {
                this->introCsState = 17;
                this->csTimer = 0;
            }
            break;
        case 17: // turns around
            this->unk_1A0 = 3;

            if (this->csTimer == 20) {
                SkelAnime_ChangeAnimTransitionStop(&this->skelAnime, &D_06001F58, -5.0f);
                this->animationLength = SkelAnime_GetFrameCount(&D_06001F58.genericHeader);
            }

            if (this->csTimer > 10) {
                if (this->csTimer == 62) {
                    sCape->unk_16BC = 20.0f;
                }

                if (this->csTimer == 57) {
                    Audio_PlayActorSound2(&this->actor, NA_SE_EV_GANON_MANTLE);
                }

                Math_SmoothScaleMaxF(&this->csCamFov, 110.0f, 0.1f, this->csCamMaxStepScale * 2.0f);
                Math_SmoothScaleMaxF(&this->csCamEye.z, -290.0f, 0.1f, this->csCamMaxStepScale * 2.4f);
                Math_SmoothScaleMaxF(&this->csCamMaxStepScale, 0.75f, 1.0f, 0.05f);

                if (this->csTimer == 70) {
                    this->introCsState = 18;
                    this->csTimer = 0;
                    this->csCamFov = 60.0f;
                    BossGanon_SetIntroCsCamera(this, 12);
                    func_8010B680(globalCtx, 0x70CB, NULL);
                }
            }
            break;
        case 18: // last dialog before triforce
            this->unk_1A0 = 3;
            BossGanon_SetIntroCsCamera(this, 12);
            this->csCamEye.y += -6.0f;
            this->csCamEye.z += 6.0f;

            if (func_800A56C8(&this->skelAnime, this->animationLength - 5.0f)) {
                SkelAnime_ChangeAnimTransitionRepeat(&this->skelAnime, &D_06003018, -5.0f);
                this->animationLength = 1000.0f;
            }

            if ((this->csTimer <= 50) || (func_8010BDBC(&globalCtx->msgCtx) != 0)) {
                break;
            }

            this->introCsState = 19;
            this->csTimer = 0;
            func_8010B680(globalCtx, 0x70CC, NULL);
            SkelAnime_ChangeAnimTransitionStop(&this->skelAnime, &D_06007268, -5.0f);
            this->unk_1AE = 2;
            this->unk_1E0 = 10.0f;
            this->unk_1D8 = 0.0f;
            this->unk_1D4 = 255.0f;
            this->unk_1DC = 100.0f;
            globalCtx->envCtx.unk_D8 = 0.0f;
        case 19: // show triforce
            this->unk_1A0 = 8;

            if (this->csTimer >= 60) {
                this->unk_1A0 = 9;

                if (this->csTimer == 60) {
                    globalCtx->envCtx.unk_D8 = 1.0f;
                }
            }

            BossGanon_SetIntroCsCamera(this, 12);
            this->csCamEye.y += -6.0f;
            this->csCamEye.z += 6.0f;

            if (this->csTimer >= 30) {
                if (this->csTimer == 30) {
                    func_80078884(NA_SE_EV_TRIFORCE_MARK);
                }
                // fade in ganondorfs triforce
                Math_SmoothScaleMaxF(&this->unk_1D8, 255.0f, 1.0f, 10.0f);
                Math_SmoothScaleMaxF(&this->unk_1E0, 0.6f, 1.0f, 0.3f);
                Math_SmoothScaleMaxF(&this->unk_1D4, 170.0f, 1.0f, 2.55f);
                Math_SmoothScaleMaxF(&this->unk_1DC, 200.0f, 1.0f, 3.0f);
            }

            if (this->csTimer == 17) {
                SkelAnime_ChangeAnimTransitionRepeat(&this->skelAnime, &D_06007A64, -5.0f);
            }

            if ((this->csTimer > 80) && (func_8010BDBC(&globalCtx->msgCtx) == 0)) {
                this->introCsState = 20;
                this->csTimer = 0;
                this->csCamTargetEye.x = this->csCamEye.x - 50.0f;
                this->csCamTargetEye.y = this->csCamEye.y - 100.0f;
                this->csCamTargetEye.z = this->csCamEye.z + 400.0f;
                this->csCamEyeMaxStep.x = 50.0f;
                this->csCamEyeMaxStep.y = 100.0f;
                this->csCamEyeMaxStep.z = 400.0f;
                this->csCamAtMaxStep.x = 400.0f;
                this->csCamMaxStepScale = 0.0f;
                this->csCamTargetAt.x = this->csCamAt.x + 400.0f;
                this->csCamTargetAt.y = this->csCamAt.y;
                this->csCamTargetAt.z = this->csCamAt.z;
                this->csCamMovementScale = 0.2f;
                this->unk_1E4 = 0.0f;
                this->unk_1E8 = 0.1f;
                Audio_PlayActorSound2(&this->actor, NA_SE_EN_GANON_DARKWAVE);
            }
            break;
        case 20: // zoom cam out
            this->unk_1A0 = 0xA;
            moveCam = true;
            Math_SmoothScaleMaxF(&this->csCamMaxStepScale, 0.15f, 1.0f, 0.015f);

            if (this->csTimer <= 40) {
                Math_SmoothScaleMaxF(&this->unk_1E4, 255.0f, 1.0f, 6.5f);
                Math_SmoothScaleMaxF(&this->unk_1E8, 0.2f, 1.0f, 0.025f);
            }

            if (this->csTimer > 20) {
                Audio_PlayActorSound2(&this->actor, NA_SE_EN_GANON_DARKWAVE_M - SFX_FLAG);
            }

            if (this->csTimer > 20) {
                func_808D6BF0(globalCtx, 700.0f, 2);
                func_808D6BF0(globalCtx, 700.0f, 2);
            }

            if (this->csTimer == 30) {
                func_8002DF54(globalCtx, &this->actor, 0x4A);
            }

            if (this->csTimer <= 50) {
                break;
            }

            this->introCsState = 21;
            this->csTimer = 0;
            this->unk_1D8 = 0.0f;
            this->unk_1E8 = 0.16f;
            goto skip_sound_and_fx;
        case 21: // purple wave thing
            this->unk_1A0 = 0xB;
            Audio_PlayActorSound2(&this->actor, NA_SE_EN_GANON_DARKWAVE_M - SFX_FLAG);
            func_808D6BF0(globalCtx, 700.0f, 2);
            func_808D6BF0(globalCtx, 700.0f, 2);
        skip_sound_and_fx:
            this->csCamEye.x = -30.0f;
            this->csCamEye.y = 37.0f;
            this->csCamEye.z = -30.0f;

            this->csCamAt.x = -10.0f;
            this->csCamAt.y = 45.0f;
            this->csCamAt.z = 0.0f;

            if (this->csTimer == 13) {
                func_8010B680(globalCtx, 0x70CD, NULL);
            }

            if ((this->csTimer <= 120) || (func_8010BDBC(&globalCtx->msgCtx) != 0)) {
                break;
            }

            this->introCsState = 22;
            this->csTimer = 0;
            this->unk_1BA = 0x1E;
            this->organAlpha = 254;
            this->csCamAt.x = this->unk_1FC.x - 10.0f;
            this->csCamAt.y = this->unk_1FC.y + 30.0f;
            this->csCamAt.z = this->unk_1FC.z;
            this->unk_1E4 = 255.0f;
            this->unk_1E8 = 0.2f;
        case 22: // float, show title card, start fight
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
                Audio_PlayActorSound2(&this->actor, NA_SE_EV_GANON_MANTLE);
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
                Audio_PlayActorSound2(&this->actor, NA_SE_EN_GANON_FLOAT - SFX_FLAG);

                Math_SmoothScaleMaxF(&this->actor.posRot.pos.y, 228.0f, 0.05f, 2.0f);
                Math_SmoothScaleMaxF(&this->actor.posRot.pos.z, -230.0f, 0.05f, 4.0f);

                sCape->unk_16B0 = -3.0f;
                sCape->unk_16B4 = 0.25f;
                sCape->unk_16B8 = -3.0f;

                sin = Math_Sins(this->csTimer * 1500);
                this->actor.velocity.y = this->unk_1C8 * sin * 0.04f;
                this->actor.posRot.pos.y += this->actor.velocity.y;

                cos = Math_Coss(this->csTimer * 1800);
                this->actor.posRot.pos.x = this->unk_1C8 * cos * 0.5f;
                this->actor.velocity.x = this->actor.posRot.pos.x - this->actor.pos4.x;

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
                func_8002DF54(globalCtx, &this->actor, 7);
                func_808DBAF0(this, globalCtx);
            }

            if (sZelda != NULL) {
                sZelda->actor.posRot.pos.x = 0.0f;
                sZelda->actor.posRot.pos.y = 350.0f;
                sZelda->actor.posRot.pos.z = 0.0f;
            }
    }

    if (this->csCamIndex != 0) {
        if (moveCam) {
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
    s32 animBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_GANON_ANIME2);

    if (Object_IsLoaded(&globalCtx->objectCtx, animBankIndex)) {
        this->animBankIndex = animBankIndex;
        gSegments[6] = VIRTUAL_TO_PHYSICAL(globalCtx->objectCtx.status[animBankIndex].segment);
        SkelAnime_ChangeAnimTransitionStop(&this->skelAnime, &D_0600EA00, 0.0f);
        this->animationLength = SkelAnime_GetFrameCount(&D_0600EA00.genericHeader);
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

void func_808DACE8(BossGanon* this, GlobalContext* globalCtx) {
    this->unk_1C2 = 0;
    this->actionTimer = 40;
    this->actionFunc = func_808DAD20;
    this->actor.velocity.x = 0.0f;
    this->actor.velocity.y = 0.0f;
    this->unk_1D0 = 100.0f;
}

void func_808DAD20(BossGanon* this, GlobalContext* globalCtx) {
    s16 i;
    f32 heightTarget;
    f32 targetPosX;
    f32 targetPosZ;
    Vec3f sp6C;
    Vec3f sp60;
    Vec3f sp54;
    Vec3f sp48;

    SkelAnime_FrameUpdateMatrix(&this->skelAnime);

    switch (this->unk_1C2) {
        case 0:
            targetPosX = Math_Sins(this->unk_1A2 * 1280);
            targetPosX = targetPosX * this->unk_1D0;
            targetPosZ = Math_Coss(this->unk_1A2 * 1792);
            targetPosZ = targetPosZ * this->unk_1D0;

            Math_SmoothScaleMaxF(&this->actor.posRot.pos.x, targetPosX, 0.05f, this->unk_1C8);
            Math_SmoothScaleMaxF(&this->actor.posRot.pos.z, targetPosZ, 0.05f, this->unk_1C8);
            Math_SmoothScaleMaxF(&this->unk_1D0, 0.0f, 1, 1.5f);

            if (this->actionTimer == 5) {
                Audio_PlayActorSound2(&this->actor, NA_SE_EN_GANON_HIT_GND);
            }

            if (this->actionTimer < 14) {
                heightTarget = 250.0f;
                this->unk_258 += (Math_Rand_ZeroFloat(M_PI / 2) + (M_PI / 2));
                Math_SmoothScaleMaxF(&this->unk_254, 7.0f, 0.5f, 1.0f);
                this->unk_1A0 = 1;
            } else {
                heightTarget = 200.0f;
            }

            Math_SmoothScaleMaxF(&this->actor.posRot.pos.y, heightTarget, 0.1f, this->actor.velocity.y);
            Math_SmoothScaleMaxF(&this->actor.velocity.y, 20.0f, 1.0f, 1.0f);

            if (this->actionTimer == 14) {
                this->animationLength = SkelAnime_GetFrameCount(&D_06002D2C.genericHeader);
                SkelAnime_ChangeAnimTransitionStop(&this->skelAnime, &D_06002D2C, 0.0f);
                this->actor.velocity.y = 0.0f;
            }

            if (this->actionTimer == 0) {
                this->unk_1C2 = 1;
                this->actor.velocity.y = 0.0f;
            }
            break;
        case 1:
            sCape->unk_16C8 = -1.0f;
            this->unk_1A0 = 1;
            Math_SmoothScaleMaxF(&this->actor.velocity.y, -50.0f, 1.0f, 10.0f);
            this->actor.posRot.pos.y += this->actor.velocity.y;

            if (this->actor.posRot.pos.y < 60.0f) {
                this->actor.posRot.pos.y = 60.0f;
                this->unk_1C2 = 2;
                this->actionTimer = 10;
                func_80033E88(&this->actor, globalCtx, 0xA, 0x14); // rumble
                this->unk_19C = 35;
                this->unk_19E = 0;
                Audio_PlayActorSound2(&this->actor, NA_SE_EN_GANON_HIT_GND_IMP);
                this->unk_254 = 0.0f;
                sp60 = this->unk_260;
                sp60.y = 0.0f;

                for (i = 0; i < 80; i++) {
                    sp6C.x = Math_Rand_CenteredFloat(25.0f);
                    sp6C.y = Math_Rand_ZeroFloat(17.0f);
                    sp6C.z = Math_Rand_CenteredFloat(25.0f);
                    // impact light thing?
                    func_808D6AAC(globalCtx, &sp60, &sp6C, &D_808E4C6C, Math_Rand_ZeroFloat(300.0f) + 500.0f, 13.0f,
                                  0x1E);
                }
            }
            break;
        case 2:
            this->unk_1A0 = 1;

            if (this->actionTimer == 0) {
                this->animationLength = SkelAnime_GetFrameCount(&D_0600343C.genericHeader);
                SkelAnime_ChangeAnimTransitionStop(&this->skelAnime, &D_0600343C, 0.0f);
                this->unk_1C2 = 3;
                this->unk_19F = 1;
                this->actor.velocity.y = 0.0f;
            }
            break;
        case 3:
            Math_SmoothScaleMaxF(&this->actor.posRot.pos.y, 150.0f, 0.1f, this->actor.velocity.y);
            Math_SmoothScaleMaxF(&this->actor.velocity.y, 20.0f, 1.0f, 1.0f);

            if (func_800A56C8(&this->skelAnime, this->animationLength)) {
                this->animationLength = SkelAnime_GetFrameCount(&D_06008A88.genericHeader);
                SkelAnime_ChangeAnimTransitionStop(&this->skelAnime, &D_06008A88, 0.0f);
                SkelAnime_FrameUpdateMatrix(&this->skelAnime);
                sCape->unk_16C4 = 18.0f;
                Audio_PlayActorSound2(&this->actor, NA_SE_EV_GANON_MANTLE);
                this->unk_1C2 = 4;
            }
            break;
        case 4:
            Math_SmoothScaleMaxF(&this->actor.posRot.pos.y, 150.0f, 0.1f, this->actor.velocity.y);
            Math_SmoothScaleMaxF(&this->actor.velocity.y, 20.0f, 1.0f, 1.0f);

            if (func_800A56C8(&this->skelAnime, this->animationLength)) {
                func_808DBAF0(this, globalCtx);
            }
            break;
    }

    if ((this->unk_19C == 35) || (this->unk_19C == 30) || (this->unk_19C == 25)) {
        sp54 = this->actor.posRot.pos;
        sp54.y = 0.0f;
        func_808D6E54(globalCtx, &sp54, 0, 3.0f, this->unk_19C - 25);
    }

    if (this->unk_19C == 35) {
        sp48 = this->actor.posRot.pos;
        sp48.y = 0.0f;
        func_808D6F3C(globalCtx, &sp48, 0, 3.0f);
    }
}

void func_808DB278(BossGanon* this, GlobalContext* globalCtx) {
    this->unk_1C2 = 0;
    this->actionTimer = 30;
    this->actor.velocity.x = 0.0f;
    this->actor.velocity.y = 0.0f;
    this->unk_1D0 = 100.0f;
    this->unk_1AA = Math_Rand_ZeroFloat(20000.0f);
    this->unk_1AC = 0;
    this->actionFunc = func_808DB2E8;
}

void func_808DB2E8(BossGanon* this, GlobalContext* globalCtx) {
    s32 pad;
    f32 targetPosX;
    f32 targetPosZ;
    Vec3f sp80;
    Vec3f sp74;
    Vec3f sp68;
    s16 i;

    SkelAnime_FrameUpdateMatrix(&this->skelAnime);

    targetPosX = Math_Sins(this->unk_1A2 * 1280);
    targetPosX = targetPosX * this->unk_1D0;
    targetPosZ = Math_Coss(this->unk_1A2 * 1792);
    targetPosZ = targetPosZ * this->unk_1D0;

    Math_SmoothScaleMaxF(&this->actor.posRot.pos.x, targetPosX, 0.05f, this->unk_1C8);
    Math_SmoothScaleMaxF(&this->actor.posRot.pos.z, targetPosZ, 0.05, this->unk_1C8);
    Math_SmoothScaleMaxF(&this->unk_1D0, 0.0f, 1.0f, 1.5f);
    Math_SmoothScaleMaxF(&this->actor.posRot.pos.y, 200.0f, 0.05f, this->actor.velocity.y);
    Math_SmoothScaleMaxF(&this->actor.velocity.y, 20.0f, 1.0f, 1.0f);

    switch (this->unk_1C2) {
        case 0:
            if (this->actionTimer == 0) {
                this->animationLength = SkelAnime_GetFrameCount(&D_06001B0C.genericHeader);
                SkelAnime_ChangeAnimTransitionStop(&this->skelAnime, &D_06001B0C, 0.0f);
                this->unk_1C2 = 1;
            }
            break;
        case 1:
            if (func_800A56C8(&this->skelAnime, this->animationLength)) {
                this->animationLength = SkelAnime_GetFrameCount(&D_06001FF8.genericHeader);
                SkelAnime_ChangeAnimTransitionRepeat(&this->skelAnime, &D_06001FF8, 0.0f);
                this->unk_1C2 = 2;
                this->actionTimer = 100;
            }
            break;
        case 2:
            this->unk_1A0 = 2;
            Audio_PlayActorSound2(&this->actor, NA_SE_EN_GANON_CHARGE_MASIC - SFX_FLAG);
            this->unk_278.x = this->unk_2EC[0].x;
            this->unk_278.y = this->unk_2EC[0].y + 50.0f + 30.0f;
            this->unk_278.z = this->unk_2EC[0].z;

            Math_SmoothScaleMaxF(&this->unk_284, 0.25f, 0.1f, 0.006f);
            Math_SmoothScaleMaxF(&this->unk_288, 255.0f, 1.0f, 255.0f);
            Math_SmoothScaleMaxF(&this->unk_28C, 0.25f, 0.1f, 0.006f);

            if ((this->actionTimer > 20) && (this->actionTimer < 60)) {
                Math_SmoothScaleMaxF(&this->unk_290, 255.0f, 1.0f, 15.0f);
            }

            if (this->actionTimer == 0) {
                this->animationLength = SkelAnime_GetFrameCount(&D_06000540.genericHeader);
                SkelAnime_ChangeAnimTransitionStop(&this->skelAnime, &D_06000540, 0.0f);
                this->unk_1C2 = 3;
                this->actionTimer = 6;
                this->unk_1B8 = 0xF;
                Audio_PlayActorSound2(&this->actor, NA_SE_EN_GANON_DARKWAVE);
                break;
            }

            Math_SmoothScaleMaxS(&this->actor.shape.rot.y, this->actor.yawTowardsLink, 5, 0x3E8);

            if (this->actionTimer < -4) {
                for (i = 0; i < ARRAY_COUNT(this->unk_294); i++) {
                    Math_SmoothScaleMaxF(&this->unk_294[i], 0.0f, 1.0f, 40.0f);
                }
            } else if ((this->actionTimer >= 7) && (this->actionTimer < 26)) {
                if (this->unk_1AC < ARRAY_COUNT(this->unk_294)) {
                    this->unk_1AC++;
                }

                for (i = 0; i < this->unk_1AC; i++) {
                    Math_SmoothScaleMaxF(&this->unk_294[i], 200.0f, 1.0f, 40.0f);
                }
            }

            if (this->actionTimer <= 30) {
                Math_SmoothScaleMaxF(&this->unk_284, 0.4f, 0.5f, 0.017f);
                this->unk_28C = this->unk_284;
            }

            if (this->actionTimer <= 30) {
                Math_SmoothScaleMaxF(&this->unk_2D0, 45.0f, 0.1f, 10.0f);
                this->unk_66E = 1;
                this->unk_66C = 2;
                D_8015FCF8 = this->unk_278;
            }

            if (this->actionTimer == 47) {
                this->unk_274 = 1;
            }

            if (this->actionTimer == 46) {
                this->unk_274 = 2;
            }

            if (this->actionTimer == 45) {
                this->unk_274 = 3;
            }

            if (this->actionTimer == 44) {
                this->unk_274 = 4;
            }

            if (this->actionTimer == 43) {
                this->unk_274 = 5;
            }

            if (this->actionTimer == 42) {
                this->unk_274 = 6;
            }

            if (this->actionTimer > 30) {
                sp74.x = 0.0f;
                sp74.y = Math_Rand_ZeroFloat(10.0f) + 150.0f;
                sp74.z = 0.0f;

                Matrix_RotateY((this->actor.yawTowardsLink / 32768.0f) * 3.1415927f, MTXMODE_NEW);
                Matrix_RotateZ(Math_Rand_ZeroFloat(65536.0f), MTXMODE_APPLY);
                Matrix_MultVec3f(&sp74, &sp68);

                sp80.x = this->unk_278.x + sp68.x;
                sp80.y = this->unk_278.y + sp68.y;
                sp80.z = this->unk_278.z + sp68.z;

                func_808D7034(globalCtx, &sp80, 20.0f);
            }
            break;
        case 3:
            this->unk_1A0 = 2;
            for (i = 0; i < ARRAY_COUNT(this->unk_294); i++) {
                Math_SmoothScaleMaxF(&this->unk_294[i], 0.0f, 1.0f, 40.0f);
            }

            if (this->actionTimer == 1) {
                sCape->unk_16C0 = 15.0f;
                Audio_PlayActorSound2(&this->actor, NA_SE_EV_GANON_MANTLE);
            }

            if (this->actionTimer == 0) {
                Math_SmoothDownscaleMaxF(&this->unk_284, 1.0f, 0.08f);
                this->unk_28C = this->unk_284;
                Math_SmoothDownscaleMaxF(&this->unk_2D0, 1.0f, 10.0f);
                Math_SmoothScaleMaxF(&this->unk_278.x, this->unk_1FC.x, 0.5f, 30.0f);
                Math_SmoothScaleMaxF(&this->unk_278.y, this->unk_1FC.y, 0.5f, 30.0f);
                Math_SmoothScaleMaxF(&this->unk_278.z, this->unk_1FC.z, 0.5f, 30.0f);
            }

            if (this->unk_1B8 == 0) {
                this->animationLength = SkelAnime_GetFrameCount(&D_06000FE8.genericHeader);
                SkelAnime_ChangeAnimTransitionRepeat(&this->skelAnime, &D_06000FE8, 0.0f);
                this->unk_1C2 = 4;
                this->unk_288 = 0.0f;
                this->unk_290 = 0.0f;
                this->unk_284 = 0.0f;
                this->unk_28C = 0.0f;
            }
            break;
        case 4:
            this->unk_1A0 = 2;
            if (func_800A56C8(&this->skelAnime, 5.0f)) {
                for (i = 0; i < 5; i++) {
                    Actor_SpawnAsChild(&globalCtx->actorCtx, &this->actor, globalCtx, ACTOR_BOSS_GANON, this->unk_1FC.x,
                                       this->unk_1FC.y, this->unk_1FC.z, 0, this->actor.yawTowardsLink, 0, 0x104 + i);
                }

                Audio_PlayActorSound2(&this->actor, NA_SE_EN_GANON_BIGMASIC);
                Audio_PlayActorSound2(&this->actor, NA_SE_EN_GANON_THROW_BIG);
            }

            if (func_800A56C8(&this->skelAnime, 3.0f)) {
                sCape->unk_16C4 = 26.0f;
                Audio_PlayActorSound2(&this->actor, NA_SE_EV_GANON_MANTLE);
            }

            if (func_800A56C8(&this->skelAnime, this->animationLength)) {
                this->animationLength = SkelAnime_GetFrameCount(&D_06001440.genericHeader);
                SkelAnime_ChangeAnimTransitionRepeat(&this->skelAnime, &D_06001440, 0.0f);
                this->unk_1C2 = 5;
            }
            break;
        case 5:
            this->unk_1A0 = 2;

            if (func_800A56C8(&this->skelAnime, this->animationLength)) {
                func_808DBAF0(this, globalCtx);
            }
            break;
    }
}

void func_808DBAF0(BossGanon* this, GlobalContext* globalCtx) {
    func_808D712C(this, globalCtx, OBJECT_GANON_ANIME1);
    SkelAnime_ChangeAnimTransitionRepeat(&this->skelAnime, &D_06009A14, -10.0f);
    this->actionFunc = func_808DBB78;
    this->unk_1C8 = 0.0f;
    this->actionTimer = (s16)Math_Rand_ZeroFloat(64.0f) + 30;
    this->unk_1C2 = 0;
    sCape->unk_16AC = 2.0f;
}

void func_808DBB78(BossGanon* this, GlobalContext* globalCtx) {
    f32 sin;
    s32 pad;
    f32 cos;
    Player* player = PLAYER;

    this->unk_199 = 1;

    sCape->unk_16B0 = -3.0f;
    sCape->unk_16B4 = 0.25f;
    sCape->unk_16B8 = -3.0f;
    sCape->unk_16D0 = 20.0f;

    SkelAnime_FrameUpdateMatrix(&this->skelAnime);

    if ((this->unk_1C2 == 0) && !(player->actor.posRot.pos.y < 0.0f)) {
        if (!(player->stateFlags1 & 0x2000) && (fabsf(player->actor.posRot.pos.x) < 110.0f) &&
            (fabsf(player->actor.posRot.pos.z) < 110.0f)) {
            func_808DACE8(this, globalCtx);
        } else if ((this->actionTimer == 0) && !(player->stateFlags1 & 0x2000)) {
            this->actionTimer = (s16)Math_Rand_ZeroFloat(30.0f) + 30;

            if ((s8)this->actor.colChkInfo.health >= 20) {
                func_808DBEC4(this, globalCtx);
            } else if (Math_Rand_ZeroOne() >= 0.5f) {
                if ((Math_Rand_ZeroOne() >= 0.5f) || (this->actor.xzDistFromLink > 350.0f)) {
                    func_808DB278(this, globalCtx);
                } else {
                    func_808DACE8(this, globalCtx);
                }
            } else {
                func_808DBEC4(this, globalCtx);
            }
        }
    }

    sin = Math_Sins(this->unk_1A2 * 1280) * 100.0f;
    cos = Math_Coss(this->unk_1A2 * 1792) * 100.0f;

    Math_SmoothScaleMaxF(&this->actor.posRot.pos.x, sin, 0.05f, this->unk_1C8);
    Math_SmoothScaleMaxF(&this->actor.posRot.pos.y, 150.0f, 0.05f, this->unk_1C8 * 0.2f);
    Math_SmoothScaleMaxF(&this->actor.posRot.pos.z, cos, 0.05f, this->unk_1C8);
    Math_SmoothScaleMaxF(&this->unk_1C8, 50.0f, 1.0f, 0.5f);

    this->actor.velocity.x = this->actor.posRot.pos.x - this->actor.pos4.x;
    this->actor.velocity.z = this->actor.posRot.pos.z - this->actor.pos4.z;

    sin = Math_Sins(this->unk_1A2 * 1500);
    this->actor.velocity.y = this->unk_1C8 * sin * 0.04f;
    this->actor.posRot.pos.y += this->actor.velocity.y;

    Math_SmoothScaleMaxS(&this->actor.shape.rot.y, this->actor.yawTowardsLink, 5, 0xBB8);
    func_80078914(&this->actor.projectedPos, NA_SE_EN_FANTOM_FLOAT - SFX_FLAG);
}

void func_808DBEC4(BossGanon* this, GlobalContext* globalCtx) {
    func_808D712C(this, globalCtx, OBJECT_GANON_ANIME1);
    this->animationLength = SkelAnime_GetFrameCount(&D_0600AA24.genericHeader);
    SkelAnime_ChangeAnimTransitionStop(&this->skelAnime, &D_0600AA24, -3.0f);
    this->actionFunc = func_808DBF30;
    this->actionTimer = 25;
}

void func_808DBF30(BossGanon* this, GlobalContext* globalCtx) {
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);

    sCape->unk_16B0 = -3.0f;
    sCape->unk_16B4 = 1.25f;
    sCape->unk_16B8 = -2.0f;
    sCape->unk_16D0 = 10.0f;

    if (this->actionTimer < 17) {
        this->unk_1A0 = 1;
    }

    if (this->actionTimer == 17) {
        this->unk_26C = 0xA;
        this->unk_270 = Math_Rand_ZeroFloat(M_PI);
        Audio_PlayActorSound2(&this->actor, NA_SE_EN_GANON_SPARK);
    }

    if (this->actionTimer < 10) {
        this->unk_258 += (Math_Rand_ZeroFloat(M_PI / 2) + (M_PI / 2));
        Math_SmoothScaleMaxF(&this->unk_254, 10.0f, 0.5f, 1.25f);

        if (this->actionTimer == 0) {
            func_808DC0E8(this, globalCtx);
        }
    }

    Math_SmoothScaleMaxS(&this->actor.shape.rot.y, this->actor.yawTowardsLink, 5, 0x7D0);

    this->actor.posRot.pos.x += this->actor.velocity.x;
    this->actor.posRot.pos.z += this->actor.velocity.z;

    Math_SmoothDownscaleMaxF(&this->actor.velocity.x, 1.0f, 0.5f);
    Math_SmoothDownscaleMaxF(&this->actor.velocity.z, 1.0f, 0.5f);

    this->actor.velocity.y = Math_Sins(this->unk_1A2 * 1500) * 2.0f;
    this->actor.posRot.pos.y += this->actor.velocity.y;
}

void func_808DC0E8(BossGanon* this, GlobalContext* globalCtx) {
    func_808D712C(this, globalCtx, OBJECT_GANON_ANIME1);
    this->animationLength = SkelAnime_GetFrameCount(&D_0600738C.genericHeader);
    SkelAnime_ChangeAnimTransitionStop(&this->skelAnime, &D_0600738C, 0.0f);
    this->actionFunc = func_808DC14C;
}

void func_808DC14C(BossGanon* this, GlobalContext* globalCtx) {
    s16 rand;

    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    Math_SmoothDownscaleMaxF(&this->unk_254, 1.0f, 0.2f);

    switch (this->unk_1C2) {
        case 0:
            this->unk_1A0 = 1;

            if (func_800A56C8(&this->skelAnime, this->animationLength)) {
                this->unk_1C2 = 1;
                SkelAnime_ChangeAnimTransitionRepeat(&this->skelAnime, &D_06009A14, 0.0f);
            }

            if (this->skelAnime.animCurrentFrame <= 12.0f) {
                this->unk_66E = 2;
                this->unk_66C = 2;
                D_8015FCF8 = this->unk_260;
            }

            if (func_800A56C8(&this->skelAnime, 12.0f)) {
                this->unk_254 = 0.0f;
            }

            if (func_800A56C8(&this->skelAnime, 11.0f) != 0) {
                this->unk_25C = 1;
                Audio_PlayActorSound2(&this->actor, NA_SE_EN_GANON_THROW);
                Audio_PlayActorSound2(&this->actor, NA_SE_EN_GANON_THROW_MASIC);
                Actor_SpawnAsChild(&globalCtx->actorCtx, &this->actor, globalCtx, ACTOR_BOSS_GANON, this->unk_260.x,
                                   this->unk_260.y, this->unk_260.z, 0, 0, 0, 0x64);
            }
            break;
        case 1:
            if (this->unk_1C0 != 0) {
                rand = Math_Rand_ZeroOne() * 1.99f;
                this->animationLength = SkelAnime_GetFrameCount(&D_808E4D38[rand]->genericHeader);
                SkelAnime_ChangeAnimTransitionStop(&this->skelAnime, D_808E4D38[rand], 0.0f);
                sCape->unk_16BC = D_808E4D40[rand];
                Audio_PlayActorSound2(&this->actor, NA_SE_EV_GANON_MANTLE);
                this->unk_1C0 = 0;
            }
            break;
    }

    Math_SmoothScaleMaxS(&this->actor.shape.rot.y, this->actor.yawTowardsLink, 5, 0x7D0);

    this->actor.posRot.pos.x += this->actor.velocity.x;
    this->actor.posRot.pos.z += this->actor.velocity.z;

    Math_SmoothScaleMaxMinF(&this->actor.velocity.x, 0.0f, 1.0f, 0.5f, 0.0f);
    Math_SmoothScaleMaxMinF(&this->actor.velocity.z, 0.0f, 1.0f, 0.5f, 0.0f);

    this->actor.velocity.y = Math_Sins(this->unk_1A2 * 1500) * 2.0f;
    this->actor.posRot.pos.y += this->actor.velocity.y;
}

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
// void BossGanon_Update(Actor* thisx, GlobalContext* globalCtx) {
//     BossGanon* this = THIS;


//     f32 sp120;
//     f32 sp108;
//     f32 sp104;
//     f32 sp100;
//     f32 spFC;
//     f32 spF8;
//     f32 spF4;
//     f32 spEC;
//     ? spE8;
//     f32 spE0;
//     f32 spDC;
//     f32 spD8;
//     f32 spD4;
//     f32 spD0;
//     f32 spCC;
//     f32 spC4;
//     f32 spC0;
//     f32 spBC;
//     f32 spB0;
//     f32 spAC;
//     f32 spA8;
//     f32 spA4;
//     ColliderCylinder* temp_s0;
//     CollisionCheckContext* temp_s1_3;
//     f32* temp_a2;
//     f32* temp_s1_5;
//     f32* temp_s2_2;
//     f32 temp_f0;
//     f32 temp_f0_2;
//     f32 temp_f12;
//     f32 temp_f20;
//     f32 temp_f20_2;
//     f32 temp_f22;
//     f32 temp_f22_2;
//     f32 temp_f24;
//     f32 temp_f2;
//     s16 temp_a0_2;
//     s16 temp_a0_3;
//     s16 temp_s0_2;
//     s16 temp_s1;
//     s16 temp_s1_2;
//     s16 temp_s1_4;
//     s16 temp_s1_6;
//     s16 temp_s1_7;
//     s16 temp_s2;
//     s16 temp_v0_2;
//     s16 temp_v0_3;
//     s16 temp_v0_4;
//     s16 temp_v0_5;
//     s16 temp_v0_6;
//     s16 temp_v0_8;
//     s16 temp_v0_9;
//     s16 temp_v1_3;
//     s16 temp_v1_5;
//     s16 temp_v1_6;
//     s8 temp_v0_12;
//     u32 temp_t1;
//     u8 temp_a0;
//     u8 temp_v0_13;
//     u8 temp_v0_14;
//     void (*)(struct BossGanon*, GlobalContext*) temp_v1;
//     void (*)(struct BossGanon*, GlobalContext*) temp_v1_2;
//     void (*)(struct BossGanon*, GlobalContext*) temp_v1_4;
//     void* temp_s0_3;
//     void* temp_s0_4;
//     void* temp_s3;
//     void* temp_v0;
//     void* temp_v0_10;
//     void* temp_v0_11;
//     void* temp_v0_7;
//     s16 phi_s1;
//     s16 phi_s1_2;
//     f32 phi_f22;
//     f32 phi_f20;
//     s16 phi_s1_3;
//     s16 phi_s0;
//     s16 phi_s2;
//     void* phi_s0_2;
//     s16 phi_s1_4;
//     void* phi_v0;
//     f32 phi_f0;

//     temp_v1 = this->actionFunc;
//     temp_s3 = globalCtx->unk1C44;
//     if ((&func_808D7918 != temp_v1) && (&func_808D933C != temp_v1)) {
//         func_808D712C(this, globalCtx, 0x17C);
//     } else {
//         *(gSegments + 0x18) = globalCtx->objectCtx.status[this->animBankIndex].segment + 0x80000000;
//     }
//     temp_a0 = this->unk71B;
//     if (temp_a0 != 0) {
//         func_808D91F8(temp_a0);
//         spF8 = 0.0f;
//         phi_s1 = 0;
//     loop_6:
//         sp104 = Math_Rand_ZeroFloat(240.0f) + 20.0f;
//         if (Math_Rand_ZeroOne() < 0.5f) {
//             sp100 = 463.0f;
//             sp108 = Math_Rand_ZeroFloat(463.0f);
//             spF4 = Math_Rand_ZeroFloat(2.0f);
//             spFC = Math_Rand_ZeroFloat(1.0f);
//         } else {
//             sp108 = 463.0f;
//             sp100 = Math_Rand_ZeroFloat(463.0f);
//             spFC = Math_Rand_ZeroFloat(2.0f);
//             spF4 = Math_Rand_ZeroFloat(1.0f);
//         }
//         func_808D6870(globalCtx, &sp100, &spF4, Math_Rand_ZeroFloat(0.075f) + 0.08f);
//         temp_s1 = phi_s1 + 1;
//         phi_s1 = temp_s1;
//         if (temp_s1 < 0xA) {
//             goto loop_6;
//         }
//     }
//     this->collider.base.type = 3;
//     sCape->unk_16C8 = -3.0f;
//     temp_v1_2 = this->actionFunc;
//     this->unk2E4 = 0;
//     this->actor.flags = this->actor.flags & -2;
//     this->unk_1A2 = this->unk_1A2 + 1;
//     this->unk_1A4 = this->unk_1A4 + 1;
//     if ((&func_808DBB78 == temp_v1_2) || (&func_808DC4DC == temp_v1_2)) {
//         if (temp_s3->unkA73 != 0) {
//             func_808DC420(this, globalCtx);
//         }
//     }
//     this->actionFunc(this, globalCtx);
//     phi_s1_2 = 0;
// loop_15:
//     temp_v0 = this + (phi_s1_2 * 2);
//     temp_v1_3 = temp_v0->unk1B6;
//     temp_s1_2 = phi_s1_2 + 1;
//     if (temp_v1_3 != 0) {
//         temp_v0->unk1B6 = temp_v1_3 - 1;
//     }
//     phi_s1_2 = temp_s1_2;
//     if (temp_s1_2 < 5) {
//         goto loop_15;
//     }
//     temp_v0_2 = this->unk1A6;
//     if (temp_v0_2 != 0) {
//         this->unk1A6 = temp_v0_2 - 1;
//     }
//     temp_v0_3 = this->unk_2D4;
//     if (temp_v0_3 != 0) {
//         this->unk_2D4 = temp_v0_3 - 1;
//     }
//     temp_v0_4 = this->unk2E8;
//     if (temp_v0_4 != 0) {
//         this->unk2E8 = temp_v0_4 - 1;
//     }
//     temp_v0_5 = this->unk2E6;
//     if (temp_v0_5 != 0) {
//         this->unk2E6 = temp_v0_5 - 1;
//     }
//     temp_v0_6 = this->unk_19C;
//     if (temp_v0_6 != 0) {
//         this->unk_19C = temp_v0_6 - 1;
//     }
//     if (this->introCsState == 0) {
//         func_808DD20C(this, globalCtx);
//         temp_s0 = &this->collider;
//         func_808D70F0(&this->unk_1FC, temp_s0);
//         temp_s1_3 = &globalCtx->colChkCtx;
//         CollisionCheck_SetOC(globalCtx, temp_s1_3, temp_s0);
//         if (this->unk_2D4 == 0) {
//             CollisionCheck_SetAC(globalCtx, temp_s1_3, temp_s0);
//             temp_v1_4 = this->actionFunc;
//             if ((&func_808DC75C != temp_v1_4) && (&func_808DCB7C != temp_v1_4) && (&func_808DD14C != temp_v1_4)) {
//                 CollisionCheck_SetAT(globalCtx, temp_s1_3, temp_s0);
//             }
//         }
//     }
//     if (this->unk_199 != 0) {
//         temp_f20 = Math_Sins(0 - this->actor.shape.rot.y);
//         temp_f0 = Math_Coss(0 - this->actor.shape.rot.y);
//         temp_f2 = this->actor.velocity.z;
//         temp_f12 = this->actor.velocity.x;
//         temp_f22 = ((temp_f2 * temp_f20) + (temp_f0 * temp_f12)) * 300.0f;
//         sp120 = ((-temp_f20 * temp_f12) + (temp_f0 * temp_f2)) * 300.0f;
//         temp_a0_2 = this->unk_1A2;
//         phi_f22 = temp_f22;
//         phi_f20 =
//             (Math_Sins(((((((temp_a0_2 * 8) + temp_a0_2) * 8) - temp_a0_2) * 8) - temp_a0_2) * 4) * -500.0f) - 500.0f;
//     } else {
//         sp120 = 0.0f;
//         phi_f22 = 0.0f;
//         phi_f20 = 0.0f;
//     }
//     this->unk_199 = 0;
//     Math_SmoothScaleMaxMinF(this + 0x50C, phi_f22, 1.0f, 600.0f, 0.0f);
//     Math_SmoothScaleMaxMinF(this + 0x510, (bitwise f32)(bitwise s32)sp120, 1.0f, 600.0f, 0.0f);
//     Math_SmoothScaleMaxMinF(this + 0x514, phi_f20, 1.0f, 100.0f, 0.0f);
//     if (this->unk_1BA == 1) {
//         Audio_PlayActorSound2(this, 0x39C7);
//     }
//     if (this->unk_1BA == 0x64) {
//         Audio_PlayActorSound2(this, 0x39D6);
//         this->unk_1BA = 0;
//     }
//     if ((this->unk2E6 != 0) || (this->unk2E8 != 0)) {
//         phi_s1_3 = 1;
//     loop_44:
//         temp_v0_7 = this + (phi_s1_3 * 2);
//         temp_v1_5 = temp_v0_7->unk4E4;
//         if (temp_v1_5 != 0) {
//             temp_v0_7->unk4E4 = temp_v1_5 - 1;
//             Math_SmoothScaleMaxF(this + (phi_s1_3 * 4) + 0x49C, (bitwise f32)this->unk508, 1.0f, 2.0f);
//         } else {
//             Math_SmoothDownscaleMaxF(this + (phi_s1_3 * 4) + 0x49C, 1.0f, 0.2f);
//         }
//         temp_s1_4 = phi_s1_3 + 1;
//         phi_s1_3 = temp_s1_4;
//         if (temp_s1_4 < 0x12) {
//             goto loop_44;
//         }
//         if (this->unk2E8 != 0) {
//             func_80078914(temp_s3 + 0xE4, 0x68);
//             func_808D6BF0(globalCtx, 700.0f, 1);
//         }
//     }
//     if (this->unk_19F != 0) {
//         this->unk_19F = 0;
//         spE8.unk0 = (bitwise s32)this->actor.posRot.pos.x;
//         spE8.unk4 = (bitwise s32)this->actor.posRot.pos.y;
//         spE8.unk8 = (bitwise s32)this->actor.posRot.pos.z;
//         spEC = 0.0f;
//         func_808D6D60(globalCtx, &spE8, 0x3E4CCCCD, 0x3F333333);
//         func_808D6D60(globalCtx, &spE8, 0x3E99999A, 0x3F4CCCCD);
//     }
//     temp_v0_8 = this->unk_26C;
//     if (temp_v0_8 != 0) {
//         this->unk_26C = temp_v0_8 - 1;
//         if (this->unk_26C == 0) {
//             func_808D6CBC(globalCtx, 1.0f, 0.0f, 0.0f);
//         }
//         func_808D6CBC(globalCtx, 1.0f, (*(&D_808E4D44 + (this->unk_26C * 4)) * 0.62831855f) + this->unk_270,
//                       Math_Rand_CenteredFloat(0.62831855f) + 1.5707964f);
//     }
//     temp_v0_9 = this->unk_19C;
//     if ((temp_v0_9 != 0) && (this->unk_19E < 4)) {
//         if ((this->unk_19A == 0) && (temp_v0_9 == 0x14)) {
//             this->unk_19A = 1;
//             spD0 = 0.0f;
//             temp_s1_5 = &spCC;
//             spCC = -180.0f;
//             phi_s2 = 0;
//         loop_61:
//             spD4 = -180.0f;
//             phi_s0 = 0;
//         loop_62:
//             func_808E0F4C(this, globalCtx, temp_s1_5);
//             temp_s0_2 = phi_s0 + 1;
//             spD4 = spD4 + 120.0f;
//             phi_s0 = temp_s0_2;
//             if (temp_s0_2 < 4) {
//                 goto loop_62;
//             }
//             temp_s2 = phi_s2 + 1;
//             spCC = spCC + 120.0f;
//             phi_s2 = temp_s2;
//             if (temp_s2 < 4) {
//                 goto loop_61;
//             }
//         } else if (temp_v0_9 < 0x1E) {
//             spD8 = 0.0f;
//             spDC = 0.0f;
//             spE0 = (30.0f - this->unk_19C) * 15.0f;
//             Matrix_RotateY(Math_Rand_ZeroFloat(6.2831855f), 0);
//             Matrix_MultVec3f(&spD8, &spCC);
//             this->unk_19E = this->unk_19E + func_808E0F4C(this, globalCtx, &spCC);
//         }
//     }
//     temp_s0_3 = globalCtx->unk1C4C;
//     if (temp_s0_3 != 0) {
//         temp_s2_2 = &spBC;
//         phi_s0_2 = temp_s0_3;
//     loop_69:
//         if (phi_s0_2->unk1C != 1) {

//         } else {
//             phi_s1_4 = 0;
//         loop_72:
//             spBC = 0.0f;
//             spC0 = 0.0f;
//             spC4 = 60.0f;
//             Matrix_RotateY(phi_s1_4 * 0.7853982f, 0);
//             Matrix_MultVec3f(temp_s2_2, &spB0);
//             temp_a2 = &spA4;
//             spA4 = phi_s0_2->unk24 + spB0;
//             spA8 = phi_s0_2->unk28;
//             spAC = phi_s0_2->unk2C + spB8;
//             func_808E0F4C(this, globalCtx, temp_a2);
//             temp_s1_6 = phi_s1_4 + 1;
//             phi_s1_4 = temp_s1_6;
//             if (temp_s1_6 < 8) {
//                 goto loop_72;
//             }
//         }
//         temp_s0_4 = phi_s0_2->unk124;
//         phi_s0_2 = temp_s0_4;
//         if (temp_s0_4 != 0) {
//             goto loop_69;
//         }
//     }
//     func_808E3564(globalCtx);
//     temp_v0_10 = globalCtx->unk1C64;
//     phi_v0 = temp_v0_10;
//     if (temp_v0_10 != 0) {
//     loop_75:
//         if (0x106 != phi_v0->unk0) {
//         block_79:
//             temp_v0_11 = phi_v0->unk124;
//             phi_v0 = temp_v0_11;
//             if (temp_v0_11 != 0) {
//                 goto loop_75;
//             }
//         } else if (phi_v0->unk16E != 0) {
//             this->unk_1A0 = 1;
//         } else {
//             goto block_79;
//         }
//     }
//     globalCtx->envCtx.unk_BF = 0;
//     globalCtx->unk10AE2 = 0;
//     globalCtx->envCtx.unk_DC = 2;

//     switch (this->unk_1A0) {
//         case 1:
//             Math_SmoothScaleMaxF(&globalCtx->envCtx.unk_D8, 0.0f, 1.0f, 0.02f);
//             break;
//         case 2:
//             globalCtx->unk10AE1 = 1;
//             Math_SmoothScaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.1f);
//             break;
//         case 3:
//             globalCtx->unk10AE1 = 1;
//             Math_SmoothScaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.02f);
//             break;
//         case 4:
//             globalCtx->unk10AE1 = 3;
//             globalCtx->envCtx.unk_D8 = 1.0f;
//             break;
//         case 36:
//             globalCtx->unk10AE1 = 0;
//             globalCtx->envCtx.unk_D8 = 1.0f;
//             break;
//         case 5:
//             globalCtx->unk10AE1 = 4;
//             globalCtx->envCtx.unk_D8 = 1.0f;
//             break;
//         case 6:
//             globalCtx->unk10AE2 = 5;
//             globalCtx->unk10AE1 = 3;
//             Math_SmoothDownscaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 0.075f);
//             break;
//         case 7:
//             globalCtx->unk10AE2 = 5;
//             globalCtx->envCtx.unk_D8 = 0.0f;
//             break;
//         case 65:
//             globalCtx->unk10AE2 = 3;
//             globalCtx->unk10AE1 = 6;
//             Math_SmoothDownscaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 0.05f);
//             break;
//         case 8:
//             globalCtx->unk10AE2 = 7;
//             globalCtx->envCtx.unk_D8 = 0.0f;
//             break;
//         case 75:
//             globalCtx->unk10AE2 = 4;
//             globalCtx->unk10AE1 = 8;
//             Math_SmoothDownscaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 0.05f);
//             break;
//         case 9:
//             globalCtx->unk10AE2 = 3;
//             globalCtx->unk10AE1 = 9;
//             Math_SmoothScaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.05f);
//             break;
//         case 10:
//             globalCtx->unk10AE2 = 3;
//             globalCtx->unk10AE1 = 0xA;
//             Math_SmoothDownscaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 0.05f);
//             break;
//         case 11:
//             globalCtx->unk10AE2 = 3;
//             globalCtx->unk10AE1 = 0xB;
//             Math_SmoothScaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.05f);
//             this->unk_1A4 = 0;
//             break;
//         case 12:
//             globalCtx->unk10AE2 = 0xC;
//             globalCtx->unk10AE1 = 0xB;
//             temp_a0_3 = this->unk_1A4;
//             Math_SmoothScaleMaxF(&globalCtx->envCtx.unk_D8,
//                                  (Math_Coss(((temp_a0_3 * 4) - temp_a0_3) << 0xB) * 0.5f) + 0.5f, 1.0f, 1.0f);
//             break;
//         case 13:
//             globalCtx->unk10AE2 = 0xC;
//             globalCtx->unk10AE1 = 3;
//             Math_SmoothScaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.05f);
//             break;
//         case 14:
//             globalCtx->unk10AE1 = 0xD;
//             Math_SmoothScaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.025f);
//             break;
//         case 15:
//             globalCtx->unk10AE1 = 0xE;
//             globalCtx->envCtx.unk_D8 = 1.0f;
//             break;
//         case 16:
//             globalCtx->unk10AE2 = 0xE;
//             globalCtx->unk10AE1 = 0xF;
//             Math_SmoothScaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.01f);
//             break;
//         case 17:
//             globalCtx->unk10AE2 = 0x10;
//             globalCtx->unk10AE1 = 0xF;
//             Math_SmoothDownscaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 0.05f);
//             break;
//         case 21:
//             globalCtx->unk10AE2 = 2;
//             globalCtx->unk10AE1 = 1;
//             break;
//         default:
//             break;
//     }

//     temp_f0_2 = this->unk714;
//     this->unk_1A0 = 0;
//     if (0.0f != temp_f0_2) {
//         globalCtx->unk10B09 = temp_f0_2;
//         globalCtx->unk10B08 = 0xFF;
//         globalCtx->unk10B07 = 0xFF;
//         globalCtx->envCtx.unk_E2 = 0xFF;
//         globalCtx->envCtx.unk_E1 = 1;
//     } else if (this->unk_1C4 != 0) {
//         globalCtx->envCtx.unk_E1 = 1;
//         globalCtx->unk10B08 = 0xFF;
//         globalCtx->unk10B07 = 0xFF;
//         globalCtx->envCtx.unk_E2 = 0xFF;
//         if ((this->unk_1C4 & 1) != 0) {
//             globalCtx->unk10B09 = 0x64;
//         } else {
//             globalCtx->unk10B09 = 0;
//         }
//         this->unk_1C4 = this->unk_1C4 - 1;
//     } else {
//         globalCtx->unk10B09 = 0;
//         globalCtx->envCtx.unk_E1 = 0;
//     }
//     temp_v1_6 = this->unk_66E;
//     if (temp_v1_6 != 0) {
//         temp_v0_13 = this->unk_66C;
//         this->unk_66E = temp_v1_6 - 1;
//         if (temp_v0_13 == 1) {
//             phi_f0 = 40.0f;
//         } else if (temp_v0_13 == 4) {
//             phi_f0 = 25.0f;
//         } else {
//             phi_f0 = 10.0f;
//         }
//         Math_SmoothScaleMaxF(this->unk_670, phi_f0, 0.3f, 10.0f);
//     } else {
//         Math_SmoothDownscaleMaxF(this->unk_670, 1.0f, 5.0f);
//         if (0.0f == (bitwise f32)this->unk_670) {
//             this->unk_66C = 0;
//         }
//     }
//     if (this->unk_66C != 0) {
//         D_8015FCF0 = 1;
//         if (this->unk_66C == 1) {
//             D_8015FCF8.x = (bitwise f32)(bitwise s32)this->actor.posRot.pos.x;
//             D_8015FCF8.y = (bitwise f32)(bitwise s32)this->actor.posRot.pos.y;
//             D_8015FCF8.z = (bitwise f32)(bitwise s32)this->actor.posRot.pos.z;
//         }
//         D_8015FD06 = (bitwise f32)this->unk_670;
//         D_8015FD08 = 10.0f;
//         D_8015FD0C = 0;
//     } else {
//         D_8015FCF0 = 0;
//     }
//     temp_v0_14 = this->unk_274;
//     if (temp_v0_14 != 0) {
//         temp_s1_7 = temp_v0_14 - 1;
//         this->unk_278.x = (bitwise f32)this->unk_2EC;
//         temp_f20_2 = temp_s1_7;
//         this->unk_278.y = this->unk2F0 + 50.0f + 30.0f;
//         this->unk_278.z = this->unk2F4;
//         temp_f22_2 = temp_f20_2 * 1.2566371f;
//         temp_f24 = sinf(temp_f22_2) * 600.0f;
//         Actor_SpawnAsChild(&globalCtx->actorCtx, this, globalCtx, 0xE8, this->unk_1FC.x + temp_f24, this->unk_1FC.y,
//                            this->unk_1FC.z + (cosf(temp_f22_2) * 600.0f), 0, (temp_f20_2 * 13107.2f) + 0x6000, 0,
//                            temp_s1_7 + 0xFA);
//         this->unk_274 = 0;
//     }
// }

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
