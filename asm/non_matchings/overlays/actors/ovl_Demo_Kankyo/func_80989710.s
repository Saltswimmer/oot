glabel func_80989710
/* 00890 80989710 27BDFFD0 */  addiu   $sp, $sp, 0xFFD0           ## $sp = FFFFFFD0
/* 00894 80989714 00067880 */  sll     $t7, $a2,  2               
/* 00898 80989718 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 0089C 8098971C AFA40030 */  sw      $a0, 0x0030($sp)           
/* 008A0 80989720 AFA60038 */  sw      $a2, 0x0038($sp)           
/* 008A4 80989724 00AFC021 */  addu    $t8, $a1, $t7              
/* 008A8 80989728 8F021D8C */  lw      $v0, 0x1D8C($t8)           ## 00001D8C
/* 008AC 8098972C 00A03825 */  or      $a3, $a1, $zero            ## $a3 = 00000000
/* 008B0 80989730 8C4A0018 */  lw      $t2, 0x0018($v0)           ## 00000018
/* 008B4 80989734 8C59000C */  lw      $t9, 0x000C($v0)           ## 0000000C
/* 008B8 80989738 8C480010 */  lw      $t0, 0x0010($v0)           ## 00000010
/* 008BC 8098973C 448A5000 */  mtc1    $t2, $f10                  ## $f10 = 0.00
/* 008C0 80989740 8C490014 */  lw      $t1, 0x0014($v0)           ## 00000014
/* 008C4 80989744 44992000 */  mtc1    $t9, $f4                   ## $f4 = 0.00
/* 008C8 80989748 46805420 */  cvt.s.w $f16, $f10                 
/* 008CC 8098974C 44883000 */  mtc1    $t0, $f6                   ## $f6 = 0.00
/* 008D0 80989750 44894000 */  mtc1    $t1, $f8                   ## $f8 = 0.00
/* 008D4 80989754 468020A0 */  cvt.s.w $f2, $f4                   
/* 008D8 80989758 E7B00018 */  swc1    $f16, 0x0018($sp)          
/* 008DC 8098975C 8C4B001C */  lw      $t3, 0x001C($v0)           ## 0000001C
/* 008E0 80989760 448B9000 */  mtc1    $t3, $f18                  ## $f18 = 0.00
/* 008E4 80989764 46803320 */  cvt.s.w $f12, $f6                  
/* 008E8 80989768 46809120 */  cvt.s.w $f4, $f18                  
/* 008EC 8098976C 468043A0 */  cvt.s.w $f14, $f8                  
/* 008F0 80989770 E7A4001C */  swc1    $f4, 0x001C($sp)           
/* 008F4 80989774 8C4C0020 */  lw      $t4, 0x0020($v0)           ## 00000020
/* 008F8 80989778 448C3000 */  mtc1    $t4, $f6                   ## $f6 = 0.00
/* 008FC 8098977C 00000000 */  nop
/* 00900 80989780 46803220 */  cvt.s.w $f8, $f6                   
/* 00904 80989784 E7A80020 */  swc1    $f8, 0x0020($sp)           
/* 00908 80989788 94E61D74 */  lhu     $a2, 0x1D74($a3)           ## 00001D74
/* 0090C 8098978C 94450002 */  lhu     $a1, 0x0002($v0)           ## 00000002
/* 00910 80989790 94440004 */  lhu     $a0, 0x0004($v0)           ## 00000004
/* 00914 80989794 E7AE002C */  swc1    $f14, 0x002C($sp)          
/* 00918 80989798 E7AC0028 */  swc1    $f12, 0x0028($sp)          
/* 0091C 8098979C 0C01BE4F */  jal     Kankyo_InvLerp_u16              
/* 00920 809897A0 E7A20024 */  swc1    $f2, 0x0024($sp)           
/* 00924 809897A4 C7A20024 */  lwc1    $f2, 0x0024($sp)           
/* 00928 809897A8 C7AA0018 */  lwc1    $f10, 0x0018($sp)          
/* 0092C 809897AC 8FA20030 */  lw      $v0, 0x0030($sp)           
/* 00930 809897B0 C7AC0028 */  lwc1    $f12, 0x0028($sp)          
/* 00934 809897B4 46025401 */  sub.s   $f16, $f10, $f2            
/* 00938 809897B8 C7AE002C */  lwc1    $f14, 0x002C($sp)          
/* 0093C 809897BC 46008482 */  mul.s   $f18, $f16, $f0            
/* 00940 809897C0 46029100 */  add.s   $f4, $f18, $f2             
/* 00944 809897C4 E4440024 */  swc1    $f4, 0x0024($v0)           ## 00000024
/* 00948 809897C8 C7A6001C */  lwc1    $f6, 0x001C($sp)           
/* 0094C 809897CC 460C3201 */  sub.s   $f8, $f6, $f12             
/* 00950 809897D0 46004282 */  mul.s   $f10, $f8, $f0             
/* 00954 809897D4 460C5400 */  add.s   $f16, $f10, $f12           
/* 00958 809897D8 E4500028 */  swc1    $f16, 0x0028($v0)          ## 00000028
/* 0095C 809897DC C7B20020 */  lwc1    $f18, 0x0020($sp)          
/* 00960 809897E0 460E9101 */  sub.s   $f4, $f18, $f14            
/* 00964 809897E4 46002182 */  mul.s   $f6, $f4, $f0              
/* 00968 809897E8 460E3200 */  add.s   $f8, $f6, $f14             
/* 0096C 809897EC E448002C */  swc1    $f8, 0x002C($v0)           ## 0000002C
/* 00970 809897F0 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 00974 809897F4 27BD0030 */  addiu   $sp, $sp, 0x0030           ## $sp = 00000000
/* 00978 809897F8 03E00008 */  jr      $ra                        
/* 0097C 809897FC 00000000 */  nop
