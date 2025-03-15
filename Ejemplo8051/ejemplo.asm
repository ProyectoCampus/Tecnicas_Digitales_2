	GREEN_LED EQU P1.0
	ORG 0000h
	LJMP MAIN

	ORG 100h
MAIN:
	CLR GREEN_LED
	ACALL DELAY500
	SETB GREEN_LED
	ACALL DELAY500
	SJMP MAIN

DELAY100:
	MOV R7, #200
LOOP1:	MOV R6, #250
LOOP0:	DJNZ R6, LOOP0
	DJNZ R7, LOOP1
	RET

DELAY500:
	CALL DELAY100
	CALL DELAY100
	CALL DELAY100
	CALL DELAY100
	CALL DELAY100
	RET
END