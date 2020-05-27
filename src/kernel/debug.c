#include "debug.h"
#include "serial.h"

void _putchar(char c) {
  serial_write_char(SERIAL_COM1, c);
}

void debug_init() {
  DEBUG_INIT_START();
  serial_init(SERIAL_COM1);
  DEBUG_INIT_END();
}
