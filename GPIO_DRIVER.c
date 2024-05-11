<<<<<<< HEAD
#include"GPIO_DRIVER.h"


void SWITCH_INIT(void){
SYSCTL_RCGCGPIO_R |=0x20;
	while((SYSCTL_PRGPIO_R & 0x20) ==0);
GPIO_PORTF_LOCK_R =GPIO_LOCK_KEY; // unlocking the PORTS
GPIO_PORTF_CR_R |=sw12_mask;   // CR is responsible for allowing changes for the switches 
GPIO_PORTF_DEN_R |=sw12_mask;          
GPIO_PORTF_DIR_R &=(~sw12_mask);       // the switches(PF0,PF4) are  inputs 
GPIO_PORTF_PUR_R &=(~sw12_mask); //switches are pulldown 
GPIO_PORTF_AFSEL_R	&= (~sw12_mask);
GPIO_PORTF_DATA_R  	|=sw12_mask;    //initializing the data of switches (1 BECAUSE SWITCHES ARE PULL down logic)
GPIO_PORTF_AMSEL_R	&= (~sw12_mask);		
GPIO_PORTF_PCTL_R	&= (~sw12_mask);     
}

void LED_INIT(void){
SYSCTL_RCGCGPIO_R |=0x20;
	while((SYSCTL_PRGPIO_R & 0x20) ==0);
GPIO_PORTF_LOCK_R =GPIO_LOCK_KEY; // unlocking the PORTS
GPIO_PORTF_CR_R |=LED_mask;   // CR is responsible for allowing changes for the LEDS 
GPIO_PORTF_DEN_R |=LED_mask;          
GPIO_PORTF_DIR_R |=LED_mask;       //  the leds(1,2,3) are outputs
GPIO_PORTF_AFSEL_R	&= (~LED_mask);
GPIO_PORTF_DATA_R  	&= (~LED_mask);    //initializing the data of leds
GPIO_PORTF_AMSEL_R	&= (~LED_mask);		
GPIO_PORTF_PCTL_R	&= (~LED_mask);     
}

unsigned char sw1_read(void){
	return GPIO_PORTF_DATA_R &0x01;
}
unsigned char sw2_read(void){
	return GPIO_PORTF_DATA_R &0x10;
}
void LED_ON(unsigned char led){
	GPIO_PORTF_DATA_R  	|= led;
}

void LED_OFF(unsigned char led){
GPIO_PORTF_DATA_R  	&= (~LED_mask);
}

=======
#include"GPIO_DRIVER.h"


void SWITCH_INIT(void){
SYSCTL_RCGCGPIO_R |=0x20;
	while((SYSCTL_PRGPIO_R & 0x20) ==0);
GPIO_PORTF_LOCK_R =GPIO_LOCK_KEY; // unlocking the PORTS
GPIO_PORTF_CR_R |=sw12_mask;   // CR is responsible for allowing changes for the switches 
GPIO_PORTF_DEN_R |=sw12_mask;          
GPIO_PORTF_DIR_R &=(~sw12_mask);       // the switches(PF0,PF4) are  inputs 
GPIO_PORTF_PUR_R &=(~sw12_mask); //switches are pulldown 
GPIO_PORTF_AFSEL_R	&= (~sw12_mask);
GPIO_PORTF_DATA_R  	|=sw12_mask;    //initializing the data of switches (1 BECAUSE SWITCHES ARE PULL down logic)
GPIO_PORTF_AMSEL_R	&= (~sw12_mask);		
GPIO_PORTF_PCTL_R	&= (~sw12_mask);     
}

void LED_INIT(void){
SYSCTL_RCGCGPIO_R |=0x20;
	while((SYSCTL_PRGPIO_R & 0x20) ==0);
GPIO_PORTF_LOCK_R =GPIO_LOCK_KEY; // unlocking the PORTS
GPIO_PORTF_CR_R |=LED_mask;   // CR is responsible for allowing changes for the LEDS 
GPIO_PORTF_DEN_R |=LED_mask;          
GPIO_PORTF_DIR_R |=LED_mask;       //  the leds(1,2,3) are outputs
GPIO_PORTF_AFSEL_R	&= (~LED_mask);
GPIO_PORTF_DATA_R  	&= (~LED_mask);    //initializing the data of leds
GPIO_PORTF_AMSEL_R	&= (~LED_mask);		
GPIO_PORTF_PCTL_R	&= (~LED_mask);     
}

unsigned char sw1_read(void){
	return GPIO_PORTF_DATA_R &0x01;
}
unsigned char sw2_read(void){
	return GPIO_PORTF_DATA_R &0x10;
}
void LED_ON(unsigned char led){
	GPIO_PORTF_DATA_R  	|= led;
}

void LED_OFF(unsigned char led){
GPIO_PORTF_DATA_R  	&= (~LED_mask);
}

>>>>>>> 407b50c (Initialize UART5)
