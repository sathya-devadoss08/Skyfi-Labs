#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define ServoMin 150
#define ServoMax 510

int flag=0;
void servoWrite(int servoNum, int angle) {
  int tick = map(angle, 0, 180, ServoMin, ServoMax);
  pwm.setPWM(servoNum, 0, tick);
}
void zeroSet() {
  for(int i=0; i<6;i++) {
    servoWrite(i*2, 90);
    delay(500);
  }
  delay(1000);
}

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);
  delay(100);
  zeroSet();
  delay(1000);
}

void loop() {
  /**
   * Step - 1
   * Left Ankle 90 -> 45
   * Right Ankle 90 -> 70
   */
  for(int i=0; i<4;i++) {
    servoWrite(0, 90-15*i);
    delay(100);
    if(i<3) {
      servoWrite(10, 90-10*i);
      delay(100);
    }
  }

  if(flag = 0) {
    /**
     * Step 2
     * Left Hip 90 -> 105
     * Left Thigh 90->105
     * Right Hip 90->105
     * Right Thigh 90 ->105
     */
     for(int i=0; i<4;i++) {
      servoWrite(4, 90+5*i);
      servoWrite(2, 90+5*i);
      servoWrite(6, 90+5*i);
      servoWrite(8, 90+5*i);
      delay(100);
     }
  } else {
        /**
     * Step 2A
     * Left Hip 75 -> 105
     * Left Thigh 75->105
     * Right Hip 75->105
     * Right Thigh 75 ->105
     */
     for(int i=0; i<7;i++) {
      servoWrite(4, 75+5*i);
      servoWrite(2, 75+5*i);
      servoWrite(6, 75+5*i);
      servoWrite(8, 75+5*i);
      delay(100);
     }
  }

  /**
   * Step 3
   * Left Ankle 45 -> 90
   * Right Ankle 70 -> 90
   */
   for(int i=0; i<4;i++) {
    servoWrite(0, 45+15*i);
    delay(100);
    if(i<3) {
      servoWrite(10, 70+10*i);
      delay(100);
    }
   }

  /**
   * Step 4
   * Right Ankle 90 -> 135
   * Left Ankle 90 -> 110
   */
   for(int i=0; i<4;i++) {
    servoWrite(10, 90+15*i);
    delay(100);
    if(i<3) {
      servoWrite(0, 90+10*i);
      delay(100);
    }
   }

    /**
     * Step 5
     * Left Hip 105 -> 75
     * Left Thigh 105 -> 75
     * Right Hip 105 -> 75
     * Right Thigh 105 -> 75
     */
     for(int i=0; i<4;i++) {
      servoWrite(4, 105-5*i);
      servoWrite(2, 105-5*i);
      servoWrite(6, 105-5*i);
      servoWrite(8, 105-5*i);
      delay(100);
     }

  /**
   * Step 6
   * Right Ankle 135 -> 90
   * Left Ankle 110 -> 90
   */
   for(int i=0; i<4;i++) {
    servoWrite(10, 135-15*i);
    delay(100);
    if(i<3) {
      servoWrite(0, 110-10*i);
      delay(100);
    }
   }
   flag++;
  
}
