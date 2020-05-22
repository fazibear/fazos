#ifndef _MULTIBOOT_H
#define _MULTIBOOT_H

#define MULTIBOOT_MAGIC 0x1BADB002 // multiboot magic
#define MULTIBOOT_ALIGN 1 << 0 // Align loaded modules at 4k
#define MULTIBOOT_MEMINFO 1 << 1 // Receive a memory map from the bootloader.
#define MULTIBOOT_ADDR 1 << 16 // Load specific addr
#define MULTIBOOT_FLAGS ALIGN | MEMINFO // Combine the flags.
#define MULTIBOOT_CHECKSUM ~(MAGIC +% FLAGS) +% 1

struct multiboot_header {
  unsigned int magic;
} __attribute__((section(".multiboot")));

// pub const Header = packed struct {
//     magic: u32 = MAGIC, // Must be equal to header magic number.
//     flags: u32 = FLAGS, // Feature flags.
//     checksum: u32 = CHECKSUM, // Above fields plus this one must equal 0 mod 2^32.
//     // following fields are used if flag bit 16 is specified
//     header_addr: u32 = 0,
//     load_addr: u32 = 0,
//     load_end_addr: u32 = 0,
//     bss_end_addr: u32 = 0,
//     entry_addr: u32 = 0,
// };
// struct multiboot_header {
//   ...
// } __attribute__((section(".multiboot")));
#endif
