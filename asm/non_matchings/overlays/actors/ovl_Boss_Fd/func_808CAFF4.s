glabel func_808CAFF4
/* 00234 808CAFF4 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 00238 808CAFF8 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 0023C 808CAFFC 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
.L808CB000:
/* 00240 808CB000 908E0024 */  lbu     $t6, 0x0024($a0)           ## 00000024
/* 00244 808CB004 24420001 */  addiu   $v0, $v0, 0x0001           ## $v0 = 00000001
/* 00248 808CB008 00021400 */  sll     $v0, $v0, 16               
/* 0024C 808CB00C 15C00035 */  bne     $t6, $zero, .L808CB0E4     
/* 00250 808CB010 00021403 */  sra     $v0, $v0, 16               
/* 00254 808CB014 240F0004 */  addiu   $t7, $zero, 0x0004         ## $t7 = 00000004
/* 00258 808CB018 A08F0024 */  sb      $t7, 0x0024($a0)           ## 00000024
/* 0025C 808CB01C A0800025 */  sb      $zero, 0x0025($a0)         ## 00000025
/* 00260 808CB020 8CB90000 */  lw      $t9, 0x0000($a1)           ## 00000000
/* 00264 808CB024 3C014120 */  lui     $at, 0x4120                ## $at = 41200000
/* 00268 808CB028 44816000 */  mtc1    $at, $f12                  ## $f12 = 10.00
/* 0026C 808CB02C AC990000 */  sw      $t9, 0x0000($a0)           ## 00000000
/* 00270 808CB030 8CB80004 */  lw      $t8, 0x0004($a1)           ## 00000004
/* 00274 808CB034 C4840000 */  lwc1    $f4, 0x0000($a0)           ## 00000000
/* 00278 808CB038 AC980004 */  sw      $t8, 0x0004($a0)           ## 00000004
/* 0027C 808CB03C 8CB90008 */  lw      $t9, 0x0008($a1)           ## 00000008
/* 00280 808CB040 C48A0004 */  lwc1    $f10, 0x0004($a0)          ## 00000004
/* 00284 808CB044 AC990008 */  sw      $t9, 0x0008($a0)           ## 00000008
/* 00288 808CB048 8CC90000 */  lw      $t1, 0x0000($a2)           ## 00000000
/* 0028C 808CB04C AC89000C */  sw      $t1, 0x000C($a0)           ## 0000000C
/* 00290 808CB050 8CC80004 */  lw      $t0, 0x0004($a2)           ## 00000004
/* 00294 808CB054 C486000C */  lwc1    $f6, 0x000C($a0)           ## 0000000C
/* 00298 808CB058 AC880010 */  sw      $t0, 0x0010($a0)           ## 00000010
/* 0029C 808CB05C 8CC90008 */  lw      $t1, 0x0008($a2)           ## 00000008
/* 002A0 808CB060 46062201 */  sub.s   $f8, $f4, $f6              
/* 002A4 808CB064 C4900010 */  lwc1    $f16, 0x0010($a0)          ## 00000010
/* 002A8 808CB068 AC890014 */  sw      $t1, 0x0014($a0)           ## 00000014
/* 002AC 808CB06C 8CEB0000 */  lw      $t3, 0x0000($a3)           ## 00000000
/* 002B0 808CB070 C4860014 */  lwc1    $f6, 0x0014($a0)           ## 00000014
/* 002B4 808CB074 C4840008 */  lwc1    $f4, 0x0008($a0)           ## 00000008
/* 002B8 808CB078 AC8B0018 */  sw      $t3, 0x0018($a0)           ## 00000018
/* 002BC 808CB07C 8CEA0004 */  lw      $t2, 0x0004($a3)           ## 00000004
/* 002C0 808CB080 46105481 */  sub.s   $f18, $f10, $f16           
/* 002C4 808CB084 44805000 */  mtc1    $zero, $f10                ## $f10 = 0.00
/* 002C8 808CB088 AC8A001C */  sw      $t2, 0x001C($a0)           ## 0000001C
/* 002CC 808CB08C 8CEB0008 */  lw      $t3, 0x0008($a3)           ## 00000008
/* 002D0 808CB090 E4880000 */  swc1    $f8, 0x0000($a0)           ## 00000000
/* 002D4 808CB094 46062201 */  sub.s   $f8, $f4, $f6              
/* 002D8 808CB098 E4920004 */  swc1    $f18, 0x0004($a0)          ## 00000004
/* 002DC 808CB09C E48A0034 */  swc1    $f10, 0x0034($a0)          ## 00000034
/* 002E0 808CB0A0 AC8B0020 */  sw      $t3, 0x0020($a0)           ## 00000020
/* 002E4 808CB0A4 E4880008 */  swc1    $f8, 0x0008($a0)           ## 00000008
/* 002E8 808CB0A8 87AC002E */  lh      $t4, 0x002E($sp)           
/* 002EC 808CB0AC A48C002A */  sh      $t4, 0x002A($a0)           ## 0000002A
/* 002F0 808CB0B0 0C00CFBE */  jal     Rand_ZeroFloat
              
/* 002F4 808CB0B4 AFA40018 */  sw      $a0, 0x0018($sp)           
/* 002F8 808CB0B8 8FA40018 */  lw      $a0, 0x0018($sp)           
/* 002FC 808CB0BC 3C0143C8 */  lui     $at, 0x43C8                ## $at = 43C80000
/* 00300 808CB0C0 44819000 */  mtc1    $at, $f18                  ## $f18 = 400.00
/* 00304 808CB0C4 E4800038 */  swc1    $f0, 0x0038($a0)           ## 00000038
/* 00308 808CB0C8 A480002C */  sh      $zero, 0x002C($a0)         ## 0000002C
/* 0030C 808CB0CC C7B00028 */  lwc1    $f16, 0x0028($sp)          
/* 00310 808CB0D0 46128103 */  div.s   $f4, $f16, $f18            
/* 00314 808CB0D4 E4840030 */  swc1    $f4, 0x0030($a0)           ## 00000030
/* 00318 808CB0D8 87AD0032 */  lh      $t5, 0x0032($sp)           
/* 0031C 808CB0DC 10000004 */  beq     $zero, $zero, .L808CB0F0   
/* 00320 808CB0E0 A48D002E */  sh      $t5, 0x002E($a0)           ## 0000002E
.L808CB0E4:
/* 00324 808CB0E4 284100B4 */  slti    $at, $v0, 0x00B4           
/* 00328 808CB0E8 1420FFC5 */  bne     $at, $zero, .L808CB000     
/* 0032C 808CB0EC 2484003C */  addiu   $a0, $a0, 0x003C           ## $a0 = 0000003C
.L808CB0F0:
/* 00330 808CB0F0 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 00334 808CB0F4 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 00338 808CB0F8 03E00008 */  jr      $ra                        
/* 0033C 808CB0FC 00000000 */  nop
