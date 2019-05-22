from matplotlib import pyplot as plt
import collections

grades = [83, 95, 91, 87, 70, 0, 85, 82, 100, 67, 73, 77, 0]
decile = lambda grade: grade // 10 * 10
histogram = collections.Counter(decile(grade) for grade in grades)# -> test

plt.bar([x + 5 for x in histogram.keys()],  # shift each bar to the left by 4
        histogram.values(),  # give each bar its correct height
        8, color='g')  # give each bar a width of 8
plt.axis([0, 110, 0, 5])  # x-axis from -5 to 105, y-axis from 0 to 5  test

plt.xticks([10 * i for i in range(11)])  # x-axis labels at 0, 10, ..., 100
plt.xlabel("Decile")
plt.ylabel("# of Students")
plt.title("Distribution of Exam 1 Grades")
plt.show()