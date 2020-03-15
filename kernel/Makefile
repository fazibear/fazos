CC ?= gcc
ASM ?= as

ASM_FLAGS = --32
OBJS = boot.o screen.o main.o

CFLAGS = -m32 -ffreestanding -O2 -Wall -Wextra

OUT = kernel.bin

all: kernel.bin

kernel.bin: $(OBJS)
	@echo "LINK $(OUT)"
	@ld -T link.ld -m elf_i386 -o $(OUT) $(OBJS) -nostdlib

.S.o:
	@echo " AS  $@"
	@$(ASM) $(ASM_FLAGS) $< -o $@

.c.o:
	@echo " CC  $@"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@
clean: 
	rm -f $(OBJS) $(OUT)
