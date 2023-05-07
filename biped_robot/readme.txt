You Tube details
Title - Biped Walking Robot - Project assignment for Skyfi Labs online course - by Sathya Devadoss

Description - This video is made by Sathya Devadoss of Middle College High School as part of the final assignment of Biped Walking Robot course from Skyfi Labs. The Biped Walking Robot Project kit from Skyfi Labs was used along with online course tutorials to complete this project.

Git Hub Url
  https://github.com/sathya-devadoss08/Skyfi-Labs

Items used in this,
 6 servo motor with metal horn
 1 servo sheild (16 channel)
 6 multipurpose servo bracket
 6 u clamp
 1 L clamp
 1 long u bracket
 1 biped foot
 6 cub bearing
 6 m3 locknut
 30 m3 screws (6mm)
 30 m3 screws (10mm)
 30 m3 nuts
 24 m4 screws
 24 m4 nuts
 4 m3 flat head screws
 male to male jumper wires
 male to female jumper wires


For M3 screws,(we need 6mm & 10mm)
https://www.amazon.com/Socket-Screws-Bolts-Thread-100pcs/dp/B07CMSBQ11/ref=sr_1_3?keywords=m3+10mm&qid=1678256072&s=industrial&sr=1-3
https://www.amazon.com/Socket-Screws-Bolts-Thread-100pcs/dp/B07CMRQ3TB/ref=sr_1_3?keywords=m3%2B10mm&qid=1678256072&s=industrial&sr=1-3&th=1

M3 nuts
https://www.amazon.com/Uxcell-a16033100ux0563-Carbon-Steel-Hexagon/dp/B01IWUSDYY/ref=sr_1_3?keywords=m3+nuts&qid=1678256234&s=industrial&sr=1-3

M4 nuts
https://www.amazon.com/uxcell-Metric-Stainless-Hexagon-Silver/dp/B07H3VF3BF/ref=sr_1_2_sspa?keywords=m4+nuts&qid=1678256283&s=industrial&sr=1-2-spons&psc=1&smid=A30WUG2ZDGM0XM&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExOVUyME5GRzdUOE9YJmVuY3J5cHRlZElkPUEwNTkxMTg0MzU3M0hSWDFQUjc3SiZlbmNyeXB0ZWRBZElkPUEwODQ5MDkyMlVTRTVZOVpRWk1OJndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==

M4 screws
https://www.amazon.com/HELIFOUNER-Pieces-Button-Washers-Stainless/dp/B09GRHHXT5/ref=sr_1_4?keywords=m4+screws&qid=1678256323&s=industrial&sr=1-4

Servo Driver
https://www.amazon.com/SongHe-Channel-interface-PCA9685-arduino-Raspberry/dp/B082QT9D5F/ref=sr_1_3?crid=2KOS9X5QXGUP8&keywords=pwm+servo+motor+driver&qid=1678256888&sprefix=pwm+serv%2Caps%2C253&sr=8-3

Servo motor
https://www.amazon.com/ETMall-Digital-Helicopter-Compatible-Raspberry/dp/B08CH2SJLR/ref=sr_1_4_sspa?keywords=mg995+servo&qid=1678256979&sprefix=mg995%2Caps%2C288&sr=8-4-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExVUdDMFdPVTMwNEg5JmVuY3J5cHRlZElkPUExMDE4NDE2RlZFWjZFNkVQTVJCJmVuY3J5cHRlZEFkSWQ9QTAyNTQ2NjgyNllITFY2NzFUOTc0JndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==


Voice over
Hello,
  This is Sathya Devadoss.
  This video is about Biped Walking Robot using GAIT algorithm.
  I have assembled 2 legs and a hip as part of this project.
  The left leg has 3 servo motors and the right leg has 3 motors.
  The 2 legs are assembled separately and joined by the hip connector.
  The motors are connected to Arduino using a servo shield (we are using 16 channel servo driver shield for this, which means we can control 16 motors with this).
  Before assembling the legs, all motors are zero set to 90 degree(this step is important).
  In the loop() method we go thru 6 steps to move various motors according to GAIT algorithm to simulate human walking pattern.


Detailed Description:
====================
follow below description along with the video,

Ankle assembling
===============
Step 1: assembling each ankle
   for each ankle we need below items (for each leg, so multiply by 2)
    1 biped foot
    1 multipurpose servo bracket
    star head screw driver & nose plier
    4 m3 flat head screws
    4 m3 nuts
    
    attach servo bracket to the biped foot, assemble such that the side of foot which has grove to keep m3 flat head screws hidden should be at bottom, and also the 4 (12mm) holes should be at front.
    
Step 2: attach u clamp to ankle servo bracket
 needed items,
  1 u bracket
  1 cub bearing
  10mm m3 screws
  1 lock nut
  
  b4 attaching u clamp, 
    => insert the 10mm m3 screw from 2nd hole of servo bracket (from right for left ankle and from left for right ankle) of the multi-purpose servo bracket.
    head of the screw should be towards the front of the foot
    => then insert the cub bearing to the bracket hole and insert into the m3 screw and tighten with the lock nut
    The clamp should be able to move freely
    
Step 3: attaching the servo motor(for foot movement)
  need below items,
    1 servo motor
    4 m4 screws and nuts
  
  => servo must be zero set to 90 degrees
  => for left ankle attach the motor to right side of the bracket
  => in servo motor fix the metal servo horn with a m3 screw
  => fix the servo motor to the arm of the bracket with m4 screws and nuts
    then fix the u-clamp to the servo clamp with m4 screws.
    
Knee assembling
===============
step 1: fix L clamp to foot we built.
  need below items,
    1 L clamp
    4 m3 screws (10mm) and m3 nuts
  => fix L clamp to foot, long side should face the front and tighten with the m3 screws and nuts (put screw from top)
  => Do the same for Right knee
  
Step 2: now ready the knee join for left
  need below items,
    2 u clamps
    4 m3 screws of 10mm and 4 m3 nuts
    
    => attach both clamps to each other with m3 screws and nuts such a way that 2 u-clamps face opposite to each other.
    
Step 2A:    
    Now attach the above u clamp to a multipurpose bracket
     need below items,
      1 multi bracket 
      1 cub bearing
      1 lock nut
      1 m3 screw (10 mm)
    => attach the clamp to right side 2nd hole of the bracket with m3 screw, now from outside insert the cub bearing for the bracket and tighten with the lock nut
    => Do the same for right but attach to left side 2nd hole
     
Step 3
  now we need to attach the knee join we built to the clamp of the left knee with 4 m3 (6mm) screws
Step 4 : now attach the servo motor (for knee movement)
  
  need below
    1 servo motor with metal horn
    4 m4 screws and nuts
  => servo motor should be zero set to 90 degrees
  => attach to the arms using m4 screws and nuts
  
Hip assembling
==============

Step 1:
need below,
  1 long u bracket
  2 multi purpose servo bracket
  8 m3 screws (6mm)
  8 m3 lock nuts
  - attach both the servo bracket to u bracket with arms of servo bracket facing down and outward and screws inserted from down.
Step 2:
 attaching the assembled bracket to left leg 
  1 cub bearing
  1 m3 screw (10mm)
  1 m3 nut
  => attach one side of the multi purpose bracket to the u clamp of left leg   
    => to attach insert m3 screw thru the bracket and to the u-clamp, add the cub bearing to the m3 screw and tight with the nut.
  => do the same for right leg.
Step 3 : now attach the servo motors (for hip movement)
  need below items,
    2 servo motor
    8 m4 screws and nuts
    
wiring details:

Step 1: connect motors to the sheild
  the sheild we use supports 16 motors, we are using 6 for this project, so we will use channels 0, 2, 4,6,8,10
    0 => for left foot
    2 => for left knee
    4 => for left hip
    6 => for right hip
    8 => for right knee
    10 => for right foot
    => make sure brown wire of motor goes to black pin in channel
    => red wire of motor goes to red pin in channel
    => orange wire of motor goes to yellow pin in channel

Step 2: connect servo driver sheild to Arduino
  => vcc pin from sheild goes to 5v of Arduino
  => gnd pin to ground pin of Arduino
  => sda pin to A4 pin of Arduino
  => scl pin to A5 pin of Arduino
  
Step 3: power the servo driver
  connect vcc and gnd of driver to a power supply
    => for this project we cut a usb cable to connect to power supply of the servo driver.

