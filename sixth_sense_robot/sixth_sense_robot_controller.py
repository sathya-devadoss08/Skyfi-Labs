import cv2 as cv
import numpy as np
import serial
import time

Arduino = serial.Serial('COM9', 9600,  timeout=0.05)
time.sleep(2)

cam = cv.VideoCapture(0)

lower_green = np.array([40,43, 60])
upper_green = np.array([69, 250,195])

while(1):
    ret, frame=cam.read()
    frame=cv.flip(frame,1);

    w = frame.shape[1];
    h = frame.shape[0]

    #smoothen the image
    image_smooth = cv.GaussianBlur(frame, (7,7), 0)

    #define roi
    mask = np.zeros_like(frame);

    mask[50:350, 50:350] = [255, 255, 255]
    image_roi = cv.bitwise_and(image_smooth, mask)
    cv.rectangle(frame, (50, 50), (350, 350), (0, 0, 255), 2)
    cv.line(frame, (150, 50), (150, 350), (0, 0, 255), 1)
    cv.line(frame, (250, 50), (250, 350), (0, 0, 255), 1)
    cv.line(frame, (50, 150), (350, 150), (0, 0, 255), 1)
    cv.line(frame, (50, 250), (350, 250), (0, 0, 255), 1)

    #threshold the image for green color
    image_hsv = cv.cvtColor(image_smooth, cv.COLOR_BGR2HSV)
    image_threshold = cv.inRange(image_hsv, lower_green, upper_green)

    #find contours
    contours, heirarchy = cv.findContours(image_threshold, \
                                                         cv.RETR_TREE, \
                                                         cv.CHAIN_APPROX_NONE)

    #find the index of largets contour
    if(len(contours) !=0):
        areas = [cv.contourArea(c) for c in contours]
        max_index = np.argmax(areas)
        cnt = contours[max_index]

        #pointer on video
        M = cv.moments(cnt)
        if(M['m00'] != 0):
            cx = int(M['m10']/M['m00'])
            cy = int(M['m01']/M['m00'])
            cv.circle(frame, (cx, cy), 4, (0,0,255), -1)

            #cursor Motion
            if cx in range(150, 250):
               if cy < 150:
                   #print("Upper Middle")
                   Arduino.write(b'f')
                   print("moving forward");
               elif cy > 250:
                  # print("Lower Middle")
                   Arduino.write(b'b')
                   print("moving backward");
               else:
                  # print("center")
                   Arduino.write(b's')
                   print("stopping");
            if cy in range(150, 350):
               if cx < 150:
                  # print("Left Middle")
                   Arduino.write(b'l')
                   print("moving left");
               elif cx > 250:
                  # print("Right Middle")
                   Arduino.write(b'r')
                   print("moving right");
               else:
                  # print("Center")
                   Arduino.write(b's')
                   print("stopping");
            line = Arduino.readline();
            line = line.decode("utf-8") #ser.readline returns a binary, convert to string
            print("ardino o/p==>" + line);
               
    cv.imshow('Frame', frame)
    key = cv.waitKey(100)
    if key == 27:
         break
cv.destroyAllWindows()
        
