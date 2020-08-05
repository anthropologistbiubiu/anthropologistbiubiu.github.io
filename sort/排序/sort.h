#ifndef _SORT_H_ 
#define _SORT_H_
#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
#include<memory.h>
#include"list.h"
void Swap(int* a, int*b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void PrintElement(int*elem,int first,int end)
{
	for (int i = first; i<end; i++)
	{
		printf("%d ", elem[i]);
	}
	printf("\n");
}
//��������֮������,�����ȶ�����
void InertSort(int*elem, int first, int last)
{
	int end = first + 1;
	for (int i=end; i<last; i++)
	{
		end = i;
		while (end > first&&elem[end] < elem[end - 1])
		{
			Swap(&elem[end], &elem[end - 1]);
			end--;
		}
	}
}
//1.Ԫ�ؼ����½ӽ�����ֱ�Ӳ���������㷨Ч��Խ��
//2.ʱ�临�Ӷȣ�O(N^2)
//3.�ռ临�Ӷ�ΪO��1��
//4.��һ���ȶ�����
//��������֮�ƶ���
void InertSort_1(int*elem, int first, int last)
{
	int end = first + 1;
	for (int i = end; i<last; i++)
	{
		end = i;
		int temp = elem[end];
		while (end > first&&temp < elem[end - 1])
		{
			elem[end] = elem[end - 1];
			end--;
		}
		elem[end] = temp;
	}
}
//ֱ�Ӳ�������--�ڱ���  ��ֹ�Ƚ�Խ�����
void InertSort_2(int*elem, int first, int last)
{
	int end = first + 1;
	for (int i = end; i<last; i++)
	{
		end = i;
		elem[0] = elem[end];
		while (elem[0]< elem[end - 1])
		{
			elem[end] = elem[end - 1];
			end--;
		}
		elem[end] = elem[0];
	}
}
//�۰��������  ���ֲ�������
void BinInsertSort(int *elem, int first, int last)
{
	for (int i=first+1; i < last; i++)
	{
		int temp = elem[i];
		int low = first;
		int high = i - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (elem[mid]>temp)
				high = mid - 1;
			if (elem[mid] <= temp)//Ϊ�ȶ���������㷨
			   low = mid + 1;     //	����д�� ���򻹻����ִ��low = mid + 1;
		}
		for (int j = i; j > low;j--)
			elem[j] = elem[j - 1];
		elem[low] = temp;        //low ��Ϊ��Ҫ�����λ��
	}
}
//ʱ�临�Ӷ���Ȼ��O��n^2��
//��·��������
void TwoWays(int*elem,int first,int last)
{
	int n = last - first;
	int*tem = (int*)malloc(sizeof(int)*n);
	int start, end;
	start = end = 0;
	tem[0] = elem[0];
	for (int i=first+1; i<last; i++)
	{
		if (elem[i]>tem[end])
			tem[++end] = elem[i];
		else if (elem[i] < tem[start])//��֤�ȶ�����
		{
			start = (start - 1 + n) % n;
			tem[start] = elem[i];
		}
		else if (elem[i]<tem[end])
		{
			int j = end;
			while (elem[i] < tem[j])
			{
				tem[(j + 1+n)%n] = tem[j];
				j = (j - 1 + n) % n;
			}
			tem[(j+1 ) % n] = elem[i];
			end++;//��һ������ˣ��´�ǧ����������Ϊ�����ʧ���������ݡ�
		}
	}
	int k = start;
	for (int i = 0; i < n;i++)
	{
		elem[i] = tem[k % n];
		k++;
	}
}
//ϣ������----��С��������
void ShellSort(int*elem, int first, int last)
{
	int ar[3] = { 5, 3, 1 };
	int n = sizeof(ar) / sizeof(ar[0]);
	for (int j = 0; j<n; j++)
	{
		int dk =ar[j];
		for (int i = first; i < last - dk; i++)
		{
			int end = i;
			while (end>=first&&elem[end]>elem[end + dk])
			{
				Swap(&elem[end], &elem[end + dk]);
				end -= dk;
			}
		}
	}
}
//ϣ�������Ż���
void ShellSort_1(int*elem, int first, int last)
{
	int ar[3] = { 5, 3, 1 };
	int n = sizeof(ar) / sizeof(ar[0]);
	for (int j = 0; j<n; j++)
	{
		int dk = ar[j];
		for (int i = first; i < last - dk; i++)
		{
			int end = i;
			int tmp = elem[end];
			while (end>=first&&elem[end]>elem[end + dk])
			{
				elem[end] = elem[end + dk];
				elem[end+dk] = tmp;
				end -= dk;
			}
		}
	}
}
//ϣ�������Ż��汾
void ShellSort_2(int*elem, int first, int last)
{
	int ar[3] = { 5, 3, 1 };
	int n = sizeof(ar) / sizeof(ar[0]);
	for (int j = 0; j<n; j++)
	{
		int dk = ar[j];
		for (int i = first; i < last - dk; i++)
		{
			int end = i;
			int tmp = elem[end+dk];
			while (end>=first && tmp<elem[end])
			{
				elem[end] = elem[end + dk];
				end -= dk;
			}
			elem[end + dk] = tmp;
		}
	}
}
//ϣ�����������Ż��汾
void ShellSort_3(int*elem, int first, int last)
{
	int dk = last - first;
	while (dk>1)//ֻҪdk>1
	{
	    dk = dk/ 3 + 1;
		for (int i = first; i < last - dk; i++)
		{
			if (elem[i + dk]<elem[i])
			{	
				int end = i;
				int temp = elem[end + dk];
				while (end >= first&&elem[end]>temp)
				{
					elem[end+dk] = elem[end];
					end -= dk;
				}
				elem[end + dk] = temp;
			}
		}
	}
}
//ѡ������ֱ֮��ѡ������
int GetInedex(int*elem, int first, int last)
{
	int index = first;
	int min_val = elem[first];
	for (int i=first+1; i < last; i++)
	{
		if (min_val > elem[i])//��С���������
		{
			min_val = elem[i];
			index = i;
		}
	}
	return index;
}
void SelectSort(int*elem, int first, int last)
{
	for (int i = 0; i < last-1; i++)
	{
		int index = GetInedex(elem,i, last);
		if (i != index)
		{
			Swap(&elem[index], &elem[i]);
		}
	}
}
//ֱ��ѡ��������ص�
//1.ֱ��ѡ������������⣬����Ч�ʲ����Ǻܸߡ���ʵ���к����õ�
//2.ʱ�临�Ӷ�ΪO(N^2)
//3.�ռ临�Ӷ�ΪO(1)
//4.�ȶ��ԣ����ȶ�
//ѡ������֮������
void AdjustDown(int*elem, int first, int last, int start)
{
	int i = start;
	int j = 2 * i + 1;
	int n = last - first;
	int temp = elem[i];
	while (j<n)
	{
		if (j + 1 < n && elem[j + 1] > elem[j])
			j++;
		if (temp< elem[j])
		{
			//Swap(&elem[j], &elem[i]);
			elem[i] = elem[j];
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
	elem[i] = temp;//������ˣ�������i����j;
}
void HeapSort(int*elem, int first, int last)
{
     //�������	
	int n = last - first;
	int cur = n / 2 - 1;
	while (cur>=0)
	{
		AdjustDown(elem, first, last, cur);
		cur--;
	}
	//����
	int end = last - 1;
	while (end > first)
	{
		Swap(&elem[end], &elem[first]);
		end--;
		AdjustDown(elem, first, end + 1, first);
		
	}
}
//ѡ������֮ð������
void BubleSort(int*elem, int first, int last)
{
	for (int i = 0; i < last - 1; i++)
	{
		for (int j = 0; j < last - i - 1; j++)//���������Ԫ�ظ�����
		{
			if (elem[j] >elem[j + 1])
			{
				Swap(&elem[j], &elem[j + 1]);
			}
		}
	}
}
//ѡ������֮ð������Ľ���
void BubleSort_1(int*elem, int first, int last)
{
	bool Is_Swap = false;
	for (int i = 0; i < last - 1; i++)
	{
		for (int j = 0; j < last - i - 1; j++)//���������Ԫ�ظ�����
		{
			if (elem[j] >elem[j + 1])//�����ȶ�����
			{
				Swap(&elem[j], &elem[j + 1]);
				Is_Swap = true;
			}
		}
		if (!Is_Swap)
			break;
	}
}
 
//��������horoa�汾
int GetPosition_QuickSort_1(int*elem, int first, int last)
{
	int key = elem[first];
	while (first < last)
	{
		while (first < last&&key <= elem[last])
			last--;
		Swap(&elem[first], &elem[last]);
		while (first < last&&elem[first] < key)
			first++;
		Swap(&elem[first], &elem[last]);
	}
	return first;
}
void QuickSort_1(int*elem, int first, int last)
{
	if (first >= last)
		return;//��һ��ûд�����䣬����һֱ�ж��뱨��
	//QuickSort_1(elem, first, last - 1);
	int pos = GetPosition_QuickSort_1(elem, first, last - 1);
	QuickSort_1(elem, first, pos);
	QuickSort_1(elem, pos + 1, last);
}
//��������֮�ڿӷ�
int GetPosition_QuickSort_2(int*elem, int first, int last)
{
	int key = elem[first];
	while (first < last)
	{
		while (first < last&&key <= elem[last])
			last--;
		elem[first] = elem[last];
		while (first < last&&elem[first] < key)
			first++;
		elem[last] = elem[first];
	}
	elem[first] = key;
	return first;
}
void QuickSort_2(int*elem, int first, int last)
{
	if (first >= last)
		return;//��һ��ûд�����䣬����һֱ�ж��뱨��
	//QuickSort_1(elem, first, last - 1);
	int pos = GetPosition_QuickSort_2(elem, first, last - 1);
	QuickSort_2(elem, first, pos);
	QuickSort_2(elem, pos + 1, last);
}
//����ȡ�з��Թؼ�ֵ���Ż���
int GetIndex(int*elem, int first, int last)
{
	int mid = (first + last) / 2;
	if (elem[first] > elem[last] && elem[first] < elem[mid])
		return first;
	if (elem[last]>elem[first] && elem[last] < elem[mid])
		return last;
	return mid;
}
int GetPosition_QuickSort_3(int*elem, int first, int last)
{
	int mid = GetIndex(elem, first, last);
	if (mid != first)
		Swap(&elem[first], &elem[mid]);
	int pos = first;
	int key = elem[first];
	for (int i = pos + 1; i < last; i++)
	{
		if (elem[i]<key)
		{
			pos++;
			if (pos != i)
				Swap(&elem[i], &elem[pos]);
		}
	}
	Swap(&elem[pos], &elem[first]);
	return pos;
}
//��������֮ǰ��ָ�뷨
/*
int GetPosition_QuickSort_3(int*elem, int first, int last)
{
	int pos = first;
	int key = elem[first];
	for (int i = pos + 1; i < last; i++)
	{
		if (elem[i]<key)
		{
			pos++;
			if (pos != i)
				Swap(&elem[i], &elem[pos]);
		}
	}
	Swap(&elem[pos], &elem[first]);
	return pos;
}
*/
void QuickSort_3(int*elem, int first, int last)
{
	if (first >= last)
		return;//��һ��ûд�����䣬����һֱ�ж��뱨��
	//QuickSort_1(elem, first, last - 1);
	int pos = GetPosition_QuickSort_3(elem, first, last);
	QuickSort_3(elem, first, pos);//ע������ĺ�߽硣
	QuickSort_3(elem, pos + 1, last);
}
//�鲢����
void _MergeSort(int *elem, int first, int last, int *tmp)
{
	if (first >= last)
		return;
	int mid = (first + last) / 2;
	_MergeSort(elem, first, mid, tmp);
	_MergeSort(elem, mid + 1, last, tmp);

	//�鲢
	int begin1, end1, begin2, end2;
	begin1 = first, end1 = mid;
	begin2 = mid + 1, end2 = last;

	int i = first;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (elem[begin1] < elem[begin2])
			tmp[i++] = elem[begin1++];
		else
			tmp[i++] = elem[begin2++];
	}

	while (begin1 <= end1)
	{
		tmp[i++] = elem[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = elem[begin2++];
	}

	memcpy(elem + first, tmp + first, sizeof(int)*(last - first + 1));
}
void MergeSort(int *elem, int first, int last)
{
	int n = last - first;
	int *tmp = (int*)malloc(sizeof(int)* n);
	_MergeSort(elem, first, last - 1, tmp);
	free(tmp);
}
#define Radix 10
#define M 3
static SList ar[Radix];
//��������
int GetKey(int elem,int k)
{
		int key;
		while (k >= 0)
		{
		    key = elem % 10;
			 elem = elem / 10;
			k--;
		}
		return key;
}
void _Distribute(int*elem, int first, int last, int k)
{
	for (int i = first; i < last; i++)
	{
		int key = GetKey(elem[i],k);
		SListPushBack(&ar[key], elem[i]);
	}
}
void _Collect(int*elem)
{
	int k = 0;
	for (int i = 0; i < Radix; i++)
	{
		SListNode*p = ar[i].head;
		while (p != NULL)
		{
			elem[k++] = p->data;
			SListPopFront(&ar[i]);
			p = ar[i].head;
		}
	}
}
void RadixSort(int*elem, int first, int last)
{
	for (int j = 0; j < Radix; j++)
	{
		SListInit(&ar[j]);
	}
	for (int i = 0; i < M; i++)
	{
		_Distribute(elem, first, last, i);
		_Collect(elem);
	}
}
void TestSortEffiency()
{
	int n =5000;
	int*al = (int*)malloc(sizeof(int)*n);
	int*ar = (int*)malloc(sizeof(int)*n);
	int*ar1 = (int*)malloc(sizeof(int)*n);
	int*ar2 = (int*)malloc(sizeof(int)*n);
	int*ar3 = (int*)malloc(sizeof(int)*n);
	int*ar4 = (int*)malloc(sizeof(int)*n);
	int*ar5 = (int*)malloc(sizeof(int)*n);
	int*ar6 = (int*)malloc(sizeof(int)*n);
	int*ar7 = (int*)malloc(sizeof(int)*n);
	int*ar8 = (int*)malloc(sizeof(int)*n);
	int*ar9 = (int*)malloc(sizeof(int)*n);
	int*ar10 = (int*)malloc(sizeof(int)*n);
	int*ar11 = (int*)malloc(sizeof(int)*n);
	int*ar12 = (int*)malloc(sizeof(int)*n);
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		al[i] = rand();
		ar[i] = rand();
		ar1[i] = rand();
		ar2[i] = rand();
		ar3[i] = rand();
		ar4[i] = rand();
		ar5[i] = rand();
		ar6[i] = rand();
		ar7[i] = rand();
		ar8[i] = rand();
		ar9[i] = rand();
		ar10[i] = rand();
		ar11[i] = rand();
		ar12[i] = rand();
	}
	time_t start = clock();
	InertSort(al, 0, n);
	time_t end = clock();
	printf(" ֱ�Ӳ������� InsertSort: %u\n", end - start);
	start = clock();
	InertSort_1(ar, 0, n);
	end = clock();
	printf(" ֱ�Ӳ��������ƶ��� InsertSort_1: %u\n", end - start);
	start = clock();
	InertSort_2(ar1, 1, n);
	end = clock();
	printf(" ֱ�Ӳ��������ڱ��� InsertSort_2: %u\n", end - start);
	start = clock();
	BinInsertSort(ar2, 0, n);
	end = clock();
	printf(" ���ֲ������� BinInsertSort: %u\n", end - start);
	start = clock();
	TwoWays(ar3, 0, n);
	end = clock();
	printf(" ��·�������� TwoWays: %u\n", end - start);
	start = clock();
	ShellSort_1(ar4, 0, n);
	end = clock();
	printf(" ϣ������ ShellSort_1: %u\n", end - start);
	start = clock();
	ShellSort_2(ar5, 0, n);
	end = clock();
	printf(" ϣ�������Ż��� ShellSort_2: %u\n", end - start);
	start = clock();
	ShellSort_3(ar6, 0, n);
	end = clock();
	printf(" ϣ�����������Ż��� ShellSort_3: %u\n", end - start);
	start = clock();
	SelectSort(ar7, 0, n);
	end = clock();
	printf("ֱ��ѡ������SelectSort: %u\n", end - start);
	start = clock();
	HeapSort(ar8, 0, n);
	end = clock();
	printf("������HeapSort: %u\n", end - start);
	start = clock();
	BubleSort(ar9, 0, n);
	end = clock();
	printf("ð������BubleSort: %u\n", end - start);
	start = clock();
	QuickSort_1(ar9, 0, n);
	end = clock();
	printf("��������֮hoare: %u\n", end - start);
	start = clock();
	QuickSort_2(ar9, 0, n);
	end = clock();
	printf("��������֮�ڿӷ�: %u\n", end - start);
	start = clock();
	QuickSort_3(ar9, 0, n);
	end = clock();
	printf("��������֮ǰ��ָ�뷨: %u\n", end - start);
	free(ar);
	free(ar1);
	free(ar2);
	free(ar3);
	free(ar4);
	free(ar5); 
	free(ar6);
	free(ar7);
	free(ar8);
	free(ar9);
	free(ar10);
	free(ar11);
	free(ar12);
}
#define _SORT_H_
#endif