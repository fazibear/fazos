/* entry point of our kernel */
ENTRY(start)

SECTIONS
{
	/* we need 1MB of space atleast */
	. = 1M;

  	/* text section */
	.text : ALIGN(4K)
	{
		*(.multiboot)
		*(.text)
	}

	/* read only data section */
	.rodata : ALIGN(4K)
	{
		*(.rodata)
	}

	/* data section */
	.data : ALIGN(4K)
	{
		*(.data)
	}

	/* bss section */
	.bss : ALIGN(4K)
	{
		*(COMMON)
		*(.bss)
	}

}
