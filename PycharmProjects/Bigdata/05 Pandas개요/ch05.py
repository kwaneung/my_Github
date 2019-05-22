# from pandas import Series, DataFrame
# import numpy as np
import math


class Circle:
    counter = 0

    def __init__(self, radius=1.0):
        self.__radius = radius
        Circle.counter += 1

    def setRadius(self, r):
        self.__radius = r

    def calcArea(self):
        area = math.pi * self.__radius * self.__radius
        return area


c1 = Circle(10)
print("원의 넓이=", c1.calcArea())
print("circle 객체의 수=", c1.counter)

# data = DataFrame(np.arange(16).reshape((4, 4)),
#                 index=['Ohio', 'Colorado', 'Utah', 'New York'],
#                 columns=['one', 'two', 'three', 'four'])
# data[data['two']>5]


# sdata = {'Ohio': 35000, 'Texas': 71000, 'Oregon': 16000, 'Utah': 5000}
# obj3 = Series(sdata)
# data = {'state': ['Ohio', 'Ohio', 'Ohio', 'Nevada', 'Nevada'],
#         'year': [2000, 2001, 2002, 2001, 2002],
#         'pop': [1.5, 1.7, 3.6, 2.4, 2.9]}
# # frame = DataFrame(data)
# # print(frame)
# frame2 = DataFrame(data, columns=['year','state','pop','debt'],
#                 index=['one','two','three','four','five'])
#
# frame2['debt']=np.arange(5.)
# print(frame2)
