section .text

global ISRWrapper
align 4

DefaultInterruptWrapper:
	pushad
	extern InterruptHandler
	call InterruptHandler
	popad
	add esp, 4
	iret

%assign i 0
%rep 256
global InterruptWrapper%+i
InterruptWrapper%+i:
	push i
	jmp DefaultInterruptWrapper
%assign i i+1
%endrep

extern AddInterrupt

global AddInterrupts
AddInterrupts:
	%assign n 0
	%rep 256
	push InterruptWrapper%+n
	push n
	call AddInterrupt
	%assign n n+1
	%endrep
	extern SayHello
	call SayHello ; WHY DOES THIS WORK?!
	; hlt
	; popad
	; add esp, 4
	; ret