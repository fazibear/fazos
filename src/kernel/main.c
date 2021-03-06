#include "vga.h"
#include "gdt.h"
#include "idt.h"
#include "isr.h"

#include "pmem.h"
#include "paging.h"
#include "timer.h"

#include "multiboot.h"
#include "debug.h"
#include "test.h"

void main(unsigned int magic, struct multiboot_info* info) {
  debug_init();

  INFO("Magic Value: %x", magic);
  INFO("Bootloader name: %s", info->boot_loader_name);

  vga_init();
  vga_set_foreground(VGA_COLOR_GREY);

  pmem_init(info);
  paging_init();

  gdt_init();
  idt_init();
  isr_init();

  timer_init();

  vga_set_foreground(VGA_COLOR_WHITE);
  vga_print_string("READY.\n");

  test_debug();
}
