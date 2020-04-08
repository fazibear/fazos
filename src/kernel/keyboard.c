#include "system.h"
#include "keyboard.h"
#include "screen.h"
#include "irq.h"
#include "helpers.h"
#include "stdbool.h"

bool keyboard_shift = false;
bool keyboard_alt = false;

unsigned char keyboard_chars[128] = {
  0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b', '\t',
  'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', 0, 'a', 's',
  'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0, '\\', 'z', 'x', 'c', 'v',
  'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' ',  0, 0,  0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

unsigned char keyboard_chars_shift[128] = {
  0, 0, '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '\b', '\t',
  'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n', 0, 'A', 'S',
  'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '"', '~', 0, '|', 'Z', 'X', 'C', 'V',
  'B', 'N', 'M', '<', '>', '?', 0, '0', 0, ' ',  0, 0,  0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

bool set_control_keys(unsigned char scancode) {
  switch(scancode) {
  case 0x2a:
  case 0x36:
    keyboard_shift = true;
    return true;
  case 0x38:
    keyboard_alt = true;
    return true;
  case 0xAA:
  case 0xB6:
    keyboard_shift = false;
    return true;
  case 0xB8:
    keyboard_alt = false;
    return true;
  default:
    return false;
  }
}

unsigned char scancode_to_char(unsigned char scancode) {
  if(keyboard_shift) {
    return keyboard_chars_shift[scancode];
  } else {
    return keyboard_chars[scancode];
  }
}

/* Handles the keyboard interrupt */
void keyboard_handler(struct regs *r UNUSED ) {
  unsigned char scancode;

  /* Read from the keyboard's data buffer */
  scancode = inportb(0x60);

  /* If the top bit of the byte we read from the keyboard is
  *  set, that means that a key has just been released */
  if (scancode & 0x80) {
    set_control_keys(scancode);
  } else {
    if(!set_control_keys(scancode)) {
      screen_print_char(scancode_to_char(scancode));
    }
  }
}

void keyboard_install() {
  /* Installs 'timer_handler' to IRQ0 */
  irq_install_handler(1, keyboard_handler);
}



