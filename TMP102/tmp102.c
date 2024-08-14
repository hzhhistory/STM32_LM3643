#include"tmp102.h"
u16 recv_data;
double temp;
void Tmp102_Init(void)
{
    MyI2C_Init();
}
u8 Tmp102_ReadOneByte(u8 DeviceAdd, u8 PointAddr)
{

    u8 temp=0;
    MyI2C_Start();
    MyI2C_SendByte(DeviceAdd);
    MyI2C_ReceiveAck();
    MyI2C_SendByte(PointAddr);
    MyI2C_ReceiveAck();
    MyI2C_Start();
    MyI2C_SendByte(DeviceAdd|0x01);
    MyI2C_ReceiveAck();
    temp=MyI2C_ReceiveByte();
    MyI2C_Stop();
    return temp;
}

u16 Tmp102_ReadOneWrite(u8 DeviceAdd, u8 PointAddr)
{
    u16 tempH=0;
    u16 tempL=0;
    u16 temp=0;
    MyI2C_Start();
    MyI2C_SendByte(DeviceAdd);   //·¢ËÍÆ÷¼þµØÖ·0X92,Ð´Êý¾Ý
    MyI2C_ReceiveAck();
    MyI2C_SendByte(PointAddr);
    MyI2C_ReceiveAck();

    MyI2C_Start();
    MyI2C_SendByte(DeviceAdd|0x01);
    MyI2C_ReceiveAck();
    tempH=MyI2C_ReceiveByte();
    MyI2C_ReceiveAck();
    HAL_GPIO_WritePin(PORT,SDA_PIN,GPIO_PIN_SET);   //**如果不对信号线进行拉高则只能读取一次数据**
    tempL=MyI2C_ReceiveByte();
    IIC_NACK();
    MyI2C_Stop();
    temp = (tempH << 8) | tempL ;
    temp = (temp >> 4); //ÓÉÓÚtmp102ºÍtmp112µÄÓÐÐ§Î»Îª12bit£¨¸ß12Î»ÓÐÐ§£©¡£ËùÒÔÐèÒªÓÒÒÆ4Î»
    return temp;
}
void 	Tmp102_WriteOneByte(u8 DeviceAdd,u8 PointAddr,u8 DataToWrite)
{

    MyI2C_Start();
    MyI2C_SendByte(DeviceAdd);
    MyI2C_ReceiveAck();
    MyI2C_SendByte(PointAddr);
    MyI2C_ReceiveAck();
    IIC_SDA_H();
    MyI2C_SendByte(DataToWrite);
    MyI2C_ReceiveAck();
    MyI2C_Stop();
    Delay_ms(30);
}

void 	Tmp102_WriteOneWrite(u8 DeviceAdd,u8 PointAddr,u16 DataToWrite)
{
    u8 ack;
    MyI2C_Start();
    MyI2C_SendByte(DeviceAdd);   //·¢ËÍÆ÷¼þµØÖ·0XA0,Ð´Êý¾Ý
    MyI2C_ReceiveAck();
    MyI2C_SendByte(PointAddr);   //·¢ËÍµÍµØÖ·
    MyI2C_ReceiveAck();
    IIC_SDA_H();
    MyI2C_SendByte((DataToWrite>>8)&0xff);
    ack = MyI2C_ReceiveAck();
    MyI2C_SendByte(DataToWrite&0xff);
    ack = MyI2C_ReceiveAck();
    MyI2C_Stop();//²úÉúÒ»¸öÍ£Ö¹Ìõ¼þ
    Delay_ms(30);
}




u8 Tmp102_ReadTemperature(void)
{
    Tmp102_WriteOneWrite(0X92,0X02,0X7640);
    delay_ms(1000);
    recv_data = Tmp102_ReadOneWrite(0X92,0X02);
    temp=recv_data*0.0625;

    return (u8)temp;


}