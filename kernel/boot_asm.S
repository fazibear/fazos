# set magic number to 0x1BADB002 to identified by bootloader 
.set MAGIC,    0x1BADB002

# set flags to 0
.set FLAGS,    0

# set the checksum
.set CHECKSUM, -(MAGIC + FLAGS)

# set multiboot enabled
.section .multiboot

# define type to long for each data defined as above
.long MAGIC
.long FLAGS
.long CHECKSUM

# set the stack bottom 
stack_bottom:
# define the maximum size of stack to 512 bytes
.skip 1024

# set the stack top which grows from higher to lower

stack_top:

.section .text

.global _start

_start:

  # assign current stack pointer location to stack_top
	mov $stack_top, %esp

  # call the kernel main source
	call _main

	cli

# put system in infinite loop
hlt_loop:

	hlt
	jmp hlt_loop

.size _start, . - _start
