<<<<<<< HEAD
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
=======
#include"UART_INIT.h"

void UART_INIT(void){
    //GPS interface
    SYSCTL_RCGCUART_R |=0x20; // 1)enable uart5, 2^5=32
    SYSCTL_RCGCGPIO_R |= 0X10; //2) enable portE, 2^4=16
    while((SYSCTL_PRGPIO_R & 0x10)==0); // delay for portE to be enabled
    GPIO_PORTE_AFSEL_R|=0x030; // 3) enable alternate function PE4, PE5
    GPIO_PORTE_PCTL_R=(GPIO_PORTE_PCTL_R&0xFF00FFFF)+0x00110000; //5) ENABLE UART PE5,PE$
    UART5_CTL_R&= ~0x0001;  //2.1) Disable UART
 	UART5_IBRD_R=520; //2.2) IBRD=int(80MHz/(16*9600))=520
	UART5_FBRD_R=53; //2.3) FBRD int(0.83333*64+0.5)=53
	UART5_LCRH_R=0x070; // 2.4) 8bit,no parity bits, one stop,enable FIFOs
	UART5_CTL_R|=0x301; //2.7) enabling the UART, TX, RX


	// for laptop interface
	SYSCTL_RCGCUART_R |=0x01; //1.1) enable UART0 2^0=1
	SYSCTL_RCGCGPIO_R |= 0x01; //1.2) enable PORTA 2^0=1
	while((SYSCTL_PRGPIO_R & 0x01)==0); //DELAY
	GPIO_PORTA_AFSEL_R|=0x03; //1.3) enable Alt function PA0, PA1
	GPIO_PORTA_PCTL_R=(GPIO_PORTA_PCTL_R & 0xFFFFFF00)+0x00000011; //1.5) enable UART in PA0, PA1
	GPIO_PORTA_DEN_R|= 0x000011; //enable digital I/O PA0, PA1
	UART0_CTL_R&= ~0x0001;  //2.1) Disable UART
	UART0_IBRD_R=520; //2.2) IBRD=int(80MHz/(16*9600))=520
	UART0_FBRD_R=53; //2.3) FBRD int(0.83333*64+0.5)=53
	UART0_LCRH_R=0x070; // 2.4) 8bit,no parity bits, one stop,enable FIFOs
	UART5_CTL_R|=0x301; //2.7) enabling the UART, TX, RX

}
uint8_t CHECK_UART_READ_DATA(void){
	if((UART1_FR_R &(0x01<<4))==0)return 1;    //if not empty
	else return 0;													 //else empty
}


 char READ_UART(void){
	while((UART1_FR_R & 0x10)!=0);
	return((char)(UART1_DR_R&(0xFF))); //uint_8 ==>>> unsigned char modified
}

void WRITE_UART(char data){
	while((UART1_FR_R & 0x20)!=0);
	UART1_DR_R=data;
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
>>>>>>> 407b50c (Initialize UART5)
