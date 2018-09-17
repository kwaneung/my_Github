#include <stdio.h>

#include <memory.h>

 

void *function1(char **);

void *function2(char **);

void *function3(char **);

 

int main()

{

	char *school = NULL;

	char *dept = NULL;

	char *name = NULL;

 

	school = function1(&school);

	dept = function2(&dept);

	name = function3(&name);

 

	printf("%s \n%s \n%s \n", school, dept, name);

 

	return 0;

}

 

void *function1(char **school)

{

	*school = malloc(sizeof(char) * 20);

	strcpy(*school, "한국산업기술대학교");

}

void *function2(char **dept)

{

	*dept = malloc(sizeof(char) * 20);

	strcpy(*dept, "컴퓨터공학부");

}

void *function3(char **name)

{

	*name = malloc(sizeof(char) * 20);

	strcpy(*name, "김관응");

}