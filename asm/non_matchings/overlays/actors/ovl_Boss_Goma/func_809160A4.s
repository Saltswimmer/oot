glabel func_809160A4
/* 00694 809160A4 27BDFFD0 */  addiu   $sp, $sp, 0xFFD0           ## $sp = FFFFFFD0
/* 00698 809160A8 AFA40030 */  sw      $a0, 0x0030($sp)
/* 0069C 809160AC AFBF0024 */  sw      $ra, 0x0024($sp)
/* 006A0 809160B0 3C040601 */  lui     $a0, 0x0601                ## $a0 = 06010000
/* 006A4 809160B4 0C028800 */  jal     SkelAnime_GetFrameCount

/* 006A8 809160B8 24842678 */  addiu   $a0, $a0, 0x2678           ## $a0 = 06012678
/* 006AC 809160BC 44822000 */  mtc1    $v0, $f4                   ## $f4 = 0.00
/* 006B0 809160C0 24040014 */  addiu   $a0, $zero, 0x0014         ## $a0 = 00000014
/* 006B4 809160C4 2405001E */  addiu   $a1, $zero, 0x001E         ## $a1 = 0000001E
/* 006B8 809160C8 468021A0 */  cvt.s.w $f6, $f4
/* 006BC 809160CC 0C01DF64 */  jal     Rand_S16Offset

/* 006C0 809160D0 E7A6002C */  swc1    $f6, 0x002C($sp)
/* 006C4 809160D4 8FA30030 */  lw      $v1, 0x0030($sp)
/* 006C8 809160D8 3C01C0A0 */  lui     $at, 0xC0A0                ## $at = C0A00000
/* 006CC 809160DC 44815000 */  mtc1    $at, $f10                  ## $f10 = -5.00
/* 006D0 809160E0 A46201D2 */  sh      $v0, 0x01D2($v1)           ## 000001D2
/* 006D4 809160E4 C7A8002C */  lwc1    $f8, 0x002C($sp)
/* 006D8 809160E8 3C050601 */  lui     $a1, 0x0601                ## $a1 = 06010000
/* 006DC 809160EC 24A52678 */  addiu   $a1, $a1, 0x2678           ## $a1 = 06012678
/* 006E0 809160F0 AFA00014 */  sw      $zero, 0x0014($sp)
/* 006E4 809160F4 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 006E8 809160F8 24070000 */  addiu   $a3, $zero, 0x0000         ## $a3 = 00000000
/* 006EC 809160FC 2464014C */  addiu   $a0, $v1, 0x014C           ## $a0 = 0000014C
/* 006F0 80916100 E7AA0018 */  swc1    $f10, 0x0018($sp)
/* 006F4 80916104 0C029468 */  jal     SkelAnime_ChangeAnim

/* 006F8 80916108 E7A80010 */  swc1    $f8, 0x0010($sp)
/* 006FC 8091610C 8FAF0030 */  lw      $t7, 0x0030($sp)
/* 00700 80916110 3C0E8092 */  lui     $t6, %hi(func_809195A4)    ## $t6 = 80920000
/* 00704 80916114 25CE95A4 */  addiu   $t6, $t6, %lo(func_809195A4) ## $t6 = 809195A4
/* 00708 80916118 ADEE0190 */  sw      $t6, 0x0190($t7)           ## 00000190
/* 0070C 8091611C 8FBF0024 */  lw      $ra, 0x0024($sp)
/* 00710 80916120 27BD0030 */  addiu   $sp, $sp, 0x0030           ## $sp = 00000000
/* 00714 80916124 03E00008 */  jr      $ra
/* 00718 80916128 00000000 */  nop
