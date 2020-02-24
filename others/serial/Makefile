SERIALDEV	 = /dev/ttyS0
CLOCKFREQ	 = 12000
TARGET		 = arm02
MODULOS		 = main.o fpp.o i2c.o crt.o
TERMINAL	 = ltser
BAUDRATE	 = 19200

CC		 = arm-elf-gcc
LD		 = arm-elf-gcc
AS		 = arm-elf-as
AFLAGS		 = -mapcs-32 -mcpu=arm7tdmi
CFLAGS		 = -Wall -Os -mcpu=arm7tdmi-s -D BAUDRATE=${BAUDRATE}
CFLAGS		+= -Wstrict-prototypes -Wmissing-prototypes
CFLAGS		+= -Wshadow -Wmissing-declarations -Wpointer-arith
CFLAGS		+= -Wcast-qual -Wsign-compare
LFLAGS		 = -nostartfiles

all: ${TARGET}.hex

%.hex: %.elf
	arm-elf-objcopy -O ihex $< $@

%.o: %.c
	${CC} $(CFLAGS) -c -o $@ $<

%.o: %.S
	${AS} ${AFLAGS} -o $@ $<

${TARGET}.elf: ${MODULOS}
	${LD} ${LFLAGS} -Tlpc2378_flash.ld -o ${TARGET}.elf ${MODULOS}

${TARGET}r.elf: ${MODULOS}
	${LD} ${LFLAGS} -Tlpc2378_ram.ld -o ${TARGET}r.elf ${MODULOS}

# Program ram
tser: ${TARGET}r.hex
	${TERMINAL} ${SERIALDEV} b=${BAUDRATE} ${TARGET}r.hex

# Program flash
isp: ${TARGET}.hex
	lpc21isp ${TARGET}.hex ${SERIALDEV} ${BAUDRATE} ${CLOCKFREQ}

clean:
	rm -vf *.o *.elf *~ *.bin *.map *.hex cscope*
