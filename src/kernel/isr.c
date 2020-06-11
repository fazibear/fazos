#include "isr.h"
#include "idt.h"
#include "exception.h"
#include "interrupt.h"
#include "debug.h"

/* All of our Exception handling Interrupt Service Routines will
*  point to this function. This will tell us what exception has
*  happened! Right now, we simply halt the system by hitting an
*  endless loop. All isrs disable interrupts while they are being
*  serviced as a 'locking' mechanism to prevent an IRQ from
*  happening and messing up kernel data structures */
void isr_handler(struct isr_regs *context) {
  if (context->int_no > 31) {
    interrupt_handler(context);
  } else {
    exception_handler(context);
  }
}

void isr_init() {
  INIT_START();
  idt_set_gate(1, (unsigned)isr1, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(2, (unsigned)isr2, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(3, (unsigned)isr3, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(4, (unsigned)isr4, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(5, (unsigned)isr5, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(6, (unsigned)isr6, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(7, (unsigned)isr7, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(8, (unsigned)isr8, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(9, (unsigned)isr9, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(10, (unsigned)isr10, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(11, (unsigned)isr11, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(12, (unsigned)isr12, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(13, (unsigned)isr13, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(14, (unsigned)isr14, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(15, (unsigned)isr15, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(16, (unsigned)isr16, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(17, (unsigned)isr17, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(18, (unsigned)isr18, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(19, (unsigned)isr19, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(20, (unsigned)isr20, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(21, (unsigned)isr21, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(22, (unsigned)isr22, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(23, (unsigned)isr23, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(24, (unsigned)isr24, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(25, (unsigned)isr25, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(26, (unsigned)isr26, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(27, (unsigned)isr27, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(28, (unsigned)isr28, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(29, (unsigned)isr29, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(30, (unsigned)isr30, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(31, (unsigned)isr31, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);

  interrupt_remap();

  idt_set_gate(32, (unsigned)isr32, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(33, (unsigned)isr33, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(34, (unsigned)isr34, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(35, (unsigned)isr35, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(36, (unsigned)isr36, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(37, (unsigned)isr37, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(38, (unsigned)isr38, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(39, (unsigned)isr39, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(40, (unsigned)isr40, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(41, (unsigned)isr41, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(42, (unsigned)isr42, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(43, (unsigned)isr43, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(44, (unsigned)isr44, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(45, (unsigned)isr45, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(46, (unsigned)isr46, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  idt_set_gate(47, (unsigned)isr47, ISR_KERNEL_CODE, IDT_GATE_INTERRUPT);
  INIT_END();
}

