/*========================================================================
*                        INCLUDE FILES
==========================================================================*/
#include<stdio.h>
#include<stdint.h>

/*========================================================================
*                        DETINITISION
==========================================================================*/

#define RRC_ADDRESS								0x40023800
#define RRC_ADD      							3

#define PORTA_ADDRESS							0x40020000
#define PORTB_ADDRESS							0x40020400
#define PORTC_ADDRESS							0x40020800
#define PORTD_ADDRESS							0x40020C00
#define PORTE_ADDRESS							0x40021000
#define PORTF_ADDRESS							0x40021400
#define PORTG_ADDRESS							0x40021800
#define PORTH_ADDRESS							0x40021C00
#define PORTI_ADDRESS							0x40022000
#define PORTJ_ADDRESS							0x40022400
#define PORTK_ADDRESS							0x40022800

/*========================================================================
*                        LOCAL FUNSION PROTOTYPES
==========================================================================*/

void Delay_ms(uint16_t time);
void GPIO_Configuration();

/*========================================================================
*                        LOCAL TYPEDEFS (STRUCTURE, UNIONS, ENUMS)
==========================================================================*/
/* creat a struct for RRC register */

struct My_RRC_Type
{
	uint32_t My_RC;
	uint32_t My_PLLCFGR;
	uint32_t My_CFGR;
	uint32_t My_CIR;
	uint32_t My_AHB1RSTR;
	uint32_t My_AHB2RSTR;
	uint32_t My_AHB3RSTR;
	uint32_t My_APB1RSTR;
	uint32_t My_APB2RSTR;
	uint32_t My_AHB1ENR;
	uint32_t My_AHB2ENR;
	uint32_t My_AHB3ENR;
	uint32_t My_APB1ENR;
	uint32_t My_APB2ENR;
	uint32_t My_AHB1LPENR;
	uint32_t My_AHB2LPENR;
	uint32_t My_AHB3LPENR;
	uint32_t My_APB1LPENR;
	uint32_t My_APB2LPENR;
	uint32_t My_BDCR;
	uint32_t My_SSCGR;
	uint32_t My_PLLI2SCFGR;

};

/* creat a struct for GPIO register */

struct My_GPIO_Type
{
	uint32_t My_MODER;
	uint32_t My_OTYPER;
	uint32_t My_OSPEEDR;
	uint32_t My_PUPDR;
	uint32_t My_IDR;
	uint32_t My_ODR;
	uint32_t My_BSRR;
	uint32_t My_LCKR;
	uint32_t My_AFRL;
	uint32_t My_AFRH;

};

/*========================================================================
*                        LOCAL VARIABLES
==========================================================================*/

struct My_RRC_Type * My_RRC = (struct My_RRC_Type *)RRC_ADDRESS;
struct My_GPIO_Type * PORTA = (struct My_GPIO_Type *)PORTA_ADDRESS;
struct My_GPIO_Type * PORTG = (struct My_GPIO_Type *)PORTG_ADDRESS;


/*========================================================================
*                        LOCAL FUNCTIONS
==========================================================================*/

void GPIO_Configuration(void)
{

unsigned int* RCC_AHB1_ENB;
unsigned int* GPIOG_MODER;
unsigned int* GPIOG_PUPDR;
unsigned int* GPIOG_ODR;
unsigned int* GPIOG_BSRR;

RCC_AHB1_ENB = 0x40023830;
*RCC_AHB1_ENB = 0X40;

GPIOG_MODER = 0x40021800;
*GPIOG_MODER = 0x04000000;
GPIOG_ODR = 0x40021814;
*GPIOG_ODR = 0x2000;
GPIOG_BSRR = 0x40021818;
//*GPIOG_BSRR = 0x2000;
//*GPIOG_BSRR = 0x20000000;
};

void Delay_ms(uint16_t time)
{
	uint32_t time_n = time * 12000;
	    while (time_n != 0){ time_n--;}
}

/*========================================================================
*                        GLOBAL FUNCTIONS
==========================================================================*/
int main(void)
{
	 GPIO_Configuration();

	 while(1)
	 	{
	 		GPIOG
	 	}

}


