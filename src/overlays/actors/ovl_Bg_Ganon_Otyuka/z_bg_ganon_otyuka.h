#ifndef _Z_BG_GANON_OTYUKA_H_
#define _Z_BG_GANON_OTYUKA_H_

#include "ultra64.h"
#include "global.h"

struct BgGanonOtyuka;

typedef void (*BgGanonOtyukaActionFunc)(struct BgGanonOtyuka*, GlobalContext*);

typedef struct BgGanonOtyuka {
    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ BgGanonOtyukaActionFunc actionFunc;
    /* 0x0168 */ char unk_168[0x6];
    /* 0x016E */ u8 unk_16E;
    /* 0x016F */ char unk_16F[0x1D];
} BgGanonOtyuka; // size = 0x018C

extern const ActorInit Bg_Ganon_Otyuka_InitVars;

#endif
