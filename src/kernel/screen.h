#ifndef _SCREEN_H
#define _SCREEN_H

#include "system.h"

#define SCREEN_ADDRESS 0xB8000
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define SCREEN_BUFSIZE SCREEN_HEIGHT * SCREEN_WIDTH

enum screen_color {
  BLACK,
  BLUE,
  GREEN,
  CYAN,
  RED,
  MAGENTA,
  BROWN,
  GREY,
  DARK_GREY,
  BRIGHT_BLUE,
  BRIGHT_GREEN,
  BRIGHT_CYAN,
  BRIGHT_RED,
  BRIGHT_MAGENTA,
  YELLOW,
  WHITE,
};

void screen_cls();
void screen_new_line();
void screen_print_char(char ch);
void screen_print_string(char *string);
void screen_set_color(short color);
void screen_set_background_color(short color);

#endif
