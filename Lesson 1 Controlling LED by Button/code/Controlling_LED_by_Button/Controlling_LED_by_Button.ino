// void setup() {
//   pinMode(9, OUTPUT);                 
//   pinMode(A0, INPUT);           
// }

// void loop() {
//   int Pread = analogRead(A0);
//   int outvalue = map(Pread, 0, 1023, 0, 255);
//   analogWrite(9, outvalue);
// }

int num_array[10][7] = { 
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,0,0,1,1}
};

void Num_Write(int n) {
  int pin = 2;
  for (int x = 0; x < 7; x++){
    digitalWrite(pin, num_array[n][x]);
    pin++;
  }
}

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT); 
}

void loop() {
  for (int n = 0; n < 10; n++) {
    Num_Write(n);
    delay(1000);
  }
  delay(3000);
}
