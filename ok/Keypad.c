#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_gpio.h"
#include "driverlib/interrupt.h"
#include "inc/hw_ints.h"
#include "LCD.h"
#include "LCD.h"

uint8_t Command[2]="41";
uint8_t Command1[2]="AA";
uint8_t Command2[2]="01";
uint8_t Command3[2]="02";
uint8_t Command4[2]="03";
uint8_t Command5[2]="04";
uint8_t Command6[2]="05";
uint8_t Entered_Command[2];
uint8_t col=2;
uint8_t inttertuptvalue=0;
uint8_t X;
uint8_t Y;
uint8_t Enterd_Command_Counter=0;
uint8_t Command_Confirm_Counter=0;
uint8_t NewCommand_Counter=0;
bool NewCommandControl=0;
bool CommandUpdate=0;


uint8_t KeyPad[4][4]= {//same as the keypad
          {'1','2','3','A'},
          {'4','5','6','B'},
          {'7','8','9','C'},
          {'*','0','#','D'}
        };


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void KeyPad_Lcd_Setup()//The starting screen of the LCD
{

     has_lcd_erase();
     has_lcd_write(1,1,"Enter the led");
     has_lcd_write(2,1,"Command: ");

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void KeyPad_Command_Confirm()
{   uint8_t a=0;
    uint8_t b=0;
    uint8_t c=0;
    uint8_t d=0;
    uint8_t e=0;
    uint8_t f=0;

   if(NewCommand_Counter==1){//if we enter the update screen and enter any button we will back to enter the command
       NewCommandControl=0;
       NewCommand_Counter=0;
       has_lcd_erase();
       has_lcd_write(1,1,"Ready for update");
       SysCtlDelay(SysCtlClockGet()/2);
       KeyPad_Lcd_Setup();
}
   else{//Check if  entered command is matched with the design command and run it
       for(a=0;a<2;a++){
                    if(Entered_Command[a]==Command1[a]){
                     Command_Confirm_Counter++;
                    }
                }
                if(Command_Confirm_Counter==2)
                {
                    has_lcd_erase();
                    has_lcd_write(1,1,"correct Command");
                    SysCtlDelay(SysCtlClockGet()/2);
                    CorrectCommandWait=1;
                    has_lcd_erase();
                    has_lcd_write(1,1,"LED IS ");
                    has_lcd_write(2,1,"Resetting");
                    SysCtlDelay(200000);
                    GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,0);
                    GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,0);
                    GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,0);
                    }Command_Confirm_Counter=0;
         for(c=0;c<2;c++){
             if(Entered_Command[c]==Command2[c]){
              Command_Confirm_Counter++;
             }
         }
         if(Command_Confirm_Counter==2)
         {
             has_lcd_erase();
             has_lcd_write(1,1,"correct Command");
             SysCtlDelay(SysCtlClockGet()/2);
             CorrectCommandWait=1;
             has_lcd_erase();
             has_lcd_write(1,1,"RED LED IS ");
             has_lcd_write(2,1,"Lighting");
             SysCtlDelay(200000);
             GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,2);
             }Command_Confirm_Counter=0;
             for(d=0;d<2;d++){
                        if(Entered_Command[d]==Command4[d]){
                         Command_Confirm_Counter++;
                        }
                    }
                    if(Command_Confirm_Counter==2)
                    {
                        has_lcd_erase();
                        has_lcd_write(1,1,"correct Command");
                        SysCtlDelay(SysCtlClockGet()/2);
                        CorrectCommandWait=1;
                        has_lcd_erase();
                        has_lcd_write(1,1,"Green LED IS ");
                        has_lcd_write(2,1,"Lighting");
                        SysCtlDelay(200000);
                        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,8);
                        }Command_Confirm_Counter=0;
         for(b=0;b<2;b++){
                     if(Entered_Command[b]==Command3[b]){
                         Command_Confirm_Counter++;
                     }
                 }
                 if(Command_Confirm_Counter==2)
                 {
                     has_lcd_erase();
                     has_lcd_write(1,1,"Correct Command");
                     SysCtlDelay(SysCtlClockGet()/2);
                     CorrectCommandWait=1;
                     has_lcd_erase();
                     has_lcd_write(1,1,"Blue LED IS ");
                     has_lcd_write(2,1,"Lighting");
                     SysCtlDelay(200000);
                     GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,4);
                 }Command_Confirm_Counter=0;
                 for(e=0;e<2;e++){
                             if(Entered_Command[e]==Command6[e]){
                                 Command_Confirm_Counter++;
                             }
                         }
                         if(Command_Confirm_Counter==2)
                         {
                             has_lcd_erase();
                             has_lcd_write(1,1,"Correct Command");
                             SysCtlDelay(SysCtlClockGet()/2);
                             CorrectCommandWait=1;
                             has_lcd_erase();
                             GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,0);
                             GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,0);
                             has_lcd_write(1,1,"Red IS");
                             has_lcd_write(2,1,"STOP");
                             GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,2);
                             SysCtlDelay(3500000);
                             has_lcd_erase();
                             has_lcd_write(1,1,"Yellow  IS ");
                             has_lcd_write(2,1,"WAIT");
                             GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,8);
                             SysCtlDelay(6500000);
                             has_lcd_erase();
                             has_lcd_write(1,1,"Green IS ");
                             has_lcd_write(2,1,"go");
                             GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,0);

                         }Command_Confirm_Counter=0;
                         for(f=0;f<2;f++){
                             if(Entered_Command[f]==Command5[f]){
                             Command_Confirm_Counter++;
                                                     }}
                            if(Command_Confirm_Counter==2)
                              {
                               has_lcd_erase();
                               has_lcd_write(1,1,"Correct Command");
                               has_lcd_write(2,1,"MIXCOLOR");
                               SysCtlDelay(SysCtlClockGet()/2);
                               CorrectCommandWait=1;
                               has_lcd_erase();
                               GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,0);
                               GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,0);
                               has_lcd_write(1,1,"Red ");
                               GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,2);
                               SysCtlDelay(3500000);
                               has_lcd_erase();
                               has_lcd_write(1,1,"BLUE ");
                               GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,0);
                               GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,4);
                               SysCtlDelay(6500000);
                               has_lcd_erase();
                               has_lcd_write(1,1,"RED and BLUE");
                               has_lcd_write(2,1,"Violet ");
                               GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,2);
                               SysCtlDelay(6500000);
                               has_lcd_erase();
                               has_lcd_write(1,1,"Green ");
                               GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,0);
                               GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,0);
                               GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,8);
                               SysCtlDelay(6500000);
                               has_lcd_erase();
                               has_lcd_write(1,1,"GREEN and RED");
                               has_lcd_write(2,1,"Yellow ");
                               GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,2);
                               SysCtlDelay(6500000);
                               has_lcd_erase();
                               has_lcd_write(1,1,"Green and Blue ");
                               has_lcd_write(2,1,"Cyan");
                               GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,0);
                               GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,4);
                               SysCtlDelay(6500000);
                               has_lcd_erase();
                               has_lcd_write(1,1,"MIX OF ALL");
                               has_lcd_write(2,1,"White");
                               GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,2);

                                                 }
                            else if(Command_Confirm_Counter<2){
                                has_lcd_write(1,1,"Improper Command ");
                            }


         Enterd_Command_Counter=0;
         Command_Confirm_Counter=0;
       }



}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


uint8_t power(uint8_t x)//calcuate the bit of the input
{
    uint8_t y=1;
    uint8_t i=0;
    for(i=0;i<x;i++)
    {
        y=y*2;
    }
return y;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void KeyPad_wait()
{

    while((Enterd_Command_Counter<2)&&(NewCommand_Counter<1)){//prompt user to enter the command in proper digit
       for(col=4;col<=7;col++){
         GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,240-power(col));
         //write the data in the correct place by positive logic
         SysCtlDelay(20000);

       }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void NewCommandUpdate()//update the command and allow user to enter a new command
{

     CorrectCommandWait=0;
     has_lcd_erase();
     has_lcd_write(1,1,"updating");
     has_lcd_position(2,1);
     NewCommandControl=1;

}
/////////////////////////////////////////////////////////////////////////////////////

uint8_t ln(uint8_t x)//take log 2 of the function
{
    uint8_t y=0;
        while(x!=1)
        {
            x=x/2;
            y++;
        }

return y;
}
///////////////////////////////////////////////////////////////////////////////

void KeyPad_int()//to find the interrupt of portA to read user input
{


    inttertuptvalue=GPIOIntStatus(GPIO_PORTA_BASE,false); //read the value
    X=ln(inttertuptvalue)-4;//find the row in the keypad
    Y=col-4;//find the number of column

    //if it is in updating it send normal value
    if(!CommandUpdate){
    has_lcd_sendchar(MKeyPad[X][Y]);
    }
    SysCtlDelay(SysCtlClockGet()/4);


    //if we keep pressing # it will go into update else it is a normal input
    if (MKeyPad[X][Y]=='#'){
        SysCtlDelay(20000);

        if(GPIOPinRead(GPIO_PORTA_BASE,inttertuptvalue)==0){
            SysCtlDelay(SysCtlClockGet());

            while(GPIOPinRead(GPIO_PORTA_BASE,inttertuptvalue)==0){
                NewCommandUpdate();
            }
        }

        else if(!CommandUpdate){
            CommandTypeControl();
        }
    }

    else if(!CommandUpdate){
        CommandTypeControl();
    }

    GPIOIntClear(GPIO_PORTA_BASE,GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CommandTypeControl()//send the user input to be the command
{

      if(NewCommandControl){
                  Command[NewCommand_Counter]=KeyPad[X][Y];
                  NewCommand_Counter++;
      }
      else{
               Entered_Command[Enterd_Command_Counter]=KeyPad[X][Y];
               Enterd_Command_Counter++;
      }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void KeyPad_Setup()
{
    IntMasterEnable();
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);//Enable GPIOPORT F
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);//Enable GPIOPORT C
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);//Enable GPIOPORT A
    //enable input output , config and edge
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
    GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,0xFF);
    GPIOPinTypeGPIOInput(GPIO_PORTA_BASE,GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
    GPIOPadConfigSet(GPIO_PORTA_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD_WPU);
    GPIOIntRegister(GPIO_PORTA_BASE,KeyPad_int);
    GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,GPIO_FALLING_EDGE);
    GPIOIntClear(GPIO_PORTA_BASE,GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
    GPIOIntEnable(GPIO_PORTA_BASE,GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
    IntEnable(INT_GPIOF_TM4C123);

}







