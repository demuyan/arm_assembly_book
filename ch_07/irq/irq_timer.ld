ENTRY(vectors_start)
SECTIONS
{
 . = 0x10000;
 .text : {
 vectors.o
 *(.text .rodata)
 }
 .data : { *(.data) }
 .bss : { *(.bss) }
 .stack : {
  . = . + 0x1000; /* スタックエリア(スーパバイザ, 4kB) */
  . = ALIGN(4);
  stack_top = .;
  . = . + 0x1000; /* スタックエリア(IRQ, 4kB) */
  . = ALIGN(4);
  irq_stack_top = .;
 }
}