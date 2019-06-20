import numpy as np
import cv2

# 이미지 불러오기
srcImage = cv2.imread("plate1.jpg")

# 컬러 변환
grayImage = cv2.cvtColor(srcImage, cv2.COLOR_BGR2GRAY)

# 이진 이미지 생성
ret, binaryImage = cv2.threshold(grayImage, 100, 255,
cv2.THRESH_BINARY_INV)

# 이진 이미지 필터링
kernel = np.ones((6, 6), np.uint8)
binaryImage = cv2.erode(binaryImage, kernel, iterations=1)
binaryImage = cv2.dilate(binaryImage, kernel, iterations=3)
binaryImage = cv2.erode(binaryImage, kernel, iterations=1)

# 객체 레이블링
nlabels, labels, stats, centroids = cv2.connectedComponentsWithStats(binaryImage)

# 레이블링 결과 출력
for i in range(1, nlabels):
    rect = (stats[i][0], stats[i][1], stats[i][2], stats[i][3])
    cv2.rectangle(srcImage, rect, (0, 255, 0), 3)

# 이미지 출력
cv2.imshow('srcImage', srcImage)
cv2.imshow('binaryImage', binaryImage)
cv2.waitKey(0)