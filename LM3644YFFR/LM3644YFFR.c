#include "LM3644YFFR.h"
#include"port_dev.h"
#include"gpio.h"

#define IIC2

IIC_SIM_DRV_T IIC_DEV={
        .delay= i2c_Delay,
        .setSDA=MyI2C_W_SDA,
        .setSCL=MyI2C_W_SCL,
        .readSDA=MyI2C_R_SDA,
};

/*
 * @Function description: Initialization of the LM3644YFFR
 * @parameter:void
 * @return void
 * @date time is 2024.7.29
 */

void LM3644YFFR_INIT(void)
{
    I2C_Init();
    Power_Enable;
}
#ifdef IIC1
/*
 * @Function description:Registers written to the LM3644YFFR
 * @parameter1: Register address
 * @parameter2 :Write register data
 * @return void
 * @date time is 2024.7.29
 */

uint8_t LM3644YFFR_WriteReg( uint8_t PointAddr,uint8_t Data)
{
    MyI2C_Start();
    MyI2C_SendByte(IIC_SLAVE_ADDRW);
    MyI2C_ReceiveAck();
    MyI2C_SendByte(PointAddr);
    MyI2C_ReceiveAck();
    MyI2C_SendByte(Data);
    MyI2C_ReceiveAck();
    MyI2C_Stop();

}

/*
 * @Function description:Read LM3644YFFR data
 * @parameter:void
 * @return:8 bits of data
 * @date time is 2024.7.29
 */

uint8_t LM3644YFFR_ReadReg(void)
{
    uint8_t Data;

    MyI2C_Start();
    MyI2C_SendByte(IIC_SLAVE_ADDRR);
    MyI2C_ReceiveAck();
    MyI2C_SendByte(0x0C);
    MyI2C_ReceiveAck();
    Data=MyI2C_ReceiveByte();
    MyI2C_ReceiveAck();
    MyI2C_Stop();

    return Data;
}
#endif

#ifdef IIC2

/*
 * @Function description:Registers written to the LM3644YFFR
 * @parameter1: Register address
 * @parameter2 :Write register data
 * @return void
 * @date time is 2024.7.29
 */

void LM3644YFFR_WriteReg( uint8_t PointAddr,uint8_t Data)
{
    iicStart(&IIC_DEV);
    iicSendByte(&IIC_DEV,IIC_SLAVE_ADDRW);
    iicWaitAck(&IIC_DEV);
    iicSendByte(&IIC_DEV,PointAddr);
    iicWaitAck(&IIC_DEV);
    iicSendByte(&IIC_DEV,Data);
    iicWaitAck(&IIC_DEV);
    iicStop(&IIC_DEV);

}

/*
 * @Function description:Read LM3644YFFR data
 * @parameter:void
 * @return:8 bits of data
 * @date time is 2024.7.29
 */

uint8_t LM3644YFFR_ReadReg(void)
{
    uint8_t Data;

    iicStart(&IIC_DEV);
    iicSendByte(&IIC_DEV,IIC_SLAVE_ADDRR);
    iicWaitAck(&IIC_DEV);
    iicSendByte(&IIC_DEV,0x0C);
    iicWaitAck(&IIC_DEV);
    Data = iicReadByte(&IIC_DEV);
    iicWaitAck(&IIC_DEV);
    iicStop(&IIC_DEV);

    return Data;
}
#endif

/*
 * @Function description First gear
 * @parameters:void
 * @return void
 * @date time is 2024.7.29
 */

void Infrared_Firstgear(void)
{
    LM3644YFFR_WriteReg(Enable_Register,0x19);
    LM3644YFFR_WriteReg(IVFM_Register,0x27);
    LM3644YFFR_WriteReg(Torch1_Brightness,0x00);
    LM3644YFFR_WriteReg(Boost_Configuration,0x00);
}

/*
 * @Function description Second gear
 * @parameters:void
 * @return void
 * @date time is 2024.7.29
 */

void Infrared_Secondgear(void)
{
    LM3644YFFR_WriteReg(Enable_Register,0x19);
    LM3644YFFR_WriteReg(IVFM_Register,0x27);
    LM3644YFFR_WriteReg(Torch1_Brightness,0x00);
    LM3644YFFR_WriteReg(Boost_Configuration,0x00);
}

/*
 * @Function description Third gear
 * @parameters:void
 * @return void
 * @date time is 2024.7.29
 */

void Infrared_Thirdgear(void)
{
    LM3644YFFR_WriteReg(Enable_Register,0x19);
    LM3644YFFR_WriteReg(IVFM_Register,0x27);
    LM3644YFFR_WriteReg(Torch1_Brightness,0x3F);
    LM3644YFFR_WriteReg(Boost_Configuration,0x00);
}

/*
 * @Function description Fourth gear
 * @parameters:void
 * @return void
 * @date time is 2024.7.29
 */

void Infrared_Fourthgear(void)
{
    LM3644YFFR_WriteReg(Enable_Register,0x19);
    LM3644YFFR_WriteReg(IVFM_Register,0x27);
    LM3644YFFR_WriteReg(Torch1_Brightness,0x7F);
    LM3644YFFR_WriteReg(Boost_Configuration,0x00);
}

/*
 * @Function description Fifth gear
 * @parameters:void
 * @return void
 * @date time is 2024.7.29
 */

void Infrared_Fifthgear(void)
{
    LM3644YFFR_WriteReg(Enable_Register,0x19);
    LM3644YFFR_WriteReg(IVFM_Register,0x27);
    LM3644YFFR_WriteReg(Torch1_Brightness,0x7F);
    LM3644YFFR_WriteReg(Boost_Configuration,0x01);
}

/*
 * @Function description Sixth gear
 * @parameters:void
 * @return void
 * @date time is 2024.7.29
 */

void Infrared_Sixthgear(void)
{
    LM3644YFFR_WriteReg(Enable_Register,0x19);
    LM3644YFFR_WriteReg(IVFM_Register,0x27);
    LM3644YFFR_WriteReg(Torch1_Brightness,0x7F);
    LM3644YFFR_WriteReg(Boost_Configuration,0x03);
}

/*
 * @Function description Seventh gear
 * @parameters:void
 * @return void
 * @date time is 2024.7.29
 */

void Infrared_Seventhgear(void)
{
    LM3644YFFR_WriteReg(Enable_Register,0x0D);
    LM3644YFFR_WriteReg(LED1_Brightness,0x00);
}

/*
 * @Function description Eighth gear
 * @parameters:void
 * @return void
 * @date time is 2024.7.29
 */

void Infrared_Eighthgear(void)
{
    LM3644YFFR_WriteReg(Enable_Register,0x0D);
}

/*
 * @Function description:Select the infrared brightness and mode that does not work
 * @parameters:The value range of the uint8_t type is 0~8
 * @return void
 * @date time is 2024.7.29
 */

void LM3644YFFR_LEDFlash(uint8_t Luminance)
{
    switch (Luminance)
    {
        case Infrared_1:Infrared_Firstgear();   break;
        case Infrared_2:Infrared_Secondgear();  break;
        case Infrared_3:Infrared_Thirdgear();   break;
        case Infrared_4:Infrared_Fourthgear();  break;
        case Infrared_5:Infrared_Fifthgear();   break;
        case Infrared_6:Infrared_Sixthgear();   break;
        case Infrared_7:Infrared_Seventhgear(); break;
        case Infrared_8:Infrared_Eighthgear();  break;
        default:Infrared_Eighthgear();          break;
    }

}



