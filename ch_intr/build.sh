arm-linux-gnueabi-gcc -mcpu=arm926ej-s -c -marm -o test.o test.c
arm-linux-gnueabi-gcc -mcpu=arm926ej-s -c -o vectors.o vectors.S
arm-linux-gnueabi-gcc -T test.ld -nostdlib -Xlinker --build-id=none test.o vectors.o -o test
arm-linux-gnueabi-objcopy -O binary test test.bin
qemu-system-arm -M versatilepb -nographic -kernel test
