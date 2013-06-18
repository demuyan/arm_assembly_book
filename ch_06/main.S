	.cpu arm9
	.eabi_attribute 27, 3
	.fpu vfpv3-d16
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 2
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"main.c"
	.section	.text.startup,"ax",%progbits
	.align	2
	.global	main
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, lr}
	mov	r1, #2
	sub	sp, sp, #16
	mov	r0, #1
	bl	add_values
	ldr	r1, .L2
	mov	r2, r0
	mov	r0, #1
	bl	__printf_chk
	mov	ip, #5
	mov	lr, #6
	mov	r3, #4
	mov	r1, #2
	mov	r2, #3
	mov	r0, #1
	stmia	sp, {ip, lr}
	bl	add_values6
	ldr	r1, .L2+4
	mov	r2, r0
	mov	r0, #1
	bl	__printf_chk
	mov	r3, #2
	mov	r4, #1
	strh	r3, [sp, #12]	@ movhi
	add	r0, sp, #8
	mov	r3, #3
	strb	r3, [sp, #14]
	str	r4, [sp, #8]
	bl	sum_struct_values
	ldr	r1, .L2+8
	mov	r2, r0
	mov	r0, r4
	bl	__printf_chk
	mov	r0, #0
	add	sp, sp, #16
	ldmfd	sp!, {r4, lr}
	bx	lr
.L3:
	.align	2
.L2:
	.word	.LC0
	.word	.LC1
	.word	.LC2
	.size	main, .-main
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC0:
	.ascii	"add_values()=%d\012\000"
	.space	3
.LC1:
	.ascii	"add_values6()=%d\012\000"
	.space	2
.LC2:
	.ascii	"sum_struct_values()=%d\012\000"
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",%progbits
