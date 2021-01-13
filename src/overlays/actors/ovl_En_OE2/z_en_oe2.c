/*
 * File: z_en_oe2.c
 * Overlay: ovl_En_Oe2
 * Description: Blue Navi Target Spot
 */

#include "z_en_oe2.h"
#include "objects/Santa/Santa.h"

#define FLAGS 0x00000009

#define THIS ((Santa*)thisx)

void Santa_Init(Actor* thisx, GlobalContext* globalCtx);
void Santa_Destroy(Actor* thisx, GlobalContext* globalCtx);
void Santa_Update(Actor* thisx, GlobalContext* globalCtx);
void Santa_Draw(Actor* thisx, GlobalContext* globalCtx);

void Santa_Wait(Santa* this, GlobalContext* globalCtx);

const ActorInit En_OE2_InitVars = {
    ACTOR_EN_OE2,
    ACTORTYPE_NPC,
    FLAGS,
    OBJECT_OE2,
    sizeof(Santa),
    (ActorFunc)Santa_Init,
    (ActorFunc)Santa_Destroy,
    (ActorFunc)Santa_Update,
    (ActorFunc)Santa_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    { COLTYPE_UNK10, 0x00, 0x11, 0x39, 0x10, COLSHAPE_CYLINDER },
    { 0x00, { 0x00000000, 0x00, 0x00 }, { 0xFFCFFFFF, 0x00, 0x00 }, 0x00, 0x01, 0x01 },
    { 30, 40, 0, { 0, 0, 0 } },
};

void Santa_Init(Actor* thisx, GlobalContext* globalCtx) {
    Santa* this = THIS;

    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawFunc_Circle, 45.0f);
    SkelAnime_InitFlex(globalCtx, &this->skelAnime, &gSantaSkel, &gSantaIdleAnim, 
                       this->jointTable, this->morphTable, 18);
    this->actor.posRot2.pos = this->actor.posRot.pos;
    this->actor.posRot2.pos.y += 60.0f;
    Collider_InitCylinder(globalCtx, &this->collider);
    Collider_SetCylinder(globalCtx, &this->collider, &this->actor, &sCylinderInit);
    Actor_SetScale(&this->actor, 0.01f);
    this->actor.colChkInfo.mass = 0xFF;
    this->actionFunc = Santa_Wait;
}

void Santa_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void Santa_Talk(Santa* this, GlobalContext* globalCtx) {
    u8 dialogState = func_8010BDBC(&globalCtx->msgCtx);

    if (dialogState != 4) {
        if (dialogState == 6 && func_80106BC8(globalCtx)) { // advanced final textbox
            this->actionFunc = Santa_Wait;
        }
    }
}

void Santa_Wait(Santa* this, GlobalContext* globalCtx) {
    s16 yawDiff = this->actor.yawTowardsLink - this->actor.shape.rot.y;

    if (func_8002F194(&this->actor, globalCtx)) { 
        this->actionFunc = Santa_Talk;
    } else if ((this->actor.xzDistToLink < 90.0f) && (ABS(yawDiff) < 0x4000)) {
        this->actor.textId = 0x4058;
        func_8002F2CC(&this->actor, globalCtx, 90.0f);
    }
}

void Santa_Update(Actor* thisx, GlobalContext* globalCtx) {
    Santa* this = THIS;
    Player* player = PLAYER;

    SkelAnime_Update(&this->skelAnime);
    func_8002E4B4(globalCtx, &this->actor, 0.0f, 0.0f, 0.0f, 4);
    Collider_CylinderUpdate(&this->actor, &this->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->collider);
    this->limbAngle.unk_18 = player->actor.posRot.pos;
    this->limbAngle.unk_14 = kREG(16) + 30.0f;
    func_80034A14(&this->actor, &this->limbAngle, kREG(17) + 0xC, 2);
    this->actionFunc(this, globalCtx);
}

s32 Santa_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    Santa* this = THIS;

    if (limbIndex == 3) {
        rot->y += this->limbAngle.unk_08.y;
        rot->x += this->limbAngle.unk_08.x;
    }

    return false;
}

void Santa_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Santa* this = THIS;

    func_800943C8(globalCtx->state.gfxCtx);
    SkelAnime_DrawFlexOpa(globalCtx, this->skelAnime.skeleton, this->skelAnime.jointTable, this->skelAnime.dListCount,
                          Santa_OverrideLimbDraw, NULL, this);
}
