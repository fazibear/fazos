#ifndef _DEBUG_H
#define _DEBUG_H

//Regular text
#define DEBUG_BLACK "\e[0;30m"
#define DEBUG_RED "\e[0;31m"
#define DEBUG_GREEN "\e[0;32m"
#define DEBUG_YELLOW "\e[0;33m"
#define DEBUG_BLUE "\e[0;34m"
#define DEBUG_MAGENYA "\e[0;35m"
#define DEBUG_CYAN "\e[0;36m"
#define DEBUG_WHITE "\e[0;37m"
#define DEBUG_RESET "\e[0m"

#define STRIPPATH(s)\
    (sizeof(s) > 2 && (s)[sizeof(s)-2] == '/' ? (s) + sizeof(s) - 1 : \
    sizeof(s) > 3 && (s)[sizeof(s)-3] == '/' ? (s) + sizeof(s) - 2 : \
    sizeof(s) > 4 && (s)[sizeof(s)-4] == '/' ? (s) + sizeof(s) - 3 : \
    sizeof(s) > 5 && (s)[sizeof(s)-5] == '/' ? (s) + sizeof(s) - 4 : \
    sizeof(s) > 6 && (s)[sizeof(s)-6] == '/' ? (s) + sizeof(s) - 5 : \
    sizeof(s) > 7 && (s)[sizeof(s)-7] == '/' ? (s) + sizeof(s) - 6 : \
    sizeof(s) > 8 && (s)[sizeof(s)-8] == '/' ? (s) + sizeof(s) - 7 : \
    sizeof(s) > 9 && (s)[sizeof(s)-9] == '/' ? (s) + sizeof(s) - 8 : \
    sizeof(s) > 10 && (s)[sizeof(s)-10] == '/' ? (s) + sizeof(s) - 9 : \
    sizeof(s) > 11 && (s)[sizeof(s)-11] == '/' ? (s) + sizeof(s) - 10 : (s))

#define __FILENAME__ STRIPPATH(__FILE__)

// vga_printf("%s() in %s: " FORMAT "\n", __func__, __FILENAME__, __VA_ARGS__)

#define DEBUG(FORMAT, ...) \
    debug_printf("%s[%15s:%-3d] %s%s(): %s" FORMAT "%s\n",\
        DEBUG_YELLOW, __FILENAME__, __LINE__,\
        DEBUG_BLUE, __func__, \
        DEBUG_WHITE, __VA_ARGS__, \
        DEBUG_RESET)

int debug_printf(const char *format, ...);
int debug_sprintf(char *out, const char *format, ...);

#endif
