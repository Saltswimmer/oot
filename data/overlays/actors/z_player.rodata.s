.include "macro.inc"

 # assembler directives
 .set noat      # allow manual use of $at
 .set noreorder # don't insert nops after branches
 .set gp=64     # allow use of 64-bit general purposee registers

.section .rodata

glabel D_80855240
    .asciz "../z_player.c"
    .balign 4

glabel D_80855250
    .asciz "size = %x\n"
    .balign 4

glabel D_8085525C
    .asciz "size <= 1024 * 8"
    .balign 4

glabel D_80855270
    .asciz "../z_player.c"
    .balign 4

glabel D_80855280
    .asciz "../z_player.c"
    .balign 4

glabel D_80855290
    .asciz "../z_player.c"
    .balign 4

glabel D_808552A0
    .asciz "../z_player.c"
    .balign 4

glabel D_808552B0
    .asciz "../z_player.c"
    .balign 4

glabel D_808552C0
    .asciz "../z_player.c"
    .balign 4

glabel D_808552D0
    .asciz "../z_player.c"
    .balign 4

glabel D_808552E0
    .asciz "../z_player.c"
    .balign 4

glabel D_808552F0
    .asciz "../z_player.c"
    .balign 4

glabel D_80855300
    .asciz "../z_player.c"
    .balign 4

glabel D_80855310
    .asciz "../z_player.c"
    .balign 4

glabel D_80855320
    .asciz "DEBUG MODE"
    .balign 4

glabel D_8085532C
    .asciz "TOOL MODE=%d\n"
    .balign 4

glabel D_8085533C
    .asciz "DEMO MODE=%d\n"
    .balign 4

glabel D_8085534C
 .word 0x362A9004
glabel D_80855350
 .word 0x3F23D70A
glabel D_80855354
 .word 0x3F2AAAAB
glabel D_80855358
 .word 0x3F2AAAAB
glabel D_8085535C
 .word 0x3F99999A
glabel D_80855360
 .word 0xBF99999A
glabel D_80855364
 .word 0x3F4CCCCD
glabel D_80855368
 .word 0x3F19999A
glabel D_8085536C
 .word 0x3C03126F
glabel D_80855370
 .word 0x3E0F5C29
glabel D_80855374
 .word 0x38000100
glabel D_80855378
 .word 0x3DA3D70A
glabel D_8085537C
 .word 0x3DCCCCCD
glabel D_80855380
 .word 0x3DCCCCCD
glabel D_80855384
 .word 0x38000100
glabel D_80855388
 .word 0x38000100
glabel D_8085538C
 .word 0x40B9999A
glabel D_80855390
 .word 0x44A28000
glabel D_80855394
 .word 0x3DCCCCCD
glabel D_80855398
 .word 0x44A28000
glabel D_8085539C
 .word 0x3E99999A
glabel D_808553A0
 .word 0x469C4000
glabel D_808553A4
 .word 0x3CA3D70A
glabel D_808553A8
 .word 0x3B83126F
glabel D_808553AC
 .word 0x3E4CCCCD
glabel D_808553B0
 .word 0x3E051EB8
glabel D_808553B4
 .word 0x3DCCCCCD
glabel D_808553B8
 .word 0x38000100
glabel D_808553BC
 .word 0x3F99999A
glabel D_808553C0
 .word 0x3C75C28F
glabel D_808553C4
 .word 0x41EB7972
glabel D_808553C8
 .word 0x41EB7972
glabel D_808553CC
 .word 0x3F8CCCCD
glabel D_808553D0
 .word 0x38000100
glabel D_808553D4
 .word 0x38000100
glabel D_808553D8
 .word 0x402E0000, 0x07800000
glabel D_808553E0
 .word 0x402E0000, 0x07800000
glabel D_808553E8
 .word 0x38000100
glabel D_808553EC
 .word 0x38000100
glabel D_808553F0
 .word 0x38000100
glabel D_808553F4
 .word 0xBECCCCCD
glabel D_808553F8
 .word 0x40D9999A
glabel D_808553FC
 .word 0x3E99999A
glabel D_80855400
 .word 0x3E99999A
glabel D_80855404
 .word 0x3DCCCCCD
glabel D_80855408
 .word 0x409CCCCD
glabel D_8085540C
 .word 0x3F2AAAAB
glabel D_80855410
 .word 0x409CCCCD
glabel D_80855414
 .word 0x3ECCCCCD
glabel D_80855418
 .word 0x3DCCCCCD
glabel D_8085541C
 .word 0x3F99999A
glabel D_80855420
 .word 0x3F0D3DCB
glabel D_80855424
 .word 0x409CCCCD
glabel D_80855428
 .word 0x3DCCCCCD
glabel D_8085542C
 .word 0x3F0D3DCB
glabel D_80855430
 .word 0x40666666
glabel D_80855434
 .word 0x3F666666
glabel D_80855438
 .word 0x3DCCCCCD
glabel D_8085543C
 .word 0x462AA800
glabel D_80855440
 .word 0x3A1D4952
glabel D_80855444
 .word 0x3F99999A
glabel D_80855448
 .word 0x3F308D3E
glabel D_8085544C
 .word 0x3DCCCCCD
glabel D_80855450
 .word 0xBF99999A
glabel D_80855454
 .word 0xBF99999A
glabel D_80855458
 .word 0x3F59999A
glabel D_8085545C
 .word 0x3DCCCCCD
glabel D_80855460
 .word 0x3F39611A
glabel D_80855464
 .word 0x3E4CCCCD
glabel D_80855468
 .word 0x3DCCCCCD
glabel D_8085546C
 .word 0x3AC49BA6
glabel D_80855470
 .word 0x3F39611A
glabel D_80855474
 .word 0x3E4CCCCD
glabel D_80855478
 .word 0x3DCCCCCD
glabel D_8085547C
 .word 0x3DAE147B
glabel D_80855480
 .word 0x3D9374BC
glabel D_80855484
 .word 0x3DCCCCCD
glabel D_80855488
 .word 0x38A7C5AC
glabel D_8085548C
 .word 0x3DCCCCCD
glabel D_80855490
 .word 0x38000100
glabel D_80855494
 .word 0x43C7FAE2
glabel D_80855498
 .word 0x43C7FAE2
glabel D_8085549C
 .word 0x38000100
glabel D_808554A0
 .word 0x38000100
glabel D_808554A4
 .word 0x38000100
glabel D_808554A8
 .word 0x418F3333
glabel D_808554AC
 .word 0x3ECCCCCD
glabel D_808554B0
 .word 0x3E4CCCCD
glabel D_808554B4
 .word 0x3E4CCCCC
glabel D_808554B8
 .word 0x3C23D70A
glabel D_808554BC
 .word 0x3CA3D70A
glabel D_808554C0
 .word 0x3C23D70A
glabel D_808554C4
 .word 0x48435000
glabel D_808554C8
 .word 0x4A742400
glabel D_808554CC
 .word 0x3DCCCCCD
glabel D_808554D0
 .word 0x7F7FFFFF
glabel D_808554D4
 .word 0x7F7FFFFF
glabel D_808554D8
 .word 0x3F4CCCCD
glabel D_808554DC
 .word 0xC4966000
glabel D_808554E0
 .word 0xC4966000
glabel D_808554E4
 .word 0x3DE38E39
glabel D_808554E8
 .word 0x40490FDB
glabel D_808554EC
 .word 0x3F8CCCCD
glabel D_808554F0
 .word 0x3F733333
glabel D_808554F4
 .word 0x44BB8000
glabel D_808554F8
 .word 0xC4BB8000
glabel D_808554FC
 .word 0x3F4CCCCD
glabel D_80855500
 .word 0x3CA3D70A
glabel D_80855504
 .word 0x3D4CCCCD
glabel D_80855508
 .word 0xBDCCCCCD
glabel D_8085550C
 .word 0xBE4CCCCD
glabel D_80855510
 .word 0xBE99999A
glabel D_80855514
 .word 0x3DCCCCCD
glabel D_80855518
 .word 0xBF4CCCCD
glabel D_8085551C
 .word 0x3F4CCCCD
glabel D_80855520
 .word 0x3D051EB8
glabel D_80855524
 .word 0x3D4CCCCD
glabel D_80855528
 .word 0x40566666
glabel D_8085552C
 .word 0x3CF5C28F
glabel D_80855530
 .word 0x3DCCCCCD
glabel D_80855534
 .word 0x3E4CCCCD
glabel D_80855538
 .word 0x3C9374BC
glabel D_8085553C
 .word 0x3C75C28F
glabel D_80855540
 .word 0x3C23D70A
glabel D_80855544
 .word 0x3E99999A
glabel D_80855548
 .word 0x3727C5AC
glabel D_8085554C
 .word 0x3DCCCCCD
