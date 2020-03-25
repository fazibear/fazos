CC ?= gcc
AS ?= as

ASFLAGS = --32
CFLAGS = -m32 -ffreestanding -O2 -Wall -Wextra

OBJS = boot.o screen.o gdt.o main.o

OUT = kernel.bin

BUILD_DIR = build/

all: clean kernel.bin

.S.o:
	@echo "[ \e[33mAS\e[0m ] $< -> $@"
	@$(AS) $(ASFLAGS) $< -o $@

.c.o:
	@echo "[ \e[34mCC\e[0m ] $< -> $@"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

kernel.bin: $(OBJS)
	@echo "[ \e[35mLD\e[0m ] $(OUT)"
	@ld -T link.ld -m elf_i386 -o $(OUT) $(OBJS)

clean: 
	rm -f $(OBJS) $(OUT)
