.late_rodata
glabel D_809F6054
    .float 1.99000000954

.text
glabel func_809F4BA4
/* 018E4 809F4BA4 27BDFFD0 */  addiu   $sp, $sp, 0xFFD0           ## $sp = FFFFFFD0
/* 018E8 809F4BA8 AFB00028 */  sw      $s0, 0x0028($sp)
/* 018EC 809F4BAC 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 018F0 809F4BB0 AFBF002C */  sw      $ra, 0x002C($sp)
/* 018F4 809F4BB4 3C040600 */  lui     $a0, %hi(D_060006CC)                ## $a0 = 06000000
/* 018F8 809F4BB8 AFA50034 */  sw      $a1, 0x0034($sp)
/* 018FC 809F4BBC 0C028800 */  jal     SkelAnime_GetFrameCount

/* 01900 809F4BC0 248406CC */  addiu   $a0, $a0, %lo(D_060006CC)           ## $a0 = 060006CC
/* 01904 809F4BC4 44822000 */  mtc1    $v0, $f4                   ## $f4 = 0.00
/* 01908 809F4BC8 3C01C120 */  lui     $at, 0xC120                ## $at = C1200000
/* 0190C 809F4BCC 44819000 */  mtc1    $at, $f18                  ## $f18 = -10.00
/* 01910 809F4BD0 468021A0 */  cvt.s.w $f6, $f4
/* 01914 809F4BD4 3C050600 */  lui     $a1, %hi(D_060006CC)                ## $a1 = 06000000
/* 01918 809F4BD8 24A506CC */  addiu   $a1, $a1, %lo(D_060006CC)           ## $a1 = 060006CC
/* 0191C 809F4BDC 2604014C */  addiu   $a0, $s0, 0x014C           ## $a0 = 0000014C
/* 01920 809F4BE0 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 01924 809F4BE4 24070000 */  addiu   $a3, $zero, 0x0000         ## $a3 = 00000000
/* 01928 809F4BE8 4600320D */  trunc.w.s $f8, $f6
/* 0192C 809F4BEC 440F4000 */  mfc1    $t7, $f8
/* 01930 809F4BF0 00000000 */  nop
/* 01934 809F4BF4 A60F026E */  sh      $t7, 0x026E($s0)           ## 0000026E
/* 01938 809F4BF8 8618026E */  lh      $t8, 0x026E($s0)           ## 0000026E
/* 0193C 809F4BFC AFA00014 */  sw      $zero, 0x0014($sp)
/* 01940 809F4C00 E7B20018 */  swc1    $f18, 0x0018($sp)
/* 01944 809F4C04 44985000 */  mtc1    $t8, $f10                  ## $f10 = 0.00
/* 01948 809F4C08 00000000 */  nop
/* 0194C 809F4C0C 46805420 */  cvt.s.w $f16, $f10
/* 01950 809F4C10 0C029468 */  jal     SkelAnime_ChangeAnim

/* 01954 809F4C14 E7B00010 */  swc1    $f16, 0x0010($sp)
/* 01958 809F4C18 3C0141A0 */  lui     $at, 0x41A0                ## $at = 41A00000
/* 0195C 809F4C1C 24190001 */  addiu   $t9, $zero, 0x0001         ## $t9 = 00000001
/* 01960 809F4C20 44816000 */  mtc1    $at, $f12                  ## $f12 = 20.00
/* 01964 809F4C24 0C00CFBE */  jal     Rand_ZeroFloat

/* 01968 809F4C28 A2190218 */  sb      $t9, 0x0218($s0)           ## 00000218
/* 0196C 809F4C2C 4600010D */  trunc.w.s $f4, $f0
/* 01970 809F4C30 3C0141A0 */  lui     $at, 0x41A0                ## $at = 41A00000
/* 01974 809F4C34 44815000 */  mtc1    $at, $f10                  ## $f10 = 20.00
/* 01978 809F4C38 240EFFFF */  addiu   $t6, $zero, 0xFFFF         ## $t6 = FFFFFFFF
/* 0197C 809F4C3C 44092000 */  mfc1    $t1, $f4
/* 01980 809F4C40 A60E0272 */  sh      $t6, 0x0272($s0)           ## 00000272
/* 01984 809F4C44 3C01809F */  lui     $at, %hi(D_809F6054)       ## $at = 809F0000
/* 01988 809F4C48 00095400 */  sll     $t2, $t1, 16
/* 0198C 809F4C4C 000A5C03 */  sra     $t3, $t2, 16
/* 01990 809F4C50 448B3000 */  mtc1    $t3, $f6                   ## $f6 = 0.00
/* 01994 809F4C54 00000000 */  nop
/* 01998 809F4C58 46803220 */  cvt.s.w $f8, $f6
/* 0199C 809F4C5C 460A4400 */  add.s   $f16, $f8, $f10
/* 019A0 809F4C60 4600848D */  trunc.w.s $f18, $f16
/* 019A4 809F4C64 440D9000 */  mfc1    $t5, $f18
/* 019A8 809F4C68 00000000 */  nop
/* 019AC 809F4C6C A60D0264 */  sh      $t5, 0x0264($s0)           ## 00000264
/* 019B0 809F4C70 0C00CFBE */  jal     Rand_ZeroFloat

/* 019B4 809F4C74 C42C6054 */  lwc1    $f12, %lo(D_809F6054)($at)
/* 019B8 809F4C78 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 019BC 809F4C7C 44812000 */  mtc1    $at, $f4                   ## $f4 = 1.00
/* 019C0 809F4C80 3C18809F */  lui     $t8, %hi(func_809F4CB4)    ## $t8 = 809F0000
/* 019C4 809F4C84 240F0001 */  addiu   $t7, $zero, 0x0001         ## $t7 = 00000001
/* 019C8 809F4C88 4604003C */  c.lt.s  $f0, $f4
/* 019CC 809F4C8C 27184CB4 */  addiu   $t8, $t8, %lo(func_809F4CB4) ## $t8 = 809F4CB4
/* 019D0 809F4C90 45020003 */  bc1fl   .L809F4CA0
/* 019D4 809F4C94 AE180214 */  sw      $t8, 0x0214($s0)           ## 00000214
/* 019D8 809F4C98 A60F0272 */  sh      $t7, 0x0272($s0)           ## 00000272
/* 019DC 809F4C9C AE180214 */  sw      $t8, 0x0214($s0)           ## 00000214
.L809F4CA0:
/* 019E0 809F4CA0 8FBF002C */  lw      $ra, 0x002C($sp)
/* 019E4 809F4CA4 8FB00028 */  lw      $s0, 0x0028($sp)
/* 019E8 809F4CA8 27BD0030 */  addiu   $sp, $sp, 0x0030           ## $sp = 00000000
/* 019EC 809F4CAC 03E00008 */  jr      $ra
/* 019F0 809F4CB0 00000000 */  nop
