#include <Servo.h>

Servo servox;
Servo servoy;
Servo servoz;
Servo servog;
int servox_pin = 9;
int servoy_pin = 10;
int servoz_pin = 11;
int servog_pin = 6;

int pos =0;

void arm() {
  servox.write(0);
  servoy.write(90);
  servog.write(90);
  delay(1000);
}

void setup() {
  servox.attach(servox_pin);
  servoy.attach(servoy_pin);
  servoz.attach(servoz_pin);
  servog.attach(servog_pin);
  arm();
  Serial.begin(9600);
}

void loop() {


//move down to grab the object

  move(servoy,60, 140);//move down
  move(servog, 90, 0);//grab
  move(servoy,140, 60);//move up
  move(servox, 0, 90);//move to drop location

// now come down and drop the object
  move(servoy,60, 140);//move down
  move(servog, 0, 90);//release object
  move(servoy,140, 60);//move up
  move(servox, 90, 0);//go to original position
//  move(servog, 90, 0);
  //servog.write(75);
  //delay(1000);

  //final values
//x=0
//y=60
//g=0
//delay(2000);
}

void move(Servo servo, int x,int y) {
  String msg = "inside move from " ;
  msg = msg + x ;
  msg = msg + " to ";
  msg = msg + y;
  Serial.println(msg);
  delay (2000);
  if(x<y) {
    for(pos=x; pos<=y; pos++) {
      servo.write(pos);
      Serial.println(pos);
      delay(50);
    }
  } else {
    for(pos=x; pos>=y; pos--) {
      servo.write(pos);
      Serial.println(pos);
      delay(50);
    }
  }
  }
