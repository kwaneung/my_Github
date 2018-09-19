#include<stdio.h>
#include<stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	int *list;
	int length;
}ArrayListType;

void error(char *message)
{

}

void init(ArrayListType*L)
{
	L->length = 0;
}

int is_empty(ArrayListType*L)
{
	return L->length == 0;
}

int is_full(ArrayListType *L)
{
	return L->length == MAX_LIST_SIZE;
}

void display(ArrayListType *L)
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%d -> %d\n", i + 1, L->list[i]);
	}
}
void add(ArrayListType *L, int position, element item)
{
	if (!is_full(L))
	{
		L->length++;

		for (int i = L->length; i > position; i--)
		{
			L->list[i] = L->list[i - 1];
		}

		L->list[position] = item;
	}
}

element delete(ArrayListType*L, int position)
{

}

main()
{
	ArrayListType list1;
	ArrayListType *plist = NULL;

	list1.list = (int*)malloc(MAX_LIST_SIZE);
	

	init(&list1);
	add(&list1, 0, 10);
	add(&list1, 0, 20);
	add(&list1, 0, 30);
	display(&list1);
	
	printf("\n");
	plist = (ArrayListType*)malloc(sizeof(ArrayListType));
	plist->list = (int*)malloc(MAX_LIST_SIZE);
	init(plist);
	add(plist, 0, 10);
	add(plist, 0, 20);
	add(plist, 0, 30);
	display(plist);
	free(plist);
}