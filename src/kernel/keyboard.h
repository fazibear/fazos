#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include "system.h"
#include "screen.h"
#include "irq.h"
#include "helpers.h"
#include "stdbool.h"

unsigned char keyboard_chars[128];
unsigned char keyboard_chars_shift[128];

void keyboard_handler(struct regs *r);
void keyboard_install();

#endif
