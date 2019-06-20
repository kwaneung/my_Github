#include <stdio.h>
#include <stdlib.h>
#define SIZE_OF_BLOCK 3 //블록 사이즈 정의
int main()
{
	int idx = 0;
	int hit = 0;	//적중 횟수 산정 변수
	int k = 0;	//data배열의 인덱스
	int data[30];	//주기억장치 배열
	int count = 0;	//캐시 위치를 가리키는 포인터
	int cache[SIZE_OF_BLOCK];	//캐시블록의 배열
	FILE *fp = NULL;
	fopen_s(&fp, "input.txt", "r");

	if (fp == NULL)
	{
		printf("파일 열기 실패\n");
		exit(1);
	}
	else
		printf("파일 열기 성공\n");

	while (fscanf_s(fp, "%d ", &data[k]) != EOF)//파일의 끝이 확인될때까지 값을 읽어와 주기억장치 배열에 파일에서 읽어온값을 data 배열에 적재
		k++;

	for (int j = 0; j < SIZE_OF_BLOCK; j++)//초기 블럭 사이즈만큼 삽입
	{
		if (data[j] == 99)//99는 입력이 아닌 종료의 의미

		{
			printf("99가 입력되었으므로 종료합니다.");
			idx = 1;
		}
		if (idx == 0)
		{
			printf("%d를 캐시블럭에 삽입\n", data[j]);
			cache[j] = data[j];//캐시블록 배열에 주기억장치 배열의 값 읽어 저장
		}
	}

	if (idx == 0)
	{
		for (int j = SIZE_OF_BLOCK; j < k; j++)//초기 삽입이후부터 블록사이즈만큼 반복
		{
			if (data[j] == 99)//99는 입력이 아닌 종료의 의미
				break;

			printf("%d를 캐시블럭에 삽입\n", data[j]);

			//hit 여부 검사.
			for (int k = 0; k < SIZE_OF_BLOCK; k++)//캐시안에 같은값이 존재하면 hit를 증가시킨다.
			{
				if (cache[k] == data[j])
				{
					hit++;
					count--;
					break;
				}
			}
			cache[count%SIZE_OF_BLOCK] = data[j];//캐시에 데이터 적재
			count++;
		}
	}

	printf("\n캐시블럭 출력 결과\n");
	for (int j = 0; j < SIZE_OF_BLOCK; j++)
		printf("%d ", cache[j]);
	printf("hit : %d/%d", hit, k);
	printf("아무키나 입력하시오");
	scanf_s("%d", &hit);
	fclose(fp);

}