;**********************************
;******** MSYS, LAB4,DEL 2 ********
;******** Henning Hargaard ********
;******** 11.september 2012 *******
;**********************************
;*********** INITIERING ***********
.include "M32DEF.INC"
   LDI  R16,HIGH(RAMEND)
   OUT  SPH,R16
   LDI  R16,LOW(RAMEND)
   OUT  SPL,R16

;---> Skriv kode her, der konfigurerer PC, ben 0 til udgang.
   SBI DDRC, 0
;---> Skriv kode her, der konfigurerer hele PA til indgange.
   CLR R16
   OUT DDRA, R16

;*********** PROGRAM-LOOP *********
 HERE:

;---> Skriv kode her, der aftaster de 8 trykknapper og
;     styrer duty cycle på LED-udgangen i henhold til
;     hvilken knap, der aktiveres.
   SBIS PINA, 7
   LDI  R20, 255
   SBIS PINA, 6
   LDI  R20, 128
   SBIS PINA, 5
   LDI  R20, 64
   SBIS PINA, 4
   LDI  R20, 32
   SBIS PINA, 3
   LDI  R20, 16
   SBIS PINA, 2
   LDI  R20, 8
   SBIS PINA, 1
   LDI  R20, 4
   SBIS PINA, 0
   LDI  R20, 2

   CBI  PORTC, 0	; tænder led
   MOV  R18, R20
   CALL DELAY

   SBI  PORTC, 0	; slukker led
   LDI  R18, 128
   CALL DELAY

   RJMP  HERE      ;Gentag loop

;********* DELAY (R18*4us) ********
DELAY:
   LDI  R17,4
AGAIN:
   DEC  R17
   BRNE AGAIN
   DEC  R18
   BRNE DELAY
   RET	
;**********************************
