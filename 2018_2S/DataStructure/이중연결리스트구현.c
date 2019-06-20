#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

typedef struct address_t								//��� ���߿��Ḯ��Ʈ ����ü
{
   char name[64];
   char street[64];
   char city[64];
   char province[16];
   char zip[16];
   struct address_t *prev;
   struct address_t *next;
}person;

void dlist_insert(person *pre_node, person *p);			//������ �Լ�
void dlist_display(person *i);							//��� ��ü��ȸ �Լ�
person *dllsorted_insort(person *, person *);			//���Ļ��� �Լ�
void dlist_delete(person *i, person *removed);			//������ �Լ�
void init(person *phead);								//�ʱ�ȭ

void main()
{
	person *p = (person *)malloc(sizeof(person));
	person *head_node = p;

	init(p);

	while(1)
	{
		printf("�̸��� �Է��� �ּ���(���� : Q!) : ");
		p = (person *)malloc(sizeof(person));
		fscanf_s(stdin, "%s", p->name, sizeof(p->name));
		if (strcmp(p->name, "q!") == 0 || strcmp(p->name, "Q!") == 0)
		{
			fprintf(stdout, "\n�Է� ����\n");
			break;
		}
		dllsorted_insort(head_node, p);
	}
	dlist_display(head_node);
}

void init(person *phead)
{
	phead->prev = phead;
	phead->next = phead;
}

void dlist_insert(person *pre_node, person *p)
{
	p->prev = pre_node;
	p->next = pre_node->next;
	pre_node->next->prev = p;
	pre_node->next = p;
}

void dlist_display(person *phead)
{
	fprintf_s(stdout, "\n��� ��ȸ\n\n");
	person *p = phead->next;

	while (p != phead)
	{
		printf("| %s |\n", p->name);
		p = p->next;
	}
	fprintf_s(stdout, "\n��ȸ �Ϸ�\n");
}

person *dllsorted_insort(person *head, person *p)
{
	person *node = head->next;

	while(node != head)
	{
		if (strcmp(node->name, p->name) >= 0)
		{
			dlist_insert(node->prev, p);
			return 0;
		}
		node = node->next;
	}
	dlist_insert(node->prev, p);

	return p;
}

void dlist_delete(person *phead_node, person *removed)
{
	if (removed == phead_node) return;
	removed->prev->next = removed->next;
	removed->next->prev = removed->prev;
	free(removed);
}