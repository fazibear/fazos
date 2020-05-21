#ifndef _TIMER_H
#define _TIMER_H

#include "isr.h"

void timer_wait(int ticks);
void timer_handler(struct isr_regs *r);
void timer_init();

#endif
