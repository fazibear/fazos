CC ?= gcc
AS ?= as

ASFLAGS = --32
CFLAGS = -m32 -ffreestanding -O2 -Wall -Wextra

OBJS = boot.o screen.o main.o

OUT = kernel.bin

all: kernel.bin

.S.o:
	@echo "[ AS ] $<\t-> $@"
	@$(AS) $(ASFLAGS) $< -o $@

.c.o:
	@echo "[ CC ] $<\t-> $@"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

kernel.bin: $(OBJS)
	@echo "[ LD ] $(OUT)"
	@ld -T link.ld -m elf_i386 -o $(OUT) $(OBJS)

clean: 
	rm -f $(OBJS) $(OUT)
