#include "debug.h"
#include "serial.h"

void _putchar(char c){
  serial_write_char(SERIAL_COM1, c);
}

void debug_init() {
  serial_init(SERIAL_COM1);
}
