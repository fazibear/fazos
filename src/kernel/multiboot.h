#ifndef _MULTIBOOT_H
#define _MULTIBOOT_H

#define MULTIBOOT_MAGIC 0x1BADB002 // multiboot magic
#define MULTIBOOT_ALIGN 1 << 0 // Align loaded modules at 4k
#define MULTIBOOT_MEMINFO 1 << 1 // Receive a memory map from the bootloader.
#define MULTIBOOT_ADDR 1 << 16 // Load specific addr
#define MULTIBOOT_FLAGS (MULTIBOOT_ALIGN | MULTIBOOT_MEMINFO) // Combine the flags.
#define MULTIBOOT_CHECKSUM -(MULTIBOOT_MAGIC + MULTIBOOT_FLAGS)

struct multiboot_header {
  unsigned int magic;
  unsigned int flags;
  unsigned int checksum;
  unsigned int header_addr;
  unsigned int load_addr;
  unsigned int load_end_addr;
  unsigned int entry_addr;
};

#endif
