
#include "CALC_DISP.h"
#include "GPIO_DRIVER.H"
#include "UART_INIT.h"
#include <math.h>
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
total_distance=150;
 
if (total_distance>=100){
	 LED_ON(RED_LED);
}
}
}









