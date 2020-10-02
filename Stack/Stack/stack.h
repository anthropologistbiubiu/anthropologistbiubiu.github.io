#ifndef _STACK_H_
#define _STACK_H_
#include"common.h"
#define SEQSTACK_DEFAULT_SIZE 8
///////////////////////////////
//顺序栈

typedef struct SeqStack
{
	ElemType* base;
	size_t capacity;
	int top;
}SeqStack;
void SeqStackInit(SeqStack*pst)
{
	pst->base = (ElemType*)malloc(sizeof(SeqStack)*SEQSTACK_DEFAULT_SIZE);
	pst->capacity = SEQSTACK_DEFAULT_SIZE;
	pst->top = 0;
}
bool SeqStackIsFull(SeqStack*pst)
{
	assert(pst != NULL);
	return pst->top >= pst->capacity;
}
bool SeqStackIsEmpty(SeqStack*pst)
{
	assert(pst != NULL);
	return pst->top == 0;
}
void SeqStackPush(SeqStack*pst, ElemType x)
{
	assert(pst != NULL);
	if (SeqStackIsFull(pst))
	{
		printf("顺序栈已满，%d 不能插入\n", x);
		return;
	}
	pst->base[pst->top] = x;
	pst->top++;
}
void SeqStackPop(SeqStack*pst)
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("栈为空，不能出栈\n");
		return;
	}
	pst->top--;
}
ElemType SeqStackTop(SeqStack*pst)
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("栈为空，不能出栈\n");
		return;
	}
	return pst->base[pst->top - 1];
}
void SeqStackDestroy(SeqStack*pst)
{
	assert(pst != NULL);
	pst->base = NULL;
	pst->capacity = pst->top = 0;

}
void SeqStackPrint(SeqStack*pst)
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
		return;
	for (int i = pst->top - 1; i >= 0; i--)
		printf("%d\n", pst->base[i]);
	printf("\n");
}
///////////////////////////////////////////////
//链栈
typedef struct LinkStackNode
{
	ElemType data;
	struct LinkStackNode* link;
}LinkStackNode;
typedef struct LinkStack
{
	LinkStackNode*top;
}LinkStack;
void LinkStackInit(LinkStack*pst)
{
	assert(pst != NULL);
	pst->top = NULL;
}
void LinkStackPush(LinkStack*pst, ElemType x)
{
	assert(pst != NULL);
	LinkStackNode*node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(node != NULL);
	node->data = x;
	node->link = pst->top;
	pst->top = node;
}
void LinkStackPop(LinkStack*pst)
{
	assert(pst != NULL);
	LinkStackNode*p = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	p = pst->top;
	pst->top = p->link;
	free(p);
}
ElemType LinkStackTop(LinkStack*pst)
{
	assert(pst != NULL);
	if (pst->top == NULL)
	{
		printf("数据站为空，特种兵扑了空\n");
	}
	if (pst->top != NULL)
		return pst->top->data;
}
void LinkStackDestroy(LinkStack*pst)
{
	assert(pst != NULL);
	if (pst->top == NULL)
	{
		printf("数据站为空，特种兵扑了空\n");
	}
	while (pst->top != NULL)
	{
		LinkStackNode*p = pst->top;
		pst->top = p->link;
		free(p);
	}
	printf("特种兵摧毁数据栈成功，光荣完成党和国家交给的使命\n");
}
void LinkStackPrint(LinkStack*pst)
{
	assert(pst != NULL);
	LinkStackNode*p = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	p = pst->top;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->link;
	}
	printf("\n");
}
#endif