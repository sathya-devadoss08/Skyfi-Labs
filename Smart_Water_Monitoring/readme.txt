You Tube details
Title - Smart Water Monitoring using IoT - Project assignment for Skyfi Labs online course - by Sathya Devadoss
Description - This video is made by Sathya Devadoss of Middle College High School as part of the final assignment of Smart Water Monitoring using IoT course from Skyfi Labs. The Smart Water Monitoring using IoT kit from Skyfi Labs was used along with online course tutorials to complete this project.

Git Hub Url
  https://github.com/sathya-devadoss08/Skyfi-Labs
Jumper wires
=============
  https://www.amazon.com/EDGELEC-Breadboard-Multicolored-1pin-1pin-Connector/dp/B07GD1ZCHQ/ref=sr_1_1_sspa?crid=2S2F1PHH3GQLE&keywords=male+to+male+wire&qid=1678428761&sprefix=male+to+male+wire%2Caps%2C154&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUFKT1RUSVg3TzRKRDEmZW5jcnlwdGVkSWQ9QTAxODQzMDYzSVNZNFhQM0xNOURSJmVuY3J5cHRlZEFkSWQ9QTAyNDA1NTAyMVk5WkdGTE9VMUJSJndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==
  https://www.amazon.com/EDGELEC-Breadboard-Optional-Assorted-Multicolored/dp/B07GD2BWPY/ref=sr_1_1_sspa?crid=1U29WMGF9XKAL&keywords=male+to+female+wire&qid=1678428782&sprefix=male+to+female+wire%2Caps%2C160&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEzOVJCWFZaWFFaV1hIJmVuY3J5cHRlZElkPUEwMTYxNzQ2MUVGNzNGMVBUR1lRTyZlbmNyeXB0ZWRBZElkPUEwNTg5OTEyMllXVUtWN05NT0hZWSZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=

Water Sensor
=============
  https://www.amazon.com/HiLetgo-1-75MPa-Flowmeter-Control-Arduino/dp/B01N2NJQHD/ref=sr_1_4?keywords=water+flow+sensor&qid=1678428818&sprefix=water+flow%2Caps%2C146&sr=8-4

ESP8266   
  https://www.amazon.com/ESP8266-Updated-Wireless-Transceiver-Arduino/dp/B07H1W6DJZ/ref=sr_1_10?crid=1AE6WW95Q5X6D&keywords=esp+8266&qid=1679764481&sprefix=%2Caps%2C674&sr=8-10

esp8266 'AT' commands
======================
  https://www.electronicshub.org/esp8266-at-commands/

Voice over
===========
Hello,
  This is Sathya Devadoss.
  This video is about Smart Water Monitoring using IoT
  In this video we will connect an Water Flow Sensor with Arduino and also connect ESP8266 wifi module and Interface with Arduino.
  With this we will be able to calculate the water used and upload to websites for analysing.
  I have uploaded the program to github for downloading. but make sure u change the ssid, password and api key to your values.
    https://github.com/sathya-devadoss08/Skyfi-Labs
  The program calculates the water used per minute and outputs to serial monitor and also uploads the data to https://thingspeak.com/
Detail Description
==================
Step 1: Interfacing Water Flow Sensor with Arduino
  items needed
    male to male connector wires (if possible with an extender wire)
    water sensor 
    
    wiring water sensor
      red wire in sensor is vcc => connct to 5v pin of Arduino
      black wire is ground => connct to Gnd pin of Arduino
      yellow wire is signal pin => connct to pin 2 of Arduino
      
      I also used a adapter bought from home depo and used to connect sensor to water supply.
      
Step 2: ESP8266 wifi module - Interfacing with Arduino
  items needed
    esp 8266 wifi module
    Arduino uno
    battery and a barrel connector

  Wiring details:
    pins 'VCC' and 'En' of ESP8266 should be connected to 3.3v of Arduino
      for this we used electric Wire Connector which connects all lines to single line, so we connect 3 male to female wire to the wire connector, and other ends of the wires to vcc, en (of esp8266) and 3.5(of Arduino)
     https://www.amazon.com/GKEEMARS-Connector-Conductor-Connectors-Splicing/dp/B08P1LXKY5/ref=sr_1_1_sspa?keywords=electric+wire+connectors+for+wiring&qid=1678342082&sprefix=electric+wire+conn%2Caps%2C204&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEzRjNCMUpMUk82SDVSJmVuY3J5cHRlZElkPUEwNDM2ODUwMTlLNjdYSUMxREJNUCZlbmNyeXB0ZWRBZElkPUEwNDU3NDkyTVU1NzJENFM4MU83JndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==
      
    pin 'GND' of ESP8266 should be connected to GND pin of Arduino
    pin 'RX' of ESP8266 should be connected to pin A4 of Arduino
    pin 'TX' of ESP8266 should be connected to pin A3 of Arduino
    


Step 3: Reading Data from Water Flow Sensor


esp 8266 wiring
orange - rx - pin 3
yellow - tx - pin 4
blue - gnd
green - 3.3v


sensor wiring
red - + - red
yellow - signal - blue - pin 2
black - gnd - purple

==========

AT+UART_DEF=9600,8,1,0,0
AT+GMR
AT+CWMODE=1 //station mode, can only send or push data
AT+CWMODE=2 //Access point mode, this is same as wifi or hotspot mobile
AT+CWMODE=3 //both AP and station mode, put into access point mode

AT+CWLAP => list all hot spots

AT+CWJAP="SSID","PWD" => to connect to wifi
AT+CIFSR => fetches the ip and mac address


ESP8266   
  https://www.amazon.com/ESP8266-Updated-Wireless-Transceiver-Arduino/dp/B07H1W6DJZ/ref=sr_1_10?crid=1AE6WW95Q5X6D&keywords=esp+8266&qid=1679764481&sprefix=%2Caps%2C674&sr=8-10

esp8266 'AT' commands
======================
  https://www.electronicshub.org/esp8266-at-commands/


Code Explanation
===============
   => The code is uploaded to the github please go ahead and have a look.
    => https://github.com/sathya-devadoss08/Skyfi-Labs
   => The water sensor we are using sends a interrupt signal to our arduino pin 2 (set as input pin).
   => First we define all the variables we need like flowRate, sensorPin etc
      => we also define ssid & pwd for the esp module to connect to internet
        => here give ur house internet name(ssid) and password, if u click on wireless icon you will see all ur wireless names
   => in setup() method 
      => we attach a method 'pulseCounter' to this interupt pin (for falling mode pulse mode), so when ever the sensor senses a water flow it sends a interupt signal which we count.
        attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
          => in above we are attaching 'sensorInterrupt pin to call 'pulseCounter' method for every FALLING point of pwm pulse.
        => in setup() method we also initialize all the variables and set up the esp module by calling sendAT & connectWifi methods.
  => in loop() method all we do is calculate the water flow by checking our pulse count (which is incremented whenever we got a interupt).
    => we do the calcultion only for every minute, so we wait for a minute b4 doing our calculation.
    => we also do one things, we disable the sensor intertupt while we are calculating so that we dont mess our calculation. 
      detachInterrupt(sensorInterrupt);
    => after calculation we attach back.
 => the code also uploads the data to internet (https://thingspeak.com) using our esp8266 chip.
  => pls check below url for wifi module AT commands (the link is added in description)
    https://www.electronicshub.org/esp8266-at-commands/

=> 
  


