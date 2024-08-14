#ifndef __MPU6050_H
#define __MPU6050_H
#include "stm32f1xx_hal.h"                  // Device header
#include"delay.h"
#define PORT GPIOB
#define SDA_PIN  GPIO_PIN_7
#define SCL_PIN  GPIO_PIN_6
void MyACK(void);
void MyI2C_Init(void);
void MyI2C_Start(void);
void MyI2C_Stop(void);
void MyI2C_SendByte(uint8_t Byte);
uint8_t MyI2C_ReceiveByte(void);
void MyI2C_SendAck(uint8_t AckBit);
uint8_t MyI2C_ReceiveAck(void);


#endif
