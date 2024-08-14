#ifndef _DELAY_H
#define _DELAY_H
#include "sys.h"
#include"stm32f1xx.h"

void delay_us(uint32_t xus);


void Delay_ms(uint32_t xms);


void Delay_s(uint32_t xs);
void i2c_Delay(void);
#endif

