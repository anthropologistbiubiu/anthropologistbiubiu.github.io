#ifndef _HEAP_H_
#define _HEAP_H_
#include"common.h"
#include"heap.h"
#define HeapData int
typedef struct heap
{
	HeapData *base;
	int capacity;
	int size;
}heap;
void HeapInit(heap*pst, int n)
{
	assert(pst != NULL);
	pst->base = (HeapData*)malloc(sizeof(HeapData)*n);
	assert(pst->base != NULL);
	pst->capacity = n;
	pst->size = 0;
}
//向上调整函数，不用调动交换函数，节约调动交换函数的开销
/*
void AdjustUp(HeapData*base, int start)
{
int j = start;
int i = (j - 1) / 2;
HeapData temp = base[j];
temp = base[i];
while (j > 0)
{
if (temp < base[i])
{
base[j] = base[i];
j = i;
i = (j - 1) / 2;
}
else
break;
}
base[j]=temp;
}
*/
void AdjustUp(HeapData*base, int start)
{
	int j = start;//j来接受pst->size也就是说 j的位置也就是插入节点的起始位置
	int i = (j - 1) / 2;//i来当做j的父节点
	while (j > 0)//开始向上调整，直到j没有父节点
	{
		if (base[j] < base[i])
		{
			Swap(&(base[i]), &(base[j]));
			j = i;//j追到i的位置作为起始位置，即j以i父节点的位置作为起始调整位置，一步一个脚印向上调整
			i = (j - 1) / 2;//重新定位父节点的位置
		}
		else
			break;//如果不需要调整，直接结束，开始下一轮的插入调整
	}
}

void MinHeapInsert(heap*php, HeapData x)
{
	assert(php != NULL);
	if (php->size < php->capacity)
	{
		php->base[php->size] = x;
		AdjustUp(php->base, php->size);
		//调整为小堆结构，从下往上调整
		php->size++;//开始下一轮的插入调整
	}
}
void AdjustDown(HeapData*base, int start, int n)
{
	int i = start;
	int j = 2 * i + 1;
	while (j<n)
	{
		if (j + 1 < n && base[j] > base[j + 1])
			j++;
		if (base[i]>base[j])
		{
			Swap(&(base[i]), &(base[j]));
			i = j;
			j = 2 * j + 1;
		}
		else
			break;
	}
}
bool HeapEmpty(heap*pst)
{
	return pst->size == 0;
}
HeapData MinHeapRemove(heap*pst)
{
	assert(pst != NULL);
	assert(pst->size >0);
	int HeapTop_val = pst->base[0];
	pst->size--;
	pst->base[0] = pst->base[pst->size];
	AdjustDown(pst->base, 0, pst->size);
	return HeapTop_val;//返回打印最小值
}
void HeapPrintf(heap*pst)
{
	for (int i = 0; i < pst->size; i++)
		printf("%d ", pst->base[i]);
	printf("\n");
}
void HeapSort(heap*pst, int ar[], int n)
{
	assert(pst != NULL);
	for (int i = 0; i < n; i++)
	{
		pst->base[i] = ar[i];
	}
	pst->size = n;
	//调整成小堆,利用向下调整的方法开始向上调整
	int curpos = n / 2 - 1;//找到最后一个分支节点
	while (curpos>0)
	{
		AdjustDown(pst->base, 0, n);
		curpos--;
	}
	//排序
	int end = n - 1;
	while (end > 0)
	{
		Swap(&pst->base[0], &pst->base[end]);
		AdjustDown(pst->base, 0, end);
		end--;
	}
	int k = pst->size - 1;
	for (int j = 0; j < pst->size; j++)
	{
		ar[j] = pst->base[k--];
	}
}
void HeapPrint(heap*pst)
{
	assert(pst != NULL);
	for (int i = 0; i < pst->size; i++)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}
#endif
