//#include"common.h"
//#include"stack.h"

#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
//////////////////////////////////////////////////////带头结点的单链表////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ListNode
{
	char data;
	struct ListNode*next;
}ListNode;
typedef ListNode*List;//定义指向节点的指针
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
//头插法创建带头结点的单链表
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

//////////////////////////////////////////////////////顺序栈////////////////////////////////////////////////////////
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
		printf("栈已经满，最多插入十个字符串，不能插入\n");
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
		printf("栈已空，不能出栈\n");
		return;
	}
	else
		pt->top--;
}
char TopElem(SeqStack*pt)
{
	if (Is_empty(pt))
	{
		printf("栈已空\n");
		return;
	}
	else
	{
		return pt->data[pt->top - 1];
	}
}
////////////////////////////////////////////////66页///////////////////////////////////////////////////////////////
//3.假设一I和O分别表示入栈和出栈的工作。栈的始态和终态均为空，入栈和出栈的操作系列可表示为仅由I和O组成的序列，可以操
//做的序列成为合法序列，否则称为非法序列。
//通过分析，写一个算法，判定所给的操作序列是否合法，若合法就返回ture，否则就返回false（假定被判定的操作序列已存入）
//(一维数组中）。
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
//4.设单链表对的表头指针为L，结点 结构由data和next两个域构成，其中data域为字符域。试设计算法，判断该链表的全部n个字符
//是否中心对称(只对有效范围内的字符串比较）
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
////////////////////////////////////////////////////////////共用栈///////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//5.设有两个栈s1和s2都采用顺序栈方式，并采用同一个存储区[0....maximum-1]。为了尽量利用空间，减少溢出的可能，采用栈顶相向，
//迎面增长的的存储方式,试着设计s1,和s2有关出栈和入栈的操作算法

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
		printf("操作序列合法\n");
	else
		printf("操作序列非法\n");
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
		printf("字符串对称\n");
	}
	else
		printf("字符串不对称\n");
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
	printf("%d 出栈\n", val);
	SeqStackPop(&st);
	val = SeqStackTop(&st);
	printf("%d 出栈\n", val);
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
	printf("栈顶元素为%d\n ", val);
	LinkStackDestroy(&st);

	system("pause");
}
*/