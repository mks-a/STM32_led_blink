SLEEP_MODES_DEF = 0

.ifndef STM32F103C8T6_REGISTERS
.include "stm32f103c8t6_core/registers.inc"
.endif

@ initialize sleep mode behaviours
sleep_mode_init:
	push {r0, r1}
	@ set SLEEPONEXIT bit in System Control register (if the SLEEPONEXIT bit is set, the MCU enters Sleep mode as soon as it exits the lowest priority ISR)
	
	@ read SCR register value (system control register)
	ldr r1, =SCR
	ldr r0, [r1]
	
	@ set SLEEPONEXIT bit (first bit)
	@orr r0, r0, 0x02					@ NOTE!!! this will break returning from interrupt and because of that Program Counter will be initialized with 0x00 
	
	@ store r0 value to SCR register
	str r0, [r1]
	
	pop {r0, r1}
	bx lr
