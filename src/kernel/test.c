#include "test.h"
#include "debug.h"

void test_debug() {
  unsigned long long a = 10;
  unsigned long long b = 23;

  DEBUG("%d %d", a, b);
}
