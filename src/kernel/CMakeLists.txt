SET (CMAKE_C_FLAGS "-m32 -ffreestanding -O2 -Wall -Wextra")
SET (CMAKE_EXE_LINKER_FLAGS "-T link.ld -m elf_i386 -nostdlib")
SET (CMAKE_C_LINK_EXECUTABLE "<CMAKE_LINKER> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")

IF (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  SET (CMAKE_C_FLAGS "-c -target i386-unknown-unknown-unknown -Wno-unused-command-line-argument ${CMAKE_C_FLAGS}")
  SET (CMAKE_LINKER "ld.lld")
ENDIF ()

FILE (GLOB C_SOURCES "*.c")
FILE (GLOB S_SOURCES "*.s")

SET_PROPERTY (SOURCE ${S_SOURCES} PROPERTY LANGUAGE C)

ADD_EXECUTABLE (kernel
  ${S_SOURCES}
  ${C_SOURCES}
)
