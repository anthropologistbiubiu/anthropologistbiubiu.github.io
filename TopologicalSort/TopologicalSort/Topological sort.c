#include "stdio.h"    
#include "stdlib.h"   


#define MAXEDGE 20
#define MAXVEX 14
#define INFINITY 65535

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */

/* 邻接矩阵结构 */
typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

/* 邻接表结构****************** */
typedef struct EdgeNode /* 边表结点  */
{
	int adjvex;    /* 邻接点域，存储该顶点对应的下标 */
	int weight;		/* 用于存储权值，对于非网图可以不需要 */
	struct EdgeNode *next; /* 链域，指向下一个邻接点 */
}EdgeNode;

typedef struct VertexNode /* 顶点表结点 */
{
	int in;	/* 顶点入度 */
	int data; /* 顶点域，存储顶点信息 */
	EdgeNode *firstedge;/* 边表头指针 */
}VertexNode, AdjList[10];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges; /* 图中当前顶点数和边数 */
}graphAdjList, *GraphAdjList;
/* **************************** */


void CreateMGraph(MGraph *G)/* 构建图 */
{
	int i, j;

	/* printf("请输入边数和顶点数:"); */
	G->numEdges = 9;
	G->numVertexes = 9;

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		G->vexs[i] = i;
	}

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = 0;
		}
	}


	G->arc[0][1] = 1;
	G->arc[0][2] = 1;
	G->arc[1][2] = 1;
	G->arc[1][3] = 1;
	G->arc[1][4] = 1;

	G->arc[2][4] = 1;
	G->arc[2][5] = 1;
	G->arc[3][4] = 1;
	G->arc[3][6] = 1;
	G->arc[4][5] = 1;

	G->arc[4][6] = 1;
	G->arc[4][7] = 1;
	G->arc[5][7] = 1;
	G->arc[6][7] = 1;
	G->arc[6][8] = 1;

	G->arc[7][8] = 1;
	

}

/* 利用邻接矩阵构建邻接表 */
void CreateALGraph(MGraph G, GraphAdjList *GL)
{
	int i, j;
	EdgeNode *e;

	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));

	(*GL)->numVertexes = G.numVertexes;
	(*GL)->numEdges = G.numEdges;
	for (i = 0; i <G.numVertexes; i++) /* 读入顶点信息，建立顶点表 */
	{
		(*GL)->adjList[i].in = 0;
		(*GL)->adjList[i].data = G.vexs[i];
		(*GL)->adjList[i].firstedge = NULL; 	/* 将边表置为空表 */
	}

	for (i = 0; i<G.numVertexes; i++) /* 建立边表 */
	{
		for (j = 0; j<G.numVertexes; j++)
		{
			if (G.arc[i][j]==1 )
			{
				e = (EdgeNode*)malloc(sizeof(EdgeNode));
				e->adjvex = j;					/* 邻接序号为j  */
				e->next = (*GL)->adjList[i].firstedge;	/* 将当前顶点上的指向的结点指针赋值给e */
				(*GL)->adjList[i].firstedge = e;		/* 将当前顶点的指针指向e  */
				(*GL)->adjList[j].in++;   

			}
		}
	}

}


/* 拓扑排序，若GL无回路，则输出拓扑排序序列并返回1，若有回路返回0。 */
Status TopologicalSort(GraphAdjList GL)
{
	EdgeNode *e;
	int i, k, gettop;
	int top = 0;  /* 用于栈指针下标  */
	int *stack;	/* 建栈将入度为0的顶点入栈  */
	stack = (int *)malloc(GL->numVertexes * sizeof(int));

	for (i = 0; i < GL->numVertexes; i++)
	{
		if (0 == GL->adjList[i].in) /* 将入度为0的顶点入栈 */
			stack[++top] = i;
	}
	while (top != 0)
	{
		gettop = stack[top--];
		printf("%d -> ", GL->adjList[gettop].data);
		for (e = GL->adjList[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			if (!(--GL->adjList[k].in))  /* 将i号顶点的邻接点的入度减1，如果减1后为0，则入栈 */
				stack[++top] = k;
		}
	}
	printf("\n");
}


int main(void)
{
	MGraph G;
	GraphAdjList GL;
	int result;
	CreateMGraph(&G);
	CreateALGraph(G, &GL);
	system("pause");
}