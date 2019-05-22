import matplotlib.pyplot as plt
import numpy as np

trainData = np.array([[0,0],[0,1],[1,0],[1,1]])


ANDoutput = np.array([0,0,0,1])
NANDoutput = np.array([1,1,1,0])
ORoutput = np.array([0,1,1,1])


step = 100
input = 2; out = 1
w = np.random.rand(input, out); b = np.random.randn(1)
a = np.arange(-1, 2, 0.5)

eta = 0.5

for j in range(1, step, 1):
    for i in range(0, 4, 1):
        x = trainData[i]
        ry = NANDoutput[i]
        if (np.dot(x, w) + b) > 0:
            y = 1
        else:
            y = 0

        e = ry - y

        dw = eta * e *np.transpose([np.array(x)])
        db = eta * e * 1

        w = w + dw
        b = b + db


plt.plot(trainData[:,0], trainData[:,1], '*')
plt.plot(a, (-w[0, 0]*a - b)/w[1, 0], 'r')
plt.show()