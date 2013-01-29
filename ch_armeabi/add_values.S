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
	.file	"add_values.c"
	.text
	.align	2
	.global	add_values2
	.type	add_values2, %function
add_values2:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	add	r0, r1, r0
	bx	lr
	.size	add_values2, .-add_values2
	.align	2
	.global	add_values6
	.type	add_values6, %function
add_values6:
	@ Function supports interworking.
	@ args = 8, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	add	r1, r1, r0
	add	r1, r1, r2
	ldr	r2, [sp, #0]
	add	r1, r1, r3
	add	r0, r1, r2
	ldr	r2, [sp, #4]
	add	r0, r0, r2
	bx	lr
	.size	add_values6, .-add_values6
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",%progbits
