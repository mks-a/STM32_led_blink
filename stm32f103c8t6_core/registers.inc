STM32F103C8T6_REGISTERS = 0 

.ifndef STM32F103C8T6_PORT_CODES
.include "stm32f103c8t6_core/memory_mapping.inc"
.endif

@ nested vector interrupt controller registers
.equ NVIC_ICTR, 0xE000E004			@ Interrupt Controller Type Register (Read Only register)
@ Interrupt Set-Enable Registers
.equ NVIC_ISER0, 0xE000E100			
.equ NVIC_ISER1, 0xE000E104
.equ NVIC_ISER2, 0xE000E108
.equ NVIC_ISER3, 0xE000E10C
.equ NVIC_ISER4, 0xE000E110
.equ NVIC_ISER5, 0xE000E114
.equ NVIC_ISER6, 0xE000E118
.equ NVIC_ISER7, 0xE000E11C
@ Interrupt Clear-Enable Registers (Clearing an Interrupt Set-Enable Register bit does not affect currently active interrupts. It only prevents new activations.)
.equ NVIC_ICER0, 0xE000E180
.equ NVIC_ICER1, 0xE000E184
.equ NVIC_ICER2, 0xE000E188
.equ NVIC_ICER3, 0xE000E18C
.equ NVIC_ICER4, 0xE000E190
.equ NVIC_ICER5, 0xE000E194
.equ NVIC_ICER6, 0xE000E198
.equ NVIC_ICER7, 0xE000E19C
@ Interrupt Set-Pending Registers
.equ NVIC_ISPR0, 0xE000E200
.equ NVIC_ISPR1, 0xE000E204
.equ NVIC_ISPR2, 0xE000E208
.equ NVIC_ISPR3, 0xE000E20C
.equ NVIC_ISPR4, 0xE000E210
.equ NVIC_ISPR5, 0xE000E214
.equ NVIC_ISPR6, 0xE000E218
.equ NVIC_ISPR7, 0xE000E21C
@ Interrupt Clear-Pending Registers
.equ NVIC_ICPR0, 0xE000E280
.equ NVIC_ICPR1, 0xE000E284
.equ NVIC_ICPR2, 0xE000E288
.equ NVIC_ICPR3, 0xE000E28C
.equ NVIC_ICPR4, 0xE000E290
.equ NVIC_ICPR5, 0xE000E294
.equ NVIC_ICPR6, 0xE000E298
.equ NVIC_ICPR7, 0xE000E29C
@ Interrupt Active Bit Registers (read only)
.equ NVIC_IABR0, 0xE000E300
.equ NVIC_IABR1, 0xE000E304
.equ NVIC_IABR2, 0xE000E308
.equ NVIC_IABR3, 0xE000E30C
.equ NVIC_IABR4, 0xE000E310
.equ NVIC_IABR5, 0xE000E314
.equ NVIC_IABR6, 0xE000E318
.equ NVIC_IABR7, 0xE000E31C
@ Interrupt Priority Registers
.equ NVIC_IPR0, 0xE000E400
.equ NVIC_IPR1, 0xE000E404
.equ NVIC_IPR2, 0xE000E408
.equ NVIC_IPR3, 0xE000E40C
.equ NVIC_IPR4, 0xE000E410
.equ NVIC_IPR5, 0xE000E414
.equ NVIC_IPR6, 0xE000E418
.equ NVIC_IPR7, 0xE000E41C

@ system registers
.equ SCR, 0xE000ED10				@ system control register

@ timer2 registers
.equ TIM2_CR1, TIM2 + 0x00			@ timer2 control register 1
.equ TIM2_CR2, TIM2 + 0x04			@ timer2 control register 2
.equ TIM2_SMCR, TIM2 + 0x08			@ timer2 slave mode control register
.equ TIM2_DIER, TIM2 + 0x0C			@ timer2 DMA (direct memory access)/Interrupt enable register
.equ TIM2_SR, TIM2 + 0x10			@ timer2 status register
.equ TIM2_EGR, TIM2 + 0x14			@ timer2 event generation register
.equ TIM2_CCMR1, TIM2 + 0x18		@ timer2 capture/compare mode register 1
.equ TIM2_CCMR2, TIM2 + 0x1C		@ timer2 capture/compare mode register 2
.equ TIM2_CCER, TIM2 + 0x20			@ timer2 capture/compare enable register
.equ TIM2_CNT, TIM2 + 0x24			@ timer2 counter register
.equ TIM2_PSC, TIM2 + 0x28			@ timer2 prescaler register
.equ TIM2_ARR, TIM2 + 0x2C			@ timer2 auto-reload register	
.equ TIM2_CCR1, TIM2 + 0x34			@ timer2 capture/compare register 1
.equ TIM2_CCR2, TIM2 + 0x38			@ timer2 capture/compare register 2
.equ TIM2_CCR3, TIM2 + 0x3C			@ timer2 capture/compare register 3
.equ TIM2_CCR4, TIM2 + 0x40			@ timer2 capture/compare register 4
.equ TIM2_DCR, TIM2 + 0x48			@ timer2 DMA (direct memory access) control register
.equ TIM2_DMAR, TIM2 + 0x4C			@ timer2 DMA (direct memory access) address for full transfer

@ reset and clock cotrol registers
.equ RCC_CR, RCC + 0x00				@ clock control register
.equ RCC_CFGR, RCC + 0x04			@ clock configuration register
.equ RCC_CIR, RCC + 0x08			@ clock interrupt register
.equ RCC_APB2RSTR, RCC + 0x0C		@ APB2 peripherial reset register (APB - advanced peripherial bus)
.equ RCC_APB1RSTR, RCC + 0x10		@ APB1 peripherial reset register
.equ RCC_AHBENR, RCC + 0x14			@ AHB peripherial clock enable register (AHB - advanced high performance bus)
.equ RCC_APB2ENR, RCC + 0x18		@ APB2 peripherial clock enable register
.equ RCC_APB1ENR, RCC + 0x1C		@ APB1 peripherial clock enable register
.equ RCC_BDCR, RCC + 0x20			@ backup domain control register	
.equ RCC_CSR, RCC + 0x24			@ control/status register

@ GPIO port C registers
.equ GPIOC_CRL, PORT_C				@ port C control register low
.equ GPIOC_CRH, PORT_C + 0x04		@ port C control register high
.equ GPIOC_IDR, PORT_C + 0x08		@ port C input data register
.equ GPIOC_ODR, PORT_C + 0x0C		@ port C output data register
.equ GPIOC_BSRR, PORT_C + 0x10		@ port C bit set/reset register
.equ GPIOC_BRR, PORT_C + 0x14		@ port C bit reset register (16 bit)
.equ GPIOC_LCKR, PORT_C + 0x18		@ port C configuration lock register
