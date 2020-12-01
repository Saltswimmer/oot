#include "z_en_ganon_mant.h"
#include "overlays/actors/ovl_Boss_Ganon/z_boss_ganon.h"

#define FLAGS 0x00000030

#define THIS ((EnGanonMant*)thisx)

void EnGanonMant_Init(Actor* thisx, GlobalContext* globalCtx);
void EnGanonMant_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnGanonMant_Update(Actor* thisx, GlobalContext* globalCtx);
void EnGanonMant_Draw(Actor* thisx, GlobalContext* globalCtx);
/*
const ActorInit En_Ganon_Mant_InitVars = {
    ACTOR_EN_GANON_MANT,
    ACTORTYPE_BOSS,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnGanonMant),
    (ActorFunc)EnGanonMant_Init,
    (ActorFunc)EnGanonMant_Destroy,
    (ActorFunc)EnGanonMant_Update,
    (ActorFunc)EnGanonMant_Draw,
};
*/

typedef struct {
    /* 0x00 */ s16* arr;
    /* 0x04 */ s16 count;
} UnkCapeStruct;

extern UnkCapeStruct D_80A24D64[];
extern s16 D_80A24F78[];

/*
s16 D_80A24D20[] = { 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 };
s16 D_80A24D34[] = { 0, 0, 0, 0, 1, 1, 2, 2, 2, 1, 1, 0, 0, 0, 0 };
s16 D_80A24D54[] = { 0, 0, 0, 0, 0, 0, 0 };

UnkCapeStruct D_80A24D64[] = {
    { D_80A24D20, 10 },
    { D_80A24D20, 10 },
    { D_80A24D34, 15 },
    { D_80A24D54, 7 },
};
*/

void EnGanonMant_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnGanonMant* this = THIS;

    this->actor.flags &= ~1;
}

void EnGanonMant_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

#ifdef NON_MATCHING
// ordering and and float stuff in the nested loops
// I started this function to reverse the unk_14C struct, apologies for not finishing it
void func_80A23D84(EnGanonMant* this) {
    f32 rand32;
    f32 rand64;
    f32 rand2pi;
    f32 sin;
    f32 cos;
    UnkCapeStruct* entry;
    s16 i;
    s16 j;
    s16 k;
    s16 index;

    rand32 = Math_Rand_ZeroFloat(32.0f);
    rand64 = Math_Rand_ZeroFloat(64.0f);
    rand2pi = Math_Rand_ZeroFloat(2 * M_PI);

    sin = sinf(rand2pi);
    cos = cosf(rand2pi);

    entry = &D_80A24D64[(s16)Math_Rand_ZeroFloat(3.99f)];

    for (i = 0; i < entry->count; i++) {
        if ((rand32 >= 0.0f) && (rand32 < 32.0f) && (rand64 >= 0.0f) && (rand64 < 64.0f)) {
            for (j = 0; j < entry->arr[i]; j++) {
                for (k = 0; k < entry->arr[i]; k++) {
                    // this definitley needs to be reordered
                    index = ((s16)rand32 + ((s16)rand64 * 32)) + j + (k * 32);

                    if (index < 0x800) {
                        D_80A24F78[index] = 0;
                    }
                }
            }
        }
        rand32 += sin;
        rand64 += cos;
    }

    for (i = 0; i < 4; i++) {
        this->unk_14C[(s16)Math_Rand_ZeroFloat(11.9f)].unk_1B0[(s16)Math_Rand_ZeroFloat(11.9f)] = 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ganon_Mant/func_80A23D84.s")
#endif

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ganon_Mant/func_80A23FE0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ganon_Mant/func_80A245A4.s")

void EnGanonMant_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnGanonMant* this = THIS;
    BossGanon* ganondorf = (BossGanon*)this->actor.parent;

    this->unk_1705 = 1;
    this->unk_1706++;

    if (this->unk_16C0 == 0.0f) {

    } else {
        this->unk_16C0 -= 1.0f;
    }

    if (this->unk_16BC != 0.0f) {
        this->unk_16BC -= 1.0f;
    }

    if (this->unk_16C4 != 0.0f) {
        this->unk_16C4 -= 1.0f;
    }

    this->actor.shape.rot.y = ganondorf->actor.shape.rot.y;

    if (this->unk_1704 != 0) {
        this->unk_1704--;
        func_80A23D84(this);
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ganon_Mant/func_80A24884.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ganon_Mant/EnGanonMant_Draw.s")
