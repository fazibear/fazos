#ifndef _PAGING_H
#define _PAGING_H

extern void paging_load_page_directory(unsigned int);
extern void paging_enable();

void paging_init();

#endif
