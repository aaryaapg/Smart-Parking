#include<Servo.h>
// for entry
# define sp1 PA8 //servomotor
# define t1 PB0  //trigpin
# define e1 PC13 //echopin
// for exit
# define sp2 PA9. //servomotor
# define t2 PB5  //trigpin
# define e2 PC14 //echopin 
int i=0;
Servo myServo1;
Servo myServo2;
void setup() {
  pinMode(t1,OUTPUT);
  pinMode(e1,INPUT);
  myServo1.attach(sp1);
  pinMode(t2,OUTPUT);
  pinMode(e2,INPUT);
  myServo2.attach(sp2);
}

void loop() {
  // put your main code here, to run repeatedly:
 myServo1.write(0);
  myServo2.write(0);
  long du1,d1;
  digitalWrite(t1,LOW);
  delayMicroseconds(10);
  digitalWrite(t1,HIGH);
  delayMicroseconds(2);
  digitalWrite(t1,LOW);
  du1=pulseIn(e1,HIGH);
  d1=0.034*du1/2;
  if(d1!=0&&d1<7&&i<5)
  {
  Serial.println(d1);
  delay(50);
  myServo1.write(0);
  delay(1500);
  myServo1.write(90);
  delay(2000);
  myServo1.write(0);
  delay(1500);
  i++;

  }
  long du2,d2;
  digitalWrite(t2,LOW);
  delayMicroseconds(10);
  digitalWrite(t2,HIGH);
  delayMicroseconds(2);
  digitalWrite(t2,LOW);
  du2=pulseIn(e2,HIGH);
  d2=0.034*du2/2;
  if(d2!=0&&d2<7&&i>0)
  {
  Serial.println(d2);
  delay(50);
  myServo2.write(0);
  delay(1500);
  myServo2.write(90);
  delay(2000);
  myServo2.write(0);
  delay(1500);
  i--;
}
}
