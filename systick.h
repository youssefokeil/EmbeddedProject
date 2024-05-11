<<<<<<< HEAD
/*
 * systick.h
 * Header file for SysTick module
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "stdint.h"

/*******************************************************************************
 *                      Preprocessor Macros & Configuration                    *
 *******************************************************************************/
#define SYSTICK_USE 1       /* Set to 1 to enable the use of SysTick delay */
#define NULL_PTR (void *)0
#define MAX 0x00FFFFFF      /* Maximum value of the Reload Register */

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void Systick_setCallBack(void(*a_ptr)(void));
void delay_ms(void); // Delay in milliseconds
void delay_5ms(void); // Delay in 5 milliseconds
void delay_10ms(void); // Delay in 10 milliseconds
void SysTick_Init(void); // Initialize SysTick
void delay_s(void); // Delay in seconds
void wait_s(uint32_t num); // Wait for specified number of seconds
void wait_ms(uint32_t num); // Wait for specified number of milliseconds
void wait_5ms(uint32_t num); // Wait for specified number of 5 milliseconds
void wait_10ms(uint32_t num); // Wait for specified number of 10 milliseconds

#endif /* SYSTICK_H_ */
=======
/*
 * systick.h
 * Header file for SysTick module
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "stdint.h"

/*******************************************************************************
 *                      Preprocessor Macros & Configuration                    *
 *******************************************************************************/
#define SYSTICK_USE 1       /* Set to 1 to enable the use of SysTick delay */
#define NULL_PTR (void *)0
#define MAX 0x00FFFFFF      /* Maximum value of the Reload Register */

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void Systick_setCallBack(void(*a_ptr)(void));
void delay_ms(void); // Delay in milliseconds
void delay_5ms(void); // Delay in 5 milliseconds
void delay_10ms(void); // Delay in 10 milliseconds
void SysTick_Init(void); // Initialize SysTick
void delay_s(void); // Delay in seconds
void wait_s(uint32_t num); // Wait for specified number of seconds
void wait_ms(uint32_t num); // Wait for specified number of milliseconds
void wait_5ms(uint32_t num); // Wait for specified number of 5 milliseconds
void wait_10ms(uint32_t num); // Wait for specified number of 10 milliseconds

#endif /* SYSTICK_H_ */
>>>>>>> 407b50c (Initialize UART5)
