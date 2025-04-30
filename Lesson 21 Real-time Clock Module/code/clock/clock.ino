//This code is to use with DS1302 RTC module, it permits you to setup the actual time and date
//And you can visualize them on the LCD i2c screen
//This code is a modified version of the code provided in virtuabotixRTC library
//Refer to https://Surtrtech.com for more information
//Updated by https://www.makerlab-electronics.com/

// Manually changed importing of libraries to the 'src' folder located inside this project sketch.
#include "src/ArduinoRTClibrary-master/virtuabotixRTC.h"
#include "src/Newliquidcrystal_1.3.5/LiquidCrystal_I2C.h"

#define I2C_ADDR 0x27 //LCD i2c stuff
#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
//Wiring SCLK -> 6, I/O -> 7, CE -> 8
//Or CLK -> 6 , DAT -> 7, Reset -> 8

virtuabotixRTC myRTC(6, 7, 8); //If you change the wiring change the pins here also

void setup() {
 Serial.begin(9600);
 lcd.begin (16,2); //Initialize the LCD
 lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
 lcd.setBacklight(HIGH);
 lcd.home ();

 
 // HOW TO SET / UPDATE TIME FOR RTC DS1302 MODULE

 /* Only edit the paramters of the line below this comment to set/update time. */
 myRTC.setDS1302Time(00, 35, 13, 2, 9, 5, 2023);
 /*
            ^
            |
            |
            |
 Update this line to set/update the time of the RTC.

 HOW?
 1. Uncomment the line above by removing the "//".
 2. Change the values of the 'setDS1302Time' parameter in this order:
   */
  
   // myRTC.setDS1302Time(second, minute, hour, dayofweekasnumber [Note: 1 => Monday up to 7 => Sunday], day, month, year)
  
   /*
 3. Upload the sketch once until it says 'Done Uploading.'
 4. Comment the line above and upload the sketch again until it says 'Done Uploading'.
 5. You have successfully set/updated the RTC DS1302 Time!
 
 */
}

void loop() {
 lcd.clear(); //Here after clearing the LCD we take the time from the module and print it on the screen with usual LCD functions
 myRTC.updateTime();
 lcd.setCursor(0,0);
 lcd.print(myRTC.dayofmonth);
 lcd.print("/");
 lcd.print(myRTC.month);
 lcd.print("/");
 lcd.print(myRTC.year);
 lcd.setCursor(0,1);
 lcd.print(myRTC.hours);
 lcd.print(":");
 lcd.print(myRTC.minutes);
 lcd.print(":");
 lcd.print(myRTC.seconds);
 delay(1000);
}
