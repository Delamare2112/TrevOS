.set ALIGN,		1<<0				# align loaded modules on page boundaries
.set MEMINFO,	1<<1				# provide memory map
.set FLAGS,		ALIGN | MEMINFO		# the multiboot flag field
.set MAGIC,		0x1BADB002			# magic number to find header
.set CHECKSUM,	-(MAGIC + FLAGS)	# checksum of above, to prove we are multiboot

# a header in the Multiboot Standard.
# force the header to be in the start of the final program
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# using esp may cause harm so well make our own stack
.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

# The linker script specifies _start as the entry point to the kernel
# The bootloader will jump to this position once the kernel has been loaded.
.section .text
.global _start
.type _start, @function
_start:
	# YAY KERNEL MODE!
	# not much here yet...
	# set the esp register to point to the top of our stack
	movl $stack_top, %esp

	# Lets take a break from assembly!
	call StartKernel

	# The kernel returns?  How dare it!  I doom you to Infinite Loop!
	cli
	hlt
.Lhang:
	jmp .Lhang

# Set the size of the _start symbol to the current location . minus its start
.size _start, . - _start
