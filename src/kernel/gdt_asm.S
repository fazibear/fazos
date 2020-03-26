.extern gp 
.global _gdt_flush

_gdt_flush:
	lgdt gp

	movw $0x10,%ax    # 0x10 is the offset in the GDT to our data segment
	movw %ax,%ds      # Load all data segment selectors
	movw %ax,%es
	movw %ax,%fs
	movw %ax,%gs
	movw %ax,%ss
	ljmp $0x08, $flush2   # 0x08 is the offset to our code segment: Far jump!
flush2: 
   	ret
