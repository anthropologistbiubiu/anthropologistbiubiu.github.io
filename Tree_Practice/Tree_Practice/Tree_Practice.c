#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>

#define ElemType char
//������������
typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode* leftchild;
	struct BinTreeNode* rightchild;
}BinTreeNode;
//������������ʼ��
typedef struct ListTree
{
	BinTreeNode* root;
}ListTree;
void ListTreeInit(ListTree* plist)
{
	plist->root = NULL;
}
//������ջ���
typedef struct LinkStackNode
{
	BinTreeNode* data;
	struct LinkStackNode* link;
}LinkStackNode;
//������ջ
typedef struct LinkStack
{
	LinkStackNode*top;
}LinkStack;

//������ջ�ĸ���ӿ�
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
BinTreeNode* LinkStackTop(LinkStack*pst,BinTreeNode**plist)
{
	assert(pst->top != NULL);
	(*plist) = pst->top->data;
}
bool LinkStackEmpty(LinkStack*pst)
{
	return pst->top == NULL;
}
void visit(BinTreeNode*bt)
{
	printf("%c ", bt->data);
}

void postorder(BinTreeNode*plist)
{
	if (plist != NULL)
	{
		printf("%c ", plist->data);
		postorder(plist->leftchild);
		postorder(plist->rightchild);
	}
	return 0;
}


//126.��д��������������ķǵݹ��㷨
My_postorder(ListTree*bt)
{
	postorder(bt->root);
}

void My_PostOrder(BinTreeNode*bt)
{
	BinTreeNode*pre;
	BinTreeNode*top;
	BinTreeNode*cur = bt;
	LinkStack st;
	LinkStackInit(&st);
	while (cur || LinkStackEmpty(&st))
	{
		while (cur)
		{
			LinkStackPush(&st, cur);

		}
	}
}
void PostOrder(ListTree* plist)
{
	LinkStack t;
	LinkStackInit(&t);
	BinTreeNode*p = plist->root;
	BinTreeNode*r = NULL;
	while (p || !LinkStackEmpty(&t))
	{
		if (p)
		{
			LinkStackPush(&t, p);
			p = p->leftchild;
		}
		else
		{
			LinkStackTop(&t, p);
		}
		if (p->rightchild&&p->rightchild != r)
		{
			p = p->rightchild;
			LinkStackPush(&t, p);
			p = p->leftchild;
		}
		else
		{
			LinkStackPop(&t, p);
			visit(p->data);
			r = p;
			p = NULL;
		}
	}
}
 BinTreeNode* BinTreeNodeCreate()
{
	ElemType item;
	BinTreeNode* bt = NULL;
	scanf("%c", &item);
	if (item == '#')
		return NULL;     //���return NULL  ��ĺ���Ҫ
	bt = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	bt->data = item;
	bt->leftchild = BinTreeNodeCreate();
	bt->rightchild = BinTreeNodeCreate();
	return bt;
}
 void My_BinTreeNodeCreate(ListTree* bt)
 {
	 bt->root = BinTreeNodeCreate();
 }

 //���Ÿ��������������¶��ϣ����ҵ���Ĳ�α����㷨
 //��α�����Ҫ��סһ������
 //������ʽ���нڵ�
 typedef struct LinkQueueNode
 {
	 BinTreeNode* data;
	 struct LinkQueueNode*Link;
 }LinkQueueNode;
 //������ʽ����
 typedef struct LinkQueue
 {
	 LinkQueueNode*front;
	 LinkQueueNode*rear;
 }LinkQueue;
 //��ʼ������ʽ����
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

 void LeverOrder(ListTree*pq)
 {
	 assert(pq != NULL);
	 if (pq->root != NULL)
	 {
		 LinkQueue Q;
		 LinkQueueInit(&Q);
		 LinkQueueEnque(&Q, pq->root);
		 while (!(LinkQueueEmpty(&Q)))
		 {
			 BinTreeNode*temp = LinkQueueFront(&Q);
			 LinkQueueDeque(&Q);
			 printf("%c ", temp->data);
			 if (temp->leftchild != NULL)
				 LinkQueueEnque(&Q, temp->leftchild);
			 if (temp->rightchild != NULL)
				 LinkQueueEnque(&Q, temp->rightchild);
		 }
	 }
	 printf("\n");
 }
 void  My_LeverOrder(ListTree*pq) //���������ҵ��󣬴��µ��ϵĲ�α���
 {
	 assert(pq != NULL);
	 LinkStack S;
	 LinkStackInit(&S);
	 if (pq->root != NULL)
	 {
		 LinkQueue Q;
		 LinkQueueInit(&Q);
		 LinkQueueEnque(&Q, pq->root);
		 while (!LinkQueueEmpty(&Q))
		 {
			 BinTreeNode*t = LinkQueueFront(&Q);
			 LinkStackPush(&S, t);
			 LinkQueueDeque(&Q);
			 if (t->leftchild != NULL)
				 LinkQueueEnque(&Q, t->leftchild);
			 if (t->rightchild != NULL)
				 LinkQueueEnque(&Q, t->rightchild);
		 }
	 }
	 while (!LinkStackEmpty(&S))      //���ﴫ����һ������ָ�룬��ע�⡣
	 {
		  BinTreeNode*temp = NULL;
		  LinkStackTop(&S,&temp);
		  LinkStackPop(&S);
		  printf("%c ", temp->data);
	 }
	 printf("\n");
 }

//������������ö�������洢�ṹ�����һ���ǵݹ���㷨��������ĸ߶ȡ�
 int  TreeHeight(BinTreeNode*pt)
 {
	 if (pt == NULL)
	 {
		 return 0;
	 }
	 else
	 {
		 int left_h = TreeHeight(pt->leftchild);
		 int right_h = TreeHeight(pt->rightchild);
		 return (left_h > right_h ? left_h : right_h) + 1;        
	 }

 }
 //�ѵݹ��㷨��Ҫ����һ������
 int My_TreeHeight(BinTreeNode*bt)
 {
	 int lever = 0;
	 int last = 0;
	 int front = -1;
	 int rear = -1;
	 BinTreeNode* Q[10];
	 Q[++rear] = bt;
	 while (front < rear)
	 {
		 BinTreeNode*temp = Q[++front];
		 if (temp->leftchild)
			 Q[++rear] = temp->leftchild;
		 if (temp->rightchild)
			 Q[++rear] = temp->rightchild;
		 if (front == last)
		 {
			 lever++;
			 last = rear;
		 }
	 }
	 return lever;
 }
 //��һ�Ŷ������и��ڵ��ֵ��ͬ�����������������������ֱ����һά����A��B���Ա�д
 //�㷨���ö������Ķ�������




 //������������������ʽ�洢����дһ���㷨�ж������������Ƿ�����ȫ������
 bool Completebinarytree(BinTreeNode*bt)
 {
	 LinkQueue Q;
	 LinkQueueInit(&Q);
	 if (bt)
	 {
		 LinkQueueEnque(&Q, bt);
		 while (!(LinkQueueEmpty(&Q)))
		 {
			 BinTreeNode*pt;
			 pt = LinkQueueFront(&Q);
			 LinkQueueDeque(&Q);
			 if (pt)
			 {
				 LinkQueueEnque(&Q,pt->leftchild);
				 LinkQueueEnque(&Q,pt->rightchild);
			 }
			 else
			 {
				 while (!LinkQueueEmpty(&Q))
				 {
					 if (pt)
					 {
						 return false;
					 }
					 pt = LinkQueueFront(&Q);
					 LinkQueueDeque(&Q, pt);
				 }
			 }
		 }
	 }
	 return true;
 }


 //����B��һ�Ų�����ʽ�洢�ṹ�Ķ���������дһ���㷨���Խ����������нڵ�������������н���
 void main()
 {
	 ListTree T;
	 ListTreeInit(&T);
	 My_BinTreeNodeCreate(&T);
	 LeverOrder(&T);
	 My_LeverOrder(&T);        //�������������̫���ˣ���һ�α����ҷ�����ߴ�������������
	 int height=TreeHeight((&T)->root);
	 printf("heght=%d\n", height);
	 height = My_TreeHeight((&T)->root);
	 printf("height=%d\n", height);
	 bool flag = Completebinarytree((&T)->root);
	 if (flag)
		 printf("��ȫ������\n");
	 else
		 printf("����ȫ������\n");
	 system("pause");
 }













