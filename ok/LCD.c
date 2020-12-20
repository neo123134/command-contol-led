#include "LCD.h"
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_gpio.h"
#include "driverlib/pin_map.h"
\\


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void has_lcd_erase()//clear the text in LCD
{
    has_lcd_sendcommand(0x01);
    SysCtlDelay(1000);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void has_lcd_write(uint8_t line , uint8_t column,char str[])//write the information in a select row and col
{
    has_lcd_position(line,column);
    int i=0;
    while((str[i])!=0)
    {
        has_lcd_sendchar(str[i]);
    i++;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void has_lcd_position(uint8_t line , uint8_t column)// set the position of the cursor
{
    if(line==1)
    {
        has_lcd_sendcommand(0x80+(column-1));
    }
    else
    {
        has_lcd_sendcommand(0xc0+(column-1));
    }
  SysCtlDelay(100);

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void has_lcd_4bitsetup()//enable all the pin to be output pin
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    GPIOPinTypeGPIOOutput(LCDPORT,0x0ff);
          SysCtlDelay(5000000);
          GPIOPinWrite(LCDPORT, RW,  0x00 );
          SysCtlDelay(5000000);
          GPIOPinWrite(LCDPORT, RS,  0x00 );

          GPIOPinWrite(LCDPORT, highpin,  0x30 );
          GPIOPinWrite(LCDPORT, E, 0x04);
          SysCtlDelay(50000);
          GPIOPinWrite(LCDPORT, E, 0x00);

          SysCtlDelay(50000);

          GPIOPinWrite(LCDPORT, highpin,  0x30 );
          GPIOPinWrite(LCDPORT, E, 0x04);
          SysCtlDelay(50000);
          GPIOPinWrite(LCDPORT, E, 0x00);

          SysCtlDelay(50000);

          GPIOPinWrite(LCDPORT,highpin,  0x30 );
          GPIOPinWrite(LCDPORT, E, 0x04);
          SysCtlDelay(50000);
          GPIOPinWrite(LCDPORT, E, 0x00);

          SysCtlDelay(50000);

          GPIOPinWrite(LCDPORT, highpin,  0x20 );
          GPIOPinWrite(LCDPORT, E, 0x04);
          SysCtlDelay(50000);
          GPIOPinWrite(LCDPORT, E, 0x00);

          SysCtlDelay(50000);

          has_lcd_sendcommand(0x28);
          has_lcd_sendcommand(0x06);
          has_lcd_sendcommand(0x0c);

          SysCtlDelay(50000);

}



