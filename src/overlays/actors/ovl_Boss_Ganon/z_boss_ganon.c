#include "z_boss_ganon.h"
#include "overlays/actors/ovl_En_Ganon_Mant/z_en_ganon_mant.h"
#include "overlays/actors/ovl_En_Zl3/z_en_zl3.h"
#include "overlays/actors/ovl_Bg_Ganon_Otyuka/z_bg_ganon_otyuka.h"

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
void func_808DBB78(BossGanon* this, GlobalContext* globalCtx); // wait

void func_808DBF30(BossGanon* this, GlobalContext* globalCtx); // spawn light ball
void func_808DC14C(BossGanon* this, GlobalContext* globalCtx); // throw light ball

void func_808DAD20(BossGanon* this, GlobalContext* globalCtx); // pound the floor

void func_808DB2E8(BossGanon* this, GlobalContext* globalCtx); // charge up thing

void func_808DC4DC(BossGanon* this, GlobalContext* globalCtx);
void func_808DC75C(BossGanon* this, GlobalContext* globalCtx);
void func_808DCB7C(BossGanon* this, GlobalContext* globalCtx);
void func_808DD14C(BossGanon* this, GlobalContext* globalCtx);

// setup action
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
extern f32 D_808E4D44[];
extern u8 D_808E4C58[];
extern Color_RGB8 D_808E4C78[];

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

typedef struct {
    /* 0x00 */ u8 type;
    /* 0x01 */ s8 unk_01;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f velocity;
    /* 0x1C */ Vec3f accel;
    /* 0x28 */ Color_RGB8 color; // this might not be a color
    /* 0x2B */ u8 unk_2B;
    /* 0x2C */ s16 unk_2C;
    /* 0x2E */ s16 unk_2E;
    /* 0x30 */ s16 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
} GanondorfEffect; // size = 0x4C

extern GanondorfEffect sCustomEffects[200];
extern EnGanonMant* sCape; // D_808F93C0
// D_808F93C4
// D_808F93C8
// D_808F93CC
extern BossGanon* sGanondorf; // D_808F93D0
extern EnZl3* sZelda;         // D_808F93D4

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
extern AnimationHeader D_06008128;
extern AnimationHeader D_06008F44;
// extern AnimationHeader ;
// extern AnimationHeader ;
// extern AnimationHeader ;
// extern AnimationHeader ;
// extern AnimationHeader ;

void func_808D6870(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, f32 arg3) {
    s16 i;
    GanondorfEffect* eff = globalCtx->customActorEffects;
    Color_RGB8* color;

    for (i = 0; i < 200; i++, eff++) {
        if (eff->type == 0) {
            eff->type = 9;
            eff->pos = *pos;
            eff->velocity = *velocity;
            eff->accel = D_808E4C6C;
            eff->unk_34 = arg3;
            eff->accel.y = -1.5f;
            eff->unk_44 = Math_Rand_ZeroFloat(6.28f);
            eff->unk_48 = Math_Rand_ZeroFloat(6.28f);
            color = &D_808E4C78[(s16)Math_Rand_ZeroFloat(2.99f)];
            eff->color.r = color->r;
            eff->color.g = color->g;
            eff->color.b = color->b;
            eff->unk_01 = (s16)Math_Rand_ZeroFloat(20.0f);
            return;
        }
    }
}

void func_808D69B0(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, f32 arg4, s16 arg6) {
    s16 i;
    GanondorfEffect* eff = globalCtx->customActorEffects;

    for (i = 0; i < 150; i++, eff++) {
        if (eff->type == 0) {
            eff->type = 1;
            eff->pos = *pos;
            eff->velocity = *velocity;
            eff->accel = *accel;
            eff->unk_34 = arg4 / 1000.0f;
            eff->unk_2E = (s16)Math_Rand_ZeroFloat(100.0f) + 0xC8;
            eff->unk_30 = arg6;
            eff->unk_01 = (s16)Math_Rand_ZeroFloat(10.0f);
            return;
        }
    }
}

void func_808D6AAC(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, f32 arg4, f32 arg5, s16 arg6) {
    s16 i;
    GanondorfEffect* eff = globalCtx->customActorEffects;

    for (i = 0; i < 150; i++, eff++) {
        if (eff->type == 0) {
            eff->type = 2;
            eff->pos = *pos;
            eff->velocity = *velocity;
            eff->accel = *accel;
            eff->unk_34 = arg4 / 1000.0f;
            eff->unk_38 = 1.0f;
            eff->unk_40 = arg5;
            eff->unk_2E = (s16)Math_Rand_ZeroFloat(100.0f) + 0xC8;
            eff->unk_30 = arg6;
            eff->unk_01 = (s16)Math_Rand_ZeroFloat(10.0f);
            eff->unk_48 = atan2f(eff->velocity.z, eff->velocity.x);
            eff->unk_44 = -atan2f(sqrtf(SQ(eff->velocity.x) + SQ(eff->velocity.z)), eff->velocity.y);
            return;
        }
    }
}

// shock
void func_808D6BF0(GlobalContext* globalCtx, f32 arg1, s16 arg2) {
    s16 i;
    GanondorfEffect* eff = globalCtx->customActorEffects;

    for (i = 0; i < 75; i++, eff++) {
        if (eff->type == 0) {
            eff->type = 3;
            eff->pos = D_808E4C6C;
            eff->pos.y = -2000.0f;
            eff->velocity = D_808E4C6C;
            eff->accel = D_808E4C6C;
            eff->unk_34 = arg1 / 1000.0f;
            eff->unk_2E = arg2;
            eff->unk_01 = 0;
            return;
        }
    }
}

void func_808D6CBC(GlobalContext* globalCtx, f32 arg1, f32 arg2, f32 arg3) {
    s16 i;
    GanondorfEffect* eff = globalCtx->customActorEffects;

    for (i = 0; i < 150; i++, eff++) {
        if (eff->type == 0) {
            eff->type = 4;
            eff->velocity = D_808E4C6C;
            eff->accel = D_808E4C6C;
            eff->unk_2E = 0;
            eff->unk_34 = arg1;
            eff->unk_48 = arg2;
            eff->unk_3C = arg3;
            eff->unk_01 = 0;
            return;
        }
    }
}

void func_808D6D60(GlobalContext* globalCtx, Vec3f* pos, f32 arg2, f32 arg3);
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D6D60.s")

// void func_808D6D60(GlobalContext* globalCtx, Vec3f* pos, f32 arg2, f32 arg3) {
//     s16 i;
//     GanondorfEffect* eff = globalCtx->customActorEffects;

//     for (i = 0; i < 150; i++, eff++) {
//         if (eff->type == 0) {
//             eff->type = 5;
//             eff->pos = *pos;
//             eff->velocity = D_808E4C6C;
//             eff->accel = D_808E4C6C;
//             eff->unk_34 = arg2;
//             eff->unk_40 = 1.0f;
//             eff->unk_38 = arg3;
//             eff->unk_30 = (s16)Math_Rand_ZeroFloat(100.0f);
//             eff->unk_2C = 0;
//             eff->unk_2E = eff->unk_01 = eff->unk_2D;
//             return;
//         }
//     }
// }

void func_808D6E54(GlobalContext* globalCtx, Vec3f* pos, f32 arg2, f32 arg3, s16 arg4);
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D6E54.s")

void func_808D6F3C(GlobalContext* globalCtx, Vec3f* pos, f32 arg2, f32 arg3);
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D6F3C.s")
// void func_808D6F3C(GlobalContext* globalCtx, Vec3f* pos, f32 arg2, f32 arg3) {
//     s16 i;
//     GanondorfEffect* eff = globalCtx->customActorEffects;

//     for (i = 0; i < 150; i++, eff++) {
//         if (eff->type == 0) {
//             eff->type = 7;
//             eff->pos = *pos;
//             eff->velocity = D_808E4C6C;
//             eff->accel = D_808E4C6C;
//             eff->unk_2C = 0xFF;
//             eff->unk_34 = arg2;
//             eff->unk_38 = arg3;
//             eff->unk_40 = 0.6f;
//             eff->unk_30 = Math_Rand_ZeroFloat(100.0f);
//             eff->unk_2E = 0;
//             eff->unk_01 = 0;
//             return;
//         }
//     }
// }

void func_808D7034(GlobalContext* globalCtx, Vec3f* pos, f32 arg2);
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808D7034.s")

void func_808D70F0(Vec3f* src, ColliderCylinder* collider) {
    collider->dim.pos.x = src->x;
    collider->dim.pos.y = src->y;
    collider->dim.pos.z = src->z;
}

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
            sCustomEffects[i].type = 0;
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

                this->timers[1] = 3;
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
                    this->timers[0] = 7;
                } else {
                    this->timers[0] = (s16)Math_Rand_ZeroFloat(3.0f) + 3;
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

            this->timers[1] = 3;
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

    switch (this->cutsceneState) {
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
                this->cutsceneState = 17;
                this->csTimer = 0;
                player->actor.posRot.pos.z = 20.0f;
                this->unk_71A = 0;
                SkelAnime_ChangeAnimTransitionRepeat(&this->skelAnime, &D_060089F8, -5.0f);
                this->animationLength = 1000.0f;
                BossGanon_SetIntroCsCamera(this, 11);
                this->unk_198 = 2;
                this->timers[2] = 0x6E;
                gSaveContext.healthAccumulator = 0x140;
                Audio_SetBGM(NA_BGM_STOP);
            } else {
                this->unk_71A = 1;
                BossGanon_SetIntroCsCamera(this, 0);
                this->cutsceneState = 1;
                sZelda = (EnZl3*)Actor_SpawnAsChild(&globalCtx->actorCtx, &this->actor, globalCtx, ACTOR_EN_ZL3, 0.0f,
                                                    220.0f, -150.0f, 0, 0, 0, 0x2000);
            }

            Actor_SpawnAsChild(&globalCtx->actorCtx, &this->actor, globalCtx, ACTOR_EN_GANON_ORGAN, 0.0f, 0.0f, 0.0f, 0,
                               0, 0, 1);
            sCape->unk_16AC = 57.0f;
        case 1:
            this->unk_1A0 = 3;
            if (this->csTimer == 70) {
                this->cutsceneState = 2;
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

            this->cutsceneState = 3;
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
            this->cutsceneState = 4;
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
                this->cutsceneState = 5;
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
                this->cutsceneState = 6;
                this->csTimer = 0;
                this->unk_1A0 = 3;
            }
            break;
        case 6:
            this->unk_1A0 = 3;

            if (this->csTimer != 30) {
                break;
            }

            this->cutsceneState = 7;
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
                this->cutsceneState = 8;
                this->csTimer = 0;
            }
            break;
        case 8:
            this->unk_1A0 = 3;
            BossGanon_SetIntroCsCamera(this, 5);

            if (this->csTimer != 30) {
                break;
            }

            this->cutsceneState = 9;
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
                this->cutsceneState = 10;
                this->csTimer = 0;
            }
            break;
        case 10: // top view of playing the organ
            this->unk_1A0 = 3;
            BossGanon_SetIntroCsCamera(this, 7);

            if (this->csTimer == 40) {
                this->cutsceneState = 11;
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
                this->cutsceneState = 12;
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
                this->cutsceneState = 15;
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
                this->cutsceneState = 16;
                this->csTimer = 0;
                BossGanon_SetIntroCsCamera(this, 11);
                this->unk_198 = 2;
                sZelda->unk_3C8 = 2;
                this->timers[2] = 0x6E;
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
                this->cutsceneState = 17;
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
                    this->cutsceneState = 18;
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

            this->cutsceneState = 19;
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
                this->cutsceneState = 20;
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

            this->cutsceneState = 21;
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

            this->cutsceneState = 22;
            this->csTimer = 0;
            this->timers[2] = 0x1E;
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
                this->cutsceneState = this->csCamIndex = 0;
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

// death and tower collapse cutscene
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
        this->cutsceneState = 0x64;
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
    this->timers[0] = 40;
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

            if (this->timers[0] == 5) {
                Audio_PlayActorSound2(&this->actor, NA_SE_EN_GANON_HIT_GND);
            }

            if (this->timers[0] < 14) {
                heightTarget = 250.0f;
                this->unk_258 += (Math_Rand_ZeroFloat(M_PI / 2) + (M_PI / 2));
                Math_SmoothScaleMaxF(&this->unk_254, 7.0f, 0.5f, 1.0f);
                this->unk_1A0 = 1;
            } else {
                heightTarget = 200.0f;
            }

            Math_SmoothScaleMaxF(&this->actor.posRot.pos.y, heightTarget, 0.1f, this->actor.velocity.y);
            Math_SmoothScaleMaxF(&this->actor.velocity.y, 20.0f, 1.0f, 1.0f);

            if (this->timers[0] == 14) {
                this->animationLength = SkelAnime_GetFrameCount(&D_06002D2C.genericHeader);
                SkelAnime_ChangeAnimTransitionStop(&this->skelAnime, &D_06002D2C, 0.0f);
                this->actor.velocity.y = 0.0f;
            }

            if (this->timers[0] == 0) {
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
                this->timers[0] = 10;
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

            if (this->timers[0] == 0) {
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
    this->timers[0] = 30;
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
            if (this->timers[0] == 0) {
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
                this->timers[0] = 100;
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

            if ((this->timers[0] > 20) && (this->timers[0] < 60)) {
                Math_SmoothScaleMaxF(&this->unk_290, 255.0f, 1.0f, 15.0f);
            }

            if (this->timers[0] == 0) {
                this->animationLength = SkelAnime_GetFrameCount(&D_06000540.genericHeader);
                SkelAnime_ChangeAnimTransitionStop(&this->skelAnime, &D_06000540, 0.0f);
                this->unk_1C2 = 3;
                this->timers[0] = 6;
                this->timers[1] = 0xF;
                Audio_PlayActorSound2(&this->actor, NA_SE_EN_GANON_DARKWAVE);
                break;
            }

            Math_SmoothScaleMaxS(&this->actor.shape.rot.y, this->actor.yawTowardsLink, 5, 0x3E8);

            if (this->timers[0] < -4) {
                for (i = 0; i < ARRAY_COUNT(this->unk_294); i++) {
                    Math_SmoothScaleMaxF(&this->unk_294[i], 0.0f, 1.0f, 40.0f);
                }
            } else if ((this->timers[0] >= 7) && (this->timers[0] < 26)) {
                if (this->unk_1AC < ARRAY_COUNT(this->unk_294)) {
                    this->unk_1AC++;
                }

                for (i = 0; i < this->unk_1AC; i++) {
                    Math_SmoothScaleMaxF(&this->unk_294[i], 200.0f, 1.0f, 40.0f);
                }
            }

            if (this->timers[0] <= 30) {
                Math_SmoothScaleMaxF(&this->unk_284, 0.4f, 0.5f, 0.017f);
                this->unk_28C = this->unk_284;
            }

            if (this->timers[0] <= 30) {
                Math_SmoothScaleMaxF(&this->unk_2D0, 45.0f, 0.1f, 10.0f);
                this->unk_66E = 1;
                this->unk_66C = 2;
                D_8015FCF8 = this->unk_278;
            }

            if (this->timers[0] == 47) {
                this->unk_274 = 1;
            }

            if (this->timers[0] == 46) {
                this->unk_274 = 2;
            }

            if (this->timers[0] == 45) {
                this->unk_274 = 3;
            }

            if (this->timers[0] == 44) {
                this->unk_274 = 4;
            }

            if (this->timers[0] == 43) {
                this->unk_274 = 5;
            }

            if (this->timers[0] == 42) {
                this->unk_274 = 6;
            }

            if (this->timers[0] > 30) {
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

            if (this->timers[0] == 1) {
                sCape->unk_16C0 = 15.0f;
                Audio_PlayActorSound2(&this->actor, NA_SE_EV_GANON_MANTLE);
            }

            if (this->timers[0] == 0) {
                Math_SmoothDownscaleMaxF(&this->unk_284, 1.0f, 0.08f);
                this->unk_28C = this->unk_284;
                Math_SmoothDownscaleMaxF(&this->unk_2D0, 1.0f, 10.0f);
                Math_SmoothScaleMaxF(&this->unk_278.x, this->unk_1FC.x, 0.5f, 30.0f);
                Math_SmoothScaleMaxF(&this->unk_278.y, this->unk_1FC.y, 0.5f, 30.0f);
                Math_SmoothScaleMaxF(&this->unk_278.z, this->unk_1FC.z, 0.5f, 30.0f);
            }

            if (this->timers[1] == 0) {
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
    this->timers[0] = (s16)Math_Rand_ZeroFloat(64.0f) + 30;
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
            func_808DACE8(this, globalCtx); // pound floor
        } else if ((this->timers[0] == 0) && !(player->stateFlags1 & 0x2000)) {
            this->timers[0] = (s16)Math_Rand_ZeroFloat(30.0f) + 30;

            if ((s8)this->actor.colChkInfo.health >= 20) {
                func_808DBEC4(this, globalCtx);
            } else if (Math_Rand_ZeroOne() >= 0.5f) {
                if ((Math_Rand_ZeroOne() >= 0.5f) || (this->actor.xzDistFromLink > 350.0f)) {
                    func_808DB278(this, globalCtx);
                } else {
                    func_808DACE8(this, globalCtx); // pound floor
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
    this->timers[0] = 25;
}

void func_808DBF30(BossGanon* this, GlobalContext* globalCtx) {
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);

    sCape->unk_16B0 = -3.0f;
    sCape->unk_16B4 = 1.25f;
    sCape->unk_16B8 = -2.0f;
    sCape->unk_16D0 = 10.0f;

    if (this->timers[0] < 17) {
        this->unk_1A0 = 1;
    }

    if (this->timers[0] == 17) {
        this->unk_26C = 0xA;
        this->unk_270 = Math_Rand_ZeroFloat(M_PI);
        Audio_PlayActorSound2(&this->actor, NA_SE_EN_GANON_SPARK);
    }

    if (this->timers[0] < 10) {
        this->unk_258 += (Math_Rand_ZeroFloat(M_PI / 2) + (M_PI / 2));
        Math_SmoothScaleMaxF(&this->unk_254, 10.0f, 0.5f, 1.25f);

        if (this->timers[0] == 0) {
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

void func_808DC66C(BossGanon* this, GlobalContext* globalCtx) {
    s16 i;

    func_808D712C(this, globalCtx, OBJECT_GANON_ANIME1);
    this->animationLength = SkelAnime_GetFrameCount(&D_06008128.genericHeader);
    SkelAnime_ChangeAnimTransitionStop(&this->skelAnime, &D_06008128, 0);
    this->timers[0] = 70;
    sCape->unk_16BC = sCape->unk_16C0 = 0;

    for (i = 1; i < 15; i++) {
        this->unk_4E4[i] = D_808E4C58[i];
    }

    this->unk_2E6 = 0x50;
    this->unk_2E8 = 0;
    this->actionFunc = func_808DC75C;
    this->actor.velocity.x = this->actor.velocity.z = 0.0f;
    this->unk_1C2 = 0;
    this->unk_1A6 = 0xF;
    this->unk_508 = 6.0f;
}

void func_808DC75C(BossGanon* this, GlobalContext* globalCtx) {
    s16 i;
    Vec3f sp50;

    SkelAnime_FrameUpdateMatrix(&this->skelAnime);

    if (this->unk_1C2 == 0) {
        func_808D6BF0(globalCtx, 1500.0f, 0);

        if (func_800A56C8(&this->skelAnime, this->animationLength)) {
            this->animationLength = SkelAnime_GetFrameCount(&D_06008F44.genericHeader);
            SkelAnime_ChangeAnimTransitionRepeat(&this->skelAnime, &D_06008F44, 0.0f);
            this->unk_1C2 = 1;
        }
    } else if (this->unk_1C2 == 1) {
        func_808D6BF0(globalCtx, 1000.0f, 0);

        if (this->timers[0] == 0) {
            this->animationLength = SkelAnime_GetFrameCount(&D_06008A88.genericHeader);
            SkelAnime_ChangeAnimTransitionStop(&this->skelAnime, &D_06008A88, 0.0f);
            this->unk_1C2 = 2;
            SkelAnime_FrameUpdateMatrix(&this->skelAnime);
            sCape->unk_16C4 = 18.0f;
            Audio_PlayActorSound2(this, NA_SE_EV_GANON_MANTLE);
            Audio_PlayActorSound2(this, NA_SE_EN_GANON_RESTORE);
            this->timers[2] = 130;
        }
    } else {
        if (func_800A56C8(&this->skelAnime, 7.0f)) {
            for (i = 0; i < 100; i++) {
                sp50.x = Math_Rand_CenteredFloat(25.0f);
                sp50.y = Math_Rand_CenteredFloat(25.0f);
                sp50.z = Math_Rand_CenteredFloat(25.0f);

                func_808D69B0(globalCtx, &this->unk_1FC, &sp50, &D_808E4C6C, Math_Rand_ZeroFloat(200.0f) + 500.0f,
                              0x14);
            }

            Audio_PlayActorSound2(this, NA_SE_PL_WALK_WATER2);
        }

        if (func_800A56C8(&this->skelAnime, this->animationLength)) {
            func_808DBAF0(this, globalCtx);
        }
    }

    this->actor.velocity.y = Math_Sins(this->unk_1A2 * 1500) * 2.0f;
    this->actor.posRot.pos.y += this->actor.velocity.y;
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DC9B4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DCB7C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DD0E8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DD14C.s")

void func_808DD20C(BossGanon* this, GlobalContext* globalCtx);
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808DD20C.s")
// void func_808DD20C(BossGanon* this, GlobalContext* globalCtx) {
//     s16 i;
//     Vec3f sp50;
//     ColliderBody* acHitItem;
//     s32 hitWithSword;
//     s32 swordDamage;
//     s32 damage;

//     Vec3f* temp_s0;
//     f32* temp_s1;
//     s16 temp_s1_2;
//     s16 temp_s1_3;
//     s16 temp_s2;
//     s16 temp_s2_2;
//     s16 temp_s2_3;
//     s32 temp_lo;
//     s32 temp_lo_2;
//     u8 temp_v0_3;
//     u8 temp_v1;
//     s16 phi_s2_2;
//     s16 phi_s1;
//     s16 phi_s2_3;
//     s16 phi_s1_2;

//     if (this->collider.base.acFlags & 2) {
//         this->unk_2D4 = 2;
//         this->collider.base.acFlags &= ~2;
//         acHitItem = this->collider.body.acHitItem;

//         if ((this->actionFunc == func_808DC75C) || (this->actionFunc == func_808DB2E8)) {
//             if (acHitItem->toucher.flags & 0x2000) {
//                 func_808DC9B4(this, globalCtx);
//                 this->timers[2] = 0;
//                 Audio_PlayActorSound2(this, NA_SE_EN_GANON_DAMAGE1);
//                 this->unk_1A6 = 0xF;
//                 return;
//             }
//         } else if ((this->actionFunc == func_808DCB7C) && (this->unk_1C2 >= 3)) {
//             if (!(acHitItem->toucher.flags & 0x80)) {
//                 for (i = 0; i < 30; i++) {
//                     sp50.x = Math_Rand_CenteredFloat(20.0f);
//                     sp50.y = Math_Rand_CenteredFloat(20.0f);
//                     sp50.z = Math_Rand_CenteredFloat(20.0f);
//                     func_808D69B0(globalCtx, &this->unk_1FC, &sp50, &D_808E4C6C, Math_Rand_ZeroFloat(200.0f) +
//                     500.0f,
//                                   0x1E);
//                 }

//                 swordDamage = func_800635D0(acHitItem->toucher.flags);

//                 if (swordDamage == 0) {
//                     hitWithSword = false;
//                     damage = 2;
//                 } else {
//                     hitWithSword = true;
//                     damage = swordDamage;
//                 }

//                 if ((this->actor.colChkInfo.health >= 3) || hitWithSword) {
//                     this->actor.colChkInfo.health -= damage;
//                 }

//                 phi_s2_2 = 0;
//             loop_17:
//                 phi_s1 = 1;
//             loop_18:
//                 temp_lo = phi_s1 * 0xC;
//                 (sCape + (((((phi_s2_2 * 8) - phi_s2_2) * 8) + phi_s2_2) * 8) + temp_lo)->unk278 =
//                     Math_Rand_CenteredFloat(15.0f);
//                 temp_s1_2 = phi_s1 + 1;
//                 (sCape + (((((phi_s2_2 * 8) - phi_s2_2) * 8) + phi_s2_2) * 8) + temp_lo)->unk280 =
//                     Math_Rand_CenteredFloat(15.0f);
//                 phi_s1 = temp_s1_2;
//                 if (temp_s1_2 < 0xC) {
//                     goto loop_18;
//                 }
//                 temp_s2_2 = phi_s2_2 + 1;
//                 phi_s2_2 = temp_s2_2;
//                 if (temp_s2_2 < 0xC) {
//                     goto loop_17;
//                 }

//                 if (this->actor.colChkInfo.health > 0) {
//                     Audio_PlayActorSound2(this, NA_SE_EN_GANON_DAMAGE2);
//                     Audio_PlayActorSound2(this, NA_SE_EN_GANON_CUTBODY);
//                     func_808DD0E8(this, globalCtx);
//                     this->unk_1A6 = 0xF;
//                     sCape->unk_1704 = 1;
//                 } else {
//                     func_808D9018(this, globalCtx);
//                     Audio_PlayActorSound2(this, NA_SE_EN_GANON_DEAD);
//                     Audio_PlayActorSound2(this, NA_SE_EN_GANON_DD_THUNDER);
//                     func_80078914(&D_808E4C6C, NA_SE_EN_LAST_DAMAGE);
//                     Audio_SetBGM(0x100100FF);
//                     this->unk_1C4 = 4;
//                 }
//             }
//         } else if (acHitItem->toucher.flags & 0x1F8A4) {
//             Audio_PlayActorSound2(this, 0);

//             phi_s2_3 = 0;
//         loop_25:
//             phi_s1_2 = 1;
//         loop_26:
//             temp_lo_2 = phi_s1_2 * 0xC;
//             (sCape + (((((phi_s2_3 * 8) - phi_s2_3) * 8) + phi_s2_3) * 8) + temp_lo_2)->unk278 =
//                 Math_Rand_CenteredFloat(15.0f);
//             temp_s1_3 = phi_s1_2 + 1;
//             (sCape + (((((phi_s2_3 * 8) - phi_s2_3) * 8) + phi_s2_3) * 8) + temp_lo_2)->unk280 =
//                 Math_Rand_CenteredFloat(15.0f);
//             phi_s1_2 = temp_s1_3;
//             if (temp_s1_3 < 0xC) {
//                 goto loop_26;
//             }
//             temp_s2_3 = phi_s2_3 + 1;
//             phi_s2_3 = temp_s2_3;
//             if (temp_s2_3 < 0xC) {
//                 goto loop_25;
//             }
//         }
//     }
// }

#ifdef NON_MATCHING
void BossGanon_Update(Actor* thisx, GlobalContext* globalCtx) {
    BossGanon* this = THIS;
    Player* player = PLAYER;
    f32 sin;
    f32 cos;
    f32 target50C_X;
    f32 target50C_Y; // target50C_Y
    f32 target50C_Z;
    Vec3f sp100;
    Vec3f spF4;
    Vec3f spE8;
    Vec3f spD8;
    Vec3f spCC;
    Vec3f spBC;
    Vec3f spB0;
    Vec3f spA4;
    Actor* explosive;
    Actor* prop; // might need only one temp for this
    BgGanonOtyuka* platform;
    f32 target670;
    s16 decr274;
    f32 decr2pi;
    s16 i;
    s16 j;

    if ((this->actionFunc != func_808D7918) && (this->actionFunc != func_808D933C)) {
        func_808D712C(this, globalCtx, OBJECT_GANON_ANIME1);
    } else {
        gSegments[6] = VIRTUAL_TO_PHYSICAL(globalCtx->objectCtx.status[this->animBankIndex].segment);
    }

    if (this->unk_71B != 0) { // if hit by light arrow, spawn light stuff around him?
        func_808D91F8(this->unk_71B);
        spF4.y = 0.0f;

        for (i = 0; i < 10; i++) {
            sp100.y = Math_Rand_ZeroFloat(240.0f) + 20.0f;

            if (Math_Rand_ZeroOne() < 0.5f) {
                sp100.x = 463.0f;
                sp100.z = Math_Rand_ZeroFloat(463.0f);
                spF4.x = Math_Rand_ZeroFloat(2);
                spF4.z = Math_Rand_ZeroFloat(1.0f);
            } else {
                sp100.z = 463.0f;
                sp100.x = Math_Rand_ZeroFloat(463);
                spF4.z = Math_Rand_ZeroFloat(2.0f);
                spF4.x = Math_Rand_ZeroFloat(1.0f);
            }

            func_808D6870(globalCtx, &sp100, &spF4, Math_Rand_ZeroFloat(0.075f) + 0.08f);
        }
    }

    this->collider.base.type = 3;
    sCape->unk_16C8 = -3.0f;
    this->unk_2E4 = 0;
    this->actor.flags &= ~1;
    this->unk_1A2++;
    this->unk_1A4++;

    // block links attack if hes shooting something
    if ((this->actionFunc == func_808DBB78) || (this->actionFunc == func_808DC4DC)) {
        if (player->unk_A73 != 0) {
            func_808DC420(this, globalCtx);
        }
    }

    this->actionFunc(this, globalCtx);

    for (i = 0; i < ARRAY_COUNT(this->timers); i++) {
        if (this->timers[i] != 0) {
            this->timers[i]--;
        }
    }

    if (this->unk_1A6 != 0) {
        this->unk_1A6--;
    }

    if (this->unk_2D4 != 0) {
        this->unk_2D4--;
    }

    if (this->unk_2E8 != 0) {
        this->unk_2E8--;
    }

    if (this->unk_2E6 != 0) {
        this->unk_2E6--;
    }

    if (this->unk_19C != 0) {
        this->unk_19C--;
    }

    if (this->cutsceneState == 0) {
        func_808DD20C(this, globalCtx);
        func_808D70F0(&this->unk_1FC, &this->collider);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->collider);

        if (this->unk_2D4 == 0) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &this->collider);

            if ((this->actionFunc != func_808DC75C) && (this->actionFunc != func_808DCB7C) &&
                (this->actionFunc != func_808DD14C)) {
                CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &this->collider);
            }
        }
    }

    if (this->unk_199 != 0) {
        sin = Math_Sins(-this->actor.shape.rot.y);
        cos = Math_Coss(-this->actor.shape.rot.y);
        // flip mults if needed
        target50C_X = ((this->actor.velocity.z * sin) + (cos * this->actor.velocity.x)) * 300.0f;
        target50C_Y = ((-sin * this->actor.velocity.x) + (cos * this->actor.velocity.z)) * 300.0f;
        target50C_Z = (Math_Sins(this->unk_1A2 * 2268) * -500.0f) - 500.0f;
    } else {
        target50C_X = 0.0f; // x second?
        target50C_Y = 0.0f;
        target50C_Z = 0.0f;
    }

    this->unk_199 = 0;

    Math_SmoothScaleMaxMinF(&this->unk_50C.x, target50C_X, 1.0f, 600.0f, 0.0f);
    Math_SmoothScaleMaxMinF(&this->unk_50C.y + 1296, target50C_Y, 1.0f, 600.0f, 0.0f); // float for 1296?
    Math_SmoothScaleMaxMinF(&this->unk_50C.z, target50C_Z, 1.0f, 100.0f, 0.0f);

    if (this->timers[2] == 1) {
        Audio_PlayActorSound2(this, NA_SE_EN_GANON_LAUGH);
    }

    if (this->timers[2] == 100) {
        Audio_PlayActorSound2(this, NA_SE_EN_FANTOM_ST_LAUGH);
        this->timers[2] = 0;
    }

    if ((this->unk_2E6 != 0) || (this->unk_2E8 != 0)) {
        for (i = 1; i < ARRAY_COUNT(this->unk_49C); i++) {
            if (this->unk_4E4[i] != 0) {
                this->unk_4E4[i]--;
                Math_SmoothScaleMaxF(&this->unk_49C[i], this->unk_508, 1.0f, 2.0f);
            } else {
                Math_SmoothDownscaleMaxF(&this->unk_49C[i], 1.0f, 2.0f);
            }
        }

        // link hit, spawn shock and play sound
        if (this->unk_2E8 != 0) {
            func_80078914(&player->actor.projectedPos, NA_SE_PL_SPARK - SFX_FLAG);
            func_808D6BF0(globalCtx, 700.0f, 1);
        }
    }

    if (this->unk_19F != 0) {
        this->unk_19F = 0;
        spE8 = this->actor.posRot.pos;
        spE8.y = 0.0f;
        func_808D6D60(globalCtx, &spE8, 0.2f, 0.7f); // no f?
        func_808D6D60(globalCtx, &spE8, 0.3f, 0.8f); // no f?
    }

    if (this->unk_26C != 0) {
        this->unk_26C--;

        if (this->unk_26C == 0) {
            func_808D6CBC(globalCtx, 1.0f, 0.0f, 0.0f);
        }

        func_808D6CBC(globalCtx, 1.0f, D_808E4D44[i] * (M_PI / 5) + this->unk_270,
                      Math_Rand_CenteredFloat(M_PI / 5) + (M_PI / 2));
    }

    // see if light ball hit and should knock platform down?
    if ((this->unk_19C != 0) && (this->unk_19E < 4)) {
        if ((this->unk_19A == 0) && (this->unk_19C == 20)) {
            this->unk_19A = 1;
            spCC.y = 0.0f; // x first?
            spCC.x = -180.0f;

            for (i = 0; i < 4; i++) {
                spCC.z = -180.0f;

                for (j = 0; j < 4; j++) {
                    func_808E0F4C(this, globalCtx, &spCC);
                    spCC.z += 120.0f;
                }

                spCC.x += 120.0f;
            }
        } else if (this->unk_19C < 30) {
            spD8.x = 0.0f;
            spD8.y = 0.0f;
            spD8.z = (30.0f - this->unk_19C) * 15.0f;

            Matrix_RotateY(Math_Rand_ZeroFloat(M_PI * 2), MTXMODE_NEW);
            Matrix_MultVec3f(&spD8, &spCC);

            this->unk_19E += func_808E0F4C(this, globalCtx, &spCC);
        }
    }

    // see if a bomb exploded near a group of platforms and if they should fall
    explosive = globalCtx->actorCtx.actorList[ACTORTYPE_EXPLOSIVES].first;

    while (explosive != NULL) {
        if (explosive->params == 1) {
            for (i = 0; i < 8; i++) {
                spBC.x = 0.0f;
                spBC.y = 0.0f;
                spBC.z = 60.0f;

                Matrix_RotateY(i * (M_PI / 4), MTXMODE_NEW);
                Matrix_MultVec3f(&spBC, &spB0);

                spA4.x = explosive->posRot.pos.x + spB0.x;
                spA4.y = explosive->posRot.pos.y;
                spA4.z = explosive->posRot.pos.z + spB0.z;

                func_808E0F4C(this, globalCtx, &spA4);
            }
        }
        explosive = explosive->next;
    }

    func_808E3564(globalCtx);

    prop = globalCtx->actorCtx.actorList[ACTORTYPE_PROP].first;
    // is this supposed to break after successfully finding one platform?
    while (prop != NULL) {
        if ((prop->id == ACTOR_BG_GANON_OTYUKA)) {
            platform = (BgGanonOtyuka*)prop;

            if (platform->unk_16E != 0) {
                this->unk_1A0 = 1;
            }
        } else {
            prop = prop->next;
        }
    }

    globalCtx->envCtx.unk_BF = 0;
    globalCtx->envCtx.unk_BE = 0;
    globalCtx->envCtx.unk_DC = 2;

    switch (this->unk_1A0) {
        case 1:
            Math_SmoothScaleMaxF(&globalCtx->envCtx.unk_D8, 0.0f, 1.0f, 0.02f);
            break;
        case 2:
            globalCtx->envCtx.unk_BD = 1;
            Math_SmoothScaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.1f);
            break;
        case 3:
            globalCtx->envCtx.unk_BD = 1;
            Math_SmoothScaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.02f);
            break;
        case 4:
            globalCtx->envCtx.unk_BD = 3;
            globalCtx->envCtx.unk_D8 = 1.0f;
            break;
        case 36:
            globalCtx->envCtx.unk_BD = 0;
            globalCtx->envCtx.unk_D8 = 1.0f;
            break;
        case 5:
            globalCtx->envCtx.unk_BD = 4;
            globalCtx->envCtx.unk_D8 = 1.0f;
            break;
        case 6:
            globalCtx->envCtx.unk_BE = 5;
            globalCtx->envCtx.unk_BD = 3;
            Math_SmoothDownscaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 0.075f);
            break;
        case 7:
            globalCtx->envCtx.unk_BE = 5;
            globalCtx->envCtx.unk_D8 = 0.0f;
            break;
        case 65:
            globalCtx->envCtx.unk_BE = 3;
            globalCtx->envCtx.unk_BD = 6;
            Math_SmoothDownscaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 0.05f);
            break;
        case 8:
            globalCtx->envCtx.unk_BE = 7;
            globalCtx->envCtx.unk_D8 = 0.0f;
            break;
        case 75:
            globalCtx->envCtx.unk_BE = 4;
            globalCtx->envCtx.unk_BD = 8;
            Math_SmoothDownscaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 0.05f);
            break;
        case 9:
            globalCtx->envCtx.unk_BE = 3;
            globalCtx->envCtx.unk_BD = 9;
            Math_SmoothScaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.05f);
            break;
        case 10:
            globalCtx->envCtx.unk_BE = 3;
            globalCtx->envCtx.unk_BD = 0xA;
            Math_SmoothDownscaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 0.05f);
            break;
        case 11:
            globalCtx->envCtx.unk_BE = 3;
            globalCtx->envCtx.unk_BD = 0xB;
            Math_SmoothScaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.05f);
            this->unk_1A4 = 0;
            break;
        case 12:
            globalCtx->envCtx.unk_BE = 0xC;
            globalCtx->envCtx.unk_BD = 0xB;
            Math_SmoothScaleMaxF(&globalCtx->envCtx.unk_D8, (Math_Coss(this->unk_1A4 * 0x1800) * 0.5f) + 0.5f, 1.0f,
                                 1.0f);
            break;
        case 13:
            globalCtx->envCtx.unk_BE = 0xC;
            globalCtx->envCtx.unk_BD = 3;
            Math_SmoothScaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.05f);
            break;
        case 14:
            globalCtx->envCtx.unk_BD = 0xD;
            Math_SmoothScaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.025f);
            break;
        case 15:
            globalCtx->envCtx.unk_BD = 0xE;
            globalCtx->envCtx.unk_D8 = 1.0f;
            break;
        case 16:
            globalCtx->envCtx.unk_BE = 0xE;
            globalCtx->envCtx.unk_BD = 0xF;
            Math_SmoothScaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.01f);
            break;
        case 17:
            globalCtx->envCtx.unk_BE = 0x10;
            globalCtx->envCtx.unk_BD = 0xF;
            Math_SmoothDownscaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 0.05f);
            break;
        case 21:
            globalCtx->envCtx.unk_BE = 2;
            globalCtx->envCtx.unk_BD = 1;
            break;
        default:
            break;
    }

    this->unk_1A0 = 0;

    if (this->unk_714 != 0.0f) {
        globalCtx->envCtx.unk_E2[3] = this->unk_714;
        globalCtx->envCtx.unk_E2[0] = globalCtx->envCtx.unk_E2[1] = globalCtx->envCtx.unk_E2[2] = 255;
        globalCtx->envCtx.unk_E1 = 1;
    } else if (this->unk_1C4 != 0) {
        globalCtx->envCtx.unk_E1 = 1;
        globalCtx->envCtx.unk_E2[0] = globalCtx->envCtx.unk_E2[1] = globalCtx->envCtx.unk_E2[2] = 255;

        if ((this->unk_1C4 & 1) != 0) {
            globalCtx->envCtx.unk_E2[3] = 0x64;
        } else {
            globalCtx->envCtx.unk_E2[3] = 0;
        }

        this->unk_1C4--;
    } else {
        globalCtx->envCtx.unk_E2[3] = 0;
        globalCtx->envCtx.unk_E1 = 0;
    }

    if (this->unk_66E != 0) {
        this->unk_66E--;

        if (this->unk_66C == 1) {
            target670 = 40.0f;
        } else if (this->unk_66C == 4) {
            target670 = 25.0f;
        } else {
            target670 = 10.0f;
        }

        Math_SmoothScaleMaxF(&this->unk_670, target670, 0.3f, 10.0f);
    } else {
        Math_SmoothDownscaleMaxF(&this->unk_670, 1.0f, 5.0f);

        if (this->unk_670 == 0.0f) {
            this->unk_66C = 0;
        }
    }

    if (this->unk_66C != 0) {
        D_8015FCF0 = 1;

        if (this->unk_66C == 1) {
            D_8015FCF8 = this->actor.posRot.pos;
        }

        D_8015FD06 = this->unk_670;
        D_8015FD08 = 10.0f;
        D_8015FD0C = 0;
    } else {
        D_8015FCF0 = 0;
    }

    if (this->unk_274 != 0) {
        decr274 = this->unk_274 - 1;

        this->unk_278.x = this->unk_2EC[0].x;
        this->unk_278.y = this->unk_2EC[0].y + 50.0f + 30.0f;
        this->unk_278.z = this->unk_2EC[0].z;

        decr2pi = decr274 * 1.2566371f; // fake?
        // temp_f24 = sinf(decr2pi) * 600.0f; might need a temp for cosf
        // 5 or 6 light balls that go into the charge. not the same as the ones that he throws
        Actor_SpawnAsChild(&globalCtx->actorCtx, &this->actor, globalCtx, ACTOR_BOSS_GANON,
                           this->unk_1FC.x + sinf(decr2pi) * 600.0f, this->unk_1FC.y,
                           this->unk_1FC.z + (cosf(decr2pi) * 600.0f), 0, (decr274 * 13107.2f) + 0x6000, 0,
                           0xFA + decr274);
        this->unk_274 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/BossGanon_Update.s")
#endif

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

// check distance and set platform to fall if it passes
s32 func_808E0F4C(BossGanon* this, GlobalContext* globalCtx, Vec3f* arg2);
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808E0F4C.s")

void func_808E1034(Actor* thisx, GlobalContext* globalCtx2) {
    u8 hitWithBottle;
    s16 i;
    s16 spBA = 0;
    Vec3f spAC;
    Vec3f spA0;
    Vec3f sp94;
    BossGanon* this = THIS;
    GlobalContext* globalCtx = globalCtx2;
    f32 xDistFromLink;
    f32 yDistFromLink;
    f32 zDistFromLink;
    f32 minReflectDist;
    f32 xDistFromGanondorf;
    f32 yDistFromGanondorf;
    f32 zDistFromGanondorf;
    Player* player = PLAYER;
    s32 pad;
    BossGanon* ganondorf = (BossGanon*)this->actor.parent;
    s32 pad1;

    this->unk_1A2++;
    ganondorf->unk_1A0 = 1;

    if (this->unk_1A8 != 0) {
        if (this->unk_1A8 == 2) {
            Math_SmoothDownscaleMaxF(&this->animationLength, 1.0f, 10.0f);
            Math_SmoothScaleMaxF(&this->actor.scale.x, 30.0f, 0.5f, 100.0f);
        } else {
            this->actor.shape.rot.y += 0x1000;
            ganondorf->unk_66E = 1;
            D_8015FCF8 = this->actor.posRot.pos;
            Math_SmoothDownscaleMaxF(&this->animationLength, 1.0f, 30.0f);
            Math_SmoothScaleMaxF(&this->actor.scale.x, 20.0f, 0.5f, 100.0f);
            this->unk_1C8 += ((M_PI / 2) + Math_Rand_ZeroFloat((M_PI / 4)));
        }

        Actor_SetScale(&this->actor, this->actor.scale.x);

        if (this->animationLength == 0.0f) {
            Actor_Kill(&this->actor);
            return;
        }
    } else {
        Audio_PlayActorSound2(&this->actor, NA_SE_EN_GANON_FIRE - SFX_FLAG);

        if (this->unk_1A2 & 1) {
            Actor_SetScale(&this->actor, 6.0f);
        } else {
            Actor_SetScale(&this->actor, 5.25f);
        }

        this->actor.shape.rot.z += (s16)(Math_Rand_ZeroOne() * 20000.0f) + 0x4000;

        for (i = 0; i < ARRAY_COUNT(this->timers); i++) {
            if (this->timers[i] != 0) {
                this->timers[i]--;
            }
        }

        xDistFromGanondorf = ganondorf->unk_1FC.x - this->actor.posRot.pos.x;
        yDistFromGanondorf = ganondorf->unk_1FC.y - this->actor.posRot.pos.y;
        zDistFromGanondorf = ganondorf->unk_1FC.z - this->actor.posRot.pos.z;

        xDistFromLink = player->actor.posRot.pos.x - this->actor.posRot.pos.x;
        yDistFromLink = (player->actor.posRot.pos.y + 40.0f) - this->actor.posRot.pos.y;
        zDistFromLink = player->actor.posRot.pos.z - this->actor.posRot.pos.z;

        func_8002D908(&this->actor);
        func_8002D7EC(&this->actor);

        switch (this->unk_1C2) {
            case 0:
                if ((player->stateFlags1 & 2) &&
                    (ABS((s16)(player->actor.shape.rot.y - (s16)(ganondorf->actor.yawTowardsLink + 0x8000))) <
                     0x2000) &&
                    (sqrtf(SQ(xDistFromLink) + SQ(yDistFromLink) + SQ(zDistFromLink)) <= 25.0f)) {
                    hitWithBottle = true;
                } else {
                    hitWithBottle = false;
                }

                if ((this->collider.base.acFlags & 2) || hitWithBottle) {
                    ColliderBody* acHitItem = this->collider.body.acHitItem;
                    this->collider.base.acFlags &= ~2;

                    if ((hitWithBottle == false) && (acHitItem->toucher.flags & 0x100000)) {
                        spBA = 2;
                        Audio_PlaySoundGeneral(NA_SE_IT_SHIELD_REFLECT_MG, &player->actor.projectedPos, 4, &D_801333E0,
                                               &D_801333E0, &D_801333E8);
                        func_800AA000(this->actor.xyzDistFromLinkSq, 0xFF, 0x14, 0x96);
                    } else {
                        spBA = 1;
                        this->actor.posRot.rot.y = atan2s(zDistFromGanondorf, xDistFromGanondorf);
                        this->actor.posRot.rot.x =
                            atan2s(sqrtf(SQ(xDistFromGanondorf) + SQ(zDistFromGanondorf)), yDistFromGanondorf);
                        this->unk_1A4++;
                        this->timers[1] = 2;
                        Audio_PlaySoundGeneral(NA_SE_IT_SWORD_REFLECT_MG, &player->actor.projectedPos, 4, &D_801333E0,
                                               &D_801333E0, &D_801333E8);
                        func_800AA000(this->actor.xyzDistFromLinkSq, 0xB4, 0x14, 0x64);

                        if (hitWithBottle == false) {
                            // if ganondorf is 250 units away from link, at least 3 volleys are required
                            if ((ganondorf->actor.xyzDistFromLinkSq > 62500.0f) && (this->unk_1A4 < 3)) {
                                this->unk_1C2 = 1;
                            } else if (Math_Rand_ZeroOne() < 0.7f) {
                                this->unk_1C2 = 1;
                            } else {
                                this->unk_1C2 = 3;
                            }

                            // if a spin attack is used
                            if (player->swordAnimation >= 24) {
                                this->actor.speedXZ = 20.0f;
                            }
                            break;
                        } else {
                            if (Math_Rand_ZeroOne() < 0.9f) {
                                this->unk_1C2 = 1;
                            } else {
                                this->unk_1C2 = 3;
                            }
                        }
                    }
                } else {
                    if (sqrtf(SQ(xDistFromLink) + SQ(yDistFromLink) + SQ(zDistFromLink)) <= 25.0f) {
                        spBA = 5;
                        func_8002F6D4(globalCtx, &this->actor, 3.0f, this->actor.posRot.rot.y, 0.0f, 0x30);
                        Audio_PlaySoundAtPosition(globalCtx, &this->actor.posRot.pos, 0x28, NA_SE_EN_GANON_HIT_THUNDER);
                        ganondorf->timers[2] = 20;

                        for (i = 0; i < ARRAY_COUNT(ganondorf->unk_4E4); i++) {
                            ganondorf->unk_4E4[i] = D_808E4C58[i];
                        }

                        ganondorf->unk_2E6 = 0;
                        ganondorf->unk_2E8 = 60;
                        ganondorf->unk_508 = 4.0f;
                    }
                }
                break;
            case 1:
                if ((ganondorf->actionFunc == func_808DC14C) && (ganondorf->unk_1C2 == 1)) {
                    minReflectDist = (this->actor.speedXZ >= 19.0f) ? 250.0f : 170.0f;

                    if (sqrtf(SQ(xDistFromGanondorf) + SQ(yDistFromGanondorf) + SQ(zDistFromGanondorf)) <
                        minReflectDist) {
                        ganondorf->unk_1C0 = 1;
                        this->timers[0] = 8;
                        this->unk_1C2 = 2;
                    }
                }
                break;
            case 2:
                if (this->timers[0] == 1) {
                    spBA = 1;
                    this->actor.posRot.rot.y = atan2s(zDistFromLink, xDistFromLink);
                    this->actor.posRot.rot.x = atan2s(sqrtf(SQ(xDistFromLink) + SQ(zDistFromLink)), yDistFromLink);
                    this->timers[1] = 2;
                    Audio_PlayActorSound2(&this->actor, NA_SE_IT_SWORD_REFLECT_MG);
                    Audio_PlayActorSound2(&this->actor, NA_SE_EN_GANON_AT_RETURN);
                    this->unk_1C2 = 0;
                    break;
                }
            case 4:
                if (sqrtf(SQ(xDistFromGanondorf) + SQ(yDistFromGanondorf) + SQ(zDistFromGanondorf)) < 30.0f) {
                    spBA = 3;
                    Audio_PlaySoundAtPosition(globalCtx, &this->actor.posRot.pos, 40, NA_SE_EN_GANON_DAMAGE1);
                    Audio_PlaySoundAtPosition(globalCtx, &this->actor.posRot.pos, 40, NA_SE_EN_GANON_HIT_THUNDER);
                }
                break;
            case 3:
                if (sqrtf(SQ(xDistFromGanondorf) + SQ(yDistFromGanondorf) + SQ(zDistFromGanondorf)) < 100.0f) {
                    ganondorf->unk_1C0 = 1;
                    this->unk_1C2 = 4;
                }
                break;
        }

        Collider_CylinderUpdate(&this->actor, &this->collider);

        if (this->timers[1] == 0) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &this->collider.base);
        }

        for (i = 0; i < 2; i++) {
            spA0.x = spA0.z = 0.0f;
            spA0.y = 0.2f;

            spAC.x = spAC.y = spAC.z = 0.0f;

            sp94.x = Math_Rand_CenteredFloat(30.0f) + this->actor.posRot.pos.x;
            sp94.y = Math_Rand_CenteredFloat(30.0f) + this->actor.posRot.pos.y;
            sp94.z = Math_Rand_CenteredFloat(30.0f) + this->actor.posRot.pos.z;

            func_808D69B0(globalCtx, &sp94, &spAC, &spA0, Math_Rand_ZeroFloat(500.0f) + 700.0f, 0x1E);
        }

        if (this->actor.posRot.pos.y < 10.0f) {
            func_8002E4B4(globalCtx, &this->actor, 0.0f, 20.0f, 20.0f, 4);
        }

        if ((fabsf(this->actor.posRot.pos.x) > 465.0f) || (this->actor.posRot.pos.y > 500.0f) ||
            (fabsf(this->actor.posRot.pos.z) > 465.0f)) {
            spBA = 4;
        }

        if ((spBA != 0) || (this->actor.bgCheckFlags & 1)) {
            f32 sp58;
            f32 sp54;
            f32 phi_f20;
            s16 sp4E;

            if (spBA == 1) {
                sp58 = Math_Rand_ZeroFloat(100.0f) + 300.0f;
                sp54 = 10.0f;
                phi_f20 = 25.0f;
                sp4E = 40;
            } else {
                sp58 = Math_Rand_ZeroFloat(200.0f) + 500.0f;
                sp54 = 15.0f;
                phi_f20 = 30.0f;
                sp4E = 70;
                Audio_PlaySoundAtPosition(globalCtx, &this->actor.posRot.pos, 0x50, NA_SE_EN_GANON_HIT_THUNDER);
            }

            for (i = 0; i < sp4E; i++) {
                if (spBA != 0) {
                    spAC.x = Math_Rand_CenteredFloat(phi_f20);
                    spAC.y = Math_Rand_CenteredFloat(phi_f20);
                    spAC.z = Math_Rand_CenteredFloat(phi_f20);
                } else {
                    spAC.x = Math_Rand_CenteredFloat(phi_f20);
                    spAC.y = Math_Rand_ZeroFloat(25.0f);
                    spAC.z = Math_Rand_CenteredFloat(phi_f20);
                }

                func_808D6AAC(globalCtx, &this->actor.posRot.pos, &spAC, &D_808E4C6C, sp58, sp54, 0x1E);
            }

            if (spBA != 1) {
                this->unk_1A8 = 1;

                if (spBA == 0) {
                    func_808E0F4C(this, globalCtx, &this->actor.posRot.pos);
                }

                if (spBA == 3) {
                    func_808DC66C(ganondorf, globalCtx);
                } else if (ganondorf->actionFunc == func_808DC14C) {
                    func_808DBAF0(ganondorf, globalCtx);

                    if (spBA == 5) {
                        ganondorf->timers[0] = 125;
                    }
                }
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808E1B54.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808E1EB4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808E229C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808E2544.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808E324C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808E3564.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon/func_808E3D84.s")
