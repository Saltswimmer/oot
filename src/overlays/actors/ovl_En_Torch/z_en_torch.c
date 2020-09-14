
#include "z_en_torch.h"
#include <alloca.h>

#define FLAGS 0x00000030

#define THIS ((EffectsDebugger*)thisx)

// replaces line 55 in spot00_room_0.c
// { ACTOR_EN_OWL, 4284, 182, 7877, 0, 0, 0, 0x004C }, //0x00000A24
// with
// { ACTOR_EN_TORCH, 100, 80, 1580, 0, 0, 0, 0 }

static Vec3f sZeroVec = { 0.0f, 0.0f, 0.0f };

static Color_RGBA8 red = { 0, 0, 0, 0 };
static Color_RGBA8 orange = { 0, 0, 0, 0 };
static Color_RGBA8 yellow = { 0, 0, 0, 0 };
static Color_RGBA8 green = { 0, 0, 0, 0 };
static Color_RGBA8 blue = { 0, 0, 0, 0 };
static Color_RGBA8 purple = { 0, 0, 0, 0 };
static Color_RGBA8 black = { 0, 0, 0, 0 };
static Color_RGBA8 white = { 0, 0, 0, 0 };
static Color_RGBA8 gray = { 0, 0, 0, 0 };
/*
char* effectNames[] = {
    "Effect_Ss_Dust",      "Effect_Ss_KiraKira",  "Effect_Ss_Bomb",       "Effect_Ss_Bomb2",
    "Effect_Ss_Blast",     "Effect_Ss_G_Spk",     "Effect_Ss_D_Fire",     "Effect_Ss_Bubble",
    "Effect_Ss_G_Ripple",  "Effect_Ss_G_Splash",  "Effect_Ss_G_Magma",    "Effect_Ss_G_Fire",
    "Effect_Ss_Lightning", "Effect_Ss_Dt_Bubble", "Effect_Ss_Hahen",      "Effect_Ss_Stick",
    "Effect_Ss_Sibuki",    "Effect_Ss_Sibuki2",   "Effect_Ss_G_Magma2",   "Effect_Ss_Stone1",
    "Effect_Ss_HitMark",   "Effect_Ss_Fhg_Flash", "Effect_Ss_K_Fire",     "Effect_Ss_Solder_Srch_Ball",
    "Effect_Ss_Kakera",    "Effect_Ss_Ice_Piece", "Effect_Ss_En_Ice",     "Effect_Ss_Fire_Tail",
    "Effect_Ss_En_Fire",   "Effect_Ss_Extra",     "Effect_Ss_Fcircle",    "Effect_Ss_Dead_Db",
    "Effect_Ss_Dead_Dd",   "Effect_Ss_Dead_Ds",   "Effect_Ss_Dead_Sound", "Effect_Ss_Ice_Smoke",
};
*/

char* effectNames[] = {
    "Effect_Ss_Blast",
};

static s32 sRate;

void EffectsDebugger_Init(Actor* thisx, GlobalContext* globalCtx);
void EffectsDebugger_Update(Actor* thisx, GlobalContext* globalCtx);

const ActorInit En_Torch_InitVars = {
    ACTOR_EN_TORCH,
    ACTORTYPE_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EffectsDebugger),
    (ActorFunc)EffectsDebugger_Init,
    NULL,
    (ActorFunc)EffectsDebugger_Update,
    NULL,
};

void EffectsDebugger_Init(Actor* thisx, GlobalContext* globalCtx) {
    EffectsDebugger* this = THIS;
    sRate = 10;
    this->effectIndex = 0;
}

void EffectsDebugger_Update(Actor* thisx, GlobalContext* globalCtx) {
    EffectsDebugger* this = THIS;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    GfxPrint* printer;

    Interface_ChangeAlpha(0);
    gSaveContext.dayTime = 0x8000;
    gSaveContext.naviTimer = 0;

    printer = alloca(sizeof(GfxPrint));
    GfxPrint_Init(printer);
    GfxPrint_Open(printer, gfxCtx->polyOpa.p);

    GfxPrint_SetPos(printer, 1, 1);
    GfxPrint_SetColor(printer, 255, 255, 255, 255);
    GfxPrint_Printf(printer, "%s", effectNames[this->effectIndex]);

    //this->func(this, globalCtx, printer);

    gfxCtx->polyOpa.p = GfxPrint_Close(printer);
    GfxPrint_Destroy(printer);
    
}
