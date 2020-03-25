#include "gdt.h"
#include "screen.h"

void _main() {
  gdt_install();
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

  screen_println("");
  screen_set_color(WHITE);
  screen_println("READY.");
}
