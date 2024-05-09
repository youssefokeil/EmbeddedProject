#ifndef LCD_H_
#define LCD_H_

//==================== Header Files ====================
#include "sysctl.h"
#include "gpio.h"
#include <stdint.h>
#include <stdbool.h>

//==================== Macro ===========================
//---------------
//Data port
#define LCD_DATA_PORT               GPIO_PORTB_DATA_R     // Port B (1)

//define DATA pins

#define LCD_D4                      GPIO_PIN_4          // B4:B7
#define LCD_D5                      GPIO_PIN_5
#define LCD_D6                      GPIO_PIN_6
#define LCD_D7                      GPIO_PIN_7

#define LCD_DATA_PORT_ENABLE        SYSCTL_PERIPH_GPIOB // (2)

//Control port
#define LCD_CONTROL_PORT            GPIO_PORTA_DATA_R     // Port A

#define LCD_RS                      GPIO_PIN_2          // A2
#define LCD_EN                      GPIO_PIN_3          // A3

#define LCD_CONTROL_PORT_ENABLE     SYSCTL_PERIPH_GPIOA

// Available LCD Commands
// ----------------------
#define LCD_CLEAR                   1   // Clear display
#define LCD_CURSOR_OFF              2   // Turn off cursor
#define LCD_UNDERLINE_ON            3   // Underline cursor on
#define LCD_BLINK_CURSOR_ON         4   // Blink cursor on
#define LCD_FIRST_ROW               5   // Move cursor to the 1st row
#define LCD_SECOND_ROW              6   // Move cursor to the 2nd row

//=================== Function Prototypes ===================

extern void Lcd_Init(void);                                         // Initialize ports which will be used
extern void Lcd_Cmd(uint8_t cmd);                                   // Perform Commands from above using its digit
extern void Lcd_Chr(uint8_t row, uint8_t column, uint8_t out_char); // Print character in specific location. Note: Display is 2 rows and 16 columns
extern void Lcd_Chr_Cp(uint8_t out_char);                           // Print character in the succeeding slot.
extern void Lcd_Text(uint8_t row, uint8_t column, uint8_t *text);   // Print text. *text is pointer of a variable that stores multiple characters.
extern void Lcd_Text_Cp(uint8_t *text);                             // ""                          ""


//---------------------------------------------------------------
#endif // LCD_H_
