#include <SPI.h>  
#include <MFRC522.h> 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   
Servo myServo;

int *aux;
int card1[4];
int flag = 0;
int led = 13;
int cnt =0;

void setup() {
        pinMode(led, OUTPUT);
        
        lcd.init();
        lcd.backlight();
    SPI.begin();        
    mfrc522.PCD_Init();   
        lcd.print(" Tap the Card");
        lcd.setCursor(0,1);
        lcd.print(" to register ");

        myServo.attach(3); 
        myServo.write(0);
}

void loop() {
   
    if ( ! mfrc522.PICC_IsNewCardPresent()) {
        return;
    }

   
    if ( ! mfrc522.PICC_ReadCardSerial()) {
        return;
    }

   
    
    for (byte i = 0; i < mfrc522.uid.size; i++) {
            aux[i]= mfrc522.uid.uidByte[i];
    } 
           if(flag == 0)
           {
             lcd.clear();
             lcd.print("   Card UID:    ");
             lcd.setCursor(0,1);
             for (byte i = 0; i < mfrc522.uid.size; i++) {
               card1[i] = aux[i];
             lcd.print( card1[i], DEC);
             lcd.print( " ");
             flag =1;
            }
           delay(3000);
           lcd.clear();
           lcd.print(" Tap the Card");
           lcd.setCursor(0,1);
           lcd.print("   to access   ");
           } 

           else{
            
           
             for (byte i = 0; i < mfrc522.uid.size; i++) {
               if(aux[i] == card1[i])
                cnt++;
             }
                            
            if(cnt == mfrc522.uid.size-1)
            {
              lcd.clear();
              lcd.print("     ACCESS     ");
              lcd.setCursor(0,1);
              lcd.print("     ALLOWED    ");
              delay(200);

               myServo.write(180);
               delay(5000);
               myServo.write(0);
             }
             else
             {
              lcd.clear();
              lcd.print("     ACCESS     ");
              lcd.setCursor(0,1);
              lcd.print("     DENIED     ");
              delay(2000);
             }
             
           }
           
           lcd.clear();
           lcd.print(" Tap the Card");
           lcd.setCursor(0,1);
           lcd.print("   to access   ");
  cnt=0;
}
