SRC=helloworld
arm-linux-gnueabi-gcc -o $SRC.elf $SRC.c
# arm-none-eabi-gcc -o $SRC.elf $SRC.c
qemu-arm -L /usr/arm-linux-gnueabi/ $SRC.elf
