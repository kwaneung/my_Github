#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	char *name;
	double grade;
};
typedef struct student Student;

void swap(Student *, Student *);

int main()
{
	Student *std[10] = { 0 };
	FILE *fp;
	char buffer[80];
	double grade;
	int i, j, count = 0;

	fp = fopen("Sorted.txt", "w+" );


	for (i = 0; i < 10; i++)
	{
		printf("%dnd student \n", i + 1);
		printf("input name: ");
		gets(buffer);
		if (strcmp(buffer, "") == 0) break;
		

		std[i] = (Student*)malloc(sizeof(Student));
		std[i]->name = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
		strcpy(std[i]->name, buffer);
		
		printf("input grade: ");
		scanf_s("%lf", &grade);
		std[i]->grade = grade;
		while (getchar() != '\n');
		count++;
	}
	

	//이름순 정렬
 	for (i = 0; i < count - 1; i++)
	{
		if (strcmp(std[i + 1]->name, std[i]->name) == -1)
		{
			swap(std[i], std[i + 1]);
			i = -1;
		}
	}
	
	fprintf(fp, "--이름의 올림차순으로 정렬된 학생--\n");
	puts("이름의 올림차순으로 정렬된 학생");
	for (i = 0; i < count; i++)
	{
		printf("%17s %12.1lf\n", std[i]->name, std[i]->grade);
		fprintf(fp, "%17s %12.1lf\n", std[i]->name, std[i]->grade);
	}

	//평점 순 정렬
	for (i = 0; i < count - 1; i++)
	{
		if (std[i + 1]->grade > std[i]->grade)
		{
			swap(std[i], std[i + 1]);
			i = -1;
		}
	}

	fprintf(fp, "--평점의 올림차순으로 정렬된 학생--\n");
	puts("평점의 올림차순으로 정렬된 학생");
	for (i = 0; i < count; i++)
	{
		printf("%17s %12.1lf\n", std[i]->name, std[i]->grade);
		fprintf(fp, "%17s %12.1lf\n", std[i]->name, std[i]->grade);
	}

	fclose(fp);



	for (i = 0; i < count; i++)
		free(std[i]->name);
}

void swap(Student *S1, Student *S2)
{
	Student *tmp = { 0 };
	tmp = (Student*)malloc(sizeof(Student));

	tmp->name = S1->name;
	S1->name = S2->name;
	S2->name = tmp->name;

	tmp->grade = S1->grade;
	S1->grade = S2->grade;
	S2->grade = tmp->grade;
}