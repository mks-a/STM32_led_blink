.thumb
@This turns on Unified Assembly Language which is required to get all the features of Thumb-2.
.syntax unified					@ without this line "orr r0, r0, #0x200000" will give an error "unshifted register required" 
.cpu cortex-m3

.equ STACKINIT, 0x20005000		@ end of SRAM 20kb

.section .text
.org 0x00000000					
SP: .word STACKINIT				@ 20kb of RAM, so I will put stack pointer to the end of it
RESET: .word main
NMI_HANDLER: .word nmi_fault
HARD_FAULT: .word hard_fault
MEMORY_FAULT: .word memory_fault
BUS_FAULT: .word bus_fault
USAGE_FAULT: .word usage_fault
.org 0x000000B0
TIMER2_INTERRUPT: .word timer2_interupt + 1				@ +1 is needed because thumb mode address lsb shoud have 1 

.ifndef LED_DEF
.include "stm32f103c8t6_core/led.inc"
.endif

.ifndef TIMER_DEF
.include "stm32f103c8t6_core/timer.inc"
.endif

@.balign 2 				@ if bit 0 of address is 1 this indicate Thumb state of CPU, for Cortex-M it always should be 1, becaus it not support ARM state
main:
	push {lr}
	bl led_init					@ call led init function
	bl timer2_init
	pop {lr}
	
	push {lr}
	bl timer2_enable
	pop {lr}
	
	cpsie i						@ enable interrupts
	
_main_loop:		
	wfi 						@ wait for interrupt
	
	b _main_loop				@ branch to _main_loop and not load return address to link register (LR)
	@ return from function
	bx lr						@ indirect branch to link register address

nmi_fault:
	@ breakpoint
	bkpt
	bx lr
	
hard_fault:
	@ breakpoint
	bkpt
	bx lr

memory_fault:
	@ breakpoint
	bkpt
	bx lr

bus_fault:
	@ breakpoint
	bkpt
	bx lr

usage_fault:
	@ breakpoint
	bkpt
	bx lr

timer2_interupt:	
	push {lr}
	bl led_flash
	pop {lr}

_timer2_interupt_exit:
	
	@ clear status register (especially interested in clearing bit 0 in status register), after that pending state of interrupt can be cleared
	ldr r1, =TIM2_SR
	ldr r0, =0x00
	str r0, [r1]
	
	push {lr}
	bl timer2_clear_pending
	pop {lr}
	
	bx lr				@ return from ISR (will shitch context back to main programm)

@ this is dummy function that just return from interrupt
returtn_form_interrupt:
	@ breakpoint
	bkpt
	bx lr
	
@.section .bss 					@ block started by symbol
@.offset 0x20000000				@ move bss to the beginning of SRAM (this is done by linkage map file)
@flash_counter: .word			@ bss section holds uninitialized variables
	
.end
	