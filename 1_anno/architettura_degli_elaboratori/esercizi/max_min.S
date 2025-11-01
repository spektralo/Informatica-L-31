array	dcd		5,9,10,34,8,2,1,4,50,11
		
		;r0		= numero di elementi
		;r1		= puntatore all'elemento corrente
		;r2		= max
		;r3		= min
		;r4		= elemento corrente letto dalla memoria
		
		MOV		R0, #10
		MOV		R1, #array
		
		LDR		R2, [R1]
		MOV		R3, R2
		
		ADD		R1, R1, #4
		
loop
		CMP		R0, #1
		BEQ		end_loop
		
		LDR		R4, [R1]
		CMP		R4, R2
		BLE		cont
		MOV		R2, R4
		
cont
		CMP		R4,R3
		BGE		cont2
		MOV		R3, R4
		
cont2
		SUB		R0, R0, #1
		ADD		R1, R1, #4
		B		loop
		
end_loop
		end
		
		