#ifndef _PMEM_H
#define _PMEM_H

#include "multiboot.h"

void pmem_init(struct multiboot_info* info);
void pmem_free(unsigned int addr);
unsigned long page_align(unsigned long address);
void pmem_free_pages_add(unsigned int addr);
unsigned long long pmem_free_pages_del();

#endif
