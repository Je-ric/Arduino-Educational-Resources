int led1 = 7;
int led2 = 6;
int led3 = 5;
int led4 = 4;
int led5 = 3;

int triggerPin = 9;
int echoPin = 10;

long readTime(int triggerPin, int echoPin){
  
  // In order for the sensor to send out a pulse the trigger needs to be set low for 2us
  // Then set HIGH for 10us 
     
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW); 
  delayMicroseconds(2); 

  digitalWrite(triggerPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(triggerPin, LOW); 
  pinMode(echoPin, INPUT); 
  return pulseIn(echoPin, HIGH);
}

void setup() {
  Serial.begin(9600);
  pinMode(led1,OUTPUT); 
  pinMode(led2,OUTPUT); 
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT); 
  pinMode(led5,OUTPUT); 
}

void loop() {
  int distance; 
  distance = 0.01715 * readTime(triggerPin, echoPin); // From calculation above Distance = 0.0343 / 2 * readTime
  Serial.print("distance: "); 
  Serial.print(distance);
  Serial.println("cm"); 
  
  if(distance > 25){
      digitalWrite(led1, HIGH); 
      digitalWrite(led2, HIGH); 
      digitalWrite(led3, HIGH); 
      digitalWrite(led4, HIGH); 
      digitalWrite(led5, HIGH); 
    }
  
  if(distance > 20 && distance < 25){
      digitalWrite(led1, HIGH); 
      digitalWrite(led2, HIGH); 
      digitalWrite(led3, HIGH); 
      digitalWrite(led4, HIGH); 
      digitalWrite(led5, LOW); 
    }

    if(distance > 15 && distance < 20){
      digitalWrite(led1, HIGH); 
      digitalWrite(led2, HIGH); 
      digitalWrite(led3, HIGH); 
      digitalWrite(led4, LOW); 
      digitalWrite(led5, LOW); 
    }

    if(distance > 10 && distance < 15){
      digitalWrite(led1, HIGH); 
      digitalWrite(led2, HIGH); 
      digitalWrite(led3, LOW); 
      digitalWrite(led4, LOW); 
      digitalWrite(led5, LOW); 
    }

  
    if(distance > 5 && distance < 10){
      digitalWrite(led1, HIGH); 
      digitalWrite(led2, LOW); 
      digitalWrite(led3, LOW); 
      digitalWrite(led4, LOW); 
      digitalWrite(led5, LOW); 
    }
  if(distance < 5){
      digitalWrite(led1, LOW); 
      digitalWrite(led2, LOW); 
      digitalWrite(led3, LOW); 
      digitalWrite(led4, LOW); 
      digitalWrite(led5, LOW);  
    }
  
}
