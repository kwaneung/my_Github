#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include<time.h>

#define NUMOFPROC 20 //���μ����� ����

struct proc
{
	int size;	//���μ��� ũ��
	bool load;	//���μ��� ���� ����
	int locate; //���μ��� ���� ��ġ
};

int memory[NUMOFPROC * 20] = { 0 };
struct proc p[NUMOFPROC]; //���μ��� ����

void proc();
void ranload();

int main()
{

	proc(); //������ ���μ������� �޸�ũ�⸦ �����ְ� ����Ȯ�� �÷��� false�� �ʱ�ȭ

	ranload(); //������ ���μ����� ������ �޸𸮻��� ������ ������ �Ҵ�
	
	
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

	for (i = 0; i < NUMOFPROC; i++)//�� ���μ����� ����Ȯ�� �÷��� false�� �ʱ�ȭ
	{
		p[i].load = false;
		p[i].locate = 0;
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
		if (p[i].load == true)					//p[i]�� ����üũ �Ǿ��ִٸ�.
		{
			b:
			x = rand() % (NUMOFPROC * 20);		//0���� 399�� �Ѱ��� �޸𸮰� ����� �������� ����

			for (j = 0; j < p[i].size; j++)		//memory[x]���� memory[x+p[i].size]������ ��� 0�� ��� x������ �Ҵ�
			{
				if (memory[x + j] == 1)			//�̹� �Ҵ�Ǿ��ִ� �޸𸮰� ������
				{
					goto b;
				}
				if (j == p[i].size - 1)			//�ش� �޸��ּ�(x)���� �ش� ���μ���p[i]ũ�⸸ŭ�� �ּҰ� ����ִٸ�
				{
					p[i].locate = x;
					for (k = x; k < x + p[i].size; k++)
						memory[k] = 1;
				}
			}
		}
	}
}