
#include<Servo.h>
// for entry
# define sp1 PA8 //servomotor
# define t1 PB0  //trigpin
# define e1 PC13 //echopin
// for exit
# define sp2 PA7 //servomotor
# define t2 PB5  //trigpin
# define e2 PC14 //echopin 
// for 4 irsensors
#define a1 PB1 //analogpin
#define a2 PB2
#define a3 PB3
#define a4 PB4
// leds detecting empty space
#define l1 PA9
#define l2 PA10
#define l3 PA11
#define l4 PA12
int i=0;
int s1=0; //irsensorvalue
int s2=0;
int s3=0;
int s4=0;
Servo myServo1;
Servo myServo2;
void setup() {
  pinMode(t1,OUTPUT);
  pinMode(e1,INPUT);
  myServo1.attach(sp1);
  pinMode(t2,OUTPUT);
  pinMode(e2,INPUT);
  myServo2.attach(sp2);
   pinMode(PA9, OUTPUT);
   pinMode(PA10, OUTPUT);
   pinMode(PA11, OUTPUT);
   pinMode(PA12, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
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
// read the analog in value:
  s1= analogRead(a1);
  s2= analogRead(a2);
  s3= analogRead(a3);
  s4= analogRead(a4);
  // print the results to the serial monitor:
  //the threshold found fron analog In Out program was when object is detected, the sensor value is below 100
  //set the threshold whihc you get
  //the threshold varies for different sets of emitter-receiver pairs
  if(s1 < 3000){ //checks if object is there or not
    digitalWrite(PA9, HIGH);
    //Serial.print("\nempty");
    }
  else{
    digitalWrite(PA9, LOW);
    //Serial.print("\noccupied");
    }
  delay(500);
  if(s2 < 3000){ //checks if object is there or not
    digitalWrite(PA10, HIGH);
    //Serial.print("\nempty");
    }
  else{
    digitalWrite(PA10, LOW);
    //Serial.print("\noccupied");
    }
  delay(500);
  if(s3 < 3000){ //checks if object is there or not
    digitalWrite(PA11, HIGH);
    //Serial.print("\nempty");
    }
  else{
    digitalWrite(PA11, LOW);
    //Serial.print("\noccupied");
    }
  delay(500);
  if(s4 < 3000){ //checks if object is there or not
    digitalWrite(PA12, HIGH);
    //Serial.print("\nempty");
    }
  else{
    digitalWrite(PA12, LOW);
    //Serial.print("\noccupied");
    }
  delay(500);
}
  // put your main code here, to run repeatedly:
