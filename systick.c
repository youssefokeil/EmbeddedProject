#include "systick.h"
#include "stdint.h"
#include "tm4c123gh6pm.h"

static volatile void (*g_callBackPtrSystick)(void) = NULL_PTR;

void SysTick_Init(void) {
    // Max Reload_value = 0x00FFFFFF --> 0.2 sec
    // Reload_value = (required_delay * sysClk(80M)) - 1
    NVIC_ST_CTRL_R = 0; // Disable SysTick during setup
    NVIC_ST_RELOAD_R = MAX - 1; // Set reload value for desired delay
    NVIC_ST_CURRENT_R = 0; // Clear current register and COUNTFLAG
    // Enable SysTick with core clock and interrupts
    NVIC_ST_CTRL_R = 0x05; // Enable SysTick, select core clock, and enable interrupts
}

void delay_s(void) {
    uint8_t i;
    for (i = 0; i < 5; i++) { // Repeat delay for 5 times (1 second)
        SysTick_Init(); // Initialize SysTick with desired delay
        while ((NVIC_ST_CTRL_R & 0x10000) == 0); // Wait until COUNTFLAG is set
    }
}

void wait_s(uint32_t num) {
    unsigned long k;
    for (k = 0; k < num; k++) { // Repeat delay_s() for specified number of seconds
        delay_s();
    }
}

void delay_ms(void) {
    NVIC_ST_CTRL_R = 0; // Disable SysTick during setup
    NVIC_ST_RELOAD_R = 80000 - 1; // Set reload value for 1 ms delay
    NVIC_ST_CURRENT_R = 0; // Clear current register and COUNTFLAG
    NVIC_ST_CTRL_R = 5; // Enable SysTick with core clock and interrupts (101 = 5)
    while ((NVIC_ST_CTRL_R & 0x10000) == 0); // Wait until COUNTFLAG is set
}

void wait_ms(uint32_t num) {
    unsigned long k;
    for (k = 0; k < num; k++) { // Repeat delay_ms() for specified number of milliseconds
        delay_ms();
    }
}

void delay_5ms(void) {
    NVIC_ST_CTRL_R = 0; // Disable SysTick during setup
    NVIC_ST_RELOAD_R = (400000) - 1; // Set reload value for 5 ms delay
    NVIC_ST_CURRENT_R = 0; // Clear current register and COUNTFLAG
    NVIC_ST_CTRL_R = 5; // Enable SysTick with core clock and interrupts (101 = 5)
    while ((NVIC_ST_CTRL_R & 0x10000) == 0); // Wait until COUNTFLAG is set
}

void wait_5ms(uint32_t num) {
    unsigned long k;
    for (k = 0; k < num; k++) { // Repeat delay_5ms() for specified number of 5 milliseconds
        delay_5ms();
    }
}

void delay_10ms(void) {
    NVIC_ST_CTRL_R = 0; // Disable SysTick during setup
    NVIC_ST_RELOAD_R = (800000) - 1; // Set reload value for 10 ms delay
    NVIC_ST_CURRENT_R = 0; // Clear current register and COUNTFLAG
    NVIC_ST_CTRL_R = 5; // Enable SysTick with core clock and interrupts (101 = 5)
   while ((NVIC_ST_CTRL_R & 0x10000) == 0); // Wait until COUNTFLAG is set
}

void wait_10ms(uint32_t num) {
    unsigned long k;
    for (k = 0; k < num; k++) { // Repeat delay_10ms() for specified number of 10 milliseconds
        delay_10ms();
    }
}

void SysTick_Handler(void) {
    if (g_callBackPtrSystick != NULL_PTR) {
        // Call the callback function for SysTick interrupt
        (*g_callBackPtrSystick)();
    }
}

void Systick_setCallBack(void (*a_ptr)(void)) {
    g_callBackPtrSystick = (volatile void (*)(void))a_ptr;
}
