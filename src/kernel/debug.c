#include "debug.h"
#include "serial.h"

static void debug_print_char(char **str, int c);
static int debug_prints(char **out, const char *string, int width, int pad);
static int debug_printi(char **out, int i, int b, int sg, int width, int pad, int letbase);
static int debug_print(char **out, int *varg);

void debug_init() {
  serial_init(SERIAL_COM1);
  serial_write_string(SERIAL_COM1, "DEBUG INITIALIZED !");
}

int debug_printf(const char *format, ...) {
  register int *varg = (int *)(&format);
  return debug_print(0, varg);
}

int debug_sprintf(char *out, const char *format, ...) {
  register int *varg = (int *)(&format);
  return debug_print(&out, varg);
}

static void debug_print_char(char **str, int c) {
  if (str) {
    **str = c;
    ++(*str);
  } else (void)serial_write_char(SERIAL_COM1, c);
}

/*
    Copyright 2001 Georges Menie
    https://www.menie.org/georges/embedded/small_printf_source_code.html

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#define PAD_RIGHT 1
#define PAD_ZERO 2

static int debug_prints(char **out, const char *string, int width, int pad) {
  register int pc = 0, padchar = ' ';

  if (width > 0) {
    register int len = 0;
    register const char *ptr;
    for (ptr = string; *ptr; ++ptr) ++len;
    if (len >= width) width = 0;
    else width -= len;
    if (pad & PAD_ZERO) padchar = '0';
  }
  if (!(pad & PAD_RIGHT)) {
    for ( ; width > 0; --width) {
      debug_print_char (out, padchar);
      ++pc;
    }
  }
  for ( ; *string ; ++string) {
    debug_print_char (out, *string);
    ++pc;
  }
  for ( ; width > 0; --width) {
    debug_print_char (out, padchar);
    ++pc;
  }

  return pc;
}

/* the following should be enough for 32 bit int */
#define PRINT_BUF_LEN 12

static int debug_printi(char **out, int i, int b, int sg, int width, int pad, int letbase) {
  char print_buf[PRINT_BUF_LEN];
  register char *s;
  register int t, neg = 0, pc = 0;
  register unsigned int u = i;

  if (i == 0) {
    print_buf[0] = '0';
    print_buf[1] = '\0';
    return debug_prints (out, print_buf, width, pad);
  }

  if (sg && b == 10 && i < 0) {
    neg = 1;
    u = -i;
  }

  s = print_buf + PRINT_BUF_LEN-1;
  *s = '\0';

  while (u) {
    t = u % b;
    if( t >= 10 )
      t += letbase - '0' - 10;
    *--s = t + '0';
    u /= b;
  }

  if (neg) {
    if( width && (pad & PAD_ZERO) ) {
      debug_print_char (out, '-');
      ++pc;
      --width;
    } else {
      *--s = '-';
    }
  }

  return pc + debug_prints (out, s, width, pad);

}
static int debug_print(char **out, int *varg) {
  register int width, pad;
  register int pc = 0;
  register char *format = (char *)(*varg++);
  char scr[2];

  for (; *format != 0; ++format) {
    if (*format == '%') {
      ++format;
      width = pad = 0;
      if (*format == '\0') break;
      if (*format == '%') goto out;
      if (*format == '-') {
        ++format;
        pad = PAD_RIGHT;
      }
      while (*format == '0') {
        ++format;
        pad |= PAD_ZERO;
      }
      for ( ; *format >= '0' && *format <= '9'; ++format) {
        width *= 10;
        width += *format - '0';
      }
      if( *format == 's' ) {
        register char *s = *((char **)varg++);
        pc += debug_prints (out, s?s:"(null)", width, pad);
        continue;
      }
      if( *format == 'd' ) {
        pc += debug_printi (out, *varg++, 10, 1, width, pad, 'a');
        continue;
      }
      if( *format == 'x' ) {
        pc += debug_printi (out, *varg++, 16, 0, width, pad, 'a');
        continue;
      }
      if( *format == 'X' ) {
        pc += debug_printi (out, *varg++, 16, 0, width, pad, 'A');
        continue;
      }
      if( *format == 'u' ) {
        pc += debug_printi (out, *varg++, 10, 0, width, pad, 'a');
        continue;
      }
      if( *format == 'c' ) {
        /* char are converted to int then pushed on the stack */
        scr[0] = *varg++;
        scr[1] = '\0';
        pc += debug_prints (out, scr, width, pad);
        continue;
      }
    } else {
out:
      debug_print_char (out, *format);
      ++pc;
    }
  }
  if (out) **out = '\0';
  return pc;
}
