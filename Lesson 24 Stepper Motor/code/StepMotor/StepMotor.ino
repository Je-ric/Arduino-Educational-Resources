/****************************************
 * name:Stepper Motor
 * function:you should see the rocker arm of the stepper motor spin clockwise and counterclockwise alternately. 
 * Stepper Motor         SunFounder Uno R3
 * IN1                      11
 * IN2                      10
 * IN3                      9
 * IN4                      8

 *****************************************/

const int IN1=11;

const int IN2=10;
const int IN3=9;
const int IN4=8;
const char tab1[] =
{
  0x01, 0x03, 0x02, 0x06, 0x04, 0x0c, 0x08, 0x09
};
const char tab2[] =
{
  0x01, 0x09, 0x08, 0x0c, 0x04, 0x06, 0x02, 0x03
};

void setup() 
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  ctlStepMotor(360, 1);
  StepMotorStop();
  delay(1000);
  ctlStepMotor(-360, 1);
  StepMotorStop();
  delay(1000);
}

void ctlStepMotor(int angle, char speeds )
{
  for (int j = 0; j < abs(angle) ; j++)
  {
    if (angle > 0)
    {
      for (int i = 0; i < 8; i++)
      {
        digitalWrite(IN1, ((tab1[i] & 0x01) == 0x01 ? true : false));
        digitalWrite(IN2, ((tab1[i] & 0x02) == 0x02 ? true : false));
        digitalWrite(IN3, ((tab1[i] & 0x04) == 0x04 ? true : false));
        digitalWrite(IN4, ((tab1[i] & 0x08) == 0x08 ? true : false));
        delay(speeds);
      }
    }
    else
    {
      for (int i = 0; i < 8 ; i++)
      {
        digitalWrite(IN1, ((tab2[i] & 0x01) == 0x01 ? true : false));
        digitalWrite(IN2, ((tab2[i] & 0x02) == 0x02 ? true : false));
        digitalWrite(IN3, ((tab2[i] & 0x04) == 0x04 ? true : false));
        digitalWrite(IN4, ((tab2[i] & 0x08) == 0x08 ? true : false));
        delay(speeds);
      }
    }
  }
}
void StepMotorStop()
{
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 0);
}
