#include <Stepper.h>



#include <Servo.h>
//Initialize variables
int mode = 0;             
int buttonState = 0;      
int prevButtonState = 0;  
int topLeftLight = 0;     
int topRightLight = 0;
int bottomLeftLight = 0;
int bottomRightLight = 0;
int LeftLight = 0;
int RightLight = 0;
int TopLight = 0;
int BottomLight = 0;
//Declare two servos
Servo servo_9;
Servo servo_10;


void setup()
{
  pinMode(7, INPUT);    //Mode Button
  pinMode(12, OUTPUT);  //Led indicator for manual mode
  pinMode(11, OUTPUT);  //Led indicator for auto mode
  pinMode(A0, INPUT);   //Potentiometer for right-left movement
  pinMode(A1, INPUT);   //Potentiometer for up-down movement
  pinMode(A2, INPUT);   //Light sensor up - left
  pinMode(A3, INPUT);   //Light sensor up - right
  pinMode(A4, INPUT);   //Light sensor bottom - left
  pinMode(A5, INPUT);   //Light sensor bottom - right
  servo_9.attach(9);    //Servo motor right - left movement
  servo_10.attach(10);  //Servo motor up - down movement
}

void loop()
{
  buttonState = digitalRead(7);
  if (buttonState != prevButtonState) {
    if (buttonState == HIGH) {
      //Change mode and ligh up the correct indicator  
      if (mode == 1) {
        mode = 0;
        digitalWrite(12, HIGH);
        digitalWrite(11, LOW);
      } else {
        mode = 1;
        digitalWrite(11, HIGH);
        digitalWrite(12, LOW);
      }
    }
  }
  prevButtonState = buttonState;
  delay(50); // Wait for 50 millisecond(s)
  if (mode == 0) {
    //If mode is manual map the pot values to degrees of rotation
    servo_9.write(map(analogRead(A0), 0, 1023, 0, 180));
    servo_10.write(map(analogRead(A1), 0, 1023, 0, 180));
  } else {
    //if mode is auto map the sensor values to 0-100 ligh intensity. 
    //Every light sensor has different sensitivity and must be first tested 
    //for it's high and low values
    topLeftLight = map(analogRead(A2),50,980,0,100);
    topRightLight = map(analogRead(A3),50,980,0,100);
    bottomLeftLight = map(analogRead(A4),50,980,0,100);
    bottomRightLight = map(analogRead(A5),50,980,0,100);
    //Calculate the average light conditions
    TopLight = ((topRightLight + topLeftLight) / 2);
    BottomLight = ((bottomRightLight + bottomLeftLight) / 2);
    LeftLight = ((topLeftLight + bottomLeftLight) / 2);
    RightLight = ((topRightLight + bottomRightLight) / 2);
    //Rotate the servos if needed
    if (abs((RightLight - LeftLight)) > 4) {    //Change position only if light difference is bigger then 4%
      if (RightLight > LeftLight) {
        if (servo_9.read() < 180) {
          servo_9.write((servo_9.read() + 1));
        }
      }
      if (RightLight < LeftLight) {
        if (servo_9.read() > 0) {
          servo_9.write((servo_9.read() - 1));
        }
      }
    }
    if (abs((TopLight - BottomLight)) > 4) {  //Change position only if light difference is bigger then 4%
      if (TopLight > BottomLight) {
        if (servo_10.read() > 0) {
          servo_10.write((servo_10.read() - 1));
        }
      }
      if (TopLight < BottomLight) {
        if (servo_10.read() < 180) {
          servo_10.write((servo_10.read() + 1));
        }
      }
    }
   }
}
