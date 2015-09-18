;********** MSYS, LAB2_2 **********
;******** Henning Hargaard ********
;********* 30.august 2012 *********
;**********************************

;*********** INITIERING ***********

.include "M32DEF.INC"
LDI R20, 16
IGEN: 
NOP
NOP
DEC R20
BRNE IGEN
;**********************************
