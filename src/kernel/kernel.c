int main() {
  char *str = "Hello, world", *ch;
  unsigned short *vidmem = (unsigned short*) 0xb8000;
  unsigned i;

  for (ch = str, i = 0; *ch; ch++, i++)
    vidmem[i] = (unsigned char) *ch | 0x1200;

  for (;;)
    ;
}
