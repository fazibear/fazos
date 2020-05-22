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
