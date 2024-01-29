#include<stdio.h>
#include<stdint.h>

void Delay_ms(uint16_t time);



void GPIO_Configuration(void)
{
	unsigned long* RCC_AHB1ENR = (unsigned long*)0x40023830 ;
	unsigned long* PORTG_MODER = (unsigned long*)0x40021800 ;
	unsigned long* PORTG_ODR = (unsigned long*)0x40021814 ;
	*RCC_AHB1ENR |= 0x40;
	*PORTG_MODER |= 0x04000000;
	*PORTG_ODR |= 0x2000;



};

void Delay_ms(uint16_t time)
{
	uint32_t time_n = time*1200;
	    while (time_n != 0){ time_n--;}
}

int main (void)
{
	GPIO_Configuration();

	unsigned long* PORTG_BSRR = (unsigned long*)0x40023818 ;

	while(1)
				{
					*PORTG_BSRR |= 0x2000;  // bat den
					Delay_ms(1000);
					*PORTG_BSRR |= 0x20000000; //tat den
					Delay_ms(1000);
				}
}


