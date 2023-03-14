#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>
#include <string.h>

#define NVIC_ISER0			((uint32_t*)(0xE000E100))

typedef enum
{
	EXTI0_IRQNumber = 6,
	EXTI1_IRQNumber = 7,
	EXTI2_IRQNumber = 8,
	EXTI3_IRQNumber = 9,
	SPI1_IRQNumber = 35,
	EXTI15_10_IRQNumber = 40
}IRQNumber_TypeDef_t;

#define _IO volatile

#define SET_BIT(REG, BIT)		((REG) |=  (BIT))
#define CLEAR_BIT(REG, BIT) 	((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)		((REG) &   (BIT))
#define UNUSED(x)				(void)x

typedef enum
{
	DISABLE = 0x0U,
	ENABLE = !DISABLE
}FunctionalState_t;

/*
 *
* Memory Base Address
*
*/
#define FLASH_BASE_ADDR			(0x08000000UL) 	/* Flash Base Address (up to 1MB) (0x20000000UL)	 */
#define SRAM1_BASE_ADDR			(0x20000000UL)  /* SRAM1 Base Address 112 KB 						 */
#define SRAM2_BASE_ADDR			(0x2001C000UL)	/* SRAM2 Base Address 16 KB							 */

/*
 *
 *	Peripheral Base Addresses
*/
#define PERIPH_BASE_ADDR		(0x40000000UL)							/* Base Address for All peripherals	*/

#define APB1_BASE_ADDR			PERIPH_BASE_ADDR						/* APB1 Bus Domain Base Address		*/
#define APB2_BASE_ADDR			(PERIPH_BASE_ADDR + 0x00010000UL)		/* APB2 Bus Domain Base Address		*/
#define AHB1_BASE_ADDR			(PERIPH_BASE_ADDR + 0x00020000UL)		/* AHB1 Bus Domain Base Address 	*/
#define AHB2_BASE_ADDR			(PERIPH_BASE_ADDR + 0x10000000UL)		/* AHB2 Bus Domain Base Address		*/


/*
 *
 * APB1 Peripherals Base Addresses
 *
 */
#define TIM2_BASE_ADDR			(APB1_BASE_ADDR + 0x0000UL) 			/* Timer 2 Base Address		*/
#define TIM3_BASE_ADDR			(APB1_BASE_ADDR + 0x0400UL) 			/* Timer 3 Base Address		*/
#define TIM4_BASE_ADDR			(APB1_BASE_ADDR + 0x0800UL)				/* Timer 4 Base Address		*/

#define SPI2_BASE_ADDR			(APB1_BASE_ADDR + 0x3800UL) 			/* SPI 2 Base Address		*/
#define SPI3_BASE_ADDR			(APB1_BASE_ADDR + 0x3C00UL) 			/* SPI 3 Base Address		*/

#define USART2_BASE_ADDR 		(APB1_BASE_ADDR + 0x4400UL) 			/* USART 2 Base Address		*/
#define USART3_BASE_ADDR		(APB1_BASE_ADDR + 0x4800UL) 			/* USART 3 Base Address		*/
#define UART4_BASE_ADDR			(APB1_BASE_ADDR + 0x4C00UL) 			/* UART 4 Base Address		*/
#define UART5_BASE_ADDR			(APB1_BASE_ADDR + 0x5000UL) 			/* UART 5 Base Address		*/

#define I2C1_BASE_ADDR			(APB1_BASE_ADDR + 0x5400UL) 			/* I2C 1 Base Address		*/
#define I2C2_BASE_ADDR			(APB1_BASE_ADDR + 0x5800UL) 			/* I2C 2 Base Address		*/
#define I2C3_BASE_ADDR			(APB1_BASE_ADDR + 0x5C00UL) 			/* I2C 3 Base Address		*/

/*
 *
 * APB2 Peripherals Base Addresses
 *
 */
#define TIM1_BASE_ADDR			(APB2_BASE_ADDR + 0x0000UL) 			/* Timer 1 Base Address		*/
#define TIM8_BASE_ADDR			(APB2_BASE_ADDR + 0x0400UL) 			/* Timer 8 Base Address		*/

#define USART1_BASE_ADDR		(APB2_BASE_ADDR + 0x1000UL) 			/* USART 1 Base Address		*/
#define USART6_BASE_ADDR		(APB2_BASE_ADDR + 0x1400UL) 			/* USART 6 Base Address		*/

#define SPI1_BASE_ADDR			(APB2_BASE_ADDR + 0x3000UL) 			/* SPI 1 Base Address		*/
#define SPI4_BASE_ADDR			(APB2_BASE_ADDR + 0x3400UL) 			/* SPI 4 Base Address		*/

#define SYSCFG_BASE_ADDR 		(APB2_BASE_ADDR + 0x3800UL) 			/* SYSCFG Base Address		*/
#define EXTI_BASE_ADDR			(APB2_BASE_ADDR + 0x3C00UL) 			/* EXTI Base Address		*/

/*
 *
 * GPIO Base Addresses
 *
 */
#define GPIOA_BASE_ADDR				(AHB1_BASE_ADDR + 0x0000UL)			/* GPIOA Base Address 		*/
#define GPIOB_BASE_ADDR 			(AHB1_BASE_ADDR + 0x0400UL)			/* GPIOB Base Address 		*/
#define GPIOC_BASE_ADDR 			(AHB1_BASE_ADDR + 0x0800UL)			/* GPIOC Base Address 		*/
#define GPIOD_BASE_ADDR 			(AHB1_BASE_ADDR + 0x0C00UL)			/* GPIOD Base Address 		*/
#define GPIOE_BASE_ADDR				(AHB1_BASE_ADDR + 0x1000UL)			/* GPIOE Base Address 		*/

/*
 *
 * RCC Base Address
 *
 */
#define RCC_BASE_ADDR				(AHB1_BASE_ADDR + 0x3800UL)			/* RCC Base Address			*/

/*
*
*
* Peripheral Structure Definitions
*/

typedef struct
{
	_IO uint32_t MODER;					/*!< GPIO port mode register							Address Offset = 0x0000 */
	_IO uint32_t OTYPER;				/*!< GPIO port output type register						Address Offset = 0x0004 */
	_IO uint32_t OSPEEDR;				/*!< GPIO port output speed register					Address Offset = 0x0008 */
	_IO uint32_t PUPDR;					/*!< GPIO port pull-up/pull-down register				Address Offset = 0x000C */
	_IO uint32_t IDR; 					/*!< GPIO port input register							Address Offset = 0x0010 */
	_IO uint32_t ODR; 					/*!< GPIO port output data register						Address Offset = 0x0014 */
	_IO uint32_t BSRR;					/*!< GPIO port bit/reset register						Address Offset = 0x0018 */
	_IO uint32_t LCKR; 					/*!< GPIO port configuraiton lock register 				Address Offset = 0x001C */
	_IO uint32_t AFR[2];				/*!< GPIO alternate function							Address Offset = 0x0020 */


}GPIO_TypeDef_t;


typedef struct
{
	_IO uint32_t CR;					/*!< RCC clock control register 													Address Offset = 0x0000 */
	_IO uint32_t PLLCFGR;				/*!< RCC PLL configuration register													Address Offset = 0x0040 */
	_IO uint32_t CFGR;				 	/*!< RCC clock configuration register												Address Offset = 0x0008 */
	_IO uint32_t CIR;					/*!< RCC clock interrupt register													Address Offset = 0x000C */
	_IO uint32_t AHB1RSTR; 				/*!< RCC AHB1 peripheral reset register												Address Offset = 0x0010 */
	_IO uint32_t AHB2RSTR; 				/*!< RCC AHB2 peripheral reset register												Address Offset = 0x0014 */
	_IO uint32_t AHB3RSTR;				/*!< RCC AHB3 peripheral reset register												Address Offset = 0x0018 */
	_IO uint32_t RESERVED0; 			/*!< RESERVED AREA																	Address Offset = 0x001C */
	_IO uint32_t APB1RSTR;				/*!< RCC APB1 peripheral reset register												Address Offset = 0x0020 */
	_IO uint32_t APB2RSTR;				/*!< RCC APB1 peripheral reset register												Address Offset = 0x0024 */
	_IO uint32_t RESERVED1[2]; 			/*!< RESERVED AREA																	Address Offset = 0x0028 */
	_IO uint32_t AHB1ENR;				/*!< RCC AHB1 peripheral reset register												Address Offset = 0x0030 */
	_IO uint32_t AHB2ENR;				/*!< RCC AHB2 peripheral reset register												Address Offset = 0x0034 */
	_IO uint32_t AHB3ENR;				/*!< RCC AHB3 peripheral reset register												Address Offset = 0x0038 */
	_IO uint32_t RESERVED2;				/*!< RESERVED AREA																	Address Offset = 0x003C */
	_IO uint32_t APB1ENR;				/*!< RCC APB1 peripheral reset register												Address Offset = 0x0040 */
	_IO uint32_t APB2ENR;				/*!< RCC APB2 peripheral reset register												Address Offset = 0x0044 */
	_IO uint32_t RESERVED3[2];			/*!< RESERVED AREA																	Address Offset = 0x0048 */
	_IO uint32_t AHB1LPENR;				/*!< RCC AHB1 peripheral clock enable in low power mode register					Address Offset = 0x0050 */
	_IO uint32_t AHB2LPENR;				/*!< RCC AHB2 peripheral clock enable in low power mode register					Address Offset = 0x0054 */
	_IO uint32_t AHB3LPENR;				/*!< RCC AHB3 peripheral clock enable in low power mode register					Address Offset = 0x0058 */
	_IO uint32_t RESERVED4;				/*!< RESERVED AREA																	Address Offset = 0x005C */
	_IO uint32_t APB1LPENR;				/*!<  RCC APB1 peripheral clock enable in low power mode register					Address Offset = 0x0060 */
	_IO uint32_t APB2LPENR;				/*!< RCC APB2 peripheral clock enable in low power mode register					Address Offset = 0x0064 */
	_IO uint32_t RESERVED5[2];			/*!< RESERVED AREA																	Address Offset = 0x0068 */
	_IO uint32_t BDCR;					/*!< RCC Backup domain control register												Address Offset = 0x0070 */
	_IO uint32_t CSR;					/*!< RCC clock control & status register											Address Offset = 0x0074 */
	_IO uint32_t RESERVED6[2];			/*!< RESERVED AREA																	Address Offset = 0x0078 */
	_IO uint32_t SSCGR;					/*!< RCC spread spectrum clock generation register									Address Offset = 0x0080 */
	_IO uint32_t PLLI2SCFGR;			/*!< RCC PLLI2S configuration register												Address Offset = 0x0084 */

}RCC_TypeDef_t;


typedef struct
{
	_IO uint32_t MEMRMP;			/*!< SYSCFG MEMORY REMAP REGISTER						ADDRESS OFFSET = 0x00 */
	_IO uint32_t PMC;				/*!< SYSCFG PERIPHERAL MODE CONFIGURATION REGISTER		ADDRESS OFFSET = 0x04 */
	_IO uint32_t EXTI_CR[4];		/*!< SYSCFG EXTERNAL INTERRUPT CONFIGURATION REGISTER	ADDRESS OFFSET = 0x08 */
	_IO uint32_t CMPCR;				/*!< SYSCFG COMPENSATION CELL CONTROL REGISTER			ADDRESS OFFSET = 0x20 */

}SYSCFG_TypeDef_t;


typedef struct
{
	_IO uint32_t IMR;		/*!< INTERRUPT MASK REGISTER 				ADDRESS OFFSET = 0x00 */
	_IO uint32_t EMR;		/*!< EVENT MASK REGISTER					ADDRESS OFFSET = 0x04 */
	_IO uint32_t RTSR;		/*!< RISING TRIGGER SELECTION REGISTER		ADDRESS OFFSET = 0x08 */
	_IO uint32_t FTSR;		/*!< FALLING TRIGGER SELECTION REGISTER		ADDRESS OFFSET = 0x0C */
	_IO uint32_t SWIER;		/*!< SOFTWARE INTERRUPT EVENT REGISTER		ADDRESS OFFSET = 0x10 */
	_IO uint32_t PR;		/*!< PENDING REGISTER						ADDRESS OFFSET = 0x14 */

}EXTI_TypeDef_t;


typedef struct
{
	_IO uint32_t CR1;		/*!< SPI CONTROL REGISTER					ADDRESS OFFSET = 0x00 */
	_IO uint32_t CR2;		/*!< SPI CONTROL REGISTER 2					ADDRESS OFFSET = 0x04 */
	_IO uint32_t SR;		/*!< SPI STATUS REGISTER					ADDRESS OFFSET = 0x08 */
	_IO uint32_t DR;		/*!< SPI DATA REGISTER						ADDRESS OFFSET = 0x0C */
	_IO uint32_t CRCPR;		/*!< SPI CRC POLYNOMİAL REGISTER			ADDRESS OFFSET = 0x10 */
	_IO uint32_t RXCRCR;	/*!< SPI RX CRC RGISTER						ADDRESS OFFSET = 0x14 */
	_IO uint32_t TXCRCR;	/*!< SPI TX CRC REGISTER					ADDRESS OFFSET = 0x18 */
	_IO uint32_t I2SCFGR;	/*!< SPI_I2S CONFIGURATION REGISTER			ADDRESS OFFSET = 0x1C */
	_IO uint32_t I2SPR;		/*!< SPI_I2S PRESCALER REGISTER				ADDRESS OFFSET = 0x20 */

}SPI_TypeDef_t;



typedef struct
{
	_IO uint32_t SR;		/*!<  USART STATUS REGISTER							ADDRESS OFFSET = 0x00 */
	_IO uint32_t DR;		/*!< USART DATA REGISTER							ADDRESS OFFSET = 0x04 */
	_IO uint32_t BRR;		/*!<  USART BAUND RATE REGISTER						ADDRESS OFFSET = 0x08 */
	_IO uint32_t CR1;		/*!< USART CONTROL REGISTER 1						ADDRESS OFFSET = 0x0C */
	_IO uint32_t CR2;		/*!< USART CONTROL REGISTER 2						ADDRESS OFFSET = 0x10 */
	_IO uint32_t CR3;		/*!< USART CONTROL REGISTER 3						ADDRESS OFFSET = 0x14 */
	_IO uint32_t GTPR;		/*!< USART GUARD TIME AND PRESCALER REGISTER		ADDRESS OFFSET = 0x18 */

}USART_TypeDef_t;


typedef struct
{
		_IO uint32_t CR1;		/*!<  I2C CONTROL REGISTER 1					ADDRESS OFFSET = 0x00 */
		_IO uint32_t CR2;		/*!<  I2C CONTROL REGISTER 2					ADDRESS OFFSET = 0x04 */
		_IO uint32_t OAR1;		/*!<  I2C OWN ADDRESS REGISTER					ADDRESS OFFSET = 0x08 */
		_IO uint32_t OAR2;		/*!<  I2C OWN ADDRESS REGISTER					ADDRESS OFFSET = 0x0C */
		_IO uint32_t DR;		/*!<  I2C DATA REGISTER						    ADDRESS OFFSET = 0X10 */
		_IO uint32_t SR1;		/*!<  I2C STATUS REGISTER	1					ADDRESS OFFSET = 0X14 */
		_IO uint32_t SR2;		/*!<  I2C STATUS REGISTER	2					ADDRESS OFFSET = 0X18 */
		_IO uint32_t CCR;		/*!<  I2C CLOCK CONTROL REGISTER				ADDRESS OFFSET = 0X1C */
		_IO uint32_t TRISE;		/*!<  I2C TRISE REGISTER						ADDRESS OFFSET = 0X20 */
		_IO uint32_t FLTR;		/*!<  I2C FLTR REGISTER						    ADDRESS OFFSET = 0X24 */

}I2C_TypeDef_t;


#define GPIOA							((GPIO_TypeDef_t *)(GPIOA_BASE_ADDR))
#define GPIOB							((GPIO_TypeDef_t *)(GPIOB_BASE_ADDR))
#define GPIOC							((GPIO_TypeDef_t *)(GPIOC_BASE_ADDR))
#define GPIOD							((GPIO_TypeDef_t *)(GPIOD_BASE_ADDR))
#define GPIOE							((GPIO_TypeDef_t *)(GPIOE_BASE_ADDR))

#define RCC								((RCC_TypeDef_t *)(RCC_BASE_ADDR))

#define SYSCFG 							((SYSCFG_TypeDef_t*)(SYSCFG_BASE_ADDR))

#define EXTI							((EXTI_TypeDef_t*)(EXTI_BASE_ADDR))

#define SPI1							((SPI_TypeDef_t*)(SPI1_BASE_ADDR))
#define SPI2							((SPI_TypeDef_t*)(SPI2_BASE_ADDR))
#define SPI3							((SPI_TypeDef_t*)(SPI3_BASE_ADDR))
#define SPI4							((SPI_TypeDef_t*)(SPI4_BASE_ADDR))

#define USART2							((USART_TypeDef_t*)(USART2_BASE_ADDR))
#define USART3							((USART_TypeDef_t*)(USART3_BASE_ADDR))
#define UART4							((USART_TypeDef_t*)(UART4_BASE_ADDR))
#define UART5							((USART_TypeDef_t*)(UART5_BASE_ADDR))

#define USART1							((USART_TypeDef_t*)(USART1_BASE_ADDR))
#define USART6							(USART_TypeDef_t*)(USART6_BASE_ADDR))

#define I2C1							(I2C_TypeDef_t*)(I2C1_BASE_ADDR)
#define I2C2							(I2C_TypeDef_t*)(I2C2_BASE_ADDR)
#define I2C3							(I2C_TypeDef_t*)(I2C3_BASE_ADDR)

#define RCC_AHB1ENR_GPIOAEN_Pos			(0U)								/*!< RCC AHB1ENR register GPIOAEN Bit Position	*/
#define RCC_AHB1ENR_GPIOAEN_Msk 		(0x1 << RCC_AHB1ENR_GPIOAEN_Pos) 	/*!< RCC AHB1ENR register GPIOAEN Bit Mask		*/
#define RCC_AHB1ENR_GPIOAEN 			RCC_AHB1ENR_GPIOAEN_Msk 			/*!< RCC AHB1ENR register GPIOAEN Macro			*/

#define RCC_AHB1ENR_GPIOBEN_Pos			(1U)								/*!< RCC AHB1ENR register GPIOBEN Bit Position 	*/
#define RCC_AHB1ENR_GPIOBEN_Msk 		(0x1 << RCC_AHB1ENR_GPIOBEN_Pos) 	/*!< RCC AHB1ENR register GPIOBEN Bit Mask		*/
#define RCC_AHB1ENR_GPIOBEN 			RCC_AHB1ENR_GPIOBEN_Msk 			/*!< RCC AHB1ENR register GPIOBEN Macro			*/

#define RCC_AHB1ENR_GPIOCEN_Pos			(2U)								/*!< RCC AHB1ENR register GPIOCEN Bit Position	*/
#define RCC_AHB1ENR_GPIOCEN_Msk 		(0x1 << RCC_AHB1ENR_GPIOCEN_Pos) 	/*!< RCC AHB1ENR register GPIOCEN Bit Mask		*/
#define RCC_AHB1ENR_GPIOCEN 			RCC_AHB1ENR_GPIOCEN_Msk 			/*!< RCC AHB1ENR register GPIOCEN Macro			*/

#define RCC_AHB1ENR_GPIODEN_Pos			(3U)								/*!< RCC AHB1ENR register GPIODEN Bit Position	*/
#define RCC_AHB1ENR_GPIODEN_Msk 		(0x1 << RCC_AHB1ENR_GPIODEN_Pos) 	/*!< RCC AHB1ENR register GPIODEN Bit Mask		*/
#define RCC_AHB1ENR_GPIODEN 			RCC_AHB1ENR_GPIODEN_Msk 			/*!< RCC AHB1ENR register GPIODEN Macro			*/

#define RCC_APB2ENR_SYSCFGEN_Pos		(14U)								/*!< RCC APB2ENR register SYSCFGEN Bit Position	*/
#define RCC_APB2ENR_SYSCFGEN_Msk		(0x1U << RCC_APB2ENR_SYSCFGEN_Pos)	/*!< RCC APB2ENR register SYSCFGEN Bit Mask		*/
#define RCC_APB2ENR_SYSCFGEN			RCC_APB2ENR_SYSCFGEN_Msk			/*!< RCC APB2ENR register SYSCFGEN Macro		*/

#define RCC_APB2ENR_SPI1_Pos			(12U)								/*!< RCC APB2ENR register SPI1EN Bit Position	*/
#define RCC_APB2ENR_SPI1EN_Msk			(0x1U << RCC_APB2ENR_SPI1_Pos)		/*!< RCC APB2ENR register SPI1EN Bit Mask		*/
#define RCC_APB2ENR_SPI1EN				RCC_APB2ENR_SPI1EN_Msk				/*!< RCC APB2ENR register SPI1EN Macro 			*/

#define RCC_APB1ENR_SPI2_Pos			(14U)								/*!< RCC APB1ENR register SPI2EN Bit Position	*/
#define RCC_APB1ENR_SPI2EN_Msk			(0x1U << RCC_APB1ENR_SPI2_Pos)		/*!< RCC APB1ENR register SPI2EN Bit Mask		*/
#define RCC_APB1ENR_SPI2EN				RCC_APB2ENR_SPI2EN_Msk				/*!< RCC APB1ENR register SPI2EN Macro			*/

#define RCC_APB1ENR_I2C1EN_Pos			(21U)								/*!< RCC APB1ENR register I2C1EN Bit Position	*/
#define RCC_APB1ENR_I2C1EN_Msk			(0x1U << RCC_APB1ENR_I2C1EN_Pos)	/*!< RCC APB1ENR register I2C1EN Bit Mask		*/
#define RCC_APB1ENR_I2C1EN				RCC_APB1ENR_I2C1EN_Msk				/*!< RCC APB1ENR register I2C1EN Macro			*/

#define RCC_APB1ENR_USART2EN_POS		(17U)
#define	RCC_APB1ENR_USART2EN_Msk		(0x1U << RCC_APB1ENR_USART2EN_Pos)
#define RCC_APB1ENR_USART2EN			RCC_APB1ENR_USART2EN_Msk

#define SPI_CR1_SPE						(6U)
#define SPI_CR1_DFF						(11U)

#define SPI_SR_Busy						(7U)
#define SPI_SR_TxE						(1U)
#define SPI_SR_RxNE						(0U)

#define SPI_CR2_TXEIE					(7U)
#define SPI_CR2_RXNEIE					(6U)

#define SPI_CR1_DFF						(11U)

#define USART_CR1_UE					(13U)
#define USART_CR1_TxEIE					(7U)
#define USART_CR1_RxNEIE				(5U)

#define UART_CR2_STOP					(12U)

#define USART_SR_TxE					(7U)
#define USART_SR_TC						(6U)
#define USART_SR_RxNE					(5U)

#define I2C_CR1_PE						(0U)

/*
 *
 * Flag Definitions
 *
 */
#define	SPI_TxE_FLAG					(0x1U << SPI_SR_TxE)
#define	SPI_Busy_FLAG					(0x1U << SPI_SR_Busy)

#define USART_TxE_FLAG					(0x1U << USART_SR_TxE)
#define USART_TC_FLAG					(0x1U << USART_SR_TC)
#define USART_RxNE_FLAG					(0X1U << USART_SR_RxNE)


#include "RCC.h"
#include "EXTI.h"
#include "USART.h"
#include "SPI.h"
#include "I2C.h"


#endif /* INC_STM32F407XX_H_ */
