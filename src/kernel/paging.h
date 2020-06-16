#ifndef _PAGING_H
#define _PAGING_H

#define PAGING_PAGE_DIRECTORY_FLAG_IGNORED 1 << 8
#define PAGING_PAGE_DIRECTORY_FLAG_PAGE_SIZE 1 << 6
#define PAGING_PAGE_DIRECTORY_FLAG_ACCESSED 1 << 5
#define PAGING_PAGE_DIRECTORY_FLAG_CACHE_DISABLED 1 << 4
#define PAGING_PAGE_DIRECTORY_FLAG_WRITE_THROUGH 1 << 3
#define PAGING_PAGE_DIRECTORY_FLAG_USER 1 << 2
#define PAGING_PAGE_DIRECTORY_FLAG_WRITE 1 << 1
#define PAGING_PAGE_DIRECTORY_FLAG_PRESENT 1 << 0

#define PAGING_PAGE_TABLE_FLAG_GLOBAL 1 << 8
#define PAGING_PAGE_TABLE_FLAG_DIRTY 1 << 6
#define PAGING_PAGE_TABLE_FLAG_ACCESSED 1 << 5
#define PAGING_PAGE_TABLE_FLAG_CACHE_DISABLED 1 << 4
#define PAGING_PAGE_TABLE_FLAG_WRITE_THROUGH 1 << 3
#define PAGING_PAGE_TABLE_FLAG_USER 1 << 2
#define PAGING_PAGE_TABLE_FLAG_WRITE 1 << 1
#define PAGING_PAGE_TABLE_FLAG_PRESENT 1 << 0

extern void paging_load_page_directory(unsigned int);
extern void paging_enable();

void paging_init();
unsigned long paging_entry(unsigned long address, short flags);

void paging_init();

#endif
