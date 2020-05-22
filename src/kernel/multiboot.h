#ifndef _MULTIBOOT_H
#define _MULTIBOOT_H

/* The magic field should contain this. */
#define MULTIBOOT_HEADER_MAGIC 0x1BADB002

/* This should be in %eax. */
#define MULTIBOOT_BOOTLOADER_MAGIC 0x2BADB002

/* Alignment of multiboot modules. */
#define MULTIBOOT_MOD_ALIGN 0x00001000

/* Alignment of the multiboot info structure. */
#define MULTIBOOT_INFO_ALIGN 0x00000004

/* Flags set in the 'flags' member of the multiboot header. */

/* Align all boot modules on i386 page (4KB) boundaries. */
#define MULTIBOOT_PAGE_ALIGN 0x00000001

/* Must pass memory information to OS. */
#define MULTIBOOT_MEMORY_INFO 0x00000002

/* Must pass video information to OS. */
#define MULTIBOOT_VIDEO_MODE 0x00000004

/* This flag indicates the use of the address fields in the header. */
#define MULTIBOOT_AOUT_KLUDGE 0x00010000

/* Flags to be set in the 'flags' member of the multiboot info structure. */

/* is there basic lower/upper memory information? */
#define MULTIBOOT_INFO_MEMORY 0x00000001
/* is there a boot device set? */
#define MULTIBOOT_INFO_BOOTDEV 0x00000002
/* is the command-line defined? */
#define MULTIBOOT_INFO_CMDLINE 0x00000004
/* are there modules to do something with? */
#define MULTIBOOT_INFO_MODS 0x00000008

/* These next two are mutually exclusive */

/* is there a symbol table loaded? */
#define MULTIBOOT_INFO_AOUT_SYMS 0x00000010
/* is there an ELF section header table? */
#define MULTIBOOT_INFO_ELF_SHDR 0X00000020

/* is there a full memory map? */
#define MULTIBOOT_INFO_MEM_MAP 0x00000040

/* Is there drive info? */
#define MULTIBOOT_INFO_DRIVE_INFO 0x00000080

/* Is there a config table? */
#define MULTIBOOT_INFO_CONFIG_TABLE 0x00000100

/* Is there a boot loader name? */
#define MULTIBOOT_INFO_BOOT_LOADER_NAME 0x00000200

/* Is there a APM table? */
#define MULTIBOOT_INFO_APM_TABLE 0x00000400

/* Is there video information? */
#define MULTIBOOT_INFO_VBE_INFO 0x00000800
#define MULTIBOOT_INFO_FRAMEBUFFER_INFO 0x00001000

#define MULTIBOOT_FRAMEBUFFER_TYPE_INDEXED 0
#define MULTIBOOT_FRAMEBUFFER_TYPE_RGB     1
#define MULTIBOOT_FRAMEBUFFER_TYPE_EGA_TEXT	2

#define MULTIBOOT_MEMORY_AVAILABLE		1
#define MULTIBOOT_MEMORY_RESERVED		2
#define MULTIBOOT_MEMORY_ACPI_RECLAIMABLE       3
#define MULTIBOOT_MEMORY_NVS                    4
#define MULTIBOOT_MEMORY_BADRAM                 5

#define MULTIBOOT_FLAGS (MULTIBOOT_INFO_ALIGN | MULTIBOOT_MEMORY_INFO)
#define MULTIBOOT_CHECKSUM -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_FLAGS)

struct multiboot_header {
  /* Must be MULTIBOOT_MAGIC - see above. */
  unsigned int magic;

  /* Feature flags. */
  unsigned int flags;

  /* The above fields plus this one must equal 0 mod 2^32. */
  unsigned int checksum;

  /* These are only valid if MULTIBOOT_AOUT_KLUDGE is set. */
  unsigned int header_addr;
  unsigned int load_addr;
  unsigned int load_end_addr;
  unsigned int bss_end_addr;
  unsigned int entry_addr;

  /* These are only valid if MULTIBOOT_VIDEO_MODE is set. */
  unsigned int mode_type;
  unsigned int width;
  unsigned int height;
  unsigned int depth;
};

/* The symbol table for a.out.  */
struct multiboot_aout_symbol_table {
  unsigned int tabsize;
  unsigned int strsize;
  unsigned int addr;
  unsigned int reserved;
};

/* The section header table for ELF.  */
struct multiboot_elf_section_header_table {
  unsigned int num;
  unsigned int size;
  unsigned int addr;
  unsigned int shndx;
};

struct multiboot_info {
  /* Multiboot info version number */
  unsigned int flags;

  /* Available memory from BIOS */
  unsigned int mem_lower;
  unsigned int mem_upper;

  /* "root" partition */
  unsigned int boot_device;

  /* Kernel command line */
  unsigned int cmdline;

  /* Boot-Module list */
  unsigned int mods_count;
  unsigned int mods_addr;

  union {
    struct multiboot_aout_symbol_table aout_sym;
    struct multiboot_elf_section_header_table elf_sec;
  } u;

  /* Memory Mapping buffer */
  unsigned int mmap_length;
  unsigned int mmap_addr;

  /* Drive Info buffer */
  unsigned int drives_length;
  unsigned int drives_addr;

  /* ROM configuration table */
  unsigned int config_table;

  /* Boot Loader Name */
  unsigned int boot_loader_name;

  /* APM table */
  unsigned int apm_table;

  /* Video */
  unsigned int vbe_control_info;
  unsigned int vbe_mode_info;
  unsigned short vbe_mode;
  unsigned short vbe_interface_seg;
  unsigned short vbe_interface_off;
  unsigned short vbe_interface_len;

  unsigned long long framebuffer_addr;
  unsigned int framebuffer_pitch;
  unsigned int framebuffer_width;
  unsigned int framebuffer_height;
  unsigned char framebuffer_bpp;
  unsigned char framebuffer_type;
  union {
    struct {
      unsigned int framebuffer_palette_addr;
      unsigned short framebuffer_palette_num_colors;
    };
    struct {
      unsigned char framebuffer_red_field_position;
      unsigned char framebuffer_red_mask_size;
      unsigned char framebuffer_green_field_position;
      unsigned char framebuffer_green_mask_size;
      unsigned char framebuffer_blue_field_position;
      unsigned char framebuffer_blue_mask_size;
    };
  };
};

struct multiboot_color {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
};

struct multiboot_mmap_entry {
  unsigned int size;
  unsigned long long addr;
  unsigned long long len;
  unsigned int type;
} __attribute__((packed));

struct multiboot_mod_list {
  /* the memory used goes from bytes 'mod_start' to 'mod_end-1' inclusive */
  unsigned int mod_start;
  unsigned int mod_end;

  /* Module command line */
  unsigned int cmdline;

  /* padding to take it to 16 bytes (must be zero) */
  unsigned int pad;
};

/* APM BIOS info.  */
struct multiboot_apm_info {
  unsigned short version;
  unsigned short cseg;
  unsigned int offset;
  unsigned short cseg_16;
  unsigned short dseg;
  unsigned short flags;
  unsigned short cseg_len;
  unsigned short cseg_16_len;
  unsigned short dseg_len;
};

#endif
