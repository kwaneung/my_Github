#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include<time.h>

#define NUMOFPROC 20 //���μ����� ����
#define SIZEOFMEM 400 //�޸� ũ��

struct proc
{
	int size;	//���μ��� ũ��
	bool load;	//���μ��� ���� ����
	int locate; //���μ��� ���� ��ġ
};

struct avalablemem	//���� �޸��� ũ��� ��ġ
{
	int size;
	int location;
};

int memory[SIZEOFMEM] = { 0 };
struct proc p[NUMOFPROC]; //���μ��� ����

void proc();
void ranload();
void worstfit();

int main()
{

	proc(); //������ ���μ������� �޸�ũ�⸦ �����ְ� ����Ȯ�� �÷��� false�� �ʱ�ȭ

	ranload(); //������ ���μ����� ������ �޸𸮻��� ������ ������ �Ҵ�
	worstfit();


}

void proc()
{
	int i;
	int percent;
	int t;

	for (i = 0; i < NUMOFPROC; i++) //�� ���μ������� �޸� ũ�� ����
	{
		percent = rand() % 100 + 1;
		t = rand() % 2;
		if (percent >= 30)//70�ۼ�Ʈ Ȯ���� �޸��� ũ�Ⱑ 20 +-3 ũ��� ����
		{
			if (t == 0)
				p[i].size = 20 + (rand() % 4);
			else
				p[i].size = 20 - (rand() % 4);
		}
		else if (percent < 30 && percent >= 10)//20�ۼ�Ʈ Ȯ���� ũ�Ⱑ 20 +- 5 ũ��� ����
		{
			if (t == 0)
				p[i].size = 20 + (rand() % 6);
			else
				p[i].size = 20 - (rand() % 6);
		}
		else//10�ۼ�Ʈ Ȯ���� ũ�Ⱑ 20 +- 10 ũ��� ����
		{
			if (t == 0)
				p[i].size = 20 + (rand() % 11);
			else
				p[i].size = 20 - (rand() % 11);
		}
	}



}

void ranload()//������ ���μ����� ������ �޸𸮻��� ������ ������ �Ҵ�
{
	int x;
	int i, j, k;

	for (i = 0; i < NUMOFPROC / 2; i++)//������ ���μ����� ���� ���� i=0���� i<10���� 0,1,2,3,4,5,6,7,8,9 �� 10�� ����
	{
	a:
		x = rand() % NUMOFPROC; // x�� 0���� 19������ ���� �Ѱ����� ��. �װ��� ���õ� ���μ����� ����.
		if (p[x].load == false)
		{
			p[x].load = true;
		}
		else
			goto a;
	}

	for (i = 0; i < NUMOFPROC; i++)				//ù��° ���μ������� ������ �Ҵ�� ���μ����� �ش�Ǵ� �޸𸮸� ������ �Ҵ�
	{
		if (p[i].load == true)					//p[i]�� ���� üũ�� ���μ������
		{
		b:
			x = rand() % (SIZEOFMEM);		//0���� 399�� �Ѱ��� �޸𸮰� ����� �������� ����

			for (j = 0; j < p[i].size; j++)		//memory[x]���� memory[x+p[i].size]������ ��� 0�� ��� x������ �Ҵ�
			{
				if (memory[x + j] == 1)			//�̹� �Ҵ�Ǿ��ִ� �޸𸮰� ������
				{
					goto b;
				}
				if (j == p[i].size - 1)			//�ش� �޸��ּ�(x)���� �ش� ���μ���p[i]ũ�⸸ŭ�� �ּҰ� ����ִٸ�
				{
					p[i].locate = x;
					for (k = x; k < x + p[i].size; k++)//�޸��� �ش� �ּҺ��� ���μ����� ũ�⸸ŭ �޸𸮰��� 1�� ���
						memory[k] = 1;
				}
			}
		}
	}

	for (i = 0; i < NUMOFPROC; i++)
		if (p[i].locate != 0)
		{
			printf("���Ƿ� �Ҵ�� ");
			printf("���μ����� %d�� �Դϴ�.\n", i + 1);
		}

	printf("\n���� �޸�\n");
	for (i = 0; i < SIZEOFMEM; i++)
		printf("%d", memory[i]);
	printf("\n\n");



}

void worstfit()
{
	int z;
	int i, j, k;
	int m;
	int x = 0; //�޸��� ���� ��ġ�� ��Ÿ��
	int t = 0;	//����޸��� �����ּҸ� ��Ÿ��
	int y;
	int tmp_size;
	int tmp_locate;
	struct avalablemem mem[NUMOFPROC];

	for (i = 0; i < NUMOFPROC; i++)		//����޸� ����ü ���� �ʱ�ȭ
	{
		mem[i].size = 0;
		mem[i].location = 0;
	}

	for (i = 0; i < NUMOFPROC; i++)
	{
		tmp_size = 0;
		tmp_locate = 0;
		y = 0;

		for (j = 0; j < NUMOFPROC; j++)//���� ���μ����� ����޸� ������ �ʱ�ȭ
		{
			mem[j].size = 0;
			mem[j].location = 0;
		}
		
		if (p[i].load != true)	//i�� ���μ����� ����Ǿ� ���� ���� ��� �޸� ��ĵ ����
		{
			printf("�Ҵ���� ���� %d�� ���μ����� �޸� ũ�� : %d\n", i + 1, p[i].size);

			for (m = 0; m < SIZEOFMEM; m++)
			{

				for (j = 0; j < p[i].size; j++)		//memory[x]���� memory[x+p[i].size]������ ��� 0�� ��� x������ �Ҵ�
				{
					if ((m + j) == SIZEOFMEM - 1)
					{
						m = SIZEOFMEM - 1;
						break;
					}

					if (memory[m + j] == 1)			//�̹� �Ҵ�Ǿ��ִ� �޸𸮰� ������
					{
						m += j;
						break;
					}

					if (j == p[i].size - 1)			//�ش� �޸��ּ�(x)���� �ش� ���μ���p[i]ũ�⸸ŭ�� �ּҰ� ����ִٸ� �޸� ��ü�� ����� ��� Ȯ���Ҷ� ���� ���� �ּ��� ũ�⸦ ã�´�.
					{
						t = m;
						mem[y].location = m;	//������� �޸��� ��ġ
						while (memory[t] == 0)	//�޸��� ������� ����
						{
							mem[y].size++;
							t++;
						}
						m += mem[y].size;
						m--;
						y++;

					}
				}
			}

			for (k = 0; k < NUMOFPROC; k++)
			{
				if (mem[k].size != 0)
				{
					printf("%d��° ����޸��� ��ġ : %d\n", k + 1, mem[k].location);
					printf("%d��° ����޸��� ũ�� : %d\n\n", k + 1, mem[k].size);

					if (mem[k].size > tmp_size) //k���� ����޸𸮰� tmp���� ū ���
					{
						tmp_size = mem[k].size;
						tmp_locate = mem[k].location;
					}

				}
			}

			
			if (y > 0)//����޸𸮰� ������ ��� �����Ѵ�
			{
				printf("%d�� ���μ����� worstfit �ּҴ� %d�̰� ũ��� %d �̴�.\n\n", i + 1, tmp_locate, tmp_size);

				p[i].locate = tmp_size;

				//�̰����� p[i]�� worstfit�� �´� �޸��� ������� �����Ѵ�
				//�̰� �����Ѵ�.

				for (j = 0; j < p[i].size; j++)
				{
					memory[tmp_locate + j] = 1;
				}

				p[i].load = true;

				printf("%d�� ���μ����� worstfit �ּҴ� %d�̰� ũ��� %d��ŭ ������ �Ϸ�Ǿ����ϴ�.(���� �Ϸ� ���� : %d)\n\n", i + 1, p[i].locate, p[i].size, p[i].load);
			}
			else //�޸� ���� �� ���
			{
				printf("%d�� ���μ����� worstfit �ּҴ� %d�̰� ũ��� %d��ŭ ������ �޸� �������� ���еǾ����ϴ�.(���� �Ϸ� ���� : %d)\n\n", i + 1, p[i].locate, p[i].size, p[i].load);
			}

			printf("\n���� �޸�\n");
			for (z = 0; z < SIZEOFMEM; z++)
				printf("%d", memory[z]);
			printf("\n\n");
		}
	}
}