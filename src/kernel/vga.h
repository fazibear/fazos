#ifndef _VGA_H
#define _VGA_H

#define VGA_SCREEN_ADDRESS 0xB8000
#define VGA_SCREEN_WIDTH 80
#define VGA_SCREEN_HEIGHT 25
#define VGA_SCREEN_SIZE VGA_SCREEN_HEIGHT * VGA_SCREEN_WIDTH

enum VGA_COLOR {
  VGA_COLOR_BLACK,
  VGA_COLOR_BLUE,
  VGA_COLOR_GREEN,
  VGA_COLOR_CYAN,
  VGA_COLOR_RED,
  VGA_COLOR_MAGENTA,
  VGA_COLOR_BROWN,
  VGA_COLOR_GREY,
  VGA_COLOR_DARK_GREY,
  VGA_COLOR_BRIGHT_BLUE,
  VGA_COLOR_BRIGHT_GREEN,
  VGA_COLOR_BRIGHT_CYAN,
  VGA_COLOR_BRIGHT_RED,
  VGA_COLOR_BRIGHT_MAGENTA,
  VGA_COLOR_YELLOW,
  VGA_COLOR_WHITE,
};

void vga_init();
void vga_clear();
unsigned short vga_screen_entry(char);
void vga_set_background_color(enum VGA_COLOR);
void vga_set_foreground(enum VGA_COLOR);
void vga_print_char(char);
void vga_print_string(char*);
void vga_update_cursor();
void vga_screen_scroll();

#endif
