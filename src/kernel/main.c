#include "vga.h"
#include "gdt.h"
#include "idt.h"
#include "isr.h"

#include "timer.h"
#include "printf.h"

void main() {
  vga_init();
  gdt_init();
  idt_init();
  isr_init();

  timer_init();
}
