glabel func_80B12FE0
/* 016F0 80B12FE0 27BDFFF0 */  addiu   $sp, $sp, 0xFFF0           ## $sp = FFFFFFF0
/* 016F4 80B12FE4 3C0F80B1 */  lui     $t7, %hi(D_80B136D0)       ## $t7 = 80B10000
/* 016F8 80B12FE8 AFA40010 */  sw      $a0, 0x0010($sp)           
/* 016FC 80B12FEC AFA60018 */  sw      $a2, 0x0018($sp)           
/* 01700 80B12FF0 AFA7001C */  sw      $a3, 0x001C($sp)           
/* 01704 80B12FF4 25EF36D0 */  addiu   $t7, $t7, %lo(D_80B136D0)  ## $t7 = 80B136D0
/* 01708 80B12FF8 8DF90000 */  lw      $t9, 0x0000($t7)           ## 80B136D0
/* 0170C 80B12FFC 27AE0000 */  addiu   $t6, $sp, 0x0000           ## $t6 = FFFFFFF0
/* 01710 80B13000 8DF80004 */  lw      $t8, 0x0004($t7)           ## 80B136D4
/* 01714 80B13004 ADD90000 */  sw      $t9, 0x0000($t6)           ## FFFFFFF0
/* 01718 80B13008 8DF90008 */  lw      $t9, 0x0008($t7)           ## 80B136D8
/* 0171C 80B1300C 2401000D */  addiu   $at, $zero, 0x000D         ## $at = 0000000D
/* 01720 80B13010 ADD80004 */  sw      $t8, 0x0004($t6)           ## FFFFFFF4
/* 01724 80B13014 14A1000A */  bne     $a1, $at, .L80B13040       
/* 01728 80B13018 ADD90008 */  sw      $t9, 0x0008($t6)           ## FFFFFFF8
/* 0172C 80B1301C 8FA20024 */  lw      $v0, 0x0024($sp)           
/* 01730 80B13020 8FA30020 */  lw      $v1, 0x0020($sp)           
/* 01734 80B13024 C44402BC */  lwc1    $f4, 0x02BC($v0)           ## 000002BC
/* 01738 80B13028 84680002 */  lh      $t0, 0x0002($v1)           ## 00000002
/* 0173C 80B1302C 4600218D */  trunc.w.s $f6, $f4                   
/* 01740 80B13030 440C3000 */  mfc1    $t4, $f6                   
/* 01744 80B13034 00000000 */  nop
/* 01748 80B13038 010C6821 */  addu    $t5, $t0, $t4              
/* 0174C 80B1303C A46D0002 */  sh      $t5, 0x0002($v1)           ## 00000002
.L80B13040:
/* 01750 80B13040 2401000B */  addiu   $at, $zero, 0x000B         ## $at = 0000000B
/* 01754 80B13044 8FA20024 */  lw      $v0, 0x0024($sp)           
/* 01758 80B13048 14A10016 */  bne     $a1, $at, .L80B130A4       
/* 0175C 80B1304C 8FA30020 */  lw      $v1, 0x0020($sp)           
/* 01760 80B13050 C44802B8 */  lwc1    $f8, 0x02B8($v0)           ## 000002B8
/* 01764 80B13054 846E0000 */  lh      $t6, 0x0000($v1)           ## 00000000
/* 01768 80B13058 846B0002 */  lh      $t3, 0x0002($v1)           ## 00000002
/* 0176C 80B1305C 4600428D */  trunc.w.s $f10, $f8                  
/* 01770 80B13060 84790004 */  lh      $t9, 0x0004($v1)           ## 00000004
/* 01774 80B13064 44095000 */  mfc1    $t1, $f10                  
/* 01778 80B13068 00000000 */  nop
/* 0177C 80B1306C 01C95021 */  addu    $t2, $t6, $t1              
/* 01780 80B13070 A46A0000 */  sh      $t2, 0x0000($v1)           ## 00000000
/* 01784 80B13074 C45002B4 */  lwc1    $f16, 0x02B4($v0)          ## 000002B4
/* 01788 80B13078 4600848D */  trunc.w.s $f18, $f16                 
/* 0178C 80B1307C 440F9000 */  mfc1    $t7, $f18                  
/* 01790 80B13080 00000000 */  nop
/* 01794 80B13084 016FC021 */  addu    $t8, $t3, $t7              
/* 01798 80B13088 A4780002 */  sh      $t8, 0x0002($v1)           ## 00000002
/* 0179C 80B1308C C44402B0 */  lwc1    $f4, 0x02B0($v0)           ## 000002B0
/* 017A0 80B13090 4600218D */  trunc.w.s $f6, $f4                   
/* 017A4 80B13094 44083000 */  mfc1    $t0, $f6                   
/* 017A8 80B13098 00000000 */  nop
/* 017AC 80B1309C 03286021 */  addu    $t4, $t9, $t0              
/* 017B0 80B130A0 A46C0004 */  sh      $t4, 0x0004($v1)           ## 00000004
.L80B130A4:
/* 017B4 80B130A4 24010007 */  addiu   $at, $zero, 0x0007         ## $at = 00000007
/* 017B8 80B130A8 54A10017 */  bnel    $a1, $at, .L80B13108       
/* 017BC 80B130AC 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
/* 017C0 80B130B0 C44802AC */  lwc1    $f8, 0x02AC($v0)           ## 000002AC
/* 017C4 80B130B4 846D0000 */  lh      $t5, 0x0000($v1)           ## 00000000
/* 017C8 80B130B8 846A0002 */  lh      $t2, 0x0002($v1)           ## 00000002
/* 017CC 80B130BC 4600428D */  trunc.w.s $f10, $f8                  
/* 017D0 80B130C0 84780004 */  lh      $t8, 0x0004($v1)           ## 00000004
/* 017D4 80B130C4 440E5000 */  mfc1    $t6, $f10                  
/* 017D8 80B130C8 00000000 */  nop
/* 017DC 80B130CC 01AE4821 */  addu    $t1, $t5, $t6              
/* 017E0 80B130D0 A4690000 */  sh      $t1, 0x0000($v1)           ## 00000000
/* 017E4 80B130D4 C45002A8 */  lwc1    $f16, 0x02A8($v0)          ## 000002A8
/* 017E8 80B130D8 4600848D */  trunc.w.s $f18, $f16                 
/* 017EC 80B130DC 440B9000 */  mfc1    $t3, $f18                  
/* 017F0 80B130E0 00000000 */  nop
/* 017F4 80B130E4 014B7821 */  addu    $t7, $t2, $t3              
/* 017F8 80B130E8 A46F0002 */  sh      $t7, 0x0002($v1)           ## 00000002
/* 017FC 80B130EC C44402A4 */  lwc1    $f4, 0x02A4($v0)           ## 000002A4
/* 01800 80B130F0 4600218D */  trunc.w.s $f6, $f4                   
/* 01804 80B130F4 44193000 */  mfc1    $t9, $f6                   
/* 01808 80B130F8 00000000 */  nop
/* 0180C 80B130FC 03194021 */  addu    $t0, $t8, $t9              
/* 01810 80B13100 A4680004 */  sh      $t0, 0x0004($v1)           ## 00000004
/* 01814 80B13104 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
.L80B13108:
/* 01818 80B13108 03E00008 */  jr      $ra                        
/* 0181C 80B1310C 27BD0010 */  addiu   $sp, $sp, 0x0010           ## $sp = 00000000

