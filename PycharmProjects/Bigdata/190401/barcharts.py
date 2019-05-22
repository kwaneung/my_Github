from matplotlib import pyplot as plt

movies = ["Annie Hall", "Ben-Hur", "Casablanca", "Gandhi", "West Side Story"]
num_oscars = [5, 11, 3, 8, 10]
test = ['a', 'b', 'c', 'd', 'e']

# bars are by default width 0.8, so we'll add 0.1 to the left coordinates
# so that each bar is centered
#xs는x값의 위치 조정. 안해주면 바랑 x위치가 어긋남.
xs = [i + 0.1 for i, _ in enumerate(movies)]

# plot bars with left x-coordinates [xs], heights [num_oscars]
plt.bar(xs, num_oscars, color = 'g')
plt.ylabel("# of Academy Awards")
plt.title("My Favorite Movies")

# label x-axis with movie names at bar centers
#위에서 수정한 각 xs값들에 대입할 이름들
plt.xticks([i + 0.1 for i, _ in enumerate(movies)], test)

plt.show()
