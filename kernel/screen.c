#include "screen.h"

unsigned short *screen_mem = (unsigned short*) 0xb8000;
unsigned short screen_current = 0;

void screen_cls() {
  for(int i = 0; i < BUFSIZE; i++) {
    screen_mem[i] = 0;
  }
  screen_current = 0;
}

void screen_print(char *string) {
  char *ch;
  unsigned i;

  for (ch = string, i = 0; *ch; ch++, i++)
    screen_mem[screen_current++] = (unsigned char) *ch | 0x1200;
}

void screen_println(char *string) {
  screen_print(string);
}
