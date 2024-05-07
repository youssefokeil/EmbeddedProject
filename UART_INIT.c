#include"UART_INIT.h"
/////////////////////////////////////////PortD uart2
void UART_INI(void){
	SYSCTL_RCGCUART_R |=0x08;  
	SYSCTL_RCGCGPIO_R |= 0x08;
	GPIO_PORTD_LOCK_R =GPIO_LOCK_KEY; // unlocking the PORTS
	GPIO_PORTD_CR_R |=0xc0;
	UART2_CTL_R=0;
	UART2_IBRD_R=520;
	UART2_FBRD_R=53;
	UART2_LCRH_R=0x070; // 8bit,no parity bits, one stop,FIFOs
	UART2_CTL_R|=0x01; //enabling the UART, TX, RX
	GPIO_PORTD_DEN_R|=0xc0;
	GPIO_PORTD_AFSEL_R|=0xc0;
	GPIO_PORTD_PCTL_R|=0x1100 0000;
	GPIO_PORTD_AMSEL_R&=(~0xc0); //enable transmit and recieve and enable uart end of config
}
//////////////////////////////////////////////


uint8_t CHECK_UART_READ_DATA(void){
	if((UART0_FR_R &(0x01<<4))==0)return 1;    //if not empty
	else return 0;													 //else empty
}


unsigned char READ_UART(void){
	while(CHECK_UART_READ_DATA()==0);
	return((unsigned char)(UART0_DR_R&(0xFF))); //uint_8 ==>>> unsigned char modified
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
 uint8_t *GPS_GET_LINE(void){
	uint8_t buffer[82];    				//longest nema massege is 82
	uint8_t read_ch;			
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
		if(read_ch !=0 &&read_ch !='$')								// doesn't take newlines
		{
			buffer[i]=read_ch;
			i++;
		}
		else{
			break;
		}
	}
	return buffer;
}
