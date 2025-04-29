//This code will control LED brightness through PWM
//https://www.makerlab-electronics.com/

/**************************************************************/
const int ledPin = 7;                   // the pin that the LED is attached to

void setup ()
{
  pinMode(ledPin, OUTPUT);              // declare pin 9 to be an output:
}
 
void loop()
{
  for (int a=255; a<=255;a++)               //loop  from 0 to 255 ; can change the value of a 
  {
    analogWrite(ledPin, a);               // set the brightness of pin 9:
    delay(8);                             //wait for 8 microseconds            
  }
    for (int a=255; a>=0;a--)             //loop from 255 down to 0
  {
    analogWrite(ledPin, a);               // set the brightness of pin 9:
    delay(5);                             //wait for 5 microseconds   
  }
  delay(100);                             //wait for 100 microseconds  
}

