glabel func_800E2BE0
/* B59D80 800E2BE0 3C028017 */  lui   $v0, %hi(gAudioContext) # $v0, 0x8017
/* B59D84 800E2BE4 2442F180 */  addiu $v0, %lo(gAudioContext) # addiu $v0, $v0, -0xe80
/* B59D88 800E2BE8 8C4E2984 */  lw    $t6, 0x2984($v0)
/* B59D8C 800E2BEC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* B59D90 800E2BF0 AFB00018 */  sw    $s0, 0x18($sp)
/* B59D94 800E2BF4 2DC10011 */  sltiu $at, $t6, 0x11
/* B59D98 800E2BF8 00808025 */  move  $s0, $a0
/* B59D9C 800E2BFC AFBF001C */  sw    $ra, 0x1c($sp)
/* B59DA0 800E2C00 14200003 */  bnez  $at, .L800E2C10
/* B59DA4 800E2C04 AFA50024 */   sw    $a1, 0x24($sp)
/* B59DA8 800E2C08 10000026 */  b     .L800E2CA4
/* B59DAC 800E2C0C 2402FFFF */   li    $v0, -1
.L800E2C10:
/* B59DB0 800E2C10 8FA3003C */  lw    $v1, 0x3c($sp)
/* B59DB4 800E2C14 24010002 */  li    $at, 2
/* B59DB8 800E2C18 8FB80024 */  lw    $t8, 0x24($sp)
/* B59DBC 800E2C1C 10610005 */  beq   $v1, $at, .L800E2C34
/* B59DC0 800E2C20 24010003 */   li    $at, 3
/* B59DC4 800E2C24 10610005 */  beq   $v1, $at, .L800E2C3C
/* B59DC8 800E2C28 00000000 */   nop
/* B59DCC 800E2C2C 1000001D */  b     .L800E2CA4
/* B59DD0 800E2C30 00001025 */   move  $v0, $zero
.L800E2C34:
/* B59DD4 800E2C34 10000005 */  b     .L800E2C4C
/* B59DD8 800E2C38 8C441E18 */   lw    $a0, 0x1e18($v0)
.L800E2C3C:
/* B59DDC 800E2C3C 10000003 */  b     .L800E2C4C
/* B59DE0 800E2C40 8C441E1C */   lw    $a0, 0x1e1c($v0)
/* B59DE4 800E2C44 10000017 */  b     .L800E2CA4
/* B59DE8 800E2C48 00001025 */   move  $v0, $zero
.L800E2C4C:
/* B59DEC 800E2C4C 8FA20034 */  lw    $v0, 0x34($sp)
/* B59DF0 800E2C50 2401FFF0 */  li    $at, -16
/* B59DF4 800E2C54 304F000F */  andi  $t7, $v0, 0xf
/* B59DF8 800E2C58 51E00004 */  beql  $t7, $zero, .L800E2C6C
/* B59DFC 800E2C5C A2180002 */   sb    $t8, 2($s0)
/* B59E00 800E2C60 2442000F */  addiu $v0, $v0, 0xf
/* B59E04 800E2C64 00411024 */  and   $v0, $v0, $at
/* B59E08 800E2C68 A2180002 */  sb    $t8, 2($s0)
.L800E2C6C:
/* B59E0C 800E2C6C 8FB90038 */  lw    $t9, 0x38($sp)
/* B59E10 800E2C70 24090002 */  li    $t1, 2
/* B59E14 800E2C74 02002825 */  move  $a1, $s0
/* B59E18 800E2C78 AE190004 */  sw    $t9, 4($s0)
/* B59E1C 800E2C7C 8FA80030 */  lw    $t0, 0x30($sp)
/* B59E20 800E2C80 AE07000C */  sw    $a3, 0xc($s0)
/* B59E24 800E2C84 AE020010 */  sw    $v0, 0x10($s0)
/* B59E28 800E2C88 AE080008 */  sw    $t0, 8($s0)
/* B59E2C 800E2C8C AC890014 */  sw    $t1, 0x14($a0)
/* B59E30 800E2C90 3C198013 */  lui   $t9, %hi(D_801304D0) # $t9, 0x8013
/* B59E34 800E2C94 8F3904D0 */  lw    $t9, %lo(D_801304D0)($t9)
/* B59E38 800E2C98 0320F809 */  jalr  $t9
/* B59E3C 800E2C9C 00000000 */  nop
/* B59E40 800E2CA0 00001025 */  move  $v0, $zero
.L800E2CA4:
/* B59E44 800E2CA4 8FBF001C */  lw    $ra, 0x1c($sp)
/* B59E48 800E2CA8 8FB00018 */  lw    $s0, 0x18($sp)
/* B59E4C 800E2CAC 27BD0020 */  addiu $sp, $sp, 0x20
/* B59E50 800E2CB0 03E00008 */  jr    $ra
/* B59E54 800E2CB4 00000000 */   nop

