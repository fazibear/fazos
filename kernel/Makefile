CC ?= gcc
AS ?= as

ASFLAGS = --32
CFLAGS = -m32 -ffreestanding -O2 -Wall -Wextra

OBJS = boot.o screen.o main.o

OUT = kernel.bin

all: kernel.bin

.S.o:
	@echo "[ \e[33mAS\e[0m ] $<\t-> $@"
	@$(AS) $(ASFLAGS) $< -o $@

.c.o:
	@echo "[ \e[34mCC\e[0m ] $<\t-> $@"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

kernel.bin: $(OBJS)
	@echo "[ \e[35mLD\e[0m ] $(OUT)"
	@ld -T link.ld -m elf_i386 -o $(OUT) $(OBJS)

clean: 
	rm -f $(OBJS) $(OUT)
