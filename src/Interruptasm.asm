global ISRWrapper
align 4

DefaultInterruptWrapper:
	pushad
	extern InterruptHandler
	call InterruptHandler
	popad
	add esp, 4
	iret

global InterruptWrapper0
InterruptWrapper0:
	push 0
	jmp DefaultInterruptWrapper
	
