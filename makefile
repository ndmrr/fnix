
override KERNEL := kernel_fnix.elf
 
ifeq ($(origin CC), default)
CC := cc
endif
ASMC := nasm

ifeq ($(origin LD), default)
LD := ld
endif
 

CFLAGS ?= -O2 -g -Wall -Wextra -pipe

ASMFLAGS ?= 
 

LDFLAGS ?=
 

override INTERNALCFLAGS :=   \
	-I.                  \
	-std=gnu11           \
	-ffreestanding       \
	-fno-stack-protector \
	-fno-pic             \
	-mabi=sysv           \
	-mno-80387           \
	-mno-mmx             \
	-mno-3dnow           \
	-mno-sse             \
	-mno-sse2            \
	-mno-red-zone        \
	-mcmodel=kernel      \
	-MMD
 
override INTERNALLDFLAGS :=    \
	-Tlinker.ld            \
	-nostdlib              \
	-zmax-page-size=0x1000 \
	-static
 

CFILES := $(shell find ./ -type f -name '*.c')
ASMFILES := $(shell find ./ -type f -name '*.asm')

OBJ := $(CFILES:.c=.o)
OBJ += $(ASMFILES:.asm=.asm_o)

.PHONY: all
all: $(KERNEL)
 

$(KERNEL): $(OBJ)
	$(LD) $(OBJ) $(LDFLAGS) $(INTERNALLDFLAGS) -o $@
 

%.o: %.c
	$(CC) $(CFLAGS) $(INTERNALCFLAGS) -Ikernel/ -c $< -o $@
 

%.asm_o: %.asm
	$(ASMC) $(ASMFLAGS) $^ -f elf64 -o $@
 

.PHONY: clean
clean:
	rm -rf $(KERNEL) $(OBJ) $(HEADER_DEPS)
