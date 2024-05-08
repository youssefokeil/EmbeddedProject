#include"UART_INIT.h"

void UART_INI(void){
	SYSCTL_RCGCUART_R |=0x01;
	SYSCTL_RCGCGPIO_R |= 0x01;
	GPIO_PORTA_LOCK_R =GPIO_LOCK_KEY; // unlocking the PORTS
	GPIO_PORTA_CR_R |=0x003;
	UART0_CTL_R=0;
	UART0_IBRD_R=520;
	UART0_FBRD_R=53;
	UART0_LCRH_R=0x070; // 8bit,no parity bits, one stop,FIFOs
	UART0_CTL_R|=0x01; //enabling the UART, TX, RX
	GPIO_PORTA_DEN_R|=0x03;
	GPIO_PORTA_AFSEL_R|=0x003;
	GPIO_PORTA_PCTL_R|=0x011;
	GPIO_PORTA_AMSEL_R&=(~0x03); //enable transmit and rescieve and enable uart end of config
}
uint8_t CHECK_UART_READ_DATA(void){
	if((UART0_FR_R &(0x01<<4))==0)return 1;    //if not empty
	else return 0;													 //else empty
}


 char READ_UART(void){
	while(CHECK_UART_READ_DATA()==0);
	return((char)(UART0_DR_R&(0xFF))); //uint_8 ==>>> unsigned char modified
}

void WRITE_UART(char data){
	while((UART0_FR_R&(0x01<<5))!=0);
	UART0_DR_R=data;
}/*
unsigned char* code_sent(unsigned char* code){
	
	int flag=0;
	int counter=0;
	while(1){
unsigned char test=(unsigned char)READ_UART;
		WRITE_UART(test);
	if(test=='$')
		flag++;
	if(flag==2)
		return code;	
	else
		code[counter]=test;
	}
*/
 void *GPS_GET_LINE( char *buffer){
	//uint8_t buffer[82];    				//longest nema massege is 82
	 char read_ch;			
	int i=1;
	//begins saving data when reads $
	do{
		read_ch=READ_UART();
		WRITE_UART(read_ch);
	}while(read_ch !='$');
	buffer[0]=read_ch;
	
	// taking a nema massege from gps
	while(i<82){
		read_ch=READ_UART();
		WRITE_UART(read_ch);
		if(read_ch !='$')								// doesn't take newlines
		{
			buffer[i]=read_ch;
			i++;
		}
		else{
			break;
		}
	}
}
