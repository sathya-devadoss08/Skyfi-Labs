#include<SoftwareSerial.h>

SoftwareSerial esp8266(3,2); //Rx pin=3, Tx pin =2
//String SSIDandPW    = "AT+CWJAP=\"xxxxxxwifi\",\"xxxxxx123\"\r\n";
String SSIDandPW    = "AT+CWJAP=\"NETGEAR25\",\"XXXX\"\r\n";

//                                      [The STATIC IP of the wifi module]
//                                      |                [The main IP of the router]
//                                      |                |              [The default submask]
//                                      |                |              |
//                                      V                V              V
String eIPrIPmask   = "AT+CIPSTA_DEF=\"192.168.9.60\",\"192.168.9.1\",\"255.255.255.0\"\r\n";


#define DEBUG true
#define SSID "YOUR SSID"
#define PWD "UR PASSWORD"
int state =5;
int left_motor_A1_pin = 8;
int left_motor_A2_pin = 9;

int right_motor_B1_pin = 10;
int right_motor_B2_pin = 11;

void setup() {
  Serial.begin(19200);
  esp8266.begin(19200);
  connectWifi();
  //set motor pins as output pins
  pinMode(left_motor_A1_pin,OUTPUT);
  pinMode(left_motor_A2_pin,OUTPUT);
  pinMode(right_motor_B1_pin,OUTPUT);
  pinMode(right_motor_B2_pin,OUTPUT);
  digitalWrite(13, HIGH);//make led on
  
digitalWrite(left_motor_A1_pin, LOW);
    digitalWrite(left_motor_A2_pin, LOW);
    digitalWrite(right_motor_B1_pin, LOW);
    digitalWrite(right_motor_B2_pin, LOW);
}

void loop() {
  Serial.println(" \n ");
  if(esp8266.available()) {
    if(esp8266.find("+IPD,")) {
      delay(500);
      String msg;
      esp8266.find("?");//find ? mark in the message
      msg = esp8266.readStringUntil(' ');
      Serial.println("message receive is");
      Serial.println(msg);
      Serial.println("====");
      String command = msg.substring(0, 3);//first 3 chars=command
      String valueStr = msg.substring(4);//next 4 chars=value
      int value = valueStr.toInt();//convert to integer
      if(DEBUG) {
        Serial.println(command);
        Serial.println(value);
      }
      //move forward
      if(command == "cm1") {
        state = 1;
        Serial.println("forward");
      }
      //move backward
      if(command == "cm2") {
        state = 2;
        Serial.println("backward");
      }
      //move right
      if(command == "cm3") {
        state = 3;
        Serial.println("move right");
      }
      //move left
      if(command == "cm4") {
        state = 4;
        Serial.println("move left");
      }
      //move left
      if(command == "cm5") {
        state = 5;
        Serial.println("stop");
      }
      //test connection
      if(command == "cm6") {
        state = 6;
        Serial.println("connected to client");
        Serial.println("Now user arrow keys to control ur robot");
      }
    }
  }
  Serial.println("STATE");
  Serial.println(state);
  //move forward
  if(state == 1) {
    digitalWrite(left_motor_A2_pin, HIGH);
    digitalWrite(right_motor_B2_pin, HIGH);
  }
  //move backward
  if(state == 2) {
    digitalWrite(left_motor_A1_pin, HIGH);
    digitalWrite(right_motor_B1_pin, HIGH);
  }
  //turn right
  if(state == 3) {
    digitalWrite(left_motor_A2_pin, HIGH);
    digitalWrite(right_motor_B1_pin, HIGH);
  }
  //turn left
  if(state == 4) {
    digitalWrite(left_motor_A1_pin, HIGH);
    digitalWrite(right_motor_B2_pin, HIGH);
  }
  //stop
  if(state == 5) {
    digitalWrite(left_motor_A1_pin, LOW);
    digitalWrite(left_motor_A2_pin, LOW);
    digitalWrite(right_motor_B1_pin, LOW);
    digitalWrite(right_motor_B2_pin, LOW);
  }
  if(state == 6) {
    
  }
  
  

}

String sendData(String command, const int timeout, boolean debug) {
  String response = "";
  long int time   = millis();

  esp8266.print(command);          // send the read character to the esp8266
  Serial.println("Sending command below");
Serial.println(command);
  while((time + timeout) > millis()) {
    while(esp8266.available()) {
                                   // The esp has data so display its output to the serial window
        char c = esp8266.read();   // read the next character.
        response += c;
    }
  }

  if (debug) { Serial.println('Returned: ' + response); }
  return response;
}

void connectWifi() {
  esp8266.begin(19200);
  sendData("AT+RST\r\n",                    2000, true); // Reset module
  sendData("AT+CWMODE=1\r\n",               2000, true); // Configure as access point
  sendData(SSIDandPW,                       5000, true); // Pass of current wifi
  sendData("AT+CIPMUX=1\r\n",               2000, true); // Configure for multiple connections
  sendData("AT+UART_DEF=19200,8,1,0,0\r\n", 2000, true); // Set baud of COM
  sendData(eIPrIPmask,                      2000, true); // Default network mask IP
  sendData("AT+CIPSERVER=1,8080\r\n",         2000, true); // Turn on server on port 8080
  sendData("AT+GMR\r\n",                    2000, true); // Get firmware version
  sendData("AT+CIFSR\r\n",                  2000, true); // Get ip address
  Serial.println("Server is now running!");
  
    //send reset cmd
 // sendAT("AT+RST\r\n", 2000, DEBUG);
  //set to station mode
 // sendAT("AT+CWMODE=1\r\n", 2000 ,DEBUG);
  //connect to wifi
  //sendAT("AT+CWJAP=\""SSID"\",\""PWD"\"\r\n",5000 ,DEBUG);
//         "AT+CWJAP=\""SSID"\",\""PASS"\"\r\n"
 // while(!esp8266.find("OK")) {
    //wait for connection
    
  //}
  //print IP addr
  //sendAT("AT+CIFSR\r\n", 1000 ,DEBUG);
  //set to multiple connection mode
  //sendAT("AT+CIPMUX=1\r\n", 1000 ,DEBUG);
  //AT command to start a web server on port 8080
  //sendAT("AT+CIPSERVER=1,8080\r\n", 1000 ,DEBUG);
  //delay(4000);
 // Serial.println("initialization done...");
  
  //sendAT("AT\r\n", 1000);
}

String sendAT(String command, const int timeout, boolean debug) {
  String response="";
  esp8266.print(command);
  long int time = millis();
  while((time+timeout)>millis()) {
    while(esp8266.available()) {
      char c = esp8266.read();
      response += c;
    }
  }
  if(debug)
    Serial.print(response);
  return response;
}
