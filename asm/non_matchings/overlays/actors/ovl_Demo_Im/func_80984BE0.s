glabel func_80984BE0
/* 00000 80984BE0 27BDFFC8 */  addiu   $sp, $sp, 0xFFC8           ## $sp = FFFFFFC8
/* 00004 80984BE4 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 00008 80984BE8 848E025E */  lh      $t6, 0x025E($a0)           ## 0000025E
/* 0000C 80984BEC 00803025 */  or      $a2, $a0, $zero            ## $a2 = 00000000
/* 00010 80984BF0 24C3025E */  addiu   $v1, $a2, 0x025E           ## $v1 = 0000025E
/* 00014 80984BF4 15C00003 */  bne     $t6, $zero, .L80984C04     
/* 00018 80984BF8 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
/* 0001C 80984BFC 10000005 */  beq     $zero, $zero, .L80984C14   
/* 00020 80984C00 2483025E */  addiu   $v1, $a0, 0x025E           ## $v1 = 0000025E
.L80984C04:
/* 00024 80984C04 846F0000 */  lh      $t7, 0x0000($v1)           ## 0000025E
/* 00028 80984C08 25F8FFFF */  addiu   $t8, $t7, 0xFFFF           ## $t8 = FFFFFFFF
/* 0002C 80984C0C A4780000 */  sh      $t8, 0x0000($v1)           ## 0000025E
/* 00030 80984C10 84620000 */  lh      $v0, 0x0000($v1)           ## 0000025E
.L80984C14:
/* 00034 80984C14 14400008 */  bne     $v0, $zero, .L80984C38     
/* 00038 80984C18 2404003C */  addiu   $a0, $zero, 0x003C         ## $a0 = 0000003C
/* 0003C 80984C1C 2405003C */  addiu   $a1, $zero, 0x003C         ## $a1 = 0000003C
/* 00040 80984C20 AFA3001C */  sw      $v1, 0x001C($sp)           
/* 00044 80984C24 0C01DF64 */  jal     Math_Rand_S16Offset
              
/* 00048 80984C28 AFA60038 */  sw      $a2, 0x0038($sp)           
/* 0004C 80984C2C 8FA3001C */  lw      $v1, 0x001C($sp)           
/* 00050 80984C30 8FA60038 */  lw      $a2, 0x0038($sp)           
/* 00054 80984C34 A4620000 */  sh      $v0, 0x0000($v1)           ## 00000000
.L80984C38:
/* 00058 80984C38 84790000 */  lh      $t9, 0x0000($v1)           ## 00000000
/* 0005C 80984C3C 24C2025C */  addiu   $v0, $a2, 0x025C           ## $v0 = 0000025C
/* 00060 80984C40 A4590000 */  sh      $t9, 0x0000($v0)           ## 0000025C
/* 00064 80984C44 84480000 */  lh      $t0, 0x0000($v0)           ## 0000025C
/* 00068 80984C48 29010003 */  slti    $at, $t0, 0x0003           
/* 0006C 80984C4C 54200003 */  bnel    $at, $zero, .L80984C5C     
/* 00070 80984C50 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 00074 80984C54 A4400000 */  sh      $zero, 0x0000($v0)         ## 0000025C
/* 00078 80984C58 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L80984C5C:
/* 0007C 80984C5C 27BD0038 */  addiu   $sp, $sp, 0x0038           ## $sp = 00000000
/* 00080 80984C60 03E00008 */  jr      $ra                        
/* 00084 80984C64 00000000 */  nop

