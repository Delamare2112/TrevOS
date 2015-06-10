.globl	ISRWrapper
.align	4

ISRWraper:
	pusha
	cld
	call InterruptHandler
	popa
	iret

.p2align 4
idt:
	.skip 50*16

  idtr:
	.short (50*16)-1
	.long idt

.globl do_test
do_test:
	lidt idtr
	movl $ISRWraper, %eax
	mov %ax, idt+49*16
	movw $0x20, idt+49*16+2
	movw $0x8e00, idt+49*16+4
    shr $16, %eax
	mov %ax, idt+49*16+6
	shr $16, %eax
	mov %eax, idt+49*16+8
	int $5 # This causes lots of restarts
		
