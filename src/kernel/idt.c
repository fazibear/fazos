#include "idt.h"
#include "system.h"
#include "debug.h"

struct idt_entry idt[256];
struct idt_register idt_pointer;

void idt_init() {
  DEBUG_INIT_START();
  memset(&idt, 0, sizeof(idt));

  idt_pointer.limit = sizeof(idt);
  idt_pointer.base = (unsigned int) &idt;

  lidt(&idt_pointer);
  DEBUG_INIT_END();
}

/* Use this function to set an entry in the IDT. Alot simpler
*  than twiddling with the GDT ;) */
void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags) {
  /* The interrupt routine's base address */
  idt[num].base_lo = (base & 0xFFFF);
  idt[num].base_hi = (base >> 16) & 0xFFFF;

  /* The segment or 'selector' that this IDT entry will use
  *  is set here, along with any access flags */
  idt[num].sel = sel;
  idt[num].always0 = 0;
  idt[num].flags = flags;
}

void lidt(struct idt_register* idtr) {
  __asm__ __volatile__ ("lidt (%[idtr])" : : [idtr] "r" (idtr));
}
