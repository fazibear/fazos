#ifndef _GDT_H
#define _GDT_H

// Access byte values.
#define GDT_ACCESS_KERNEL 0x90
#define GDT_ACCESS_USER 0xF0
#define GDT_ACCESS_CODE 0x0A
#define GDT_ACCESS_DATA 0x02

// Segment flags.
#define GDT_SEGMENT_PROTECTED (1 << 2)
#define GDT_SEGMENT_BLOCKS_4K (1 << 3)

struct gdt_entry {
  unsigned short limit_low;
  unsigned short base_low;
  unsigned char base_middle;
  unsigned char access;
  unsigned char limit_high_flags;
  unsigned char base_high;
} __attribute__((packed));

struct gdt_register {
  unsigned short limit;
  unsigned int base;
} __attribute__((packed));

extern void load_gdt(struct gdt_register*);

void gdt_init();
void gdt_set_entry(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);

#endif
