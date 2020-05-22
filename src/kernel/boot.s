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

.section .text

.global start
.type start, @function

start:
  mov $0x80000, %esp # Setup the stack

  push %ebx # Pass multiboot info structure
  push %eax # Pass multiboot magic code

  call main # Call the kernel

  cli

sti_loop:
  sti
  jmp sti_loop
