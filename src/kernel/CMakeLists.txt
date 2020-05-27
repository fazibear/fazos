SET (CMAKE_C_FLAGS "-m32 -nostdlib -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -ffreestanding -O2 -mno-sse")
SET (CMAKE_EXE_LINKER_FLAGS "-T link.ld -m elf_i386")
SET (CMAKE_C_LINK_EXECUTABLE "<CMAKE_LINKER> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")

IF (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  SET (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -c -target i386-unknown-unknown-unknown -Wno-unused-command-line-argument")
  SET (CMAKE_LINKER "ld.lld")
ENDIF ()

SET (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DPRINTF_DISABLE_SUPPORT_LONG_LONG")

FILE (GLOB C_SOURCES "*.c")
FILE (GLOB S_SOURCES "*.s")

SET (C_SOURCES "${C_SOURCES};${printf_SOURCE_DIR}/printf.c")

SET_PROPERTY (SOURCE ${S_SOURCES} PROPERTY LANGUAGE C)

ADD_EXECUTABLE (kernel ${S_SOURCES} ${C_SOURCES})
