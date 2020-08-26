#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"




#define MAXSIZE 100 /* 存储空间初始分配量 */

#define HASHSIZE 12 /* 定义散列表长为数组的长度 */
#define NULLKEY -32768 



typedef struct
{
	int *elem; /* 数据元素存储基址，动态分配数组 */
	int count; /*  当前数据元素个数 */
}HashTable;

/* 初始化散列表 */
int InitHashTable(HashTable *H)
{
    H->count = HASHSIZE;
	H->elem = (int *)malloc(HASHSIZE*sizeof(int));
	for (int i = 0; i<m; i++)
		H->elem[i] = NULLKEY;
	return 1;
}

/* 散列函数 */
int Hash(int key)
{
	return key % m; /* 除留余数法 */
}

/* 插入关键字进散列表 */
void InsertHash(HashTable *H, int key)
{
	int addr = Hash(key);                /* 求散列地址 */
	while (H->elem[addr] != NULLKEY)     /* 如果不为空，则冲突 */
	{
		addr = (addr + 1) % m;           /* 开放定址法的线性探测 */
	}
	H->elem[addr] = key;                 /* 直到有空位后插入关键字 */
}

/* 散列表查找关键字 */
int SearchHash(HashTable H, int key, int *addr)
{
	*addr = Hash(key);  /* 求散列地址 */
	while (H.elem[*addr] != key) /* 如果不为空，则冲突 */
	{
		*addr = (*addr + 1) % m; /* 开放定址法的线性探测 */
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key)) /* 如果循环回到原点 */
			return 0;	/* 则说明关键字不存在 */
	}
	return 1;
}

int main()
{
	int arr[HASHSIZE] = { 12, 67, 56, 16, 25, 37, 22, 29, 15, 47, 48, 34 };
	int addr, key;
	HashTable H;
	InitHashTable(&H);
	for (int i = 0; i<m; i++)
		InsertHash(&H, arr[i]);


	printf("请输入要查询的值\n");
	scanf("%d", &key);
	int result = SearchHash(H, key, &addr);
	if (result)
		printf("查找 %d 的地址为：%d \n", key, addr);
	else
		printf("查找 %d 失败。\n", key);

	for (int i = 0; i<m; i++)
	{
		key = arr[i];
		SearchHash(H, key, &addr);
		printf("查找 %d 的地址为：%d \n", key, addr);
	}
	system("pause");
}
