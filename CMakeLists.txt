CMAKE_MINIMUM_REQUIRED (VERSION 3.17)

PROJECT (fazos)

SET (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

# Deps

INCLUDE (FetchContent)

FETCHCONTENT_DECLARE (
  printf
  GIT_REPOSITORY "https://github.com/mpaland/printf.git"
  GIT_TAG "v4.0.0"
)

MESSAGE (STATUS "printf downloading ...")
FETCHCONTENT_POPULATE (printf)
MESSAGE (STATUS "printf source dir: ${printf_SOURCE_DIR}")

# Build parts

ADD_SUBDIRECTORY (src/kernel)

# Additional make commands

ADD_CUSTOM_TARGET (qemu
  DEPENDS kernel
  COMMAND qemu-system-i386 -kernel ${EXECUTABLE_OUTPUT_PATH}/kernel -d unimp -serial stdio
  VERBATIM
)

ADD_CUSTOM_TARGET (format
  COMMAND astyle -n --style=google -s2 --recursive ./*.c,*.h --exclude=CMakeFiles
  VERBATIM
)

