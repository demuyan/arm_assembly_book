arm-linux-gnueabi-gcc -mcpu=arm926ej-s -c -marm -o irq_timer.o irq_timer.c
arm-linux-gnueabi-gcc -mcpu=arm926ej-s -c -o vectors.o vectors.S
arm-linux-gnueabi-gcc -T irq_timer.ld -nostdlib -Xlinker --build-id=none irq_timer.o vectors.o -o irq_timer
arm-linux-gnueabi-objcopy -O binary irq_timer irq_timer.bin
qemu-system-arm -M versatilepb -nographic -kernel irq_timer.bin

# 実行を止めるにはctrl-a x