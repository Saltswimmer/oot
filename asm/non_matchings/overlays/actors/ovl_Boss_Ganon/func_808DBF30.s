.late_rodata
glabel D_808F7FF4
    .float 3.14159274101

glabel D_808F7FF8
    .float 1.5707964

glabel D_808F7FFC
    .float 1.5707964

.text
glabel func_808DBF30
/* 056C0 808DBF30 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 056C4 808DBF34 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 056C8 808DBF38 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 056CC 808DBF3C AFBF001C */  sw      $ra, 0x001C($sp)           
/* 056D0 808DBF40 AFA50024 */  sw      $a1, 0x0024($sp)           
/* 056D4 808DBF44 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 056D8 808DBF48 24840150 */  addiu   $a0, $a0, 0x0150           ## $a0 = 00000150
/* 056DC 808DBF4C 3C038090 */  lui     $v1, %hi(sCape)       ## $v1 = 80900000
/* 056E0 808DBF50 246393C0 */  addiu   $v1, $v1, %lo(sCape)  ## $v1 = 808F93C0
/* 056E4 808DBF54 3C01C040 */  lui     $at, 0xC040                ## $at = C0400000
/* 056E8 808DBF58 44812000 */  mtc1    $at, $f4                   ## $f4 = -3.00
/* 056EC 808DBF5C 8C6E0000 */  lw      $t6, 0x0000($v1)           ## 808F93C0
/* 056F0 808DBF60 3C013FA0 */  lui     $at, 0x3FA0                ## $at = 3FA00000
/* 056F4 808DBF64 44813000 */  mtc1    $at, $f6                   ## $f6 = 1.25
/* 056F8 808DBF68 E5C416B0 */  swc1    $f4, 0x16B0($t6)           ## 000016B0
/* 056FC 808DBF6C 8C6F0000 */  lw      $t7, 0x0000($v1)           ## 808F93C0
/* 05700 808DBF70 3C01C000 */  lui     $at, 0xC000                ## $at = C0000000
/* 05704 808DBF74 44814000 */  mtc1    $at, $f8                   ## $f8 = -2.00
/* 05708 808DBF78 E5E616B4 */  swc1    $f6, 0x16B4($t7)           ## 000016B4
/* 0570C 808DBF7C 8C780000 */  lw      $t8, 0x0000($v1)           ## 808F93C0
/* 05710 808DBF80 3C014120 */  lui     $at, 0x4120                ## $at = 41200000
/* 05714 808DBF84 44815000 */  mtc1    $at, $f10                  ## $f10 = 10.00
/* 05718 808DBF88 E70816B8 */  swc1    $f8, 0x16B8($t8)           ## 000016B8
/* 0571C 808DBF8C 8C790000 */  lw      $t9, 0x0000($v1)           ## 808F93C0
/* 05720 808DBF90 24080001 */  addiu   $t0, $zero, 0x0001         ## $t0 = 00000001
/* 05724 808DBF94 2409000A */  addiu   $t1, $zero, 0x000A         ## $t1 = 0000000A
/* 05728 808DBF98 E72A16D0 */  swc1    $f10, 0x16D0($t9)          ## 000016D0
/* 0572C 808DBF9C 860201B6 */  lh      $v0, 0x01B6($s0)           ## 000001B6
/* 05730 808DBFA0 28410011 */  slti    $at, $v0, 0x0011           
/* 05734 808DBFA4 50200004 */  beql    $at, $zero, .L808DBFB8     
/* 05738 808DBFA8 24010011 */  addiu   $at, $zero, 0x0011         ## $at = 00000011
/* 0573C 808DBFAC A20801A0 */  sb      $t0, 0x01A0($s0)           ## 000001A0
/* 05740 808DBFB0 860201B6 */  lh      $v0, 0x01B6($s0)           ## 000001B6
/* 05744 808DBFB4 24010011 */  addiu   $at, $zero, 0x0011         ## $at = 00000011
.L808DBFB8:
/* 05748 808DBFB8 5441000B */  bnel    $v0, $at, .L808DBFE8       
/* 0574C 808DBFBC 2841000A */  slti    $at, $v0, 0x000A           
/* 05750 808DBFC0 A609026C */  sh      $t1, 0x026C($s0)           ## 0000026C
/* 05754 808DBFC4 3C01808F */  lui     $at, %hi(D_808F7FF4)       ## $at = 808F0000
/* 05758 808DBFC8 0C00CFBE */  jal     Math_Rand_ZeroFloat
              
/* 0575C 808DBFCC C42C7FF4 */  lwc1    $f12, %lo(D_808F7FF4)($at) 
/* 05760 808DBFD0 E6000270 */  swc1    $f0, 0x0270($s0)           ## 00000270
/* 05764 808DBFD4 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 05768 808DBFD8 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 0576C 808DBFDC 24053867 */  addiu   $a1, $zero, 0x3867         ## $a1 = 00003867
/* 05770 808DBFE0 860201B6 */  lh      $v0, 0x01B6($s0)           ## 000001B6
/* 05774 808DBFE4 2841000A */  slti    $at, $v0, 0x000A           
.L808DBFE8:
/* 05778 808DBFE8 10200014 */  beq     $at, $zero, .L808DC03C     
/* 0577C 808DBFEC 3C01808F */  lui     $at, %hi(D_808F7FF8)       ## $at = 808F0000
/* 05780 808DBFF0 0C00CFBE */  jal     Math_Rand_ZeroFloat
              
/* 05784 808DBFF4 C42C7FF8 */  lwc1    $f12, %lo(D_808F7FF8)($at) 
/* 05788 808DBFF8 3C01808F */  lui     $at, %hi(D_808F7FFC)       ## $at = 808F0000
/* 0578C 808DBFFC C4327FFC */  lwc1    $f18, %lo(D_808F7FFC)($at) 
/* 05790 808DC000 C6100258 */  lwc1    $f16, 0x0258($s0)          ## 00000258
/* 05794 808DC004 26040254 */  addiu   $a0, $s0, 0x0254           ## $a0 = 00000254
/* 05798 808DC008 46120100 */  add.s   $f4, $f0, $f18             
/* 0579C 808DC00C 3C054120 */  lui     $a1, 0x4120                ## $a1 = 41200000
/* 057A0 808DC010 3C063F00 */  lui     $a2, 0x3F00                ## $a2 = 3F000000
/* 057A4 808DC014 3C073FA0 */  lui     $a3, 0x3FA0                ## $a3 = 3FA00000
/* 057A8 808DC018 46048180 */  add.s   $f6, $f16, $f4             
/* 057AC 808DC01C 0C01E107 */  jal     Math_SmoothScaleMaxF
              
/* 057B0 808DC020 E6060258 */  swc1    $f6, 0x0258($s0)           ## 00000258
/* 057B4 808DC024 860A01B6 */  lh      $t2, 0x01B6($s0)           ## 000001B6
/* 057B8 808DC028 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 057BC 808DC02C 55400004 */  bnel    $t2, $zero, .L808DC040     
/* 057C0 808DC030 260400B6 */  addiu   $a0, $s0, 0x00B6           ## $a0 = 000000B6
/* 057C4 808DC034 0C23703A */  jal     func_808DC0E8              
/* 057C8 808DC038 8FA50024 */  lw      $a1, 0x0024($sp)           
.L808DC03C:
/* 057CC 808DC03C 260400B6 */  addiu   $a0, $s0, 0x00B6           ## $a0 = 000000B6
.L808DC040:
/* 057D0 808DC040 8605008A */  lh      $a1, 0x008A($s0)           ## 0000008A
/* 057D4 808DC044 24060005 */  addiu   $a2, $zero, 0x0005         ## $a2 = 00000005
/* 057D8 808DC048 0C01E1EF */  jal     Math_SmoothScaleMaxS
              
/* 057DC 808DC04C 240707D0 */  addiu   $a3, $zero, 0x07D0         ## $a3 = 000007D0
/* 057E0 808DC050 C6080024 */  lwc1    $f8, 0x0024($s0)           ## 00000024
/* 057E4 808DC054 C60A005C */  lwc1    $f10, 0x005C($s0)          ## 0000005C
/* 057E8 808DC058 C610002C */  lwc1    $f16, 0x002C($s0)          ## 0000002C
/* 057EC 808DC05C C6040064 */  lwc1    $f4, 0x0064($s0)           ## 00000064
/* 057F0 808DC060 460A4480 */  add.s   $f18, $f8, $f10            
/* 057F4 808DC064 2604005C */  addiu   $a0, $s0, 0x005C           ## $a0 = 0000005C
/* 057F8 808DC068 3C053F80 */  lui     $a1, 0x3F80                ## $a1 = 3F800000
/* 057FC 808DC06C 46048180 */  add.s   $f6, $f16, $f4             
/* 05800 808DC070 E6120024 */  swc1    $f18, 0x0024($s0)          ## 00000024
/* 05804 808DC074 3C063F00 */  lui     $a2, 0x3F00                ## $a2 = 3F000000
/* 05808 808DC078 0C01E123 */  jal     Math_SmoothDownscaleMaxF
              
/* 0580C 808DC07C E606002C */  swc1    $f6, 0x002C($s0)           ## 0000002C
/* 05810 808DC080 26040064 */  addiu   $a0, $s0, 0x0064           ## $a0 = 00000064
/* 05814 808DC084 3C053F80 */  lui     $a1, 0x3F80                ## $a1 = 3F800000
/* 05818 808DC088 0C01E123 */  jal     Math_SmoothDownscaleMaxF
              
/* 0581C 808DC08C 3C063F00 */  lui     $a2, 0x3F00                ## $a2 = 3F000000
/* 05820 808DC090 860401A2 */  lh      $a0, 0x01A2($s0)           ## 000001A2
/* 05824 808DC094 00800821 */  addu    $at, $a0, $zero            
/* 05828 808DC098 00042080 */  sll     $a0, $a0,  2               
/* 0582C 808DC09C 00812023 */  subu    $a0, $a0, $at              
/* 05830 808DC0A0 00042100 */  sll     $a0, $a0,  4               
/* 05834 808DC0A4 00812023 */  subu    $a0, $a0, $at              
/* 05838 808DC0A8 000420C0 */  sll     $a0, $a0,  3               
/* 0583C 808DC0AC 00812023 */  subu    $a0, $a0, $at              
/* 05840 808DC0B0 00042080 */  sll     $a0, $a0,  2               
/* 05844 808DC0B4 00042400 */  sll     $a0, $a0, 16               
/* 05848 808DC0B8 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 0584C 808DC0BC 00042403 */  sra     $a0, $a0, 16               
/* 05850 808DC0C0 46000080 */  add.s   $f2, $f0, $f0              
/* 05854 808DC0C4 C6080028 */  lwc1    $f8, 0x0028($s0)           ## 00000028
/* 05858 808DC0C8 46024280 */  add.s   $f10, $f8, $f2             
/* 0585C 808DC0CC E6020060 */  swc1    $f2, 0x0060($s0)           ## 00000060
/* 05860 808DC0D0 E60A0028 */  swc1    $f10, 0x0028($s0)          ## 00000028
/* 05864 808DC0D4 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 05868 808DC0D8 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 0586C 808DC0DC 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 05870 808DC0E0 03E00008 */  jr      $ra                        
/* 05874 808DC0E4 00000000 */  nop
