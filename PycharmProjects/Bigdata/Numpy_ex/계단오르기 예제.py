# import random
# import matplotlib.pyplot as plt
#
# position = 0
# walk = [position]
# steps = 10
# for i in range(steps):
#     steps = 1 if random.randint(0, 1) else -1
#     position += steps
#     walk.append(position)
# print(walk)
#
# plt.figure()
# plt.plot(walk)
# plt.show()

import numpy as np
nsteps = 10
draws = np.random.randint(0, 2, size=nsteps)
print(draws)
steps = np.where(draws > 0, 1, -1)
walk = steps.cumsum()
print(walk)
print(walk.min())
print(walk.max())
tval = 2
print((np.abs(walk) >= tval).argmax())