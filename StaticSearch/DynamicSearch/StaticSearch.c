#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  


int F[20];		/* 斐波那契数列 */

/* 无哨兵顺序查找，a为数组，n为要查找的数组个数，key为要查找的关键字 */
int Sequential_Search(int *a, int n, int key)
{
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == key)
			return i;
	}
	return 999;
}
/* 有哨兵顺序查找 */
int Sequential_Search2(int *a, int n, int key)
{
	a[0] = key;
	int i = n;
	while (a[i] != key)
	{
		i--;
	}
	return i;
}

/* 折半查找 */
int Binary_Search(int *a, int n, int key)
{
	int low = 1;							/* 定义最低下标为记录首位 */
	int high = n;						/* 定义最高下标为记录末位 */
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;		/* 折半 */
		if (key<a[mid])				/* 若查找值比中值小 */
			high = mid - 1;			/* 最高下标调整到中位下标小一位 */
		else if (key>a[mid])			/* 若查找值比中值大 */
			low = mid + 1;			/* 最低下标调整到中位下标大一位 */
		else
		{
			return mid;				/* 若相等则说明mid即为查找到的位置 */
		}
	}
	return 0;
}

/* 插值查找 */
int Interpolation_Search(int *a, int n, int key)
{
	int low, high, mid;
	low =1;							/* 定义最低下标为记录首位 */
	high = n;						/* 定义最高下标为记录末位 */
	while (low <= high)
	{
		mid = low + (high - low)*(key - a[low]) / (a[high] - a[low]); /* 插值 */
		if (key<a[mid])				/* 若查找值比插值小 */
			high = mid - 1;			/* 最高下标调整到插值下标小一位 */
		else if (key>a[mid])			/* 若查找值比插值大 */
			low = mid + 1;			/* 最低下标调整到插值下标大一位 */
		else
			return mid;				/* 若相等则说明mid即为查找到的位置 */
	}
	return 0;
}

/* 斐波那契查找 */
int Fibonacci_Search(int *a, int n, int key)
{
	int k = 0;
	int low =1;								/* 定义最低下标为记录首位 */
	int high = n;							/* 定义最高下标为记录末位 */
	while (n>F[k] - 1)
		k++;
	for (int i = n; i<F[k] - 1; i++)
		a[i] = a[n];

	while (low <= high)
	{
		int mid = low + F[k - 1] - 1;
		if (key<a[mid])
		{
			high = mid - 1;
			k = k - 1;
		}
		else if (key>a[mid])
		{
			low = mid + 1;
			k = k - 2;
		}
		else
		{
			if (mid <= n)
				return mid;			/* 若相等则说明mid即为查找到的位置 */
			else
				return 0;
		}
	}
	return 0;
}
int fibMonaccianSearch(int arr[], int x, int n)
{
	//初始化斐波那契数列
	int fibMm2 = 0; // 第(m-2)个斐波那契数
	int fibMm1 = 1; // 第(m-1)个斐波那契数
	int fibM = fibMm2 + fibMm1; //第m个斐波那契数。

	/* fibM 保存大于等于数组长度 n 的最小斐波那契数*/
	while (fibM < n)
	{
		fibMm2 = fibMm1;
		fibMm1 = fibM;
		fibM = fibMm2 + fibMm1;
	}
	// 用于标记已经查找过且不需要再查找的数组的下标
	int offset = -1; 
	while (fibM > 1)
	{
		// 确保mid 在数组的下标范围之内 
		int mid = min(offset + fibMm2, n - 1);
		if (arr[mid] < x)
		{
			fibM = fibMm1;
			fibMm1 = fibMm2;
			fibMm2 = fibM - fibMm1;
			offset = mid;
		}
		else if (arr[mid] > x)
		{
			fibM = fibMm2;
			fibMm1 = fibMm1 - fibMm2;
			fibMm2 = fibM - fibMm1;
		}
		else
			return mid;
	}
	if (fibMm1 && arr[offset + 1] == x)      
		return offset + 1;
	return -1;
}
int main()
{
	int arr[] = { 0, 1, 2, 16, 24, 35, 47, 59, 62, 73, 88, 99, 100 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int key,result;
	scanf("%d", &key);
	result = Sequential_Search(arr, n-1, key);
	printf("Sequential_Search:%d \n",result);
	result = Sequential_Search2(arr, n-1, key);
	printf("Sequential_Search2:%d \n", result);

	
	result = Binary_Search(arr, n-1, key);
	printf("Binary_Search:%d \n", result);


	result = Interpolation_Search(arr, n-1, key);
	printf("Interpolation_Search:%d \n", result);


	F[0] = 0;
	F[1] = 1;
	for (int i = 2; i < 100; i++)
	{
		F[i] = F[i - 1] + F[i - 2];
	}
	result = Fibonacci_Search(arr, n-1, key);
	printf("Fibonacci_Search:%d \n", result);
	
	
	
	result=fibMonaccianSearch(arr, key, n);
	printf("Fibonacci_Search:%d \n", result);
	system("pause");
}

