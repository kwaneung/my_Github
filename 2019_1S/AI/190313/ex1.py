import matplotlib.pyplot as plt
import numpy as np

A = np.zeros((250, 250), dtype = np.uint8)
for x in range(0, 125, 1):
    A[x , x + 125] = 250
    A[x , -x -125] = 250
    A[x + 125, x] = 250
    A[x + 125, -x] = 250

plt.imshow(A, cmap='gray')
plt.show()