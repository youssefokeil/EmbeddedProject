#include"LCD.h"
/*****************************************************************************/

/*
 -------------                 ------------
 | TM4C123   |                 |   LCD    |
 |           |                 |          |
 |        PB7|---------------->|D7        |
 |        PB6|---------------->|D6        |
 |        PB5|---------------->|D5        |
 |        PB4|---------------->|D4        |
 |        PB3|---------------->|D3        |
 |        PB2|---------------->|D2        |
 |        PB1|---------------->|D1        |
 |        PB0|---------------->|D0        |
 |           |                 |          |
 |        PE5|---------------->|E         |
 |        PE4|---------------->|RW        |
 |        PE3|---------------->|RS        |
 -------------                 ------------
 */
 
/*****************************************************************************/


/*
int main ()
{

	LCD_Init();
	LCD_Command(lcd_SetCursor);
	
	LCD_String("HELLO,BRO123",12);
	
	LCD_Command(lcd_Clear);
	
}


*/

void LCD_Init(void)
{

  SYSCTL_RCGCGPIO_R |= 0x12;            //Enable clock to PORTB and PORTE  
  
  while ((SYSCTL_PRGPIO_R &0x12)==0);   //wait for clock to be setted
  
  
  GPIO_PORTB_LOCK_R   = 0x4C4F434B;     //unlock GPIO port B
  GPIO_PORTB_CR_R    |= 0xFF;           //Allow settings for all pins of PORTB
  GPIO_PORTB_AMSEL_R  = 0x00;           //disable analog on (PB0-PB7)
  GPIO_PORTB_DIR_R    = 0xFF;           //(PB0-PB7)are used as digital output
  GPIO_PORTB_PCTL_R   = 0x00000000;     //PCTL GPIO on (PB0-PB7)
  GPIO_PORTB_AFSEL_R  = 0x00;           //diable alt funct on (PB0-PB7)
  GPIO_PORTB_DEN_R    = 0xFF;           //Set PORTB as digital pins
  GPIO_PORTB_DATA_R   = 0x00;
  
  
  GPIO_PORTE_LOCK_R   = 0x4C4F434B;     //unlock GPIO port E
  GPIO_PORTE_CR_R    |= 0x38;           //Allow settings for pins of PORTE (PE3-PE5)
  GPIO_PORTE_AMSEL_R &= 0xC7;           //disable analog on (PE3-PE5)
  GPIO_PORTE_DIR_R   |= 0x38;           //(PE3-PE5) are used as digital output
  GPIO_PORTE_PCTL_R   = 0x00000000;     //PCTL GPIO on (PE3-PE5)
  GPIO_PORTE_AFSEL_R &= 0xC7;           //diable alt funct on (PE3-PE5)
  GPIO_PORTE_DEN_R   |= 0x38;           //Set PORTE as digital pins (PE3-PE5)
  GPIO_PORTE_DATA_R  &= 0xC7;
  
  LCD_Command(lcd_Clear);               // clear LCD
  _delay_ms(20);
  
  LCD_Command(lcd_Home);                // transmit 8_bits to LCD
  _delay_ms(15);
  
  LCD_Command(lcd_FunctionSet8bit);     // transmit 8_bits to LCD
  _delay_ms(15);
  
  LCD_Command(lcd_Wakeup);              // Wake up LCD
  _delay_ms(15);
  
  LCD_Command(lcd_EntryMode);           // increment cursor on LCD
  _delay_ms(20);
  
  LCD_Command(lcd_Turnondisplay);       // disply on LCD
  _delay_ms(15);
	
    
}


void LCD_Command(u8 cmd)
{
	
	GPIO_PORTE_DATA_R |= 0x00;
	GPIO_PORTB_DATA_R = cmd;
	
	GPIO_PORTE_DATA_R |= 0x20;
	_delay_ms(10);
	GPIO_PORTE_DATA_R &= 0xC7;
}


void LCD_Char(u8 data)
{
	
	GPIO_PORTE_DATA_R |= 0x08;	
	GPIO_PORTB_DATA_R = data;
	
	GPIO_PORTE_DATA_R |= 0x20;
	_delay_ms(10);
	GPIO_PORTE_DATA_R &= 0xC7;
}

void LCD_String(u8* String, u8 Index,float distance)
{
	int dis=(int)distance;
	int Units = (dis % 10);	
	int Tenth = (dis % 100)/10;
	int Hundereds = (dis % 1000)/100;
	u8 iteration=0;

	for (iteration=0; iteration< Index ; iteration++)
	{
		/* Write Character on LCD */
		LCD_Char(String[iteration]);

		/* Delay to let the LCD show the character */
		_delay_ms(10);
	}
	
	/////////////////////////
	LCD_Char(Hundereds+'0');
	_delay_ms(10);
	LCD_Char(Tenth+'0');
	_delay_ms(10);
	LCD_Char(Units+'0');
	_delay_ms(10);


}

void _delay_ms(u8 mill_sec)
{
	u16 i,j;
	for(i=0;i<mill_sec;i++)
	for(j=0;j<3180;j++)
	{}
}



