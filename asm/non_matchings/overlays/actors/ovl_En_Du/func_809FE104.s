glabel func_809FE104
/* 004D4 809FE104 27BDFFD0 */  addiu   $sp, $sp, 0xFFD0           ## $sp = FFFFFFD0
/* 004D8 809FE108 3C0F80A0 */  lui     $t7, %hi(D_809FF3F0)       ## $t7 = 80A00000
/* 004DC 809FE10C AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 004E0 809FE110 25EFF3F0 */  addiu   $t7, $t7, %lo(D_809FF3F0)  ## $t7 = 809FF3F0
/* 004E4 809FE114 8DF90000 */  lw      $t9, 0x0000($t7)           ## 809FF3F0
/* 004E8 809FE118 8DF80004 */  lw      $t8, 0x0004($t7)           ## 809FF3F4
/* 004EC 809FE11C 27AE0020 */  addiu   $t6, $sp, 0x0020           ## $t6 = FFFFFFF0
/* 004F0 809FE120 ADD90000 */  sw      $t9, 0x0000($t6)           ## FFFFFFF0
/* 004F4 809FE124 ADD80004 */  sw      $t8, 0x0004($t6)           ## FFFFFFF4
/* 004F8 809FE128 8DF8000C */  lw      $t8, 0x000C($t7)           ## 809FF3FC
/* 004FC 809FE12C 8DF90008 */  lw      $t9, 0x0008($t7)           ## 809FF3F8
/* 00500 809FE130 00803025 */  or      $a2, $a0, $zero            ## $a2 = 00000000
/* 00504 809FE134 ADD8000C */  sw      $t8, 0x000C($t6)           ## FFFFFFFC
/* 00508 809FE138 ADD90008 */  sw      $t9, 0x0008($t6)           ## FFFFFFF8
/* 0050C 809FE13C 848801E6 */  lh      $t0, 0x01E6($a0)           ## 000001E6
/* 00510 809FE140 2484014C */  addiu   $a0, $a0, 0x014C           ## $a0 = 0000014C
/* 00514 809FE144 29010004 */  slti    $at, $t0, 0x0004           
/* 00518 809FE148 50200015 */  beql    $at, $zero, .L809FE1A0     
/* 0051C 809FE14C 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 00520 809FE150 8CC5015C */  lw      $a1, 0x015C($a2)           ## 0000015C
/* 00524 809FE154 AFA60030 */  sw      $a2, 0x0030($sp)           
/* 00528 809FE158 0C0295B2 */  jal     Animation_OnFrame              
/* 0052C 809FE15C AFA40018 */  sw      $a0, 0x0018($sp)           
/* 00530 809FE160 8FA40018 */  lw      $a0, 0x0018($sp)           
/* 00534 809FE164 1040000D */  beq     $v0, $zero, .L809FE19C     
/* 00538 809FE168 8FA60030 */  lw      $a2, 0x0030($sp)           
/* 0053C 809FE16C 84C901E6 */  lh      $t1, 0x01E6($a2)           ## 000001E6
/* 00540 809FE170 3C0580A0 */  lui     $a1, %hi(D_809FF268)       ## $a1 = 80A00000
/* 00544 809FE174 24A5F268 */  addiu   $a1, $a1, %lo(D_809FF268)  ## $a1 = 809FF268
/* 00548 809FE178 252A0001 */  addiu   $t2, $t1, 0x0001           ## $t2 = 00000001
/* 0054C 809FE17C A4CA01E6 */  sh      $t2, 0x01E6($a2)           ## 000001E6
/* 00550 809FE180 84C201E6 */  lh      $v0, 0x01E6($a2)           ## 000001E6
/* 00554 809FE184 28410004 */  slti    $at, $v0, 0x0004           
/* 00558 809FE188 10200004 */  beq     $at, $zero, .L809FE19C     
/* 0055C 809FE18C 00025880 */  sll     $t3, $v0,  2               
/* 00560 809FE190 03AB3021 */  addu    $a2, $sp, $t3              
/* 00564 809FE194 0C00D3B0 */  jal     Actor_ChangeAnimation              
/* 00568 809FE198 8CC60020 */  lw      $a2, 0x0020($a2)           ## 00000020
.L809FE19C:
/* 0056C 809FE19C 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L809FE1A0:
/* 00570 809FE1A0 27BD0030 */  addiu   $sp, $sp, 0x0030           ## $sp = 00000000
/* 00574 809FE1A4 03E00008 */  jr      $ra                        
/* 00578 809FE1A8 00000000 */  nop
