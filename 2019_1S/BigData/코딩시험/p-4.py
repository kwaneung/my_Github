import numpy as np
import matplotlib.pyplot as plt


stock = np.genfromtxt('stock.txt', dtype=None, encoding='ascii')


def make_simple_bar_chart():

    stkname = []
    stkvalue = []

    for i in range(len(stock)):
        stkname.append(stock[i][0])
        stkvalue.append(stock[i][1])

    xs = [i + 0.5 for i, _ in enumerate(stkname)]

    plt.bar(xs, stkvalue)
    plt.xlabel("Stock name")
    plt.ylabel("Stock price")
    plt.title("Stock list")

    plt.xticks([i + 0.5 for i, _ in enumerate(stkname)], stkname)

    plt.show()


make_simple_bar_chart()
