#include "screen.h"

void _main() {
  screen_cls();
  screen_print("Hello World!");
  screen_set_color(YELLOW);
  screen_set_background_color(BLUE);
  screen_print("Hello World!");
}
