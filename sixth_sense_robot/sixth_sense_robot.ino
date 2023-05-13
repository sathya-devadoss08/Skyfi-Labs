char data;
String command;

int leftWheelMotorNegativePin = 10;
int leftWheelMotorPositivePin = 11;

int rightWheelMotorNegativePin = 8;
int rightWheelMotorPositivePin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(leftWheelMotorPositivePin, OUTPUT);
  pinMode(leftWheelMotorNegativePin, OUTPUT);
  pinMode(rightWheelMotorPositivePin, OUTPUT);
  pinMode(rightWheelMotorNegativePin, OUTPUT);

}

void moveRobot(String motion) {
  Serial.println("motioncmd received==>");
  Serial.print(motion);
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
  //delay(1000);
}
void loop() {
  //moveRobot("Forward");
 while(Serial.available() > 0) {
  data = Serial.read();
  command = String(data);
  String motionCmd;
  //Serial.print("command11==>");
  //Serial.println(command);
  if( command == "f") {
    motionCmd = "Forward";
  } else if (command == "b") {
    motionCmd = "Reverse";
  } else if (command == "l") {
    motionCmd = "Left";
    Serial.println ("left command");
  } else if (command == "r") {
    motionCmd = "Right";
  } else if (command == "s") {
    motionCmd = "Stop";
  }
  Serial.print("auto cmd==>");
  Serial.println(motionCmd);
  if(motionCmd.length() > 0)  {
    moveRobot(motionCmd);
  }
 }

  
}
