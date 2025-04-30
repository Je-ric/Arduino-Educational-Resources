const int SW_pin = 2; // digital pin connected to SW
const int X_pin = 0; // analog pin connected to VRx
const int Y_pin = 1; // analog pin connected to VRy
void setup() {
 pinMode(SW_pin, INPUT);
 digitalWrite(SW_pin, HIGH);
 Serial.begin(9600);
}
void loop() {
 Serial.print("X: ");
 Serial.print(analogRead(X_pin));
 Serial.print(" Y: ");
 Serial.print(analogRead(Y_pin));
 Serial.print(" Z: ");
 Serial.println(digitalRead(SW_pin));
 delay(250);
}
