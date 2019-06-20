import numpy as np
import matplotlib.image as img

path = "C:\\Users\\whats\\PycharmProjects\\AI\\190320\\testData\\"
trainData = np.zeros((20 * 16, 8))#8이 한종류의 템플릿의 수
meanData = np.zeros((20 * 16, 10))#10이 템플릿 종류의 수


for i in range(0, 10, 1):#숫자범위
    for j in range(1, 8, 1):#각 숫자별 탬플릿 수.
        fn = path + "digit%d_%d.bmp" % (i, j)
        xi = img.imread(fn)
        x = xi[:, :, 0].reshape(16 * 20) / 255 #정규화 하는것. 실수 형태로 바꿔주기 위해.
        trainData[:, j] = x
    meanData[:, i] = np.mean(trainData, 1)

k = input("파일명을 입력하세요 : ")
fn = path + k
x = img.imread(fn)
data = x[:, :, 0].reshape(16*20) / 255

distArray = []

for i in range(0, 8, 1):
    dist = np.linalg.norm(meanData[:, i] - data)
    distArray.append(dist)

minVal = distArray.index(min(distArray))

print("입력한 데이터는 %d 입니다" % (minVal))