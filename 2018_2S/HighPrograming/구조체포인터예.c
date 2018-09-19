#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct student_t {
	int id;
	char name[32];
	char hobby[128];
}student;
student *get_data();
void display_data(student *st);

int main()
{
	display_data(get_data());

	return 0;
}

student *get_data()
{
	student * st = NULL;
	st = malloc(sizeof(student) * 3);

	st[0].id = 1;
	strcpy_s(st[0].name,sizeof(st[0].name), "�պ���");
	strcpy_s(st[0].hobby, sizeof(st[0].hobby), "�˴���");

	st[1].id = 2;
	strcpy_s(st[1].name, sizeof(st[1].name), "�����");
	strcpy_s(st[1].hobby, sizeof(st[0].hobby), "����");

	st[2].id = 3;
	strcpy_s(st[2].name, sizeof(st[2].name), "���̼�");
	strcpy_s(st[2].hobby, sizeof(st[0].hobby), "����");

	return st;

}

void display_data(student *st)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		printf("%d��° �л��� ����(ID, name, hobby) : %d, %s, %s\n", i + 1, st[i].id, st[i].name, st[i].hobby);
	}
}

