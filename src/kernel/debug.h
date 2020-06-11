#ifndef _DEBUG_H
#define _DEBUG_H

#include "../../_deps/printf-src/printf.h"

#ifdef DEBUG

#define DEBUG_BLACK "\e[0;30m"
#define DEBUG_RED "\e[0;31m"
#define DEBUG_GREEN "\e[0;32m"
#define DEBUG_YELLOW "\e[0;33m"
#define DEBUG_BLUE "\e[0;34m"
#define DEBUG_MAGENTA "\e[0;35m"
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
    sizeof(s) > 11 && (s)[sizeof(s)-11] == '/' ? (s) + sizeof(s) - 10 : \
    sizeof(s) > 11 && (s)[sizeof(s)-12] == '/' ? (s) + sizeof(s) - 11 : \
    sizeof(s) > 11 && (s)[sizeof(s)-13] == '/' ? (s) + sizeof(s) - 12 : \
    sizeof(s) > 11 && (s)[sizeof(s)-14] == '/' ? (s) + sizeof(s) - 13 : \
    sizeof(s) > 11 && (s)[sizeof(s)-15] == '/' ? (s) + sizeof(s) - 14 : \
    sizeof(s) > 11 && (s)[sizeof(s)-16] == '/' ? (s) + sizeof(s) - 15 : \
    sizeof(s) > 11 && (s)[sizeof(s)-17] == '/' ? (s) + sizeof(s) - 16 : \
    sizeof(s) > 11 && (s)[sizeof(s)-18] == '/' ? (s) + sizeof(s) - 17 : \
    sizeof(s) > 11 && (s)[sizeof(s)-19] == '/' ? (s) + sizeof(s) - 18 : \
    sizeof(s) > 11 && (s)[sizeof(s)-20] == '/' ? (s) + sizeof(s) - 19 : \
    sizeof(s) > 11 && (s)[sizeof(s)-21] == '/' ? (s) + sizeof(s) - 20 : \
    sizeof(s) > 11 && (s)[sizeof(s)-22] == '/' ? (s) + sizeof(s) - 21 : \
    sizeof(s) > 11 && (s)[sizeof(s)-23] == '/' ? (s) + sizeof(s) - 22 : \
    sizeof(s) > 11 && (s)[sizeof(s)-24] == '/' ? (s) + sizeof(s) - 23 : \
    sizeof(s) > 11 && (s)[sizeof(s)-25] == '/' ? (s) + sizeof(s) - 24 : \
    sizeof(s) > 11 && (s)[sizeof(s)-26] == '/' ? (s) + sizeof(s) - 25 : \
    sizeof(s) > 11 && (s)[sizeof(s)-27] == '/' ? (s) + sizeof(s) - 26 : \
    sizeof(s) > 11 && (s)[sizeof(s)-28] == '/' ? (s) + sizeof(s) - 27 : \
    sizeof(s) > 11 && (s)[sizeof(s)-29] == '/' ? (s) + sizeof(s) - 28 : \
    sizeof(s) > 11 && (s)[sizeof(s)-30] == '/' ? (s) + sizeof(s) - 29 : (s))

#define __FILENAME__ STRIPPATH(__FILE__)

#define ERROR(FORMAT, ...) \
    printf(DEBUG_YELLOW"[%15s:%-3d] "DEBUG_BLUE"%s(): "DEBUG_RED FORMAT DEBUG_RESET"\n", \
        __FILENAME__, __LINE__,\
        __func__, \
        ##__VA_ARGS__)

#define INFO(FORMAT, ...) \
    printf(DEBUG_YELLOW"[%15s:%-3d] "DEBUG_BLUE"%s(): "DEBUG_WHITE FORMAT DEBUG_RESET"\n", \
        __FILENAME__, __LINE__,\
        __func__, \
        ##__VA_ARGS__)

#define INIT_START() \
    printf(DEBUG_YELLOW"[%15s:%-3d] "DEBUG_BLUE"%s(): "DEBUG_WHITE "*** INITIALIZING ***" DEBUG_RESET"\n", \
        __FILENAME__, __LINE__,\
        __func__)

#define INIT_END() \
    printf(DEBUG_YELLOW"[%15s:%-3d] "DEBUG_BLUE"%s(): "DEBUG_WHITE "*** INITIALIZED! ***" DEBUG_RESET"\n", \
        __FILENAME__, __LINE__,\
        __func__)

#else

#define ERROR(FORMAT, ...)
#define INFO(FORMAT, ...)
#define INIT_START()
#define INIT_END()

#endif

void debug_init();

#endif
