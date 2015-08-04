ENTRY(_start)

SECTIONS
{
	/* It is convention to place for kernels */
	. = 1M;

	StartOfKernel = .;

	.text BLOCK(4K) : ALIGN(4K)
	{
		*(.multiboot)
		*(.text)
	}

	/* Read-only data */
	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.data)
	}

	/* Read-write data */
	.bss BLOCK(4K) : ALIGN(4K)
	{
		*(COMMON)
		*(.bss)
		*(.bootstrap_stack)
	}

	EndOfKernel = .;
}