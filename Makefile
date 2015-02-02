#----------------------------------------------------------------------------
# Makefile for USB-n1nja
#
# written by:
#   dot_Cipher
#----------------------------------------------------------------------------
# avr-gcc -g -Os -mmcu=atmega8 -c flash.c
# avr-gcc -g -mmcu=atmega8 -o flash.elf flash.o
# avr-objcopy -j .text -j .data -O ihex flash.elf flash.hex

# --------------- VALUE DEFINITIONS ---------------

TARGET = usb-n1nja
SRC = $(TARGET).c \
	usb_debug_only.c \
	print.c

SHELL = bash
CC = avr-gcc
OBJCOPY = avr-objcopy
SIZE = avr-size
COPY = cp
WINSHELL = cmd

MCU = atmega32u4
F_CPU = 16000000

FORMAT = ihex
OBJDIR = .

OPT = s
DEBUG = dwarf-2
CSTANDARD = -std=gnu99
CDEFS = -DF_CPU=$(F_CPU)UL

CFLAGS = -g$(DEBUG)
CFLAGS += $(CDEFS)
CFLAGS += -O$(OPT)
CFLAGS += -funsigned-char
CFLAGS += -funsigned-bitfields
CFLAGS += -ffunction-sections
CFLAGS += -fpack-struct
CFLAGS += -fshort-enums
CFLAGS += -Wall
CFLAGS += -Wstrict-prototypes
CFLAGS += $(CSTANDARD)
CFLAGS += -mmcu=$(MCU)

# Define Messages
MSG_ERRORS_NONE = Errors: none
MSG_BEGIN = -------- begin --------
MSG_END = --------  end  --------
MSG_SIZE_BEFORE = Size before: 
MSG_SIZE_AFTER = Size after:
MSG_LINKING = Linking:
MSG_COMPILING = Compiling C:
MSG_CLEANING = Cleaning project:

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)
HEXSIZE = $(SIZE) --target=$(FORMAT) $(TARGET).hex


# --------------- RULE DEFINITIONS ---------------

all: begin gccversion sizebefore build sizeafter end

#build: hex elf
build: hex

hex: $(TARGET).hex
elf: $(TARGET).elf

begin:
	echo; echo $(MSG_BEGIN)

gccversion:
	$(CC) --version

sizebefore:
	@if test -f $(TARGET).hex; then echo; echo $(MSG_SIZE_BEFORE); \
	$(HEXSIZE); 2>/dev/null; echo; fi

sizeafter:
	@if test -f $(TARGET).hex; then echo; echo $(MSG_SIZE_AFTER); \
		$(HEXSIZE); 2>/dev/null; echo; fi

end:
	echo $(MSG_END); echo 

