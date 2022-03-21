	.def warteschleife
	.text
;hält sich an die c kovention
;in R12 steht die anzahl n * 1000( n in sekunden)
warteschleife:
	mov #2667, R11 ;in R11 steht der Wert 8000/3 um die Funktion um 1ms zu verzögern
verzogerung:
	dec R11
	jnz verzogerung
	dec R12
	jnz warteschleife

	ret
