#include "vga.h"
#include "system.h"

unsigned short *vga_video_memory = (unsigned short*) 0xb8000;
unsigned int vga_current_position = 0;

enum VGA_COLOR vga_current_backgroud = VGA_COLOR_BLACK;
enum VGA_COLOR vga_current_foreground = VGA_COLOR_WHITE;

void vga_init() {
  vga_clear();
  vga_print_string("\n                           ");
  vga_set_foreground(VGA_COLOR_YELLOW);
  vga_print_string("* ");
  vga_set_foreground(VGA_COLOR_BLUE);
  vga_print_string("* ");
  vga_set_foreground(VGA_COLOR_RED);
  vga_print_string("* ");
  vga_set_foreground(VGA_COLOR_GREEN);
  vga_print_string("* ");
  vga_set_foreground(VGA_COLOR_GREY);
  vga_print_string("* ");

  vga_set_foreground(VGA_COLOR_WHITE);
  vga_print_string("FAZOS ");

  vga_set_foreground(VGA_COLOR_GREY);
  vga_print_string("* ");
  vga_set_foreground(VGA_COLOR_GREEN);
  vga_print_string("* ");
  vga_set_foreground(VGA_COLOR_RED);
  vga_print_string("* ");
  vga_set_foreground(VGA_COLOR_BLUE);
  vga_print_string("* ");
  vga_set_foreground(VGA_COLOR_YELLOW);
  vga_print_string("*\n\n");

  vga_set_foreground(VGA_COLOR_WHITE);
  vga_print_string("READY.\n");;
}

void vga_clear() {
  memsetw(vga_video_memory, vga_screen_entry(0), VGA_SCREEN_SIZE);
  vga_current_position = 0;
}

void vga_set_background(enum VGA_COLOR color) {
  vga_current_backgroud = color;
}

void vga_set_foreground(enum VGA_COLOR color) {
  vga_current_foreground = color;
}

unsigned short vga_screen_entry(char c) {
  return vga_current_backgroud << 12 | vga_current_foreground << 8 | c;
}

void vga_print_char(char character) {
  switch (character) {
  case '\n': // New line
    vga_current_position += VGA_SCREEN_WIDTH - vga_current_position % VGA_SCREEN_WIDTH;
    break;
  case '\r': // Return
    vga_current_position %= VGA_SCREEN_WIDTH;
    break;
  case '\t': // Tab
    vga_print_char(' ');
    break;
  case '\x08': // Backspace.
    vga_current_position -= 1;
    vga_print_char(' ');
    vga_current_position -= 1;
    break;
  default:
    vga_video_memory[vga_current_position] = vga_screen_entry(character);
    vga_current_position += 1;
  }

  if (vga_current_position >= VGA_SCREEN_SIZE) {
    vga_screen_scroll();
  }

  vga_update_cursor();
}

void vga_print_string(char* string) {
  char *ch;
  unsigned int i;

  for (ch = string, i = 0; *ch; ch++, i++) {
    vga_print_char(*ch);
  }
}

void vga_update_cursor() {
  outportb(0x3D4, 0x0F);
  outportb(0x3D5, vga_current_position);
  outportb(0x3D4, 0x0E);
  outportb(0x3D5, vga_current_position >> 8);
}

void vga_screen_scroll() {
  memcpyw(vga_video_memory, vga_video_memory + VGA_SCREEN_WIDTH, VGA_SCREEN_SIZE - VGA_SCREEN_WIDTH);
  memsetw(vga_video_memory + VGA_SCREEN_SIZE - VGA_SCREEN_WIDTH, vga_screen_entry(0), VGA_SCREEN_WIDTH);
  vga_current_position -= VGA_SCREEN_WIDTH;
}

