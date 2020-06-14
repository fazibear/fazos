#include "paging.h"
#include "debug.h"


unsigned long paging_page_directory[1024] __attribute__((aligned(4096)));
unsigned long paging_first_page_table[1024] __attribute__((aligned(4096)));

void paging_init() {
  INIT_START();

  for(int i = 0; i < 1024; i++) {
    // This sets the following flags to the pages:
    //   Supervisor: Only kernel-mode can access them
    //   Write Enabled: It can be both read from and written to
    //   Not Present: The page table is not present
    paging_page_directory[i] = 0x00000002;
  }

  //we will fill all 1024 entries in the table, mapping 4 megabytes
  for(int i = 0; i < 1024; i++) {
    // As the address is page aligned, it will always leave 12 bits zeroed.
    // Those bits are used by the attributes ;)
    paging_first_page_table[i] = (i * 0x1000) | 3; // attributes: supervisor level, read/write, present.
  }

  // attributes: supervisor level, read/write, present
  paging_page_directory[0] = ((unsigned int)paging_first_page_table) | 3;

  paging_load_page_directory((unsigned int)paging_page_directory);
  paging_enable();

  INIT_END();
}
