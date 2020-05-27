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
  DEBUG_INIT_START();
  unsigned long free_memory = 0;

  struct multiboot_mmap_entry* memory_map_pointer = (struct multiboot_mmap_entry*)info->mmap_addr;
  int mmap_entries = info->mmap_length / sizeof(struct multiboot_mmap_entry);

  for(int i = 0; i < mmap_entries; i++) {
    if(memory_map_pointer->type == MULTIBOOT_MEMORY_AVAILABLE) {
      DEBUG("%ld %ld", memory_map_pointer->len, memory_map_pointer->addr);
      DEBUG("%ld", memory_map_pointer->addr);
      free_memory += memory_map_pointer->len;
      for(unsigned long address = memory_map_pointer->addr; address < memory_map_pointer->addr + memory_map_pointer->len; address+=PAGE_SIZE) {
        if(address > PMEM_FREE_PAGES_END) {
          pmem_free_pages_add(page_align(address));
        }
      }
    }
    memory_map_pointer++;
  }

  DEBUG("Memory free: %d MB", free_memory / 1024 / 1024);
  DEBUG("Memory free: %d pages", pmem_free_pages - PMEM_FREE_PAGES_START);

  DEBUG_INIT_END();
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
  return (address + PAGE_SIZE - 1) & (-PAGE_SIZE + 1);
}

