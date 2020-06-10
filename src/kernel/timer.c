#include "timer.h"
#include "isr.h"
#include "interrupt.h"
#include "debug.h"

/* This will keep track of how many ticks that the system
*  has been running for */
unsigned long timer_ticks = 0;

/* Handles the timer. In this case, it's very simple: We
*  increment the 'timer_ticks' variable every time the
*  timer fires. By default, the timer fires 18.222 times
*  per second. Why 18.222Hz? Some engineer at IBM must've
*  been smoking something funky */
void timer_handler(__attribute__((unused)) struct isr_regs *r) {
  /* Increment our 'tick count' */
  timer_ticks++;

  if(timer_ticks % 60 == 0) {
    DEBUG("Timer ticks: %ld", timer_ticks);
  }
}

/* This will continuously loop until the given time has
*  been reached */
void timer_wait(int ticks) {
  unsigned long eticks;

  eticks = timer_ticks + ticks;
  while(timer_ticks < eticks);
}

/* Sets up the system clock by installing the timer handler
*  into IRQ0 */
void timer_init() {
  DEBUG_INIT_START();
  /* Installs 'timer_handler' to IRQ0 */
  interrupt_register_handler(0, timer_handler);
  DEBUG_INIT_END();
}
