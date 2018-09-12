#include <stdio.h>

typedef struct stu_tag {
	int id;
	char name[32];
	int kor, prog;
}student;

typedef struct dept_tag {
	student *freshmen;
	int nfreshmen;
	student *sophomore;
	int nsophomore;
	student *junior;
	int njunior;
	student *senior;
	int nsenior;
}dept;

dept *get_data();
void display_data(dept*);


int main()
{

	dept *department = NULL;

	department = get_data();
	printf("\n\n");
	display_data(department);
	printf("\n\n");
}

dept *get_data()
{
	dept *dp = NULL;

	dp = malloc(sizeof(dept));

	printf("input number of freshmen : ");
	scanf("%d", &dp->nfreshmen);
	printf("input number of sophomore : ");
	scanf("%d", &dp->nsophomore);
	printf("input number of junior : ");
	scanf("%d", &dp->njunior);
	printf("input number of senior : ");
	scanf("%d", &dp->nsenior);

	dp->freshmen = malloc(sizeof(student) * dp->nfreshmen);
	dp->sophomore = malloc(sizeof(student) * dp->nsophomore);
	dp->junior = malloc(sizeof(student) * dp->njunior);
	dp->senior = malloc(sizeof(student) * dp->nsenior);

	printf("---------freshmen---------\n");
	for (int i = 0; i < dp->nfreshmen; i++)
	{
		char *name;
		name = malloc(30);
		printf("input %dst student id : ", i + 1);
		scanf("%d", &dp->freshmen[i].id);
		printf("input %dst student name : ", i + 1);
		scanf("%s", name);
		strcpy(dp->freshmen[i].name, name);
		free(name);
	}
	printf("---------sophomore---------\n");
	for (int i = 0; i < dp->nsophomore; i++)
	{
		char *name;
		name = malloc(30);
		printf("input %dst student id : ", i + 1);
		scanf("%d", &dp->sophomore[i].id);
		printf("input %dst student name : ", i + 1);
		scanf("%s", name);
		strcpy(dp->sophomore[i].name, name);
		free(name);
	}
	printf("---------senior----------\n");
	for (int i = 0; i < dp->nsenior; i++)
	{
		char *name;
		name = malloc(30);
		printf("input %dst student id : ", i + 1);
		scanf("%d", &dp->senior[i].id);
		printf("input %dst student name : ", i + 1);
		scanf("%s", name);
		strcpy(dp->senior[i].name, name);
		free(name);
	}
	printf("---------junior---------\n");
	for (int i = 0; i < dp->njunior; i++)
	{
		char *name;
		name = malloc(30);
		printf("input %dst student id : ", i + 1);
		scanf("%d", &dp->junior[i].id);
		printf("input %dst student name : ", i + 1);
		scanf("%s", name);
		strcpy(dp->junior[i].name, name);
		free(name);
	}

	return dp;
}

void display_data(dept* a)
{
	printf("---------freshmen---------\n");
	for (int i = 0; i < a->nfreshmen; i++)
	{
		printf("%d st freshmen id, name : %d, %s\n", i + 1, a->freshmen[i].id, a->freshmen[i].name);
	}
	printf("\n");

	printf("---------sophomore---------\n");
	for (int i = 0; i < a->nsophomore; i++)
	{
		printf("%d st sophomore id, name : %d, %s\n", i + 1, a->sophomore[i].id, a->sophomore[i].name);
	}
	printf("\n");

	printf("---------senior---------\n");
	for (int i = 0; i < a->nsenior; i++)
	{
		printf("%d st senior id, name : %d, %s\n", i + 1, a->senior[i].id, a->senior[i].name);
	}
	printf("\n");

	printf("---------junior---------\n");
	for (int i = 0; i < a->njunior; i++)
	{
		printf("%d st junior id, name : %d, %s\n", i + 1, a->junior[i].id, a->junior[i].name);
	}
}
