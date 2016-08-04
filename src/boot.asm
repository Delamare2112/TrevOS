; Constants used for creating multiboot header
MBALIGN		equ		1<<0				; align loaded modules on page boundaries
MEMINFO		equ		1<<1				; provice memory map
FLAGS		equ		MBALIGN | MEMINFO	; multiboot flag field
MAGIC		equ		0x1BADB002 			; magic number to find header
CHECKSUM	equ		-(MAGIC + FLAGS)	; checksum of above, to prove we are multiboot

; a header in the Multiboot Standard.
; force the header to be in the start of the final program
section .multiboot
align 4
	dd MAGIC
	dd FLAGS
	dd CHECKSUM

section .bootstrap_stack
align 4
stack_bottom:
times 32768 db 0 ; 32 kilibytes
stack_top:

.data
strTextSec: db ".text section...", 0
strProcBeg: db "Wearing protection!", 0
strKernBeg: db "Handing over to C++ code...", 0

section .text
global _start
_start:
	extern ForcePrintString

	; print ".text section..."
	mov eax, strTextSec
	push eax
	call ForcePrintString
	pop eax

	; Start journey to protected land!
	cli					; I shall not be interrupted
	mov		eax, cr0	; move cr0 to eax :P
	or		al, 1
	mov		cr0, eax
	sti					; reinable interrupts

	; print "Wearing protection!"
	mov eax, strProcBeg
	push eax
	call ForcePrintString
	pop eax

	mov esp, stack_top	; set the stack

	; print "Handing over to C++ code..."
	mov eax, strKernBeg
	push eax
	call ForcePrintString
	pop eax

	extern StartKernel
	call StartKernel	; lets take a break from asm

	cli
.hang: ; Doom to infinite loop
	hlt
	jmp .hang
