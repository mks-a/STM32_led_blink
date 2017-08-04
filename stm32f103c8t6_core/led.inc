LED_DEF = 0

.text

.ifndef GPIO_DEF
.include "stm32f103c8t6_core/gpio.inc"
.endif

@ this function ititialize port C pin 14 for output
@ function not recieve nor return any parameters
led_init:
	push {r0, r1}
	
	push {lr}
	bl gpio_port_c_rcc_init
	pop {lr}
	
	@ read value from GPIOC_CRH register
	ldr r1, =GPIOC_CRH						@ set register with 32 bit constant (GPIOC_CRH)
	ldr r0, [r1]							@ load value from address on r1 register to r0 register
	@ set bits in r0 register	
	orr r0, r0, 0x2000000		@ for PC14 (set bit 25 (mode 14))	
	and r0, r0, 0xF3FFFFFF		@ for PC14
	
	@ store value from r0 to GPIOC_CRH	
	str r0, [r1]
	
	@ check stored value
	@ldr r0, [r1]
	
	@ breakpoint
	@bkpt
	
	pop {r0, r1}
	
	@ return from function
	bx lr

@ this function set PC14 to high
@ this function does not recieve nor return any parameter
led_light_on:
	push {r0, r1}
	
	@ set address of GPIOC_ODR to r1 register
	ldr r1, =GPIOC_ODR
	
	@ set r0 to led flash on value
	ldr r0, =0x4000
	
	@ store value from r0 to memory location in r1
	str r0, [r1]
	
	ldr r0, [r1]
	
	bkpt
	
	pop {r0, r1}
	@ return from function
	bx lr

@ flash switch PC14 from high to low and from low to high
led_flash:
	push {r0, r1, r2, r3}
	
	@ set address of GPIOC_ODR to r1 register
	ldr r1, =GPIOC_ODR
	
	@ load value from GPIOC_ODR to r0
	ldr r0, [r1]
	
	mov r2, r0
	
	and r2, r2, 0x4000		@ clear all bits in r2 except 14th
	eor r2, r2, 0x4000		@ exclusive or for 14th bit
	
	@ clear 14th bit in r0
	ldr r3, =0xBFFF			
	and r0, r0, r3			@ can't just use here 0xBFFF constant, because compiler gives an error (Invalid constant... after fixup)
	
	@ set all bits from r0 to r2 (except 14th bit, that was cleared)
	orr r2, r2, r0
	
	@ store value from r2 to GPIOC_ODR
	str r2, [r1]
	
	pop {r0, r1, r2, r3}
	bx lr
	