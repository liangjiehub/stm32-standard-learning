#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);  //打开时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);  //打开AFIO
//	 
//	GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2, ENABLE);  //重映射不用PA0，用PA15
//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);  //关闭调试
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	TIM_InternalClockConfig(TIM2);  //选择内部时钟
	
	TIM_TimeBaseInitTypeDef Tim_TimeBaseInitStructure;  //打开时基单元
	Tim_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	Tim_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	Tim_TimeBaseInitStructure.TIM_Period  = 100-1;  //ARR
	Tim_TimeBaseInitStructure.TIM_Prescaler  = 720-1;  //PSC
	Tim_TimeBaseInitStructure.TIM_RepetitionCounter  = 0;
	TIM_TimeBaseInit(TIM2, &Tim_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef TIM_InitStructure;
	TIM_OCStructInit(&TIM_InitStructure); //给结构体成员赋值
	TIM_InitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_InitStructure.TIM_OutputState = TIM_OutputNState_Enable;
	TIM_InitStructure.TIM_Pulse  = 50;  //CCR
	
	TIM_OC1Init(TIM2, &TIM_InitStructure);
	
	TIM_Cmd(TIM2, ENABLE);  //启动定时器
}

void PWM_SetCompare1(uint16_t Compare)
{
	TIM_SetCompare1(TIM2, Compare); //设置CCR寄存器的值
}
