//插入排序  
//直接插入排序
#include"sort.h"
 
void main()
{
	int ar[] = { 155, 380, 653, 973, 676, 113, 227, 649 };
	int n = sizeof(ar) / sizeof(ar[0]);
	PrintElement(ar, 0, n);
	//InertSort(ar, 0, n);
	//InertSort_1(ar, 0, n);
	//InertSort_2(ar, 1, n);
	//BinInsertSort(ar, 0, n);
	//TwoWays(ar, 0, n);
	//ShellSort(ar, 0, n);
	//ShellSort_1(ar, 0, n);
	//ShellSort_2(ar, 0, n);
	//ShellSort_3(ar, 0, n);
	//SelectSort(ar, 0, n);
	// HeapSort(ar, 0, n);
	 //BubleSort(ar, 0, n);
	//BubleSort_1(ar, 0, n);
	//QuickSort_1(ar, 0, n);
	//QuickSort_2(ar, 0, n);
	//QuickSort_3(ar, 0, n);
	 //MergeSort(ar, 0, n);
	 RadixSort(ar, 0, n);
	PrintElement(ar, 0, n);
	// TestSortEffiency();
	 system("pause");
}