#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

typedef struct address_t								//사람 이중연결리스트 구조체
{
   char name[64];
   char street[64];
   char city[64];
   char province[16];
   char zip[16];
   struct address_t *prev;
   struct address_t *next;
}person;

void dlist_insert(person *pre_node, person *p);			//노드삽입 함수
void dlist_display(person *i);							//노드 전체조회 함수
person *dllsorted_insort(person *, person *);			//정렬삽입 함수
void dlist_delete(person *i, person *removed);			//노드삭제 함수
void init(person *phead);								//초기화

void main()
{
	person *p = (person *)malloc(sizeof(person));
	person *head_node = p;

	init(p);

	while(1)
	{
		printf("이름을 입력해 주세요(종료 : Q!) : ");
		p = (person *)malloc(sizeof(person));
		fscanf_s(stdin, "%s", p->name, sizeof(p->name));
		if (strcmp(p->name, "q!") == 0 || strcmp(p->name, "Q!") == 0)
		{
			fprintf(stdout, "\n입력 종료\n");
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
	fprintf_s(stdout, "\n결과 조회\n\n");
	person *p = phead->next;

	while (p != phead)
	{
		printf("| %s |\n", p->name);
		p = p->next;
	}
	fprintf_s(stdout, "\n조회 완료\n");
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