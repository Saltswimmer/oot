#ifndef _Z64ENVIRONMENT_H_
#define _Z64ENVIRONMENT_H_

#include "z64math.h"
#include "z64light.h"
#include "z64dma.h"

typedef enum {
    /* 0 */ LIGHTNING_MODE_OFF, // no lightning
    /* 1 */ LIGHTNING_MODE_ON, // request ligtning strikes at random intervals
    /* 2 */ LIGHTNING_MODE_LAST // request one lightning strike before turning off
} LightningMode;

typedef enum {
    /* 0 */ LIGHTNING_STRIKE_WAIT, // wait between lightning strikes. request bolts when timer hits 0
    /* 1 */ LIGHTNING_STRIKE_START, // fade in the flash. note: bolts are requested in the previous state
    /* 2 */ LIGHTNING_STRIKE_END // fade out the flash and go back to wait
} LightningStrikeState;

typedef enum {
    /*  0 */ SKYBOX_DMA_INACTIVE,
    /*  1 */ SKYBOX_DMA_BG1_START,
    /*  2 */ SKYBOX_DMA_BG1_DONE,
    /*  3 */ SKYBOX_DMA_CLOUDS1_START,
    /* 11 */ SKYBOX_DMA_BG2_START = 11,
    /* 12 */ SKYBOX_DMA_BG2_DONE,
    /* 13 */ SKYBOX_DMA_CLOUDS2_START
} SkyboxDmaState;

typedef struct {
    /* 0x00 */ u8 state;
    /* 0x01 */ u8 flashRed;
    /* 0x02 */ u8 flashGreen;
    /* 0x03 */ u8 flashBlue;
    /* 0x04 */ u8 flashAlphaTarget;
    /* 0x08 */ f32 delayTimer;
} LightningStrike;

// describes what skybox files and blending modes to use depending on time of day
typedef struct {
    /* 0x00 */ u16 startTime;
    /* 0x02 */ u16 endTime;
    /* 0x04 */ u8 blend; // if true, blent between.. skyboxes? palletes?
    /* 0x05 */ u8 skybox1Index; // whats the difference between _pal and non _pal files?
    /* 0x06 */ u8 skybox2Index;
} struct_8011FC1C; // size = 0x8

// 1.0: 801D8EC4
// dbg: 80222A44
typedef struct {
    /* 0x00 */ char unk_00[0x02];
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ Vec3f sunPos; // moon position can be found by negating the sun position
    /* 0x10 */ u8 skybox1Index;
    /* 0x11 */ u8 skybox2Index;
    /* 0x12 */ char unk_12[0x01];
    /* 0x13 */ u8 skyboxBlend;
    /* 0x14 */ char unk_14[0x01];
    /* 0x15 */ u8 skyboxDisabled;
    /* 0x16 */ u8 sunMoonDisabled;
    /* 0x17 */ u8 unk_17; // currentWeatherMode for skybox? (prev called gloomySky)
    /* 0x18 */ u8 unk_18; // nextWeatherMode for skybox?
    /* 0x19 */ u8 unk_19;
    /* 0x1A */ u16 unk_1A;
    /* 0x1C */ char unk_1C[0x02];
    /* 0x1E */ u8 unk_1E;
    /* 0x1F */ u8 unk_1F;
    /* 0x20 */ u8 unk_20;
    /* 0x21 */ u8 unk_21;
    /* 0x22 */ u16 unk_22;
    /* 0x24 */ u16 unk_24;
    /* 0x26 */ char unk_26[0x02];
    /* 0x28 */ LightInfo unk_28;
    /* 0x36 */ LightInfo unk_36;
    /* 0x44 */ s8 skyboxDmaState;
    /* 0x45 */ char unk_45[0x3];
    /* 0x48 */ DmaRequest dmaRequest;
    /* 0x68 */ OSMesgQueue loadQueue;
    /* 0x80 */ OSMesg loadMsg;
    /* 0x84 */ f32 unk_84;
    /* 0x88 */ f32 unk_88;
    /* 0x8C */ s16 unk_8C[3][3];
    /* 0x9E */ s16 unk_9E;
    /* 0xA0 */ s16 unk_A0;
    /* 0xA2 */ char unk_A2[0x06];
    /* 0xA8 */ Vec3s windDirection;
    /* 0xB0 */ f32 windSpeed;
    /* 0xB4 */ u8 nbLightSettings;
    /* 0xB8 */ UNK_PTR lightSettingsList;
    /* 0xBC */ u8 unk_BC;
    /* 0xBD */ u8 unk_BD;
    /* 0xBE */ u8 unk_BE;
    /* 0xBF */ u8 unk_BF;
    /* 0xC0 */ u8 unk_C0[3][3];
    /* 0xC9 */ u8 unk_C9[3][3];
    /* 0xD2 */ s16 unk_D2;
    /* 0xD4 */ s16 unk_D4;
    /* 0xD6 */ u16 unk_D6;
    /* 0xD8 */ f32 unk_D8;
    /* 0xDC */ u8 unk_DC;
    /* 0xDD */ u8 gloomySkyEvent;
    /* 0xDE */ u8 unk_DE;
    /* 0xDF */ u8 lightningMode;
    /* 0xE0 */ u8 unk_E0;
    /* 0xE1 */ u8 unk_E1;
    /* 0xE2 */ u8 unk_E2[4]; // color
    /* 0xE6 */ u8 sandstormState;
    /* 0xE7 */ u8 sandstormPrimA;
    /* 0xE8 */ u8 sandstormEnvA;
    /* 0xE9 */ u8 unk_E9;
    /* 0xEA */ u8 unk_EA[4]; // color
    /* 0xEE */ u8 unk_EE[4];
    /* 0xF2 */ u8 unk_F2[4];
    /* 0xF6 */ char unk_F6[0x06];
} EnvironmentContext; // size = 0xFC

#endif
