.text
.globl paging_load_page_directory
.globl paging_enable

paging_load_page_directory:
  push %ebp
  mov %esp, %ebp
  mov 8(%esp), %eax
  mov %eax, %cr3
  mov %ebp, %esp
  pop %ebp
  ret

paging_enable:
  push %ebp
  mov %esp, %ebp
  mov %cr0, %eax
  or $0x80000000, %eax
  mov %eax, %cr0
  mov %ebp, %esp
  pop %ebp
  ret
