/****************************************
name: Voltmeter
function:adjust the potentiometer and you will see the voltage displayed on the I2C LCD1602 varies accordingly.
https://www.makerlab-electronics.com/
******************************************/

/*************************************/
// include the library code
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
/****************************************************/
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
float val = 0;
/****************************************************/
void setup()
{
  Serial.begin(9600);//initialize the serial
  lcd.init();  //initialize the lcd
  lcd.backlight();  //open the backlight 
  lcd.print("Voltage Value:");//print "Voltage Value:"
}
/****************************************************/
void loop()
{
  val = analogRead(A0);//Read the value of the potentiometer to val
  val = val/1024*5.0;// Convert the data to the corresponding voltage value in a math way
  Serial.print(val);//Print the number of val on the serial monitor
  Serial.print("V"); // print the unit as V, short for voltage on the serial monitor
   Serial.println( );
  lcd.setCursor(6,1);//Place the cursor at Line 1, Column 6. From here the characters are to be displayed
  lcd.print(val);//Print the number of val on the LCD
  lcd.print("V");//Then print the unit as V, short for voltage on the LCD
  delay(200); //Wait for 200ms
}
