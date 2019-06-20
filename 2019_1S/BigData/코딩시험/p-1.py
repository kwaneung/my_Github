import sys
cnt = 0
print('the biggest prime number up to 10 : ')
for i in range(int(sys.argv[1]), 2, -1):
    chk = True
    for j in range(2, i):
        if i % j == 0:
            chk = False
            break
    if chk:
        print(i, end=" ")
        cnt += 1
        if cnt == 3:
            break
