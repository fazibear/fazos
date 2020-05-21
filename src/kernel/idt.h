#ifndef _IDT_H
#define _IDT_H

// Types of gates.
#define IDT_GATE_INTERRUPT 0x8E
#define IDT_GATE_SYSCALL 0xEE


/* Defines an IDT entry */
struct idt_entry {
  unsigned short base_lo;
  unsigned short sel;        /* Our kernel segment goes here! */
  unsigned char always0;     /* This will ALWAYS be set to 0! */
  unsigned char flags;       /* Set using the above table! */
  unsigned short base_hi;
} __attribute__((packed));

struct idt_register {
  unsigned short limit;
  unsigned int base;
} __attribute__((packed));

void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
void idt_init();
void lidt(struct idt_register*);

#endif
