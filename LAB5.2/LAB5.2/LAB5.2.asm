.include "M32DEF.INC"

   ;1. Initier Stack Pointer
   LDI  R16,HIGH(RAMEND)
   OUT  SPH,R16
   LDI  R16,LOW(RAMEND)
   OUT  SPL,R16
   ;2. Benene PA sættes til indgange
   CLR R16
   OUT DDRA, R16
   ;3. Benene PC sættes til udgange
   SER R16
   OUT DDRC, R16
   ;4. Slukker alle lysdioder
   SER R16
   OUT PORTC, R16
   ;5. Bruger, trykker på switches
   HERE:
      SBIS PINA, 7
      CALL SYV
      SBIS PINA, 6
      CALL SEKS   
      SBIS PINA, 5
      CALL FEM  
      SBIS PINA, 4
      CALL FIRE   
      SBIS PINA, 3
      CALL TRE  
      SBIS PINA, 2
      CALL TO   
      SBIS PINA, 1
      CALL EN   
      SBIS PINA, 0
      CALL NUL
   ;6. Tidsforsinkelse
   ;7. Hopper til punkt 5
   JMP HERE
   ; Trykknappernes funktioner
   SYV:
      IN   R16, PORTC
      INC  R16
	  OUT  PORTC, R16
      RET
   SEKS:
      IN   R16, PORTC
      DEC  R16
	  OUT  PORTC, R16
      RET
   FEM:
      IN   R16, PORTC
      SWAP R16
	  OUT  PORTC, R16
	  RET
   FIRE:
	  IN  R16, PORTC
	  COM R16
      OUT PORTC, R16
	  RET
   TRE:
      IN  R16, PORTC
	  LSR R16
      LSR R16
	  LSR R16
	  LSR R16
	  OUT PORTC, R16
	  RET
   TO:
      CLR R16
	  OUT PORTC, R16
      RET
   EN:
      SBI PORTC, 0
	  SBI PORTC, 7
	  RET
   NUL:
      CBI PORTC, 0
	  CBI PORTC, 7
	  RET