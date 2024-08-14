#include "delay.h"
#include "sys.h"

/**
  * @brief  ΢�뼶��ʱ
  * @param  xus ��ʱʱ������Χ��0~233015
  * @retval ��
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
//    reload = SysTick->LOAD;                     //��ȡ��װ�ؼĴ���ֵ
//    ticks = nus * (SystemCoreClock / 1000000);  //����ʱ��ֵ   ������Ĵ���1us����શ�ʱ����value�����½�����ֵ
//    told=SysTick->VAL;                          //��ȡ��ǰ��ֵ�Ĵ���ֵ����ʼʱ��ֵ��
//
//    while(1)
//    {
//        tnow=SysTick->VAL;          //��ȡ��ǰ��ֵ�Ĵ���ֵ
//        if(tnow!=told)              //��ǰֵ�����ڿ�ʼֵ˵�����ڼ���
//        {
//
//            if(tnow<told)             //��ǰֵС�ڿ�ʼ��ֵ��˵��δ�Ƶ�0
//                tcnt+=told-tnow;     //����ֵ=��ʼֵ-��ǰֵ
//
//            else                  //��ǰֵ���ڿ�ʼ��ֵ��˵���ѼƵ�0�����¼���
//                tcnt+=reload-tnow+told;   //����ֵ=��װ��ֵ-��ǰֵ+��ʼֵ  ����
//            //�ӿ�ʼֵ�Ƶ�0��
//            told=tnow;                //���¿�ʼֵ
//            if(tcnt>=ticks)break;     //ʱ�䳬��/����Ҫ�ӳٵ�ʱ��,���˳�.
//        }
//    }
//}

/**
  * @brief  ���뼶��ʱ
  * @param  xms ��ʱʱ������Χ��0~4294967295
  * @retval ��
  */
void Delay_ms(uint32_t xms)
{
    while(xms--)
    {
        delay_us(1000);
    }
}

/**
  * @brief  �뼶��ʱ
  * @param  xs ��ʱʱ������Χ��0~4294967295
  * @retval ��
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
