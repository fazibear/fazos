#include "vga.h"
#include "gdt.h"
#include "idt.h"
#include "isr.h"

int main() {
  vga_init();
  gdt_init();
  idt_init();
  isr_init();

  for (;;)
    ;
}
