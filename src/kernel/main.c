#include "vga.h"
#include "gdt.h"

int main() {
  vga_init();
  gdt_init();

  for (;;)
    ;
}
