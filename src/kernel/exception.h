#ifndef _EXCEPTION_H
#define _EXCEPTION_H

#include "isr.h"

void exception_handler(struct isr_regs *context);

#endif
