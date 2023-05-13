import cv2 as cv
import numpy as np



cam = cv.VideoCapture(0)

lower_green = np.array([40,43, 60])
upper_green = np.array([69, 250,195])

while(1):
    ret, frame=cam.read()
  
    #smoothen the image
    image_smooth = cv.GaussianBlur(frame, (7,7), 0)

    #threshold the image for green color
    image_hsv = cv.cvtColor(image_smooth, cv.COLOR_BGR2HSV)
    image_threshold = cv.inRange(image_hsv, lower_green, upper_green)

    #find contours
    contours, heirarchy = cv.findContours(image_threshold, \
                                                         cv.RETR_TREE, \
                                                         cv.CHAIN_APPROX_NONE)
    if(len(contours) !=0):
        areas = [cv.contourArea(c) for c in contours]
        max_index = np.argmax(areas)
        cnt = contours[max_index]
        x_bound, y_bound, w_bound, h_bound = cv.boundingRect(cnt)
        cv.rectangle(frame, (x_bound, y_bound), (x_bound+w_bound, y_bound + h_bound), (255, 0,0),2)
        
    cv.imshow('bounded frame', frame)
    key = cv.waitKey(100)
    if(key == 27):
         break

cam.release()
cv.destroyAllWindows()
        
