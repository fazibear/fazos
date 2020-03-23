#include "screen.h"

void _main() {
  screen_cls();
  screen_println("Hello World!");
  screen_set_color(YELLOW);
  screen_set_background_color(BLUE);
  screen_println("Hello World!");
}
