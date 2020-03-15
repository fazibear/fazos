CC ?= gcc
ASM ?= as

ASM_FLAGS = --32
OBJS = boot.o main.o

CFLAGS = -m32 -ffreestanding -O2 -Wall -Wextra

OUT = kernel.bin

all: kernel.bin

kernel.bin: $(OBJS)
	ld -T link.ld -m elf_i386 -o $(OUT) $(OBJS) -nostdlib

boot.o: boot.S
	$(ASM) $(ASM_FLAGS) $< -o $@

clean: 
	rm -f $(OBJS) $(OUT)
