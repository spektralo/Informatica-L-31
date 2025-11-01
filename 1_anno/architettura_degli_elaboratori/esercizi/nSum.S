NUM		dcd		4
data		dcd		100,200,300,400
		
		MOV		R0, #NUM
		LDR		R2, [R0]
		MOV		R1, #data
		
		MOV		R0, #0
loop
		CMP		R2, #0
		beq		end_sum
		
		LDR		R3, [R1]
		ADD		R0, R0, R3
		
		ADD		R1, R1, #4
		SUB		R2, R2, #1
		
		B		loop
		
end_sum
		end
		
		
