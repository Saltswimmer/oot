glabel func_80919F8C
/* 0457C 80919F8C 27BDFFD0 */  addiu   $sp, $sp, 0xFFD0           ## $sp = FFFFFFD0
/* 04580 80919F90 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 04584 80919F94 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 04588 80919F98 AFA50034 */  sw      $a1, 0x0034($sp)           
/* 0458C 80919F9C 848201BA */  lh      $v0, 0x01BA($a0)           ## 000001BA
/* 04590 80919FA0 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 04594 80919FA4 10400003 */  beq     $v0, $zero, .L80919FB4     
/* 04598 80919FA8 244EFFFF */  addiu   $t6, $v0, 0xFFFF           ## $t6 = FFFFFFFF
/* 0459C 80919FAC 1000006A */  beq     $zero, $zero, .L8091A158   
/* 045A0 80919FB0 A48E01BA */  sh      $t6, 0x01BA($a0)           ## 000001BA
.L80919FB4:
/* 045A4 80919FB4 8E0307D8 */  lw      $v1, 0x07D8($s0)           ## 000007D8
/* 045A8 80919FB8 8C6F0024 */  lw      $t7, 0x0024($v1)           ## 00000024
/* 045AC 80919FBC AFAF002C */  sw      $t7, 0x002C($sp)           
/* 045B0 80919FC0 8618019C */  lh      $t8, 0x019C($s0)           ## 0000019C
/* 045B4 80919FC4 57000065 */  bnel    $t8, $zero, .L8091A15C     
/* 045B8 80919FC8 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 045BC 80919FCC 8E080190 */  lw      $t0, 0x0190($s0)           ## 00000190
/* 045C0 80919FD0 3C198092 */  lui     $t9, %hi(func_809193EC)    ## $t9 = 80920000
/* 045C4 80919FD4 273993EC */  addiu   $t9, $t9, %lo(func_809193EC) ## $t9 = 809193EC
/* 045C8 80919FD8 53280060 */  beql    $t9, $t0, .L8091A15C       
/* 045CC 80919FDC 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 045D0 80919FE0 90640016 */  lbu     $a0, 0x0016($v1)           ## 00000016
/* 045D4 80919FE4 30890002 */  andi    $t1, $a0, 0x0002           ## $t1 = 00000000
/* 045D8 80919FE8 1120005B */  beq     $t1, $zero, .L8091A158     
/* 045DC 80919FEC 308AFFFD */  andi    $t2, $a0, 0xFFFD           ## $t2 = 00000000
/* 045E0 80919FF0 A06A0016 */  sb      $t2, 0x0016($v1)           ## 00000016
/* 045E4 80919FF4 8E020190 */  lw      $v0, 0x0190($s0)           ## 00000190
/* 045E8 80919FF8 3C0B8092 */  lui     $t3, %hi(func_80919A40)    ## $t3 = 80920000
/* 045EC 80919FFC 256B9A40 */  addiu   $t3, $t3, %lo(func_80919A40) ## $t3 = 80919A40
/* 045F0 8091A000 11620007 */  beq     $t3, $v0, .L8091A020       
/* 045F4 8091A004 3C0C8092 */  lui     $t4, %hi(func_8091960C)    ## $t4 = 80920000
/* 045F8 8091A008 258C960C */  addiu   $t4, $t4, %lo(func_8091960C) ## $t4 = 8091960C
/* 045FC 8091A00C 11820004 */  beq     $t4, $v0, .L8091A020       
/* 04600 8091A010 3C0D8092 */  lui     $t5, %hi(func_80919548)    ## $t5 = 80920000
/* 04604 8091A014 25AD9548 */  addiu   $t5, $t5, %lo(func_80919548) ## $t5 = 80919548
/* 04608 8091A018 15A20008 */  bne     $t5, $v0, .L8091A03C       
/* 0460C 8091A01C 3C038092 */  lui     $v1, %hi(func_80919150)    ## $v1 = 80920000
.L8091A020:
/* 04610 8091A020 0C24588B */  jal     func_8091622C              
/* 04614 8091A024 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 04618 8091A028 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0461C 8091A02C 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 04620 8091A030 24053811 */  addiu   $a1, $zero, 0x3811         ## $a1 = 00003811
/* 04624 8091A034 10000049 */  beq     $zero, $zero, .L8091A15C   
/* 04628 8091A038 8FBF001C */  lw      $ra, 0x001C($sp)           
.L8091A03C:
/* 0462C 8091A03C 24639150 */  addiu   $v1, $v1, %lo(func_80919150) ## $v1 = FFFF9150
/* 04630 8091A040 1462001F */  bne     $v1, $v0, .L8091A0C0       
/* 04634 8091A044 8FAE002C */  lw      $t6, 0x002C($sp)           
/* 04638 8091A048 8DC40000 */  lw      $a0, 0x0000($t6)           ## 00000000
/* 0463C 8091A04C 0C018D74 */  jal     func_800635D0              
/* 04640 8091A050 AFA30024 */  sw      $v1, 0x0024($sp)           
/* 04644 8091A054 1040001A */  beq     $v0, $zero, .L8091A0C0     
/* 04648 8091A058 8FA30024 */  lw      $v1, 0x0024($sp)           
/* 0464C 8091A05C 920F00AF */  lbu     $t7, 0x00AF($s0)           ## 000000AF
/* 04650 8091A060 24053810 */  addiu   $a1, $zero, 0x3810         ## $a1 = 00003810
/* 04654 8091A064 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 04658 8091A068 01E2C023 */  subu    $t8, $t7, $v0              
/* 0465C 8091A06C A21800AF */  sb      $t8, 0x00AF($s0)           ## 000000AF
/* 04660 8091A070 821900AF */  lb      $t9, 0x00AF($s0)           ## 000000AF
/* 04664 8091A074 1B20000A */  blez    $t9, .L8091A0A0            
/* 04668 8091A078 00000000 */  nop
/* 0466C 8091A07C 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 04670 8091A080 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 04674 8091A084 0C245A0F */  jal     func_8091683C              
/* 04678 8091A088 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0467C 8091A08C 8FA40034 */  lw      $a0, 0x0034($sp)           
/* 04680 8091A090 0C00A66B */  jal     EffectSsSibuki_SpawnGroup              
/* 04684 8091A094 26050038 */  addiu   $a1, $s0, 0x0038           ## $a1 = 00000038
/* 04688 8091A098 10000007 */  beq     $zero, $zero, .L8091A0B8   
/* 0468C 8091A09C 2408000A */  addiu   $t0, $zero, 0x000A         ## $t0 = 0000000A
.L8091A0A0:
/* 04690 8091A0A0 0C2457CE */  jal     func_80915F38              
/* 04694 8091A0A4 8FA50034 */  lw      $a1, 0x0034($sp)           
/* 04698 8091A0A8 8FA40034 */  lw      $a0, 0x0034($sp)           
/* 0469C 8091A0AC 0C00CB1F */  jal     func_80032C7C              
/* 046A0 8091A0B0 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 046A4 8091A0B4 2408000A */  addiu   $t0, $zero, 0x000A         ## $t0 = 0000000A
.L8091A0B8:
/* 046A8 8091A0B8 10000027 */  beq     $zero, $zero, .L8091A158   
/* 046AC 8091A0BC A60801BA */  sh      $t0, 0x01BA($s0)           ## 000001BA
.L8091A0C0:
/* 046B0 8091A0C0 8E090190 */  lw      $t1, 0x0190($s0)           ## 00000190
/* 046B4 8091A0C4 50690025 */  beql    $v1, $t1, .L8091A15C       
/* 046B8 8091A0C8 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 046BC 8091A0CC 860A0196 */  lh      $t2, 0x0196($s0)           ## 00000196
/* 046C0 8091A0D0 8FAB002C */  lw      $t3, 0x002C($sp)           
/* 046C4 8091A0D4 51400021 */  beql    $t2, $zero, .L8091A15C     
/* 046C8 8091A0D8 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 046CC 8091A0DC 8D6C0000 */  lw      $t4, 0x0000($t3)           ## 00000000
/* 046D0 8091A0E0 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 046D4 8091A0E4 318D0005 */  andi    $t5, $t4, 0x0005           ## $t5 = 00000000
/* 046D8 8091A0E8 51A0001C */  beql    $t5, $zero, .L8091A15C     
/* 046DC 8091A0EC 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 046E0 8091A0F0 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 046E4 8091A0F4 24053811 */  addiu   $a1, $zero, 0x3811         ## $a1 = 00003811
/* 046E8 8091A0F8 0C03E341 */  jal     func_800F8D04              
/* 046EC 8091A0FC 2404380E */  addiu   $a0, $zero, 0x380E         ## $a0 = 0000380E
/* 046F0 8091A100 240E000A */  addiu   $t6, $zero, 0x000A         ## $t6 = 0000000A
/* 046F4 8091A104 A60E01BA */  sh      $t6, 0x01BA($s0)           ## 000001BA
/* 046F8 8091A108 0C24599A */  jal     func_80916668              
/* 046FC 8091A10C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 04700 8091A110 240F0064 */  addiu   $t7, $zero, 0x0064         ## $t7 = 00000064
/* 04704 8091A114 A60F01D6 */  sh      $t7, 0x01D6($s0)           ## 000001D6
/* 04708 8091A118 8FB8002C */  lw      $t8, 0x002C($sp)           
/* 0470C 8091A11C 240A005A */  addiu   $t2, $zero, 0x005A         ## $t2 = 0000005A
/* 04710 8091A120 240B0004 */  addiu   $t3, $zero, 0x0004         ## $t3 = 00000004
/* 04714 8091A124 8F190000 */  lw      $t9, 0x0000($t8)           ## 00000000
/* 04718 8091A128 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0471C 8091A12C 24060004 */  addiu   $a2, $zero, 0x0004         ## $a2 = 00000004
/* 04720 8091A130 33280001 */  andi    $t0, $t9, 0x0001           ## $t0 = 00000000
/* 04724 8091A134 11000004 */  beq     $t0, $zero, .L8091A148     
/* 04728 8091A138 2407000C */  addiu   $a3, $zero, 0x000C         ## $a3 = 0000000C
/* 0472C 8091A13C 24090028 */  addiu   $t1, $zero, 0x0028         ## $t1 = 00000028
/* 04730 8091A140 10000002 */  beq     $zero, $zero, .L8091A14C   
/* 04734 8091A144 A60901D2 */  sh      $t1, 0x01D2($s0)           ## 000001D2
.L8091A148:
/* 04738 8091A148 A60A01D2 */  sh      $t2, 0x01D2($s0)           ## 000001D2
.L8091A14C:
/* 0473C 8091A14C A60B01D4 */  sh      $t3, 0x01D4($s0)           ## 000001D4
/* 04740 8091A150 0C00CFA2 */  jal     func_80033E88              
/* 04744 8091A154 8FA50034 */  lw      $a1, 0x0034($sp)           
.L8091A158:
/* 04748 8091A158 8FBF001C */  lw      $ra, 0x001C($sp)           
.L8091A15C:
/* 0474C 8091A15C 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 04750 8091A160 27BD0030 */  addiu   $sp, $sp, 0x0030           ## $sp = 00000000
/* 04754 8091A164 03E00008 */  jr      $ra                        
/* 04758 8091A168 00000000 */  nop
