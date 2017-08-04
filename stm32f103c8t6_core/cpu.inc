CPU_DEF = 0

@ initialize CPU for using
@ function does not take, nor recieve parameters
cpu_init:
	push {r0, r1}
	
	@ set RCC_CFGR register to system clock
	ldr r1, =RCC_CFGR		@ load address of RCC_CFGR registers
	ldr r0, =0x5000000 @ high speed (clock) internal selected (HSI)
	str r0, [r1]			@ store value from r0 to address in r1
	
	pop {r0, r1}
	bx lr
	