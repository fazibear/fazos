.type load_gdt, @function
.global load_gdt

load_gdt:
	mov 0x4(%esp), %eax  # Fetch the gdtr parameter.
	lgdt (%eax)         # Load the new GDT.

	# Reload data segments (GDT entry 2: kernel data).
	mov $0x10, %ax
	mov %ax, %ds
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs
	mov %ax, %ss

	# Reload code segment (GDT entry 1: kernel code).
	ljmp $0x08, $gdt_ret

gdt_ret:
  ret
