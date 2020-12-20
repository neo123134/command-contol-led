#ifndef LCD_H_
#define LCD_H_



#define RS              GPIO_PIN_0 // RS
#define RW              GPIO_PIN_1// RW
#define E               GPIO_PIN_2// E
#define LCDPORT         GPIO_PORTB_BASE/
#define highpin         GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7 // D4 D5 D6 D7




void has_lcd_4bitsetup();
void has_lcd_erase();
void has_lcd_write(uint8_t line , uint8_t column,char str[]);
void has_lcd_position(uint8_t line , uint8_t column);





#endif /* LCD_H_*/

