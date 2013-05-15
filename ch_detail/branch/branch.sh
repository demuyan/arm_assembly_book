SRC=branch
arm-linux-gnueabi-gcc -mcpu=arm9 -marm -O2 -o $SRC.elf $SRC.c
qemu-arm -L /usr/arm-linux-gnueabi/ $SRC.elf > $SRC.txt
