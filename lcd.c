#include <stdint.h>
#include <stdbool.h>
#include "hw_memmap.h"
#include "sysctl.h"
#include "gpio.h"
#include "systick.h"
#include "lcd.h"

//======================== Constants ===================================
static const uint8_t COMMAND = 0;           // select command register
static const uint8_t DATA = 1;              // select data register

//======================== Variables ===================================
static uint8_t DATA_PINS = LCD_D4 | LCD_D5 | LCD_D6 | LCD_D7;

//=================== Function Prototypes ==============================
static void MCU_Pins_Config(void);
static void Set_Address(uint8_t row, uint8_t column);
static void Lcd_Send(uint8_t value, uint8_t type);

//======================= Implementation ================================

static void MCU_Pins_Config(void) {
    SysCtlPeripheralEnable(LCD_DATA_PORT_ENABLE);
    SysCtlPeripheralEnable(LCD_CONTROL_PORT_ENABLE);                                                // enable ports

    while (!SysCtlPeripheralReady(LCD_DATA_PORT_ENABLE)) {}
    while (!SysCtlPeripheralReady(LCD_CONTROL_PORT_ENABLE)) {}                                      // check if peripherals access is enabled

    GPIOPadConfigSet(LCD_DATA_PORT, DATA_PINS, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
    GPIOPadConfigSet(LCD_CONTROL_PORT, (LCD_RS | LCD_EN), GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);    // specify output drive strength and set the pad for standard push-pull operation

    GPIODirModeSet(LCD_DATA_PORT, DATA_PINS, GPIO_DIR_MODE_OUT);
    GPIODirModeSet(LCD_CONTROL_PORT, (LCD_RS | LCD_EN), GPIO_DIR_MODE_OUT);                         // set direction of all pins as output

    GPIOPinWrite(LCD_DATA_PORT, DATA_PINS, 0x00);
    GPIOPinWrite(LCD_CONTROL_PORT, (LCD_RS | LCD_EN), 0x00);                                        // write logic low on all pins
    }

//==================================================

extern void Lcd_Init(void) {

    //Configure MCU pins wot work with LCD
    MCU_Pins_Config();

    // 1) Wait for more than 15 ms after power is applied
    wait_10ms(2);

    // 2) Write 0x03 to LCD and wait 5 ms
    Lcd_Send(0x00, COMMAND);          // upper nibble
    Lcd_Send(0x03, COMMAND);          // lower nibble
    delay_5ms();

    // 3) Write 0x03 to LCD and wait 1 ms
    Lcd_Send(0x00, COMMAND);          // upper nibble
    Lcd_Send(0x03, COMMAND);          // lower nibble
    delay_ms();

    // 4) Again write 0x03 to LCD and wait 1 ms
    Lcd_Send(0x00, COMMAND);          // upper nibble
    Lcd_Send(0x03, COMMAND);          // lower nibble
    delay_ms();

    // 5) Write 0x02 to LCD to enable 4-bit mode
    Lcd_Send(0x00, COMMAND);          // upper nibble
    Lcd_Send(0x02, COMMAND);          // lower nibble
    delay_ms();

    // 6) LCD is 4 bit interface, 2 lines, display, 5*7 dots char
    Lcd_Send(0b0010, COMMAND);          // upper nibble
    Lcd_Send(0b1000, COMMAND);          // lower nibble
    delay_ms();

    // 7) Display is off
    Lcd_Send(0b0000, COMMAND);          // upper nibble
    Lcd_Send(0b1000, COMMAND);          // lower nibble
    delay_ms();

    // 8) Display clear
    Lcd_Send(0b0000, COMMAND);          // upper nibble
    Lcd_Send(0b0001, COMMAND);          // lower nibble
    wait_ms(2);

    // 9) Set cursor direction
    Lcd_Send(0b0000, COMMAND);          // upper nibble
    Lcd_Send(0b0110, COMMAND);          // lower nibble
    delay_ms();

    // 10) enable display, cursor off
    Lcd_Send(0b0000, COMMAND);          // upper nibble
    Lcd_Send(0b1100, COMMAND);          // lower nibble
    delay_ms();
}

//====================================================

static void Lcd_Send(uint8_t value, uint8_t type) {

    uint8_t temp =0;

    temp = (value >> 0) & 1;
    if (temp == 1) {
            GPIOPinWrite(LCD_DATA_PORT, LCD_D4, LCD_D4);
    }else{
            GPIOPinWrite(LCD_DATA_PORT, LCD_D4, 0x00);
        }

    temp = (value >> 1) & 1;
    if (temp == 1) {
            GPIOPinWrite(LCD_DATA_PORT, LCD_D5, LCD_D5);
    }else{
            GPIOPinWrite(LCD_DATA_PORT, LCD_D5, 0x00);
        }

    temp = (value >> 2) & 1;
    if (temp == 1) {
            GPIOPinWrite(LCD_DATA_PORT, LCD_D6, LCD_D6);
    }else{
            GPIOPinWrite(LCD_DATA_PORT, LCD_D6, 0x00);
        }

    temp = (value >> 3) & 1;
    if (temp == 1) {
            GPIOPinWrite(LCD_DATA_PORT, LCD_D7, LCD_D7);
    }else{
            GPIOPinWrite(LCD_DATA_PORT, LCD_D7, 0x00);
        }


    if(type == COMMAND){
            GPIOPinWrite(LCD_CONTROL_PORT, LCD_RS, 0x00);
    }else{
            GPIOPinWrite(LCD_CONTROL_PORT, LCD_RS, LCD_RS);
        }

    delay_ms();

    GPIOPinWrite(LCD_CONTROL_PORT,LCD_EN, LCD_EN);
    delay_ms();
    GPIOPinWrite(LCD_CONTROL_PORT,LCD_EN, 0x00);
    delay_ms();


}

//=====================================================

extern void Lcd_Cmd(uint8_t cmd){

    uint8_t value = 0, tmp= 0;

    switch(cmd){
    case LCD_CLEAR:

        break;

    case LCD_CURSOR_OFF:
        value = 0b00001100;
        break;

    case LCD_UNDERLINE_ON:
        value = 0b00001110;
        break;

    case LCD_BLINK_CURSOR_ON:
        value = 0b00001101;
        break;

    case LCD_FIRST_ROW:
        value = 0b10000000;
        break;

    default:                            // LCD_SECOND_ROW
        value = 0b10000000 + 0x40;
    }

    if(LCD_CLEAR != cmd){
        tmp = value >> 4;

        Lcd_Send(tmp, COMMAND);         // upper nibble
        Lcd_Send(value, COMMAND);       // lower nibble
        delay_ms();
    }

    if(LCD_CLEAR == cmd){
        Lcd_Send(0b0000, COMMAND);
        Lcd_Send(0b0001, COMMAND);
        wait_ms(2);

    }
}

//======================================================

static void Set_Address(uint8_t row, uint8_t column){

    uint8_t address = 0, tmp = 0;

    if((row == 1) | (row == LCD_FIRST_ROW)){
        address = 0b10000000 + (column-1);
    }else{
        address = 0b10000000 + 0x40 + (column-1);
    }

    tmp = address >> 4;

    Lcd_Send(tmp, COMMAND);             // uppwer nibble
    Lcd_Send(address, COMMAND);         // lower nibble
    delay_ms();
}

//======================================================

extern void Lcd_Chr_Cp(uint8_t out_char) {

    uint8_t tmp=0;
    tmp = out_char >> 4;

    Lcd_Send(tmp, DATA);                // upper nibble
    Lcd_Send(out_char, DATA);           // lower nibble
    delay_10ms();

}

//======================================================

extern void Lcd_Chr(uint8_t row, uint8_t column, uint8_t out_char){

    Set_Address(row, column);
    Lcd_Chr_Cp(out_char);

}

//======================================================

extern void Lcd_Text_Cp(uint8_t *text){

    while(*text != '\0') {
        Lcd_Chr_Cp(*text);
        text++;
    }
}

//======================================================

extern void Lcd_Text(uint8_t row, uint8_t column, uint8_t *text){

    Set_Address(row, column);
    Lcd_Text_Cp(*text);
}
