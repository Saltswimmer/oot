glabel func_80AF594C
/* 003EC 80AF594C 27BDFFD8 */  addiu   $sp, $sp, 0xFFD8           ## $sp = FFFFFFD8
/* 003F0 80AF5950 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 003F4 80AF5954 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 003F8 80AF5958 9082020A */  lbu     $v0, 0x020A($a0)           ## 0000020A
/* 003FC 80AF595C 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 00400 80AF5960 2604014C */  addiu   $a0, $s0, 0x014C           ## $a0 = 0000014C
/* 00404 80AF5964 10400006 */  beq     $v0, $zero, .L80AF5980     
/* 00408 80AF5968 3C0580AF */  lui     $a1, %hi(D_80AF7358)       ## $a1 = 80AF0000
/* 0040C 80AF596C 24010001 */  addiu   $at, $zero, 0x0001         ## $at = 00000001
/* 00410 80AF5970 5041000A */  beql    $v0, $at, .L80AF599C       
/* 00414 80AF5974 2604014C */  addiu   $a0, $s0, 0x014C           ## $a0 = 0000014C
/* 00418 80AF5978 10000015 */  beq     $zero, $zero, .L80AF59D0   
/* 0041C 80AF597C 8FBF001C */  lw      $ra, 0x001C($sp)           
.L80AF5980:
/* 00420 80AF5980 24A57358 */  addiu   $a1, $a1, %lo(D_80AF7358)  ## $a1 = 80AF7358
/* 00424 80AF5984 0C00D3B0 */  jal     Actor_ChangeAnimation              
/* 00428 80AF5988 24060008 */  addiu   $a2, $zero, 0x0008         ## $a2 = 00000008
/* 0042C 80AF598C 920E020A */  lbu     $t6, 0x020A($s0)           ## 0000020A
/* 00430 80AF5990 25CF0001 */  addiu   $t7, $t6, 0x0001           ## $t7 = 00000001
/* 00434 80AF5994 A20F020A */  sb      $t7, 0x020A($s0)           ## 0000020A
/* 00438 80AF5998 2604014C */  addiu   $a0, $s0, 0x014C           ## $a0 = 0000014C
.L80AF599C:
/* 0043C 80AF599C 8E05015C */  lw      $a1, 0x015C($s0)           ## 0000015C
/* 00440 80AF59A0 0C0295B2 */  jal     Animation_OnFrame              
/* 00444 80AF59A4 AFA40020 */  sw      $a0, 0x0020($sp)           
/* 00448 80AF59A8 10400008 */  beq     $v0, $zero, .L80AF59CC     
/* 0044C 80AF59AC 8FA40020 */  lw      $a0, 0x0020($sp)           
/* 00450 80AF59B0 3C0580AF */  lui     $a1, %hi(D_80AF7358)       ## $a1 = 80AF0000
/* 00454 80AF59B4 24A57358 */  addiu   $a1, $a1, %lo(D_80AF7358)  ## $a1 = 80AF7358
/* 00458 80AF59B8 0C00D3B0 */  jal     Actor_ChangeAnimation              
/* 0045C 80AF59BC 24060009 */  addiu   $a2, $zero, 0x0009         ## $a2 = 00000009
/* 00460 80AF59C0 9218020A */  lbu     $t8, 0x020A($s0)           ## 0000020A
/* 00464 80AF59C4 27190001 */  addiu   $t9, $t8, 0x0001           ## $t9 = 00000001
/* 00468 80AF59C8 A219020A */  sb      $t9, 0x020A($s0)           ## 0000020A
.L80AF59CC:
/* 0046C 80AF59CC 8FBF001C */  lw      $ra, 0x001C($sp)           
.L80AF59D0:
/* 00470 80AF59D0 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 00474 80AF59D4 27BD0028 */  addiu   $sp, $sp, 0x0028           ## $sp = 00000000
/* 00478 80AF59D8 03E00008 */  jr      $ra                        
/* 0047C 80AF59DC 00000000 */  nop
