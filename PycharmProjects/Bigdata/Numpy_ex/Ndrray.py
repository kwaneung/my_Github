import numpy as np

#4.1 Ndarray 다차원 배열 객체
# data = [[0.956,-0.24, 2],[0.2232, 1.232, 4],[1, 2, 3], [10, 11, 12]]
# data = np.array(data)
# print(data)
# print(data.dtype, data.ndim, data.shape)

#4.1.1 ndarray 생성
# print(np.zeros(10))
# print(np.zeros((3, 6)))
# print(np.empty((3, 2, 5))) # (차원의 수, 2차원배열의 행, 2차원배열의 열)
# print(np.arange(15))

# print(np.ones((3,4)))
# print(np.eye(5, 5))

#4.1.2 자료형
# arr = np.array([1, 2, 3, 4, 5])
# print(arr.dtype)
# print(arr.astype(np.float64))

#4.1.3 배열과 스칼라 간의 연산
#making array
# arr = np.array([np.arange(1, 5), np.arange(6, 10)])
# print(arr)

#Vector processing
# arr2 = arr + arr #배열의 각 자리끼리 연산
# print(arr2)
# print(arr*arr2)

#Broadcasting
# print(arr*3)

#list
# l1 = [0, 1, 2, 3, 4]
# l2 = l1[0:3]
# print(l2)
#
# l2[0] = 122
# print(l1, l2)

#np.array
# arr = np.array(np.arange(10))
# print(arr)
# arr2 = arr[0:4]
# arr2[0]= 123
# print(arr2)

arr2d = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
# print(arr2d[2])
# print(arr2d[0][2])
# arr3d = np.array([[[1, 2, 3], [4, 5, 6]], [[7, 8, 9], [10, 11, 12]]])
# print(arr3d)
# print(arr3d[0])

# old_values = arr3d[0].copy()
# arr3d[0] = 42
# print(arr3d)
# arr3d[0] = old_values
# print(arr3d)

#4.1.4 색인과 슬라이싱 기초
# print(arr2d)
# print(arr2d[:2])
# print(arr2d[:2, 1:])
# print(arr2d[1, :2])
# print(arr2d[2, :1])
# print(arr2d[:, :1])
# arr2d[:2, 1:] = 0
# print(arr2d)

#4.1.5 불리언 색인
# names  = np.array(['관응', '명수', '지섭', '병국', '관응', '지섭', '지섭'])
# print(names)
# data = np.random.randn(7, 4)
# print(data)

# print(names == '관응')
# print(data[names == '관응'])
#
# print(data[names == '관응', 2:])
# print(data[names != '명수'])
#
# data[names == '관응'] = 100
# print(data)

#4.1.6 팬시 색인
# arr = np.empty((8, 4))
# for i in range(8):
#     arr[i] = i

#print(arr[[-3, -5, -7]])

# arr = np.arange(32).reshape((8, 4))
# print(arr)
# print(arr[[1, 5, 7, 2], [0, 3, 1, 2]])
# print(arr[np.ix_([1, 5, 7, 2], [0, 3, 1, 2])])

#4.1.7 배열 전치와 축 바꾸기
# arr = np.arange(15).reshape((3, 5))
#arr = np.random.randn(6, 3)
# print(arr)
#
# print(arr.T)
# print(np.dot(arr, arr.T))

# arr = np.arange(16).reshape((2, 2, 4))
# print(arr)
# print("-------------------")
#
# print(arr.transpose((1, 0, 2)))

#4.2 유니버설 함수.
arr = np.arange(10)
# print(np.sqrt(arr))
# print(np.exp(arr))

# x = np.random.randn(8)
# y = np.random.randn(8)
# print(x)
# print(y)
# print(np.maximum(x, y))
# arr = np.random.randn(7) * 5
# print(arr)
# print("-----------")
# arr1, arr2 = np.modf(arr)
# print(arr1)
# print(arr2)

#4.3 배열을 사용한 데이터 처리
# points = np.arange(-5, 5, 0.01)
# xs, ys = np.meshgrid(points, points)
# import matplotlib.pyplot as plt
# z = np.sqrt(xs ** 2 + ys ** 2)
# plt.imshow(z, cmap=plt.cm.gray)
# plt.colorbar()
# plt.title("adfasdf")

#4.3.1 배열연산으로 조건절 표현하기
# xarr = np.array([1.1, 1.2, 1.3, 1.4, 1.5])
# yarr = np.array([2.1, 2.2, 2.3, 2.4, 2.5])
# cond = np.array([True, False, True, True, False])
# result = [(x if c else y)
#           for x, y, c in zip(xarr, yarr, cond)]
#
#
# arr = np.random.randn(4, 4)
# print(arr)
# print(np.where(arr>0, 2, -2))

#4.3.2 수학, 통계 메소드
# arr = np.random.randn(5, 4)
# print(arr)
# print(arr.sum(axis=1))
# arr = np.array([[0, 1, 2], [3, 4, 5], [6, 7, 8]])
# print(arr.cumsum(0))

# 4.3.3 불리언 배열을 위한 메소드
# arr = np.random.randn(100)
# print((arr>0).sum())
# bools = np.array([False, False, True, False])
# print(bools.any())
# print(bools.all())
# arr = np.random.randn(8)
# print(arr)
# arr.sort()
# print(arr)

#4.3.4 정렬
arr = np.random.randn(5, 3)
# print(arr)
# arr.sort(0)
# print(arr)
# large_arr = np.random.randn(1000)
# large_arr.sort()
# print(large_arr[int(0.05 * len(large_arr))])
#
# names = np.array(['관응', '병국', '현호', '관응', '현영', '강강'])
# print(np.unique(names))
# ints = np.array([3, 3, 3, 2, 2, 1, 1, 4, 4])
# print(np.unique(ints))
# print(sorted(set(names)))
# values = np.array([1, 2, 3, 4, 5, 6, 7])
# print(np.in1d(values, [1, 3, 5]))

#4.4.1 배열을 바이너리 형식으로 디스크에 저장하기
arr = np.arange(10)
# arr2 = np.arange(20)
# np.save('어레이저장', arr)
# print(np.load('어레이저장.npy'))
# np.savez('아카이브', a=arr, b=arr2)
# arch = np.load('아카이브.npz')
# print(arch['b'])

#4.4.2 텍스트 파일 불러오기 저장하기
# np.savetxt('텍스트.txt', arr)
# arr = np.loadtxt('텍스트.txt', delimiter=', ')
# print(arr)

#4.5 선형대수
# x = np.array([[1., 2., 3.], [4., 5., 6]])
# y = np.array([[6., 23.], [-1, 7], [8, 9]])
# print(x)
# print(y)
# print('------------')
# print(x.dot(y))
# print(np.dot(x, np.ones(3)))

from numpy.linalg import inv, qr
x = np.random.randn(5, 5)
mat = x.T.dot(x)
inv(mat)
print(mat.dot(inv(mat)))
q, r = qr(mat)
print(r)