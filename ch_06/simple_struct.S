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
	.file	"simple_struct.c"
	.text
	.align	2
	.global	sum_struct_values
	.type	sum_struct_values, %function
sum_struct_values:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldrsh	r1, [r0, #4]
	ldr	r2, [r0, #0]
	ldrb	r3, [r0, #6]	@ zero_extendqisi2
	add	r0, r1, r2
	add	r0, r0, r3
	bx	lr
	.size	sum_struct_values, .-sum_struct_values
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",%progbits
