SRC_C=main 
SRC_FUNC=add_values
SRC_STRUCT=simple_struct

arm-linux-gnueabi-gcc -mcpu=arm9 -marm -O2 -c -o $SRC_C.o $SRC_C.c
arm-linux-gnueabi-gcc -mcpu=arm9 -marm -O2 -c -o $SRC_FUNC.o $SRC_FUNC.c
arm-linux-gnueabi-gcc -mcpu=arm9 -marm -O2 -c -o $SRC_STRUCT.o $SRC_STRUCT.c

arm-linux-gnueabi-gcc -mcpu=arm9 -marm -O2 -S -c -o $SRC_C.S $SRC_C.c
arm-linux-gnueabi-gcc -mcpu=arm9 -marm -O2 -S -c -o $SRC_FUNC.S $SRC_FUNC.c
arm-linux-gnueabi-gcc -mcpu=arm9 -marm -O2 -S -c -o $SRC_STRUCT.S $SRC_STRUCT.c

arm-linux-gnueabi-gcc -o $SRC_C.elf $SRC_C.o $SRC_FUNC.o $SRC_STRUCT.o
qemu-arm -L /usr/arm-linux-gnueabi/ $SRC_C.elf
