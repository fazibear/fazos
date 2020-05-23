#ifndef _PMEM_H
#define _PMEM_H

#include "multiboot.h"

void pmem_init(struct multiboot_info* info);
void pmem_free(unsigned int addr);

#endif
