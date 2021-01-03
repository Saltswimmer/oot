/*
 * File: z_en_oe2.c
 * Overlay: ovl_En_Oe2
 * Description: Blue Navi Target Spot
 */

#include "z_en_oe2.h"
#include "objects/object_oE2/object_oE2.h"

#define FLAGS 0x00000009

#define THIS ((EnOE2*)thisx)

void EnOE2_Init(Actor* thisx, GlobalContext* globalCtx);
void EnOE2_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnOE2_Update(Actor* thisx, GlobalContext* globalCtx);
void EnOE2_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnOE2_Wait(EnOE2* this, GlobalContext* globalCtx);

const ActorInit En_OE2_InitVars = {
    ACTOR_EN_OE2,
    ACTORTYPE_NPC,
    FLAGS,
    OBJECT_OE2,
    sizeof(EnOE2),
    (ActorFunc)EnOE2_Init,
    (ActorFunc)EnOE2_Destroy,
    (ActorFunc)EnOE2_Update,
    (ActorFunc)EnOE2_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    { COLTYPE_UNK10, 0x00, 0x00, 0x39, 0x20, COLSHAPE_CYLINDER },
    { 0x00, { 0x00000000, 0x00, 0x00 }, { 0x00000000, 0x00, 0x00 }, 0x00, 0x00, 0x01 },
    { 20, 46, 0, { 0, 0, 0 } },
};

void EnOE2_SetupAction(EnOE2* this, EnOE2ActionFunc actionFunc) {
    this->actionFunc = actionFunc;
}

void EnOE2_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnOE2* this = THIS;

    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawFunc_Circle, 24.0f);
    Collider_InitCylinder(globalCtx, &this->collider);
    Collider_SetCylinder(globalCtx, &this->collider, &this->actor, &sCylinderInit);
    this->actor.shape.unk_08 = -550.0f;
    this->actor.unk_4C = -800.0f;
    this->actor.posRot2.pos = this->actor.posRot.pos;
    this->actor.posRot2.pos.y += 40.0f;
    this->actor.colChkInfo.mass = 0xFF;
    Actor_SetScale(&this->actor, 0.01f + 0.001f);
    SkelAnime_Init(globalCtx, &this->skelAnime, &gOe22Skel, &gOe2Anim, this->jointTable, this->morphTable, 39);
    EnOE2_SetupAction(this, EnOE2_Wait);
}

void EnOE2_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnOE2_UpdateEyes(EnOE2* this) {
    if (DECR(this->blinkTimer) == 0) {
        this->eyeIndex++;
        if (this->eyeIndex >= 2) {
            this->blinkTimer = Rand_S16Offset(30, 30);
            this->eyeIndex = 0;
        }
    }
}

void EnOE2_Talk(EnOE2* this, GlobalContext* globalCtx) {
    u8 dialogState = func_8010BDBC(&globalCtx->msgCtx);

    if (dialogState != 4) {
        if (dialogState == 6 && func_80106BC8(globalCtx)) { // advanced final textbox
            this->actionFunc = EnOE2_Wait;
        }
    }
}

void EnOE2_Wait(EnOE2* this, GlobalContext* globalCtx) {
    s16 yawDiff = this->actor.yawTowardsLink - this->actor.shape.rot.y;
    Player* player = PLAYER;
    if (func_8002F194(&this->actor, globalCtx)) {
        this->actionFunc = EnOE2_Talk;
    } else {
        if ((this->actor.xzDistToLink < 100.0f) && (ABS(yawDiff) <= 0x4000)) {
            this->actor.textId = 0x202C;
            func_8002F2CC(&this->actor, globalCtx, 100.0f);
        }
    }
}

void EnOE2_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnOE2* this = THIS;
    Player* player = PLAYER;

    this->actionFunc(this, globalCtx);
    EnOE2_UpdateEyes(this);
    SkelAnime_Update(&this->skelAnime);
    Collider_CylinderUpdate(&this->actor, &this->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->collider.base);

    this->angleThing.unk_18 = player->actor.posRot.pos;
    this->angleThing.unk_14 = kREG(16) + 15.0f;
    func_80034A14(&this->actor, &this->angleThing, kREG(17) + 0xC, 2);
    func_8002E4B4(globalCtx, &this->actor, 0.0f, 0.0f, 0.0f, 4);
}

Gfx* EnOE2_SetClothesColor(GraphicsContext* gfxCtx) {
    Gfx* displayList;
    Gfx* displayListHead;

    displayList = Graph_Alloc(gfxCtx, 4 * sizeof(Gfx));
    displayListHead = displayList;

    gDPPipeSync(displayListHead++);
    gDPSetEnvColor(displayListHead++, 50, 200, 45, 0);

    gSPEndDisplayList(displayListHead);
    return displayList;
}

s32 EnOE2_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnOE2* this = THIS;

    if (limbIndex == 19) {
        rot->x += this->angleThing.unk_0E.y;
        rot->y -= this->angleThing.unk_0E.x;
    } else if (limbIndex == 23) {
        rot->x += this->angleThing.unk_08.y;
        rot->z += this->angleThing.unk_08.x;
    }

    return 0;
}

void EnOE2_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static u64* eyeTextures[] = { gOe2EyeOpenTex, gOe2EyeClosedTex };
    EnOE2* this = THIS;

    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(globalCtx->state.gfxCtx->polyOpa.p++, 0x0D, EnOE2_SetClothesColor(globalCtx->state.gfxCtx));
    gSPSegment(globalCtx->state.gfxCtx->polyOpa.p++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTextures[this->eyeIndex]));
    SkelAnime_DrawOpa(globalCtx, this->skelAnime.skeleton, this->skelAnime.jointTable, EnOE2_OverrideLimbDraw, NULL,
                      this);
}
