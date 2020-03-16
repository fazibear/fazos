CC ?= gcc
ASM ?= as

ASM_FLAGS = --32
OBJS = boot.o screen.o main.o

CFLAGS = -m32 -ffreestanding -O2 -Wall -Wextra

OUT = kernel.bin

all: kernel.bin

kernel.bin: $(OBJS)
	@echo "LINK ->\t$(OUT)"
	@ld -T link.ld -m elf_i386 -o $(OUT) $(OBJS)

.S.o:
	@echo " AS  $<\t->\t$@"
	@$(ASM) $(ASM_FLAGS) $< -o $@

.c.o:
	@echo " CC  $<\t->\t$@"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean: 
	rm -f $(OBJS) $(OUT)
