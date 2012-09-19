SRC=div
arm-linux-gnueabi-gcc -mcpu=cortex-m3 -mthumb -O2 -o $SRC.elf $SRC.c
qemu-arm -cpu cortex-m3 -L /usr/arm-linux-gnueabi/ $SRC.elf
