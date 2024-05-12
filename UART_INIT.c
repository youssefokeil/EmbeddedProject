<<<<<<< HEAD
#include"UART_INIT.h"

void UART_INIT(void){
    // For GPS
	SYSCTL_RCGCUART_R |=0x20; //1)UART5 =2^5
	SYSCTL_RCGCGPIO_R |= 0x10; //2) GpioE= 2^4
	while((SYSCTL_PRGPIO_R&0x10)==0);
	GPIO_PORTE_LOCK_R =GPIO_LOCK_KEY; // unlocking the PORTS
	GPIO_PORTE_AFSEL_R |=0x030; //3) AFSEL pe4,pe5
	GPIO_PORTE_PCTL_R |= 0x0110000; //4) PCTL to pe4, pe5?
     //
	UART5_CTL_R=~(0x01);  // 1.1) Disable UARTEN
	UART5_IBRD_R=520;      // (80MHz/16*9600)=520
	UART5_FBRD_R=53;
	UART5_LCRH_R=0x070; // 1.4)8bit,no parity bits, one stop,FIFOs
	UART5_CTL_R|=0x301; //1.5) enabling the UART, TX, RX
	GPIO_PORTE_DEN_R|=0x030; // PE4, PE5 Digital enable
	GPIO_PORTE_AMSEL_R=~(0x30); // Disable analog function PE4, PE5

	//Laptop
	SYSCTL_RCGCUART_R |=0x01; //1)UART1 =2^0
	SYSCTL_RCGCGPIO_R |= 0x01; //2) GpioA= 2^0
	while((SYSCTL_PRGPIO_R&0x01)==0);

	GPIO_PORTA_AFSEL_R |=0x003; //3) alternate function AFSEL PA1,PA0
	GPIO_PORTA_PCTL_R |= 0x011; //4) PCTL to PA0, PA1
	     //
	UART0_CTL_R=~(0x01);  // 1.1) Disable UARTEN
	UART0_IBRD_R=520;      // (80MHz/16*9600)=520
	UART0_FBRD_R=53;
	UART0_LCRH_R=0x070; // 1.4)8bit,no parity bits, one stop,FIFOs
	UART0_CTL_R|=0x301; //1.5) enabling the UART, TX, RX
	GPIO_PORTA_DEN_R|=0x003; // PA0, PA1 Digital enable
	GPIO_PORTA_AMSEL_R=~(0x30); // Disable analog function PA1, PA0

}
uint8_t CHECK_UART_READ_DATA(void){
	if((UART0_FR_R &(0x01<<4))==0)return 1;    //if not empty
	else return 0;													 //else empty
}


 char READ_UART(void){
	while(UART5_FR_R &(0x01<<4))==0);
	return((char)(UART5_DR_R&(0xFF))); //uint_8 ==>>> unsigned char modified
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
=======/*


>>>>>>> 407b50c (Initialize UART5)
