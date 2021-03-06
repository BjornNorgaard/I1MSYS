;********** MSYS, LAB1 **********
;******* Henning Hargaard *******
;******** 17.august 2012 ********
;********************************

;********** INITIERING **********
.include "M32DEF.INC"
   LDI  R16,HIGH(RAMEND) ;Initialize Stack Pointer
   OUT  SPH,R16
   LDI  R16,LOW(RAMEND)
   OUT  SPL,R16           
   SER  R16              ;PORTB = Outputs
   OUT  DDRB,R16

;********** PROGRAM-LOOP ********
LOOP:
   LDI  R16,0xFF        ;R16 = 13 
   CALL DISP_AND_DELAY  ;Display R16
   LDI  R17,9           ;R17 = 9 
   ADD  R16,R17         ;R16 = R16+R17 (=22)
   CALL DISP_AND_DELAY  ;Display R16
   RJMP LOOP            ;Jump to "LOOP"

;********** DISPLAY R16 *********
;********** AND DELAY ***********
DISP_AND_DELAY:
   MOV  R17,R16
   COM  R17
   OUT  PORTB,R17
   CLR  R17
   CLR  R18
   LDI  R19,10
AGAIN:
   DEC  R17
   BRNE AGAIN
   DEC  R18
   BRNE AGAIN
   DEC  R19
   BRNE AGAIN
   RET	
;********************************
