/*
 * File: z_end_title.c
 * Overlay: ovl_End_Title
 * Description: "The End" message
 */

#include "z_end_title.h"

#define FLAGS 0x00000030

#define THIS ((EndTitle*)thisx)

void EndTitle_Init(Actor* thisx, GlobalContext* globalCtx);
void EndTitle_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EndTitle_Update(Actor* thisx, GlobalContext* globalCtx);
void EndTitle_Draw(Actor* thisx, GlobalContext* globalCtx);
void func_80B65DA8(Actor* thisx, GlobalContext* globalCtx);

const ActorInit End_Title_InitVars = {
    ACTOR_END_TITLE,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EndTitle),
    (ActorFunc)EndTitle_Init,
    (ActorFunc)EndTitle_Destroy,
    (ActorFunc)EndTitle_Update,
    (ActorFunc)EndTitle_Draw,
};

#include "z_end_title_gfx.c"

void EndTitle_Init(Actor* thisx, GlobalContext* globalCtx) {
    EndTitle* this = THIS;

    this->endAlpha = 0;
    this->tlozAlpha = 0;
    this->ootAlpha = 0;
    if (this->actor.params == 1) {
        this->actor.draw = func_80B65DA8;
    }
}

void EndTitle_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EndTitle_Update(Actor* thisx, GlobalContext* globalCtx) {
}

void EndTitle_Draw(Actor* thisx, GlobalContext* globalCtx) {
    MtxF* mf;
    EndTitle* this = THIS;
    s32 frameCount = globalCtx->csCtx.frames;
    Player* player = PLAYER;

    mf = &player->mf_9E0;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_end_title.c", 403);

    // Draw the Triforce on Link's left hand
    func_80093D84(globalCtx->state.gfxCtx);
    Matrix_Mult(mf, MTXMODE_NEW);
    Matrix_Translate(0.0f, 150.0f, 170.0f, MTXMODE_APPLY);
    Matrix_Scale(0.13f, 0.13f, 0.13f, MTXMODE_APPLY);
    Matrix_RotateX(0.287621408700943f, MTXMODE_APPLY);
    Matrix_RotateY(0.0f, MTXMODE_APPLY);
    Matrix_RotateZ(0.0f, MTXMODE_APPLY);
    gSPMatrix(oGfxCtx->polyXlu.p++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_end_title.c", 412), G_MTX_LOAD);
    gSPDisplayList(oGfxCtx->polyXlu.p++, sTriforceDList);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_end_title.c", 417);

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_end_title.c", 419);

    // Draw title cards on the screen
    if ((frameCount >= 891) && (this->endAlpha < 200)) {
        this->endAlpha += 7;
    }
    if ((frameCount >= 811) && (this->tlozAlpha < 200)) {
        this->tlozAlpha += 15;
    }
    if ((frameCount >= 851) && (this->ootAlpha < 200)) {
        this->ootAlpha += 15;
    }

    oGfxCtx->overlay.p = func_80093F34(oGfxCtx->overlay.p);
    gDPSetTextureLUT(oGfxCtx->overlay.p++, G_TT_NONE);
    gDPSetEnvColor(oGfxCtx->overlay.p++, 255, 120, 30, 0);
    gDPSetRenderMode(oGfxCtx->overlay.p++, G_RM_PASS, G_RM_XLU_SURF2);
    gSPClearGeometryMode(oGfxCtx->overlay.p++,
                         G_TEXTURE_ENABLE | G_CULL_BACK | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    gDPSetCombineLERP(oGfxCtx->overlay.p++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0,
                      0, COMBINED, 0, 0, 0, COMBINED);
    gDPSetPrimColor(oGfxCtx->overlay.p++, 0x00, 0x80, 0, 0, 0, this->endAlpha);
    gDPSetTextureImage(oGfxCtx->overlay.p++, G_IM_FMT_IA, G_IM_SIZ_8b, 80, D_80B670E0);
    gDPSetTile(oGfxCtx->overlay.p++, G_IM_FMT_IA, G_IM_SIZ_8b, 11, 0x0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_NOMIRROR,
               0, 0, G_TX_NOMIRROR | G_TX_NOMIRROR, 0, 0);
    gDPLoadSync(oGfxCtx->overlay.p++);
    gDPLoadTile(oGfxCtx->overlay.p++, G_TX_LOADTILE, 0, 0, (80 << 2), (24 << 2));
    gDPPipeSync(oGfxCtx->overlay.p++);
    gDPSetTile(oGfxCtx->overlay.p++, G_IM_FMT_IA, G_IM_SIZ_8b, 11, 0x0, G_TX_RENDERTILE, 0,
               G_TX_NOMIRROR | G_TX_NOMIRROR, 0, 0, G_TX_NOMIRROR | G_TX_NOMIRROR, 0, 0);
    gDPSetTileSize(oGfxCtx->overlay.p++, G_TX_RENDERTILE, 0, 0, (80 << 2), (24 << 2));
    gSPTextureRectangle(oGfxCtx->overlay.p++, (120 << 2), (90 << 2), (200 << 2), (113 << 2), G_TX_RENDERTILE, 0, 0,
                        (32 << 5), (32 << 5));
    gDPPipeSync(oGfxCtx->overlay.p++);
    gDPSetPrimColor(oGfxCtx->overlay.p++, 0x00, 0x80, 0, 0, 0, this->tlozAlpha);
    gDPSetTextureImage(oGfxCtx->overlay.p++, G_IM_FMT_IA, G_IM_SIZ_8b, 120, D_80B65EA0);
    gDPSetTile(oGfxCtx->overlay.p++, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 0x0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_NOMIRROR,
               0, 0, G_TX_NOMIRROR | G_TX_NOMIRROR, 0, 0);
    gDPLoadSync(oGfxCtx->overlay.p++);
    gDPLoadTile(oGfxCtx->overlay.p++, G_TX_LOADTILE, 0, 0, (120 << 2), (24 << 2));
    gDPPipeSync(oGfxCtx->overlay.p++);
    gDPSetTile(oGfxCtx->overlay.p++, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 0x0, G_TX_RENDERTILE, 0,
               G_TX_NOMIRROR | G_TX_NOMIRROR, 0, 0, G_TX_NOMIRROR | G_TX_NOMIRROR, 0, 0);
    gDPSetTileSize(oGfxCtx->overlay.p++, G_TX_RENDERTILE, 0, 0, (120 << 2), (24 << 2));
    gSPTextureRectangle(oGfxCtx->overlay.p++, (100 << 2), (160 << 2), (220 << 2), (183 << 2), G_TX_RENDERTILE, 0, 0,
                        (32 << 5), (32 << 5));
    gDPPipeSync(oGfxCtx->overlay.p++);
    gDPSetPrimColor(oGfxCtx->overlay.p++, 0x00, 0x80, 0, 0, 0, this->ootAlpha);
    gDPSetTextureImage(oGfxCtx->overlay.p++, G_IM_FMT_IA, G_IM_SIZ_8b, 112, D_80B669E0);
    gDPSetTile(oGfxCtx->overlay.p++, G_IM_FMT_IA, G_IM_SIZ_8b, 15, 0x0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_NOMIRROR,
               0, 0, G_TX_NOMIRROR | G_TX_NOMIRROR, 0, 0);
    gDPLoadSync(oGfxCtx->overlay.p++);
    gDPLoadTile(oGfxCtx->overlay.p++, G_TX_LOADTILE, 0, 0, (112 << 2), (16 << 2));
    gDPPipeSync(oGfxCtx->overlay.p++);
    gDPSetTile(oGfxCtx->overlay.p++, G_IM_FMT_IA, G_IM_SIZ_8b, 15, 0x0, G_TX_RENDERTILE, 0,
               G_TX_NOMIRROR | G_TX_NOMIRROR, 0, 0, G_TX_NOMIRROR | G_TX_NOMIRROR, 0, 0);
    gDPSetTileSize(oGfxCtx->overlay.p++, G_TX_RENDERTILE, 0, 0, (112 << 2), (16 << 2));
    gSPTextureRectangle(oGfxCtx->overlay.p++, (104 << 2), (177 << 2), (216 << 2), (192 << 2), G_TX_RENDERTILE, 0, 0,
                        (32 << 5), (32 << 5));

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_end_title.c", 515);
}

/**
 * This function is never executed in normal gameplay because actor params are never set to 1
 * Produces the same results as the main draw function, except without the title cards on the end screen
 */
void func_80B65DA8(Actor* thisx, GlobalContext* globalCtx) {
    EndTitle* this = THIS;
    s32 pad;
    s32 frames = globalCtx->csCtx.frames;

    if ((frames >= 1101) && (this->endAlpha < 255)) {
        this->endAlpha += 3;
    }

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_end_title.c", 594);

    oGfxCtx->overlay.p = func_80093F34(oGfxCtx->overlay.p);
    gDPSetPrimColor(oGfxCtx->overlay.p++, 0, 0x80, 0, 0, 0, this->endAlpha);
    gSPDisplayList(oGfxCtx->overlay.p++, dList_80B69720);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_end_title.c", 600);
}
