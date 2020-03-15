#ifndef SCREEN_H
#define SCREEN_H

#define VGA_ADDRESS 0xB8000
#define BUFSIZE 2200
#define NULL 0

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
void screen_cls();
void screen_print(char *string);

#endif
