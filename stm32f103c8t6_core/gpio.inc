GPIO_DEF = 0

.ifndef STM32F103C8T6_REGISTERS
.include "stm32f103c8t6_core/registers.inc"
.endif

@ this function initialize rcc registers for using gpio pins on port C
@ function does not ake nor recieve parameters
gpio_port_c_rcc_init:
	push {r0, r1}
	
	ldr r0, =0x10			@ set bit 4 in r0 register
	@ Note!!! should not reset port C on RCC_APB2RSTR register
	
	@ set RCC_APB2ENR register values for using port C
	ldr r1, =RCC_APB2ENR
	str r0, [r1]
	
	pop {r0, r1}
	bx lr
