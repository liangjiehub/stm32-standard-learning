#include "stm32f10x.h"                  // Device header

int main(void)
{
	RCC->APB2ENR = 0x00000010;  //AHB2外设时钟使能寄存器
	GPIOC->CRH = 0x00300000;   //端口配置高寄存器（CNF：通用推完输出模式，MODE：输出模式）
	GPIOC->ODR = 0x00002000; //端口输出数据寄存器(2000灭)
	
////	GPIO_InitTypeDef GPIO_InitStructure;
////	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
////	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
////	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
////	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
////	GPIO_Init(GPIOC,&GPIO_InitStructure);
////	GPIO_SetBits(GPIOC,GPIO_Pin_13);  //(亮,点下复位)
////	//GPIO_ResetBits(GPIOC,GPIO_Pin_13);  //(灭)
	while(1)
	{
		
	}
}
