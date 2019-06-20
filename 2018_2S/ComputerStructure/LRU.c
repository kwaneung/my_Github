#include <stdio.h>
#include <stdlib.h>
#define SIZE_OF_BLOCK 4 //블록 사이즈 정의
int main()
{
	int idx = 0;
	int hit = 0;	//적중 횟수 산정 변수
	int k = 0;	//data배열의 인덱스
	int data[30];	//주기억장치 배열
	int count = 0;	//캐시 위치를 가리키는 포인터
	int cache[SIZE_OF_BLOCK];	//캐시블록 배열
	int LRU[SIZE_OF_BLOCK] = { 0 };	//캐시블록과 같은 인덱스를 사용하며 참조될때마다 값을 증가시키고 카운트가 가리킬때마다 감소시킴
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
		for (int j = SIZE_OF_BLOCK - 1; j < k; j++)//초기 삽입이후부터 블록사이즈만큼 반복
		{
			if (data[j] == 99)//99는 입력이 아닌 종료의 의미로 사용
				break;//반복문 빠져 나옴
			printf("%d를 캐시블럭에 삽입\n", data[j]);

			//hit여부 검사.
			for (int k = 0; k < SIZE_OF_BLOCK; k++)//캐시안에 같은값이 존재하면 같은 인덱스의 LRU값과 hit를 증가시킨다.
				if (cache[k] == data[j])
				{
					LRU[k]++;
					hit++;
					goto end;
				}

			while (LRU[count % SIZE_OF_BLOCK] != 0)//LRU안의값이 0이될때까지 감소시키며 다음을 확인한다
			{
				LRU[count % SIZE_OF_BLOCK]--;
				count++;
			}
			cache[count % SIZE_OF_BLOCK] = data[j];//LRU값이 0인경우 cache에 삽입한다.

			count++;
		end:;
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