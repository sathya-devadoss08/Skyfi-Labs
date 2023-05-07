WiFi Controlled Robot

YouTube Title - WiFi Controlled Robot - Project assignment for Skyfi Labs online course - by Sathya Devadoss

YouTube Description - This video is made by Sathya Devadoss of Middle College High School as part of the final assignment of WiFi Controlled Robot course from Skyfi Labs. The WiFi Controlled Robot kit from Skyfi Labs was used along with online course tutorials to complete this project.

Git Hub Url
  https://github.com/sathya-devadoss08/Skyfi-Labs/blob/main/WiFi_Controlled_Robot.ino

Items needed:
Arduino UNO
Arduino UNO USB Cable
ESP8266 WiFi Module
1k Resistors - 5 Nos.
Motor Driver - 1 No.
DC motors - 2 Nos.
Wheels for Motors - 2 Nos.

Chassis - 1 No.
U Clamps - 2 Nos.
Castor Wheels - 1 No.
Capacitors (100 & 1000 Micro Farad)
Wire stripper
Screwdriver - 2 Nos.
Other miscellaneous items
Arduino IDE
  https://www.arduino.cc/en/software
Jumper wires
=============
  https://www.amazon.com/EDGELEC-Breadboard-Multicolored-1pin-1pin-Connector/dp/B07GD1ZCHQ/ref=sr_1_1_sspa?crid=2S2F1PHH3GQLE&keywords=male+to+male+wire&qid=1678428761&sprefix=male+to+male+wire%2Caps%2C154&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUFKT1RUSVg3TzRKRDEmZW5jcnlwdGVkSWQ9QTAxODQzMDYzSVNZNFhQM0xNOURSJmVuY3J5cHRlZEFkSWQ9QTAyNDA1NTAyMVk5WkdGTE9VMUJSJndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==
  https://www.amazon.com/EDGELEC-Breadboard-Optional-Assorted-Multicolored/dp/B07GD2BWPY/ref=sr_1_1_sspa?crid=1U29WMGF9XKAL&keywords=male+to+female+wire&qid=1678428782&sprefix=male+to+female+wire%2Caps%2C160&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEzOVJCWFZaWFFaV1hIJmVuY3J5cHRlZElkPUEwMTYxNzQ2MUVGNzNGMVBUR1lRTyZlbmNyeXB0ZWRBZElkPUEwNTg5OTEyMllXVUtWN05NT0hZWSZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=

Arduino uno
  https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/ref=sr_1_1?keywords=Arduino+uno&qid=1679542476&s=industrial&sr=1-1-catcorr
 
L293d motor driver ic & L293 motor driver ic
  https://www.amazon.com/Bridgold-16-pin-Stepper-Drivers-Controllers/dp/B07NXTWJV9/ref=sr_1_2?crid=2VRMJTOZUUQXY&keywords=L293d+motor+driver+ic&qid=1679542591&s=industrial&sprefix=l293d+motor+driver+ic%2Cindustrial%2C147&sr=1-2
  https://www.amazon.com/Bridgold-16-pin-Stepper-Drivers-Controllers/dp/B07NXTWJV9/ref=sr_1_3?crid=QDRDZG9KGBJU&keywords=l293+motor+driver&qid=1679543055&s=industrial&sprefix=l293+motor+%2Cindustrial%2C143&sr=1-3

 Motors
  https://www.amazon.com/Cylewet-Motor-Shaft-Arduino-CYT1037/dp/B01N9MS3UZ/ref=sr_1_31?crid=24MJZN102C28X&keywords=bo+one+motors+for+arduino+wheels&qid=1679543427&s=industrial&sprefix=bo+one+motors+for+arduino+wheels%2Cindustrial%2C141&sr=1-31
  https://www.amazon.com/BOJACK-Pcs-Type-130-EK1450/dp/B09FPXF1QK/ref=sr_1_2?crid=EOQUS110TR8O&keywords=dc+motor+for+arduino&qid=1679543537&s=industrial&sprefix=dc+motor+for+a%2Cindustrial%2C132&sr=1-2
  
Detailed description
====================

====
=> WiFi stands for Wireless Fidelity
=> Elements of Wifi
  => Access point
  => Distribution system
  => wireless medium
  => station
=> Access point
  => router acts as a wireless Access point
  => enables connected wireless devives to exchange information with the wired network
  => 
=> Distribution system
  => connects various access points and mediates between access point and internet
=> station
  => 
=> ESP 8266
  => works with 3 - 3.6 v
  => CH_PD -> enabling pin
  => TX, Rx to 
=> Hayes commands
  => command language to control modem
  => combination of series of short texts for modem operation.
  => AT => attention
    => informs the modem about start of a command
  => 4 set of commands
    => test commands => test if the command is supported by the chip
    => read
    => set
    => execution
  => https://www.electronicshub.org/esp8266-at-commands/
  => AT+CWMODE=<mode>
    => set command to set wifi mode
    => mode => allowd values, 1,2 or 3,
      => Station(1), AccessPoint(2) or both modes(3)
  => AT+CWLAP
    => execute command
    => list all available access points - wifi & hotspots
  => AT+CWJAP="SSID","pwd"
    => set command
    => set to join the wifi network with this ssid & pwd
  => AT+CIPSTART
    => execute command
    => setup tcp/ip connection to send data
  => AT+CIPSEND
    => execute command
    => send data over the tcp/ip connection
  => AT+CIFSR
    => execute command
    => used to get the ip addr of the exp8266 assigned by the access point

Step 1- Assemble Wheels and 1 of the Chassis of the Robot
=========================================================
items needed
  2 wooden chassi
  wheels (2)
  castor wheels (1)
  2 bo one motor
  2 metal clamps
  4 60mm M3 screws
  4 30mm M3 screws
  3 45mm M3 screws
  6 M3 nuts
  
  => attach the metal clamps to each side of wooden chasis using 60 mm M3 screws (attach closer to one end of the wooden chasis as this will become the wheel holders and also insert the screw from bottom so that it protrudes upward which will be used to place the 2nd layer of wooden chasis)
  => now insert 2 30mm M3 screws to each of the bo one motors.
  => now attach the motors to each metal clamp by inserting the m3 screw which is protruding the motor to the clamp (motor should be placed outward and shaft should be projecting outward) and tighten with the m3 nuts.
  => now attach the wheels to the motors shaft and secure it with a screw.
  => insert 3 45 mm m3 screw to the castor wheel and secure with m3 nuts.
  => now insert m3 nut on each screw, this will be used to secure and adjust the height of caster wheel.
  => now attach the castor wheel to the front and tighten it with m3 screws  and adjust the height to level with other wheels.
  
Step 2: place the 2nd wooden chasis and other components
  => insert a m3 nut to the protuding 60mm screw (from the metal clamps), this will help in holding the 2nd wooden chasis in place
  => now place the 2nd wooden chasis on top of the 1st one by inserting the produting screw to this wooden chasis and tighten it with the m3 nuts (both nuts, from bottom and up)
  => with a double sided tape stick the motor driver and Arduino uno on the 2nd wooden chasis such a way that motor driver is near to the back wheel motors and Arduino uno near front.

Step 3 : interface wheel Motors with motor driver circuit (L293 motor driver)
========
  => take 2 sets of jumper wires (male to male) and solder each one with the terminal wires of the wheel motor.
    => use same color for the 2 positive wires of motors and same color for -ve terminal of the motors.
  => connect left Motor as below
    +ve terminal to MB1 of L293 driver
    -ve terminal to MB2 of L293 driver
  => connect right Motor as below
    +ve terminal to MA2 (* see its MA2) (becos its placed in opposite direction)
    -ve terminal to MA1
    
Step 4: interface motor driver circuit (L293) with Arduino uno
=======
  => take 2 sets of jumper wires (female to male) and solder both at male end.
  => now take another male to male jumper wires and solder one end with the above step's male end.
  => now connect  the 2 female ends to EN A & EN B of driver and connec the soldered male end to 5v of Arduino.
  => connect V- to GND pin of Arduino.
  => now power the motor driver with a 9v Battery with the help of a battery connector.
  => connect the +ve wire of the batery connector to V+ pin of motor driver
  => connect the -ve wire of the batery connector to GND pin of motor driver
  => use female to male jumper wires for below
    => INP A1 to digital pin 8 (left motor)
    => INP A2 to digital pin 9 (left motor)
    => INP B1 to digital pin 10 (right motor)
    => INP B2 to digital pin 11 (right motor)
  => connect 9 volt batter to motor driver
      => connect v+ to +ve terminal of battery
      => connect GND to -ve terminal of battery

Step 5: ESP8266 wifi module - Interfacing with Arduino
=======
  items needed
    esp 8266 wifi module
    Arduino uno
    battery and a barrel connector

  Wiring details:
    pins 'VCC' and 'CH_PD' of ESP8266 should be connected to 3.3v of Arduino,
      for this we used electric Wire Connector which connects all lines to single line, so we connect 3 male to female wire to the wire connector, and other ends of the wires to vcc, en (of esp8266) and 3.5(of Arduino)
     https://www.amazon.com/GKEEMARS-Connector-Conductor-Connectors-Splicing/dp/B08P1LXKY5/ref=sr_1_1_sspa?keywords=electric+wire+connectors+for+wiring&qid=1678342082&sprefix=electric+wire+conn%2Caps%2C204&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEzRjNCMUpMUk82SDVSJmVuY3J5cHRlZElkPUEwNDM2ODUwMTlLNjdYSUMxREJNUCZlbmNyeXB0ZWRBZElkPUEwNDU3NDkyTVU1NzJENFM4MU83JndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==
   => use female to male jumper wires for below,
    pin 'GND' of ESP8266 should be connected to GND pin of Arduino
    pin 'RX' of ESP8266 should be connected to pin A3 of Arduino
    pin 'TX' of ESP8266 should be connected to pin A2 of Arduino
    

    
