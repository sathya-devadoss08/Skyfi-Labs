
int fanMotorPin = 9;
int leftWheelMotorPositivePin = 12;
int leftWheelMotorNegativePin = 13;
int rightWheelMotorPositivePin = 10;
int rightWheelMotorNegativePin = 11;

int rightSensorPin = A0;
int middleSensorPin = A1;
int leftSensorPin = A2;

 
void setup() {
  Serial.begin(9600);
  pinMode(rightSensorPin, INPUT);
  pinMode(middleSensorPin, INPUT);
  pinMode(leftSensorPin, INPUT);
  pinMode(fanMotorPin, OUTPUT);
  pinMode(leftWheelMotorPositivePin, OUTPUT);
  pinMode(leftWheelMotorNegativePin, OUTPUT);
  pinMode(rightWheelMotorPositivePin, OUTPUT);
  pinMode(rightWheelMotorNegativePin, OUTPUT);

}

void moveRobot(String motion) {
  if(motion == "Forward") {//both wheel's +ve to high
    digitalWrite(leftWheelMotorPositivePin, HIGH);
    digitalWrite(rightWheelMotorPositivePin, HIGH);
    digitalWrite(leftWheelMotorNegativePin, LOW);
    digitalWrite(rightWheelMotorNegativePin, LOW);
    Serial.println("Moving forward");
  } else if(motion == "Reverse") {//both wheel's -ve to high
    digitalWrite(leftWheelMotorPositivePin, LOW);
    digitalWrite(leftWheelMotorNegativePin, HIGH);
    digitalWrite(rightWheelMotorPositivePin, LOW);
    digitalWrite(rightWheelMotorNegativePin, HIGH);
    Serial.println("Moving reverse");
  } else if(motion == "Left") {
//Left wheel's (goes reverse) -ve to high, right wheel (goes forward) +ve to high
    digitalWrite(leftWheelMotorPositivePin, LOW);
    digitalWrite(leftWheelMotorNegativePin, HIGH);
    digitalWrite(rightWheelMotorPositivePin, HIGH);
    digitalWrite(rightWheelMotorNegativePin, LOW);
    Serial.println("Moving Left");
  } else if(motion == "Right") {
//Left wheel forward +ve to high, right wheel reverse -ve to high
    digitalWrite(leftWheelMotorPositivePin, HIGH);
    digitalWrite(leftWheelMotorNegativePin, LOW);
    digitalWrite(rightWheelMotorPositivePin, LOW);
    digitalWrite(rightWheelMotorNegativePin, HIGH);
    Serial.println("Moving Right");
  }else if(motion == "Stop") {
    digitalWrite(leftWheelMotorPositivePin, LOW);
    digitalWrite(leftWheelMotorNegativePin, LOW);
    digitalWrite(rightWheelMotorPositivePin, LOW);
    digitalWrite(rightWheelMotorNegativePin, LOW);
    Serial.println("STOP");
  }
}
void loop() {
  int left = analogRead(leftSensorPin);
  int middle = analogRead(middleSensorPin);
  int right = analogRead(rightSensorPin);
  Serial.print(right);
  Serial.print("\t");
  Serial.print(middle);
  Serial.print("\t");
  Serial.print(left);
  Serial.print("\t");
  Serial.println("");
  
  if(left < 100 && right < 100 && middle < 100) {
    moveRobot("Stop");
  } else {
    if( (left > middle) && (left > right) ) {
      moveRobot("Left");
      delay(100);
      moveRobot("Stop");
      delay(200);
    } else if( (right > middle) && (right > left) ) {
      moveRobot("Right");
      delay(100);
      moveRobot("Stop");
      delay(200);
    } else if( (middle > right) && (middle > left) && middle < 700 ) {
      moveRobot("Forward");
      delay(60);
      moveRobot("Stop");
      delay(200);
    } else if( (middle > right) && (middle > left) && middle > 700 ) {
      moveRobot("Stop");
      digitalWrite(fanMotorPin, HIGH);
      delay(2000);
      digitalWrite(fanMotorPin, LOW);
    }
  }
  
}
