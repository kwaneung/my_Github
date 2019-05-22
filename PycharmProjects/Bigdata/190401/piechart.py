from matplotlib import pyplot as plt

plt.pie([0.85, 0.05], labels=["Uses pie charts", "Knows better"])

# make sure pie is a circle and not an oval
plt.axis("equal")
plt.show()
