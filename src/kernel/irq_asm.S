.macro IRQ_ENTRY irq num
	.global _irq\irq
	_irq\irq:
		cli
		pushl $0
		pushl $\num
		jmp irq_common_stub
.endm

irq_common_stub:
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	mov $0x10, %ax
	mov %ax, %ds
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs
	mov %esp, %eax
	push %eax
	// Call the kernel IRQ handler
	call irq_handler
	popl %eax
	popl %gs
	popl %fs
	popl %es
	popl %ds
	popa
	add $8, %esp
	iret

IRQ_ENTRY 0, 32
IRQ_ENTRY 1, 33
IRQ_ENTRY 2, 34
IRQ_ENTRY 3, 35
IRQ_ENTRY 4, 36
IRQ_ENTRY 5, 37
IRQ_ENTRY 6, 38
IRQ_ENTRY 7, 39
IRQ_ENTRY 8, 40
IRQ_ENTRY 9, 41
IRQ_ENTRY 10, 42
IRQ_ENTRY 11, 43
IRQ_ENTRY 12, 44
IRQ_ENTRY 13, 45
IRQ_ENTRY 14, 46
IRQ_ENTRY 15, 47
