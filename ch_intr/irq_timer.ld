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
  . = ALIGN(4);
  . = . + 0x1000; /* スタックエリア(ソフト, 4kB) */
  stack_top = .;
  . = . + 0x1000; /* スタックエリア(IRQ, 4kB) */
  irq_stack_top = .;
 }
}