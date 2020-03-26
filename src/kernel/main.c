#include "system.h"
#include "screen.h"
#include "gdt.h"
#include "idt.h"
#include "isrs.h"
#include "irq.h"

void _main() {
  gdt_install();
  idt_install();
  isrs_install();
  irq_install();

  screen_cls();

  screen_println("");

  screen_print("                           ");
  screen_set_color(YELLOW);
  screen_print("* ");
  screen_set_color(BLUE);
  screen_print("* ");
  screen_set_color(RED);
  screen_print("* ");
  screen_set_color(GREEN);
  screen_print("* ");
  screen_set_color(GREY);
  screen_print("* ");

  screen_set_color(WHITE);
  screen_print("FAZOS ");

  screen_set_color(GREY);
  screen_print("* ");
  screen_set_color(GREEN);
  screen_print("* ");
  screen_set_color(RED);
  screen_print("* ");
  screen_set_color(BLUE);
  screen_print("* ");
  screen_set_color(YELLOW);
  screen_println("*");

//  char x = 2/0;
//  screen_print_char(x);

  screen_println("");
  screen_set_color(WHITE);
  screen_println("READY.");
}
