#include <stdio.h>
#include <stdlib.h>
#define SIZE_OF_BLOCK 3 //��� ������ ����
int main()
{
	int idx = 0;
	int hit = 0;	//���� Ƚ�� ���� ����
	int k = 0;	//data�迭�� �ε���
	int data[30];	//�ֱ����ġ �迭
	int count = 0;	//ĳ�� ��ġ�� ����Ű�� ������
	int cache[SIZE_OF_BLOCK];	//ĳ�ú���� �迭
	FILE *fp = NULL;
	fopen_s(&fp, "input.txt", "r");

	if (fp == NULL)
	{
		printf("���� ���� ����\n");
		exit(1);
	}
	else
		printf("���� ���� ����\n");

	while (fscanf_s(fp, "%d ", &data[k]) != EOF)//������ ���� Ȯ�εɶ����� ���� �о�� �ֱ����ġ �迭�� ���Ͽ��� �о�°��� data �迭�� ����
		k++;

	for (int j = 0; j < SIZE_OF_BLOCK; j++)//�ʱ� �� �����ŭ ����
	{
		if (data[j] == 99)//99�� �Է��� �ƴ� ������ �ǹ�

		{
			printf("99�� �ԷµǾ����Ƿ� �����մϴ�.");
			idx = 1;
		}
		if (idx == 0)
		{
			printf("%d�� ĳ�ú��� ����\n", data[j]);
			cache[j] = data[j];//ĳ�ú�� �迭�� �ֱ����ġ �迭�� �� �о� ����
		}
	}

	if (idx == 0)
	{
		for (int j = SIZE_OF_BLOCK; j < k; j++)//�ʱ� �������ĺ��� ��ϻ����ŭ �ݺ�
		{
			if (data[j] == 99)//99�� �Է��� �ƴ� ������ �ǹ�
				break;

			printf("%d�� ĳ�ú��� ����\n", data[j]);

			//hit ���� �˻�.
			for (int k = 0; k < SIZE_OF_BLOCK; k++)//ĳ�þȿ� �������� �����ϸ� hit�� ������Ų��.
			{
				if (cache[k] == data[j])
				{
					hit++;
					count--;
					break;
				}
			}
			cache[count%SIZE_OF_BLOCK] = data[j];//ĳ�ÿ� ������ ����
			count++;
		}
	}

	printf("\nĳ�ú� ��� ���\n");
	for (int j = 0; j < SIZE_OF_BLOCK; j++)
		printf("%d ", cache[j]);
	printf("hit : %d/%d", hit, k);
	printf("�ƹ�Ű�� �Է��Ͻÿ�");
	scanf_s("%d", &hit);
	fclose(fp);

}