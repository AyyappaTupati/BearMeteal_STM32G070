//This file is containing the default register configurations
//Memory mapped registers are defined here with their respected address

/*
 * Below are the common bit manipulation techniques
 * but they play vital role
 *  */

#define SET_BIT(REG,BIT)     REG = (REG | (1<<BIT))
#define TGL_BIT(REG,BIT)     REG = (REG ^ (1<<BIT))
#define CLR_BIT(REG,BIT)     REG = (REG & (~(1<<BIT)))

/*
 *  this is the base address of the memory mapped registers for peripherals
 *  and the bus addresses which are connected to drive the clock from RCC
 *  */
#define BASE_ADDR 	(0x40000000)
#define AHB_ADDR 	(0x40020000)
#define APB_ADDR 	(0x40000000)
#define IOP_ADDR 	(0x50000000)

/*
 * Defining the RCC registers for clock
 * */
#define RCC_ADDR    (0x40021000)
/*
 *  we need to access only the IOPORT to Blink An LED for that only clock is enabled
* */
#define RCC_IOPENR  (*(volatile unsigned int *)(RCC_ADDR + 0x00000034))

/*
 * for GPIO reference read below
 * Each general-purpose I/O port has four 32-bit configuration registers (GPIOx_MODER,
 * GPIOx_OTYPER, GPIOx_OSPEEDR and GPIOx_PUPDR), two 32-bit data registers
 * GPIOx_IDR and GPIOx_ODR) and a 32-bit set/reset register (GPIOx_BSRR). In addition
 * all GPIOs have a 32-bit locking register (GPIOx_LCKR) and two 32-bit alternate function
 * selection registers (GPIOx_AFRH and GPIOx_AFRL).
 */
/*
 * Defining registers for PORTA IOs
 */
#define PORTA_ADDR  (0x50000000)
//These are the control registers of PORTA
#define PORTA_MODER (*(volatile unsigned int *)(PORTA_ADDR + 0x00000000))  // register address and the offset
#define PORTA_OTPR  (*(volatile unsigned int *)(PORTA_ADDR + 0x00000004))
#define PORTA_OSPR  (*(volatile unsigned int *)(PORTA_ADDR + 0x00000008))
#define PORTA_PUPR  (*(volatile unsigned int *)(PORTA_ADDR + 0x0000000C))
//These are the data registers of the PORTA
#define PORTA_IPDR  (*(volatile unsigned int *)(PORTA_ADDR + 0x00000010))
#define PORTA_OPDR  (*(volatile unsigned int *)(PORTA_ADDR + 0x00000014))
//These are the config registers of the PORTA
#define PORTA_BSRR  (*(volatile unsigned int *)(PORTA_ADDR + 0x00000018))
#define PORTA_LCKR  (*(volatile unsigned int *)(PORTA_ADDR + 0x0000001C))











