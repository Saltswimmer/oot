glabel func_80895BEC
/* 002FC 80895BEC 27BDFFC0 */  addiu   $sp, $sp, 0xFFC0           ## $sp = FFFFFFC0
/* 00300 80895BF0 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 00304 80895BF4 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 00308 80895BF8 8CAE1C44 */  lw      $t6, 0x1C44($a1)           ## 00001C44
/* 0030C 80895BFC 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 00310 80895C00 AFAE003C */  sw      $t6, 0x003C($sp)           
/* 00314 80895C04 0C01DE1C */  jal     Math_SinS
              ## sins?
/* 00318 80895C08 84840170 */  lh      $a0, 0x0170($a0)           ## 00000170
/* 0031C 80895C0C E7A00024 */  swc1    $f0, 0x0024($sp)           
/* 00320 80895C10 0C01DE0D */  jal     Math_CosS
              ## coss?
/* 00324 80895C14 86040170 */  lh      $a0, 0x0170($s0)           ## 00000170
/* 00328 80895C18 44070000 */  mfc1    $a3, $f0                   
/* 0032C 80895C1C 27A4002C */  addiu   $a0, $sp, 0x002C           ## $a0 = FFFFFFEC
/* 00330 80895C20 26050174 */  addiu   $a1, $s0, 0x0174           ## $a1 = 00000174
/* 00334 80895C24 0C22563C */  jal     func_808958F0              
/* 00338 80895C28 8FA60024 */  lw      $a2, 0x0024($sp)           
/* 0033C 80895C2C C6040024 */  lwc1    $f4, 0x0024($s0)           ## 00000024
/* 00340 80895C30 C7A6002C */  lwc1    $f6, 0x002C($sp)           
/* 00344 80895C34 8FA2003C */  lw      $v0, 0x003C($sp)           
/* 00348 80895C38 46062200 */  add.s   $f8, $f4, $f6              
/* 0034C 80895C3C E4480024 */  swc1    $f8, 0x0024($v0)           ## 00000024
/* 00350 80895C40 C7B00030 */  lwc1    $f16, 0x0030($sp)          
/* 00354 80895C44 C60A0028 */  lwc1    $f10, 0x0028($s0)          ## 00000028
/* 00358 80895C48 46105480 */  add.s   $f18, $f10, $f16           
/* 0035C 80895C4C E4520028 */  swc1    $f18, 0x0028($v0)          ## 00000028
/* 00360 80895C50 C7A60034 */  lwc1    $f6, 0x0034($sp)           
/* 00364 80895C54 C604002C */  lwc1    $f4, 0x002C($s0)           ## 0000002C
/* 00368 80895C58 46062200 */  add.s   $f8, $f4, $f6              
/* 0036C 80895C5C E448002C */  swc1    $f8, 0x002C($v0)           ## 0000002C
/* 00370 80895C60 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 00374 80895C64 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 00378 80895C68 27BD0040 */  addiu   $sp, $sp, 0x0040           ## $sp = 00000000
/* 0037C 80895C6C 03E00008 */  jr      $ra                        
/* 00380 80895C70 00000000 */  nop
