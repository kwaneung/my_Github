import matplotlib.pyplot as plt
import numpy as np

A = np.zeros((250, 250), dtype = np.uint8)

for x in range(0, 126, 1):
    A[:, x] = x
    A[:, -x] = x

plt.imshow(A, cmap='gray')
plt.show()
