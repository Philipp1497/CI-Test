	.cdecls "bocas.h"
	.def count
	.bss count, 2, 2
	.bss wert, 2, 2
	.ref blink
	.ref umschalten
; Interruptroutine in Vector eintragen
	.sect .int06
	.word isrTimerA

	.text
isrTimerA:
; naechster Interrupt in 50ms

	;call #getAdress
	add.w #50000, &TACCR0 ; hier auch auf 1000 setzen wenn 50Hz erreicht werden soll
	dec.w count
	jnz isr_done
; der Hilszaehler ist null, also ist nun eine Sekunde vergangen

	push R15
	push R14
	push R13
	push R12
	push R11
	push R10
	push R9
	push R8
	push R7
	push R6
	push R5
	push R4


	mov R1, R12; alten Stackpointer als Argument übergeben und speichern

	call #umschalten;neuen Stackpointer ausgeben

	mov R12, R1


	xor.b #0x80, &P4OUT
	mov.w #20, count


	pop R4
	pop R5
	pop R6
	pop R7
	pop R8
	pop R9
	pop R10
	pop R11
	pop R12
	pop R13
	pop R14
	pop R15


isr_done:
	reti


