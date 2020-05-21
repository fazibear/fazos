CMAKE_MINIMUM_REQUIRED (VERSION 3.17)

PROJECT (fazos)

SET (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

ADD_SUBDIRECTORY (src/kernel)

add_custom_target("qemu" COMMAND
  qemu-system-i386
  -kernel ${EXECUTABLE_OUTPUT_PATH}/kernel
  VERBATIM
)

add_custom_target("format" COMMAND
  astyle
  -n
  --style=google
  -s2
  --recursive ./*.c,*.h
  --exclude=CMakeFiles
  VERBATIM
)
