import matplotlib.pyplot as plt
import numpy as np

x = np.array([1.0, 2.0, 3.0])
print(x)
#[1, 2, 3]
print(type(x))
# <class ‘numpy.ndarray’>

x = np.array([1.0, 2.0, 3.0])
y = np.array([2.0, 4.0, 6.0])
print(x + y)
# ([3. , 6. , 9.])
print(x - y)
# ([-1. , -2. , -3.])
print(x * y)
# array([2. , 8., 18.])
print(x / y)
# array([0.5, 0.5, 0.5)

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
