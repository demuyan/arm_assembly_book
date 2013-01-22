 .text
 .code 32

        .global vectors_start
        .global vectors_end
        
vectors_start:
 LDR PC, reset_handler_addr
 LDR PC, undef_handler_addr
 LDR PC, swi_handler_addr
 LDR PC, prefetch_abort_handler_addr
 LDR PC, data_abort_handler_addr
 B .
 LDR PC, irq_handler_addr
 LDR PC, fiq_handler_addr

reset_handler_addr: .word reset_handler
undef_handler_addr: .word halt
swi_handler_addr: .word halt
prefetch_abort_handler_addr: .word halt
data_abort_handler_addr: .word halt
irq_handler_addr: .word irq_handler
fiq_handler_addr: .word 
vectors_end:

halt:   b .
        
reset_handler:
 /* set Supervisor stack */
 LDR sp, =stack_top
 /* copy vector table to address 0 */
/*  BL copy_vectors */

        mov r0, #0x00
	    ldr r1, =vectors_start
	    ldr r3, =vectors_end
keep_loading:
	    ldr r2, [r1, #0x0]
	    str r2, [r0, #0x0]
	    add r0, r0, #0x4
	    add r1, r1, #0x4
	    cmp r1, r3
	    bne keep_loading


 /* get Program Status Register */
 MRS r0, cpsr
 /* go in IRQ mode */
 BIC r1, r0, #0x1F
 ORR r1, r1, #0x12
 MSR cpsr, r1
 /* set IRQ stack */
 LDR sp, =irq_stack_top
 /* Enable IRQs */
/* BIC r0, r0, #0x80 */
 /* go back in Supervisor mode */
/* MSR cpsr, r0 */
 /* jump to main */
 BL main
 B .

        .globl enable_irq
enable_irq:
        mrs r0,cpsr
        bic r0,r0,#0x80
        msr cpsr_c,r0
        bx lr

.end