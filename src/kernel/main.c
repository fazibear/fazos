#include "vga.h"
#include "gdt.h"
#include "idt.h"
#include "isr.h"

#include "pmem.h"
#include "timer.h"

#include "multiboot.h"
#include "debug.h"

void main(unsigned int magic, struct multiboot_info* info) {
  vga_init();
  vga_set_foreground(VGA_COLOR_GREY);

  pmem_init(info);

  gdt_init();
  idt_init();
  isr_init();

  timer_init();

  vga_set_foreground(VGA_COLOR_WHITE);
  vga_print_string("READY.\n");;

  DEBUG("Magic Value: %x", magic);
  DEBUG("Bootloader name: %s", info->boot_loader_name);
}
