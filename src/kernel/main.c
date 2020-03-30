#include "system.h"
#include "screen.h"
#include "gdt.h"
#include "idt.h"
#include "isrs.h"
#include "irq.h"
#include "timer.h"
#include "keyboard.h"

void _main() {
  gdt_install();
  idt_install();
  isrs_install();
  irq_install();
  // timer_install();
  keyboard_install();

  screen_cls();

  screen_print_string("\n");

  screen_print_string("                           ");
  screen_set_color(YELLOW);
  screen_print_string("* ");
  screen_set_color(BLUE);
  screen_print_string("* ");
  screen_set_color(RED);
  screen_print_string("* ");
  screen_set_color(GREEN);
  screen_print_string("* ");
  screen_set_color(GREY);
  screen_print_string("* ");

  screen_set_color(WHITE);
  screen_print_string("FAZOS ");

  screen_set_color(GREY);
  screen_print_string("* ");
  screen_set_color(GREEN);
  screen_print_string("* ");
  screen_set_color(RED);
  screen_print_string("* ");
  screen_set_color(BLUE);
  screen_print_string("* ");
  screen_set_color(YELLOW);
  screen_print_string("*\n\n");

//  char x = 2/0;
//  screen_print_char(x);

  screen_set_color(WHITE);
  screen_print_string("READY.\n");
}
