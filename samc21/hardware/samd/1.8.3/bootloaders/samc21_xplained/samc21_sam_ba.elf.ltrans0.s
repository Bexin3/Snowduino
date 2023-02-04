	.cpu cortex-m0plus
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 4
	.eabi_attribute 34, 0
	.file	"<artificial>"
	.text
	.align	1
	.global	uart_read_byte
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	uart_read_byte, %function
uart_read_byte:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
.L2:
	ldrb	r3, [r0, #24]
	lsls	r3, r3, #29
	bpl	.L2
	ldrh	r3, [r0, #26]
	lsls	r3, r3, #31
	bmi	.L3
	ldrh	r3, [r0, #26]
	lsls	r3, r3, #30
	bmi	.L3
	ldrh	r3, [r0, #26]
.L3:
	ldrh	r0, [r0, #40]
	@ sp needed
	uxtb	r0, r0
	bx	lr
	.size	uart_read_byte, .-uart_read_byte
	.align	1
	.global	uart_write_byte
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	uart_write_byte, %function
uart_write_byte:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
.L7:
	ldrb	r3, [r0, #24]
	lsls	r3, r3, #31
	bpl	.L7
	uxth	r1, r1
	strh	r1, [r0, #40]
	@ sp needed
	bx	lr
	.size	uart_write_byte, .-uart_write_byte
	.align	1
	.global	uart_disable
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	uart_disable, %function
uart_disable:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
.L11:
	ldr	r3, [r0, #28]
	lsls	r3, r3, #30
	bmi	.L11
	movs	r2, #2
	ldr	r3, [r0]
	@ sp needed
	bics	r3, r2
	str	r3, [r0]
	bx	lr
	.size	uart_disable, .-uart_disable
	.align	1
	.global	uart_basic_init
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	uart_basic_init, %function
uart_basic_init:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, lr}
.L14:
	ldr	r3, [r0, #28]
	lsls	r3, r3, #30
	bmi	.L14
	movs	r4, #2
	ldr	r3, [r0]
	bics	r3, r4
	str	r3, [r0]
.L15:
	ldr	r3, [r0, #28]
	lsls	r3, r3, #31
	bmi	.L15
	movs	r3, #1
	ldr	r4, [r0]
	orrs	r3, r4
	str	r3, [r0]
.L16:
	ldr	r3, [r0]
	lsls	r3, r3, #31
	bmi	.L16
.L17:
	ldr	r3, [r0, #28]
	lsls	r3, r3, #31
	bmi	.L17
	ldr	r3, [r0, #28]
	lsls	r3, r3, #30
	bmi	.L17
	ldr	r3, .L28
	orrs	r2, r3
	str	r2, [r0]
.L19:
	ldr	r3, [r0, #28]
	lsls	r3, r3, #29
	bmi	.L19
	movs	r3, #192
	lsls	r3, r3, #10
	str	r3, [r0, #4]
	strh	r1, [r0, #12]
.L20:
	ldr	r3, [r0, #28]
	lsls	r3, r3, #30
	bmi	.L20
	movs	r3, #2
	ldr	r2, [r0]
	@ sp needed
	orrs	r3, r2
	str	r3, [r0]
	pop	{r4, pc}
.L29:
	.align	2
.L28:
	.word	1073741828
	.size	uart_basic_init, .-uart_basic_init
	.align	1
	.global	LED_pulse
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	LED_pulse, %function
LED_pulse:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r1, .L35
	ldr	r3, .L35+4
	ldrb	r2, [r1]
	cmp	r2, #0
	bne	.L31
	ldrb	r2, [r3]
	ldrb	r0, [r3, #1]
	adds	r2, r2, r0
	movs	r0, #128
	uxtb	r2, r2
	strb	r2, [r3, #1]
	ldr	r2, .L35+8
	lsls	r0, r0, #10
	str	r0, [r2, #28]
.L31:
	ldrb	r2, [r1]
	adds	r2, r2, #1
	uxtb	r2, r2
	strb	r2, [r1]
	ldrb	r2, [r3, #1]
	cmp	r2, #240
	bhi	.L32
	ldrb	r2, [r3, #1]
	cmp	r2, #9
	bhi	.L33
.L32:
	ldrb	r2, [r3]
	rsbs	r2, r2, #0
	sxtb	r2, r2
	strb	r2, [r3]
	ldrb	r2, [r3]
	ldrb	r0, [r3, #1]
	adds	r2, r2, r0
	uxtb	r2, r2
	strb	r2, [r3, #1]
.L33:
	ldrb	r2, [r1]
	ldrb	r3, [r3, #1]
	cmp	r2, r3
	bne	.L30
	movs	r2, #128
	ldr	r3, .L35+8
	lsls	r2, r2, #10
	str	r2, [r3, #28]
.L30:
	@ sp needed
	bx	lr
.L36:
	.align	2
.L35:
	.word	.LANCHOR0
	.word	.LANCHOR1
	.word	1090536448
	.size	LED_pulse, .-LED_pulse
	.data
	.set	.LANCHOR1,. + 0
	.type	ledDirection, %object
	.size	ledDirection, 1
ledDirection:
	.byte	1
	.type	ledTargetValue, %object
	.size	ledTargetValue, 1
ledTargetValue:
	.byte	20
	.bss
	.set	.LANCHOR0,. + 0
	.type	ledKeepValue, %object
	.size	ledKeepValue, 1
ledKeepValue:
	.space	1
	.ident	"GCC: (GNU Tools for Arm Embedded Processors 7-2017-q4-major) 7.2.1 20170904 (release) [ARM/embedded-7-branch revision 255204]"
