#include "serial.h"
#include "system.h"

int serial_received(enum serial_port port) {
  return port_inb(port + 5) & 1;
}

int serial_is_transmit_empty(enum serial_port port) {
  return port_inb(port + 5) & 0x20;
}

char serial_read_char(enum serial_port port) {
  while (serial_received(port) == 0);

  return port_inb(port);
}

void serial_write_char(enum serial_port port, char c) {
  while (serial_is_transmit_empty(port) == 0);

  port_outb(port, c);
}

void serial_write_string(enum serial_port port, char* string) {
  char *ch;
  unsigned int i;

  for (ch = string, i = 0; *ch; ch++, i++) {
    serial_write_char(port, *ch);
  }
}

void serial_init(enum serial_port port) {
  port_outb(port + 1, 0x00);    // Disable all interrupts
  port_outb(port + 3, 0x80);    // Enable DLAB (set baud rate divisor)
  port_outb(port + 0, 0x01);    // Set divisor to 3 (lo byte) 38400 baud
  port_outb(port + 1, 0x00);    //                  (hi byte)
  port_outb(port + 3, 0x03);    // 8 bits, no parity, one stop bit
  port_outb(port + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
  port_outb(port + 4, 0x0B);    // IRQs enabled, RTS/DSR set}

}
