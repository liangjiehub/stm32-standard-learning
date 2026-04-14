#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "IC.h"

int main(void)
{
	OLED_Init();
	PWM_Init();
	IC_Init();
	
	OLED_ShowString(1, 1, "Freq:00000Hz");
	
	PWM_SetPrescaler(720 - 1);  // Freq = 72M / (Psc + 1) / (ARR + 1)   目前这里的ARR+1是100
	PWM_SetCompare1(50);        // Duty = CCR / 100
	
	
	while (1)
	{
		OLED_ShowNum(1, 6, IC_GetFre(), 5);
	}
}
