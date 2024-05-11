<<<<<<< HEAD
#ifndef GPIO_H
#define GPIO_H

#include "tm4c123gh6pm.h"
#define GPIO_LOCK_KEY           0x4C4F434B  
#define RED_LED 0x02
#define BLUE_LED 0x04
#define GREEN_LED 0x08
#define sw1 0x01
#define sw2 0x10
#define sw12_mask 0x11
#define LED_mask 0x0E

void SWITCH_INIT(void);

void LED_INIT(void);

unsigned char sw1_read(void);
unsigned char sw2_read(void);
void LED_ON(unsigned char led);
#endif
=======
#ifndef GPIO_H
#define GPIO_H

#include "tm4c123gh6pm.h"
#define GPIO_LOCK_KEY           0x4C4F434B  
#define RED_LED 0x02
#define BLUE_LED 0x04
#define GREEN_LED 0x08
#define sw1 0x01
#define sw2 0x10
#define sw12_mask 0x11
#define LED_mask 0x0E

void SWITCH_INIT(void);

void LED_INIT(void);

unsigned char sw1_read(void);
unsigned char sw2_read(void);
void LED_ON(unsigned char led);
#endif
>>>>>>> 407b50c (Initialize UART5)
