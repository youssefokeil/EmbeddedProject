#ifndef UART_INI_H
#define UART_INI_H

#include"tm4c123gh6pm.h"
#include"STD_TYPES.h"
void UART_INI(void);
unsigned char READ_UART(void);
void WRITE_UART(char h);
//unsigned char* code_sent(unsigned char* code);
uint8_t *GPS_GET_LINE(void);   	
#endif