
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
	float h;
	int i=1;
	char buffer[100];
  unsigned char B;
	float c;
	char y;
GPS_GET_LINE(buffer);
	if(*buffer != NULL){
for(i=0;i<100;i++){
	B = buffer[i];
	if(buffer[i]!=0)
	WRITE_UART(B);
	
}}
c = extractlatitudes(buffer);
	y = extractlatitudesdirection(buffer);
	WRITE_UART(y);


}
}
