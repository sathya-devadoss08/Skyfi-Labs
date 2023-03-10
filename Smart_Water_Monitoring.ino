#include<SoftwareSerial.h>
byte statusLed=13;
byte sensorInterrupt=0;
byte sensorPin=2;

//for hall effect
float calibrationFactor=4.5;
volatile byte pulseCount;
float flowRate;
unsigned int flowMilliLitres;
unsigned long totalMilliLitres;
unsigned long oldTime;
unsigned int frac;
SoftwareSerial esp8266(3,4); //Rx pin=3, Tx pin =4

#define SSID "YOUR SSID"
#define PWD "UR PASSWORD"

String sendAT(String command, const int timeout) {
  String response="";
  esp8266.print(command);
  long int time = millis();
  while((time+timeout)>millis()) {
    while(esp8266.available()) {
      char c = esp8266.read();
      response += c;
    }
  }
  Serial.print(response);
  return response;
}

void connectWifi() {
  sendAT("AT\r\n", 1000);
  //set to station mode
  sendAT("AT+CWMODE=1\r\n", 1000);
  //connect to wifi
  sendAT("AT+CWJAP=\""SSID"\",\""PWD"\"\r\n",2000);
  while(!esp8266.find("OK")) {
    //wait for connection
    
  }
  //print IP addr
  sendAT("AT+CIFSR\r\n", 1000);
  //set to multiple connection mode
  sendAT("AT+CIPMUX=0\r\n", 1000);
}

void setup() {
  Serial.begin(9600);
  esp8266.begin(9600);
  //send reset cmd
  sendAT("AT+RST\r\n", 2000);
  connectWifi();
  //status led line
  pinMode(statusLed,OUTPUT);
  digitalWrite(statusLed, HIGH);
  pinMode(sensorPin, INPUT);
  digitalWrite(sensorPin, HIGH);
  pulseCount=0;
  flowRate=0.0;
  flowMilliLitres=0;
  totalMilliLitres=0;
  oldTime=0;
//sensor connected to pint 2 which is interrupt 0
  attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
  

}

void loop() {
  if((millis()-oldTime)>1000) {
    //disable for now
    detachInterrupt(sensorInterrupt);
    flowRate=((1000.0/(millis()-oldTime))*pulseCount)/calibrationFactor;
    //save the time
    oldTime=millis();
    //convert to litres per minute
    flowMilliLitres=(flowRate/60)*1000;

    totalMilliLitres+=flowMilliLitres;

    //print now
    Serial.print("Flow rate:");
    Serial.print(int(flowRate));
    Serial.print(".");
    //fraction of flowRate
    frac=(flowRate-int(flowRate))*10;
    Serial.print(frac,DEC);
    Serial.print("L/min");

    Serial.print("current Liquid Flowing:");
    Serial.print(flowMilliLitres);
    Serial.print("mL/sec");

    Serial.print("Output Liquid Quantity:");
    Serial.print(totalMilliLitres);
    Serial.print("mL");
    
    //reset
    pulseCount=0;
    //enable again
    attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
  }

  String F = String(frac);
  String FM = String(flowMilliLitres);
  String TM = String(totalMilliLitres);
  updateTS(F,FM,TM);
  delay(3000);

}

void updateTS(String F, String FM, String TM) {
  Serial.print("");
  sendAT("AT+CIPSTART=\"TCP\",\"api.thinkspeak.com\",80\r\n", 1000);
  delay(2000);
  //replace xxx with ur api key
  String cmd = "GET/update?key=xxxx&field1="+F +"&field2=" + FM + "&field3="+TM+"\r\n";
  String len = String(cmd.length());
  sendAT("AT+CIPSEND=" + (len) + "\r\n", 2000);
  esp8266.print(cmd);
  sendAT("AT+CIPCLOSE", 2000);
  Serial.print("");
}

void pulseCounter() {
  //increment
  pulseCount++;
}
