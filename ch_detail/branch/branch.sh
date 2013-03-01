SRC=branch
arm-linux-gnueabi-gcc -mcpu=cortex-a8 -marm -O2 -o $SRC.elf $SRC.c
qemu-arm -L /usr/arm-linux-gnueabi/ $SRC.elf > $SRC.txt
