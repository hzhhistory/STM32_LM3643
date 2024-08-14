#ifndef __PORT_DEV_H__
#define __PORT_DEV_H__
#include"stdbool.h"
#include"delay.h"
#include"stm32f1xx_hal.h"
#define PORT GPIOB
#define SDA_PIN  GPIO_PIN_7
#define SCL_PIN  GPIO_PIN_6
void I2C_Init(void);
void MyI2C_W_SDA(bool BitValue);
void MyI2C_W_SCL(bool BitValue);
bool MyI2C_R_SDA(void);




#endif