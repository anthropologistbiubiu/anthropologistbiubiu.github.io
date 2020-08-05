#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>
#define ElemType int
typedef struct SListNode
{
	ElemType data;
	struct SListNode*next;
}SListNode;

typedef struct SList
{
	SListNode* head;
}SList;

void SListInit(SList*plist)
{
	assert(plist != NULL);
	plist->head = NULL;
}
static SListNode* Buy_SListNode()
{
	SListNode*p = (SListNode*)malloc(sizeof(SListNode));
	assert(p != NULL);
	return p;
}
void SListPushBack(SList*plist,ElemType x)
{
	assert(plist != NULL);
	SListNode*p = Buy_SListNode();
	p->data = x;
	p->next = NULL;
	if (plist->head == NULL)
	{
		plist->head = p;
		return;
	}
	else
	{
		SListNode* s = plist->head;
		while (s->next!=NULL)
		{
			s = s->next;
		}
		s->next = p;
	}
}
void SListPopFront(SList*plist)
{
	assert(plist != NULL);
	if (plist->head == NULL)
		return;
	plist->head = plist->head->next;
}
