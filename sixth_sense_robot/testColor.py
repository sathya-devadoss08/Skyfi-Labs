import cv2 as cv
import numpy as np
from matplotlib import pyplot as plt


cam = cv.VideoCapture(0)


while(1):
    ret, frame=cam.read()
    cv.imshow('Frame', frame)
    
    key = cv.waitKey(100)
    if key == 27:
         break
img_RGB = cv.cvtColor(frame, cv.COLOR_BGR2RGB)
plt.imshow(img_RGB)
plt.show()

cam.release()
cv.destroyAllWindows()
        
