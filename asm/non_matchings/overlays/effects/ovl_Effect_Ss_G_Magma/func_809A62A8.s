glabel func_809A62A8
/* 00158 809A62A8 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 0015C 809A62AC AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 00160 809A62B0 AFA5001C */  sw      $a1, 0x001C($sp)           
/* 00164 809A62B4 84C20040 */  lh      $v0, 0x0040($a2)           ## 00000040
/* 00168 809A62B8 24010064 */  addiu   $at, $zero, 0x0064         ## $at = 00000064
/* 0016C 809A62BC 00C02825 */  or      $a1, $a2, $zero            ## $a1 = 00000000
/* 00170 809A62C0 0041001A */  div     $zero, $v0, $at            
/* 00174 809A62C4 00001012 */  mflo    $v0                        
/* 00178 809A62C8 00021400 */  sll     $v0, $v0, 16               
/* 0017C 809A62CC 00021403 */  sra     $v0, $v0, 16               
/* 00180 809A62D0 28410008 */  slti    $at, $v0, 0x0008           
/* 00184 809A62D4 14200002 */  bne     $at, $zero, .L809A62E0     
/* 00188 809A62D8 3C06809A */  lui     $a2, %hi(D_809A6334)       ## $a2 = 809A0000
/* 0018C 809A62DC 24020007 */  addiu   $v0, $zero, 0x0007         ## $v0 = 00000007
.L809A62E0:
/* 00190 809A62E0 00027080 */  sll     $t6, $v0,  2               
/* 00194 809A62E4 00CE3021 */  addu    $a2, $a2, $t6              
/* 00198 809A62E8 0C009FE0 */  jal     EffectSs_DrawGEffect              
/* 0019C 809A62EC 8CC66334 */  lw      $a2, %lo(D_809A6334)($a2)  
/* 001A0 809A62F0 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 001A4 809A62F4 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 001A8 809A62F8 03E00008 */  jr      $ra                        
/* 001AC 809A62FC 00000000 */  nop
