.late_rodata
glabel jtbl_80B5FBD8
.word L80B5C494
.word L80B5C4B4
.word L80B5C508
.word L80B5C550
.word L80B5C628
.word L80B5C670
.word L80B5C6D4
.word L80B5C7F0
.word L80B5C838
.word L80B5C8A4
.word L80B5C8F4
.word L80B5C958
.word L80B5C704
.word L80B5C71C

.text
glabel func_80B5C458
/* 00CA8 80B5C458 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 00CAC 80B5C45C AFBF001C */  sw      $ra, 0x001C($sp)           
/* 00CB0 80B5C460 AFB10018 */  sw      $s1, 0x0018($sp)           
/* 00CB4 80B5C464 AFB00014 */  sw      $s0, 0x0014($sp)           
/* 00CB8 80B5C468 90820208 */  lbu     $v0, 0x0208($a0)           ## 00000208
/* 00CBC 80B5C46C 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 00CC0 80B5C470 00A08825 */  or      $s1, $a1, $zero            ## $s1 = 00000000
/* 00CC4 80B5C474 2C41000E */  sltiu   $at, $v0, 0x000E           
/* 00CC8 80B5C478 10200137 */  beq     $at, $zero, .L80B5C958     
/* 00CCC 80B5C47C 00027080 */  sll     $t6, $v0,  2               
/* 00CD0 80B5C480 3C0180B6 */  lui     $at, %hi(jtbl_80B5FBD8)       ## $at = 80B60000
/* 00CD4 80B5C484 002E0821 */  addu    $at, $at, $t6              
/* 00CD8 80B5C488 8C2EFBD8 */  lw      $t6, %lo(jtbl_80B5FBD8)($at)  
/* 00CDC 80B5C48C 01C00008 */  jr      $t6                        
/* 00CE0 80B5C490 00000000 */  nop
glabel L80B5C494
/* 00CE4 80B5C494 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00CE8 80B5C498 0C2D6FE4 */  jal     func_80B5BF90              
/* 00CEC 80B5C49C 24050019 */  addiu   $a1, $zero, 0x0019         ## $a1 = 00000019
/* 00CF0 80B5C4A0 10400004 */  beq     $v0, $zero, .L80B5C4B4     
/* 00CF4 80B5C4A4 00000000 */  nop
/* 00CF8 80B5C4A8 920F0208 */  lbu     $t7, 0x0208($s0)           ## 00000208
/* 00CFC 80B5C4AC 25F80001 */  addiu   $t8, $t7, 0x0001           ## $t8 = 00000001
/* 00D00 80B5C4B0 A2180208 */  sb      $t8, 0x0208($s0)           ## 00000208
glabel L80B5C4B4
.L80B5C4B4:
/* 00D04 80B5C4B4 0C042F6F */  jal     func_8010BDBC              
/* 00D08 80B5C4B8 262420D8 */  addiu   $a0, $s1, 0x20D8           ## $a0 = 000020D8
/* 00D0C 80B5C4BC 24010005 */  addiu   $at, $zero, 0x0005         ## $at = 00000005
/* 00D10 80B5C4C0 1441000F */  bne     $v0, $at, .L80B5C500       
/* 00D14 80B5C4C4 00000000 */  nop
/* 00D18 80B5C4C8 0C041AF2 */  jal     func_80106BC8              
/* 00D1C 80B5C4CC 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 00D20 80B5C4D0 1040000B */  beq     $v0, $zero, .L80B5C500     
/* 00D24 80B5C4D4 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 00D28 80B5C4D8 0C2D6DEC */  jal     func_80B5B7B0              
/* 00D2C 80B5C4DC 24050003 */  addiu   $a1, $zero, 0x0003         ## $a1 = 00000003
/* 00D30 80B5C4E0 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 00D34 80B5C4E4 00310821 */  addu    $at, $at, $s1              
/* 00D38 80B5C4E8 24190037 */  addiu   $t9, $zero, 0x0037         ## $t9 = 00000037
/* 00D3C 80B5C4EC A03903DC */  sb      $t9, 0x03DC($at)           ## 000103DC
/* 00D40 80B5C4F0 24080028 */  addiu   $t0, $zero, 0x0028         ## $t0 = 00000028
/* 00D44 80B5C4F4 24090002 */  addiu   $t1, $zero, 0x0002         ## $t1 = 00000002
/* 00D48 80B5C4F8 A6080212 */  sh      $t0, 0x0212($s0)           ## 00000212
/* 00D4C 80B5C4FC A2090208 */  sb      $t1, 0x0208($s0)           ## 00000208
.L80B5C500:
/* 00D50 80B5C500 10000115 */  beq     $zero, $zero, .L80B5C958   
/* 00D54 80B5C504 92020208 */  lbu     $v0, 0x0208($s0)           ## 00000208
glabel L80B5C508
/* 00D58 80B5C508 86020212 */  lh      $v0, 0x0212($s0)           ## 00000212
/* 00D5C 80B5C50C 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 00D60 80B5C510 24057030 */  addiu   $a1, $zero, 0x7030         ## $a1 = 00007030
/* 00D64 80B5C514 14400003 */  bne     $v0, $zero, .L80B5C524     
/* 00D68 80B5C518 244AFFFF */  addiu   $t2, $v0, 0xFFFF           ## $t2 = FFFFFFFF
/* 00D6C 80B5C51C 10000003 */  beq     $zero, $zero, .L80B5C52C   
/* 00D70 80B5C520 00001825 */  or      $v1, $zero, $zero          ## $v1 = 00000000
.L80B5C524:
/* 00D74 80B5C524 A60A0212 */  sh      $t2, 0x0212($s0)           ## 00000212
/* 00D78 80B5C528 86030212 */  lh      $v1, 0x0212($s0)           ## 00000212
.L80B5C52C:
/* 00D7C 80B5C52C 14600006 */  bne     $v1, $zero, .L80B5C548     
/* 00D80 80B5C530 00000000 */  nop
/* 00D84 80B5C534 0C042DA0 */  jal     func_8010B680              
/* 00D88 80B5C538 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 00D8C 80B5C53C 920B0208 */  lbu     $t3, 0x0208($s0)           ## 00000208
/* 00D90 80B5C540 256C0001 */  addiu   $t4, $t3, 0x0001           ## $t4 = 00000001
/* 00D94 80B5C544 A20C0208 */  sb      $t4, 0x0208($s0)           ## 00000208
.L80B5C548:
/* 00D98 80B5C548 10000103 */  beq     $zero, $zero, .L80B5C958   
/* 00D9C 80B5C54C 92020208 */  lbu     $v0, 0x0208($s0)           ## 00000208
glabel L80B5C550
/* 00DA0 80B5C550 0C042F6F */  jal     func_8010BDBC              
/* 00DA4 80B5C554 262420D8 */  addiu   $a0, $s1, 0x20D8           ## $a0 = 000020D8
/* 00DA8 80B5C558 24010004 */  addiu   $at, $zero, 0x0004         ## $at = 00000004
/* 00DAC 80B5C55C 14410005 */  bne     $v0, $at, .L80B5C574       
/* 00DB0 80B5C560 00000000 */  nop
/* 00DB4 80B5C564 0C041AF2 */  jal     func_80106BC8              
/* 00DB8 80B5C568 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 00DBC 80B5C56C 14400003 */  bne     $v0, $zero, .L80B5C57C     
/* 00DC0 80B5C570 3C0D0001 */  lui     $t5, 0x0001                ## $t5 = 00010000
.L80B5C574:
/* 00DC4 80B5C574 100000F8 */  beq     $zero, $zero, .L80B5C958   
/* 00DC8 80B5C578 92020208 */  lbu     $v0, 0x0208($s0)           ## 00000208
.L80B5C57C:
/* 00DCC 80B5C57C 01B16821 */  addu    $t5, $t5, $s1              
/* 00DD0 80B5C580 91AD04BD */  lbu     $t5, 0x04BD($t5)           ## 000104BD
/* 00DD4 80B5C584 24050004 */  addiu   $a1, $zero, 0x0004         ## $a1 = 00000004
/* 00DD8 80B5C588 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 00DDC 80B5C58C 15A00014 */  bne     $t5, $zero, .L80B5C5E0     
/* 00DE0 80B5C590 00000000 */  nop
/* 00DE4 80B5C594 0C2D6DEC */  jal     func_80B5B7B0              
/* 00DE8 80B5C598 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 00DEC 80B5C59C 3C0580B6 */  lui     $a1, %hi(D_80B5E7B8)       ## $a1 = 80B60000
/* 00DF0 80B5C5A0 24A5E7B8 */  addiu   $a1, $a1, %lo(D_80B5E7B8)  ## $a1 = 80B5E7B8
/* 00DF4 80B5C5A4 2604014C */  addiu   $a0, $s0, 0x014C           ## $a0 = 0000014C
/* 00DF8 80B5C5A8 0C00D3B0 */  jal     Actor_ChangeAnimation              
/* 00DFC 80B5C5AC 2406001C */  addiu   $a2, $zero, 0x001C         ## $a2 = 0000001C
/* 00E00 80B5C5B0 240E0005 */  addiu   $t6, $zero, 0x0005         ## $t6 = 00000005
/* 00E04 80B5C5B4 240F0001 */  addiu   $t7, $zero, 0x0001         ## $t7 = 00000001
/* 00E08 80B5C5B8 A6000210 */  sh      $zero, 0x0210($s0)         ## 00000210
/* 00E0C 80B5C5BC A20E020D */  sb      $t6, 0x020D($s0)           ## 0000020D
/* 00E10 80B5C5C0 A20F020E */  sb      $t7, 0x020E($s0)           ## 0000020E
/* 00E14 80B5C5C4 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 00E18 80B5C5C8 24057032 */  addiu   $a1, $zero, 0x7032         ## $a1 = 00007032
/* 00E1C 80B5C5CC 0C042DA0 */  jal     func_8010B680              
/* 00E20 80B5C5D0 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 00E24 80B5C5D4 24180007 */  addiu   $t8, $zero, 0x0007         ## $t8 = 00000007
/* 00E28 80B5C5D8 10000011 */  beq     $zero, $zero, .L80B5C620   
/* 00E2C 80B5C5DC A2180208 */  sb      $t8, 0x0208($s0)           ## 00000208
.L80B5C5E0:
/* 00E30 80B5C5E0 0C2D6DEC */  jal     func_80B5B7B0              
/* 00E34 80B5C5E4 24050002 */  addiu   $a1, $zero, 0x0002         ## $a1 = 00000002
/* 00E38 80B5C5E8 3C0580B6 */  lui     $a1, %hi(D_80B5E7B8)       ## $a1 = 80B60000
/* 00E3C 80B5C5EC 24A5E7B8 */  addiu   $a1, $a1, %lo(D_80B5E7B8)  ## $a1 = 80B5E7B8
/* 00E40 80B5C5F0 2604014C */  addiu   $a0, $s0, 0x014C           ## $a0 = 0000014C
/* 00E44 80B5C5F4 0C00D3B0 */  jal     Actor_ChangeAnimation              
/* 00E48 80B5C5F8 24060009 */  addiu   $a2, $zero, 0x0009         ## $a2 = 00000009
/* 00E4C 80B5C5FC 24190002 */  addiu   $t9, $zero, 0x0002         ## $t9 = 00000002
/* 00E50 80B5C600 A219020E */  sb      $t9, 0x020E($s0)           ## 0000020E
/* 00E54 80B5C604 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 00E58 80B5C608 24057031 */  addiu   $a1, $zero, 0x7031         ## $a1 = 00007031
/* 00E5C 80B5C60C 0C042DA0 */  jal     func_8010B680              
/* 00E60 80B5C610 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 00E64 80B5C614 92080208 */  lbu     $t0, 0x0208($s0)           ## 00000208
/* 00E68 80B5C618 25090001 */  addiu   $t1, $t0, 0x0001           ## $t1 = 00000001
/* 00E6C 80B5C61C A2090208 */  sb      $t1, 0x0208($s0)           ## 00000208
.L80B5C620:
/* 00E70 80B5C620 100000CD */  beq     $zero, $zero, .L80B5C958   
/* 00E74 80B5C624 92020208 */  lbu     $v0, 0x0208($s0)           ## 00000208
glabel L80B5C628
/* 00E78 80B5C628 3C014180 */  lui     $at, 0x4180                ## $at = 41800000
/* 00E7C 80B5C62C 44812000 */  mtc1    $at, $f4                   ## $f4 = 16.00
/* 00E80 80B5C630 C6060164 */  lwc1    $f6, 0x0164($s0)           ## 00000164
/* 00E84 80B5C634 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00E88 80B5C638 46062032 */  c.eq.s  $f4, $f6                   
/* 00E8C 80B5C63C 00000000 */  nop
/* 00E90 80B5C640 45020004 */  bc1fl   .L80B5C654                 
/* 00E94 80B5C644 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00E98 80B5C648 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 00E9C 80B5C64C 2405686B */  addiu   $a1, $zero, 0x686B         ## $a1 = 0000686B
/* 00EA0 80B5C650 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
.L80B5C654:
/* 00EA4 80B5C654 0C2D6FE4 */  jal     func_80B5BF90              
/* 00EA8 80B5C658 2405000A */  addiu   $a1, $zero, 0x000A         ## $a1 = 0000000A
/* 00EAC 80B5C65C 10400004 */  beq     $v0, $zero, .L80B5C670     
/* 00EB0 80B5C660 00000000 */  nop
/* 00EB4 80B5C664 920A0208 */  lbu     $t2, 0x0208($s0)           ## 00000208
/* 00EB8 80B5C668 254B0001 */  addiu   $t3, $t2, 0x0001           ## $t3 = 00000001
/* 00EBC 80B5C66C A20B0208 */  sb      $t3, 0x0208($s0)           ## 00000208
glabel L80B5C670
.L80B5C670:
/* 00EC0 80B5C670 0C042F6F */  jal     func_8010BDBC              
/* 00EC4 80B5C674 262420D8 */  addiu   $a0, $s1, 0x20D8           ## $a0 = 000020D8
/* 00EC8 80B5C678 24010005 */  addiu   $at, $zero, 0x0005         ## $at = 00000005
/* 00ECC 80B5C67C 14410013 */  bne     $v0, $at, .L80B5C6CC       
/* 00ED0 80B5C680 00000000 */  nop
/* 00ED4 80B5C684 0C041AF2 */  jal     func_80106BC8              
/* 00ED8 80B5C688 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 00EDC 80B5C68C 1040000F */  beq     $v0, $zero, .L80B5C6CC     
/* 00EE0 80B5C690 240C0037 */  addiu   $t4, $zero, 0x0037         ## $t4 = 00000037
/* 00EE4 80B5C694 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 00EE8 80B5C698 00310821 */  addu    $at, $at, $s1              
/* 00EEC 80B5C69C 3C0580B6 */  lui     $a1, %hi(D_80B5E7B8)       ## $a1 = 80B60000
/* 00EF0 80B5C6A0 A02C03DC */  sb      $t4, 0x03DC($at)           ## 000103DC
/* 00EF4 80B5C6A4 24A5E7B8 */  addiu   $a1, $a1, %lo(D_80B5E7B8)  ## $a1 = 80B5E7B8
/* 00EF8 80B5C6A8 2604014C */  addiu   $a0, $s0, 0x014C           ## $a0 = 0000014C
/* 00EFC 80B5C6AC 0C00D3B0 */  jal     Actor_ChangeAnimation              
/* 00F00 80B5C6B0 24060009 */  addiu   $a2, $zero, 0x0009         ## $a2 = 00000009
/* 00F04 80B5C6B4 240D0002 */  addiu   $t5, $zero, 0x0002         ## $t5 = 00000002
/* 00F08 80B5C6B8 A20D020E */  sb      $t5, 0x020E($s0)           ## 0000020E
/* 00F0C 80B5C6BC 0C2D6FF9 */  jal     func_80B5BFE4              
/* 00F10 80B5C6C0 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00F14 80B5C6C4 240E0006 */  addiu   $t6, $zero, 0x0006         ## $t6 = 00000006
/* 00F18 80B5C6C8 A20E0208 */  sb      $t6, 0x0208($s0)           ## 00000208
.L80B5C6CC:
/* 00F1C 80B5C6CC 100000A2 */  beq     $zero, $zero, .L80B5C958   
/* 00F20 80B5C6D0 92020208 */  lbu     $v0, 0x0208($s0)           ## 00000208
glabel L80B5C6D4
/* 00F24 80B5C6D4 A200020E */  sb      $zero, 0x020E($s0)         ## 0000020E
/* 00F28 80B5C6D8 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 00F2C 80B5C6DC 0C2D6DEC */  jal     func_80B5B7B0              
/* 00F30 80B5C6E0 24050003 */  addiu   $a1, $zero, 0x0003         ## $a1 = 00000003
/* 00F34 80B5C6E4 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 00F38 80B5C6E8 24057030 */  addiu   $a1, $zero, 0x7030         ## $a1 = 00007030
/* 00F3C 80B5C6EC 0C042DA0 */  jal     func_8010B680              
/* 00F40 80B5C6F0 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 00F44 80B5C6F4 240F000C */  addiu   $t7, $zero, 0x000C         ## $t7 = 0000000C
/* 00F48 80B5C6F8 A20F0208 */  sb      $t7, 0x0208($s0)           ## 00000208
/* 00F4C 80B5C6FC 10000096 */  beq     $zero, $zero, .L80B5C958   
/* 00F50 80B5C700 31E200FF */  andi    $v0, $t7, 0x00FF           ## $v0 = 0000000C
glabel L80B5C704
/* 00F54 80B5C704 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00F58 80B5C708 0C2D6FE4 */  jal     func_80B5BF90              
/* 00F5C 80B5C70C 24050019 */  addiu   $a1, $zero, 0x0019         ## $a1 = 00000019
/* 00F60 80B5C710 10400002 */  beq     $v0, $zero, .L80B5C71C     
/* 00F64 80B5C714 2418000D */  addiu   $t8, $zero, 0x000D         ## $t8 = 0000000D
/* 00F68 80B5C718 A2180208 */  sb      $t8, 0x0208($s0)           ## 00000208
glabel L80B5C71C
.L80B5C71C:
/* 00F6C 80B5C71C 0C042F6F */  jal     func_8010BDBC              
/* 00F70 80B5C720 262420D8 */  addiu   $a0, $s1, 0x20D8           ## $a0 = 000020D8
/* 00F74 80B5C724 24010004 */  addiu   $at, $zero, 0x0004         ## $at = 00000004
/* 00F78 80B5C728 14410005 */  bne     $v0, $at, .L80B5C740       
/* 00F7C 80B5C72C 00000000 */  nop
/* 00F80 80B5C730 0C041AF2 */  jal     func_80106BC8              
/* 00F84 80B5C734 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 00F88 80B5C738 14400003 */  bne     $v0, $zero, .L80B5C748     
/* 00F8C 80B5C73C 3C190001 */  lui     $t9, 0x0001                ## $t9 = 00010000
.L80B5C740:
/* 00F90 80B5C740 10000085 */  beq     $zero, $zero, .L80B5C958   
/* 00F94 80B5C744 92020208 */  lbu     $v0, 0x0208($s0)           ## 00000208
.L80B5C748:
/* 00F98 80B5C748 0331C821 */  addu    $t9, $t9, $s1              
/* 00F9C 80B5C74C 933904BD */  lbu     $t9, 0x04BD($t9)           ## 000104BD
/* 00FA0 80B5C750 24050004 */  addiu   $a1, $zero, 0x0004         ## $a1 = 00000004
/* 00FA4 80B5C754 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 00FA8 80B5C758 17200014 */  bne     $t9, $zero, .L80B5C7AC     
/* 00FAC 80B5C75C 00000000 */  nop
/* 00FB0 80B5C760 0C2D6DEC */  jal     func_80B5B7B0              
/* 00FB4 80B5C764 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 00FB8 80B5C768 3C0580B6 */  lui     $a1, %hi(D_80B5E7B8)       ## $a1 = 80B60000
/* 00FBC 80B5C76C 24A5E7B8 */  addiu   $a1, $a1, %lo(D_80B5E7B8)  ## $a1 = 80B5E7B8
/* 00FC0 80B5C770 2604014C */  addiu   $a0, $s0, 0x014C           ## $a0 = 0000014C
/* 00FC4 80B5C774 0C00D3B0 */  jal     Actor_ChangeAnimation              
/* 00FC8 80B5C778 2406001C */  addiu   $a2, $zero, 0x001C         ## $a2 = 0000001C
/* 00FCC 80B5C77C 24080005 */  addiu   $t0, $zero, 0x0005         ## $t0 = 00000005
/* 00FD0 80B5C780 24090001 */  addiu   $t1, $zero, 0x0001         ## $t1 = 00000001
/* 00FD4 80B5C784 A6000210 */  sh      $zero, 0x0210($s0)         ## 00000210
/* 00FD8 80B5C788 A208020D */  sb      $t0, 0x020D($s0)           ## 0000020D
/* 00FDC 80B5C78C A209020E */  sb      $t1, 0x020E($s0)           ## 0000020E
/* 00FE0 80B5C790 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 00FE4 80B5C794 24057032 */  addiu   $a1, $zero, 0x7032         ## $a1 = 00007032
/* 00FE8 80B5C798 0C042DA0 */  jal     func_8010B680              
/* 00FEC 80B5C79C 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 00FF0 80B5C7A0 240A0007 */  addiu   $t2, $zero, 0x0007         ## $t2 = 00000007
/* 00FF4 80B5C7A4 10000010 */  beq     $zero, $zero, .L80B5C7E8   
/* 00FF8 80B5C7A8 A20A0208 */  sb      $t2, 0x0208($s0)           ## 00000208
.L80B5C7AC:
/* 00FFC 80B5C7AC 0C2D6DEC */  jal     func_80B5B7B0              
/* 01000 80B5C7B0 24050002 */  addiu   $a1, $zero, 0x0002         ## $a1 = 00000002
/* 01004 80B5C7B4 3C0580B6 */  lui     $a1, %hi(D_80B5E7B8)       ## $a1 = 80B60000
/* 01008 80B5C7B8 24A5E7B8 */  addiu   $a1, $a1, %lo(D_80B5E7B8)  ## $a1 = 80B5E7B8
/* 0100C 80B5C7BC 2604014C */  addiu   $a0, $s0, 0x014C           ## $a0 = 0000014C
/* 01010 80B5C7C0 0C00D3B0 */  jal     Actor_ChangeAnimation              
/* 01014 80B5C7C4 24060009 */  addiu   $a2, $zero, 0x0009         ## $a2 = 00000009
/* 01018 80B5C7C8 240B0002 */  addiu   $t3, $zero, 0x0002         ## $t3 = 00000002
/* 0101C 80B5C7CC A20B020E */  sb      $t3, 0x020E($s0)           ## 0000020E
/* 01020 80B5C7D0 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 01024 80B5C7D4 24057031 */  addiu   $a1, $zero, 0x7031         ## $a1 = 00007031
/* 01028 80B5C7D8 0C042DA0 */  jal     func_8010B680              
/* 0102C 80B5C7DC 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 01030 80B5C7E0 240C0004 */  addiu   $t4, $zero, 0x0004         ## $t4 = 00000004
/* 01034 80B5C7E4 A20C0208 */  sb      $t4, 0x0208($s0)           ## 00000208
.L80B5C7E8:
/* 01038 80B5C7E8 1000005B */  beq     $zero, $zero, .L80B5C958   
/* 0103C 80B5C7EC 92020208 */  lbu     $v0, 0x0208($s0)           ## 00000208
glabel L80B5C7F0
/* 01040 80B5C7F0 3C014188 */  lui     $at, 0x4188                ## $at = 41880000
/* 01044 80B5C7F4 44814000 */  mtc1    $at, $f8                   ## $f8 = 17.00
/* 01048 80B5C7F8 C60A0164 */  lwc1    $f10, 0x0164($s0)          ## 00000164
/* 0104C 80B5C7FC 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01050 80B5C800 460A4032 */  c.eq.s  $f8, $f10                  
/* 01054 80B5C804 00000000 */  nop
/* 01058 80B5C808 45020004 */  bc1fl   .L80B5C81C                 
/* 0105C 80B5C80C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01060 80B5C810 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 01064 80B5C814 2405686D */  addiu   $a1, $zero, 0x686D         ## $a1 = 0000686D
/* 01068 80B5C818 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
.L80B5C81C:
/* 0106C 80B5C81C 0C2D6FE4 */  jal     func_80B5BF90              
/* 01070 80B5C820 2405001D */  addiu   $a1, $zero, 0x001D         ## $a1 = 0000001D
/* 01074 80B5C824 10400004 */  beq     $v0, $zero, .L80B5C838     
/* 01078 80B5C828 00000000 */  nop
/* 0107C 80B5C82C 920D0208 */  lbu     $t5, 0x0208($s0)           ## 00000208
/* 01080 80B5C830 25AE0001 */  addiu   $t6, $t5, 0x0001           ## $t6 = 00000001
/* 01084 80B5C834 A20E0208 */  sb      $t6, 0x0208($s0)           ## 00000208
glabel L80B5C838
.L80B5C838:
/* 01088 80B5C838 0C042F6F */  jal     func_8010BDBC              
/* 0108C 80B5C83C 262420D8 */  addiu   $a0, $s1, 0x20D8           ## $a0 = 000020D8
/* 01090 80B5C840 24010005 */  addiu   $at, $zero, 0x0005         ## $at = 00000005
/* 01094 80B5C844 14410015 */  bne     $v0, $at, .L80B5C89C       
/* 01098 80B5C848 00000000 */  nop
/* 0109C 80B5C84C 0C041AF2 */  jal     func_80106BC8              
/* 010A0 80B5C850 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 010A4 80B5C854 10400011 */  beq     $v0, $zero, .L80B5C89C     
/* 010A8 80B5C858 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 010AC 80B5C85C 0C2D6E22 */  jal     func_80B5B888              
/* 010B0 80B5C860 24050002 */  addiu   $a1, $zero, 0x0002         ## $a1 = 00000002
/* 010B4 80B5C864 3C0580B6 */  lui     $a1, %hi(D_80B5E7B8)       ## $a1 = 80B60000
/* 010B8 80B5C868 24A5E7B8 */  addiu   $a1, $a1, %lo(D_80B5E7B8)  ## $a1 = 80B5E7B8
/* 010BC 80B5C86C 2604014C */  addiu   $a0, $s0, 0x014C           ## $a0 = 0000014C
/* 010C0 80B5C870 0C00D3B0 */  jal     Actor_ChangeAnimation              
/* 010C4 80B5C874 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 010C8 80B5C878 A6000210 */  sh      $zero, 0x0210($s0)         ## 00000210
/* 010CC 80B5C87C A200020D */  sb      $zero, 0x020D($s0)         ## 0000020D
/* 010D0 80B5C880 A200020E */  sb      $zero, 0x020E($s0)         ## 0000020E
/* 010D4 80B5C884 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 010D8 80B5C888 240570FC */  addiu   $a1, $zero, 0x70FC         ## $a1 = 000070FC
/* 010DC 80B5C88C 0C042DA0 */  jal     func_8010B680              
/* 010E0 80B5C890 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 010E4 80B5C894 240F0009 */  addiu   $t7, $zero, 0x0009         ## $t7 = 00000009
/* 010E8 80B5C898 A20F0208 */  sb      $t7, 0x0208($s0)           ## 00000208
.L80B5C89C:
/* 010EC 80B5C89C 1000002E */  beq     $zero, $zero, .L80B5C958   
/* 010F0 80B5C8A0 92020208 */  lbu     $v0, 0x0208($s0)           ## 00000208
glabel L80B5C8A4
/* 010F4 80B5C8A4 0C042F6F */  jal     func_8010BDBC              
/* 010F8 80B5C8A8 262420D8 */  addiu   $a0, $s1, 0x20D8           ## $a0 = 000020D8
/* 010FC 80B5C8AC 24010005 */  addiu   $at, $zero, 0x0005         ## $at = 00000005
/* 01100 80B5C8B0 1441000E */  bne     $v0, $at, .L80B5C8EC       
/* 01104 80B5C8B4 00000000 */  nop
/* 01108 80B5C8B8 0C041AF2 */  jal     func_80106BC8              
/* 0110C 80B5C8BC 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 01110 80B5C8C0 1040000A */  beq     $v0, $zero, .L80B5C8EC     
/* 01114 80B5C8C4 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 01118 80B5C8C8 0C2D6DEC */  jal     func_80B5B7B0              
/* 0111C 80B5C8CC 24050005 */  addiu   $a1, $zero, 0x0005         ## $a1 = 00000005
/* 01120 80B5C8D0 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 01124 80B5C8D4 240570FD */  addiu   $a1, $zero, 0x70FD         ## $a1 = 000070FD
/* 01128 80B5C8D8 0C042DA0 */  jal     func_8010B680              
/* 0112C 80B5C8DC 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 01130 80B5C8E0 92180208 */  lbu     $t8, 0x0208($s0)           ## 00000208
/* 01134 80B5C8E4 27190001 */  addiu   $t9, $t8, 0x0001           ## $t9 = 00000001
/* 01138 80B5C8E8 A2190208 */  sb      $t9, 0x0208($s0)           ## 00000208
.L80B5C8EC:
/* 0113C 80B5C8EC 1000001A */  beq     $zero, $zero, .L80B5C958   
/* 01140 80B5C8F0 92020208 */  lbu     $v0, 0x0208($s0)           ## 00000208
glabel L80B5C8F4
/* 01144 80B5C8F4 0C042F6F */  jal     func_8010BDBC              
/* 01148 80B5C8F8 262420D8 */  addiu   $a0, $s1, 0x20D8           ## $a0 = 000020D8
/* 0114C 80B5C8FC 24010005 */  addiu   $at, $zero, 0x0005         ## $at = 00000005
/* 01150 80B5C900 54410015 */  bnel    $v0, $at, .L80B5C958       
/* 01154 80B5C904 92020208 */  lbu     $v0, 0x0208($s0)           ## 00000208
/* 01158 80B5C908 0C041AF2 */  jal     func_80106BC8              
/* 0115C 80B5C90C 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 01160 80B5C910 10400010 */  beq     $v0, $zero, .L80B5C954     
/* 01164 80B5C914 2604014C */  addiu   $a0, $s0, 0x014C           ## $a0 = 0000014C
/* 01168 80B5C918 3C0580B6 */  lui     $a1, %hi(D_80B5E7B8)       ## $a1 = 80B60000
/* 0116C 80B5C91C 24A5E7B8 */  addiu   $a1, $a1, %lo(D_80B5E7B8)  ## $a1 = 80B5E7B8
/* 01170 80B5C920 0C00D3B0 */  jal     Actor_ChangeAnimation              
/* 01174 80B5C924 24060005 */  addiu   $a2, $zero, 0x0005         ## $a2 = 00000005
/* 01178 80B5C928 24080006 */  addiu   $t0, $zero, 0x0006         ## $t0 = 00000006
/* 0117C 80B5C92C 24090003 */  addiu   $t1, $zero, 0x0003         ## $t1 = 00000003
/* 01180 80B5C930 A208020D */  sb      $t0, 0x020D($s0)           ## 0000020D
/* 01184 80B5C934 A209020E */  sb      $t1, 0x020E($s0)           ## 0000020E
/* 01188 80B5C938 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 0118C 80B5C93C 240570FE */  addiu   $a1, $zero, 0x70FE         ## $a1 = 000070FE
/* 01190 80B5C940 0C042DA0 */  jal     func_8010B680              
/* 01194 80B5C944 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 01198 80B5C948 920A0208 */  lbu     $t2, 0x0208($s0)           ## 00000208
/* 0119C 80B5C94C 254B0001 */  addiu   $t3, $t2, 0x0001           ## $t3 = 00000001
/* 011A0 80B5C950 A20B0208 */  sb      $t3, 0x0208($s0)           ## 00000208
.L80B5C954:
/* 011A4 80B5C954 92020208 */  lbu     $v0, 0x0208($s0)           ## 00000208
glabel L80B5C958
.L80B5C958:
/* 011A8 80B5C958 2401000B */  addiu   $at, $zero, 0x000B         ## $at = 0000000B
/* 011AC 80B5C95C 14410003 */  bne     $v0, $at, .L80B5C96C       
/* 011B0 80B5C960 8FB00014 */  lw      $s0, 0x0014($sp)           
/* 011B4 80B5C964 10000002 */  beq     $zero, $zero, .L80B5C970   
/* 011B8 80B5C968 24030001 */  addiu   $v1, $zero, 0x0001         ## $v1 = 00000001
.L80B5C96C:
/* 011BC 80B5C96C 00001825 */  or      $v1, $zero, $zero          ## $v1 = 00000000
.L80B5C970:
/* 011C0 80B5C970 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 011C4 80B5C974 8FB10018 */  lw      $s1, 0x0018($sp)           
/* 011C8 80B5C978 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 011CC 80B5C97C 03E00008 */  jr      $ra                        
/* 011D0 80B5C980 00601025 */  or      $v0, $v1, $zero            ## $v0 = 00000000
