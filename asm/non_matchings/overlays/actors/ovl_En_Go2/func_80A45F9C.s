glabel func_80A45F9C
/* 0326C 80A45F9C 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 03270 80A45FA0 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 03274 80A45FA4 848E001C */  lh      $t6, 0x001C($a0)           ## 0000001C
/* 03278 80A45FA8 24010004 */  addiu   $at, $zero, 0x0004         ## $at = 00000004
/* 0327C 80A45FAC 00803825 */  or      $a3, $a0, $zero            ## $a3 = 00000000
/* 03280 80A45FB0 31CF001F */  andi    $t7, $t6, 0x001F           ## $t7 = 00000000
/* 03284 80A45FB4 15E10006 */  bne     $t7, $at, .L80A45FD0       
/* 03288 80A45FB8 00000000 */  nop
/* 0328C 80A45FBC 84980194 */  lh      $t8, 0x0194($a0)           ## 00000194
/* 03290 80A45FC0 24010002 */  addiu   $at, $zero, 0x0002         ## $at = 00000002
/* 03294 80A45FC4 24E4014C */  addiu   $a0, $a3, 0x014C           ## $a0 = 0000014C
/* 03298 80A45FC8 13010003 */  beq     $t8, $at, .L80A45FD8       
/* 0329C 80A45FCC 3C0580A5 */  lui     $a1, %hi(D_80A48348)       ## $a1 = 80A50000
.L80A45FD0:
/* 032A0 80A45FD0 1000000E */  beq     $zero, $zero, .L80A4600C   
/* 032A4 80A45FD4 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
.L80A45FD8:
/* 032A8 80A45FD8 24A58348 */  addiu   $a1, $a1, %lo(D_80A48348)  ## $a1 = 80A48348
/* 032AC 80A45FDC 24060003 */  addiu   $a2, $zero, 0x0003         ## $a2 = 00000003
/* 032B0 80A45FE0 0C00D3B0 */  jal     Actor_ChangeAnimation              
/* 032B4 80A45FE4 AFA70018 */  sw      $a3, 0x0018($sp)           
/* 032B8 80A45FE8 8FA70018 */  lw      $a3, 0x0018($sp)           
/* 032BC 80A45FEC 3C0880A4 */  lui     $t0, %hi(func_80A46CD8)    ## $t0 = 80A40000
/* 032C0 80A45FF0 24190001 */  addiu   $t9, $zero, 0x0001         ## $t9 = 00000001
/* 032C4 80A45FF4 25086CD8 */  addiu   $t0, $t0, %lo(func_80A46CD8) ## $t0 = 80A46CD8
/* 032C8 80A45FF8 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
/* 032CC 80A45FFC A4E00194 */  sh      $zero, 0x0194($a3)         ## 00000194
/* 032D0 80A46000 A0E0020F */  sb      $zero, 0x020F($a3)         ## 0000020F
/* 032D4 80A46004 A4F9026E */  sh      $t9, 0x026E($a3)           ## 0000026E
/* 032D8 80A46008 ACE80190 */  sw      $t0, 0x0190($a3)           ## 00000190
.L80A4600C:
/* 032DC 80A4600C 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 032E0 80A46010 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 032E4 80A46014 03E00008 */  jr      $ra                        
/* 032E8 80A46018 00000000 */  nop
