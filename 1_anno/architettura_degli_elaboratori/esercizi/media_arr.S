dati		dcd		3, 4, 5, 6, 7, 8, 9   ; 7 elementi
		
		mov		r0, #7     ; R0 = contatore elementi → 7
		mov		r1, #dati  ; R1 = indirizzo array (puntatore)
		mov		r2, #0     ; R2 = somma parziale iniziale = 0
		;R3		= elemento corrente array
		
loop
		
		CMP		R0, #0
		beq		end_loop
		
		LDR		R3, [R1]
		ADD		R2, R2, R3
		
		ADD		R1, R1, #4
		SUB		R0, R0, #1
		B		loop
		
end_loop
		
		mov		r1, r2     ; R1 = dividendo = 42
		mov		r2, #7     ; R2 = divisore = 7
		mov		r0, #0     ; R0 = quoziente iniziale = 0
		
div_loop
		cmp		r1, r2        ; se dividendo < divisore, termina
		blt		div_end
		
		sub		r1, r1, r2    ; R1 -= R2 (sottrai divisore)
		add		r0, r0, #1    ; quoziente++
		
		b		div_loop
div_end
