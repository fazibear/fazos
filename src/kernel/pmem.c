#include "pmem.h"

#include "multiboot.h"
#include "debug.h"

#define PMEM_FREE_PAGES_START (unsigned int*)0x200000
#define PMEM_FREE_PAGES_END 0x300000
#define PAGE_SIZE 4096

unsigned int* pmem_free_pages = PMEM_FREE_PAGES_START;

unsigned long pmem_free_asd() {
  return pmem_free_pages - PMEM_FREE_PAGES_START;
}

void pmem_init(struct multiboot_info* info) {
  INIT_START();
  unsigned long free_memory = 0;

  struct multiboot_mmap_entry* memory_map_pointer = (struct multiboot_mmap_entry*)info->mmap_addr;
  int mmap_entries = info->mmap_length / sizeof(struct multiboot_mmap_entry);

  for(int i = 0; i < mmap_entries; i++) {
    if(memory_map_pointer->type == MULTIBOOT_MEMORY_AVAILABLE) {
      free_memory += memory_map_pointer->len;
      for(unsigned long address = memory_map_pointer->addr; address < memory_map_pointer->addr + memory_map_pointer->len; address+=PAGE_SIZE) {
        if(address > PMEM_FREE_PAGES_END) {
          // INFO("Free page at 0x%x", page_align(address));
          pmem_free_pages_add(page_align(address));
        }
      }
    }
    memory_map_pointer++;
  }

  INFO("Memory free: %d MB", free_memory / 1024 / 1024);
  INFO("Memory free: %d pages", pmem_free_pages - PMEM_FREE_PAGES_START);

  INIT_END();
}


void pmem_free_pages_add(unsigned int addr) {
  *pmem_free_pages = addr;
  pmem_free_pages++;
}

unsigned long long pmem_free_pages_del() {
  if(pmem_free_pages > (unsigned int *)PMEM_FREE_PAGES_START) {
    unsigned long long addr = *pmem_free_pages;
    pmem_free_pages--;
    return addr;
  } else {
    ERROR("OUT OF MEMORY");
    return 0;
  }
}

unsigned long page_align(unsigned long address) {
  return (address + (PAGE_SIZE - 1)) & (~(PAGE_SIZE - 1));
}

