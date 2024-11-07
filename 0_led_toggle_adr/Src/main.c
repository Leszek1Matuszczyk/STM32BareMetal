//where led is connected
//port : a
//pin : 5

#define PERIPH_BASE 			(0x40000000UL)
#define AHB1PERIPH_OFFSET 		(0x00020000UL)
#define AHB1PERIPH_BASE			(PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIOA_OFFSET 			(0x0000U)


#define GPIOA_BASE				(AHB1PERIPH_BASE + GPIOA_OFFSET)


#define RCC_OFFSET				(0x00003800UL)
#define RCC_BASE				(AHB1PERIPH_BASE + RCC_OFFSET)


#define AHB1EN_R_OFFSET			(0x30)
#define RCC_AHB1_R				(*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))

#define MODE_R_OFFSET			(0x00UL)
#define GPIOA_MODE_R			(*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET				(0x14UL)
#define GPIOA_OD_R				(*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))

#define GPIOAEN					(1U<<0)

#define PIN5					(1U<<5)
#define LED_PIN					PIN5

//
//(1U<<10) set bit 10 to 1
//&=~(1U<<11) set bit 11 to 0
//
int main (void)
{

	//enable clock accest o GPIOA
	RCC_AHB1_R |= GPIOAEN;
	//SET PA5 as OUTPUT pin
	GPIOA_MODE_R |= (1U<<10);
	GPIOA_MODE_R &=~(1U<<11);

	while(1)
	{

		//TOGGLE GPIOA PIN5
		GPIOA_OD_R |= LED_PIN;
	}

}


