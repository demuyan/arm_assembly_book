SRC=addvalues_asm
arm-linux-gnueabi-gcc -mcpu=arm9 -marm -o $SRC.elf $SRC.c
arm-linux-gnueabi-gcc -mcpu=arm9 -marm -S -o $SRC.S $SRC.c
qemu-arm -L /usr/arm-linux-gnueabi/ $SRC.elf
