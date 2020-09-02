#ifndef _TREE_H_
#define _TREE_H_
#include"common.h"
typedef struct BinTreeNode   //定义树的节点
{
	ElemType data;
	struct BinTreeNode*leftchild;
	struct BinTreeNode*rightchild;

}BinTreeNode;
typedef struct BinTree     //定义树
{
	BinTreeNode*root;
}BinTree;
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
#define LEVEL_ORDER//定义链式队列
#ifdef LEVEL_ORDER

typedef struct LinkQueueNode
{
	BinTreeNode* data;
	struct LinkQueueNode*Link;
}LinkQueueNode;
typedef struct LinkQueue
{
	LinkQueueNode*front;
	LinkQueueNode*rear;
}LinkQueue;

void LinkQueueInit(LinkQueue*pq)
{
	pq->front = pq->rear = NULL;
}
void LinkQueueEnque(LinkQueue*pq, BinTreeNode* x)
{
	assert(pq != NULL);
	LinkQueueNode*node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if (pq->front == NULL)
	{
		node->data = x;
		node->Link = NULL;
		pq->front = pq->rear = node;
	}
	else
	{
		assert(node != NULL);
		node->data = x;
		node->Link = NULL;
		pq->rear->Link = node;
		pq->rear = node;
	}

}
void LinkQueueDeque(LinkQueue*pq)
{
	assert(pq != NULL);
	if (pq->front != NULL)
	{
		LinkQueueNode*p;
		p = pq->front;
		pq->front = pq->front->Link;
		free(p);
	}
}
void LinkQueuePrint(LinkQueue*pq)
{
	assert(pq != NULL);
	LinkQueueNode*p = pq->front;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->Link;
	}
	printf("\n");
}
bool LinkQueueEmpty(LinkQueue*pq)
{
	assert(pq != NULL);
	return pq->front == NULL;
}
BinTreeNode* LinkQueueFront(LinkQueue*pq)
{
	if (pq->front != NULL)
		return pq->front->data;
}
#endif
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
#define ORDER_NOR//定义链栈
#ifdef ORDER_NOR
typedef struct LinkStackNode
{
	BinTreeNode* data;
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
void LinkStackPush(LinkStack*pst, BinTreeNode* x)
{
	assert(pst != NULL);
	LinkStackNode*node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(node != NULL);
	node->data = x;
	node->link = pst->top;
	pst->top = node;
}
BinTreeNode* LinkStackPop(LinkStack*pst)
{
	assert(pst != NULL);
	LinkStackNode*p = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	p = pst->top;
	pst->top = p->link;
	free(p);
}
BinTreeNode* LinkStackTop(LinkStack*pst)
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
bool LinkStackEmpty(LinkStack*pst)
{
	return pst->top == NULL;
}
#endif
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//初始化
void BinTreeInit(BinTree*bt);
//创建
void BinTreeInit(BinTree*bt);
void BinTreeCreate_1(BinTreeNode**t);
BinTreeNode* BinTreeNodeCreat_2();
void BinTreeCreat(BinTree*bt);
BinTreeNode* BinTreeCreatByStr_1(const char*str, int*pindex);
void BinTreeCreatByStr(BinTree*bt, const char*str);
//遍历
void PreOder_1(BinTreeNode*t);
void PreOrder(BinTree*bt);
void InOder_1(BinTreeNode*t);
void InOrder(BinTree*bt);
void PostOder_1(BinTreeNode*t);
void PostOrder(BinTree*bt);
void LevelOrder_1(BinTreeNode*t);
void LevelOrder(BinTree*bt);
//查询
BinTreeNode* BinTreeFind_1(BinTreeNode*t, ElemType key);
BinTreeNode* BinTreeFind(BinTree*bt, ElemType key);
BinTreeNode* BinTreeParant_1(BinTreeNode*t, ElemType key);
BinTreeNode* BinTreeParant(BinTree*bt, ElemType key);
//拷贝
BinTreeNode* BinTreeCopy_1(BinTreeNode*t);
void BinTreeCopy(BinTree*bt1, BinTree*bt2);
//判断
bool BinTreeEqual_1(BinTreeNode*t1, BinTreeNode*t2);
bool BinTreeEqual(BinTree *bt1, BinTree *bt2);
//节点
int BinTreeCount_1(BinTreeNode*t);
int BinTreeCount(BinTree*bt);
//高度
int BinTreeHeight_1(BinTreeNode*t);
int BinTreeHeight(BinTree*bt);
//摧毁
void BinTreeDestroy_1(BinTreeNode*t);
void  BinTreeDestroy(BinTree*bt);
/////////////////////////////////////////////////////
void BinTreeInit(BinTree*bt)
{
	bt->root = NULL;
}
void BinTreeCreate_1(BinTreeNode**t)
{
	assert(t != NULL);
	ElemType item;
	scanf_s("%c", &item);
	if (item == '#')
		*t = NULL;
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		(*t)->data = item;
		BinTreeCreate_1(&(*t)->leftchild);
		BinTreeCreate_1(&((*t)->rightchild));
	}
}
BinTreeNode* BinTreeNodeCreat_2()
{
	ElemType item;
	scanf_s("%c", &item);
	if (item == '#')
		return NULL;
	else
	{
		BinTreeNode*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = item;
		t->leftchild = BinTreeNodeCreat_2();
		t->rightchild = BinTreeNodeCreat_2();
		return t;
	}
}
void BinTreeCreat(BinTree*bt)
{
	BinTreeCreate_1(&(bt->root));
	//bt->root = BinTreeNodeCreat_2();

}
//通过给如字符串直接创建二叉树
BinTreeNode* BinTreeCreatByStr_1(const char*str, int*pindex)
{
	if (str[*pindex] == '#' || str[*pindex] == '\0')
	{
		return NULL;
	}
	else
	{
		BinTreeNode*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = str[*pindex];
		(*pindex)++;
		t->leftchild = BinTreeCreatByStr_1(str, pindex);
		(*pindex)++;
		t->rightchild = BinTreeCreatByStr_1(str, pindex);
		return t;
	}
}
void BinTreeCreatByStr(BinTree*bt, const char*str)
{
	int index = 0;
	bt->root = BinTreeCreatByStr_1(str, &index);
}
//前序遍历
void PreOder_1(BinTreeNode*t)
{
	if (t != NULL)
	{
		printf("%c ", t->data);
		PreOder_1(t->leftchild);
		PreOder_1(t->rightchild);
	}
}
void PreOrder(BinTree*bt)
{
	PreOder_1(bt->root);
}
//中序遍历
void InOder_1(BinTreeNode*t)
{
	if (t != NULL)
	{
		InOder_1(t->leftchild);
		printf("%c ", t->data);
		InOder_1(t->rightchild);
	}
}
void InOrder(BinTree*bt)
{
	InOder_1(bt->root);
}
//后序遍历
void PostOder_1(BinTreeNode*t)
{
	if (t != NULL)
	{
		PostOder_1(t->leftchild);
		PostOder_1(t->rightchild);
		printf("%c ", t->data);
	}
}
void PostOrder(BinTree*bt)
{
	PostOder_1(bt->root);
}
//层次遍历
void LevelOrder_1(BinTreeNode*t)
{
	if (t != NULL)
	{
		LinkQueue Q;
		LinkQueueInit(&Q);
		LinkQueueEnque(&Q, t);
		while (!(LinkQueueEmpty(&Q)))
		{
			BinTreeNode*p = LinkQueueFront(&Q);
			LinkQueueDeque(&Q);
			printf("%c ", p->data);
			if (p->leftchild != NULL)
				LinkQueueEnque(&Q, p->leftchild);
			if (p->rightchild != NULL)
				LinkQueueEnque(&Q, p->rightchild);
		}
	}
}
void LevelOrder(BinTree*bt)
{
	LevelOrder_1(bt->root);
}
//二叉树查找
BinTreeNode* BinTreeFind_1(BinTreeNode*t, ElemType key)
{
	BinTreeNode*p;
	if (t == NULL || t->data == key)
		return t;
	p = BinTreeFind_1(t->leftchild, key);
	if (p != NULL)
		return p;
	return BinTreeFind_1(t->rightchild, key);
}
BinTreeNode* BinTreeFind(BinTree*bt, ElemType key)
{
	return BinTreeFind_1(bt->root, key);
}
//寻找二叉树的父节点
BinTreeNode* BinTreeParant_1(BinTreeNode*t, ElemType key)
{
	BinTreeNode*p;
	if (t == NULL || t->data == key)
		return NULL;
	if ((t->leftchild != NULL&&t->leftchild->data == key)
		|| (t->rightchild != NULL&&t->rightchild->data == key))
		return t;
	p = BinTreeParant_1(t->leftchild, key);
	if (p != NULL)
		return p;
	return BinTreeParant_1(t->rightchild, key);
}
BinTreeNode* BinTreeParant(BinTree*bt, ElemType key)
{
	return  BinTreeParant_1(bt->root, key);
}
//拷贝二叉树
BinTreeNode* BinTreeCopy_1(BinTreeNode*t)
{
	if (t == NULL)
		return NULL;
	else
	{
		BinTreeNode*temp = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(temp != NULL);
		temp->data = t->data;
		temp->leftchild = BinTreeCopy_1(t->leftchild);
		temp->rightchild = BinTreeCopy_1(t->rightchild);
		return temp;
	}
}
void BinTreeCopy(BinTree*bt1, BinTree*bt2)
{
	bt2->root = BinTreeCopy_1(bt1->root);
}
//判断二叉树是否相等
bool BinTreeEqual_1(BinTreeNode*t1, BinTreeNode*t2)
{
	if (t1 == NULL || t2 == NULL)
		return true;
	if (t1 == NULL || t2 == NULL)
		return false;
	if (t1->data == t2->data
		&&BinTreeEqual_1(t1->leftchild, t2->leftchild)
		&& BinTreeEqual_1(t1->rightchild, t2->rightchild));
	return true;
}
bool BinTreeEqual(BinTree *bt1, BinTree *bt2)
{
	return BinTreeEqual_1(bt1->root, bt2->root);
}
//求二叉树的节点个数
int BinTreeCount(BinTree*bt)
{
	BinTreeCount_1(bt->root);
}
int BinTreeCount_1(BinTreeNode*t)
{
	if (t == NULL)
		return 0;
	return (BinTreeCount_1(t->leftchild) + BinTreeCount_1(t->rightchild) + 1);
}
//求二叉树的高度
int BinTreeHeight(BinTree*bt)
{
	BinTreeHeight_1(bt->root);
}
int BinTreeHeight_1(BinTreeNode*t)
{
	if (t == NULL)
		return 0;
	else
	{
		int left_h = BinTreeHeight_1(t->leftchild);
		int right_h = BinTreeHeight_1(t->rightchild);
		return (left_h > right_h ? left_h : right_h) + 1;
	}
}
//二叉树的摧毁
void BinTreeDestroy_1(BinTreeNode*t)
{
	if (t == NULL)
		return;
	else
	{
		BinTreeDestroy_1(t->leftchild);
		BinTreeDestroy_1(t->rightchild);
		free(t);
	}
	printf("摧毁二叉树成功.\n");
}
void  BinTreeDestroy(BinTree*bt)
{
	BinTreeDestroy_1(bt->root);
}
//////////////////////////////////////////
//二叉树的非递归遍历
void PreOrder_NoR();
void PreOrder_1_NoR();
void InOrder_NoR();
void InOrder_1_NoR();
void PostOrder_NoR();
void PostOrder_1_NoR();
///////////////////////////////////////////
void PreOrder_1_NoR(BinTreeNode*t)
{
	if (t != NULL)
	{
		LinkStack st;
		LinkStackInit(&st);
		LinkStackPush(&st, t);
		while (!LinkStackEmpty(&st))
		{
			BinTreeNode*Top = LinkStackTop(&st);
			LinkStackPop(&st);
			printf("%c ", Top->data);
			if (Top->rightchild != NULL)
				LinkStackPush(&st, Top->rightchild);
			if (Top->leftchild != NULL)
				LinkStackPush(&st, Top->leftchild);
		}
		printf("\n");
	}
}
void PreOrder_NoR(BinTree*bt)
{
	PreOrder_1_NoR(bt->root);
}
void InOrder_1_NoR(BinTreeNode*t)
{
	if (t != NULL)
	{
		BinTreeNode*top;
		LinkStack st;
		BinTreeNode*cur = t;
		assert(t != NULL);
		LinkStackInit(&st);
		while (cur || !LinkStackEmpty(&st))
		{
			while (cur)
			{
				LinkStackPush(&st, cur);
				cur = cur->leftchild;
			}
			top = LinkStackTop(&st);
			printf("%c ", top->data);
			LinkStackPop(&st);
			cur = top->rightchild;
		}
	}

}
void InOrder_NoR(BinTree*bt)
{
	InOrder_1_NoR(bt->root);
}
void PostOrder_1_NoR(BinTreeNode*t)
{
	BinTreeNode*prev=NULL;
	BinTreeNode*top;
	BinTreeNode*cur = t;
	LinkStack st;
	LinkStackInit(&st);
	if (t != NULL)
	{
		while (cur || !LinkStackEmpty(&st))
		{
			while (cur)
			{
				LinkStackPush(&st, cur);
				cur = cur->leftchild;
			}
			top = LinkStackTop(&st);
			if (top->rightchild == NULL || top->rightchild == prev)
			{
				printf("%c ", top->data);
				prev = top;
				LinkStackPop(&st);
			}
			else
			{
				cur = top->rightchild;
			}
		}
	}
}
void PostOrder_NoR(BinTree*bt)
{
	PostOrder_1_NoR(bt->root);
}
//二叉树的恢复
BinTreeNode* BinTreeCreateByVLR_LVR_1(const char *VLR, const char *LVR, int n)
{
	if (n == 0)
		return NULL;
	int k = 0;
	while (VLR[0] != LVR[k])
		k++;
	BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(t != NULL);
	t->data = LVR[k]; //VLR[0];

	t->leftchild = BinTreeCreateByVLR_LVR_1(VLR + 1, LVR, k);
	t->rightchild = BinTreeCreateByVLR_LVR_1(VLR + k + 1, LVR + k + 1, n - k - 1);
	return t;
}
void BinTreeCreateByVLR_LVR(BinTree *bt, const char *VLR, const char *LVR)
{
	int n = strlen(VLR);
	bt->root = BinTreeCreateByVLR_LVR_1(VLR, LVR, n);
}

void BinTreeCreateByLRV_LVR(BinTree *bt, const char *VLR, const char *LVR);
BinTreeNode* BinTreeCreateByLRV_LVR_1(const char *VLR, const char *LVR, int n);
///////////////////////////////////////////
//顺序二叉树
typedef struct SeqBinTree
{
	char *data;
	int  capacity;
	int size;
}SeqBinTree;
void SeqBinTreeInit(SeqBinTree*psq)
{
	psq->data = (char*)malloc(sizeof(char)* 100);
	psq->capacity = 100;
	psq->size = 0;
}
void BinTreeInsert(SeqBinTree*psq, char ar[], int n)
{
	for (int i = 0; i < n; ++i)
		psq->data[psq->size++] = ar[i];
}
void SeqBinTreePrint(SeqBinTree*psq)
{
	for (int i = 0; i < psq->size; i++)
		printf("%c ", psq->data[i]);
	printf("\n");
}
#endif