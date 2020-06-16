CMAKE_MINIMUM_REQUIRED (VERSION 3.17)

PROJECT (fazos)

SET (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

INCLUDE (FetchContent)

FETCHCONTENT_DECLARE (
  printf
  GIT_REPOSITORY "https://github.com/mpaland/printf.git"
  GIT_TAG "v4.0.0"
)

MESSAGE (STATUS "printf downloading ...")
FETCHCONTENT_POPULATE (printf)
MESSAGE (STATUS "printf source dir: ${printf_SOURCE_DIR}")

SET (CMAKE_BUILD_TYPE Debug)

ADD_SUBDIRECTORY (iso)
ADD_SUBDIRECTORY (src/kernel)

SET (QEMU_ARGS -d unimp -serial stdio)
SET (GDB_ARGS -se ${KERNEL_BIN} -ex "target remote :1234")

ADD_CUSTOM_TARGET (qemu
  DEPENDS kernel
  COMMAND qemu-system-i386 -kernel ${KERNEL_BIN} ${QEMU_ARGS}
  VERBATIM
)

ADD_CUSTOM_TARGET (qemug
  DEPENDS iso
  COMMAND qemu-system-x86_64 -drive file=${ISO_IMG},format=raw,index=0,media=disk ${QEMU_ARGS}
  VERBATIM
)

ADD_CUSTOM_TARGET (qemud
  DEPENDS kernel
  COMMAND qemu-system-i386 -s -S -kernel ${KERNEL_BIN} ${QEMU_ARGS}
  VERBATIM
)

ADD_CUSTOM_TARGET (gdb
  DEPENDS kernel
  COMMAND gdb ${GDB_ARGS}
  VERBATIM
)

ADD_CUSTOM_TARGET (gdbgui
  DEPENDS kernel
  COMMAND gdbgui --gdb-args '${GDB_ARGS}'
)

ADD_CUSTOM_TARGET (format
  COMMAND astyle -n --style=google -s2 --recursive ./*.c,*.h --exclude=CMakeFiles
  VERBATIM
)
