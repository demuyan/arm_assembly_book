arm-none-eabi-gcc -c -mcpu=arm926ej-s test.c -o test.o
arm-none-eabi-as -mcpu=arm926ej-s startup.s -o startup.o
arm-none-eabi-ld -T test.ld test.o startup.o -o test.elf
arm-none-eabi-objcopy -O binary test.elf test.bin
qemu-system-arm -M versatilepb -m 128M -kernel test.bin -serial pty -serial pty
