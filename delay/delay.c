#include "delay.h"
#include "sys.h"

/**
  * @brief  微秒级延时
  * @param  xus 延时时长，范围：0~233015
  * @retval 无
  */
void delay_us(uint32_t udelay)
{
  uint32_t startval,tickn,delays,wait;

  startval = SysTick->VAL;
  tickn = HAL_GetTick();
  //sysc = 72000;  //SystemCoreClock / (1000U / uwTickFreq);
  delays =udelay * 72; //sysc / 1000 * udelay;
  if(delays > startval)
    {
      while(HAL_GetTick() == tickn)
        {

        }
      wait = 72000 + startval - delays;
      while(wait < SysTick->VAL)
        {

        }
    }
  else
    {
      wait = startval - delays;
      while(wait < SysTick->VAL && HAL_GetTick() == tickn)
        {

        }
    }
}
//void delay_us(u32 nus)
//{
//    u32 ticks;
//    u32 told,tnow,reload,tcnt=0;
//
//    reload = SysTick->LOAD;                     //获取重装载寄存器值
//    ticks = nus * (SystemCoreClock / 1000000);  //计数时间值   括号里的代表1us秒嘀嗒定时器的value会向下降多少值
//    told=SysTick->VAL;                          //获取当前数值寄存器值（开始时数值）
//
//    while(1)
//    {
//        tnow=SysTick->VAL;          //获取当前数值寄存器值
//        if(tnow!=told)              //当前值不等于开始值说明已在计数
//        {
//
//            if(tnow<told)             //当前值小于开始数值，说明未计到0
//                tcnt+=told-tnow;     //计数值=开始值-当前值
//
//            else                  //当前值大于开始数值，说明已计到0并重新计数
//                tcnt+=reload-tnow+told;   //计数值=重装载值-当前值+开始值  （已
//            //从开始值计到0）
//            told=tnow;                //更新开始值
//            if(tcnt>=ticks)break;     //时间超过/等于要延迟的时间,则退出.
//        }
//    }
//}

/**
  * @brief  毫秒级延时
  * @param  xms 延时时长，范围：0~4294967295
  * @retval 无
  */
void Delay_ms(uint32_t xms)
{
    while(xms--)
    {
        delay_us(1000);
    }
}

/**
  * @brief  秒级延时
  * @param  xs 延时时长，范围：0~4294967295
  * @retval 无
  */
void Delay_s(uint32_t xs)
{
    while(xs--)
    {
        Delay_ms(1000);
    }
}


 void i2c_Delay(void)
{
    delay_us(10);
}
