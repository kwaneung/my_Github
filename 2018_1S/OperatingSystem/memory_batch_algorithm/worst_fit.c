#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include<time.h>

#define NUMOFPROC 20 //프로세스의 갯수
#define SIZEOFMEM 400 //메모리 크기

struct proc
{
	int size;	//프로세스 크기
	bool load;	//프로세스 적재 여부
	int locate; //프로세스 적재 위치
};

struct avalablemem	//가용 메모리의 크기와 위치
{
	int size;
	int location;
};

int memory[SIZEOFMEM] = { 0 };
struct proc p[NUMOFPROC]; //프로세스 생성

void proc();
void ranload();
void worstfit();

int main()
{

	proc(); //생성된 프로세스들의 메모리크기를 정해주고 적재확인 플래스 false로 초기화

	ranload(); //생성된 프로세스중 절반을 메모리상의 임의의 공간에 할당
	worstfit();


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
		if (p[i].load == true)					//p[i]가 적재 체크된 프로세스라면
		{
		b:
			x = rand() % (SIZEOFMEM);		//0부터 399중 한개로 메모리가 적재될 번지수를 정함

			for (j = 0; j < p[i].size; j++)		//memory[x]부터 memory[x+p[i].size]까지가 모두 0일 경우 x번지에 할당
			{
				if (memory[x + j] == 1)			//이미 할당되어있는 메모리가 있을때
				{
					goto b;
				}
				if (j == p[i].size - 1)			//해당 메모리주소(x)부터 해당 프로세스p[i]크기만큼의 주소가 비어있다면
				{
					p[i].locate = x;
					for (k = x; k < x + p[i].size; k++)//메모리의 해당 주소부터 프로세스의 크기만큼 메모리공간 1로 토글
						memory[k] = 1;
				}
			}
		}
	}

	for (i = 0; i < NUMOFPROC; i++)
		if (p[i].locate != 0)
		{
			printf("임의로 할당된 ");
			printf("프로세스는 %d번 입니다.\n", i + 1);
		}

	printf("\n물리 메모리\n");
	for (i = 0; i < SIZEOFMEM; i++)
		printf("%d", memory[i]);
	printf("\n\n");



}

void worstfit()
{
	int z;
	int i, j, k;
	int m;
	int x = 0; //메모리의 현재 위치를 나타냄
	int t = 0;	//가용메모리의 시작주소를 나타냄
	int y;
	int tmp_size;
	int tmp_locate;
	struct avalablemem mem[NUMOFPROC];

	for (i = 0; i < NUMOFPROC; i++)		//가용메모리 구조체 변수 초기화
	{
		mem[i].size = 0;
		mem[i].location = 0;
	}

	for (i = 0; i < NUMOFPROC; i++)
	{
		tmp_size = 0;
		tmp_locate = 0;
		y = 0;

		for (j = 0; j < NUMOFPROC; j++)//이전 프로세스의 가용메모리 정보를 초기화
		{
			mem[j].size = 0;
			mem[j].location = 0;
		}
		
		if (p[i].load != true)	//i번 프로세스가 적재되어 있지 않을 경우 메모리 스캔 시작
		{
			printf("할당되지 않은 %d번 프로세스의 메모리 크기 : %d\n", i + 1, p[i].size);

			for (m = 0; m < SIZEOFMEM; m++)
			{

				for (j = 0; j < p[i].size; j++)		//memory[x]부터 memory[x+p[i].size]까지가 모두 0일 경우 x번지에 할당
				{
					if ((m + j) == SIZEOFMEM - 1)
					{
						m = SIZEOFMEM - 1;
						break;
					}

					if (memory[m + j] == 1)			//이미 할당되어있는 메모리가 있을때
					{
						m += j;
						break;
					}

					if (j == p[i].size - 1)			//해당 메모리주소(x)부터 해당 프로세스p[i]크기만큼의 주소가 비어있다면 메모리 전체의 빈공간 모두 확인할때 까지 가장 최소의 크기를 찾는다.
					{
						t = m;
						mem[y].location = m;	//빈공간의 메모리의 위치
						while (memory[t] == 0)	//메모리의 빈공간의 길이
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
					printf("%d번째 가용메모리의 위치 : %d\n", k + 1, mem[k].location);
					printf("%d번째 가용메모리의 크기 : %d\n\n", k + 1, mem[k].size);

					if (mem[k].size > tmp_size) //k번쨰 가용메모리가 tmp보다 큰 경우
					{
						tmp_size = mem[k].size;
						tmp_locate = mem[k].location;
					}

				}
			}

			
			if (y > 0)//가용메모리가 존재할 경우 적재한다
			{
				printf("%d번 프로세스의 worstfit 주소는 %d이고 크기는 %d 이다.\n\n", i + 1, tmp_locate, tmp_size);

				p[i].locate = tmp_size;

				//이곳에서 p[i]를 worstfit에 맞는 메모리의 빈공간에 적재한다
				//이곳 구현한다.

				for (j = 0; j < p[i].size; j++)
				{
					memory[tmp_locate + j] = 1;
				}

				p[i].load = true;

				printf("%d번 프로세스의 worstfit 주소는 %d이고 크기는 %d만큼 저장이 완료되었습니다.(적재 완료 여부 : %d)\n\n", i + 1, p[i].locate, p[i].size, p[i].load);
			}
			else //메모리 부족 할 경우
			{
				printf("%d번 프로세스의 worstfit 주소는 %d이고 크기는 %d만큼 저장이 메모리 부족으로 실패되었습니다.(적재 완료 여부 : %d)\n\n", i + 1, p[i].locate, p[i].size, p[i].load);
			}

			printf("\n물리 메모리\n");
			for (z = 0; z < SIZEOFMEM; z++)
				printf("%d", memory[z]);
			printf("\n\n");
		}
	}
}