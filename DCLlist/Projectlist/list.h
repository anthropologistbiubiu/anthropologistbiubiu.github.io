#ifndef _LIST_H_
#define _LIST_H_
#include"common.h"
//////////////////////////////////////////////////////////////
////////////////////带头结点的双循环链表//////////////////////
/*
static DCListNode* _Buydnode(ElemType x);//开辟结点
void DCListInit(DCList*plist);//初始化
void DCListPushBack(DCList*plist, ElemType x);//尾插法
void DCListPushFront(DCList*plist, ElemType x);//头插法
void DCListPopBack(DCList*plist);//尾部删除法
void DCListPopFront(DCList*plist);//头删法
DCListNode* DCListFind(DCList*plist, ElemType x);//按值查找
void DCListShow(DCList*plist);//显示打印
size_t DCListLength(DCList*plist);//求链表长度
void DCListClear(DCList*plist);//清楚链表
void DCListDestroy(DCList*plist);//摧毁链表
void DCListDeleteByVal(DCList*plist, ElemType x);//按值删除
void DCListByValInsert(DCList*plist, ElemType x);//按值插入
void DCListReverse(DCList*plist);//转置链表
void DCListSort(DCList*plist);//链表排序
*/
//////////////////////////////////////////////////////////////
typedef struct DCListNode
{
	ElemType data;
	struct DCListNode* next;
	struct DCListNode* prev;
} DCListNode;
typedef struct DCList
{
	DCListNode* head;
}DCList;
static DCListNode* _Buydnode(ElemType x)
{
	DCListNode*s = (DCListNode*)malloc(sizeof(DCListNode));
	assert(s != NULL);
	s->data = x;
	s->next = s->prev = s;
	return s;
}
void DCListInit(DCList* plist)
{
	assert(plist != NULL);
	plist->head = _Buydnode(0);
}
void DCListPushBack(DCList*plist, ElemType x)
{
	assert(plist != NULL);
	DCListNode*s = _Buydnode(x);
	s->prev = plist->head->prev;
	//s->prev = plist->head;
	s->prev->next = s;
	//plist->head->next = s;
	s->next = plist->head;
	plist->head->prev = s;
}
void DCListPushFront(DCList*plist, ElemType x)
{
	assert(plist != NULL);
	DCListNode*s =_Buydnode(x);
	s->next = plist->head->next;
	s->prev = plist->head;
	//plist->head->next = s;
	//plist->head->next->prev = s;
	s->next->prev = s;
	plist->head->next = s;
}
void DCListPopBack(DCList*plist)
{
	assert(plist != NULL);
	DCListNode*s = plist->head->next;
	assert(s != NULL);
	while (s->next->next != plist->head)
	{
		s = s->next;
	}
	free(s->next);
	s->next = plist->head;
	plist->head->prev = s;
}
/*
void DCListPopBack(DCList*plist)
{
    assert(plist != NULL);
	DCListNode*p = plist->head ->prev;
	if (p == plist->head)
	{
		return;
	}
	p->prev ->next  = plist->head;
	plist->head->prev = p->prev;
	free(p);
}
*/
void DCListPopFront(DCList*plist)
{
	assert(plist != NULL);
	DCListNode*s = plist->head->next;
	if (s == plist->head)
		return;
	s->next->prev = plist->head;
	plist->head->next = s->next;
	free(s);
}
DCListNode* DCListFind(DCList*plist, ElemType x)
{
	DCListNode*p = plist->head->next;
	if (p == plist->head)
		return;
	while (p->data != x&&p!= plist->head)
		p = p->next;
	return p;
}
void DCListShow(DCList*plist)
{
	assert(plist != NULL);
	DCListNode*p = plist->head->next;
	while (p != plist->head)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("over.\n");
}
size_t DCListLength(DCList*plist)
{
	assert(plist != NULL);
	size_t len = 0;
	DCListNode*p = plist->head->next;
	while (p != plist->head)
	{
		len++;
		p = p->next;
	}
	return len;
}
 void DCListClear(DCList*plist)
{
	assert(plist != NULL);
	DCListNode*p = plist->head->next;
	while (p != plist->head)
	{
		p->next->prev = p->prev;
		p->prev->next = p->next;
		free(p);
		p = plist->head->next;
	}
}
 void DCListDestroy(DCList*plist)
 {
	 assert(plist != NULL);
	 DCListClear(plist);
	 free(plist->head);
	 plist= NULL;
 }
 void DCListDeleteByVal(DCList*plist, ElemType x)
 {
	 assert(plist != NULL);
	 DCListNode*p = DCListFind(plist, x);
	 if (p == NULL)
	 {
		 return;
	 }
	 p->next->prev = p->prev;
	 p->prev->next = p->next;
	 free(p);
 }
 void DCListByValInsert(DCList*plist, ElemType x)
 {   
	 assert(plist != NULL);
	 DCListNode*p = plist->head -> next;
	 while (p != plist->head&&p->data < x)
		 p = p->next;
	 DCListNode*s = _Buydnode(x);
	 s->next = p;
	 s->prev = p->prev;
	 p->prev->next = s;
	 p->prev = s;
	
 }
void DCListReverse(DCList*plist)
 {
	 assert(plist != NULL);
	 DCListNode*p = plist->head->next;
	 DCListNode*q = p->next;
	 p->next = plist->head;
	 plist->head->prev = p;
	 while (q != plist->head)
	 {
		 p = q;
		 q = q->next;
		 p->next = plist->head->next;
		 p->prev = plist->head;
		 p->next->prev = p;
		 p->prev->next = p;
	 }
 }
void DCListSort(DCList*plist)
 {
	 assert(plist != NULL);
	 DCListNode*p = plist->head->next;
	 DCListNode*q = p->next;
	 p->next = plist->head;
	 plist->head->prev = p;
	 while (q != plist->head)
	 {
		 p = q;
		 q = q->next;
		 DCListNode*t = plist->head->next;
		 while (t != plist->head&&t->data < p->data)
		 {
			 t = t->next;
		 }
		 p->next = t;
		 p->prev = t->prev;
		 p->next->prev = p;
		 p->prev->next = p;
		 p = q;
	 }
 }
#endif   /*_LIST_H_*/