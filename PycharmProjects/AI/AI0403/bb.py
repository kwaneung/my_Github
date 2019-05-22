import numpy as np
import cv2

srcImage = cv2.imread("add1.jpg",1)
Template = cv2.imread("add2.jpg",1)

Rows_srcImage, cols_srcImage = srcImage.shape[:2]#원본 이미지 크기
Rows_template, cols_template = Template.shape[:2]#템플릿 이미지 크기

Temp_mean = np.mean(Template)
min_mean = 1000000
finalX,finalY = 0,0

for i in range(Rows_srcImage - Rows_template):
    for j in range(cols_srcImage - cols_template):

        comp_data = srcImage[i:i+Rows_template, j:j+cols_template]

        mean_data = np.mean(comp_data)
        dist = np.linalg.norm(mean_data - Temp_mean)
        if min_mean > dist:
            min_mean = dist
            finalX,finalY = j,i

rect = (finalX,finalY,cols_template,Rows_template)
cv2.rectangle(srcImage, rect, (0,255,0), 3)
cv2.imshow('srcImage', srcImage)
cv2.waitKey(0)