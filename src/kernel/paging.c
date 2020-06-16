#include "paging.h"
#include "debug.h"


unsigned long paging_page_directory[1024] __attribute__((aligned(4096)));
unsigned long paging_page_table_1[1024] __attribute__((aligned(4096)));

void paging_init() {
  INIT_START();

  for(int i = 0; i < 1024; i++) {
    // This sets the following flags to the pages:
    //   Supervisor: Only kernel-mode can access them
    //   Write Enabled: It can be both read from and written to
    //   Not Present: The page table is not present
    paging_page_directory[i] = paging_entry(0x0, PAGING_PAGE_DIRECTORY_FLAG_WRITE);
  }

  //we will fill all 1024 entries in the table, mapping 4 megabytes
  for(int i = 0; i < 1024; i++) {
    // As the address is page aligned, it will always leave 12 bits zeroed.
    // Those bits are used by the attributes ;)
    paging_page_table_1[i] = paging_entry(i * 0x1000, PAGING_PAGE_TABLE_FLAG_WRITE | PAGING_PAGE_TABLE_FLAG_PRESENT);
  }

  // attributes: supervisor level, read/write, present
  paging_page_directory[0] = paging_entry((unsigned int)paging_page_table_1, PAGING_PAGE_DIRECTORY_FLAG_WRITE | PAGING_PAGE_DIRECTORY_FLAG_PRESENT);

  paging_load_page_directory((unsigned int)paging_page_directory);
  paging_enable();

  INIT_END();
}

unsigned long paging_entry(unsigned long address, short flags) {
  return (address &= ~0b111111111111) | flags;
}
