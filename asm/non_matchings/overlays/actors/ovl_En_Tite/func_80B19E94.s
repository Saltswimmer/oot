glabel func_80B19E94
/* 01414 80B19E94 44800000 */  mtc1    $zero, $f0                 ## $f0 = 0.00
/* 01418 80B19E98 27BDFFD0 */  addiu   $sp, $sp, 0xFFD0           ## $sp = FFFFFFD0
/* 0141C 80B19E9C AFB00028 */  sw      $s0, 0x0028($sp)           
/* 01420 80B19EA0 AFA50034 */  sw      $a1, 0x0034($sp)           
/* 01424 80B19EA4 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 01428 80B19EA8 AFBF002C */  sw      $ra, 0x002C($sp)           
/* 0142C 80B19EAC 44050000 */  mfc1    $a1, $f0                   
/* 01430 80B19EB0 24840068 */  addiu   $a0, $a0, 0x0068           ## $a0 = 00000068
/* 01434 80B19EB4 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 01438 80B19EB8 3C073F00 */  lui     $a3, 0x3F00                ## $a3 = 3F000000
/* 0143C 80B19EBC 0C01E0C4 */  jal     Math_SmoothStepToF
              
/* 01440 80B19EC0 E7A00010 */  swc1    $f0, 0x0010($sp)           
/* 01444 80B19EC4 96020088 */  lhu     $v0, 0x0088($s0)           ## 00000088
/* 01448 80B19EC8 304E0003 */  andi    $t6, $v0, 0x0003           ## $t6 = 00000000
/* 0144C 80B19ECC 55C00009 */  bnel    $t6, $zero, .L80B19EF4     
/* 01450 80B19ED0 44801000 */  mtc1    $zero, $f2                 ## $f2 = 0.00
/* 01454 80B19ED4 860F001C */  lh      $t7, 0x001C($s0)           ## 0000001C
/* 01458 80B19ED8 2408FFFE */  addiu   $t0, $zero, 0xFFFE         ## $t0 = FFFFFFFE
/* 0145C 80B19EDC 30580020 */  andi    $t8, $v0, 0x0020           ## $t8 = 00000000
/* 01460 80B19EE0 550F0023 */  bnel    $t0, $t7, .L80B19F70       
/* 01464 80B19EE4 44801000 */  mtc1    $zero, $f2                 ## $f2 = 0.00
/* 01468 80B19EE8 53000021 */  beql    $t8, $zero, .L80B19F70     
/* 0146C 80B19EEC 44801000 */  mtc1    $zero, $f2                 ## $f2 = 0.00
/* 01470 80B19EF0 44801000 */  mtc1    $zero, $f2                 ## $f2 = 0.00
.L80B19EF4:
/* 01474 80B19EF4 C6040060 */  lwc1    $f4, 0x0060($s0)           ## 00000060
/* 01478 80B19EF8 2408FFFE */  addiu   $t0, $zero, 0xFFFE         ## $t0 = FFFFFFFE
/* 0147C 80B19EFC 4602203E */  c.le.s  $f4, $f2                   
/* 01480 80B19F00 00000000 */  nop
/* 01484 80B19F04 4502001A */  bc1fl   .L80B19F70                 
/* 01488 80B19F08 44801000 */  mtc1    $zero, $f2                 ## $f2 = 0.00
/* 0148C 80B19F0C 8619001C */  lh      $t9, 0x001C($s0)           ## 0000001C
/* 01490 80B19F10 30490020 */  andi    $t1, $v0, 0x0020           ## $t1 = 00000000
/* 01494 80B19F14 3C01C6FA */  lui     $at, 0xC6FA                ## $at = C6FA0000
/* 01498 80B19F18 55190004 */  bnel    $t0, $t9, .L80B19F2C       
/* 0149C 80B19F1C C6000080 */  lwc1    $f0, 0x0080($s0)           ## 00000080
/* 014A0 80B19F20 5520000C */  bnel    $t1, $zero, .L80B19F54     
/* 014A4 80B19F24 C6080028 */  lwc1    $f8, 0x0028($s0)           ## 00000028
/* 014A8 80B19F28 C6000080 */  lwc1    $f0, 0x0080($s0)           ## 00000080
.L80B19F2C:
/* 014AC 80B19F2C 44813000 */  mtc1    $at, $f6                   ## $f6 = -32000.00
/* 014B0 80B19F30 00000000 */  nop
/* 014B4 80B19F34 4600303C */  c.lt.s  $f6, $f0                   
/* 014B8 80B19F38 00000000 */  nop
/* 014BC 80B19F3C 4502000C */  bc1fl   .L80B19F70                 
/* 014C0 80B19F40 44801000 */  mtc1    $zero, $f2                 ## $f2 = 0.00
/* 014C4 80B19F44 E6000028 */  swc1    $f0, 0x0028($s0)           ## 00000028
/* 014C8 80B19F48 10000008 */  beq     $zero, $zero, .L80B19F6C   
/* 014CC 80B19F4C 96020088 */  lhu     $v0, 0x0088($s0)           ## 00000088
/* 014D0 80B19F50 C6080028 */  lwc1    $f8, 0x0028($s0)           ## 00000028
.L80B19F54:
/* 014D4 80B19F54 C60A0084 */  lwc1    $f10, 0x0084($s0)          ## 00000084
/* 014D8 80B19F58 E6020060 */  swc1    $f2, 0x0060($s0)           ## 00000060
/* 014DC 80B19F5C E602006C */  swc1    $f2, 0x006C($s0)           ## 0000006C
/* 014E0 80B19F60 460A4400 */  add.s   $f16, $f8, $f10            
/* 014E4 80B19F64 96020088 */  lhu     $v0, 0x0088($s0)           ## 00000088
/* 014E8 80B19F68 E6100028 */  swc1    $f16, 0x0028($s0)          ## 00000028
.L80B19F6C:
/* 014EC 80B19F6C 44801000 */  mtc1    $zero, $f2                 ## $f2 = 0.00
.L80B19F70:
/* 014F0 80B19F70 304A0042 */  andi    $t2, $v0, 0x0042           ## $t2 = 00000000
/* 014F4 80B19F74 1140003B */  beq     $t2, $zero, .L80B1A064     
/* 014F8 80B19F78 304B0040 */  andi    $t3, $v0, 0x0040           ## $t3 = 00000000
/* 014FC 80B19F7C 15600033 */  bne     $t3, $zero, .L80B1A04C     
/* 01500 80B19F80 304FFFBF */  andi    $t7, $v0, 0xFFBF           ## $t7 = 00000000
/* 01504 80B19F84 240C0050 */  addiu   $t4, $zero, 0x0050         ## $t4 = 00000050
/* 01508 80B19F88 240D000F */  addiu   $t5, $zero, 0x000F         ## $t5 = 0000000F
/* 0150C 80B19F8C 240E0001 */  addiu   $t6, $zero, 0x0001         ## $t6 = 00000001
/* 01510 80B19F90 AFAE0018 */  sw      $t6, 0x0018($sp)           
/* 01514 80B19F94 AFAD0014 */  sw      $t5, 0x0014($sp)           
/* 01518 80B19F98 AFAC0010 */  sw      $t4, 0x0010($sp)           
/* 0151C 80B19F9C 8FA40034 */  lw      $a0, 0x0034($sp)           
/* 01520 80B19FA0 26050348 */  addiu   $a1, $s0, 0x0348           ## $a1 = 00000348
/* 01524 80B19FA4 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 01528 80B19FA8 0C00CD20 */  jal     func_80033480              
/* 0152C 80B19FAC 24070002 */  addiu   $a3, $zero, 0x0002         ## $a3 = 00000002
/* 01530 80B19FB0 240F0050 */  addiu   $t7, $zero, 0x0050         ## $t7 = 00000050
/* 01534 80B19FB4 2418000F */  addiu   $t8, $zero, 0x000F         ## $t8 = 0000000F
/* 01538 80B19FB8 24190001 */  addiu   $t9, $zero, 0x0001         ## $t9 = 00000001
/* 0153C 80B19FBC AFB90018 */  sw      $t9, 0x0018($sp)           
/* 01540 80B19FC0 AFB80014 */  sw      $t8, 0x0014($sp)           
/* 01544 80B19FC4 AFAF0010 */  sw      $t7, 0x0010($sp)           
/* 01548 80B19FC8 8FA40034 */  lw      $a0, 0x0034($sp)           
/* 0154C 80B19FCC 26050354 */  addiu   $a1, $s0, 0x0354           ## $a1 = 00000354
/* 01550 80B19FD0 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 01554 80B19FD4 0C00CD20 */  jal     func_80033480              
/* 01558 80B19FD8 24070002 */  addiu   $a3, $zero, 0x0002         ## $a3 = 00000002
/* 0155C 80B19FDC 24090050 */  addiu   $t1, $zero, 0x0050         ## $t1 = 00000050
/* 01560 80B19FE0 240A000F */  addiu   $t2, $zero, 0x000F         ## $t2 = 0000000F
/* 01564 80B19FE4 240B0001 */  addiu   $t3, $zero, 0x0001         ## $t3 = 00000001
/* 01568 80B19FE8 AFAB0018 */  sw      $t3, 0x0018($sp)           
/* 0156C 80B19FEC AFAA0014 */  sw      $t2, 0x0014($sp)           
/* 01570 80B19FF0 AFA90010 */  sw      $t1, 0x0010($sp)           
/* 01574 80B19FF4 8FA40034 */  lw      $a0, 0x0034($sp)           
/* 01578 80B19FF8 26050360 */  addiu   $a1, $s0, 0x0360           ## $a1 = 00000360
/* 0157C 80B19FFC 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 01580 80B1A000 0C00CD20 */  jal     func_80033480              
/* 01584 80B1A004 24070002 */  addiu   $a3, $zero, 0x0002         ## $a3 = 00000002
/* 01588 80B1A008 240C0050 */  addiu   $t4, $zero, 0x0050         ## $t4 = 00000050
/* 0158C 80B1A00C 240D000F */  addiu   $t5, $zero, 0x000F         ## $t5 = 0000000F
/* 01590 80B1A010 240E0001 */  addiu   $t6, $zero, 0x0001         ## $t6 = 00000001
/* 01594 80B1A014 AFAE0018 */  sw      $t6, 0x0018($sp)           
/* 01598 80B1A018 AFAD0014 */  sw      $t5, 0x0014($sp)           
/* 0159C 80B1A01C AFAC0010 */  sw      $t4, 0x0010($sp)           
/* 015A0 80B1A020 8FA40034 */  lw      $a0, 0x0034($sp)           
/* 015A4 80B1A024 2605036C */  addiu   $a1, $s0, 0x036C           ## $a1 = 0000036C
/* 015A8 80B1A028 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 015AC 80B1A02C 0C00CD20 */  jal     func_80033480              
/* 015B0 80B1A030 24070002 */  addiu   $a3, $zero, 0x0002         ## $a3 = 00000002
/* 015B4 80B1A034 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 015B8 80B1A038 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 015BC 80B1A03C 2405387B */  addiu   $a1, $zero, 0x387B         ## $a1 = 0000387B
/* 015C0 80B1A040 44801000 */  mtc1    $zero, $f2                 ## $f2 = 0.00
/* 015C4 80B1A044 10000007 */  beq     $zero, $zero, .L80B1A064   
/* 015C8 80B1A048 2408FFFE */  addiu   $t0, $zero, 0xFFFE         ## $t0 = FFFFFFFE
.L80B1A04C:
/* 015CC 80B1A04C A60F0088 */  sh      $t7, 0x0088($s0)           ## 00000088
/* 015D0 80B1A050 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 015D4 80B1A054 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 015D8 80B1A058 2405388F */  addiu   $a1, $zero, 0x388F         ## $a1 = 0000388F
/* 015DC 80B1A05C 44801000 */  mtc1    $zero, $f2                 ## $f2 = 0.00
/* 015E0 80B1A060 2408FFFE */  addiu   $t0, $zero, 0xFFFE         ## $t0 = FFFFFFFE
.L80B1A064:
/* 015E4 80B1A064 C6120068 */  lwc1    $f18, 0x0068($s0)          ## 00000068
/* 015E8 80B1A068 860300B6 */  lh      $v1, 0x00B6($s0)           ## 000000B6
/* 015EC 80B1A06C 8618008A */  lh      $t8, 0x008A($s0)           ## 0000008A
/* 015F0 80B1A070 46121032 */  c.eq.s  $f2, $f18                  
/* 015F4 80B1A074 03032023 */  subu    $a0, $t8, $v1              
/* 015F8 80B1A078 00042400 */  sll     $a0, $a0, 16               
/* 015FC 80B1A07C 45000054 */  bc1f    .L80B1A1D0                 
/* 01600 80B1A080 00042403 */  sra     $a0, $a0, 16               
/* 01604 80B1A084 96020088 */  lhu     $v0, 0x0088($s0)           ## 00000088
/* 01608 80B1A088 3C014396 */  lui     $at, 0x4396                ## $at = 43960000
/* 0160C 80B1A08C 30590001 */  andi    $t9, $v0, 0x0001           ## $t9 = 00000000
/* 01610 80B1A090 57200008 */  bnel    $t9, $zero, .L80B1A0B4     
/* 01614 80B1A094 C6000090 */  lwc1    $f0, 0x0090($s0)           ## 00000090
/* 01618 80B1A098 8609001C */  lh      $t1, 0x001C($s0)           ## 0000001C
/* 0161C 80B1A09C 304A0020 */  andi    $t2, $v0, 0x0020           ## $t2 = 00000000
/* 01620 80B1A0A0 1509004B */  bne     $t0, $t1, .L80B1A1D0       
/* 01624 80B1A0A4 00000000 */  nop
/* 01628 80B1A0A8 11400049 */  beq     $t2, $zero, .L80B1A1D0     
/* 0162C 80B1A0AC 00000000 */  nop
/* 01630 80B1A0B0 C6000090 */  lwc1    $f0, 0x0090($s0)           ## 00000090
.L80B1A0B4:
/* 01634 80B1A0B4 44812000 */  mtc1    $at, $f4                   ## $f4 = 300.00
/* 01638 80B1A0B8 920B02F8 */  lbu     $t3, 0x02F8($s0)           ## 000002F8
/* 0163C 80B1A0BC A6030032 */  sh      $v1, 0x0032($s0)           ## 00000032
/* 01640 80B1A0C0 4600203C */  c.lt.s  $f4, $f0                   
/* 01644 80B1A0C4 316CFFFD */  andi    $t4, $t3, 0xFFFD           ## $t4 = 00000000
/* 01648 80B1A0C8 A20C02F8 */  sb      $t4, 0x02F8($s0)           ## 000002F8
/* 0164C 80B1A0CC 3C0142A0 */  lui     $at, 0x42A0                ## $at = 42A00000
/* 01650 80B1A0D0 45020026 */  bc1fl   .L80B1A16C                 
/* 01654 80B1A0D4 3C014334 */  lui     $at, 0x4334                ## $at = 43340000
/* 01658 80B1A0D8 44813000 */  mtc1    $at, $f6                   ## $f6 = 180.00
/* 0165C 80B1A0DC C6080094 */  lwc1    $f8, 0x0094($s0)           ## 00000094
/* 01660 80B1A0E0 4608303C */  c.lt.s  $f6, $f8                   
/* 01664 80B1A0E4 00000000 */  nop
/* 01668 80B1A0E8 45020020 */  bc1fl   .L80B1A16C                 
/* 0166C 80B1A0EC 3C014334 */  lui     $at, 0x4334                ## $at = 43340000
/* 01670 80B1A0F0 860200B4 */  lh      $v0, 0x00B4($s0)           ## 000000B4
/* 01674 80B1A0F4 04400003 */  bltz    $v0, .L80B1A104            
/* 01678 80B1A0F8 00021823 */  subu    $v1, $zero, $v0            
/* 0167C 80B1A0FC 10000001 */  beq     $zero, $zero, .L80B1A104   
/* 01680 80B1A100 00401825 */  or      $v1, $v0, $zero            ## $v1 = 00000000
.L80B1A104:
/* 01684 80B1A104 28610FA0 */  slti    $at, $v1, 0x0FA0           
/* 01688 80B1A108 50200018 */  beql    $at, $zero, .L80B1A16C     
/* 0168C 80B1A10C 3C014334 */  lui     $at, 0x4334                ## $at = 43340000
/* 01690 80B1A110 860200B8 */  lh      $v0, 0x00B8($s0)           ## 000000B8
/* 01694 80B1A114 04400003 */  bltz    $v0, .L80B1A124            
/* 01698 80B1A118 00021823 */  subu    $v1, $zero, $v0            
/* 0169C 80B1A11C 10000001 */  beq     $zero, $zero, .L80B1A124   
/* 016A0 80B1A120 00401825 */  or      $v1, $v0, $zero            ## $v1 = 00000000
.L80B1A124:
/* 016A4 80B1A124 28610FA0 */  slti    $at, $v1, 0x0FA0           
/* 016A8 80B1A128 50200010 */  beql    $at, $zero, .L80B1A16C     
/* 016AC 80B1A12C 3C014334 */  lui     $at, 0x4334                ## $at = 43340000
/* 016B0 80B1A130 96020088 */  lhu     $v0, 0x0088($s0)           ## 00000088
/* 016B4 80B1A134 304D0001 */  andi    $t5, $v0, 0x0001           ## $t5 = 00000000
/* 016B8 80B1A138 15A00007 */  bne     $t5, $zero, .L80B1A158     
/* 016BC 80B1A13C 00000000 */  nop
/* 016C0 80B1A140 860E001C */  lh      $t6, 0x001C($s0)           ## 0000001C
/* 016C4 80B1A144 304F0020 */  andi    $t7, $v0, 0x0020           ## $t7 = 00000000
/* 016C8 80B1A148 550E0008 */  bnel    $t0, $t6, .L80B1A16C       
/* 016CC 80B1A14C 3C014334 */  lui     $at, 0x4334                ## $at = 43340000
/* 016D0 80B1A150 51E00006 */  beql    $t7, $zero, .L80B1A16C     
/* 016D4 80B1A154 3C014334 */  lui     $at, 0x4334                ## $at = 43340000
.L80B1A158:
/* 016D8 80B1A158 0C2C6317 */  jal     func_80B18C5C              
/* 016DC 80B1A15C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 016E0 80B1A160 1000001B */  beq     $zero, $zero, .L80B1A1D0   
/* 016E4 80B1A164 00000000 */  nop
/* 016E8 80B1A168 3C014334 */  lui     $at, 0x4334                ## $at = 43340000
.L80B1A16C:
/* 016EC 80B1A16C 44815000 */  mtc1    $at, $f10                  ## $f10 = 180.00
/* 016F0 80B1A170 3C0142A0 */  lui     $at, 0x42A0                ## $at = 42A00000
/* 016F4 80B1A174 460A003C */  c.lt.s  $f0, $f10                  
/* 016F8 80B1A178 00000000 */  nop
/* 016FC 80B1A17C 45000012 */  bc1f    .L80B1A1C8                 
/* 01700 80B1A180 00000000 */  nop
/* 01704 80B1A184 44818000 */  mtc1    $at, $f16                  ## $f16 = 80.00
/* 01708 80B1A188 C6120094 */  lwc1    $f18, 0x0094($s0)          ## 00000094
/* 0170C 80B1A18C 4610903E */  c.le.s  $f18, $f16                 
/* 01710 80B1A190 00000000 */  nop
/* 01714 80B1A194 4500000C */  bc1f    .L80B1A1C8                 
/* 01718 80B1A198 00000000 */  nop
/* 0171C 80B1A19C 04800003 */  bltz    $a0, .L80B1A1AC            
/* 01720 80B1A1A0 00041823 */  subu    $v1, $zero, $a0            
/* 01724 80B1A1A4 10000001 */  beq     $zero, $zero, .L80B1A1AC   
/* 01728 80B1A1A8 00801825 */  or      $v1, $a0, $zero            ## $v1 = 00000000
.L80B1A1AC:
/* 0172C 80B1A1AC 28611771 */  slti    $at, $v1, 0x1771           
/* 01730 80B1A1B0 10200005 */  beq     $at, $zero, .L80B1A1C8     
/* 01734 80B1A1B4 00000000 */  nop
/* 01738 80B1A1B8 0C2C6382 */  jal     func_80B18E08              
/* 0173C 80B1A1BC 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01740 80B1A1C0 10000003 */  beq     $zero, $zero, .L80B1A1D0   
/* 01744 80B1A1C4 00000000 */  nop
.L80B1A1C8:
/* 01748 80B1A1C8 0C2C6617 */  jal     func_80B1985C              
/* 0174C 80B1A1CC 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
.L80B1A1D0:
/* 01750 80B1A1D0 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 01754 80B1A1D4 2604014C */  addiu   $a0, $s0, 0x014C           ## $a0 = 0000014C
/* 01758 80B1A1D8 8FBF002C */  lw      $ra, 0x002C($sp)           
/* 0175C 80B1A1DC 8FB00028 */  lw      $s0, 0x0028($sp)           
/* 01760 80B1A1E0 27BD0030 */  addiu   $sp, $sp, 0x0030           ## $sp = 00000000
/* 01764 80B1A1E4 03E00008 */  jr      $ra                        
/* 01768 80B1A1E8 00000000 */  nop
