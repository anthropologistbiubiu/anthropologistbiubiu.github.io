#ifndef _QUEUE_H_
#define _QUEUE_H_
#include"common.h"
#define SEQ_QUEUE_DEFAULT_SIZE 8
typedef struct SeqQueue
{
	ElemType*base;
	int capacity;
	int front;
	int rear;
}SeqQueue;
void SeqQueueInit(SeqQueue*psq)
{
	assert(psq != NULL);
	psq->base = (SeqQueue*)malloc(sizeof(SeqQueue)*SEQ_QUEUE_DEFAULT_SIZE);
	assert(psq->base != NULL);
	psq->capacity = SEQ_QUEUE_DEFAULT_SIZE;
	psq->front = psq->rear = 0;
}
bool SeqQueueIsFull(SeqQueue*psq)
{
	assert(psq != NULL);
	return psq->rear >= psq->capacity;
}
bool SeqQueueIsEmpty(SeqQueue*psq)
{
	assert(psq != NULL);
	return psq->front == psq->rear;
}
void SeqQueueEnque(SeqQueue*psq, ElemType x)
{
	assert(psq != NULL);
	if (SeqQueueIsFull(psq))
	{
		printf("�ɻ��������ѹ����������\n");
		return;
	}
	psq->base[psq->rear] = x;
	psq->rear++;
}
void SeqQueueDeque(SeqQueue*psq)
{
	assert(psq != NULL);
	if (SeqQueueIsEmpty(psq))
	{
		printf("�ɻ����ѿգ����ܳ���\n");
		return;
	}
	psq->front++;
}
ElemType SeqQueueFront(SeqQueue*psq)
{
	assert(psq != NULL);
	if (SeqQueueIsEmpty(psq))
	{
		printf("�ɻ����ѿգ����ܳ���\n");
		return;
	}
	return psq->base[psq->front];
}
void SeqQueuePrint(SeqQueue*psq)
{
	assert(psq != NULL);
	if (SeqQueueIsEmpty(psq))
	{
		printf("�ɻ����ѿգ����ܴ�ӡ\n");
		return;
	}
	for (int i = psq->front; i < psq->rear; ++i)
	{
		printf("%d ", psq->base[i]);
	}
	printf("\n");
}


////////////////////////////////////////////////////////
/////ѭ������
#define CIRCLE_SEQ_QUEUE_DEFAULT_SIZE 8
typedef struct CircleQueue
{
	ElemType*base;
	int capacity;
	int front;
	int rear;
}CircleQueue;

void CircleQueueInit(CircleQueue*psq)
{
	assert(psq != NULL);
	psq->base = (CircleQueue*)malloc(sizeof(CircleQueue)*CIRCLE_SEQ_QUEUE_DEFAULT_SIZE + 1);
	assert(psq->base != NULL);
	psq->capacity = CIRCLE_SEQ_QUEUE_DEFAULT_SIZE + 1;
	psq->front = psq->rear = 0;
}
bool CircleQueueIsFull(SeqQueue*psq)
{
	assert(psq != NULL);
	return(psq->rear + 1) % psq->capacity == psq->front;
}
bool CircleQueueIsEmpty(SeqQueue*psq)
{
	assert(psq != NULL);
	return psq->front == psq->rear;
}
void CircleQueueEnque(CircleQueue*psq, ElemType x)
{
	assert(psq != NULL);
	if (CircleQueueIsFull(psq))
	{
		printf("�ɻ��������ѹ����������\n");
		return;
	}
	psq->base[psq->rear] = x;
	psq->rear = (psq->rear + 1) % psq->capacity;
}
void CircleQueueDeque(CircleQueue*psq)
{
	assert(psq != NULL);
	if (CircleQueueIsEmpty(psq))
	{
		printf("ѭ���ɻ����ѿգ����ܳ���\n");
		return;
	}
	psq->front = (psq->front + 1) % psq->capacity;
}
ElemType CircleQueueFront(CircleQueue*psq)
{
	assert(psq != NULL);
	if (CircleQueueIsEmpty(psq))
	{
		printf("ѭ���ɻ����ѿգ�����ȡ��ͷԪ��\n");
		return;
	}
	return psq->base[psq->front];
}
void CircleQueuePrint(CircleQueue*psq)
{
	assert(psq != NULL);
	if (CircleQueueIsEmpty(psq))
	{
		printf("�ɻ����ѿգ����ܴ�ӡ\n");
		return;
	}
	for (int i = psq->front; i != psq->rear;)
	{
		printf("%d ", psq->base[i]);
		i = (i + 1) % psq->capacity;
	}
	printf("\n");
}

///////////////////////////////////////////////////////
//��ʽ����
typedef struct LinkQueueNode
{
	ElemType data;
	struct LinkQueueNode*Link;
}LinkQueueNode;
typedef struct LinkQueue
{
	LinkQueueNode*front;
	LinkQueueNode*rear;
}LinkQueue;


void LinkQueueInit(LinkQueue*pq)
{
	pq->front = pq->rear = NULL;
}
void LinkQueueEnque(LinkQueue*pq, ElemType x)
{
	assert(pq != NULL);
	LinkQueueNode*node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if (pq->front == NULL)
	{
		node->data = x;
		node->Link = NULL;
		pq->front = pq->rear = node;
	}
	else
	{
		assert(node != NULL);
		node->data = x;
		node->Link = NULL;
		pq->rear->Link = node;
		pq->rear = node;
	}

}
void LinkQueueDeque(LinkQueue*pq)
{
	assert(pq != NULL);
	if (pq->front != NULL);
	{
		LinkQueueNode*p = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
		p = pq->front;
		pq->front = p->Link;
		free(p);
	}
}
void LinkQueuePrint(LinkQueue*pq)
{
	assert(pq != NULL);
	LinkQueueNode*p = pq->front;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->Link;
	}
	printf("\n");
}
bool LinkQueueEmpty(LinkQueue*pq)
{
	assert(pq != NULL);
	return pq->front = NULL;
}
ElemType LinkQueueFront(LinkQueue*pq)
{
	if (pq->front != NULL)
		return pq->front->data;
}
#endif 