#include "pmem.h"

#include "multiboot.h"
#include "vga.h"

#define PMEM_FREE_PAGES_START 0x200000
#define PMEM_FREE_PAGES_END 0x300000
#define PAGE_SIZE 4096

unsigned int* pmem_free_pages = (unsigned int*)PMEM_FREE_PAGES_START;

void pmem_init(struct multiboot_info* info) {

  struct multiboot_mmap_entry* memory_map_pointer = (struct multiboot_mmap_entry*)info->mmap_addr;
  int mmap_entries = info->mmap_length / sizeof(struct multiboot_mmap_entry);

  for(int i = 0; i < mmap_entries; i++){
    if(memory_map_pointer->type == MULTIBOOT_MEMORY_AVAILABLE){
        vga_printf("Memory map freee: %x\n", memory_map_pointer->len);
      }
    memory_map_pointer++;
  }

  vga_printf("Memory map addr: %x\n", info->mmap_addr);
  vga_printf("Memory map length: %d\n", info->mmap_length);
  vga_printf("Memory map end: %x\n", info->mmap_addr + info->mmap_length);
  vga_printf("Memory size: %d\n", sizeof(struct multiboot_mmap_entry));

  vga_printf("Memory free stack: %d\n", pmem_free_pages);
}

void pmem_free_pages_add(unsigned int addr) {
  *pmem_free_pages = addr;
  pmem_free_pages++;
}

unsigned long long pmem_free_pages_del() {
  if(pmem_free_pages > (unsigned int *)PMEM_FREE_PAGES_START){
    unsigned long long addr = *pmem_free_pages;
    pmem_free_pages--;
    return addr;
  }else{
    return 0;
    //out of memory
  }
}

unsigned long long page_align(unsigned long long address) {
    return (address + PAGE_SIZE - 1) & (-PAGE_SIZE + 1);
}

