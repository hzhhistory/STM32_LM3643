#include"port_dev.h"
void I2C_Init(void)
{
    /*开启时钟*/
    __HAL_RCC_GPIOB_CLK_ENABLE();	//开启GPIOB的时钟

    /*GPIO初始化*/
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.Pin = SCL_PIN;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStructure.Pull = GPIO_PULLUP;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(PORT, &GPIO_InitStructure);

    GPIO_InitStructure.Pin= SDA_PIN;
    GPIO_InitStructure.Mode =  GPIO_MODE_OUTPUT_OD;
    GPIO_InitStructure.Pull = GPIO_PULLDOWN;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(PORT, &GPIO_InitStructure);

    /*设置默认电平*/
    HAL_GPIO_WritePin(GPIOB, SCL_PIN ,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, SDA_PIN,GPIO_PIN_SET);         //设置PB10和PB11引脚初始化后默认为高电平（释放总线状态）
}
void MyI2C_W_SDA(bool BitValue)
{
    HAL_GPIO_WritePin(PORT, SDA_PIN, BitValue);		//根据BitValue，设置SDA引脚的电平，BitValue要实现非0即1的特性
  										//延时10us，防止时序频率超过要求
}

void MyI2C_W_SCL(bool BitValue)
{
    HAL_GPIO_WritePin(PORT, SCL_PIN, BitValue);		//根据BitValue，设置SCL引脚的电平
    							//延时10us，防止时序频率超过要求
}
bool MyI2C_R_SDA(void)
{
    uint8_t BitValue;
    BitValue = HAL_GPIO_ReadPin(PORT, SDA_PIN);		//读取SDA电平
    // 延时10us，防止时序频率超过要求
    return BitValue;											//返回SDA电平
}