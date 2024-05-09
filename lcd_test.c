#include <stdint.h>
#include <stdbool.h>
#include "sysctl.h"
#include "systick.h"
#include "lcd.h"

void Set_Clock_80(void){
    SysCtlClockSet(SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ | SYSCTL_USE_PLL | SYSCTL_SYSDIV_2_5);
}

void main(void) {

    Set_Clock_80();
    Lcd_Init();

    while (1){
        Lcd_Cmd(LCD_CLEAR);
        Lcd_Text(2,5, "Hello");
        Lcd_Text_Cp("!!");

        wait_s(2);

        Lcd_Cmd(LCD_CLEAR);
        Lcd_Cmd(LCD_UNDERLINE_ON);

        Lcd_Chr(1, 16, 'Q');
        Lcd_Chr(2, 1, 'H');
        Lcd_Chr_Cp(65);
        Lcd_Text_Cp("65");

        wait_s(2);
        Lcd_Cmd(LCD_CURSOR_OFF);
        wait_s(2);
    }


}
