import matplotlib.pyplot as plt
import numpy as np
x = np.arange(0, 6, 0.1)
y1 = np.sin(x)
y2 = np.cos(x)

plt.plot(x, y1, 'r', label = "sin")
plt.plot(x, y2, 'g',  linestyle = "--", label = "cos")
plt.grid()
plt.xlabel("x")
plt.ylabel("y")
plt.title('sin & cos')
plt.legend()
plt.show()