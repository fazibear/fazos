#ifndef _IRQ_H
#define _IRQ_H

/* These are own ISRs that point to our special IRQ handler
*  instead of the regular 'fault_handler' function */
extern void _irq0();
extern void _irq1();
extern void _irq2();
extern void _irq3();
extern void _irq4();
extern void _irq5();
extern void _irq6();
extern void _irq7();
extern void _irq8();
extern void _irq9();
extern void _irq10();
extern void _irq11();
extern void _irq12();
extern void _irq13();
extern void _irq14();
extern void _irq15();

/* This array is actually an array of function pointers. We use
*  this to handle custom IRQ handlers for a given IRQ */
void *irq_routines[16];

/* This installs a custom IRQ handler for the given IRQ */
void irq_install_handler(int irq, void (*handler)(struct regs *r));


/* This clears the handler for a given IRQ */
void irq_uninstall_handler(int irq);

/* Normally, IRQs 0 to 7 are mapped to entries 8 to 15. This
*  is a problem in protected mode, because IDT entry 8 is a
*  Double Fault! Without remapping, every time IRQ0 fires,
*  you get a Double Fault Exception, which is NOT actually
*  what's happening. We send commands to the Programmable
*  Interrupt Controller (PICs - also called the 8259's) in
*  order to make IRQ0 to 15 be remapped to IDT entries 32 to
*  47 */
void irq_remap(void);

/* We first remap the interrupt controllers, and then we install
*  the appropriate ISRs to the correct entries in the IDT. This
*  is just like installing the exception handlers */
void irq_install();

/* Each of the IRQ ISRs point to this function, rather than
*  the 'fault_handler' in 'isrs.c'. The IRQ Controllers need
*  to be told when you are done servicing them, so you need
*  to send them an "End of Interrupt" command (0x20). There
*  are two 8259 chips: The first exists at 0x20, the second
*  exists at 0xA0. If the second controller (an IRQ from 8 to
*  15) gets an interrupt, you need to acknowledge the
*  interrupt at BOTH controllers, otherwise, you only send
*  an EOI command to the first controller. If you don't send
*  an EOI, you won't raise any more IRQs */
void irq_handler(struct regs *r);

#endif
