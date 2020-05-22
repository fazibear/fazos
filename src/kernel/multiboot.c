#include "multiboot.h"

struct multiboot_header boot_header
__attribute__ ((section(".multiboot"))) = {
  MULTIBOOT_HEADER_MAGIC,
  MULTIBOOT_FLAGS,
  MULTIBOOT_CHECKSUM,
  0, 0, 0, 0, 0,
  0, 0, 0, 0,
};

