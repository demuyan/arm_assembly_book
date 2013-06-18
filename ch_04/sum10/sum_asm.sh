SRC=sum_asm
arm-linux-gnueabi-gcc -mcpu=arm9 -marm -o $SRC.elf $SRC.c
qemu-arm -L /usr/arm-linux-gnueabi/ $SRC.elf
