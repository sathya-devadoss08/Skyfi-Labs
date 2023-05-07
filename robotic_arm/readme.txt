Hello there
  this is about Robotic Arm - Project assignment for Skyfi Labs online course
  as in cource I have used 4 stepper motors, x, y, z, and g
  these motors are attached to 9, 10, 11 and 6 pwm pins of arduino board.
  
  as u see here I have used this to pick up an object from a location
  and drop the object in another place by rotating the motors to various angular positions.
  
  i experimented various startup position and various angles to rotate for all this motors and
  finalized on this logic.
  
  first I Move motor y from 60 to 140 - this moves the arm towards the object
  then I rotate the motor g from 90 to 0 , this grabs the object
  now move motor y from 140 to 60, this moves the arm up with the picked up object
  now move motor x from 0 to 90, to rotate towards the destination
  
  Now to drop the object, move motor y from 60 to 140
  to release the object rotate motor g from 0 to 90
  after releasing move up Y from 140 to 60 to strighten the robot
  now move to oringal position by rotating X from 90 to 0
  
code desc:
==========
  This is the code to control the motors, 
  We are using pwd pins 9, 10, 11 & 6 for motar x, y , z and g respectively.
  We have a method named 'arm' to setup the initial position of the motars.
  The setup method is used to attach the pins to the servo motors and call arm method to put the motors in startup position
  inside the loop method we are having the whole logic to pick and drop an object.
  in order to simplify we have defind a move method which takes start and end position for the motor position and using for loop we move from one rotation point to another
  
  
  