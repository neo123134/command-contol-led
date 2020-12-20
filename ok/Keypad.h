#ifndef KEYPAD_H_
#define KEYPAD_H_




void KeyPad_wait();
void KeyPad_int();
void KeyPad_Setup();
void KeyPad_Lcd_Setup();
void KeyPad_Command_Confirm();
void NewCommandUpdate();
void CommandTypeControl();
uint8_t power(uint8_t);
uint8_t ln(uint8_t);

#endif /* KEYPAD_H_ */
