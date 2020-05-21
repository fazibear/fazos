#include "interrupt.h"
#include "system.h"
#include "isr.h"

void *interrupt_routines[16] = {
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0
};

/* This installs a custom IRQ handler for the given IRQ */
void interrupt_register_handler(int irq, void (*handler)(struct isr_regs *r)) {
  interrupt_routines[irq] = handler;
}

/* This clears the handler for a given IRQ */
void interrupt_inregister_handler(int irq) {
  interrupt_routines[irq] = 0;
}

void interrupt_handler(struct isr_regs *context) {
  void (*handler)(struct isr_regs *r);
  handler = interrupt_routines[context->int_no - 32];

  /* Find out if we have a custom handler to run for this IRQ, and then finally, run it */
  if (handler) {
    handler(context);
  }

  /* If the IDT entry that was invoked was greater than 40
   *  (meaning IRQ8 - 15), then we need to send an EOI to
   *  the slave controller */
  if (context->int_no >= 40) {
    outportb(0xA0, 0x20);
  }

  /* In either case, we need to send an EOI to the master
  *  interrupt controller too */
  outportb(0x20, 0x20);
}

void interrupt_remap() {
  outportb(0x20, 0x11);
  outportb(0xA0, 0x11);
  outportb(0x21, 0x20);
  outportb(0xA1, 0x28);
  outportb(0x21, 0x04);
  outportb(0xA1, 0x02);
  outportb(0x21, 0x01);
  outportb(0xA1, 0x01);
  outportb(0x21, 0x0);
  outportb(0xA1, 0x0);
}

