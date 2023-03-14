#ifndef INC_USART_H_
#define INC_USART_H_
#include "stm32F407xx.h"


#define USART_MODE_Tx					((uint32_t)(0x00000008))
#define USART_MODE_Rx					((uint32_t)(0x00000004))
#define USART_MODE_Tx_Rx				((uint32_t)(0x0000000C))

#define USART_WORDLENGTH_8BITS			((uint32_t)(0x00000000))
#define	USART_WORDLENGTH_9BITS			((uint32_t)(0x00001000))

#define USART_PARITY_NONE				((uint32_t)(0x00000000))
#define USART_PARITY_Even				((uint32_t)(0x00000400))
#define USART_PARITY_Odd				((uint32_t)(0x00000600))

#define USART_STOPBITS_1				((uint32_t)(0x00000000))
#define USART_STOPBITS_Half				((uint32_t)(0x00001000))
#define USART_STOPBITS_2				((uint32_t)(0x00002000))
#define USART_STOPBITS_1_Half			((uint32_t)(0x00003000))

#define USART_OVERSAMPLE_16				((uint32_t)(0x00000000))
#define USART_OVERSAMPLE_8				((uint32_t)(0x00008000))

#define USART_HW_NONE					(uint32_t)(0x00000000)
#define USART_HW_CTS					(uint32_t)(0x00000200)
#define USART_HW_RTS					(uint32_t)(0x00000100)
#define USART_HW_CTS_RTS				(uint32_t)(0x00000300)


#define __USART_BRR_OVERSAMPLING_8_(__PCLOCK__, __BAUDRATE__)		(1)
#define __USART_BRR_OVERSAMPLING_16_(__PCLOCK__, __BAUDRATE__)		(1)

typedef enum
{
	USART_BUS_FREE = 0x0U,
	USART_BUS_Tx = 0X1U,
	USART_BUS_Rx = 0x2U
}USART_BusState_t;


typedef struct
{
	uint32_t Mode;
	uint32_t WordLength;
	uint32_t BaudRate;
	uint32_t Parity;
	uint32_t StopBits;
	uint32_t OverSampling;
	uint32_t HardwareFlowCControl;


}USART_InitTypeDef_t;

typedef struct __USART_HandleTypedef_t
{
	USART_TypeDef_t *Instance;
	USART_InitTypeDef_t Init;
	uint8_t *pTxBuffer;
	uint16_t TxBufferSize;
	uint8_t TxStatus;
	void(*TxISR_Function)(struct __USART_HandleTypedef_t *USART_Handle);
	uint8_t *pRxBuffer;
	uint16_t RxStatus;
	uint16_t RxBufferSize;
	void (*RxISR_Function)(struct __USART_HandleTypedef_t *USART_Handle);

}USART_HandleTypedef_t;

typedef enum
{
	USART_FLAG_RESET = 0x0U,
	USART_FLAG_SET = !USART_FLAG_RESET
}USART_FlagStatus_t;


#define __USART_DIV_VALUE_16(__CLOCK__,__BAUDRADE__)				(25U * (uint32_t)(__CLOCK__)) / (4U * (__BAUDRADE__) )
#define __USART_DIV_VALUE_8(__CLOCK__,__BAUDRADE__)					(25U * (uint32_t)(__CLOCK__)) / (2U * (__BAUDRADE__) )


void USART_Init(USART_HandleTypedef_t *USART_Handle);
void USART_TransmitData(USART_HandleTypedef_t *USART_Handle, uint8_t *pData, uint16_t dataSize);
USART_FlagStatus_t USART_GetFlagStatus(USART_HandleTypedef_t *USART_Handle, uint16_t flagName);
void USART_PeriphCmd(USART_HandleTypedef_t *USART_Handle, FunctionalState_t stateOfUSART);
void USART_ReceiveData(USART_HandleTypedef_t *USART_Handle, uint8_t *pBuffer, uint16_t dataSize);
void USART_TransmitData_IT(USART_HandleTypedef_t *USART_Handle, uint8_t *pData, uint16_t dataSize);
void USART_InterruptHandler(USART_HandleTypedef_t *USART_Handle);
void USART_ReceiveData_IT(USART_HandleTypedef_t *USART_Handle, uint32_t *pBuffer, uint16_t dataSize);


#endif /* INC_USART_H_ */
