/********************************
 * name:Interactive LED Flowing Lights
 * function:Here you should see eight LEDs light up one by one in turn. Adjust the potentiometer, and you will find the time interval of LED lighting up changes. 
 * https://www.makerlab-electronics.com/
 ********************************/

int ledNum = 8;                               //the number of the led you attach
byte ledPin[] = {2, 3, 4, 5, 6, 7, 8, 9};    // Create array for LED pins
int ledDelay;                                // delay between changes
int potPin=A0;                              //Potentiometer attach to pinA0

void setup()
{                                             //set all leds as OUTPUT
  for (int x = 0; x < ledNum; x++)
  { 
    pinMode(ledPin[x], OUTPUT); 
  }	
}

void loop() 
{
  for(int i=0;i<8;i++)
  {
    ledDelay = analogRead(potPin);            //read the value of A0
    digitalWrite(ledPin[i],HIGH);             //turn on LEDs
    delay(ledDelay);                          //delay the times which read from potentiometer
    digitalWrite(ledPin[i],LOW);                //turn off leds
  }

  for(int i=7;i>=0;i--)
  {
    ledDelay = analogRead(potPin);              //read the value of A0
    digitalWrite(ledPin[i],HIGH);             //turn on LEDs
    delay(ledDelay);                          //delay the times which read from potentiometer
    digitalWrite(ledPin[i],LOW);                //turn off leds
  }
}


