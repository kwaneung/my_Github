from pandas import DataFrame, Series
import seaborn as sns
# 1. 다음 명령으로 타이타닉호 승객 데이터를 데이터프레임으로 읽어온다. 이 명령을 실행하려면 seaborn 패키지가 설치되어 있어야 한다.
# import seaborn as sns
#
# titanic = sns.load_dataset("titanic") # returns DataFrame

titanic = sns.load_dataset("titanic")
print(titanic)

# 2. 타이타닉호 승객들을 다음 각각의 기준으로 값을 구하라.
# o 기준: 성별(sex) 인원수, 나이별(age) 인원수, 선실별(class) 인원수, 사망/생존(alive) 인원수
# print('성별 인원수'); print(titanic['sex'].value_counts())
# print('나이별 인원수'); print(titanic['age'].value_counts())
# print('선실별 인원수'); print(titanic['class'].value_counts())
# print('사망/생존 인원수'); print(titanic['alive'].value_counts())


# 3. 타이타닉 데이터를 이용하여 다음과 같은 DataFrame을 만들라.
# - columns : age, embark_town
# - rows : sex, class
# 성별, class로 정렬하라.
t2 = titanic[['sex','age','embark_town', 'class']].set_index(['sex','class'])
t3 = t2.sort_index()
print(t3)


