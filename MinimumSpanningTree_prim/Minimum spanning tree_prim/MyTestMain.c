#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */

typedef struct
{
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;


void MiniSpanTree_Prim(MGraph* G)
{
	int min, i, j, k;
	int adjvex[10];
	int lowcost[10];
	lowcost[0] = 0;
	adjvex[0] = 0;
	for (i = 1; i < G->numVertexes; i++)
	{
		lowcost[i] = G->arc[0][i];
		adjvex[i] = 0;
	}
	for (i = 1; i < G->numVertexes; i++)
	{
		min = INFINITY;
		j = 1; k = 0;
		while (j < G->numVertexes)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
			j++;
		}
		printf("%d,%d)\n", adjvex[k], k);
		lowcost[k] = 0;
		for (int j = 1; j < G->numVertexes; j++)
		{
			if (G->arc[k][j] != 0 && G->arc[k][j] < lowcost[j])
			{
				lowcost[j] = G->arc[k][j];
				adjvex[j] = k;
			}
		}
	}

}
