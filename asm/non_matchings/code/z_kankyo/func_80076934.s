.rdata
glabel D_8013C770
    .asciz "../z_kankyo.c"
    .balign 4

glabel D_8013C780
    .asciz "../z_kankyo.c"
    .balign 4

.late_rodata
glabel D_8013C830
    .float 0.16666667

glabel D_8013C834
    .float 1.8333334

.text
glabel Kankyo_DrawSandstorm
/* AEDAD4 80076934 27BDFF48 */  addiu $sp, $sp, -0xb8
/* AEDAD8 80076938 3C010001 */  lui   $at, 1
/* AEDADC 8007693C AFBF0034 */  sw    $ra, 0x34($sp)
/* AEDAE0 80076940 AFA400B8 */  sw    $a0, 0xb8($sp)
/* AEDAE4 80076944 AFA500BC */  sw    $a1, 0xbc($sp)
/* AEDAE8 80076948 00816021 */  addu  $t4, $a0, $at
/* AEDAEC 8007694C 91870B0B */  lbu   $a3, 0xb0b($t4)
/* AEDAF0 80076950 91860B0C */  lbu   $a2, 0xb0c($t4)
/* AEDAF4 80076954 30A500FF */  andi  $a1, $a1, 0xff
/* AEDAF8 80076958 24010001 */  li    $at, 1
/* AEDAFC 8007695C 00E04025 */  move  $t0, $a3
/* AEDB00 80076960 10A10023 */  beq   $a1, $at, .L800769F0
/* AEDB04 80076964 00C04825 */   move  $t1, $a2
/* AEDB08 80076968 24010002 */  li    $at, 2
/* AEDB0C 8007696C 10A10027 */  beq   $a1, $at, .L80076A0C
/* AEDB10 80076970 24010003 */   li    $at, 3
/* AEDB14 80076974 10A10006 */  beq   $a1, $at, .L80076990
/* AEDB18 80076978 8FAE00B8 */   lw    $t6, 0xb8($sp)
/* AEDB1C 8007697C 24010004 */  li    $at, 4
/* AEDB20 80076980 10A1003A */  beq   $a1, $at, .L80076A6C
/* AEDB24 80076984 8FA300B4 */   lw    $v1, 0xb4($sp)
/* AEDB28 80076988 10000043 */  b     .L80076A98
/* AEDB2C 8007698C 8FA500B0 */   lw    $a1, 0xb0($sp)
.L80076990:
/* AEDB30 80076990 85CF00A4 */  lh    $t7, 0xa4($t6)
/* AEDB34 80076994 2401005E */  li    $at, 94
/* AEDB38 80076998 8FB900B8 */  lw    $t9, 0xb8($sp)
/* AEDB3C 8007699C 15E1000B */  bne   $t7, $at, .L800769CC
/* AEDB40 800769A0 24050080 */   li    $a1, 128
/* AEDB44 800769A4 81981CBC */  lb    $t8, 0x1cbc($t4)
/* AEDB48 800769A8 28C10081 */  slti  $at, $a2, 0x81
/* AEDB4C 800769AC 57000008 */  bnezl $t8, .L800769D0
/* AEDB50 800769B0 8F23009C */   lw    $v1, 0x9c($t9)
/* AEDB54 800769B4 14200003 */  bnez  $at, .L800769C4
/* AEDB58 800769B8 00002825 */   move  $a1, $zero
/* AEDB5C 800769BC 10000036 */  b     .L80076A98
/* AEDB60 800769C0 240300FF */   li    $v1, 255
.L800769C4:
/* AEDB64 800769C4 10000034 */  b     .L80076A98
/* AEDB68 800769C8 00061843 */   sra   $v1, $a2, 1
.L800769CC:
/* AEDB6C 800769CC 8F23009C */  lw    $v1, 0x9c($t9)
.L800769D0:
/* AEDB70 800769D0 240E0080 */  li    $t6, 128
/* AEDB74 800769D4 3063007F */  andi  $v1, $v1, 0x7f
/* AEDB78 800769D8 28610041 */  slti  $at, $v1, 0x41
/* AEDB7C 800769DC 14200002 */  bnez  $at, .L800769E8
/* AEDB80 800769E0 00000000 */   nop   
/* AEDB84 800769E4 01C31823 */  subu  $v1, $t6, $v1
.L800769E8:
/* AEDB88 800769E8 1000002B */  b     .L80076A98
/* AEDB8C 800769EC 24630049 */   addiu $v1, $v1, 0x49
.L800769F0:
/* AEDB90 800769F0 28E100FF */  slti  $at, $a3, 0xff
/* AEDB94 800769F4 14200003 */  bnez  $at, .L80076A04
/* AEDB98 800769F8 240300FF */   li    $v1, 255
/* AEDB9C 800769FC 10000026 */  b     .L80076A98
/* AEDBA0 80076A00 240500FF */   li    $a1, 255
.L80076A04:
/* AEDBA4 80076A04 10000024 */  b     .L80076A98
/* AEDBA8 80076A08 24050080 */   li    $a1, 128
.L80076A0C:
/* AEDBAC 80076A0C 28C10081 */  slti  $at, $a2, 0x81
/* AEDBB0 80076A10 14200003 */  bnez  $at, .L80076A20
/* AEDBB4 80076A14 24050080 */   li    $a1, 128
/* AEDBB8 80076A18 1000000A */  b     .L80076A44
/* AEDBBC 80076A1C 240300FF */   li    $v1, 255
.L80076A20:
/* AEDBC0 80076A20 8FAF00B8 */  lw    $t7, 0xb8($sp)
/* AEDBC4 80076A24 24180080 */  li    $t8, 128
/* AEDBC8 80076A28 8DE3009C */  lw    $v1, 0x9c($t7)
/* AEDBCC 80076A2C 3063007F */  andi  $v1, $v1, 0x7f
/* AEDBD0 80076A30 28610041 */  slti  $at, $v1, 0x41
/* AEDBD4 80076A34 54200003 */  bnezl $at, .L80076A44
/* AEDBD8 80076A38 24630049 */   addiu $v1, $v1, 0x49
/* AEDBDC 80076A3C 03031823 */  subu  $v1, $t8, $v1
/* AEDBE0 80076A40 24630049 */  addiu $v1, $v1, 0x49
.L80076A44:
/* AEDBE4 80076A44 0068082A */  slt   $at, $v1, $t0
/* AEDBE8 80076A48 14200013 */  bnez  $at, .L80076A98
/* AEDBEC 80076A4C 240100FF */   li    $at, 255
/* AEDBF0 80076A50 10610011 */  beq   $v1, $at, .L80076A98
/* AEDBF4 80076A54 8FAE00B8 */   lw    $t6, 0xb8($sp)
/* AEDBF8 80076A58 3C010001 */  lui   $at, 1
/* AEDBFC 80076A5C 002E0821 */  addu  $at, $at, $t6
/* AEDC00 80076A60 24190003 */  li    $t9, 3
/* AEDC04 80076A64 1000000C */  b     .L80076A98
/* AEDC08 80076A68 A0390B0A */   sb    $t9, 0xb0a($at)
.L80076A6C:
/* AEDC0C 80076A6C 28C10081 */  slti  $at, $a2, 0x81
/* AEDC10 80076A70 14200003 */  bnez  $at, .L80076A80
/* AEDC14 80076A74 00002825 */   move  $a1, $zero
/* AEDC18 80076A78 10000002 */  b     .L80076A84
/* AEDC1C 80076A7C 240300FF */   li    $v1, 255
.L80076A80:
/* AEDC20 80076A80 00061843 */  sra   $v1, $a2, 1
.L80076A84:
/* AEDC24 80076A84 15000004 */  bnez  $t0, .L80076A98
/* AEDC28 80076A88 8FAF00B8 */   lw    $t7, 0xb8($sp)
/* AEDC2C 80076A8C 3C010001 */  li    $at, 0x00010000 # 0.000000
/* AEDC30 80076A90 002F0821 */  addu  $at, $at, $t7
/* AEDC34 80076A94 A0200B0A */  sb    $zero, 0xb0a($at)
.L80076A98:
/* AEDC38 80076A98 01032023 */  subu  $a0, $t0, $v1
/* AEDC3C 80076A9C 04800003 */  bltz  $a0, .L80076AAC
/* AEDC40 80076AA0 8FB800B8 */   lw    $t8, 0xb8($sp)
/* AEDC44 80076AA4 10000002 */  b     .L80076AB0
/* AEDC48 80076AA8 00801025 */   move  $v0, $a0
.L80076AAC:
/* AEDC4C 80076AAC 00041023 */  negu  $v0, $a0
.L80076AB0:
/* AEDC50 80076AB0 28410009 */  slti  $at, $v0, 9
/* AEDC54 80076AB4 50200004 */  beql  $at, $zero, .L80076AC8
/* AEDC58 80076AB8 0068082A */   slt   $at, $v1, $t0
/* AEDC5C 80076ABC 10000007 */  b     .L80076ADC
/* AEDC60 80076AC0 00604025 */   move  $t0, $v1
/* AEDC64 80076AC4 0068082A */  slt   $at, $v1, $t0
.L80076AC8:
/* AEDC68 80076AC8 50200004 */  beql  $at, $zero, .L80076ADC
/* AEDC6C 80076ACC 25080009 */   addiu $t0, $t0, 9
/* AEDC70 80076AD0 10000002 */  b     .L80076ADC
/* AEDC74 80076AD4 2508FFF7 */   addiu $t0, $t0, -9
/* AEDC78 80076AD8 25080009 */  addiu $t0, $t0, 9
.L80076ADC:
/* AEDC7C 80076ADC 01251823 */  subu  $v1, $t1, $a1
/* AEDC80 80076AE0 04600003 */  bltz  $v1, .L80076AF0
/* AEDC84 80076AE4 00031023 */   negu  $v0, $v1
/* AEDC88 80076AE8 10000001 */  b     .L80076AF0
/* AEDC8C 80076AEC 00601025 */   move  $v0, $v1
.L80076AF0:
/* AEDC90 80076AF0 28410009 */  slti  $at, $v0, 9
/* AEDC94 80076AF4 10200003 */  beqz  $at, .L80076B04
/* AEDC98 80076AF8 3C0D8012 */   lui   $t5, %hi(D_8011FEC4)
/* AEDC9C 80076AFC 10000007 */  b     .L80076B1C
/* AEDCA0 80076B00 00A04825 */   move  $t1, $a1
.L80076B04:
/* AEDCA4 80076B04 00A9082A */  slt   $at, $a1, $t1
/* AEDCA8 80076B08 50200004 */  beql  $at, $zero, .L80076B1C
/* AEDCAC 80076B0C 25290009 */   addiu $t1, $t1, 9
/* AEDCB0 80076B10 10000002 */  b     .L80076B1C
/* AEDCB4 80076B14 2529FFF7 */   addiu $t1, $t1, -9
/* AEDCB8 80076B18 25290009 */  addiu $t1, $t1, 9
.L80076B1C:
/* AEDCBC 80076B1C 3C0140C0 */  li    $at, 0x40C00000 # 0.000000
/* AEDCC0 80076B20 44818000 */  mtc1  $at, $f16
/* AEDCC4 80076B24 3C010001 */  li    $at, 0x00010000 # 0.000000
/* AEDCC8 80076B28 00380821 */  addu  $at, $at, $t8
/* AEDCCC 80076B2C A0280B0B */  sb    $t0, 0xb0b($at)
/* AEDCD0 80076B30 01097021 */  addu  $t6, $t0, $t1
/* AEDCD4 80076B34 8FB900B8 */  lw    $t9, 0xb8($sp)
/* AEDCD8 80076B38 448E3000 */  mtc1  $t6, $f6
/* AEDCDC 80076B3C 3C010001 */  li    $at, 0x00010000 # 0.000000
/* AEDCE0 80076B40 00390821 */  addu  $at, $at, $t9
/* AEDCE4 80076B44 46803220 */  cvt.s.w $f8, $f6
/* AEDCE8 80076B48 A0290B0C */  sb    $t1, 0xb0c($at)
/* AEDCEC 80076B4C 3C014400 */  li    $at, 0x44000000 # 0.000000
/* AEDCF0 80076B50 44812000 */  mtc1  $at, $f4
/* AEDCF4 80076B54 3C013CC0 */  li    $at, 0x3CC00000 # 0.000000
/* AEDCF8 80076B58 44819000 */  mtc1  $at, $f18
/* AEDCFC 80076B5C 46082281 */  sub.s $f10, $f4, $f8
/* AEDD00 80076B60 3C1F8012 */  lui   $ra, %hi(D_8011FED0)
/* AEDD04 80076B64 27FFFED0 */  addiu $ra, %lo(D_8011FED0) # addiu $ra, $ra, -0x130
/* AEDD08 80076B68 25ADFEC4 */  addiu $t5, %lo(D_8011FEC4) # addiu $t5, $t5, -0x13c
/* AEDD0C 80076B6C 46125382 */  mul.s $f14, $f10, $f18
/* AEDD10 80076B70 460E803C */  c.lt.s $f16, $f14
/* AEDD14 80076B74 00000000 */  nop   
/* AEDD18 80076B78 45020003 */  bc1fl .L80076B88
/* AEDD1C 80076B7C 918F0A42 */   lbu   $t7, 0xa42($t4)
/* AEDD20 80076B80 46008386 */  mov.s $f14, $f16
/* AEDD24 80076B84 918F0A42 */  lbu   $t7, 0xa42($t4)
.L80076B88:
/* AEDD28 80076B88 55E00006 */  bnezl $t7, .L80076BA4
/* AEDD2C 80076B8C 91B90003 */   lbu   $t9, 3($t5)
/* AEDD30 80076B90 91980AE3 */  lbu   $t8, 0xae3($t4)
/* AEDD34 80076B94 240100FF */  li    $at, 255
/* AEDD38 80076B98 5301000D */  beql  $t8, $at, .L80076BD0
/* AEDD3C 80076B9C AFAC0058 */   sw    $t4, 0x58($sp)
/* AEDD40 80076BA0 91B90003 */  lbu   $t9, 3($t5)
.L80076BA4:
/* AEDD44 80076BA4 91AE0004 */  lbu   $t6, 4($t5)
/* AEDD48 80076BA8 91AF0005 */  lbu   $t7, 5($t5)
/* AEDD4C 80076BAC 93E90003 */  lbu   $t1, 3($ra)
/* AEDD50 80076BB0 93EA0004 */  lbu   $t2, 4($ra)
/* AEDD54 80076BB4 93EB0005 */  lbu   $t3, 5($ra)
/* AEDD58 80076BB8 AFAC0058 */  sw    $t4, 0x58($sp)
/* AEDD5C 80076BBC A3B900A4 */  sb    $t9, 0xa4($sp)
/* AEDD60 80076BC0 A3AE00A5 */  sb    $t6, 0xa5($sp)
/* AEDD64 80076BC4 100000AF */  b     .L80076E84
/* AEDD68 80076BC8 A3AF00A6 */   sb    $t7, 0xa6($sp)
/* AEDD6C 80076BCC AFAC0058 */  sw    $t4, 0x58($sp)
.L80076BD0:
/* AEDD70 80076BD0 3C0C8012 */  lui   $t4, %hi(D_8011FDD0)
/* AEDD74 80076BD4 3C088012 */  lui   $t0, %hi(D_8011FDCC)
/* AEDD78 80076BD8 9108FDCC */  lbu   $t0, %lo(D_8011FDCC)($t0)
/* AEDD7C 80076BDC 918CFDD0 */  lbu   $t4, %lo(D_8011FDD0)($t4)
/* AEDD80 80076BE0 15880012 */  bne   $t4, $t0, .L80076C2C
/* AEDD84 80076BE4 3C0D8012 */   lui   $t5, %hi(D_8011FEC4)
/* AEDD88 80076BE8 00083080 */  sll   $a2, $t0, 2
/* AEDD8C 80076BEC 25ADFEC4 */  addiu $t5, %lo(D_8011FEC4) # addiu $t5, $t5, -0x13c
/* AEDD90 80076BF0 00C83023 */  subu  $a2, $a2, $t0
/* AEDD94 80076BF4 01A61021 */  addu  $v0, $t5, $a2
/* AEDD98 80076BF8 3C1F8012 */  lui   $ra, %hi(D_8011FED0)
/* AEDD9C 80076BFC 27FFFED0 */  addiu $ra, %lo(D_8011FED0) # addiu $ra, $ra, -0x130
/* AEDDA0 80076C00 90580000 */  lbu   $t8, ($v0)
/* AEDDA4 80076C04 90590001 */  lbu   $t9, 1($v0)
/* AEDDA8 80076C08 904E0002 */  lbu   $t6, 2($v0)
/* AEDDAC 80076C0C 03E61821 */  addu  $v1, $ra, $a2
/* AEDDB0 80076C10 90690000 */  lbu   $t1, ($v1)
/* AEDDB4 80076C14 906A0001 */  lbu   $t2, 1($v1)
/* AEDDB8 80076C18 906B0002 */  lbu   $t3, 2($v1)
/* AEDDBC 80076C1C A3B800A4 */  sb    $t8, 0xa4($sp)
/* AEDDC0 80076C20 A3B900A5 */  sb    $t9, 0xa5($sp)
/* AEDDC4 80076C24 10000097 */  b     .L80076E84
/* AEDDC8 80076C28 A3AE00A6 */   sb    $t6, 0xa6($sp)
.L80076C2C:
/* AEDDCC 80076C2C 3C0D8012 */  lui   $t5, %hi(D_8011FEC4)
/* AEDDD0 80076C30 25ADFEC4 */  addiu $t5, %lo(D_8011FEC4) # addiu $t5, $t5, -0x13c
/* AEDDD4 80076C34 000C3880 */  sll   $a3, $t4, 2
/* AEDDD8 80076C38 00EC3823 */  subu  $a3, $a3, $t4
/* AEDDDC 80076C3C 01A72021 */  addu  $a0, $t5, $a3
/* AEDDE0 80076C40 908F0000 */  lbu   $t7, ($a0)
/* AEDDE4 80076C44 3C018012 */  lui   $at, %hi(D_8011FDD4)
/* AEDDE8 80076C48 C420FDD4 */  lwc1  $f0, %lo(D_8011FDD4)($at)
/* AEDDEC 80076C4C 448F9000 */  mtc1  $t7, $f18
/* AEDDF0 80076C50 3C013F80 */  li    $at, 0x3F800000 # 0.000000
/* AEDDF4 80076C54 44816000 */  mtc1  $at, $f12
/* AEDDF8 80076C58 46809220 */  cvt.s.w $f8, $f18
/* AEDDFC 80076C5C 00083080 */  sll   $a2, $t0, 2
/* AEDE00 80076C60 3C1F8012 */  lui   $ra, %hi(D_8011FED0)
/* AEDE04 80076C64 00C83023 */  subu  $a2, $a2, $t0
/* AEDE08 80076C68 27FFFED0 */  addiu $ra, %lo(D_8011FED0) # addiu $ra, $ra, -0x130
/* AEDE0C 80076C6C 46006081 */  sub.s $f2, $f12, $f0
/* AEDE10 80076C70 05E10005 */  bgez  $t7, .L80076C88
/* AEDE14 80076C74 01A61021 */   addu  $v0, $t5, $a2
/* AEDE18 80076C78 3C014F80 */  li    $at, 0x4F800000 # 0.000000
/* AEDE1C 80076C7C 44815000 */  mtc1  $at, $f10
/* AEDE20 80076C80 00000000 */  nop   
/* AEDE24 80076C84 460A4200 */  add.s $f8, $f8, $f10
.L80076C88:
/* AEDE28 80076C88 90580000 */  lbu   $t8, ($v0)
/* AEDE2C 80076C8C 46004482 */  mul.s $f18, $f8, $f0
/* AEDE30 80076C90 44983000 */  mtc1  $t8, $f6
/* AEDE34 80076C94 07010005 */  bgez  $t8, .L80076CAC
/* AEDE38 80076C98 46803120 */   cvt.s.w $f4, $f6
/* AEDE3C 80076C9C 3C014F80 */  li    $at, 0x4F800000 # 0.000000
/* AEDE40 80076CA0 44815000 */  mtc1  $at, $f10
/* AEDE44 80076CA4 00000000 */  nop   
/* AEDE48 80076CA8 460A2100 */  add.s $f4, $f4, $f10
.L80076CAC:
/* AEDE4C 80076CAC 46022202 */  mul.s $f8, $f4, $f2
/* AEDE50 80076CB0 908F0001 */  lbu   $t7, 1($a0)
/* AEDE54 80076CB4 3C014F80 */  li    $at, 0x4F800000 # 0.000000
/* AEDE58 80076CB8 448F2000 */  mtc1  $t7, $f4
/* AEDE5C 80076CBC 46089180 */  add.s $f6, $f18, $f8
/* AEDE60 80076CC0 468024A0 */  cvt.s.w $f18, $f4
/* AEDE64 80076CC4 4600328D */  trunc.w.s $f10, $f6
/* AEDE68 80076CC8 440E5000 */  mfc1  $t6, $f10
/* AEDE6C 80076CCC 05E10004 */  bgez  $t7, .L80076CE0
/* AEDE70 80076CD0 A3AE00A4 */   sb    $t6, 0xa4($sp)
/* AEDE74 80076CD4 44814000 */  mtc1  $at, $f8
/* AEDE78 80076CD8 00000000 */  nop   
/* AEDE7C 80076CDC 46089480 */  add.s $f18, $f18, $f8
.L80076CE0:
/* AEDE80 80076CE0 90580001 */  lbu   $t8, 1($v0)
/* AEDE84 80076CE4 46009182 */  mul.s $f6, $f18, $f0
/* AEDE88 80076CE8 3C014F80 */  li    $at, 0x4F800000 # 0.000000
/* AEDE8C 80076CEC 44985000 */  mtc1  $t8, $f10
/* AEDE90 80076CF0 07010004 */  bgez  $t8, .L80076D04
/* AEDE94 80076CF4 46805120 */   cvt.s.w $f4, $f10
/* AEDE98 80076CF8 44814000 */  mtc1  $at, $f8
/* AEDE9C 80076CFC 00000000 */  nop   
/* AEDEA0 80076D00 46082100 */  add.s $f4, $f4, $f8
.L80076D04:
/* AEDEA4 80076D04 46022482 */  mul.s $f18, $f4, $f2
/* AEDEA8 80076D08 908F0002 */  lbu   $t7, 2($a0)
/* AEDEAC 80076D0C 3C014F80 */  li    $at, 0x4F800000 # 0.000000
/* AEDEB0 80076D10 448F2000 */  mtc1  $t7, $f4
/* AEDEB4 80076D14 46123280 */  add.s $f10, $f6, $f18
/* AEDEB8 80076D18 468021A0 */  cvt.s.w $f6, $f4
/* AEDEBC 80076D1C 4600520D */  trunc.w.s $f8, $f10
/* AEDEC0 80076D20 440E4000 */  mfc1  $t6, $f8
/* AEDEC4 80076D24 05E10004 */  bgez  $t7, .L80076D38
/* AEDEC8 80076D28 A3AE00A5 */   sb    $t6, 0xa5($sp)
/* AEDECC 80076D2C 44819000 */  mtc1  $at, $f18
/* AEDED0 80076D30 00000000 */  nop   
/* AEDED4 80076D34 46123180 */  add.s $f6, $f6, $f18
.L80076D38:
/* AEDED8 80076D38 90580002 */  lbu   $t8, 2($v0)
/* AEDEDC 80076D3C 46003282 */  mul.s $f10, $f6, $f0
/* AEDEE0 80076D40 3C014F80 */  li    $at, 0x4F800000 # 0.000000
/* AEDEE4 80076D44 44984000 */  mtc1  $t8, $f8
/* AEDEE8 80076D48 07010004 */  bgez  $t8, .L80076D5C
/* AEDEEC 80076D4C 46804120 */   cvt.s.w $f4, $f8
/* AEDEF0 80076D50 44819000 */  mtc1  $at, $f18
/* AEDEF4 80076D54 00000000 */  nop   
/* AEDEF8 80076D58 46122100 */  add.s $f4, $f4, $f18
.L80076D5C:
/* AEDEFC 80076D5C 46022182 */  mul.s $f6, $f4, $f2
/* AEDF00 80076D60 03E72821 */  addu  $a1, $ra, $a3
/* AEDF04 80076D64 90AF0000 */  lbu   $t7, ($a1)
/* AEDF08 80076D68 03E61821 */  addu  $v1, $ra, $a2
/* AEDF0C 80076D6C 3C014F80 */  li    $at, 0x4F800000 # 0.000000
/* AEDF10 80076D70 448F2000 */  mtc1  $t7, $f4
/* AEDF14 80076D74 46065200 */  add.s $f8, $f10, $f6
/* AEDF18 80076D78 468022A0 */  cvt.s.w $f10, $f4
/* AEDF1C 80076D7C 4600448D */  trunc.w.s $f18, $f8
/* AEDF20 80076D80 440E9000 */  mfc1  $t6, $f18
/* AEDF24 80076D84 05E10004 */  bgez  $t7, .L80076D98
/* AEDF28 80076D88 A3AE00A6 */   sb    $t6, 0xa6($sp)
/* AEDF2C 80076D8C 44813000 */  mtc1  $at, $f6
/* AEDF30 80076D90 00000000 */  nop   
/* AEDF34 80076D94 46065280 */  add.s $f10, $f10, $f6
.L80076D98:
/* AEDF38 80076D98 90780000 */  lbu   $t8, ($v1)
/* AEDF3C 80076D9C 46005202 */  mul.s $f8, $f10, $f0
/* AEDF40 80076DA0 3C014F80 */  li    $at, 0x4F800000 # 0.000000
/* AEDF44 80076DA4 44989000 */  mtc1  $t8, $f18
/* AEDF48 80076DA8 07010004 */  bgez  $t8, .L80076DBC
/* AEDF4C 80076DAC 46809120 */   cvt.s.w $f4, $f18
/* AEDF50 80076DB0 44813000 */  mtc1  $at, $f6
/* AEDF54 80076DB4 00000000 */  nop   
/* AEDF58 80076DB8 46062100 */  add.s $f4, $f4, $f6
.L80076DBC:
/* AEDF5C 80076DBC 46022282 */  mul.s $f10, $f4, $f2
/* AEDF60 80076DC0 90AE0001 */  lbu   $t6, 1($a1)
/* AEDF64 80076DC4 3C014F80 */  li    $at, 0x4F800000 # 0.000000
/* AEDF68 80076DC8 448E2000 */  mtc1  $t6, $f4
/* AEDF6C 80076DCC 460A4480 */  add.s $f18, $f8, $f10
/* AEDF70 80076DD0 46802220 */  cvt.s.w $f8, $f4
/* AEDF74 80076DD4 4600918D */  trunc.w.s $f6, $f18
/* AEDF78 80076DD8 44093000 */  mfc1  $t1, $f6
/* AEDF7C 80076DDC 05C10004 */  bgez  $t6, .L80076DF0
/* AEDF80 80076DE0 312900FF */   andi  $t1, $t1, 0xff
/* AEDF84 80076DE4 44815000 */  mtc1  $at, $f10
/* AEDF88 80076DE8 00000000 */  nop   
/* AEDF8C 80076DEC 460A4200 */  add.s $f8, $f8, $f10
.L80076DF0:
/* AEDF90 80076DF0 906F0001 */  lbu   $t7, 1($v1)
/* AEDF94 80076DF4 46004482 */  mul.s $f18, $f8, $f0
/* AEDF98 80076DF8 3C014F80 */  li    $at, 0x4F800000 # 0.000000
/* AEDF9C 80076DFC 448F3000 */  mtc1  $t7, $f6
/* AEDFA0 80076E00 05E10004 */  bgez  $t7, .L80076E14
/* AEDFA4 80076E04 46803120 */   cvt.s.w $f4, $f6
/* AEDFA8 80076E08 44815000 */  mtc1  $at, $f10
/* AEDFAC 80076E0C 00000000 */  nop   
/* AEDFB0 80076E10 460A2100 */  add.s $f4, $f4, $f10
.L80076E14:
/* AEDFB4 80076E14 46022202 */  mul.s $f8, $f4, $f2
/* AEDFB8 80076E18 90B90002 */  lbu   $t9, 2($a1)
/* AEDFBC 80076E1C 3C014F80 */  li    $at, 0x4F800000 # 0.000000
/* AEDFC0 80076E20 44992000 */  mtc1  $t9, $f4
/* AEDFC4 80076E24 46089180 */  add.s $f6, $f18, $f8
/* AEDFC8 80076E28 468024A0 */  cvt.s.w $f18, $f4
/* AEDFCC 80076E2C 4600328D */  trunc.w.s $f10, $f6
/* AEDFD0 80076E30 440A5000 */  mfc1  $t2, $f10
/* AEDFD4 80076E34 07210004 */  bgez  $t9, .L80076E48
/* AEDFD8 80076E38 314A00FF */   andi  $t2, $t2, 0xff
/* AEDFDC 80076E3C 44814000 */  mtc1  $at, $f8
/* AEDFE0 80076E40 00000000 */  nop   
/* AEDFE4 80076E44 46089480 */  add.s $f18, $f18, $f8
.L80076E48:
/* AEDFE8 80076E48 906E0002 */  lbu   $t6, 2($v1)
/* AEDFEC 80076E4C 46009182 */  mul.s $f6, $f18, $f0
/* AEDFF0 80076E50 3C014F80 */  li    $at, 0x4F800000 # 0.000000
/* AEDFF4 80076E54 448E5000 */  mtc1  $t6, $f10
/* AEDFF8 80076E58 05C10004 */  bgez  $t6, .L80076E6C
/* AEDFFC 80076E5C 46805120 */   cvt.s.w $f4, $f10
/* AEE000 80076E60 44814000 */  mtc1  $at, $f8
/* AEE004 80076E64 00000000 */  nop   
/* AEE008 80076E68 46082100 */  add.s $f4, $f4, $f8
.L80076E6C:
/* AEE00C 80076E6C 46022482 */  mul.s $f18, $f4, $f2
/* AEE010 80076E70 46123280 */  add.s $f10, $f6, $f18
/* AEE014 80076E74 4600520D */  trunc.w.s $f8, $f10
/* AEE018 80076E78 440B4000 */  mfc1  $t3, $f8
/* AEE01C 80076E7C 00000000 */  nop   
/* AEE020 80076E80 316B00FF */  andi  $t3, $t3, 0xff
.L80076E84:
/* AEE024 80076E84 44892000 */  mtc1  $t1, $f4
/* AEE028 80076E88 3C018014 */  lui   $at, %hi(D_8013C830)
/* AEE02C 80076E8C C42CC830 */  lwc1  $f12, %lo(D_8013C830)($at)
/* AEE030 80076E90 460E8001 */  sub.s $f0, $f16, $f14
/* AEE034 80076E94 05210005 */  bgez  $t1, .L80076EAC
/* AEE038 80076E98 468021A0 */   cvt.s.w $f6, $f4
/* AEE03C 80076E9C 3C014F80 */  li    $at, 0x4F800000 # 0.000000
/* AEE040 80076EA0 44819000 */  mtc1  $at, $f18
/* AEE044 80076EA4 00000000 */  nop   
/* AEE048 80076EA8 46123180 */  add.s $f6, $f6, $f18
.L80076EAC:
/* AEE04C 80076EAC 93B800A4 */  lbu   $t8, 0xa4($sp)
/* AEE050 80076EB0 460E3282 */  mul.s $f10, $f6, $f14
/* AEE054 80076EB4 44984000 */  mtc1  $t8, $f8
/* AEE058 80076EB8 07010005 */  bgez  $t8, .L80076ED0
/* AEE05C 80076EBC 46804120 */   cvt.s.w $f4, $f8
/* AEE060 80076EC0 3C014F80 */  li    $at, 0x4F800000 # 0.000000
/* AEE064 80076EC4 44819000 */  mtc1  $at, $f18
/* AEE068 80076EC8 00000000 */  nop   
/* AEE06C 80076ECC 46122100 */  add.s $f4, $f4, $f18
.L80076ED0:
/* AEE070 80076ED0 46040182 */  mul.s $f6, $f0, $f4
/* AEE074 80076ED4 24090001 */  li    $t1, 1
/* AEE078 80076ED8 46065200 */  add.s $f8, $f10, $f6
/* AEE07C 80076EDC 460C4482 */  mul.s $f18, $f8, $f12
/* AEE080 80076EE0 4459F800 */  cfc1  $t9, $31
/* AEE084 80076EE4 44C9F800 */  ctc1  $t1, $31
/* AEE088 80076EE8 00000000 */  nop   
/* AEE08C 80076EEC 46009124 */  cvt.w.s $f4, $f18
/* AEE090 80076EF0 4449F800 */  cfc1  $t1, $31
/* AEE094 80076EF4 00000000 */  nop   
/* AEE098 80076EF8 31290078 */  andi  $t1, $t1, 0x78
/* AEE09C 80076EFC 11200012 */  beqz  $t1, .L80076F48
/* AEE0A0 80076F00 3C014F00 */   li    $at, 0x4F000000 # 0.000000
/* AEE0A4 80076F04 44812000 */  mtc1  $at, $f4
/* AEE0A8 80076F08 24090001 */  li    $t1, 1
/* AEE0AC 80076F0C 46049101 */  sub.s $f4, $f18, $f4
/* AEE0B0 80076F10 44C9F800 */  ctc1  $t1, $31
/* AEE0B4 80076F14 00000000 */  nop   
/* AEE0B8 80076F18 46002124 */  cvt.w.s $f4, $f4
/* AEE0BC 80076F1C 4449F800 */  cfc1  $t1, $31
/* AEE0C0 80076F20 00000000 */  nop   
/* AEE0C4 80076F24 31290078 */  andi  $t1, $t1, 0x78
/* AEE0C8 80076F28 15200005 */  bnez  $t1, .L80076F40
/* AEE0CC 80076F2C 00000000 */   nop   
/* AEE0D0 80076F30 44092000 */  mfc1  $t1, $f4
/* AEE0D4 80076F34 3C018000 */  li    $at, 0x80000000 # 0.000000
/* AEE0D8 80076F38 10000007 */  b     .L80076F58
/* AEE0DC 80076F3C 01214825 */   or    $t1, $t1, $at
.L80076F40:
/* AEE0E0 80076F40 10000005 */  b     .L80076F58
/* AEE0E4 80076F44 2409FFFF */   li    $t1, -1
.L80076F48:
/* AEE0E8 80076F48 44092000 */  mfc1  $t1, $f4
/* AEE0EC 80076F4C 00000000 */  nop   
/* AEE0F0 80076F50 0520FFFB */  bltz  $t1, .L80076F40
/* AEE0F4 80076F54 00000000 */   nop   
.L80076F58:
/* AEE0F8 80076F58 44D9F800 */  ctc1  $t9, $31
/* AEE0FC 80076F5C 448A5000 */  mtc1  $t2, $f10
/* AEE100 80076F60 312900FF */  andi  $t1, $t1, 0xff
/* AEE104 80076F64 05410005 */  bgez  $t2, .L80076F7C
/* AEE108 80076F68 468051A0 */   cvt.s.w $f6, $f10
/* AEE10C 80076F6C 3C014F80 */  li    $at, 0x4F800000 # 0.000000
/* AEE110 80076F70 44814000 */  mtc1  $at, $f8
/* AEE114 80076F74 00000000 */  nop   
/* AEE118 80076F78 46083180 */  add.s $f6, $f6, $f8
.L80076F7C:
/* AEE11C 80076F7C 93AE00A5 */  lbu   $t6, 0xa5($sp)
/* AEE120 80076F80 460E3482 */  mul.s $f18, $f6, $f14
/* AEE124 80076F84 448E2000 */  mtc1  $t6, $f4
/* AEE128 80076F88 05C10005 */  bgez  $t6, .L80076FA0
/* AEE12C 80076F8C 468022A0 */   cvt.s.w $f10, $f4
/* AEE130 80076F90 3C014F80 */  li    $at, 0x4F800000 # 0.000000
/* AEE134 80076F94 44814000 */  mtc1  $at, $f8
/* AEE138 80076F98 00000000 */  nop   
/* AEE13C 80076F9C 46085280 */  add.s $f10, $f10, $f8
.L80076FA0:
/* AEE140 80076FA0 460A0182 */  mul.s $f6, $f0, $f10
/* AEE144 80076FA4 240A0001 */  li    $t2, 1
/* AEE148 80076FA8 3C0E8016 */  lui   $t6, %hi(D_8015FDB0) # $t6, 0x8016
/* AEE14C 80076FAC 46069100 */  add.s $f4, $f18, $f6
/* AEE150 80076FB0 460C2202 */  mul.s $f8, $f4, $f12
/* AEE154 80076FB4 444FF800 */  cfc1  $t7, $31
/* AEE158 80076FB8 44CAF800 */  ctc1  $t2, $31
/* AEE15C 80076FBC 00000000 */  nop   
/* AEE160 80076FC0 460042A4 */  cvt.w.s $f10, $f8
/* AEE164 80076FC4 444AF800 */  cfc1  $t2, $31
/* AEE168 80076FC8 00000000 */  nop   
/* AEE16C 80076FCC 314A0078 */  andi  $t2, $t2, 0x78
/* AEE170 80076FD0 11400012 */  beqz  $t2, .L8007701C
/* AEE174 80076FD4 3C014F00 */   li    $at, 0x4F000000 # 0.000000
/* AEE178 80076FD8 44815000 */  mtc1  $at, $f10
/* AEE17C 80076FDC 240A0001 */  li    $t2, 1
/* AEE180 80076FE0 460A4281 */  sub.s $f10, $f8, $f10
/* AEE184 80076FE4 44CAF800 */  ctc1  $t2, $31
/* AEE188 80076FE8 00000000 */  nop   
/* AEE18C 80076FEC 460052A4 */  cvt.w.s $f10, $f10
/* AEE190 80076FF0 444AF800 */  cfc1  $t2, $31
/* AEE194 80076FF4 00000000 */  nop   
/* AEE198 80076FF8 314A0078 */  andi  $t2, $t2, 0x78
/* AEE19C 80076FFC 15400005 */  bnez  $t2, .L80077014
/* AEE1A0 80077000 00000000 */   nop   
/* AEE1A4 80077004 440A5000 */  mfc1  $t2, $f10
/* AEE1A8 80077008 3C018000 */  li    $at, 0x80000000 # 0.000000
/* AEE1AC 8007700C 10000007 */  b     .L8007702C
/* AEE1B0 80077010 01415025 */   or    $t2, $t2, $at
.L80077014:
/* AEE1B4 80077014 10000005 */  b     .L8007702C
/* AEE1B8 80077018 240AFFFF */   li    $t2, -1
.L8007701C:
/* AEE1BC 8007701C 440A5000 */  mfc1  $t2, $f10
/* AEE1C0 80077020 00000000 */  nop   
/* AEE1C4 80077024 0540FFFB */  bltz  $t2, .L80077014
/* AEE1C8 80077028 00000000 */   nop   
.L8007702C:
/* AEE1CC 8007702C 44CFF800 */  ctc1  $t7, $31
/* AEE1D0 80077030 448B9000 */  mtc1  $t3, $f18
/* AEE1D4 80077034 314A00FF */  andi  $t2, $t2, 0xff
/* AEE1D8 80077038 05610005 */  bgez  $t3, .L80077050
/* AEE1DC 8007703C 468091A0 */   cvt.s.w $f6, $f18
/* AEE1E0 80077040 3C014F80 */  li    $at, 0x4F800000 # 0.000000
/* AEE1E4 80077044 44812000 */  mtc1  $at, $f4
/* AEE1E8 80077048 00000000 */  nop   
/* AEE1EC 8007704C 46043180 */  add.s $f6, $f6, $f4
.L80077050:
/* AEE1F0 80077050 93B800A6 */  lbu   $t8, 0xa6($sp)
/* AEE1F4 80077054 460E3202 */  mul.s $f8, $f6, $f14
/* AEE1F8 80077058 44985000 */  mtc1  $t8, $f10
/* AEE1FC 8007705C 07010005 */  bgez  $t8, .L80077074
/* AEE200 80077060 468054A0 */   cvt.s.w $f18, $f10
/* AEE204 80077064 3C014F80 */  li    $at, 0x4F800000 # 0.000000
/* AEE208 80077068 44812000 */  mtc1  $at, $f4
/* AEE20C 8007706C 00000000 */  nop   
/* AEE210 80077070 46049480 */  add.s $f18, $f18, $f4
.L80077074:
/* AEE214 80077074 46120182 */  mul.s $f6, $f0, $f18
/* AEE218 80077078 240B0001 */  li    $t3, 1
/* AEE21C 8007707C 46064280 */  add.s $f10, $f8, $f6
/* AEE220 80077080 460C5102 */  mul.s $f4, $f10, $f12
/* AEE224 80077084 4459F800 */  cfc1  $t9, $31
/* AEE228 80077088 44CBF800 */  ctc1  $t3, $31
/* AEE22C 8007708C 00000000 */  nop   
/* AEE230 80077090 460024A4 */  cvt.w.s $f18, $f4
/* AEE234 80077094 444BF800 */  cfc1  $t3, $31
/* AEE238 80077098 00000000 */  nop   
/* AEE23C 8007709C 316B0078 */  andi  $t3, $t3, 0x78
/* AEE240 800770A0 11600012 */  beqz  $t3, .L800770EC
/* AEE244 800770A4 3C014F00 */   li    $at, 0x4F000000 # 0.000000
/* AEE248 800770A8 44819000 */  mtc1  $at, $f18
/* AEE24C 800770AC 240B0001 */  li    $t3, 1
/* AEE250 800770B0 46122481 */  sub.s $f18, $f4, $f18
/* AEE254 800770B4 44CBF800 */  ctc1  $t3, $31
/* AEE258 800770B8 00000000 */  nop   
/* AEE25C 800770BC 460094A4 */  cvt.w.s $f18, $f18
/* AEE260 800770C0 444BF800 */  cfc1  $t3, $31
/* AEE264 800770C4 00000000 */  nop   
/* AEE268 800770C8 316B0078 */  andi  $t3, $t3, 0x78
/* AEE26C 800770CC 15600005 */  bnez  $t3, .L800770E4
/* AEE270 800770D0 00000000 */   nop   
/* AEE274 800770D4 440B9000 */  mfc1  $t3, $f18
/* AEE278 800770D8 3C018000 */  lui   $at, 0x8000
/* AEE27C 800770DC 10000007 */  b     .L800770FC
/* AEE280 800770E0 01615825 */   or    $t3, $t3, $at
.L800770E4:
/* AEE284 800770E4 10000005 */  b     .L800770FC
/* AEE288 800770E8 240BFFFF */   li    $t3, -1
.L800770EC:
/* AEE28C 800770EC 440B9000 */  mfc1  $t3, $f18
/* AEE290 800770F0 00000000 */  nop   
/* AEE294 800770F4 0560FFFB */  bltz  $t3, .L800770E4
/* AEE298 800770F8 00000000 */   nop   
.L800770FC:
/* AEE29C 800770FC 95CEFDB0 */  lhu   $t6, %lo(D_8015FDB0)($t6)
/* AEE2A0 80077100 44D9F800 */  ctc1  $t9, $31
/* AEE2A4 80077104 316B00FF */  andi  $t3, $t3, 0xff
/* AEE2A8 80077108 448E4000 */  mtc1  $t6, $f8
/* AEE2AC 8007710C 05C10005 */  bgez  $t6, .L80077124
/* AEE2B0 80077110 468040A0 */   cvt.s.w $f2, $f8
/* AEE2B4 80077114 3C014F80 */  li    $at, 0x4F800000 # 0.000000
/* AEE2B8 80077118 44813000 */  mtc1  $at, $f6
/* AEE2BC 8007711C 00000000 */  nop   
/* AEE2C0 80077120 46061080 */  add.s $f2, $f2, $f6
.L80077124:
/* AEE2C4 80077124 3C018014 */  lui   $at, %hi(D_8013C834)
/* AEE2C8 80077128 C42AC834 */  lwc1  $f10, %lo(D_8013C834)($at)
/* AEE2CC 8007712C 3C013FC0 */  li    $at, 0x3FC00000 # 0.000000
/* AEE2D0 80077130 44814000 */  mtc1  $at, $f8
/* AEE2D4 80077134 460A1102 */  mul.s $f4, $f2, $f10
/* AEE2D8 80077138 3C013F80 */  lui   $at, 0x3f80
/* AEE2DC 8007713C 8FB900B8 */  lw    $t9, 0xb8($sp)
/* AEE2E0 80077140 46081182 */  mul.s $f6, $f2, $f8
/* AEE2E4 80077144 3C068014 */  lui   $a2, %hi(D_8013C770)
/* AEE2E8 80077148 24C6C770 */  addiu $a2, %lo(D_8013C770) # addiu $a2, $a2, -0x3890
/* AEE2EC 8007714C 27A4007C */  addiu $a0, $sp, 0x7c
/* AEE2F0 80077150 24070FCC */  li    $a3, 4044
/* AEE2F4 80077154 4600248D */  trunc.w.s $f18, $f4
/* AEE2F8 80077158 44812000 */  mtc1  $at, $f4
/* AEE2FC 8007715C 4600328D */  trunc.w.s $f10, $f6
/* AEE300 80077160 44189000 */  mfc1  $t8, $f18
/* AEE304 80077164 46041482 */  mul.s $f18, $f2, $f4
/* AEE308 80077168 A7B80096 */  sh    $t8, 0x96($sp)
/* AEE30C 8007716C 440E5000 */  mfc1  $t6, $f10
/* AEE310 80077170 00000000 */  nop   
/* AEE314 80077174 A7AE0094 */  sh    $t6, 0x94($sp)
/* AEE318 80077178 4600920D */  trunc.w.s $f8, $f18
/* AEE31C 8007717C 44184000 */  mfc1  $t8, $f8
/* AEE320 80077180 00000000 */  nop   
/* AEE324 80077184 A7B80092 */  sh    $t8, 0x92($sp)
/* AEE328 80077188 8F250000 */  lw    $a1, ($t9)
/* AEE32C 8007718C E7AE0098 */  swc1  $f14, 0x98($sp)
/* AEE330 80077190 A3AB00A2 */  sb    $t3, 0xa2($sp)
/* AEE334 80077194 A3AA00A1 */  sb    $t2, 0xa1($sp)
/* AEE338 80077198 A3A900A0 */  sb    $t1, 0xa0($sp)
/* AEE33C 8007719C 0C031AB1 */  jal   Graph_OpenDisps
/* AEE340 800771A0 AFA5008C */   sw    $a1, 0x8c($sp)
/* AEE344 800771A4 8FA3008C */  lw    $v1, 0x8c($sp)
/* AEE348 800771A8 0C024FCD */  jal   func_80093F34
/* AEE34C 800771AC 8C6402D0 */   lw    $a0, 0x2d0($v1)
/* AEE350 800771B0 8FA3008C */  lw    $v1, 0x8c($sp)
/* AEE354 800771B4 93A900A0 */  lbu   $t1, 0xa0($sp)
/* AEE358 800771B8 93AA00A1 */  lbu   $t2, 0xa1($sp)
/* AEE35C 800771BC 93AB00A2 */  lbu   $t3, 0xa2($sp)
/* AEE360 800771C0 C7AE0098 */  lwc1  $f14, 0x98($sp)
/* AEE364 800771C4 244E0008 */  addiu $t6, $v0, 8
/* AEE368 800771C8 AC6202D0 */  sw    $v0, 0x2d0($v1)
/* AEE36C 800771CC 3C0FE300 */  lui   $t7, (0xE3001A01 >> 16) # lui $t7, 0xe300
/* AEE370 800771D0 AC6E02D0 */  sw    $t6, 0x2d0($v1)
/* AEE374 800771D4 35EF1A01 */  ori   $t7, (0xE3001A01 & 0xFFFF) # ori $t7, $t7, 0x1a01
/* AEE378 800771D8 24180020 */  li    $t8, 32
/* AEE37C 800771DC AC580004 */  sw    $t8, 4($v0)
/* AEE380 800771E0 AC4F0000 */  sw    $t7, ($v0)
/* AEE384 800771E4 8C6202D0 */  lw    $v0, 0x2d0($v1)
/* AEE388 800771E8 3C0EE300 */  lui   $t6, (0xE3001801 >> 16) # lui $t6, 0xe300
/* AEE38C 800771EC 35CE1801 */  ori   $t6, (0xE3001801 & 0xFFFF) # ori $t6, $t6, 0x1801
/* AEE390 800771F0 24590008 */  addiu $t9, $v0, 8
/* AEE394 800771F4 AC7902D0 */  sw    $t9, 0x2d0($v1)
/* AEE398 800771F8 240F0080 */  li    $t7, 128
/* AEE39C 800771FC AC4F0004 */  sw    $t7, 4($v0)
/* AEE3A0 80077200 AC4E0000 */  sw    $t6, ($v0)
/* AEE3A4 80077204 8C6202D0 */  lw    $v0, 0x2d0($v1)
/* AEE3A8 80077208 3C19FA00 */  lui   $t9, (0xFA000080 >> 16) # lui $t9, 0xfa00
/* AEE3AC 8007720C 37390080 */  ori   $t9, (0xFA000080 & 0xFFFF) # ori $t9, $t9, 0x80
/* AEE3B0 80077210 24580008 */  addiu $t8, $v0, 8
/* AEE3B4 80077214 AC7802D0 */  sw    $t8, 0x2d0($v1)
/* AEE3B8 80077218 AC590000 */  sw    $t9, ($v0)
/* AEE3BC 8007721C 93AF00A4 */  lbu   $t7, 0xa4($sp)
/* AEE3C0 80077220 93AE00A5 */  lbu   $t6, 0xa5($sp)
/* AEE3C4 80077224 00002825 */  move  $a1, $zero
/* AEE3C8 80077228 000FC600 */  sll   $t8, $t7, 0x18
/* AEE3CC 8007722C 000E7C00 */  sll   $t7, $t6, 0x10
/* AEE3D0 80077230 030FC825 */  or    $t9, $t8, $t7
/* AEE3D4 80077234 93B800A6 */  lbu   $t8, 0xa6($sp)
/* AEE3D8 80077238 00003825 */  move  $a3, $zero
/* AEE3DC 8007723C 00187A00 */  sll   $t7, $t8, 8
/* AEE3E0 80077240 8FB80058 */  lw    $t8, 0x58($sp)
/* AEE3E4 80077244 032F7025 */  or    $t6, $t9, $t7
/* AEE3E8 80077248 930F0B0B */  lbu   $t7, 0xb0b($t8)
/* AEE3EC 8007724C 01CFC025 */  or    $t8, $t6, $t7
/* AEE3F0 80077250 AC580004 */  sw    $t8, 4($v0)
/* AEE3F4 80077254 8C6202D0 */  lw    $v0, 0x2d0($v1)
/* AEE3F8 80077258 3C0EFB00 */  lui   $t6, 0xfb00
/* AEE3FC 8007725C 0009C600 */  sll   $t8, $t1, 0x18
/* AEE400 80077260 24590008 */  addiu $t9, $v0, 8
/* AEE404 80077264 AC7902D0 */  sw    $t9, 0x2d0($v1)
/* AEE408 80077268 AC4E0000 */  sw    $t6, ($v0)
/* AEE40C 8007726C 000A7400 */  sll   $t6, $t2, 0x10
/* AEE410 80077270 8FB90058 */  lw    $t9, 0x58($sp)
/* AEE414 80077274 030E7825 */  or    $t7, $t8, $t6
/* AEE418 80077278 000BC200 */  sll   $t8, $t3, 8
/* AEE41C 8007727C 01F87025 */  or    $t6, $t7, $t8
/* AEE420 80077280 93380B0C */  lbu   $t8, 0xb0c($t9)
/* AEE424 80077284 01D8C825 */  or    $t9, $t6, $t8
/* AEE428 80077288 AC590004 */  sw    $t9, 4($v0)
/* AEE42C 8007728C 8C6202D0 */  lw    $v0, 0x2d0($v1)
/* AEE430 80077290 3C0EDB06 */  lui   $t6, (0xDB060020 >> 16) # lui $t6, 0xdb06
/* AEE434 80077294 35CE0020 */  ori   $t6, (0xDB060020 & 0xFFFF) # ori $t6, $t6, 0x20
/* AEE438 80077298 244F0008 */  addiu $t7, $v0, 8
/* AEE43C 8007729C AC6F02D0 */  sw    $t7, 0x2d0($v1)
/* AEE440 800772A0 AC4E0000 */  sw    $t6, ($v0)
/* AEE444 800772A4 8FB800B8 */  lw    $t8, 0xb8($sp)
/* AEE448 800772A8 240F0020 */  li    $t7, 32
/* AEE44C 800772AC 24190200 */  li    $t9, 512
/* AEE450 800772B0 8F040000 */  lw    $a0, ($t8)
/* AEE454 800772B4 97B80094 */  lhu   $t8, 0x94($sp)
/* AEE458 800772B8 AFAF0014 */  sw    $t7, 0x14($sp)
/* AEE45C 800772BC 97AF0092 */  lhu   $t7, 0x92($sp)
/* AEE460 800772C0 AFB90010 */  sw    $t9, 0x10($sp)
/* AEE464 800772C4 240E0001 */  li    $t6, 1
/* AEE468 800772C8 33190FFF */  andi  $t9, $t8, 0xfff
/* AEE46C 800772CC AFAE0018 */  sw    $t6, 0x18($sp)
/* AEE470 800772D0 AFB9001C */  sw    $t9, 0x1c($sp)
/* AEE474 800772D4 24180FFF */  li    $t8, 4095
/* AEE478 800772D8 31EE0FFF */  andi  $t6, $t7, 0xfff
/* AEE47C 800772DC 97A60096 */  lhu   $a2, 0x96($sp)
/* AEE480 800772E0 030EC823 */  subu  $t9, $t8, $t6
/* AEE484 800772E4 24180040 */  li    $t8, 64
/* AEE488 800772E8 240F0100 */  li    $t7, 256
/* AEE48C 800772EC AFAF0024 */  sw    $t7, 0x24($sp)
/* AEE490 800772F0 AFB80028 */  sw    $t8, 0x28($sp)
/* AEE494 800772F4 AFB90020 */  sw    $t9, 0x20($sp)
/* AEE498 800772F8 AFA3008C */  sw    $v1, 0x8c($sp)
/* AEE49C 800772FC E7AE0098 */  swc1  $f14, 0x98($sp)
/* AEE4A0 80077300 AFA20068 */  sw    $v0, 0x68($sp)
/* AEE4A4 80077304 0C0253D0 */  jal   Gfx_TwoTexScroll
/* AEE4A8 80077308 30C60FFF */   andi  $a2, $a2, 0xfff
/* AEE4AC 8007730C 8FA80068 */  lw    $t0, 0x68($sp)
/* AEE4B0 80077310 8FA3008C */  lw    $v1, 0x8c($sp)
/* AEE4B4 80077314 C7AE0098 */  lwc1  $f14, 0x98($sp)
/* AEE4B8 80077318 AD020004 */  sw    $v0, 4($t0)
/* AEE4BC 8007731C 8C6202D0 */  lw    $v0, 0x2d0($v1)
/* AEE4C0 80077320 3C19E300 */  lui   $t9, (0xE3001001 >> 16) # lui $t9, 0xe300
/* AEE4C4 80077324 37391001 */  ori   $t9, (0xE3001001 & 0xFFFF) # ori $t9, $t9, 0x1001
/* AEE4C8 80077328 244E0008 */  addiu $t6, $v0, 8
/* AEE4CC 8007732C AC6E02D0 */  sw    $t6, 0x2d0($v1)
/* AEE4D0 80077330 AC400004 */  sw    $zero, 4($v0)
/* AEE4D4 80077334 AC590000 */  sw    $t9, ($v0)
/* AEE4D8 80077338 8C6202D0 */  lw    $v0, 0x2d0($v1)
/* AEE4DC 8007733C 3C0E0501 */  lui   $t6, %hi(D_0500CA70) # $t6, 0x501
/* AEE4E0 80077340 25CECA70 */  addiu $t6, %lo(D_0500CA70) # addiu $t6, $t6, -0x3590
/* AEE4E4 80077344 244F0008 */  addiu $t7, $v0, 8
/* AEE4E8 80077348 AC6F02D0 */  sw    $t7, 0x2d0($v1)
/* AEE4EC 8007734C 3C18DE00 */  lui   $t8, 0xde00
/* AEE4F0 80077350 AC580000 */  sw    $t8, ($v0)
/* AEE4F4 80077354 AC4E0004 */  sw    $t6, 4($v0)
/* AEE4F8 80077358 8FB900B8 */  lw    $t9, 0xb8($sp)
/* AEE4FC 8007735C 3C068014 */  lui   $a2, %hi(D_8013C780) # $a2, 0x8014
/* AEE500 80077360 24C6C780 */  addiu $a2, %lo(D_8013C780) # addiu $a2, $a2, -0x3880
/* AEE504 80077364 8F250000 */  lw    $a1, ($t9)
/* AEE508 80077368 27A4007C */  addiu $a0, $sp, 0x7c
/* AEE50C 8007736C 24070FE4 */  li    $a3, 4068
/* AEE510 80077370 0C031AD5 */  jal   Graph_CloseDisps
/* AEE514 80077374 E7AE0098 */   swc1  $f14, 0x98($sp)
/* AEE518 80077378 C7AE0098 */  lwc1  $f14, 0x98($sp)
/* AEE51C 8007737C 3C028016 */  lui   $v0, %hi(D_8015FDB0) # $v0, 0x8016
/* AEE520 80077380 2442FDB0 */  addiu $v0, %lo(D_8015FDB0) # addiu $v0, $v0, -0x250
/* AEE524 80077384 4600718D */  trunc.w.s $f6, $f14
/* AEE528 80077388 944F0000 */  lhu   $t7, ($v0)
/* AEE52C 8007738C 8FBF0034 */  lw    $ra, 0x34($sp)
/* AEE530 80077390 27BD00B8 */  addiu $sp, $sp, 0xb8
/* AEE534 80077394 440E3000 */  mfc1  $t6, $f6
/* AEE538 80077398 00000000 */  nop   
/* AEE53C 8007739C 01EEC821 */  addu  $t9, $t7, $t6
/* AEE540 800773A0 03E00008 */  jr    $ra
/* AEE544 800773A4 A4590000 */   sh    $t9, ($v0)

