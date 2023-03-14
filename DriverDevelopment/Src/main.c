#include <stdint.h>
#include "stm32F407xx.h"
#include "GPIO.h"
#include "EXTI.h"

static void LockControl();
static void GPIO_LedConfig();
static void GPIO_ButtonInterruptConfig();
static void SPI_Config();
static void SPI_GPIO_Config();
//static void GPIO_Config(void);
//static void UART_Config(void);

SPI_HandleTypeDef_t SPI_Handle;
USART_HandleTypedef_t USART_Handle;
I2C_HandleTypeDef_t I2C_Handle;

int main(void)
{
	GPIO_LedConfig();
	//GPIO_LockPin(GPIOA, GPIO_PIN_0);
	//LockControl();
	GPIO_ButtonInterruptConfig();
	//SPI_GPIO_Config();
	//SPI_Config();

	I2C_Handle.Instance = I2C1;

	I2C_PeriphCmd(I2C_Handle.Instance, ENABLE);

	for(;;)
	{
/*
		if(GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_Pin_Set)
		{
			GPIO_WritePin(GPIOB, GPIO_PIN_0 | GPIO_PIN_7, GPIO_Pin_Set);
		}
		else
		{
			GPIO_WritePin(GPIOB, GPIO_PIN_0 | GPIO_PIN_7, GPIO_Pin_Reset);
		}
*/
	}
}

void EXTI15_10_IRQHandler()
{
	//char messageToSend[] = "HELLO WORD\n";

	if(EXTI->PR & 0x2000)
	{

		EXTI->PR |= (0x1U <<13U);

		GPIO_WritePin(GPIOB, GPIO_PIN_ALL, GPIO_Pin_Set);

		//SPI_TransmitData_IT(&SPI_Handle, (uint8_t*)messageToSend, strlen(messageToSend));
	}
}
static void GPIO_LedConfig()
{
	GPIO_InitTypeDef_t GPIO_InitStruct = { 0 };

	//RCC_GPIOA_CLK_ENABLE();
	RCC_GPIOB_CLK_ENABLE();
	RCC_GPIOC_CLK_ENABLE();
	//RCC_SYSCFG_CLK_ENABLE();


	GPIO_InitStruct.pinNumber = GPIO_PIN_0 | GPIO_PIN_7;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT;
	GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
	GPIO_InitStruct.Otype = GPIO_OTYPE_PP;
	GPIO_InitStruct.PuPd = GPIO_PUPD_NOPULL;

	GPIO_Init(GPIOB, &GPIO_InitStruct);
	memset(&GPIO_InitStruct, 0, sizeof(GPIO_InitStruct));

	GPIO_InitStruct.pinNumber = GPIO_PIN_13;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.PuPd = GPIO_PUPD_PULLDOWN;

	GPIO_Init(GPIOC, &GPIO_InitStruct);

	//EXTI_LineConfig(EXTI_PortSource_GPIOC, EXTI_LineSource_7);
}
static void LockControl()
{
	GPIO_InitTypeDef_t GPIO_InitStruct = { 0 };

	GPIO_InitStruct.pinNumber = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT;
	GPIO_InitStruct.PuPd = GPIO_PUPD_NOPULL;

	GPIO_Init(GPIOA, &GPIO_InitStruct);
}


static void GPIO_ButtonInterruptConfig()
{
	//RCC_GPIOA_CLK_ENABLE();
	EXTI_InitTypeDef_t EXTI_InitStruct = {0};

	RCC_SYSCFG_CLK_ENABLE();
	EXTI_LineConfig(EXTI_PortSource_GPIOC, EXTI_LineSource_13);

	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct.EXTI_LineNumber = EXTI_LineSource_13;
	EXTI_InitStruct.EXTI_Mode = EXTI_MODE_Interrupt;
	EXTI_InitStruct.TriggerSelection = EXTI_Trigger_Rising;

	EXTI_Init(&EXTI_InitStruct);

	NVIC_EnableInterrupt(EXTI15_10_IRQNumber);
}


static void SPI_Config()
{
	RCC_SPI1_CLK_ENABLE();

	SPI_HandleTypeDef_t SPI_Handle = {0};

	SPI_Handle.Instance = SPI1;
	SPI_Handle.Init.BaudRate = SPI_BAUDRATE_DIV8;
	SPI_Handle.Init.BusConfig = SPI_BUS_FullDublex;
	SPI_Handle.Init.CPHA = SPI_CPHA_FIRST;
	SPI_Handle.Init.CPOL = SPI_CPOL_LOW;
	SPI_Handle.Init.DFF_Format = SPI_DFF_8BITS;
	SPI_Handle.Init.Mode = SPI_MODE_MASTER;
	SPI_Handle.Init.SSM_Cmd = SPI_SSM_ENABLE;

	SPI_Init(&SPI_Handle);

	SPI_PeriphCmd(&SPI_Handle, ENABLE);

	NVIC_EnableInterrupt(SPI1_IRQNumber);
}
static void SPI_GPIO_Config()
{

	GPIO_InitTypeDef_t GPIO_InitStruct = {0};

	GPIO_InitStruct.pinNumber = GPIO_PIN_5 | GPIO_PIN_7; //PA5 SCK - PA7
	GPIO_InitStruct.Mode  = GPIO_MODE_AF;
	GPIO_InitStruct.Otype  = GPIO_OTYPE_PP;
	GPIO_InitStruct.PuPd  = GPIO_PUPD_NOPULL;
	GPIO_InitStruct.Speed  = GPIO_SPEED_VERY;

	GPIO_Init(GPIOA, &GPIO_InitStruct);

}

void SPI1_IRQHandler()
{
	SPI_InterruptHandler(&SPI_Handle);
}









