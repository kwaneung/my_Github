import numpy as np

summ = 0
mstk = []
stk = input('보유 주식 파일을 입력하시오: ')
mystock = np.genfromtxt(stk, dtype=None, encoding='ascii')
stock = np.genfromtxt('stock.txt', dtype=None, encoding='ascii')

for i in range(len(mystock)):
    for j in range(len(stock)):
        if(mystock[i][0] == stock[j][0]):
            summ += mystock[i][1]*stock[j][1]
            mstk.append((mystock[i][1]*stock[j][1], mystock[i][0]))


print('총 보유금액 : %d'%summ)
print('보유금액순 종목명 ')
mstk.sort()
mstk.reverse()
for i in range(len(mstk)):
    print(mstk[i][1])
