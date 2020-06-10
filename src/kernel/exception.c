#include "isr.h"
#include "vga.h"
#include "exception.h"
#include "debug.h"

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
  ERROR("Exception: %s", exception_messages[context->int_no]);
  vga_set_background(VGA_COLOR_RED);
  vga_set_foreground(VGA_COLOR_WHITE);
  vga_clear();
  vga_set_background(VGA_COLOR_WHITE);
  vga_set_foreground(VGA_COLOR_RED);
  vga_print_string("\n                                 System Halted!                                 \n");
  vga_set_background(VGA_COLOR_RED);
  vga_set_foreground(VGA_COLOR_WHITE);
  vga_print_string("Exception: ");
  vga_print_string(exception_messages[context->int_no]);
  for (;;);
}
