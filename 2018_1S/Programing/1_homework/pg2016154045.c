#include <stdio.h>
int notscore(int); // 점수의 범위가 0~100이면1, 아니면0반환

int main()
{
	int number[30] = { 0 };		//학번
	int score[3][30] = { 0 };	//3 횟수의 학생 점수
	int sum[3] = { 0 };			//각 횟수별 학생들의 점수 총합
	int totals[30] = { 0 };		//각 학생의 총점
	double avgs[30] = { 0.0 };	//각 학생의 평균
	char grades[30];			//각 학생의 학점
	int maxs[3] = { 0 };			//횟수별 최고점
	int mins[3] = { 10000, 10000, 10000 };//횟수별 최저점
	int max = 0, min = 10000;	//총점중 최고 최저
	int stds = 30;
	int i, j;

	printf("학생수를 입력하시오(최대 30명):");
	scanf("%d", &stds);
	if (stds > 39 || stds < 1)
	{
		printf("학생수 오류!!\n");
		printf("아무 숫자나 누르시오!!:");
		scanf("%d", &i);
		return 0;
	}
	for (i = 0; i < stds; i++)
	{
		printf("%d 번째 학생 학번 입력:", i + 1);
		scanf("%d", &number[i]);

		printf("%d 번째 학생 1 횟수 성적 입력: ", i + 1);
		scanf("%d", &score[0][i]);
		if (notscore(score[0][i]))
		{
			printf("점수 오류!!\n");
			printf("아무 숫자나 누르시오!!");
			scanf("%d", &i);
			return 0;
		}

		printf("%d 번째 학생 2 횟수 성적 입력: ", i + 2);
		scanf("%d", &score[1][i]);
		if (notscore(score[1][i]))
		{
			printf("점수 오류!!\n");
			printf("아무 숫자나 누르시오!!");
			scanf("%d", &i);
			return 0;
		}

		printf("%d 번째 학생 3 횟수 성적 입력: ", i + 3);
		scanf("%d", &score[2][i]);
		if (notscore(score[2][i]))
		{
			printf("점수 오류!!\n");
			printf("아무 숫자나 누르시오!!");
			scanf("%d", &i);
			return 0;
		}

		totals[i] = score[0][i] + score[1][i] + score[2][i];	//총점 계산
		avgs[i] = totals[i] / 3.0;								//평균 계산

		if (avgs[i] > 85.0)										//학점 계산
			grades[i] = 'A';
		else if (avgs[i] > 60.0)
			grades[i] = 'B';
		else if (avgs[i] > 40.0)
			grades[i] = 'C';
		else if (avgs[i] > 20.0)
			grades[i] = 'D';
		else
			grades[i] = 'F';

	}
	printf("====================================================\n");
	printf("      학번  수시1  수시2  수시3  총점  평균  학점\n");
	printf("====================================================\n");

	for (i = 0; i < stds; i++)
	{
		printf("%10d %6d %6d %6d %5d %5.1lf %5c\n", number[i], score[0][i], score[1][i], score[2][i], totals[i], avgs[i], grades[i]);
	}
	printf("====================================================\n");

	for (i = 0; i < 3; i++)
		for (j = 0; j < stds; j++)
			sum[i] += score[i][j]; //i는 수시123각 횟수, j는 0은1번1은2번학생을 의미 sum[0]은 수시1 학생들 총합 , sum[1]은 수시2 학생들 총합, sum[3]은 수시3 학생들 총합

	printf("평균: %11.1lf %6.1lf %6.1lf \n", (double)sum[0] / stds, (double)sum[1] / stds, (double)sum[2] / stds);


	//최고점 구해보자 max[0]은 수시1 최고점 2는 수시2최고점 3은 수시3최고점
	for (i = 0; i < 3; i++) //수시123
	{
		for (j = 0; j < stds; j++)//학생수
		{
			if (score[i][j] >= max)
			{
				max = score[i][j];
				maxs[i] = max;
			}
			if (score[i][j] <= min)
			{
				min = score[i][j];
				mins[i] = min;
			}
		}
		max = 0, min = 10000;
	}


	printf("최고: %11d %6d %6d\n", maxs[0], maxs[1], maxs[2]);
	printf("최저: %11d %6d %6d\n", mins[0], mins[1], mins[2]);

	printf("아무 숫자나 누르시오!!");
	scanf("%d", &i);
	return 0;
}

int notscore(int score) //0~100사이의 점수가 아니면 1을 반환, 점수가 맞으면 0을 반환
{
	if (score < 0 || score>100)
		return 1;
	else
		return 0;
}