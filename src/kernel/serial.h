#ifndef _SERIAL_H
#define _SERIAL_H

enum serial_port {
    SERIAL_COM1 = 0x3F8,
    SERIAL_COM2 = 0x2F8,
    SERIAL_COM3 = 0x3E8,
    SERIAL_COM4 = 0x2E8,
};

char serial_read_char(enum serial_port port);
void serial_write_char(enum serial_port port, char c);
void serial_write_string(enum serial_port port, char* s);
void serial_write_string(enum serial_port port, char* string);
void serial_init(enum serial_port port);

#endif
