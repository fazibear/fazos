#include "screen.h"

unsigned short *screen_mem = (unsigned short*) SCREEN_ADDRESS;
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
  for(int i = 0; i < SCREEN_BUFSIZE; i++) {
    screen_mem[i] = 0;
  }
  screen_current = 0;
}

void screen_print_char(char ch) {
  screen_mem[screen_current++] = screen_current_background_color << 12 | screen_current_color << 8 | ch;
}

void screen_print_string(char *string) {
  char *ch;
  unsigned int i;

  for (ch = string, i = 0; *ch; ch++, i++) {
    switch(*ch) {
    case '\n':
      screen_current += SCREEN_WIDTH - screen_current % SCREEN_WIDTH;
      break;

    case 30 ... 47:
    case 58 ... 126:
      screen_print_char(*ch);
      break;
    }
  }
}
