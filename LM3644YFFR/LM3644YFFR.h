#ifndef __LM3644YFFR_H__
#define __LM3644YFFR_H__

#include"stm32f1xx_hal.h"
#include"IIC.h"
#include"../port/port_dev.h"

/*-------------------------Register address----------------------------*/
#define IIC_SLAVE_ADDRW 0xC6
#define IIC_SLAVE_ADDRR 0xC7
#define IVFM_Register 0x02
#define Enable_Register 0x01
#define LED1_Brightness 0x03
#define LED2_Brightness 0x04
#define Torch1_Brightness 0x05
#define Torch2_Brightness 0x06
#define Boost_Configuration 0x07
#define Timing_Configuration 0x08
#define Device_ID 0x0C

/*-------------------------Power Enable--------------------------------*/
#define Power_Enable HAL_GPIO_WritePin(GPIOA,LED1_Pin,GPIO_PIN_SET)

/*-------------------------Brightness level----------------------------*/
typedef enum
{
    Infrared_1=0,
    Infrared_2,
    Infrared_3,
    Infrared_4,
    Infrared_5,
    Infrared_6,
    Infrared_7,
    Infrared_8
}LED_LM;

/*---------------------Function Definitions--------------------------*/
void LM3644YFFR_INIT(void);                                             // Initialization of the LM3644YFFR
void LM3644YFFR_WriteReg(uint8_t PointAddr,uint8_t Data);               // Registers written to the LM3644YFFR
uint8_t LM3644YFFR_ReadReg(void);                                           // Reads the LM3644YFFR
void LM3644YFFR_LEDFlash(uint8_t Luminance);                            // Reads the LM3644YFFR

#endif