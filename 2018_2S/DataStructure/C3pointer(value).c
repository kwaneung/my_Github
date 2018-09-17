#include <stdio.h>

 

char *function1();

char *function2();

char *function3();

 

int main()

{

	char *school = NULL;

	char *dept = NULL;

	char *name = NULL;

 

	school = function1();

	dept = function2();

	name = function3();

 

	printf("%s \n%s \n%s \n", school, dept, name);

 

	return 0;

}

 

char *function1()

{

	char *school = NULL;

	school = malloc(sizeof(char)*20);

	strcpy(school, "한국산업기술대학교");

 

	return school;

}

char *function2()

{

	char *dept = NULL;

	dept = malloc(sizeof(char) * 20);

	strcpy(dept, "컴퓨터공학부");

	

	return dept;

}

char *function3()

{

	char *name;

	name = malloc(sizeof(char) * 10);

	strcpy(name, "김관응");

 

	return name;

}