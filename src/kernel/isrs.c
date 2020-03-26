#include "idt.h"
#include "screen.h"
#include "isrs.h"

char *exception_messages[] = {
  "Division By Zero",
  "Debug",
  "Non Maskable Interrupt",
  "Breakpoint",
  "Into Detected Overflow",
  "Out of Bounds",
  "Invalid Opcode",
  "No Coprocessor",

  "Double Fault",
  "Coprocessor Segment Overrun",
  "Bad TSS",
  "Segment Not Present",
  "Stack Fault",
  "General Protection Fault",
  "Page Fault",
  "Unknown Interrupt",

  "Coprocessor Fault",
  "Alignment Check",
  "Machine Check",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",

  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved"
};

/* This is a very repetitive function... it's not hard, it's
*  just annoying. As you can see, we set the first 32 entries
*  in the IDT to the first 32 isrs. We can't use a for loop
*  for this, because there is no way to get the function names
*  that correspond to that given entry. We set the access
*  flags to 0x8E. This means that the entry is present, is
*  running in ring 0 (kernel level), and has the lower 5 bits
*  set to the required '14', which is represented by 'E' in
*  hex. */
void isrs_install() {
  idt_set_gate(0, (unsigned)_isr0, 0x08, 0x8E);
  idt_set_gate(1, (unsigned)_isr1, 0x08, 0x8E);
  idt_set_gate(2, (unsigned)_isr2, 0x08, 0x8E);
  idt_set_gate(3, (unsigned)_isr3, 0x08, 0x8E);
  idt_set_gate(4, (unsigned)_isr4, 0x08, 0x8E);
  idt_set_gate(5, (unsigned)_isr5, 0x08, 0x8E);
  idt_set_gate(6, (unsigned)_isr6, 0x08, 0x8E);
  idt_set_gate(7, (unsigned)_isr7, 0x08, 0x8E);

  idt_set_gate(8, (unsigned)_isr8, 0x08, 0x8E);
  idt_set_gate(9, (unsigned)_isr9, 0x08, 0x8E);
  idt_set_gate(10, (unsigned)_isr10, 0x08, 0x8E);
  idt_set_gate(11, (unsigned)_isr11, 0x08, 0x8E);
  idt_set_gate(12, (unsigned)_isr12, 0x08, 0x8E);
  idt_set_gate(13, (unsigned)_isr13, 0x08, 0x8E);
  idt_set_gate(14, (unsigned)_isr14, 0x08, 0x8E);
  idt_set_gate(15, (unsigned)_isr15, 0x08, 0x8E);

  idt_set_gate(16, (unsigned)_isr16, 0x08, 0x8E);
  idt_set_gate(17, (unsigned)_isr17, 0x08, 0x8E);
  idt_set_gate(18, (unsigned)_isr18, 0x08, 0x8E);
  idt_set_gate(19, (unsigned)_isr19, 0x08, 0x8E);
  idt_set_gate(20, (unsigned)_isr20, 0x08, 0x8E);
  idt_set_gate(21, (unsigned)_isr21, 0x08, 0x8E);
  idt_set_gate(22, (unsigned)_isr22, 0x08, 0x8E);
  idt_set_gate(23, (unsigned)_isr23, 0x08, 0x8E);

  idt_set_gate(24, (unsigned)_isr24, 0x08, 0x8E);
  idt_set_gate(25, (unsigned)_isr25, 0x08, 0x8E);
  idt_set_gate(26, (unsigned)_isr26, 0x08, 0x8E);
  idt_set_gate(27, (unsigned)_isr27, 0x08, 0x8E);
  idt_set_gate(28, (unsigned)_isr28, 0x08, 0x8E);
  idt_set_gate(29, (unsigned)_isr29, 0x08, 0x8E);
  idt_set_gate(30, (unsigned)_isr30, 0x08, 0x8E);
  idt_set_gate(31, (unsigned)_isr31, 0x08, 0x8E);
}

/* All of our Exception handling Interrupt Service Routines will
*  point to this function. This will tell us what exception has
*  happened! Right now, we simply halt the system by hitting an
*  endless loop. All isrs disable interrupts while they are being
*  serviced as a 'locking' mechanism to prevent an IRQ from
*  happening and messing up kernel data structures */
void fault_handler(struct regs *r) {
  if (r->int_no < EXCEPTION_MESSAGES_SIZE) {
    screen_set_background_color(RED);
    screen_set_color(WHITE);
    screen_print(exception_messages[r->int_no]);
    screen_println(" Exception. System Halted!");
    for (;;);
  }
}

