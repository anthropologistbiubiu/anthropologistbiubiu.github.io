#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"




#define MAXSIZE 100 /* �洢�ռ��ʼ������ */

#define HASHSIZE 12 /* ����ɢ�б�Ϊ����ĳ��� */
#define NULLKEY -32768 



typedef struct
{
	int *elem; /* ����Ԫ�ش洢��ַ����̬�������� */
	int count; /*  ��ǰ����Ԫ�ظ��� */
}HashTable;

/* ��ʼ��ɢ�б� */
int InitHashTable(HashTable *H)
{
    H->count = HASHSIZE;
	H->elem = (int *)malloc(HASHSIZE*sizeof(int));
	for (int i = 0; i<m; i++)
		H->elem[i] = NULLKEY;
	return 1;
}

/* ɢ�к��� */
int Hash(int key)
{
	return key % m; /* ���������� */
}

/* ����ؼ��ֽ�ɢ�б� */
void InsertHash(HashTable *H, int key)
{
	int addr = Hash(key);                /* ��ɢ�е�ַ */
	while (H->elem[addr] != NULLKEY)     /* �����Ϊ�գ����ͻ */
	{
		addr = (addr + 1) % m;           /* ���Ŷ�ַ��������̽�� */
	}
	H->elem[addr] = key;                 /* ֱ���п�λ�����ؼ��� */
}

/* ɢ�б���ҹؼ��� */
int SearchHash(HashTable H, int key, int *addr)
{
	*addr = Hash(key);  /* ��ɢ�е�ַ */
	while (H.elem[*addr] != key) /* �����Ϊ�գ����ͻ */
	{
		*addr = (*addr + 1) % m; /* ���Ŷ�ַ��������̽�� */
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key)) /* ���ѭ���ص�ԭ�� */
			return 0;	/* ��˵���ؼ��ֲ����� */
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


	printf("������Ҫ��ѯ��ֵ\n");
	scanf("%d", &key);
	int result = SearchHash(H, key, &addr);
	if (result)
		printf("���� %d �ĵ�ַΪ��%d \n", key, addr);
	else
		printf("���� %d ʧ�ܡ�\n", key);

	for (int i = 0; i<m; i++)
	{
		key = arr[i];
		SearchHash(H, key, &addr);
		printf("���� %d �ĵ�ַΪ��%d \n", key, addr);
	}
	system("pause");
}
