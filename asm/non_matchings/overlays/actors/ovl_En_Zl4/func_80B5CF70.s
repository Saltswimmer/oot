.late_rodata
glabel jtbl_80B5FC58
.word L80B5CFBC
.word L80B5CFFC
.word L80B5D04C
.word L80B5D09C
.word L80B5D0CC
.word L80B5D178
.word L80B5D198
.word L80B5D1F4
.word L80B5D238
.word L80B5D278
.word L80B5D2D0
.word L80B5D2F0
.word L80B5D364

.text
glabel func_80B5CF70
/* 017C0 80B5CF70 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 017C4 80B5CF74 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 017C8 80B5CF78 AFB10018 */  sw      $s1, 0x0018($sp)           
/* 017CC 80B5CF7C AFB00014 */  sw      $s0, 0x0014($sp)           
/* 017D0 80B5CF80 84AE07A0 */  lh      $t6, 0x07A0($a1)           ## 000007A0
/* 017D4 80B5CF84 90820208 */  lbu     $v0, 0x0208($a0)           ## 00000208
/* 017D8 80B5CF88 00A08025 */  or      $s0, $a1, $zero            ## $s0 = 00000000
/* 017DC 80B5CF8C 000E7880 */  sll     $t7, $t6,  2               
/* 017E0 80B5CF90 00AFC021 */  addu    $t8, $a1, $t7              
/* 017E4 80B5CF94 2C41000D */  sltiu   $at, $v0, 0x000D           
/* 017E8 80B5CF98 00808825 */  or      $s1, $a0, $zero            ## $s1 = 00000000
/* 017EC 80B5CF9C 10200100 */  beq     $at, $zero, .L80B5D3A0     
/* 017F0 80B5CFA0 8F030790 */  lw      $v1, 0x0790($t8)           ## 00000790
/* 017F4 80B5CFA4 0002C880 */  sll     $t9, $v0,  2               
/* 017F8 80B5CFA8 3C0180B6 */  lui     $at, %hi(jtbl_80B5FC58)       ## $at = 80B60000
/* 017FC 80B5CFAC 00390821 */  addu    $at, $at, $t9              
/* 01800 80B5CFB0 8C39FC58 */  lw      $t9, %lo(jtbl_80B5FC58)($at)  
/* 01804 80B5CFB4 03200008 */  jr      $t9                        
/* 01808 80B5CFB8 00000000 */  nop
glabel L80B5CFBC
/* 0180C 80B5CFBC 86280214 */  lh      $t0, 0x0214($s1)           ## 00000214
/* 01810 80B5CFC0 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01814 80B5CFC4 24057037 */  addiu   $a1, $zero, 0x7037         ## $a1 = 00007037
/* 01818 80B5CFC8 25090001 */  addiu   $t1, $t0, 0x0001           ## $t1 = 00000001
/* 0181C 80B5CFCC A6290214 */  sh      $t1, 0x0214($s1)           ## 00000214
/* 01820 80B5CFD0 862A0214 */  lh      $t2, 0x0214($s1)           ## 00000214
/* 01824 80B5CFD4 2941003C */  slti    $at, $t2, 0x003C           
/* 01828 80B5CFD8 14200006 */  bne     $at, $zero, .L80B5CFF4     
/* 0182C 80B5CFDC 00000000 */  nop
/* 01830 80B5CFE0 0C042DA0 */  jal     func_8010B680              
/* 01834 80B5CFE4 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 01838 80B5CFE8 922B0208 */  lbu     $t3, 0x0208($s1)           ## 00000208
/* 0183C 80B5CFEC 256C0001 */  addiu   $t4, $t3, 0x0001           ## $t4 = 00000001
/* 01840 80B5CFF0 A22C0208 */  sb      $t4, 0x0208($s1)           ## 00000208
.L80B5CFF4:
/* 01844 80B5CFF4 100000EA */  beq     $zero, $zero, .L80B5D3A0   
/* 01848 80B5CFF8 92220208 */  lbu     $v0, 0x0208($s1)           ## 00000208
glabel L80B5CFFC
/* 0184C 80B5CFFC 0C042F6F */  jal     func_8010BDBC              
/* 01850 80B5D000 260420D8 */  addiu   $a0, $s0, 0x20D8           ## $a0 = 000020D8
/* 01854 80B5D004 24010005 */  addiu   $at, $zero, 0x0005         ## $at = 00000005
/* 01858 80B5D008 1441000E */  bne     $v0, $at, .L80B5D044       
/* 0185C 80B5D00C 00000000 */  nop
/* 01860 80B5D010 0C041AF2 */  jal     func_80106BC8              
/* 01864 80B5D014 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01868 80B5D018 1040000A */  beq     $v0, $zero, .L80B5D044     
/* 0186C 80B5D01C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01870 80B5D020 0C2D6DEC */  jal     func_80B5B7B0              
/* 01874 80B5D024 24050007 */  addiu   $a1, $zero, 0x0007         ## $a1 = 00000007
/* 01878 80B5D028 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0187C 80B5D02C 24052076 */  addiu   $a1, $zero, 0x2076         ## $a1 = 00002076
/* 01880 80B5D030 0C042DA0 */  jal     func_8010B680              
/* 01884 80B5D034 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 01888 80B5D038 922D0208 */  lbu     $t5, 0x0208($s1)           ## 00000208
/* 0188C 80B5D03C 25AE0001 */  addiu   $t6, $t5, 0x0001           ## $t6 = 00000001
/* 01890 80B5D040 A22E0208 */  sb      $t6, 0x0208($s1)           ## 00000208
.L80B5D044:
/* 01894 80B5D044 100000D6 */  beq     $zero, $zero, .L80B5D3A0   
/* 01898 80B5D048 92220208 */  lbu     $v0, 0x0208($s1)           ## 00000208
glabel L80B5D04C
/* 0189C 80B5D04C 0C042F6F */  jal     func_8010BDBC              
/* 018A0 80B5D050 260420D8 */  addiu   $a0, $s0, 0x20D8           ## $a0 = 000020D8
/* 018A4 80B5D054 24010005 */  addiu   $at, $zero, 0x0005         ## $at = 00000005
/* 018A8 80B5D058 1441000E */  bne     $v0, $at, .L80B5D094       
/* 018AC 80B5D05C 00000000 */  nop
/* 018B0 80B5D060 0C041AF2 */  jal     func_80106BC8              
/* 018B4 80B5D064 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 018B8 80B5D068 1040000A */  beq     $v0, $zero, .L80B5D094     
/* 018BC 80B5D06C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 018C0 80B5D070 0C2D6E22 */  jal     func_80B5B888              
/* 018C4 80B5D074 24050006 */  addiu   $a1, $zero, 0x0006         ## $a1 = 00000006
/* 018C8 80B5D078 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 018CC 80B5D07C 00300821 */  addu    $at, $at, $s0              
/* 018D0 80B5D080 240F0037 */  addiu   $t7, $zero, 0x0037         ## $t7 = 00000037
/* 018D4 80B5D084 A02F03DC */  sb      $t7, 0x03DC($at)           ## 000103DC
/* 018D8 80B5D088 92380208 */  lbu     $t8, 0x0208($s1)           ## 00000208
/* 018DC 80B5D08C 27190001 */  addiu   $t9, $t8, 0x0001           ## $t9 = 00000001
/* 018E0 80B5D090 A2390208 */  sb      $t9, 0x0208($s1)           ## 00000208
.L80B5D094:
/* 018E4 80B5D094 100000C2 */  beq     $zero, $zero, .L80B5D3A0   
/* 018E8 80B5D098 92220208 */  lbu     $v0, 0x0208($s1)           ## 00000208
glabel L80B5D09C
/* 018EC 80B5D09C 8468015E */  lh      $t0, 0x015E($v1)           ## 0000015E
/* 018F0 80B5D0A0 24010002 */  addiu   $at, $zero, 0x0002         ## $at = 00000002
/* 018F4 80B5D0A4 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 018F8 80B5D0A8 150100BD */  bne     $t0, $at, .L80B5D3A0       
/* 018FC 80B5D0AC 24052077 */  addiu   $a1, $zero, 0x2077         ## $a1 = 00002077
/* 01900 80B5D0B0 0C042DA0 */  jal     func_8010B680              
/* 01904 80B5D0B4 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 01908 80B5D0B8 92290208 */  lbu     $t1, 0x0208($s1)           ## 00000208
/* 0190C 80B5D0BC 252A0001 */  addiu   $t2, $t1, 0x0001           ## $t2 = 00000001
/* 01910 80B5D0C0 A22A0208 */  sb      $t2, 0x0208($s1)           ## 00000208
/* 01914 80B5D0C4 100000B6 */  beq     $zero, $zero, .L80B5D3A0   
/* 01918 80B5D0C8 314200FF */  andi    $v0, $t2, 0x00FF           ## $v0 = 00000001
glabel L80B5D0CC
/* 0191C 80B5D0CC 0C042F6F */  jal     func_8010BDBC              
/* 01920 80B5D0D0 260420D8 */  addiu   $a0, $s0, 0x20D8           ## $a0 = 000020D8
/* 01924 80B5D0D4 24010004 */  addiu   $at, $zero, 0x0004         ## $at = 00000004
/* 01928 80B5D0D8 14410005 */  bne     $v0, $at, .L80B5D0F0       
/* 0192C 80B5D0DC 00000000 */  nop
/* 01930 80B5D0E0 0C041AF2 */  jal     func_80106BC8              
/* 01934 80B5D0E4 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01938 80B5D0E8 14400003 */  bne     $v0, $zero, .L80B5D0F8     
/* 0193C 80B5D0EC 3C0B0001 */  lui     $t3, 0x0001                ## $t3 = 00010000
.L80B5D0F0:
/* 01940 80B5D0F0 100000AB */  beq     $zero, $zero, .L80B5D3A0   
/* 01944 80B5D0F4 92220208 */  lbu     $v0, 0x0208($s1)           ## 00000208
.L80B5D0F8:
/* 01948 80B5D0F8 01705821 */  addu    $t3, $t3, $s0              
/* 0194C 80B5D0FC 916B04BD */  lbu     $t3, 0x04BD($t3)           ## 000104BD
/* 01950 80B5D100 3C0580B6 */  lui     $a1, %hi(D_80B5E7B8)       ## $a1 = 80B60000
/* 01954 80B5D104 24A5E7B8 */  addiu   $a1, $a1, %lo(D_80B5E7B8)  ## $a1 = 80B5E7B8
/* 01958 80B5D108 1560000B */  bne     $t3, $zero, .L80B5D138     
/* 0195C 80B5D10C 2624014C */  addiu   $a0, $s1, 0x014C           ## $a0 = 0000014C
/* 01960 80B5D110 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01964 80B5D114 0C2D6DEC */  jal     func_80B5B7B0              
/* 01968 80B5D118 24050008 */  addiu   $a1, $zero, 0x0008         ## $a1 = 00000008
/* 0196C 80B5D11C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01970 80B5D120 24057005 */  addiu   $a1, $zero, 0x7005         ## $a1 = 00007005
/* 01974 80B5D124 0C042DA0 */  jal     func_8010B680              
/* 01978 80B5D128 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 0197C 80B5D12C 240C0009 */  addiu   $t4, $zero, 0x0009         ## $t4 = 00000009
/* 01980 80B5D130 1000000F */  beq     $zero, $zero, .L80B5D170   
/* 01984 80B5D134 A22C0208 */  sb      $t4, 0x0208($s1)           ## 00000208
.L80B5D138:
/* 01988 80B5D138 0C00D3B0 */  jal     Actor_ChangeAnimation              
/* 0198C 80B5D13C 24060005 */  addiu   $a2, $zero, 0x0005         ## $a2 = 00000005
/* 01990 80B5D140 240D0003 */  addiu   $t5, $zero, 0x0003         ## $t5 = 00000003
/* 01994 80B5D144 A22D020E */  sb      $t5, 0x020E($s1)           ## 0000020E
/* 01998 80B5D148 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0199C 80B5D14C 24057038 */  addiu   $a1, $zero, 0x7038         ## $a1 = 00007038
/* 019A0 80B5D150 0C042DA0 */  jal     func_8010B680              
/* 019A4 80B5D154 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 019A8 80B5D158 922E0208 */  lbu     $t6, 0x0208($s1)           ## 00000208
/* 019AC 80B5D15C 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 019B0 80B5D160 24056869 */  addiu   $a1, $zero, 0x6869         ## $a1 = 00006869
/* 019B4 80B5D164 25CF0001 */  addiu   $t7, $t6, 0x0001           ## $t7 = 00000001
/* 019B8 80B5D168 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 019BC 80B5D16C A22F0208 */  sb      $t7, 0x0208($s1)           ## 00000208
.L80B5D170:
/* 019C0 80B5D170 1000008B */  beq     $zero, $zero, .L80B5D3A0   
/* 019C4 80B5D174 92220208 */  lbu     $v0, 0x0208($s1)           ## 00000208
glabel L80B5D178
/* 019C8 80B5D178 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 019CC 80B5D17C 0C2D6FE4 */  jal     func_80B5BF90              
/* 019D0 80B5D180 24050004 */  addiu   $a1, $zero, 0x0004         ## $a1 = 00000004
/* 019D4 80B5D184 10400004 */  beq     $v0, $zero, .L80B5D198     
/* 019D8 80B5D188 00000000 */  nop
/* 019DC 80B5D18C 92380208 */  lbu     $t8, 0x0208($s1)           ## 00000208
/* 019E0 80B5D190 27190001 */  addiu   $t9, $t8, 0x0001           ## $t9 = 00000001
/* 019E4 80B5D194 A2390208 */  sb      $t9, 0x0208($s1)           ## 00000208
glabel L80B5D198
.L80B5D198:
/* 019E8 80B5D198 0C042F6F */  jal     func_8010BDBC              
/* 019EC 80B5D19C 260420D8 */  addiu   $a0, $s0, 0x20D8           ## $a0 = 000020D8
/* 019F0 80B5D1A0 24010005 */  addiu   $at, $zero, 0x0005         ## $at = 00000005
/* 019F4 80B5D1A4 14410011 */  bne     $v0, $at, .L80B5D1EC       
/* 019F8 80B5D1A8 00000000 */  nop
/* 019FC 80B5D1AC 0C041AF2 */  jal     func_80106BC8              
/* 01A00 80B5D1B0 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01A04 80B5D1B4 1040000D */  beq     $v0, $zero, .L80B5D1EC     
/* 01A08 80B5D1B8 2624014C */  addiu   $a0, $s1, 0x014C           ## $a0 = 0000014C
/* 01A0C 80B5D1BC 3C0580B6 */  lui     $a1, %hi(D_80B5E7B8)       ## $a1 = 80B60000
/* 01A10 80B5D1C0 24A5E7B8 */  addiu   $a1, $a1, %lo(D_80B5E7B8)  ## $a1 = 80B5E7B8
/* 01A14 80B5D1C4 0C00D3B0 */  jal     Actor_ChangeAnimation              
/* 01A18 80B5D1C8 24060021 */  addiu   $a2, $zero, 0x0021         ## $a2 = 00000021
/* 01A1C 80B5D1CC A220020E */  sb      $zero, 0x020E($s1)         ## 0000020E
/* 01A20 80B5D1D0 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01A24 80B5D1D4 24057037 */  addiu   $a1, $zero, 0x7037         ## $a1 = 00007037
/* 01A28 80B5D1D8 0C042DA0 */  jal     func_8010B680              
/* 01A2C 80B5D1DC 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 01A30 80B5D1E0 92280208 */  lbu     $t0, 0x0208($s1)           ## 00000208
/* 01A34 80B5D1E4 25090001 */  addiu   $t1, $t0, 0x0001           ## $t1 = 00000001
/* 01A38 80B5D1E8 A2290208 */  sb      $t1, 0x0208($s1)           ## 00000208
.L80B5D1EC:
/* 01A3C 80B5D1EC 1000006C */  beq     $zero, $zero, .L80B5D3A0   
/* 01A40 80B5D1F0 92220208 */  lbu     $v0, 0x0208($s1)           ## 00000208
glabel L80B5D1F4
/* 01A44 80B5D1F4 0C042F6F */  jal     func_8010BDBC              
/* 01A48 80B5D1F8 260420D8 */  addiu   $a0, $s0, 0x20D8           ## $a0 = 000020D8
/* 01A4C 80B5D1FC 24010005 */  addiu   $at, $zero, 0x0005         ## $at = 00000005
/* 01A50 80B5D200 1441000B */  bne     $v0, $at, .L80B5D230       
/* 01A54 80B5D204 00000000 */  nop
/* 01A58 80B5D208 0C041AF2 */  jal     func_80106BC8              
/* 01A5C 80B5D20C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01A60 80B5D210 10400007 */  beq     $v0, $zero, .L80B5D230     
/* 01A64 80B5D214 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01A68 80B5D218 24052076 */  addiu   $a1, $zero, 0x2076         ## $a1 = 00002076
/* 01A6C 80B5D21C 0C042DA0 */  jal     func_8010B680              
/* 01A70 80B5D220 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 01A74 80B5D224 922A0208 */  lbu     $t2, 0x0208($s1)           ## 00000208
/* 01A78 80B5D228 254B0001 */  addiu   $t3, $t2, 0x0001           ## $t3 = 00000001
/* 01A7C 80B5D22C A22B0208 */  sb      $t3, 0x0208($s1)           ## 00000208
.L80B5D230:
/* 01A80 80B5D230 1000005B */  beq     $zero, $zero, .L80B5D3A0   
/* 01A84 80B5D234 92220208 */  lbu     $v0, 0x0208($s1)           ## 00000208
glabel L80B5D238
/* 01A88 80B5D238 0C042F6F */  jal     func_8010BDBC              
/* 01A8C 80B5D23C 260420D8 */  addiu   $a0, $s0, 0x20D8           ## $a0 = 000020D8
/* 01A90 80B5D240 24010005 */  addiu   $at, $zero, 0x0005         ## $at = 00000005
/* 01A94 80B5D244 1441000A */  bne     $v0, $at, .L80B5D270       
/* 01A98 80B5D248 00000000 */  nop
/* 01A9C 80B5D24C 0C041AF2 */  jal     func_80106BC8              
/* 01AA0 80B5D250 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01AA4 80B5D254 10400006 */  beq     $v0, $zero, .L80B5D270     
/* 01AA8 80B5D258 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01AAC 80B5D25C 24052077 */  addiu   $a1, $zero, 0x2077         ## $a1 = 00002077
/* 01AB0 80B5D260 0C042DA0 */  jal     func_8010B680              
/* 01AB4 80B5D264 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 01AB8 80B5D268 240C0004 */  addiu   $t4, $zero, 0x0004         ## $t4 = 00000004
/* 01ABC 80B5D26C A22C0208 */  sb      $t4, 0x0208($s1)           ## 00000208
.L80B5D270:
/* 01AC0 80B5D270 1000004B */  beq     $zero, $zero, .L80B5D3A0   
/* 01AC4 80B5D274 92220208 */  lbu     $v0, 0x0208($s1)           ## 00000208
glabel L80B5D278
/* 01AC8 80B5D278 0C042F6F */  jal     func_8010BDBC              
/* 01ACC 80B5D27C 260420D8 */  addiu   $a0, $s0, 0x20D8           ## $a0 = 000020D8
/* 01AD0 80B5D280 24010005 */  addiu   $at, $zero, 0x0005         ## $at = 00000005
/* 01AD4 80B5D284 14410010 */  bne     $v0, $at, .L80B5D2C8       
/* 01AD8 80B5D288 00000000 */  nop
/* 01ADC 80B5D28C 0C041AF2 */  jal     func_80106BC8              
/* 01AE0 80B5D290 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01AE4 80B5D294 1040000C */  beq     $v0, $zero, .L80B5D2C8     
/* 01AE8 80B5D298 2624014C */  addiu   $a0, $s1, 0x014C           ## $a0 = 0000014C
/* 01AEC 80B5D29C 3C0580B6 */  lui     $a1, %hi(D_80B5E7B8)       ## $a1 = 80B60000
/* 01AF0 80B5D2A0 24A5E7B8 */  addiu   $a1, $a1, %lo(D_80B5E7B8)  ## $a1 = 80B5E7B8
/* 01AF4 80B5D2A4 0C00D3B0 */  jal     Actor_ChangeAnimation              
/* 01AF8 80B5D2A8 2406001A */  addiu   $a2, $zero, 0x001A         ## $a2 = 0000001A
/* 01AFC 80B5D2AC 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01B00 80B5D2B0 24052078 */  addiu   $a1, $zero, 0x2078         ## $a1 = 00002078
/* 01B04 80B5D2B4 0C042DA0 */  jal     func_8010B680              
/* 01B08 80B5D2B8 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 01B0C 80B5D2BC 922D0208 */  lbu     $t5, 0x0208($s1)           ## 00000208
/* 01B10 80B5D2C0 25AE0001 */  addiu   $t6, $t5, 0x0001           ## $t6 = 00000001
/* 01B14 80B5D2C4 A22E0208 */  sb      $t6, 0x0208($s1)           ## 00000208
.L80B5D2C8:
/* 01B18 80B5D2C8 10000035 */  beq     $zero, $zero, .L80B5D3A0   
/* 01B1C 80B5D2CC 92220208 */  lbu     $v0, 0x0208($s1)           ## 00000208
glabel L80B5D2D0
/* 01B20 80B5D2D0 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 01B24 80B5D2D4 0C2D6FE4 */  jal     func_80B5BF90              
/* 01B28 80B5D2D8 2405001B */  addiu   $a1, $zero, 0x001B         ## $a1 = 0000001B
/* 01B2C 80B5D2DC 10400004 */  beq     $v0, $zero, .L80B5D2F0     
/* 01B30 80B5D2E0 00000000 */  nop
/* 01B34 80B5D2E4 922F0208 */  lbu     $t7, 0x0208($s1)           ## 00000208
/* 01B38 80B5D2E8 25F80001 */  addiu   $t8, $t7, 0x0001           ## $t8 = 00000001
/* 01B3C 80B5D2EC A2380208 */  sb      $t8, 0x0208($s1)           ## 00000208
glabel L80B5D2F0
.L80B5D2F0:
/* 01B40 80B5D2F0 0C042F6F */  jal     func_8010BDBC              
/* 01B44 80B5D2F4 260420D8 */  addiu   $a0, $s0, 0x20D8           ## $a0 = 000020D8
/* 01B48 80B5D2F8 24010004 */  addiu   $at, $zero, 0x0004         ## $at = 00000004
/* 01B4C 80B5D2FC 14410005 */  bne     $v0, $at, .L80B5D314       
/* 01B50 80B5D300 00000000 */  nop
/* 01B54 80B5D304 0C041AF2 */  jal     func_80106BC8              
/* 01B58 80B5D308 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01B5C 80B5D30C 14400003 */  bne     $v0, $zero, .L80B5D31C     
/* 01B60 80B5D310 3C190001 */  lui     $t9, 0x0001                ## $t9 = 00010000
.L80B5D314:
/* 01B64 80B5D314 10000022 */  beq     $zero, $zero, .L80B5D3A0   
/* 01B68 80B5D318 92220208 */  lbu     $v0, 0x0208($s1)           ## 00000208
.L80B5D31C:
/* 01B6C 80B5D31C 0330C821 */  addu    $t9, $t9, $s0              
/* 01B70 80B5D320 933904BD */  lbu     $t9, 0x04BD($t9)           ## 000104BD
/* 01B74 80B5D324 24080037 */  addiu   $t0, $zero, 0x0037         ## $t0 = 00000037
/* 01B78 80B5D328 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01B7C 80B5D32C 17200007 */  bne     $t9, $zero, .L80B5D34C     
/* 01B80 80B5D330 2405700B */  addiu   $a1, $zero, 0x700B         ## $a1 = 0000700B
/* 01B84 80B5D334 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 01B88 80B5D338 00300821 */  addu    $at, $at, $s0              
/* 01B8C 80B5D33C A02803DC */  sb      $t0, 0x03DC($at)           ## 000103DC
/* 01B90 80B5D340 2409000D */  addiu   $t1, $zero, 0x000D         ## $t1 = 0000000D
/* 01B94 80B5D344 10000005 */  beq     $zero, $zero, .L80B5D35C   
/* 01B98 80B5D348 A2290208 */  sb      $t1, 0x0208($s1)           ## 00000208
.L80B5D34C:
/* 01B9C 80B5D34C 0C042DA0 */  jal     func_8010B680              
/* 01BA0 80B5D350 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 01BA4 80B5D354 240A000C */  addiu   $t2, $zero, 0x000C         ## $t2 = 0000000C
/* 01BA8 80B5D358 A22A0208 */  sb      $t2, 0x0208($s1)           ## 00000208
.L80B5D35C:
/* 01BAC 80B5D35C 10000010 */  beq     $zero, $zero, .L80B5D3A0   
/* 01BB0 80B5D360 92220208 */  lbu     $v0, 0x0208($s1)           ## 00000208
glabel L80B5D364
/* 01BB4 80B5D364 0C042F6F */  jal     func_8010BDBC              
/* 01BB8 80B5D368 260420D8 */  addiu   $a0, $s0, 0x20D8           ## $a0 = 000020D8
/* 01BBC 80B5D36C 24010005 */  addiu   $at, $zero, 0x0005         ## $at = 00000005
/* 01BC0 80B5D370 5441000B */  bnel    $v0, $at, .L80B5D3A0       
/* 01BC4 80B5D374 92220208 */  lbu     $v0, 0x0208($s1)           ## 00000208
/* 01BC8 80B5D378 0C041AF2 */  jal     func_80106BC8              
/* 01BCC 80B5D37C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01BD0 80B5D380 10400006 */  beq     $v0, $zero, .L80B5D39C     
/* 01BD4 80B5D384 240B0037 */  addiu   $t3, $zero, 0x0037         ## $t3 = 00000037
/* 01BD8 80B5D388 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 01BDC 80B5D38C 00300821 */  addu    $at, $at, $s0              
/* 01BE0 80B5D390 A02B03DC */  sb      $t3, 0x03DC($at)           ## 000103DC
/* 01BE4 80B5D394 240C000D */  addiu   $t4, $zero, 0x000D         ## $t4 = 0000000D
/* 01BE8 80B5D398 A22C0208 */  sb      $t4, 0x0208($s1)           ## 00000208
.L80B5D39C:
/* 01BEC 80B5D39C 92220208 */  lbu     $v0, 0x0208($s1)           ## 00000208
.L80B5D3A0:
/* 01BF0 80B5D3A0 2401000D */  addiu   $at, $zero, 0x000D         ## $at = 0000000D
/* 01BF4 80B5D3A4 14410003 */  bne     $v0, $at, .L80B5D3B4       
/* 01BF8 80B5D3A8 8FB00014 */  lw      $s0, 0x0014($sp)           
/* 01BFC 80B5D3AC 10000002 */  beq     $zero, $zero, .L80B5D3B8   
/* 01C00 80B5D3B0 24030001 */  addiu   $v1, $zero, 0x0001         ## $v1 = 00000001
.L80B5D3B4:
/* 01C04 80B5D3B4 00001825 */  or      $v1, $zero, $zero          ## $v1 = 00000000
.L80B5D3B8:
/* 01C08 80B5D3B8 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 01C0C 80B5D3BC 8FB10018 */  lw      $s1, 0x0018($sp)           
/* 01C10 80B5D3C0 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 01C14 80B5D3C4 03E00008 */  jr      $ra                        
/* 01C18 80B5D3C8 00601025 */  or      $v0, $v1, $zero            ## $v0 = 00000000
