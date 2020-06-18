#include "z_en_skj.h"

#define FLAGS 0x02000015

#define THIS ((EnSkj*)thisx)

void EnSkj_Init(Actor* thisx, GlobalContext* globalCtx);
void EnSkj_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnSkj_Update(Actor* thisx, GlobalContext* globalCtx);
void EnSkj_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80B00964(Actor* thisx, GlobalContext* globalCtx); // update for params 5
void func_80B01244(Actor* thisx, GlobalContext* globalCtx); // update for params 6

void func_80AFE390(EnSkj* this);
void func_80B00514(EnSkj* this);
void func_80AFF038(EnSkj* this);
void func_80B006F8(EnSkj* this);
void func_80B00680(EnSkj* this);

void func_80B00F2C(EnSkj* this, GlobalContext* globalCtx);

// ocarina minigame action funcs
void func_80B00A54(EnSkj* this, GlobalContext* globalCtx);
void func_80B00BB0(EnSkj* this, GlobalContext* globalCtx);
void func_80B00B0C(EnSkj* this, GlobalContext* globalCtx);
void func_80B00C38(EnSkj* this, GlobalContext* globalCtx);
void func_80B00EA4(EnSkj* this, GlobalContext* globalCtx);
void func_80B01004(EnSkj* this, GlobalContext* globalCtx);
void func_80B01040(EnSkj* this, GlobalContext* globalCtx);
void func_80B010C4(EnSkj* this, GlobalContext* globalCtx);
void func_80B01134(EnSkj* this, GlobalContext* globalCtx);
void func_80B00EE0(EnSkj* this, GlobalContext* globalCtx);
void func_80B00F64(EnSkj* this, GlobalContext* globalCtx);
void func_80B00A54(EnSkj* this, GlobalContext* globalCtx);
void func_80B011CC(EnSkj* this, GlobalContext* globalCtx);

// actionFuncs enemy?
void func_80AFEECC(EnSkj* this, GlobalContext* globalCtx);
void func_80AFEF98(EnSkj* this, GlobalContext* globalCtx);
void func_80AFF07C(EnSkj* this, GlobalContext* globalCtx);
void func_80AFF19C(EnSkj* this, GlobalContext* globalCtx);
void func_80AFF220(EnSkj* this, GlobalContext* globalCtx);
void func_80AFF2E0(EnSkj* this, GlobalContext* globalCtx);
void func_80AFF380(EnSkj* this, GlobalContext* globalCtx);
void func_80AFF424(EnSkj* this, GlobalContext* globalCtx);
void func_80AFF620(EnSkj* this, GlobalContext* globalCtx);
void func_80AFF688(EnSkj* this, GlobalContext* globalCtx);
void func_80AFF7D8(EnSkj* this, GlobalContext* globalCtx);
void func_80AFFA0C(EnSkj* this, GlobalContext* globalCtx);
void func_80AFFD14(EnSkj* this, GlobalContext* globalCtx);
void func_80AFFD84(EnSkj* this, GlobalContext* globalCtx);
void func_80AFFE44(EnSkj* this, GlobalContext* globalCtx);
void func_80AFFED4(EnSkj* this, GlobalContext* globalCtx);
void func_80AFFF58(EnSkj* this, GlobalContext* globalCtx);
void func_80B00018(EnSkj* this, GlobalContext* globalCtx);
void func_80B00098(EnSkj* this, GlobalContext* globalCtx);
void func_80B00130(EnSkj* this, GlobalContext* globalCtx);
void func_80B00210(EnSkj* this, GlobalContext* globalCtx);
void func_80B002D8(EnSkj* this, GlobalContext* globalCtx);
void func_80B00390(EnSkj* this, GlobalContext* globalCtx);
void func_80B0042C(EnSkj* this, GlobalContext* globalCtx);
void func_80B0049C(EnSkj* this, GlobalContext* globalCtx);
void func_80B00554(EnSkj* this, GlobalContext* globalCtx);
void func_80B00638(EnSkj* this, GlobalContext* globalCtx);
void func_80B006B0(EnSkj* this, GlobalContext* globalCtx);
void func_80B00740(EnSkj* this, GlobalContext* globalCtx);

typedef struct {
    u8 unk0;
    EnSkj* skullkid;
} unkSkjStruct;

unkSkjStruct D_80B01640 = { 0, NULL };
unkSkjStruct D_80B01648[] = { { 0, NULL }, { 0, NULL } };

const ActorInit En_Skj_InitVars = {
    ACTOR_EN_SKJ,
    ACTORTYPE_ENEMY,
    FLAGS,
    OBJECT_SKJ,
    sizeof(EnSkj),
    (ActorFunc)EnSkj_Init,
    (ActorFunc)EnSkj_Destroy,
    (ActorFunc)EnSkj_Update,
    (ActorFunc)EnSkj_Draw,
};

static ColliderCylinderInit_Set3 sCylinderInit = {
    { COLTYPE_UNK10, 0x11, 0x09, 0x00, COLSHAPE_CYLINDER },
    { 0x00, { 0xFFCFFFFF, 0x00, 0x08 }, { 0xFFCFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
    { 8, 48, 0, { 0, 0, 0 } },
};

static DamageTable sDamageTable = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0xF1, 0xF2, 0xF4, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04, 0x02, 0x02, 0x08, 0x04, 0x00, 0x00, 0x00, 0x00,
};

static s32 sMinigameRewards[] = {
    GI_RUPEE_GREEN,
    GI_RUPEE_BLUE,
    GI_HEART_PIECE,
    GI_RUPEE_RED,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(unk_1F, 2, ICHAIN_CONTINUE),
    ICHAIN_F32(unk_4C, 30, ICHAIN_STOP),
};

typedef struct {
    AnimationHeader* header;
    u8 unk1;
    f32 transitionRate;
} EnSkjAnim;

EnSkjAnim sAnimations[] = {
    { 0x0600051C, 0x02, 0.0f }, { 0x060007A4, 0x02, 0.0f }, { 0x06000E10, 0x00, 0.0f }, { 0x06006A98, 0x02, 0.0f },
    { 0x06006D84, 0x02, 0.0f }, { 0x06007128, 0x02, 0.0f }, { 0x06008174, 0x00, 0.0f }, { 0x06008374, 0x00, 0.0f },
    { 0x06008E14, 0x00, 0.0f }, { 0x06008B9C, 0x00, 0.0f },
};

EnSkjActionFunc sActionFuncs[] = {
    func_80AFEECC, // 0
    func_80AFEF98, // 1
    func_80AFF07C, // 2
    func_80AFF19C, // 3
    func_80AFF220, // 4
    func_80AFF2E0, // 5
    func_80AFF380, // 6
    func_80AFF424, // 7
    func_80AFF620, // 8
    func_80AFF688, // 9
    func_80AFF7D8, // 10
    func_80AFFA0C, // 11
    func_80AFFD14, // 12
    func_80AFFD84, // 13
    func_80AFFE44, // 14
    func_80AFFED4, // 15
    func_80AFFF58, // 16
    func_80B00018, // 17
    func_80B00098, // 18
    func_80B00130, // 19
    func_80B00210, // 20
    func_80B002D8, // 21
    func_80B00390, // 22
    func_80B0042C, // 23
    func_80B0049C, // 24
    func_80B00554, // 25
    func_80B00638, // 26
    func_80B006B0, // 27
    func_80B00740, // 28
};

s32 D_80B01EA0; // gets set if actor flags & 0x100 is set

extern AnimationHeader D_06000E10;
extern SkeletonHeader D_06005F40;

// EnSkj_ChangeAnimation
void func_80AFE2B0(EnSkj* this, u8 animID) {
    f32 frameCount;

    frameCount = SkelAnime_GetFrameCount(sAnimations[animID].header);
    this->currentAnim = animID;
    SkelAnime_ChangeAnim(&this->skelAnime, sAnimations[animID].header, 1.0f, 0.0f, frameCount, sAnimations[animID].unk1,
                         sAnimations[animID].transitionRate);
}

// EnSkj_SetupAction
void func_80AFE338(EnSkj* this, u8 action) {
    this->action = action;
    this->actionFunc = sActionFuncs[action];
    switch (action) {
        case 0:
        case 3:
        case 4:
        case 9:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
            this->unk_2D3 = 0;
            break;
        default:
            this->unk_2D3 = 1;
            break;
    }
}

void func_80AFE390(EnSkj* this) {
    Vec3f mult;

    mult.x = 0.0f;
    mult.y = 0.0f;
    mult.z = 120.0f;

    Matrix_RotateY((this->actor.shape.rot.y / 32768.0f) * M_PI, MTXMODE_NEW);
    Matrix_MultVec3f(&mult, &this->center);
    this->center.x += this->actor.posRot.pos.x;
    this->center.z += this->actor.posRot.pos.z;
}

// EnSkj_SetNaviEnemyID
void func_80AFE428(EnSkj* this) {
    switch (this->actor.params) {
        case 0:
            if ((gSaveContext.itemGetInf[3] & 0x200) != 0) {
                this->actor.naviEnemyId = 0x41;
                return;
            } else {
                if ((gSaveContext.itemGetInf[1] & 0x40) != 0) {
                    this->actor.naviEnemyId = 0x40;
                    return;
                } else {
                    this->actor.naviEnemyId = 0x3F;
                    return;
                }
            }
            break;
        case 1:
        case 2:
            this->actor.naviEnemyId = 0x3F;
            break;
        default:
            this->actor.naviEnemyId = 0x36;
            break;
    }
}

//#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/EnSkj_Init.s")
void EnSkj_Init(Actor* thisx, GlobalContext* globalCtx) {
    s16 type;
    EnSkj* this = THIS;
    s32 pad;
    s32 pad1;
    Player* player;

    type = ((this->actor.params >> 0xA) & 0x3F);
    Actor_ProcessInitChain(thisx, &sInitChain);
    switch (type) {
        case 5:
            D_80B01640.unk0 = 1;
            D_80B01640.skullkid = THIS;

            this->actor.destroy = NULL;
            this->actor.draw = NULL;
            this->actor.update = func_80B00964;
            this->actor.flags = this->actor.flags &= ~5;
            Actor_ChangeType(globalCtx, &globalCtx->actorCtx, &this->actor, ACTORTYPE_PROP);
            break;
        case 6: // ocarina minigame manager (placed on tree stump)
            D_80B01640.unk0 = 1;
            D_80B01640.skullkid = THIS;

            this->actor.destroy = NULL;
            this->actor.draw = NULL;
            this->actor.update = func_80B01244;
            this->actor.flags = this->actor.flags &= ~5;
            Actor_ChangeType(globalCtx, &globalCtx->actorCtx, &this->actor, ACTORTYPE_PROP);
            this->actor.posRot2.pos.x = 1230.0f;
            this->actor.posRot2.pos.y = -90.0f;
            this->actor.posRot2.pos.z = 450.0f;
            this->actionFunc = func_80B00A54;
            break;
        default:
            this->actor.params = type;

            if ((this->actor.params != 0) && (this->actor.params != 1) && (this->actor.params != 2)) {
                if (INV_CONTENT(ITEM_TRADE_ADULT) < ITEM_SAW) {
                    Actor_Kill(&this->actor);
                    return;
                }
            }

            func_80AFE428(this);
            SkelAnime_InitSV(globalCtx, &this->skelAnime, &D_06005F40, &D_06000E10, this->limbDrawTable,
                             this->transitionDrawTable, 19);
            if ((type >= 0) && (type < 3)) {
                this->actor.flags &= ~5;
                this->actor.flags |= 9;
                Actor_ChangeType(globalCtx, &globalCtx->actorCtx, &this->actor, ACTORTYPE_NPC);
            }

            if ((type < 0) || (type >= 7)) {
                this->actor.flags &= ~0x02000000;
            }

            if ((type > 0) && (type < 3)) {
                // ocarina minigame
                this->actor.unk_1F = 7;
                this->posCopy = this->actor.posRot.pos;
                D_80B01648[type - 1].unk0 = 1;
                D_80B01648[type - 1].skullkid = THIS;
                this->unk_2D8 = 0;
                this->alpha = 0;
                func_80B00514(this);
            } else {
                this->alpha = 0xFF;
                func_80AFF038(this);
            }

            this->actor.colChkInfo.damageTable = &sDamageTable;
            this->actor.colChkInfo.health = 10;
            Collider_InitCylinder(globalCtx, &this->collider);
            Collider_SetCylinder_Set3(globalCtx, &this->collider, &this->actor, &sCylinderInit);
            ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawFunc_Circle, 40.0f);
            Actor_SetScale(&this->actor, 0.01f);
            this->textID = 0;
            this->actor.textId = 0;
            this->playbackTimer = 0;
            this->unk_2D2 = 0;
            this->unk_2D4 = 3;
            this->unk_2D5 = 3;
            this->actor.speedXZ = 0.0f;
            this->actor.velocity.y = 0.0f;
            this->actor.gravity = -1.0f;
            func_80AFE390(this);
            player = PLAYER;
            osSyncPrintf("Player_X : %f\n", player->actor.posRot.pos.x);
            osSyncPrintf("Player_Z : %f\n", player->actor.posRot.pos.z);
            osSyncPrintf("World_X  : %f\n", this->actor.posRot.pos.x);
            osSyncPrintf("World_Z  : %f\n", this->actor.posRot.pos.z);
            osSyncPrintf("Center_X : %f\n", this->center.x);
            osSyncPrintf("Center_Z : %f\n\n", this->center.z);
            break;
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/EnSkj_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFE8EC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFE968.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFE9AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFE9D4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFEAEC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFEC3C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFEDF8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFEE84.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFEECC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFEF5C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFEF98.s")

void func_80AFF038(EnSkj* this) {
    this->unk_2C8 = 0xAAA;
    this->unk_2EC = 200.0f;
    func_80AFE2B0(this, 2); // TODO: animation enum
    func_80AFE338(this, 2); // TODO: action enum
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFF07C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFF16C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFF19C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFF1F0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFF220.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFF2A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFF2E0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFF334.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFF380.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFF3D0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFF424.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFF5F0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFF620.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFF660.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFF688.s")

void func_80AFF7A0(EnSkj* this) {
    this->textID = 0x10BC;
    func_80AFE2B0(this, 9);
    func_80AFE338(this, 10);
}


#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFF7D8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFF9E8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFFA0C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFFCE0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFFD14.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFFD64.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFFD84.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFFE24.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFFE44.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFFEB4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFFED4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFFF38.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFFF58.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80AFFFBC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80B00018.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80B00068.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80B00098.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80B000EC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80B00130.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80B001CC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80B00210.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80B002A4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80B002D8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80B00370.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80B00390.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80B003F4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80B0042C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80B0047C.s")

void func_80B0049C(EnSkj *this, GlobalContext *globalCtx) {
    u8 state;
    Player* player;
    
    if (((state = func_8010BDBC(&globalCtx->msgCtx)), player = PLAYER,  state == 6) && (func_80106BC8(globalCtx))){
        func_80AFF7A0(this);
        player->stateFlags2 |= 0x800000;
        player->unk_6A8 = (Actor*)D_80B01640.skullkid;
    }
}

void func_80B00514(EnSkj* this) {
    this->actor.flags &= ~1;
    func_80AFE2B0(this, 9);  // TODO: animation enum
    func_80AFE338(this, 25); // TODO: action enum
}

void func_80B00554(EnSkj *this, GlobalContext *globalCtx) {
    if (this->unk_2D7 != 0) {
        this->actor.flags |= 1;
        func_80AFE338(this, 26);
    }
}

s32 func_80B00590(EnSkj* this) {
    s32 paramDecr = this->actor.params - 1;

    if (D_80B01648[paramDecr].unk0 == 2) {
        func_80B006F8(this);
        return 1;
    }
    return 0;
}


#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80B005E0.s")

//EnSkj_Appear
void func_80B00610(EnSkj *this) {
    if (this->alpha != 0xFF) {
        this->alpha += 0x14;
        if (this->alpha >= 0x100) {
            this->alpha = 0xFF;
        }
    }
}

void func_80B00638(EnSkj *this, GlobalContext *globalCtx) {
    func_80B00610(this);
    if ((func_80B00590(this) == 0) && (this->unk_2D8 != 0)) {
        func_80B00680(this);
    }
}

void func_80B00680(EnSkj* this) {
    func_80AFE2B0(this, 2);
    func_80AFE338(this, 27);
}


#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80B006B0.s")

void func_80B006F8(EnSkj* this) {
    this->actor.velocity.y = 8.0f;
    this->actor.speedXZ = -8.0f;
    func_80AFE2B0(this, 0);
    func_80AFE338(this, 28); // come back to this
}


#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80B00740.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/EnSkj_Update.s")

void func_80B00964(Actor* thisx, GlobalContext* globalCtx) {
    EnSkj* this = THIS;

    D_80B01EA0 = func_8002F194(&this->actor, globalCtx);
    if (BREG(0) != 0) {
        DebugDisplay_AddObject(this->actor.posRot.pos.x, this->actor.posRot.pos.y, this->actor.posRot.pos.z,
                               this->actor.posRot.rot.x, this->actor.posRot.rot.y, this->actor.posRot.rot.z, 1.0f, 1.0f,
                               1.0f, 255, 0, 0, 255, 4, globalCtx->state.gfxCtx);
    }
}

// EnSkj_TurnPlayer
void func_80B00A08(EnSkj* this, Player* player) {
    Math_SmoothScaleMaxMinS(&player->actor.shape.rot.y, this->actor.posRot.rot.y, 5, 2000, 0);
    player->actor.posRot.rot.y = player->actor.shape.rot.y;
    player->currentYaw = player->actor.shape.rot.y;
}

// EnSkj_StartWaitingForOcarina
void func_80B00A54(EnSkj* this, GlobalContext* globalCtx) {
    Player* player = PLAYER;

    if (func_80AFE8EC(player, this) != 0) {
        D_80B01648[0].skullkid->unk_2D7 = 1;
        D_80B01648[1].skullkid->unk_2D7 = 1;
        if (player->stateFlags2 & 0x1000000) {
            player->stateFlags2 |= 0x2000000;
            func_800F5BF0(4);
            func_80B00A08(this, player);
            player->unk_6A8 = this;
            func_8010B680(globalCtx, 0x10BE, this);
            this->actionFunc = func_80B00BB0;
        } else {
            this->actionFunc = func_80B00B0C;
        }
    }
}

// EnSkj_WaitForOcarina
void func_80B00B0C(EnSkj* this, GlobalContext* globalCtx) {
    Player* player = PLAYER;

    if (player->stateFlags2 & 0x1000000) {
        player->stateFlags2 |= 0x2000000;
        func_800F5BF0(4);
        func_80B00A08(this, player);
        player->unk_6A8 = this;
        func_8010B680(globalCtx, 0x10BE, this);
        this->actionFunc = func_80B00BB0;
    } else {
        if (func_80AFE8EC(player, this) != 0) {
            player->stateFlags2 |= 0x800000;
        }
    }
}

// EnSkj_StartMinigame
void func_80B00BB0(EnSkj* this, GlobalContext* globalCtx) {
    u8 dialogState = func_8010BDBC(&globalCtx->msgCtx);
    Player* player = PLAYER;

    func_80B00A08(this, player);

    if (dialogState == 2) {
        func_8010BD58(globalCtx, 0x2E); // play song?
        if (D_80B01648[0].skullkid != NULL) {
            D_80B01648[0].skullkid->unk_2D8 = 1;
        }
        this->playbackTimer = 160;
        this->actionFunc = func_80B00C38;
    }
}

// EnSkj_WaitForPlayback
void func_80B00C38(EnSkj* this, GlobalContext* globalCtx) {
    Player* player = PLAYER;

    func_80B00A08(this, player);
    if (globalCtx->msgCtx.unk_E3EE == 3) { // failed the game
        func_80106CCC(globalCtx);
        globalCtx->msgCtx.unk_E3EE = 4;
        player->unk_6A8 = this;
        func_8002F2CC(&this->actor, globalCtx, 26.0f);
        this->textID = 0x102D;
        this->actionFunc = func_80B00EA4;
    } else if (globalCtx->msgCtx.unk_E3EE == 0xF) { // completed the game
        func_80078884(NA_SE_SY_CORRECT_CHIME);
        func_80106CCC(globalCtx);
        globalCtx->msgCtx.unk_E3EE = 4;
        player->unk_6A8 = this;
        func_8002F2CC(&this->actor, globalCtx, 26.0f);
        this->textID = 0x10BF;
        this->actionFunc = func_80B01004;
    } else { // playing the game
        switch (globalCtx->msgCtx.msgMode) {
            case 0x2B:
                if (D_80B01648[0].skullkid != NULL) {
                    D_80B01648[0].skullkid->unk_2D8 = 0;
                }
                if (func_800F8FF4(NA_SE_SY_METRONOME) == 0) {
                    if (D_80B01648[1].skullkid != NULL) {
                        D_80B01648[1].skullkid->unk_2D8 = 1;
                    }
                    func_80106AA8(globalCtx);
                }
                break;
            case 0x2D:
                if (D_80B01648[1].skullkid != NULL) {
                    D_80B01648[1].skullkid->unk_2D8 = 0;
                }
                if (func_800F8FF4(NA_SE_SY_METRONOME) == 0) {
                    func_80106AA8(globalCtx);
                    this->playbackTimer = 160;
                }
                break;
            case 0x2E:
                if (this->playbackTimer != 0) {
                    this->playbackTimer--;
                } else { // took too long, game failed
                    func_80078884(NA_SE_SY_OCARINA_ERROR);
                    func_80106CCC(globalCtx);
                    globalCtx->msgCtx.unk_E3EE = 4;
                    player->unk_6A8 = this;
                    func_8002F2CC(&this->actor, globalCtx, 26.0f);
                    this->textID = 0x102D;
                    this->actionFunc = func_80B00EA4;
                }
                break;
            case 0x30:
                if (func_800F8FF4(NA_SE_SY_METRONOME) == 0) {
                    if (D_80B01648[1].skullkid != NULL) {
                        D_80B01648[1].skullkid->unk_2D8 = 1;
                    }
                    this->playbackTimer = 160;
                    func_800ED858(6); // related instrument sound (flute?)
                    func_800ED93C(0xE, 1);
                    globalCtx->msgCtx.msgMode = 0x2A;
                    globalCtx->msgCtx.unk_E3E7 = 2;
                }
                break;
            default:
                break;
        }
    }
}

void func_80B00EA4(EnSkj* this, GlobalContext* globalCtx) {
    if (D_80B01EA0) {
        this->actionFunc = func_80B00EE0;
    } else {
        func_8002F2CC(&this->actor, globalCtx, 26.0f);
    }
}

// EnSkj_WaitFor...
void func_80B00EE0(EnSkj* this, GlobalContext* globalCtx) {
    // if dialog state is 6 and text box is advanced
    if (func_8010BDBC(&globalCtx->msgCtx) == 6 && func_80106BC8(globalCtx)) {
        func_80B00F2C(this, globalCtx);
    }
}

// EnSkj_OfferNextRound
void func_80B00F2C(EnSkj* this, GlobalContext* globalCtx) {
    func_8010B720(globalCtx, 0x102E); // wanna play again? yes/no
    this->actionFunc = func_80B00F64;
}

// EnSkj_WaitForOfferResponse
void func_80B00F64(EnSkj* this, GlobalContext* globalCtx) {
    Player* player;

    // if dialog state is 4 and text box is advanced
    if (func_8010BDBC(&globalCtx->msgCtx) == 4 && func_80106BC8(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case 0: // yes
                player = PLAYER;
                player->unk_692 |= 0x20; // makes player take ocarina out right away after closing box
                this->actionFunc = func_80B00A54;
                break;
            case 1: // no
                this->actionFunc = func_80B011CC;
                break;
        }
    }
}

void func_80B01004(EnSkj* this, GlobalContext* globalCtx) {
    if (D_80B01EA0) {
        this->actionFunc = func_80B01040;
    } else {
        func_8002F2CC(&this->actor, globalCtx, 26.0f);
    }
}

// EnSkj_WaitToGiveReward
void func_80B01040(EnSkj* this, GlobalContext* globalCtx) {
    // if dialog state is 6 and text box is advanced
    if ((func_8010BDBC(&globalCtx->msgCtx) == 6) && (func_80106BC8(globalCtx))) {
        func_8002F434(&this->actor, globalCtx, sMinigameRewards[gSaveContext.ocarinaGameReward], 26.0f, 26.0f);
        this->actionFunc = func_80B010C4;
    }
}

// EnSkj_GiveMinigameReward
void func_80B010C4(EnSkj *this, GlobalContext *globalCtx) {
    if (func_8002F410(&this->actor, globalCtx)) {
        this->actor.attachedA = NULL;
        this->actionFunc = func_80B01134;
    } else {
         func_8002F434(&this->actor, globalCtx, sMinigameRewards[gSaveContext.ocarinaGameReward], 26.0f, 26.0f);
    }
}


// EnSkj_FinishRound
void func_80B01134(EnSkj *this, GlobalContext *globalCtx) {
    s32 ocarinaGameReward;

    // if dialog state is 6 and text box is advanced
    if ((func_8010BDBC(&globalCtx->msgCtx) == 6) && (func_80106BC8(globalCtx))) {

        ocarinaGameReward = gSaveContext.ocarinaGameReward;

        if (gSaveContext.ocarinaGameReward < 3) {
            gSaveContext.ocarinaGameReward++;
        }
        
        if (ocarinaGameReward == 2) {
            gSaveContext.itemGetInf[1] |= 0x80;
            this->actionFunc = func_80B011CC;
        } else {
            func_80B00F2C(this, globalCtx);
        }
        
    }
}

// EnSkj_DissapearFromMinigame
void func_80B011CC(EnSkj* this, GlobalContext* globalCtx) {
    if (D_80B01648[0].skullkid != NULL) {
        D_80B01648[0].unk0 = 2;
    }
    if (D_80B01648[1].skullkid != NULL) {
        D_80B01648[1].unk0 = 2;
    }
    if ((D_80B01648[0].unk0 == 2) && (D_80B01648[1].unk0 == 2)) {
        func_800F5C2C(); // bgm related
        Actor_Kill(&this->actor);
    }
}

// update for what
void func_80B01244(Actor* thisx, GlobalContext* globalCtx) {
    EnSkj* this = THIS;

    D_80B01EA0 = func_8002F194(&this->actor, globalCtx);
    this->timer++;
    this->actor.posRot2.pos.x = 1230.0f;
    this->actor.posRot2.pos.y = -90.0f;
    this->actor.posRot2.pos.z = 450.0f;
    if (BREG(0) != 0) {
        DebugDisplay_AddObject(this->actor.posRot.pos.x, this->actor.posRot.pos.y, this->actor.posRot.pos.z,
                               this->actor.posRot.rot.x, this->actor.posRot.rot.y, this->actor.posRot.rot.z, 1.0f, 1.0f,
                               1.0f, 255, 0, 0, 255, 4, globalCtx->state.gfxCtx);
    }
    this->actionFunc(this, globalCtx);
    this->actor.textId = this->textID;
    this->actor.xzDistFromLink = 50.0;
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80B01348.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80B01360.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80B01474.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/func_80B014E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Skj/EnSkj_Draw.s")
