#include "isr.h"
#include "vga.h"
#include "exception.h"

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

void exception_handler(struct isr_regs *context) {
  vga_set_background(VGA_COLOR_RED);
  vga_set_foreground(VGA_COLOR_WHITE);
  vga_print_string(exception_messages[context->int_no]);
  vga_print_string(" Exception. System Halted!\n");
  for (;;);
}
