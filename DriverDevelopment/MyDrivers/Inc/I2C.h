#ifndef INC_I2C_H_
#define INC_I2C_H_

#include "stm32F407xx.h"

#define Check_PClock_Value(__pClock__, __I2C_Clock__)		( (__I2C_Clock__ <= I2C_SPEED_Standart) ? (__pClock__ <= 2U) : (__pClock__ <= 4U) )
#define I2C_Get_FregValue(__pClock__) 						( (__pClock__) / (1000000U) )
/*
 * @def_group I2C_ClockSpeeds
 *
 */
#define I2C_SPEED_Standart			(100000U)
#define I2C_SPEED_FastMode			(400000U)

/*
 * @def_group I2C_ACK_State
 *
 */
#define I2C_ACK_DISABLE				(0x0000000U)
#define I2C_ACK_ENABLE				(0x0000400U)

/*
 * @def_group I2C_ClockStretch
 *
 */
#define I2C_STRETCH_ENABLE			(0x0000000U)
#define I2C_STRETCH_DISABLE			(0x0000080U)

/*
 * @def_group I2C_AddressingMode
 *
 */
#define I2C_ADDRMODE_7				(0x00004000U)
#define I2C_ADDRMODE_10				(0x0000C000U)

/*
 * @def_group I2C_DutyCycle
 *
 */
#define I2C_DUTY_Standart			(0x00000000U)
#define I2C_DUTY_FM_2				(0x00008000U)
#define I2C_DUTY_FM_16_9			(0x0000C000U)

typedef struct
{
	uint32_t ClockSpeed;						/*!< I2C Clock Speed Choice @def_group I2C_ClockSpeeds			*/
	uint32_t ACK_State;							/*!< I2C ACK_State Choice @def_group I2C_ACK_State				*/
	uint32_t ClockStretch;						/*!< I2C ClockStretch Choice @def_group I2C_ClockStretch		*/
	uint32_t AddressingMode;					/*!< I2C AddressingMode Choice @def_group I2C_AddressingMode	*/
	uint32_t DutyCycle;							/*!< I2C DutyCycle Choice @def_group I2C_DutyCycle				*/
	uint32_t MyOwnAddress;						/*!< I2C Slave Mode Address										*/

}I2C_InitTypeDef_t;

typedef struct
{
	I2C_TypeDef_t *Instance;
	I2C_InitTypeDef_t Init;

}I2C_HandleTypeDef_t;

void I2C_Init(I2C_HandleTypeDef_t *I2C_Handle);
void I2C_PeriphCmd(I2C_TypeDef_t *I2Cx, FunctionalState_t stateOfI2C);


#endif /* INC_I2C_H_ */

