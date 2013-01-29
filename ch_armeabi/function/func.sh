SRC_C=main
SRC_FUNC=func
arm-linux-gnueabi-gcc -c -o $SRC_FUNC.o $SRC_FUNC.c
arm-linux-gnueabi-gcc -mcpu=cortex-a8 -marm -O2 -c -o $SRC_C.o $SRC_C.c
arm-linux-gnueabi-gcc -o $SRC_C.elf $SRC_C.o $SRC_FUNC.o
qemu-arm -L /usr/arm-linux-gnueabi/ $SRC_C.elf
