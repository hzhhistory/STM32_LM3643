#ifndef __TMP102_H__
#define __TMP102_H__
#include"myiic.h"
#include"sys.h"
#include"delay.h"

u8 Tmp102_ReadOneByte(u8 DeviceAdd, u8 PointAddr);
u16 Tmp102_ReadOneWrite(u8 DeviceAdd, u8 PointAddr);
u8 Tmp102_ReadTemperature(void);
void Tmp102_Init(void);

#endif