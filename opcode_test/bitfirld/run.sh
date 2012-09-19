SRC=bitfield
arm-linux-gnueabi-gcc -mcpu=cortex-a8 -O2 -mthumb -o $SRC.elf $SRC.c
qemu-arm -L /usr/arm-linux-gnueabi/ $SRC.elf
