#include<Servo.h>
// for 6 irsensors
#define a1 PB1 //analogpin (Out)
#define a2 PB7 
#define a3 PB3
#define a4 PB4
#define a5 PB5
#define a6 PB6
int s1=0; //irsensorvalue
int s2=0;
int s3=0;
int s4=0;
int s5=0;
int s6=0;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
// read the analog in value:
  s1= analogRead(a1);
  s2= analogRead(a2);
  s3= analogRead(a3);
  s4= analogRead(a4);
  s5= analogRead(a5);
  s6= analogRead(a6);
  // print the results to the serial monitor:
  //the threshold found fron analog In Out program was when object is detected, the sensor value is below 100
  //set the threshold whihc you get
  //the threshold varies for different sets of emitter-receiver pairs
  if(s1 < 3000){ //checks if object is there or not
    digitalWrite(PA9, HIGH);
    }
  else{
    digitalWrite(PA9, LOW);
        }
  delay(500);
  if(s2 < 3000){ //checks if object is there or not
    digitalWrite(PA10, HIGH);
      }
  else{
    digitalWrite(PA10, LOW);
       }
  delay(500);
  if(s3 < 3000){ //checks if object is there or not
    digitalWrite(PA11, HIGH);
    }
  else{
    digitalWrite(PA11, LOW);
       }
  delay(500);
  if(s4 < 3000){ //checks if object is there or not
    digitalWrite(PA12, HIGH);
     }
  else{
    digitalWrite(PA12, LOW);
        }
  delay(500);
  if(s5<3000){
    digitalWrite(PA6,HIGH);
  }
  else{
    digitalWrite(PA6,LOW);
  }
  delay(500);
  if(s6<3000){
    digitalWrite(PA7,HIGH);
  }
  else{
    digitalWrite(PA7,LOW);
  }
  delay(500);
}
