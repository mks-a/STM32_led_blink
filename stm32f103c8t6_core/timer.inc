TIMER_DEF = 0

@ initialize timer 2 for using
timer2_init:
	push {r0, r1}
	
	@ TIM2 timer clock enable
	@ load value from RCC_APB1ENR register
	ldr r1, =RCC_APB1ENR
	ldr r0, [r1]
	
	@ set bit 0 (TIM2 timer clock enable)
	orr r0, r0, 0x01
	
	@ store r0 to RCC_APB1ENR
	str r0, [r1]
	
	@ load value from TIM2_CR1 register
	ldr r1, =TIM2_CR1
	ldr r0, [r1]
	
	@ set timer2 Clock division bits (to 10), Auto-reload preload enable bit, Update request source bit and Counter enable bit
	ldr r0, =0x8D @=0x85 @=0x285
	str r0, [r1]
	
	@ set timer2 prescaler register
	ldr r1, =TIM2_PSC
	ldr r0, =0x10000			@ maximum prescaler value
	str r0, [r1]
	
	@ set auto-reload value to 1 (The counter is blocked while the auto-reload value is null.)
	ldr r1, =TIM2_ARR
	ldr r0, =0xFFFF @=0x01
	str r0, [r1]
	
	@ set trigger interrupt enable bit for timer2
	ldr r1, =TIM2_DIER
	ldr r0, =0x01 @=0x40
	str r0, [r1]	
	
	@ set 28th bit in NVIC_ISER0 register, this should enable TIM2 interrupt
	ldr r1, =NVIC_ISER0
	ldr r0, [r1]
	
	orr r0, r0, 0x10000000
	
	str r0, [r1]
	
	pop {r0, r1}	
	bx lr
