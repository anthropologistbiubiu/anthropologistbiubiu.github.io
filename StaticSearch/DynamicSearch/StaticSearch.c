#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  


int F[20];		/* 쳲��������� */

/* ���ڱ�˳����ң�aΪ���飬nΪҪ���ҵ����������keyΪҪ���ҵĹؼ��� */
int Sequential_Search(int *a, int n, int key)
{
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == key)
			return i;
	}
	return 999;
}
/* ���ڱ�˳����� */
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

/* �۰���� */
int Binary_Search(int *a, int n, int key)
{
	int low = 1;							/* ��������±�Ϊ��¼��λ */
	int high = n;						/* ��������±�Ϊ��¼ĩλ */
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;		/* �۰� */
		if (key<a[mid])				/* ������ֵ����ֵС */
			high = mid - 1;			/* ����±��������λ�±�Сһλ */
		else if (key>a[mid])			/* ������ֵ����ֵ�� */
			low = mid + 1;			/* ����±��������λ�±��һλ */
		else
		{
			return mid;				/* �������˵��mid��Ϊ���ҵ���λ�� */
		}
	}
	return 0;
}

/* ��ֵ���� */
int Interpolation_Search(int *a, int n, int key)
{
	int low, high, mid;
	low =1;							/* ��������±�Ϊ��¼��λ */
	high = n;						/* ��������±�Ϊ��¼ĩλ */
	while (low <= high)
	{
		mid = low + (high - low)*(key - a[low]) / (a[high] - a[low]); /* ��ֵ */
		if (key<a[mid])				/* ������ֵ�Ȳ�ֵС */
			high = mid - 1;			/* ����±��������ֵ�±�Сһλ */
		else if (key>a[mid])			/* ������ֵ�Ȳ�ֵ�� */
			low = mid + 1;			/* ����±��������ֵ�±��һλ */
		else
			return mid;				/* �������˵��mid��Ϊ���ҵ���λ�� */
	}
	return 0;
}

/* 쳲��������� */
int Fibonacci_Search(int *a, int n, int key)
{
	int k = 0;
	int low =1;								/* ��������±�Ϊ��¼��λ */
	int high = n;							/* ��������±�Ϊ��¼ĩλ */
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
				return mid;			/* �������˵��mid��Ϊ���ҵ���λ�� */
			else
				return 0;
		}
	}
	return 0;
}
int fibMonaccianSearch(int arr[], int x, int n)
{
	//��ʼ��쳲���������
	int fibMm2 = 0; // ��(m-2)��쳲�������
	int fibMm1 = 1; // ��(m-1)��쳲�������
	int fibM = fibMm2 + fibMm1; //��m��쳲���������

	/* fibM ������ڵ������鳤�� n ����С쳲�������*/
	while (fibM < n)
	{
		fibMm2 = fibMm1;
		fibMm1 = fibM;
		fibM = fibMm2 + fibMm1;
	}
	// ���ڱ���Ѿ����ҹ��Ҳ���Ҫ�ٲ��ҵ�������±�
	int offset = -1; 
	while (fibM > 1)
	{
		// ȷ��mid ��������±귶Χ֮�� 
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

