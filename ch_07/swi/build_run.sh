arm-linux-gnueabi-gcc -mcpu=arm926ej-s -c -marm -o swi_sample.o swi_sample.c
arm-linux-gnueabi-gcc -mcpu=arm926ej-s -c -o vectors.o vectors.S
arm-linux-gnueabi-gcc -T swi_sample.ld -nostdlib -Xlinker --build-id=none swi_sample.o vectors.o -o swi_sample
arm-linux-gnueabi-objcopy -O binary swi_sample swi_sample.bin
qemu-system-arm -M versatilepb -nographic -kernel swi_sample.bin

# 実行を止めるにはctrl-a x