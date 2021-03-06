#ifndef _SYSTEM_H
#define _SYSTEM_H

extern void *memcpy(void *dest, const void *src, int count);
extern void *memcpyw(void *dest, const void *src, int count);
extern void *memset(void *dest, char val, int count);
extern unsigned short *memsetw(unsigned short *dest, unsigned short val, int count);
extern int strlen(const char *str);
extern unsigned char port_inb (unsigned short _port);
extern void port_outb (unsigned short _port, unsigned char _data);

#endif
