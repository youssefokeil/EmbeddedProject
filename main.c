<<<<<<< HEAD
#include "decoder.h"
#include "CALC_DISP.h"
#include "GPIO_DRIVER.H"
#include "UART_INIT.h"
#include <math.h>
#include "NMEA.h"
//#include <TM4C123.h>





double Start_long; 
double Start_lat; 

double current_long ;
double current_lat ;

double prev_long;
double prev_lat;


int inc_distance;
int total_distance;




int main (void){
	 
	
	SWITCH_INIT();
	LED_INIT();
	UART_INI();
	
	
	while(1){
		//---this whole commented section will be used once we finish all drivers in second milestone---
		//---there is some documentaion to understand the flow of the function---
		
		/*
		//Start_long =READ_UART(); 			 				//we will read constant coordinateof starting position once tiva is turned on  
		//Start_lat =READ_UART();  

		current_long = Start_long;  						// assign current position as starting position
		current_lat = Start_lat;

		total_distance =0; 											// intialize the total distance

		while (total_distance<100){    
		
		prev_lat = current_lat;  								// we need to update our cordinates without losing the prev cordinates
		prev_long = current_long;
		
		// delay 2 seconds using systick 				// delay to wait for tiva c to change position

		//current_long =READ_UART();						// we update current position 
		//current_lat =READ_UART();  

		 inc_distance = calc_displacment(prev_lat, prev_long, current_lat, current_long, 'm'); // we measure the small distance between current and prev position
		
		 total_distance += inc_distance; 				// we add inc displacment to total distance
   		
     		 if(sw1_read()){						//this function  should be edited to be implemented using interrupts
		 LED_ON(RED_LED);
		 break;
		 }
}
*/

//this is just a driver to test if there is any errors
/*
total_distance=150;
 
if (total_distance>=100){
	 LED_ON(GREEN_LED);
}*/
float a;
char buffer[100];
char copy[100];
char x;
char y;
float b;
 GPS_GET_LINE(buffer);
 refill(buffer,copy);
 y=getlongitudeDirection(copy);
  refill(buffer,copy);
 x=getLatitudeDirection(copy);
  refill(buffer,copy);
 a=getLatitude(copy);
  refill(buffer,copy);
 b=getlongitude(copy);
  refill(buffer,copy);
 WRITE_UART(y);
 WRITE_UART(x);
 /*for(i=0;i<100;i++)
 {
	 if(buffer[i]!=0)
	 WRITE_UART(buffer[i]);
 }*/
WRITE_UART('X');
	}
	

}








=======
#include "decoder.h"
#include "CALC_DISP.h"
#include "GPIO_DRIVER.H"
#include "UART_INIT.h"
#include <math.h>
#include "NMEA.h"
//#include <TM4C123.h>







double Start_long; 
double Start_lat; 

double current_long ;
double current_lat ;

double prev_long;
double prev_lat;


int inc_distance;
int total_distance;
void RGB_SetOutput(unsigned char data){
    GPIO_PORTF_DATA_R |= data;
}

void RGB_ClearOutput(unsigned char data){
    GPIO_PORTF_DATA_R &= data;
}
void UART_OutChar(char data){
    while((UART0_FR_R & 0x20)!=0); // wait for FIFO in transmit TXFF to not be equal 0, not full, to avoid OE error
    UART0_DR_R= data;
    }
void UART_OutString(char *pt){
    while(*pt){
        UART_OutChar(*pt);
        pt++;
    }
}

int main (void){
	 
	
	SWITCH_INIT();
	LED_INIT();
	UART_INIT();
	RGB_SetOutput(0x02);
	
	while(1){
		//---this whole commented section will be used once we finish all drivers in second milestone---
		//---there is some documentaion to understand the flow of the function---
		
		/*
		//Start_long =READ_UART(); 			 				//we will read constant coordinateof starting position once tiva is turned on  
		//Start_lat =READ_UART();  

		current_long = Start_long;  						// assign current position as starting position
		current_lat = Start_lat;

		total_distance =0; 											// intialize the total distance

		while (total_distance<100){    
		
		prev_lat = current_lat;  								// we need to update our cordinates without losing the prev cordinates
		prev_long = current_long;
		
		// delay 2 seconds using systick 				// delay to wait for tiva c to change position

		//current_long =READ_UART();						// we update current position 
		//current_lat =READ_UART();  

		 inc_distance = calc_displacment(prev_lat, prev_long, current_lat, current_long, 'm'); // we measure the small distance between current and prev position
		
		 total_distance += inc_distance; 				// we add inc displacment to total distance
   		
     		 if(sw1_read()){						//this function  should be edited to be implemented using interrupts
		 LED_ON(RED_LED);
		 break;
		 }
}
*/

//this is just a driver to test if there is any errors
/*
total_distance=150;
 
if (total_distance>=100){
	 LED_ON(GREEN_LED);
}*/
float latitude_value=1.5;
char buffer[100];
char copy[100];
char latitude_direction;
char longitude_direction;
float longitude_value=1.5;
float temp_value;

 GPS_GET_LINE(buffer);
 UART_OutString(buffer);
 refill(buffer,copy);
 longitude_direction=getlongitudeDirection(copy);
  refill(buffer,copy);
 latitude_direction=getLatitudeDirection(copy);
  refill(buffer,copy);
 temp_value=getLatitude(copy);
 if(temp_value!=0)
     latitude_value=temp_value; //sets latitude if GPGGA
  refill(buffer,copy);
 temp_value=getlongitude(copy);
 if(temp_value!=0)
     longitude_value=temp_value;
  refill(buffer,copy);

  if(latitude_value>1.5){
     RGB_ClearOutput(~0x0E);
     RGB_SetOutput(0x06);
  }
 /*for(i=0;i<100;i++)
 {
	 if(buffer[i]!=0)
	 WRITE_UART(buffer[i]);
 }*/
	}
	

}








>>>>>>> 407b50c (Initialize UART5)
