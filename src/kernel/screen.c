#include "system.h"
#include "screen.h"

unsigned short *screen_mem = (unsigned short*) SCREEN_ADDRESS;
unsigned short screen_current = 0;
unsigned short screen_current_color = WHITE;
unsigned short screen_current_background_color = BLACK;

unsigned short screen_char_with_color(char c) {
  return screen_current_background_color << 12 | screen_current_color << 8 | c;
}

void screen_set_color(short color) {
  screen_current_color = color;
}

void screen_set_background_color(short color) {
  screen_current_background_color = color;
}

/* Updates the hardware cursor: the little blinking line
*  on the screen under the last character pressed! */
void screen_set_cursor(void) {
  outportb(0x3D4, 14);
  outportb(0x3D5, screen_current >> 8);
  outportb(0x3D4, 15);
  outportb(0x3D5, screen_current);
}

void screen_cls() {
  memsetw(screen_mem, screen_char_with_color(0), SCREEN_BUFSIZE);
  screen_current = 0;
}

void screen_check_for_new_line(int offset) {
  if(screen_current + offset + SCREEN_WIDTH >= SCREEN_BUFSIZE) {
    memcpy(screen_mem, screen_mem + SCREEN_WIDTH, SCREEN_BUFSIZE - SCREEN_WIDTH);
    memsetw(screen_mem + SCREEN_BUFSIZE - SCREEN_WIDTH, screen_char_with_color(0), SCREEN_WIDTH);
    screen_current =- SCREEN_WIDTH;
  }
}

void screen_print_char(char ch) {
  screen_check_for_new_line(1);
  screen_mem[screen_current++] = screen_char_with_color(ch);
}

void screen_print_string(char *string) {
  char *ch;
  unsigned int i;

  for (ch = string, i = 0; *ch; ch++, i++) {
    switch(*ch) {
    case '\n':
      screen_check_for_new_line(SCREEN_WIDTH - screen_current % SCREEN_WIDTH);
      screen_current += SCREEN_WIDTH - screen_current % SCREEN_WIDTH;
      break;

    case 32 ... 126:
      screen_print_char(*ch);
      break;
    }
  }
  screen_set_cursor();
}
