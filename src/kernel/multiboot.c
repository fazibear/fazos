#include "multiboot.h"

struct multiboot_header boot_header
__attribute__ ((aligned (4), section(".multiboot"))) = {
  MULTIBOOT_MAGIC,
  MULTIBOOT_FLAGS,
  MULTIBOOT_CHECKSUM,
  0, 0, 0, 0
};

