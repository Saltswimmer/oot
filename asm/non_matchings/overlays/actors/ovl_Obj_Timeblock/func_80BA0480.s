glabel func_80BA0480
/* 004E0 80BA0480 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 004E4 80BA0484 00A11021 */  addu    $v0, $a1, $at              
/* 004E8 80BA0488 944E04C6 */  lhu     $t6, 0x04C6($v0)           ## 000004C6
/* 004EC 80BA048C 24010004 */  addiu   $at, $zero, 0x0004         ## $at = 00000004
/* 004F0 80BA0490 3C0F80BA */  lui     $t7, %hi(func_80BA040C)    ## $t7 = 80BA0000
/* 004F4 80BA0494 15C10002 */  bne     $t6, $at, .L80BA04A0       
/* 004F8 80BA0498 25EF040C */  addiu   $t7, $t7, %lo(func_80BA040C) ## $t7 = 80BA040C
/* 004FC 80BA049C AC8F0168 */  sw      $t7, 0x0168($a0)           ## 00000168
.L80BA04A0:
/* 00500 80BA04A0 945804C4 */  lhu     $t8, 0x04C4($v0)           ## 000004C4
/* 00504 80BA04A4 2401000A */  addiu   $at, $zero, 0x000A         ## $at = 0000000A
/* 00508 80BA04A8 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
/* 0050C 80BA04AC 17010010 */  bne     $t8, $at, .L80BA04F0       
/* 00510 80BA04B0 00000000 */  nop
/* 00514 80BA04B4 94990172 */  lhu     $t9, 0x0172($a0)           ## 00000172
/* 00518 80BA04B8 240100FE */  addiu   $at, $zero, 0x00FE         ## $at = 000000FE
/* 0051C 80BA04BC 2408006E */  addiu   $t0, $zero, 0x006E         ## $t0 = 0000006E
/* 00520 80BA04C0 57210004 */  bnel    $t9, $at, .L80BA04D4       
/* 00524 80BA04C4 8489016E */  lh      $t1, 0x016E($a0)           ## 0000016E
/* 00528 80BA04C8 10000009 */  beq     $zero, $zero, .L80BA04F0   
/* 0052C 80BA04CC A488016E */  sh      $t0, 0x016E($a0)           ## 0000016E
/* 00530 80BA04D0 8489016E */  lh      $t1, 0x016E($a0)           ## 0000016E
.L80BA04D4:
/* 00534 80BA04D4 252AFFFF */  addiu   $t2, $t1, 0xFFFF           ## $t2 = FFFFFFFF
/* 00538 80BA04D8 A48A016E */  sh      $t2, 0x016E($a0)           ## 0000016E
/* 0053C 80BA04DC 848B016E */  lh      $t3, 0x016E($a0)           ## 0000016E
/* 00540 80BA04E0 15600003 */  bne     $t3, $zero, .L80BA04F0     
/* 00544 80BA04E4 00000000 */  nop
/* 00548 80BA04E8 03E00008 */  jr      $ra                        
/* 0054C 80BA04EC 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
.L80BA04F0:
/* 00550 80BA04F0 03E00008 */  jr      $ra                        
/* 00554 80BA04F4 00000000 */  nop

