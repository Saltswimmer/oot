glabel func_80A4C594
/* 008F4 80A4C594 27BDFFA8 */  addiu   $sp, $sp, 0xFFA8           ## $sp = FFFFFFA8
/* 008F8 80A4C598 F7B40018 */  sdc1    $f20, 0x0018($sp)          
/* 008FC 80A4C59C 3C01425C */  lui     $at, 0x425C                ## $at = 425C0000
/* 00900 80A4C5A0 AFB50038 */  sw      $s5, 0x0038($sp)           
/* 00904 80A4C5A4 AFB40034 */  sw      $s4, 0x0034($sp)           
/* 00908 80A4C5A8 AFB30030 */  sw      $s3, 0x0030($sp)           
/* 0090C 80A4C5AC AFB2002C */  sw      $s2, 0x002C($sp)           
/* 00910 80A4C5B0 AFB10028 */  sw      $s1, 0x0028($sp)           
/* 00914 80A4C5B4 AFB00024 */  sw      $s0, 0x0024($sp)           
/* 00918 80A4C5B8 4481A000 */  mtc1    $at, $f20                  ## $f20 = 55.00
/* 0091C 80A4C5BC 00A09025 */  or      $s2, $a1, $zero            ## $s2 = 00000000
/* 00920 80A4C5C0 0080A825 */  or      $s5, $a0, $zero            ## $s5 = 00000000
/* 00924 80A4C5C4 AFBF003C */  sw      $ra, 0x003C($sp)           
/* 00928 80A4C5C8 00008025 */  or      $s0, $zero, $zero          ## $s0 = 00000000
/* 0092C 80A4C5CC 00008825 */  or      $s1, $zero, $zero          ## $s1 = 00000000
/* 00930 80A4C5D0 27B3004C */  addiu   $s3, $sp, 0x004C           ## $s3 = FFFFFFF4
/* 00934 80A4C5D4 2414000B */  addiu   $s4, $zero, 0x000B         ## $s4 = 0000000B
/* 00938 80A4C5D8 26101746 */  addiu   $s0, $s0, 0x1746           ## $s0 = 00001746
.L80A4C5DC:
/* 0093C 80A4C5DC 00108400 */  sll     $s0, $s0, 16               
/* 00940 80A4C5E0 00108403 */  sra     $s0, $s0, 16               
/* 00944 80A4C5E4 00102400 */  sll     $a0, $s0, 16               
/* 00948 80A4C5E8 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 0094C 80A4C5EC 00042403 */  sra     $a0, $a0, 16               
/* 00950 80A4C5F0 46140102 */  mul.s   $f4, $f0, $f20             
/* 00954 80A4C5F4 C6460000 */  lwc1    $f6, 0x0000($s2)           ## 00000000
/* 00958 80A4C5F8 00102400 */  sll     $a0, $s0, 16               
/* 0095C 80A4C5FC 00042403 */  sra     $a0, $a0, 16               
/* 00960 80A4C600 46062200 */  add.s   $f8, $f4, $f6              
/* 00964 80A4C604 E7A8004C */  swc1    $f8, 0x004C($sp)           
/* 00968 80A4C608 C64A0004 */  lwc1    $f10, 0x0004($s2)          ## 00000004
/* 0096C 80A4C60C 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 00970 80A4C610 E7AA0050 */  swc1    $f10, 0x0050($sp)          
/* 00974 80A4C614 46140402 */  mul.s   $f16, $f0, $f20            
/* 00978 80A4C618 C6520008 */  lwc1    $f18, 0x0008($s2)          ## 00000008
/* 0097C 80A4C61C 240E015E */  addiu   $t6, $zero, 0x015E         ## $t6 = 0000015E
/* 00980 80A4C620 AFAE0014 */  sw      $t6, 0x0014($sp)           
/* 00984 80A4C624 AFA00010 */  sw      $zero, 0x0010($sp)         
/* 00988 80A4C628 02A02025 */  or      $a0, $s5, $zero            ## $a0 = 00000000
/* 0098C 80A4C62C 02602825 */  or      $a1, $s3, $zero            ## $a1 = FFFFFFF4
/* 00990 80A4C630 46128100 */  add.s   $f4, $f16, $f18            
/* 00994 80A4C634 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 00998 80A4C638 00003825 */  or      $a3, $zero, $zero          ## $a3 = 00000000
/* 0099C 80A4C63C 0C00A527 */  jal     EffectSsGSplash_Spawn              
/* 009A0 80A4C640 E7A40054 */  swc1    $f4, 0x0054($sp)           
/* 009A4 80A4C644 26310001 */  addiu   $s1, $s1, 0x0001           ## $s1 = 00000001
/* 009A8 80A4C648 5634FFE4 */  bnel    $s1, $s4, .L80A4C5DC       
/* 009AC 80A4C64C 26101746 */  addiu   $s0, $s0, 0x1746           ## $s0 = 00002E8C
/* 009B0 80A4C650 02A02025 */  or      $a0, $s5, $zero            ## $a0 = 00000000
/* 009B4 80A4C654 02402825 */  or      $a1, $s2, $zero            ## $a1 = 00000000
/* 009B8 80A4C658 2406012C */  addiu   $a2, $zero, 0x012C         ## $a2 = 0000012C
/* 009BC 80A4C65C 240702BC */  addiu   $a3, $zero, 0x02BC         ## $a3 = 000002BC
/* 009C0 80A4C660 0C00A511 */  jal     EffectSsGRipple_Spawn              
/* 009C4 80A4C664 AFA00010 */  sw      $zero, 0x0010($sp)         
/* 009C8 80A4C668 240F0004 */  addiu   $t7, $zero, 0x0004         ## $t7 = 00000004
/* 009CC 80A4C66C AFAF0010 */  sw      $t7, 0x0010($sp)           
/* 009D0 80A4C670 02A02025 */  or      $a0, $s5, $zero            ## $a0 = 00000000
/* 009D4 80A4C674 02402825 */  or      $a1, $s2, $zero            ## $a1 = 00000000
/* 009D8 80A4C678 240601F4 */  addiu   $a2, $zero, 0x01F4         ## $a2 = 000001F4
/* 009DC 80A4C67C 0C00A511 */  jal     EffectSsGRipple_Spawn              
/* 009E0 80A4C680 24070384 */  addiu   $a3, $zero, 0x0384         ## $a3 = 00000384
/* 009E4 80A4C684 24180008 */  addiu   $t8, $zero, 0x0008         ## $t8 = 00000008
/* 009E8 80A4C688 AFB80010 */  sw      $t8, 0x0010($sp)           
/* 009EC 80A4C68C 02A02025 */  or      $a0, $s5, $zero            ## $a0 = 00000000
/* 009F0 80A4C690 02402825 */  or      $a1, $s2, $zero            ## $a1 = 00000000
/* 009F4 80A4C694 240601F4 */  addiu   $a2, $zero, 0x01F4         ## $a2 = 000001F4
/* 009F8 80A4C698 0C00A511 */  jal     EffectSsGRipple_Spawn              
/* 009FC 80A4C69C 24070514 */  addiu   $a3, $zero, 0x0514         ## $a3 = 00000514
/* 00A00 80A4C6A0 8FBF003C */  lw      $ra, 0x003C($sp)           
/* 00A04 80A4C6A4 D7B40018 */  ldc1    $f20, 0x0018($sp)          
/* 00A08 80A4C6A8 8FB00024 */  lw      $s0, 0x0024($sp)           
/* 00A0C 80A4C6AC 8FB10028 */  lw      $s1, 0x0028($sp)           
/* 00A10 80A4C6B0 8FB2002C */  lw      $s2, 0x002C($sp)           
/* 00A14 80A4C6B4 8FB30030 */  lw      $s3, 0x0030($sp)           
/* 00A18 80A4C6B8 8FB40034 */  lw      $s4, 0x0034($sp)           
/* 00A1C 80A4C6BC 8FB50038 */  lw      $s5, 0x0038($sp)           
/* 00A20 80A4C6C0 03E00008 */  jr      $ra                        
/* 00A24 80A4C6C4 27BD0058 */  addiu   $sp, $sp, 0x0058           ## $sp = 00000000
