#include "gdt.h"
#include "debug.h"

struct gdt_entry gdt[3];
struct gdt_register gdt_pointer;

void gdt_init() {
  INIT_START();
  gdt_pointer.limit = sizeof(gdt);
  gdt_pointer.base = (unsigned int) &gdt;

  gdt_set_entry(0, 0, 0, 0, 0);
  gdt_set_entry(1, 0, 0xFFFFFFFF, GDT_ACCESS_KERNEL | GDT_ACCESS_CODE, GDT_SEGMENT_PROTECTED | GDT_SEGMENT_BLOCKS_4K);
  gdt_set_entry(2, 0, 0xFFFFFFFF, GDT_ACCESS_KERNEL | GDT_ACCESS_DATA, GDT_SEGMENT_PROTECTED | GDT_SEGMENT_BLOCKS_4K);

  load_gdt(&gdt_pointer);
  INIT_END();
}

/* Setup a descriptor in the Global Descriptor Table */
void gdt_set_entry(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran) {
  /* Setup the descriptor base address */
  gdt[num].base_low = (base & 0xFFFF);
  gdt[num].base_middle = ((base >> 16) & 0xFF);
  gdt[num].base_high = ((base >> 24) & 0xFF);

  /* Setup the descriptor limits */
  gdt[num].limit_low = (limit & 0xFFFF);
  gdt[num].limit_high_flags = ((limit >> 16) & 0x0F);

  /* Finally, set up the flags */
  gdt[num].limit_high_flags |= (gran << 4);
  gdt[num].access = access;
}
