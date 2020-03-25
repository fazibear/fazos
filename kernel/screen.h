#ifndef SCREEN_H
#define SCREEN_H

#define SCREEN_ADDRESS 0xB8000
#define SCREEN_BUFSIZE 2200
#define SCREEN_WIDTH 80

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

unsigned short* screen_mem;
unsigned short screen_current;
unsigned short screen_current_color;
unsigned short screen_current_background_color;


void screen_cls();
void screen_print_char(char ch);
void screen_print(char *string);
void screen_print_n();
void screen_println(char *string);
void screen_set_color(short color);
void screen_set_background_color(short color);

#endif
