#include "vga.h"
#include "gdt.h"
#include "idt.h"
#include "isr.h"

#include "pmem.h"

#include "printf.h"
#include "timer.h"

#include "multiboot.h"

void main(unsigned int magic, struct multiboot_info* info) {
  vga_init();
  vga_set_foreground(VGA_COLOR_GREY);

  pmem_init(info);

  gdt_init();
  idt_init();
  isr_init();

  timer_init();

  vga_printf("Magic Value: %x\n", magic);
  vga_printf("Bootloader name: %s\n", info->boot_loader_name);

  vga_set_foreground(VGA_COLOR_WHITE);
  vga_print_string("READY.\n");;
}
