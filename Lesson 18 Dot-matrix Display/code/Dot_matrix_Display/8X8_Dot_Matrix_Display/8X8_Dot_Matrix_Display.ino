
byte character[8]={0xc7, 0xce, 0xdc, 0xf8, 0xf8, 0xdc, 0xce, 0xc7};

uint8_t colPins[8]={ 2, 3, 4, 5, 6, 7, 8, 9};

#define SER_PIN 10
#define SCK_PIN 11
#define RCK_PIN 12

void setup() {
  // Turn everything to low
  for(int i=0; i<8; i++) {
    pinMode(colPins[i],OUTPUT);
  }
  pinMode(SER_PIN, OUTPUT);
  pinMode(SCK_PIN, OUTPUT);
  pinMode(RCK_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // iterate each row
  int rowbits = 0x80;
  for(int row=0; row<8; row++) {
    for(int k=0; k<8; k++) 
      digitalWrite(colPins[k],HIGH); // Cleanup cols
    write595(rowbits); // prepare to write the row
    for(int col=0; col<8; col++)
      digitalWrite(colPins[7-col], character[row] & 1 << col ? LOW : HIGH);
    delay(1);
    write595(0);
    rowbits >>= 1; 
  } 
}

void write595(byte data) {
  digitalWrite(RCK_PIN, LOW);
  shiftOut(SER_PIN, SCK_PIN, LSBFIRST, data);
  digitalWrite(RCK_PIN, HIGH);}
