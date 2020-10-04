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
//���ϵ������������õ���������������Լ�������������Ŀ���
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
	int j = start;//j������pst->sizeҲ����˵ j��λ��Ҳ���ǲ���ڵ����ʼλ��
	int i = (j - 1) / 2;//i������j�ĸ��ڵ�
	while (j > 0)//��ʼ���ϵ�����ֱ��jû�и��ڵ�
	{
		if (base[j] < base[i])
		{
			Swap(&(base[i]), &(base[j]));
			j = i;//j׷��i��λ����Ϊ��ʼλ�ã���j��i���ڵ��λ����Ϊ��ʼ����λ�ã�һ��һ����ӡ���ϵ���
			i = (j - 1) / 2;//���¶�λ���ڵ��λ��
		}
		else
			break;//�������Ҫ������ֱ�ӽ�������ʼ��һ�ֵĲ������
	}
}

void MinHeapInsert(heap*php, HeapData x)
{
	assert(php != NULL);
	if (php->size < php->capacity)
	{
		php->base[php->size] = x;
		AdjustUp(php->base, php->size);
		//����ΪС�ѽṹ���������ϵ���
		php->size++;//��ʼ��һ�ֵĲ������
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
	return HeapTop_val;//���ش�ӡ��Сֵ
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
	//������С��,�������µ����ķ�����ʼ���ϵ���
	int curpos = n / 2 - 1;//�ҵ����һ����֧�ڵ�
	while (curpos>0)
	{
		AdjustDown(pst->base, 0, n);
		curpos--;
	}
	//����
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
