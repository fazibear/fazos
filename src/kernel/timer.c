#include "timer.h"

/* This will keep track of how many ticks that the system
*  has been running for */
unsigned long timer_ticks = 0;

void timer_handler(struct regs *r UNUSED ) {

  /* Increment our 'tick count' */
  timer_ticks++;

  /* Every 18 clocks (approximately 1 second), we will
  *  display a message on the screen */
  if (timer_ticks % 10 == 0) {
    screen_print_string("One second has passed\n");
  }
}

void timer_wait(int ticks) {
  unsigned long eticks;

  eticks = timer_ticks + ticks;
  while(timer_ticks < eticks);
}

/* Sets up the system clock by installing the timer handler
*  into IRQ0 */
void timer_install() {
  /* Installs 'timer_handler' to IRQ0 */
  irq_install_handler(0, timer_handler);
}
