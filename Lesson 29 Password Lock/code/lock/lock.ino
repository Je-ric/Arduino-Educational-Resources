/*******************************************************
 * name:Password Lock
 * function: the I2C LCD1602 will display "Hello there! Press * to start" after power on. 
 * At this point, the indicator LED on the relay keeps off.
 * When you press "*" key, it will prompt "Input Your Code:". If you enter “123456” and press “#” key to confirm, 
 * the indicator LED on the relay module will light up. The I2C LCD1602 will display "Input Correct" "Please Come In".
 * If you try to input an incorrect password, it will prompt you to press * to input again the correct password. 
 
  https://www.makerlab-electronics.com/
 *********************************************************/

#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);


#define relayPin 3 //relay attach to pin 3


const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = 
{
  { '1','2','3','A'  },
  { '4','5','6','B'  },
  { '7','8','9','C'  },
  { '*','0','#','D'  }
};
byte rowPins[ROWS] = { 8, 9, 10, 11}; //connect to the row pinouts of the keypad
byte colPins[COLS] = { 7, 6, 5, 4}; //connect to the column pinouts of the keypad


int pos = 0;
char secretCode[6] = { '1', '2', '3', '4', '5', '6'};
char inputCode[6] = { '0', '0', '0', '0', '0', '0'};

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup()
{
  lcd.init(); //initialize lcd
  lcd.backlight(); //turn the backlight
  pinMode(relayPin, OUTPUT); //set the relay as OUTPUT
  digitalWrite(relayPin,HIGH);
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print(" Hello there!");
  lcd.setCursor(0,1);
  lcd.print("Press * to start");
  delay(2000);

}

void loop()
{
  readKey();
}

void readKey()
{
  int correct = 0;
  int i;
  char customKey = customKeypad.getKey();//get the key value
  if (customKey)
  {
    switch(customKey)
    {
    case '*': //if press in "*" ,then print "Input Your Code:"
      pos = 0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Input Your Code:");
      break;
    case '#':  //if press in "#" ,then see the  password whether "1 2 3 4 5 6"
      for(i = 0; i < 6; i++)
      {
        if(inputCode[i] == secretCode[i])
        {
          correct ++;
        }
      }
      if(correct == 6)//if it right
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Input correct!");//print "Input correct!"
        lcd.setCursor(0, 1);
        lcd.print("Please Come In."); //print "Please Come In"
        digitalWrite(relayPin, LOW); //relay connected
        delay(2000);
        lcd.setCursor(0,0);
        lcd.print("    makerlab    ");
        lcd.setCursor(0,1);
        lcd.print(" electronics :)");
        digitalWrite(relayPin, HIGH);
        
      }
      else
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("  Input Error!  ");
        lcd.setCursor(0, 1);
        lcd.print("Please try again. ");
        digitalWrite(relayPin, LOW);
        delay(2000);
        lcd.clear();
        readKey();
        lcd.setCursor(0,0);
        lcd.print("  Press * to  ");
        lcd.setCursor(0,1);
        lcd.print(" input again :) ");
        digitalWrite(relayPin, LOW);
      }
      break;
    default:
      inputCode[pos] = customKey;
      lcd.setCursor(pos,1);
      lcd.print(inputCode[pos]);
      pos ++;
    }
  }
}
