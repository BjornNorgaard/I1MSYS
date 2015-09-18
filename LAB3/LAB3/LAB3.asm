;**********************************
;*********** MSYS, LAB3 ***********
;******** Henning Hargaard ********
;******** 3.september 2012 ********
;**********************************

;*********** INITIERING ***********
;***** Klargoer SP og PORTB *******
.include "M32DEF.INC"
   LDI  R16,HIGH(RAMEND) ;Initialize Stack Pointer
   OUT  SPH,R16
   LDI  R16,LOW(RAMEND)
   OUT  SPL,R16 
   SER  R16
   OUT  DDRB,R16
   CLR  R16
   OUT  PORTB,R16
 
;*********** PROGRAM-LOOP ********* 
   LDI  R20,239   ;c
   CALL TONE 
   LDI  R20,213   ;D
   CALL TONE
   LDI  R20,190   ;E
   CALL TONE
   LDI  R20,179   ;F
   CALL TONE
   LDI  R20,160   ;G
   CALL TONE 
   LDI  R20,142   ;A 
   CALL TONE 
   LDI  R20,127   ;H
   CALL TONE 
   LDI  R20,120   ;C
   CALL TONE 
HERE:
   JMP  HERE

;**********************************
;******** DELAY (R18*4us)  ********
;**********************************
DELAY:
   LDI  R17,1   ;<----- xxx skal beregnes
AGAIN:
   DEC  R17
   BRNE AGAIN
   DEC  R18
   BRNE DELAY
   RET
   	
;**********************************
;******** SPILLER EN TONE  ********
;******** 250 HALVPERIODER ********
;******** T/2 = (R20)*4 us ********
;********************************** 
TONE:
   LDI  R19,150
PIN:   
   COM  R16
   OUT  PORTB,R16
   MOV  R18,R20
   CALL DELAY
   DEC  R19
   BRNE PIN
   RET
;**********************************

