glabel func_80B00554
/* 022A4 80B00554 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 022A8 80B00558 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 022AC 80B0055C AFA5001C */  sw      $a1, 0x001C($sp)           
/* 022B0 80B00560 908E02D7 */  lbu     $t6, 0x02D7($a0)           ## 000002D7
/* 022B4 80B00564 51C00007 */  beql    $t6, $zero, .L80B00584     
/* 022B8 80B00568 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 022BC 80B0056C 8C8F0004 */  lw      $t7, 0x0004($a0)           ## 00000004
/* 022C0 80B00570 2405001A */  addiu   $a1, $zero, 0x001A         ## $a1 = 0000001A
/* 022C4 80B00574 35F80001 */  ori     $t8, $t7, 0x0001           ## $t8 = 00000001
/* 022C8 80B00578 0C2BF8CE */  jal     EnSkj_SetupAction              
/* 022CC 80B0057C AC980004 */  sw      $t8, 0x0004($a0)           ## 00000004
/* 022D0 80B00580 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L80B00584:
/* 022D4 80B00584 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 022D8 80B00588 03E00008 */  jr      $ra                        
/* 022DC 80B0058C 00000000 */  nop
