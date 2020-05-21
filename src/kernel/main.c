#include "vga.h"
#include "gdt.h"
#include "idt.h"

int main() {
  vga_init();
  gdt_init();
  idt_init();

  for (;;)
    ;
}
