//#include"common.h"
//#include"stack.h"

#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
//////////////////////////////////////////////////////��ͷ���ĵ�����////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ListNode
{
	char data;
	struct ListNode*next;
}ListNode;
typedef ListNode*List;//����ָ��ڵ��ָ��
void ListInit(List*plist)
{
	*plist = (ListNode*)malloc(sizeof(ListNode));
	(*plist)->next = NULL;
}
static ListNode* BuyNode(int x)
{
	ListNode*s = (ListNode*)malloc(sizeof(ListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}
//ͷ�巨������ͷ���ĵ�����
void ListCreat_Head(List*plist)
{
	assert(plist != NULL);
	for (int x = 1; x <= 10; ++x)
	{
		ListNode*s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = x;
		s->next = (*plist)->next;
		(*plist)->next = s;
	}
}
void ListPushBack(List*plist, int x)
{
	ListNode*p = BuyNode(x);
	assert(plist != NULL);
	if ((*plist)->next == NULL)
	{
		(*plist)->next = p;
		return;
	}
	ListNode*pt = (*plist)->next;
	while (pt->next != NULL)
	{
		pt = pt->next;
	}
	pt->next = p;
}
void ListShow(List plist)
{
	ListNode*p = plist->next;
	while (p != NULL)
	{
		printf("%c->", p->data);
		p = p->next;
	}
	printf("over\n");
}

//////////////////////////////////////////////////////˳��ջ////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct SeqStack
{
	char* data;
	int capacity;
	int top;
}SeqStack;
void SeqInit(SeqStack*pt)
{
	pt->data = (char*)malloc(sizeof(char)* 10);
	pt->capacity = 10;
	pt->top = 0;
}
bool Is_empty(SeqStack*pt)
{
	assert(pt != NULL);
	return pt->top == 0;
}
bool Is_full(SeqStack*pt)
{
	assert(pt != NULL);
	return pt->top >= pt->capacity;
}
void SeqStackPush(SeqStack*pt,char item)
{
	if (Is_full(pt))
	{
		printf("ջ�Ѿ�����������ʮ���ַ��������ܲ���\n");
		return;
	}
	else
	{
		pt->data[pt->top++] = item;
	}
}
void SeqStackPop(SeqStack*pt)
{
	assert(pt != NULL);
	if (pt->top == 0)
	{
		printf("ջ�ѿգ����ܳ�ջ\n");
		return;
	}
	else
		pt->top--;
}
char TopElem(SeqStack*pt)
{
	if (Is_empty(pt))
	{
		printf("ջ�ѿ�\n");
		return;
	}
	else
	{
		return pt->data[pt->top - 1];
	}
}
////////////////////////////////////////////////66ҳ///////////////////////////////////////////////////////////////
//3.����һI��O�ֱ��ʾ��ջ�ͳ�ջ�Ĺ�����ջ��ʼ̬����̬��Ϊ�գ���ջ�ͳ�ջ�Ĳ���ϵ�пɱ�ʾΪ����I��O��ɵ����У����Բ�
//�������г�Ϊ�Ϸ����У������Ϊ�Ƿ����С�
//ͨ��������дһ���㷨���ж������Ĳ��������Ƿ�Ϸ������Ϸ��ͷ���ture������ͷ���false���ٶ����ж��Ĳ��������Ѵ��룩
//(һά�����У���
bool Judge(SeqStack*plist,char*elem,int n)
{
	for (int i = 0; i < n; i++)
	{
		if (elem[i] == 'I')
			SeqStackPush(plist, elem[i]);
		else if(elem[i] == 'O')
		{
			if (Is_empty(plist))
				return false;
			else
			{
				SeqStackPop(plist);
			}
		}
	}
	return true;
}
//4.�赥����Եı�ͷָ��ΪL����� �ṹ��data��next�����򹹳ɣ�����data��Ϊ�ַ���������㷨���жϸ������ȫ��n���ַ�
//�Ƿ����ĶԳ�(ֻ����Ч��Χ�ڵ��ַ����Ƚϣ�
bool Is_symmetry(List plist)
{
	List p = plist->next;
	char item;
	SeqStack pt;
	SeqInit(&pt);
	while (p != NULL)
	{
		
		SeqStackPush(&pt, p->data);
		p = p->next;
	}
	 p = plist->next;
	while ((&pt)->top != 0)
	{
		if (p->data == TopElem(&pt))
		{
			p = p->next;
			(&pt)->top--;
		}
		else
			break;
	}
	if ((&pt)->top==0)  
		return true;
	else
		return false;
}
////////////////////////////////////////////////////////////����ջ///////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//5.��������ջs1��s2������˳��ջ��ʽ��������ͬһ���洢��[0....maximum-1]��Ϊ�˾������ÿռ䣬��������Ŀ��ܣ�����ջ������
//ӭ�������ĵĴ洢��ʽ,�������s1,��s2�йس�ջ����ջ�Ĳ����㷨

#define maximum 10
typedef struct SharedStack
{
	char* data;
	int capacity;
	int top[2];
}SharedStack;
void SharedStackInit(SharedStack*pt)
{
	pt->data = (char*)malloc(sizeof(char)* maximum);
	pt->capacity = maximum;
	pt->top[0] = -1;
	pt->top[1]= maximum ;
}
bool Is_Empty_SharedStack(SharedStack*pt)
{
	assert(pt != NULL);
	return pt->top[0] ==0 || pt->top[1] == maximum - 1;
}
bool Is_Full_SharedStack(SharedStack*pt)
{
	assert(pt != NULL);
	return pt->top[1] - pt->top[0] == 1;

}
void SharedStackPush(SharedStack*pt,int i,int x)
{
	assert(pt != NULL);
	bool flag=Is_Full_SharedStack(pt);
	if (flag)
		return;
	else
	{
		if (i==0)
		{
			pt->top[i]++;
			pt->data[pt->top[i]] = x;
			
		}
		else if (i==1)
		{
			pt->top[i]--;
			pt->data[pt->top[i]] = x;
			
		}
	}
}
void SharedStackPop(SharedStack*pt, int i)
{
	bool flag = Is_Empty_SharedStack(pt);
	if (flag)
		return;
	else
	{
		if (i == 0)
		{
			pt->top[i]--;
		}
		else if (i == 1)
		{
			pt->top[i]++;
		}
	}
}
void SharedStackShow(SharedStack*pt, int i)
{
	if (i ==0)
	{
		for (int j = 0; j <= pt->top[i]; j++)
			printf("%d->", pt->data[j]);
		printf("over\n");
	}
	else if (i==1)
	{
		for (int k = maximum - 1; k>=pt->top[i]; k--)
		{
			printf("%d->", pt->data[k]);
		}
			
		printf("over\n");
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////











/*
void  main()
{
	SharedStack bt;
	int item;
	SharedStackInit(&bt);
	while (scanf_s("%d", &item), item != -1)
	{
		SharedStackPush(&bt, 0,item);
	}
	SharedStackShow(&bt, 0);
	while (scanf_s("%d", &item), item != -1)
	{
		SharedStackPush(&bt, 1, item);
	}
	SharedStackShow(&bt,1);
	SharedStackPop(&bt, 0);
	SharedStackShow(&bt, 0);
	SharedStackPop(&bt, 1);
	SharedStackShow(&bt, 1);
	system("pause");
}

void main()
{
	SeqStack bt;
	SeqInit(&bt);
	char elem[] = { 'I', 'O', 'I', 'I', 'O', 'I', 'O', 'O' };
	int n = sizeof(elem) / sizeof(elem[0]);
	bool flag=Judge(&bt, elem, n);
	if (flag)
		printf("�������кϷ�\n");
	else
		printf("�������зǷ�\n");
	system("pause");
}
void main()
{
	char item;
	bool flag;
	List bt;
	ListInit(&bt);
	
	flag=Is_symmetry(bt);
	if (flag)
	{
		printf("�ַ����Գ�\n");
	}
	else
		printf("�ַ������Գ�\n");
	system("pause");
}

void main()
{
	SeqStack st;
	SeqStackInit(&st);
	SeqStackPush(&st, 1);
	SeqStackPush(&st, 2);
	SeqStackPush(&st, 3);
	SeqStackPush(&st, 4);
	SeqStackPush(&st, 5);
	SeqStackPush(&st, 6);
	SeqStackPush(&st, 7);
	SeqStackPush(&st, 8);
	SeqStackPush(&st, 9);
	SeqStackPush(&st, 10);
	SeqStackPrint(&st);
	ElemType val = SeqStackTop(&st);
	printf("%d ��ջ\n", val);
	SeqStackPop(&st);
	val = SeqStackTop(&st);
	printf("%d ��ջ\n", val);
	SeqStackPop(&st);
	SeqStackPrint(&st);
	system("pause");
}
void main()
{
	LinkStack st;
	LinkStackInit(&st);
	LinkStackPush(&st, 1);
	LinkStackPush(&st, 2);
	LinkStackPush(&st, 3);
	LinkStackPush(&st, 4);
	LinkStackPush(&st, 5);
	LinkStackPush(&st, 6);
	LinkStackPush(&st, 7);
	LinkStackPush(&st, 8);
	LinkStackPrint(&st);
	LinkStackPop(&st);
	LinkStackPop(&st);
	LinkStackPrint(&st);
	ElemType val = LinkStackTop(&st);
	printf("ջ��Ԫ��Ϊ%d\n ", val);
	LinkStackDestroy(&st);

	system("pause");
}
*/