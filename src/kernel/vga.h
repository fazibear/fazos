#ifndef _VGA_H
#define _VGA_H

#define VGA_SCREEN_ADDRESS 0xB8000
#define VGA_SCREEN_WIDTH 80
#define VGA_SCREEN_HEIGHT 25
#define VGA_SCREEN_SIZE VGA_SCREEN_HEIGHT * VGA_SCREEN_WIDTH

#define STRIPPATH(s)\
    (sizeof(s) > 2 && (s)[sizeof(s)-2] == '/' ? (s) + sizeof(s) - 1 : \
    sizeof(s) > 3 && (s)[sizeof(s)-3] == '/' ? (s) + sizeof(s) - 2 : \
    sizeof(s) > 4 && (s)[sizeof(s)-4] == '/' ? (s) + sizeof(s) - 3 : \
    sizeof(s) > 5 && (s)[sizeof(s)-5] == '/' ? (s) + sizeof(s) - 4 : \
    sizeof(s) > 6 && (s)[sizeof(s)-6] == '/' ? (s) + sizeof(s) - 5 : \
    sizeof(s) > 7 && (s)[sizeof(s)-7] == '/' ? (s) + sizeof(s) - 6 : \
    sizeof(s) > 8 && (s)[sizeof(s)-8] == '/' ? (s) + sizeof(s) - 7 : \
    sizeof(s) > 9 && (s)[sizeof(s)-9] == '/' ? (s) + sizeof(s) - 8 : \
    sizeof(s) > 10 && (s)[sizeof(s)-10] == '/' ? (s) + sizeof(s) - 9 : \
    sizeof(s) > 11 && (s)[sizeof(s)-11] == '/' ? (s) + sizeof(s) - 10 : (s))

#define __FILENAME__ STRIPPATH(__FILE__)

#define LOG(FORMAT, ...) \
    vga_printf("%s() in %s: " FORMAT "\n", __func__, __FILENAME__, __VA_ARGS__)

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
void vga_set_background(enum VGA_COLOR);
void vga_set_foreground(enum VGA_COLOR);
void vga_print_char(char);
void vga_print_string(char*);
void vga_update_cursor();
void vga_screen_scroll();

int vga_printf(const char *format, ...);
int vga_sprintf(char *out, const char *format, ...);

#endif
