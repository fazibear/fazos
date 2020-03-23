#include "screen.h"

unsigned short *screen_mem = (unsigned short*) VGA_ADDRESS;
unsigned short screen_current = 0;
unsigned short screen_current_color = WHITE;
unsigned short screen_current_background_color = BLACK;

void screen_set_color(short color) {
  screen_current_color = color;
}

void screen_set_background_color(short color) {
  screen_current_background_color = color;
}

void screen_cls() {
  for(int i = 0; i < VGA_BUFSIZE; i++) {
    screen_mem[i] = 0;
  }
  screen_current = 0;
}

void screen_print(char *string) {
  char *ch;
  unsigned i;

  for (ch = string, i = 0; *ch; ch++, i++)
    screen_mem[screen_current++] = screen_current_background_color << 12 | screen_current_color << 8 | (unsigned char) *ch;
}

void screen_println(char *string) {
  screen_print(string);
}

