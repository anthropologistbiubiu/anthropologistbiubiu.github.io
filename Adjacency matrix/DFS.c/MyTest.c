#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define VertexType char
#define EdgeType  int 

typedef struct MGraph
{
	VertexType vexs[5];
	EdgeType arcs[5][5];
	int numVertexs, numEdeges;
}MGraph;


void CreatMGraph(MGraph*G)
{
	G->numVertexs = 5;

	/*读入顶点信息创建顶点表*/
	G->vexs[0] = 'w';
	G->vexs[1] = 'a';
	G->vexs[2] = 't';
	G->vexs[3] = 'j';
	G->vexs[4] = 's';
	/*建立边边*/
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			G->arcs[i][j] = 0;
		}
	}

	G->arcs[0][1] = 1;
	G->arcs[0][2] = 1;
	G->arcs[0][3] = 1;
	G->arcs[0][4] = 1;
}
int Visted[5] = { 0 };
void My_DFS(MGraph*G, int i)
{
	Visted[i] = 1;
	printf("%c->", G->vexs[i]);
	for (int j = 0; j < G->numVertexs; j++)
	{
		if (G->arcs[i][j] == 1 && !Visted[j])
			My_DFS(G, j);
	}
}
void DFSVISIT(MGraph*G)
{
	for (int i = 0; i < G->numVertexs; i++)
	{
		if (!Visted[i])
			My_DFS(G, i);
	}
}
typedef struct SeqQueue
{
	int* base;
	int capacity;
	int front;
	int rear;
}SeqQueue;
void SeqQueueInit(SeqQueue*psq)
{
	assert(psq != NULL);
	psq->base = (SeqQueue*)malloc(sizeof(SeqQueue)*10);
	assert(psq->base != NULL);
	psq->capacity = 10;
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
void SeqQueueEnque(SeqQueue*psq, int x)
{
	assert(psq != NULL);
	if (SeqQueueIsFull(psq))
	{
		return;
	}
	psq->base[psq->rear] = x;
	psq->rear++;
}
void SeqQueueDeque(SeqQueue*psq,int* i)
{
	assert(psq != NULL);
	if (SeqQueueIsEmpty(psq))
	{
		return;
	}
	*i = psq->base[psq->front];
	psq->front++;
}
void My_BFS(MGraph*G)
{
	SeqQueue bt;
	SeqQueueInit(&bt);
	for (int i = 0; i < G->numVertexs; i++)
	{
		if (!Visted[i])
		{
			Visted[i] = 1;
			printf("%c->", G->vexs[i]);
			SeqQueueEnque(&bt, i);
			while (!SeqQueueIsEmpty(&bt))
			{
				SeqQueueDeque(&bt, &i);
				for (int j = 0; j < G->numVertexs; j++)
				{
					if (G->arcs[i][j] == 1 && !Visted[j])
					{
						Visted[j] = 1;
						printf("%c->", G->vexs[j]);
						SeqQueueEnque(&bt, j);
					}
				}
			}
			
		}
	}
}

void main()
{
	MGraph G;
	CreatMGraph(&G);
	//DFSVISIT(&G);
	My_BFS(&G);
	system("pause");
}
