CC ?= gcc
AS ?= as
LD ?= ld

ASFLAGS = --32
CFLAGS = -m32 -ffreestanding -O2 -Wall -Wextra

SRC_DIR = src
DST_DIR = dst

KERNEL_DIR = $(DST_DIR)/kernel/
KERNEL_SRC = boot_asm.S system.c screen.c gdt_asm.S gdt.c idt_asm.S idt.c isrs_asm.S isrs.c irq_asm.S irq.c main.c
KERNEL_OBJ = $(addprefix $(KERNEL_DIR),$(subst .c,.o,$(subst .S,.o,$(KERNEL_SRC))))
KERNEL_OUT = $(DST_DIR)/kernel.bin

all: clean $(KERNEL_OUT)

$(KERNEL_OUT): $(KERNEL_DIR) $(KERNEL_OBJ)
	@echo "[ \e[35mBIN\e[0m ] $(KERNEL_OUT)"
	@$(LD) -T src/kernel/link.ld -m elf_i386 -o $(KERNEL_OUT) $(KERNEL_OBJ)

qemu: $(KERNEL_OUT)
	qemu-system-i386 -kernel $(KERNEL_OUT)

# -------------------------------------------------

$(DST_DIR)/%.o: $(SRC_DIR)/%.S
	@echo "[ \e[33mASM\e[0m ] $< -> $@"
	@$(AS) $(ASFLAGS) $< -o $@

$(DST_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "[ \e[34m C \e[0m ] $< -> $@"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

$(DST_DIR)/%:
	@echo "[ \e[36mDIR\e[0m ] $@"
	@mkdir -p $@

clean:
	@echo "[ \e[31m!!!\e[0m ] Clean!"
	@rm -rf $(DST_DIR)
