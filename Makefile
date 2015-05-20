VERSION := $(shell git rev-parse --short HEAD)

CYAN := "\033[0;36m"
LIGHT_CYAN := "\033[1;36m"
LIGHT_GREEN := "\033[1;32m"
NO_COLOUR := "\033[0m"
WHITE := "\033[1;37m"

ETCDIR := etc
SRCDIR := src
OBJDIR := build
OUTDIR := bin

TARGET := $(OUTDIR)/$(shell basename `pwd`)

CXDIR := /home/baladash/cxcompiler/bin/

TRIPLET := i686-elf

LIBDIR := $(CXDIR)lib/gcc/$(TRIPLET)/4.9.2/

CC := $(CXDIR)$(TRIPLET)-gcc
CXX := $(CXDIR)$(TRIPLET)-g++
LD := $(CXDIR)$(TRIPLET)-ld
AS := $(CXDIR)$(TRIPLET)-as

CFLAGS  := -ffreestanding -nostdlib -std=gnu99 -O2 -Wall -Wextra -Werror=return-type -I$(SRCDIR)/include 
LDFLAGS :=  -L$(LIBDIR) -T $(ETCDIR)/linker.ld -ffreestanding -O2 -nostdlib 
ASFLAGS := 

CFLAGS += -D'VERSION="$(VERSION)"' 

SRCS := $(shell ls $(SRCDIR)/*.c)
ASMS := $(shell ls $(SRCDIR)/*.s)
_OBJS := $(SRCS:.c=.o)
_OBJS += $(ASMS:.s=.o)
OBJS := $(subst $(SRCDIR),$(OBJDIR),$(_OBJS))

all: debug

verbose: CFLAGS += -v
verbose: debug

debug: CFLAGS += -DDEBUG
debug: release

release: directories clean $(OBJS)
	@echo -e $(NO_COLOUR)Linking $(LIGHT_GREEN)$(TARGET).elf$(NO_COLOUR)
	@$(CC) $(LDFLAGS) -o $(TARGET).elf $(OBJS) -lgcc
	@echo -e $(NO_COLOUR)Enjoy your shiny new kernel!$(NO_COLOUR)

$(OBJS): $(SRCS) $(ASMS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo -e $(NO_COLOUR)Building $(CYAN)$@$(NO_COLOUR) from $(CYAN)$<$(NO_COLOUR)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	@echo -e $(NO_COLOUR)Assembling $(CYAN)$@$(NO_COLOUR) from $(CYAN)$<$(NO_COLOUR)
	@$(AS) $(ASFLAGS) -o $@ $<

.PHONY: clean
clean:
	@echo -e Cleaning...
	@rm -rf $(OBJDIR)/*.o $(TARGET).elf

.PHONY: directories
directories:
	if [ ! -d $(OBJDIR) -a ! -d $(OUTDIR) ]; then \
		mkdir -p $(OBJDIR) $(OUTDIR); \
	fi

.PHONY: emu
emu:
	@echo -e $(NO_COLOUR)Emulator starting$(NO_COLOUR)
	@qemu-system-i386 -kernel $(TARGET).elf

.PHONY: iso
iso:
	@cp $(TARGET).elf $(OUTDIR)/grubISO/boot/ && grub-mkrescue -o $(TARGET).iso $(OUTDIR)/grubISO

.PHONY: fullemu
fullemu:
	@qemu-system-i386 -cdrom $(OUTDIR)/$(shell basename `pwd`).iso