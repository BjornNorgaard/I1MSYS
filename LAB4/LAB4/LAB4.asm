;**********************************
;******** MSYS, LAB4,DEL 1 ********
;******** Henning Hargaard ********
;******** 11.september 2012 *******
;**********************************
;*********** INITIERING ***********
.include "M32DEF.INC"
   LDI  R16,HIGH(RAMEND)  ;Initier Stack Pointer
   OUT  SPH,R16
   LDI  R16,LOW(RAMEND)
   OUT  SPL,R16

   SER  R16
   OUT  DDRB,R16          ;PB benene er udgange 

;---> Skriv kode her, der konfigurer PA benene til INDGANGE   
  
   LDI R20, 0x0
   OUT DDRA, R20	; PA sat til indgang
   IN  R20, PINA
   OUT PORTB, R20
   

;********** PROGRAM-LOOP **********
HERE:
 
;---> Skriv kode her, der aftaster de 8 trykknapper og
;     spiller den korrekte tone, hvis en knap holdes nede. 
;     Når ingen knap holdes nede, skal lydgiveren være tavs. 
   
   SBIS PINA, 7
   CALL LAVC
   SBIS PINA, 6
   CALL D
   SBIS PINA, 5
   CALL E
   SBIS PINA, 4
   CALL F
   SBIS PINA, 3
   CALL G
   SBIS PINA, 2
   CALL A
   SBIS PINA, 1
   CALL H
   SBIS PINA, 0
   CALL HOJC

   RJMP HERE

LAVC:
   LDI R20, 239
   CALL TONE
   RET
D:
   LDI R20, 213
   CALL TONE
   RET
E:
   LDI R20, 190
   CALL TONE
   RET
F:
   LDI R20, 179
   CALL TONE
   RET
G:
   LDI R20, 160
   CALL TONE
   RET
A:
   LDI R20, 142
   CALL TONE
   RET
H: 
   LDI R20, 127
   CALL TONE
   RET
HOJC:
   LDI R20, 120
   CALL TONE
   RET

;********* DELAY (R18*4us) ********
DELAY:
   LDI  R17,1
AGAIN:
   DEC  R17
   BRNE AGAIN
   DEC  R18
   BRNE DELAY
   RET	
;**********************************
TONE:
   ;LDI  R19,250   
   COM  R16
   OUT  PORTB,R16
   CALL DELAY
   MOV  R18,R20
   ;CALL DELAY
   ;DEC  R19
   BRNE TONE
   RET