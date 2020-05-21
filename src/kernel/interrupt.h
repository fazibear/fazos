#ifndef _INTERRUPT_H
#define _INTERRUPT_H

#include "isr.h"

void interrupt_register_handler(int irq, void (*handler)(struct isr_regs *r));
void interrupt_unregister_handler(int irq);
void interrupt_handler(struct isr_regs *context);
void interrupt_remap();

#endif
