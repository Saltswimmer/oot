#ifndef _Z_BOSS_GANON_H_
#define _Z_BOSS_GANON_H_

#include "ultra64.h"
#include "global.h"

struct BossGanon;

typedef void (*BossGanonActionFunc)(struct BossGanon*, GlobalContext*);

typedef struct BossGanon {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ s32 anim2BankIndex;
    /* 0x0150 */ SkelAnime skelAnime;
    /* 0x0194 */ BossGanonActionFunc actionFunc;
    /* 0x0198 */ u8 unk_198;
    /* 0x0199 */ u8 unk_199;
    /* 0x019A */ char unk_19A[0x6];
    /* 0x01A0 */ u8 unk_1A0;
    /* 0x01A1 */ char unk_1A1[0x1];
    /* 0x01A2 */ s16 unk_1A2;
    /* 0x01A4 */ char unk_1A4[0x4];
    /* 0x01A8 */ s16 unk_1A8;
    /* 0x01AA */ char unk_1AA[0x4];
    /* 0x01AE */ s16 unk_1AE;
    /* 0x01B0 */ char unk_1B0[0x6];
    /* 0x01B6 */ s16 unk_1B6;
    /* 0x01B8 */ s16 unk_1B8;
    /* 0x01BA */ s16 unk_1BA;
    /* 0x01BC */ char unk_1BC[0x6];
    /* 0x01C2 */ s16 unk_1C2;
    /* 0x01C4 */ char unk_1C4[0x4];
    /* 0x01C8 */ f32 unk_1C8;
    /* 0x01CC */ f32 unk_1CC;
    /* 0x01D0 */ char unk_1D0[0x4];
    /* 0x01D4 */ f32 unk_1D4;
    /* 0x01D8 */ f32 unk_1D8;
    /* 0x01DC */ f32 unk_1DC;
    /* 0x01E0 */ f32 unk_1E0;
    /* 0x01E4 */ f32 unk_1E4;
    /* 0x01E8 */ f32 unk_1E8;
    /* 0x01EC */ char unk_1EC[0x10];
    /* 0x01FC */ Vec3f unk_1FC;
    /* 0x0208 */ char unk_208[0xE4];
    /* 0x02EC */ Vec3f unk_2EC[15];
    /* 0x03A0 */ char unk_3A0[0x270];
    /* 0x0610 */ ColliderCylinder collider;
    /* 0x065C */ char unk_65C[0x18];
    /* 0x0674 */ u32 csTimer;
    /* 0x0678 */ s16 introCsState;
    /* 0x067A */ s16 csCamIndex;
    /* 0x067C */ char unk_67C[0x4];
    /* 0x0680 */ Vec3f csCamEye;
    /* 0x068C */ Vec3f csCamAt;
    /* 0x0698 */ char unk_698[0xC];
    /* 0x06A4 */ Vec3f csCamEyeMaxStep;
    /* 0x06B0 */ Vec3f csCamAtMaxStep;
    /* 0x06BC */ Vec3f csCamTargetEye;
    /* 0x06C8 */ char unk_6C8[0xC];
    /* 0x06D4 */ Vec3f csCamTargetAt;
    /* 0x06E0 */ char unk_6E0[0xC];
    /* 0x06EC */ f32 csCamMaxStepScale;
    /* 0x06F0 */ f32 csCamMovementScale;
    /* 0x06F4 */ f32 csCamFov;
    /* 0x06F8 */ char unk_6F8[0xC];
    /* 0x0704 */ f32 unk_704;
    /* 0x0708 */ char unk_708[0x10];
    /* 0x0718 */ s16 organAlpha;
    /* 0x071A */ s8 unk_71A;
} BossGanon; // size = 0x71C

extern const ActorInit Boss_Ganon_InitVars;

#endif
