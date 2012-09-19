SRC=multiply
arm-linux-gnueabi-gcc -mcpu=cortex-a8 -O2 -marm -o $SRC.elf $SRC.c
qemu-arm -cpu cortex-a8 -L /usr/arm-linux-gnueabi/ $SRC.elf
