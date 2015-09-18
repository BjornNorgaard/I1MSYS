;********** MSYS, LAB2_1 **********
;******** Henning Hargaard ********
;********* 30.august 2012 *********
;**********************************
.include "M32DEF.INC"
   LDI  R16,200
   STS  0x80,R16
   LDI  R16,5
   LDI  R17,17
   LDS  R16,0x80
   DEC  R16
   MOV  R18,R16
   ADD  R17,R18
   INC  R17
   INC  R17
   COM  R17
HER:      
   JMP  HER 
;**********************************