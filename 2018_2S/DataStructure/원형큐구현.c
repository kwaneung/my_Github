#include <stdio.h>
#define MAX_QUEUE_SIZE 32

typedef int element;

typedef struct {
	element  queue[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

void error(char *message);
void init(QueueType *q);
int is_empty(QueueType *q);
int is_full(QueueType *q);
void enqueue(QueueType *q, element item);
element dequeue(QueueType *q);
element peek(QueueType *q);

int count = 0;

void main()
{
	QueueType q;
	int n = 0;
	init(&q);
	printf("front = %d rear = %d\n", q.front, q.rear);


	while (n < 1000)
	{
		for (int j = 0; j < 16; j++)
		{
			n++;
			if (n > 1000)
			{
				printf("n���� 1000�� �Ѿ���ϴ�.\n");
				exit(1);
			}
			enqueue(&q, n);
		}
		
		for (int j = 0; j < 10; j++)
		{
			printf("dequeue() = %d\n", dequeue(&q));
		}
	}

	printf("front = %d rear = %d\n", q.front, q.rear);
}

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType *q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}

int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, element item)
{
	if (count == MAX_QUEUE_SIZE)
		printf("ť�� ��ȭ�����Դϴ�\n");
	else
	{
		count++;
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->queue[q->rear] = item;
	}
}

element dequeue(QueueType *q)
{
	if (count == 0)
		error("ť�� ��������Դϴ�");
	else
	{
		count--;
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->queue[q->front];
	}
}

element peek(QueueType *q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}