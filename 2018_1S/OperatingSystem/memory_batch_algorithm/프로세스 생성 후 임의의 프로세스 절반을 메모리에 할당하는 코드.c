#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include<time.h>

#define NUMOFPROC 20 //프로세스의 갯수

struct proc
{
	int size;	//프로세스 크기
	bool load;	//프로세스 적재 여부
	int locate; //프로세스 적재 위치
};

int memory[NUMOFPROC * 20] = { 0 };
struct proc p[NUMOFPROC]; //프로세스 생성

void proc();
void ranload();

int main()
{

	proc(); //생성된 프로세스들의 메모리크기를 정해주고 적재확인 플래스 false로 초기화

	ranload(); //생성된 프로세스중 절반을 메모리상의 임의의 공간에 할당
	
	
}
void proc()
{
	int i;
	int percent;
	int t;

	for (i = 0; i < NUMOFPROC; i++) //각 프로세스들의 메모리 크기 생성
	{
		percent = rand() % 100 + 1;
		t = rand() % 2;
		if (percent >= 30)//70퍼센트 확률로 메모리의 크기가 20 +-3 크기로 생성
		{
			if (t == 0)
				p[i].size = 20 + (rand() % 4);
			else
				p[i].size = 20 - (rand() % 4);
		}
		else if (percent < 30 && percent >= 10)//20퍼센트 확률로 크기가 20 +- 5 크기로 생성
		{
			if (t == 0)
				p[i].size = 20 + (rand() % 6);
			else
				p[i].size = 20 - (rand() % 6);
		}
		else//10퍼센트 확률로 크기가 20 +- 10 크기로 생성
		{
			if (t == 0)
				p[i].size = 20 + (rand() % 11);
			else
				p[i].size = 20 - (rand() % 11);
		}
	}

	for (i = 0; i < NUMOFPROC; i++)//각 프로세스의 적재확인 플래그 false로 초기화
	{
		p[i].load = false;
		p[i].locate = 0;
	}

}

void ranload()//생성된 프로세스중 절반을 메모리상의 임의의 공간에 할당
{
	int x;
	int i, j, k;
	
	for (i = 0; i < NUMOFPROC / 2; i++)//생성된 프로세스중 절반 선택 i=0부터 i<10까지 0,1,2,3,4,5,6,7,8,9 총 10번 실행
	{
		a:
		x = rand() % NUMOFPROC; // x는 0부터 19사이의 수중 한가지만 들어감. 그값은 선택된 프로세서의 순서.
		if (p[x].load == false)
		{
			p[x].load = true;
		}
		else
			goto a;
	}
	
	for (i = 0; i < NUMOFPROC; i++)				//첫번째 프로세스부터 끝까지 할당된 프로세스에 해당되는 메모리를 실제로 할당
	{
		if (p[i].load == true)					//p[i]가 적재체크 되어있다면.
		{
			b:
			x = rand() % (NUMOFPROC * 20);		//0부터 399중 한개로 메모리가 적재될 번지수를 정함

			for (j = 0; j < p[i].size; j++)		//memory[x]부터 memory[x+p[i].size]까지가 모두 0일 경우 x번지에 할당
			{
				if (memory[x + j] == 1)			//이미 할당되어있는 메모리가 있을때
				{
					goto b;
				}
				if (j == p[i].size - 1)			//해당 메모리주소(x)부터 해당 프로세스p[i]크기만큼의 주소가 비어있다면
				{
					p[i].locate = x;
					for (k = x; k < x + p[i].size; k++)
						memory[k] = 1;
				}
			}
		}
	}
}