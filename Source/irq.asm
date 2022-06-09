	.def initTimerA
	.cdecls C,LIST,"bocas.h"


initTimerA:
; stop timer during programming
	bic.w #MC_0, &TACTL 		; use direct address mode
; select source (ACLK)
	bis.w #TASSEL_1, &TACTL  ; ACLK = 8Mhz
; select devide by 8
	bis.w #ID_3, &TACTL  ; TimerFreq = 1Mhz
; set intervall
	mov.w #0, &TACCR0
; select compare mode
	bic.w #CAP, &TACCTL0
; enable Timer-A interrupt
	bis.w #CCIE, &TACCTL0
; select continuous mode start timer
	bis.w #MC_2, &TACTL
	ret
