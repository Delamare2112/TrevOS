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
times 16384 db 0
stack_top:

GDTR:
GDTsize dw GDT_END-GDT-1
GDTbase dd 0x500

GDT:
NULL_SEL	EQU $-GDT ; null descriptor
	dd 0x0
	dd 0x0
CODESEL		EQU $-GDT
	dw	0xFFFF	; limit(2)
	dw	0x0		; base(3)
	db	0x0		; base(2)
	db	0x9A	; type: present, ring0, code, exec/read/accessed (10011000)
	db	0xCF	; limit(1) Flags:4kb inc,32bit (11001111)
	dd	0x0		; base(1)
DATASEL		EQU $-GDT
	dw	0xFFFF	; limit(2)
	dw	0x0		; base(3)
	db	0x0		; base(20
	db	0x92	; type: present, ring0, data/stack,read/write (10010010)
	db	0xCF	; limit(1) Flags:4kb inc,32bit (11001111)
	db	0x0		; base(1)
GDT_END:

section .text
global _start
_start:
	; Start hourney to protected land!
	cli					; I shall not be interrupted
	mov		eax, cr0	; move cr0 to eax :P
	or		al, 1		
	mov		cr0, eax
	lgdt[GDTR]			; load the GDT

	mov esp, stack_top	; set the stack

	extern StartKernel
	call StartKernel	; lets take a break from asm

	cli
.hang: ; Doom to infinite loop
	hlt
	jmp .hang

