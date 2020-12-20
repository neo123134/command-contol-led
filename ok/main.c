#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_gpio.h"
#include "driverlib/interrupt.h"
#include "inc/hw_ints.h"
#include "Keypad.h"
#include "LCD.h"



int main()
{
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ| SYSCTL_OSC_MAIN);
    has_lcd_4bitsetup();
    KeyPad_Lcd_Setup();
    KeyPad_Setup();
    while(1)
    {
                KeyPad_wait();
                KeyPad_Command_Confirm();

    }

}

