#include <stdio.h>
int notscore(int); // ������ ������ 0~100�̸�1, �ƴϸ�0��ȯ

int main()
{
	int number[30] = { 0 };		//�й�
	int score[3][30] = { 0 };	//3 Ƚ���� �л� ����
	int sum[3] = { 0 };			//�� Ƚ���� �л����� ���� ����
	int totals[30] = { 0 };		//�� �л��� ����
	double avgs[30] = { 0.0 };	//�� �л��� ���
	char grades[30];			//�� �л��� ����
	int maxs[3] = { 0 };			//Ƚ���� �ְ���
	int mins[3] = { 10000, 10000, 10000 };//Ƚ���� ������
	int max = 0, min = 10000;	//������ �ְ� ����
	int stds = 30;
	int i, j;

	printf("�л����� �Է��Ͻÿ�(�ִ� 30��):");
	scanf("%d", &stds);
	if (stds > 39 || stds < 1)
	{
		printf("�л��� ����!!\n");
		printf("�ƹ� ���ڳ� �����ÿ�!!:");
		scanf("%d", &i);
		return 0;
	}
	for (i = 0; i < stds; i++)
	{
		printf("%d ��° �л� �й� �Է�:", i + 1);
		scanf("%d", &number[i]);

		printf("%d ��° �л� 1 Ƚ�� ���� �Է�: ", i + 1);
		scanf("%d", &score[0][i]);
		if (notscore(score[0][i]))
		{
			printf("���� ����!!\n");
			printf("�ƹ� ���ڳ� �����ÿ�!!");
			scanf("%d", &i);
			return 0;
		}

		printf("%d ��° �л� 2 Ƚ�� ���� �Է�: ", i + 2);
		scanf("%d", &score[1][i]);
		if (notscore(score[1][i]))
		{
			printf("���� ����!!\n");
			printf("�ƹ� ���ڳ� �����ÿ�!!");
			scanf("%d", &i);
			return 0;
		}

		printf("%d ��° �л� 3 Ƚ�� ���� �Է�: ", i + 3);
		scanf("%d", &score[2][i]);
		if (notscore(score[2][i]))
		{
			printf("���� ����!!\n");
			printf("�ƹ� ���ڳ� �����ÿ�!!");
			scanf("%d", &i);
			return 0;
		}

		totals[i] = score[0][i] + score[1][i] + score[2][i];	//���� ���
		avgs[i] = totals[i] / 3.0;								//��� ���

		if (avgs[i] > 85.0)										//���� ���
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
	printf("      �й�  ����1  ����2  ����3  ����  ���  ����\n");
	printf("====================================================\n");

	for (i = 0; i < stds; i++)
	{
		printf("%10d %6d %6d %6d %5d %5.1lf %5c\n", number[i], score[0][i], score[1][i], score[2][i], totals[i], avgs[i], grades[i]);
	}
	printf("====================================================\n");

	for (i = 0; i < 3; i++)
		for (j = 0; j < stds; j++)
			sum[i] += score[i][j]; //i�� ����123�� Ƚ��, j�� 0��1��1��2���л��� �ǹ� sum[0]�� ����1 �л��� ���� , sum[1]�� ����2 �л��� ����, sum[3]�� ����3 �л��� ����

	printf("���: %11.1lf %6.1lf %6.1lf \n", (double)sum[0] / stds, (double)sum[1] / stds, (double)sum[2] / stds);


	//�ְ��� ���غ��� max[0]�� ����1 �ְ��� 2�� ����2�ְ��� 3�� ����3�ְ���
	for (i = 0; i < 3; i++) //����123
	{
		for (j = 0; j < stds; j++)//�л���
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


	printf("�ְ�: %11d %6d %6d\n", maxs[0], maxs[1], maxs[2]);
	printf("����: %11d %6d %6d\n", mins[0], mins[1], mins[2]);

	printf("�ƹ� ���ڳ� �����ÿ�!!");
	scanf("%d", &i);
	return 0;
}

int notscore(int score) //0~100������ ������ �ƴϸ� 1�� ��ȯ, ������ ������ 0�� ��ȯ
{
	if (score < 0 || score>100)
		return 1;
	else
		return 0;
}