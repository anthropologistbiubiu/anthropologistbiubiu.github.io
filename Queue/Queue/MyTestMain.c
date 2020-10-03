#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<malloc.h>
#include<stdbool.h>
#include<memory.h>
#include<assert.h>
#define CIR_QUEUE_CAPACITY 50
/////////////////////////////////////////////81页栈和队列///////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//1.若希望循环队列中的元素都能得到利用，则需要设置一个标志域tag,并以tag的值为0或者1来区分队头指针front和队尾指针rear相同时的队列的
//状态是满还是空，试着编写此结构响应的入队和出队算法.
typedef struct CirQueue
{
	int* data;
	int capacity;
	int front;
	int rear;
	int tag;
}CirQueue;
void CirQueueInit(CirQueue*psq)
{
	assert(psq != NULL);
	psq->data = (int*)malloc(sizeof(int)*CIR_QUEUE_CAPACITY);
	psq->capacity = CIR_QUEUE_CAPACITY;
	psq->front = psq->rear = 0;
	psq->tag = 0;
}
void EnCirQueuePush(CirQueue*psq, int x)
{
	assert(psq != NULL);
	if (psq->rear == psq->front&&psq->tag == 1)
	{
		printf("队列已满\n");
		return;
	}
	else
	{
		psq->data[psq->rear] = x;
		psq->rear = (psq->rear + 1) % psq->capacity;
		psq->tag = 1;    //这一句放到后面比较符合逻辑，入队之后把门带上，后面的必须是先入队再进行判断，当指针相同位置时候，
		                 //就不能再入队了
	}
}
void DeCirQueue(CirQueue*psq)
{
	assert(psq != NULL);
	if (psq->front == psq->rear&&psq->tag==0)       //先设置关卡位
	{
		printf("队列已空\n");
		return;
	}

		else{
		psq->front = (psq->front + 1) % psq->capacity;
		psq->tag = 0;      //防止是刚入完队列的成员反复的出队。
	}
}
void  Cir_Queue_Show(CirQueue*psq)
{
	assert(psq != NULL);
	if (psq->front == psq->rear&&psq->tag == 0) //此时队列并不为空，只是队列满，且在第一次打印之后将标志位置为了0。
	{
		printf("队列为空\n");
		return;
	}
	else
	{
		int i = psq->front;
		while (i != psq->rear||psq->tag==1) //这样的打印条件就会使得所有元素又出队了
		{
			printf("%d->", psq->data[i]);
			i = (i + 1) % psq->capacity;
			psq->tag = 0;
		}
		printf("over\n");
	}
}
//******************************************************************************************************************************//

typedef struct _SeqQueue
{
	int* data;
	int capacity;
	int rear;
	int front;
}_SeqQueue;
void _SeqQueueInit(_SeqQueue*pst)
{
	assert(pst != NULL);
	pst->data = (int*)malloc(sizeof(int)*CIR_QUEUE_CAPACITY);
	pst->capacity = CIR_QUEUE_CAPACITY;
	pst->front = pst->rear = 0;
}
void _SeqQueuePush(_SeqQueue*psq,int x)
{
	if (psq->rear>=psq->capacity)
	{
		printf("队列已满\n");
		return;
	}
	else
	{
		psq->data[psq->rear] = x;
		psq->rear++;
	}
}
int _SeqQueuePop_Top(_SeqQueue*psq)
{
	if (psq->front == psq->rear)
	{
		printf("队列已空\n");
		return;
	}
	else
	{
		return psq->data[psq->front];
		
	}
}
void _SeqQueuePrint(_SeqQueue*pst)
{
	assert(pst != NULL);
	if (pst->front == pst->rear)
	{
		return;
	}
	else
	{
		int i = pst->front;
		while (i != pst->rear)
		{
			printf("%d->", pst->data[i]);
			i++;
		}
	}
	printf("over\n");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct SeqStack
{
	char* data;
	int capacity;
	int top;
}SeqStack;
void SeqStackInit(SeqStack*psq)
{
	assert(psq != NULL);
	psq->data = (char*)malloc(sizeof(char)*CIR_QUEUE_CAPACITY);
	psq->capacity = CIR_QUEUE_CAPACITY;
	psq->top = 0;
}
void SeqStackPush(SeqStack*pst,char x)
{
	assert(pst != NULL);
	if (pst->top >= pst->capacity)
	{
		printf("栈已满\n");
		return;
	}
	else
	{
		pst->data[pst->top] = x;
		pst->top++;
	}
}
int  SeqStackPop_Top(SeqStack*pst)
{
	assert(pst != NULL);
	if (pst->top == 0)
	{
		printf("栈已空\n");
		return;
	}
	else
	{
  		return pst->data[pst->top - 1];
	}
}
void SeqStackPop(SeqStack*pst,char* x)
{
	assert(pst != NULL);
	if (pst->top==0)
	{
		printf("栈为空，不能出栈\n");
		return;
	}
	//x = (char*)malloc(sizeof(char));
	*x = pst->data[pst->top - 1];
	pst->top--;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//2.Q是一个队列，S是一个空栈，实现队列中的元素全逆置。
void Revers(_SeqQueue*psq)
{
	assert(psq != NULL);
	SeqStack s;
	SeqStackInit(&s);
	int x;
	while (psq->front!=psq->rear)
	{
		x = _SeqQueuePop_Top(psq);
		SeqStackPush(&s, x);
		psq->front++;
	}
	psq->front = psq->rear=0;
	while ((&s)->top!=0)
	{
		int x = SeqStackPop_Top(&s);
		_SeqQueuePush(psq, x);
		(&s)->top--;
	}
}

//3.利用两个栈s1，s2来模拟一个队列，已知栈的4个运算定义如下：
//             push(S,x);               元素x入栈s
//             Pop(S,x);                S出栈并将相应的值赋给x
//             StackEmpty(s);           判断栈是否为空
//             StackOverflow(S);        判断栈是否满
////////////////////////////////////////////////////////////////////////////////
//如何利用栈的运算来实现给队列的3个运算。
//             Enqueue;                 将元素x入队
//             Dequeue;                 出队，并将队元素值存储在x中
//             QueueEmpty;              判断队列是否为空
 
void Enqueue()
{

}

void Dequeue()
{

}

void QueueEmpty()
{

}
////////////////////////////////////////////90页算法题//////////////////////////////////////////////////////////
//1.假设一个算法表达式中包括圆括号，方括号，花括号，和括号三类括号，编写算法来判断表达式中的括号是否配对，以字符
// "\0"作为算数表达式的结束符  我的妈呀，终于写好了。缺点在于括号输入的顺序确定。
//在这个算法的书写中存在传值与传地址的问题

bool Bracket_Match(char* str)
{
	char* ch=(char*)malloc(sizeof(char));
	SeqStack bt;
	SeqStackInit(&bt);
	while (*str != '\0')
	{
		switch (*str)
		{
		case '(':
			SeqStackPush(&bt, *str);
			break;
		case '[':
			SeqStackPush(&bt, *str);
			break;
		case '{':
			SeqStackPush(&bt, *str);
			break;
		case ')':
			 SeqStackPop(&bt,ch);
			if (*ch != '(')
				return false;
			break;
		case ']':
			SeqStackPop(&bt, ch);
			if (*ch != '[')
				return false;
			break;
		case '}':
			SeqStackPop(&bt, ch);
			if (*ch != '{')
				return false;
			break;
		default:
			break;
		}
		str++;
	}
	if ((&bt)->top==0)
	{
		printf("括号匹配\n");
		return true;
	}
	else
	{
		printf("括号不匹配\n");
		return false;
	}
}

//2.
//3.利用一个栈实现以下递归函数的非递归实现
#define Maxise 100
int  function(int n,int x)
{
	struct Stack
	{
		int n;
		int val;
	}Stack[Maxise];
	int top = -1; //就是开辟的结构体数组的指针，就是栈的栈顶指针,这就是栈。就是多了个top的结构体数组
	int fv2 = 2 * x;
	int fv1 = 1;
	for (int k = n; k >= 2; k--)
	{
		top++;
		Stack[top].n = k;
	}
	while (top != -1)
	{
		Stack[top].val= 2 * x*fv2 - 2 * (Stack[top].n - 1)*fv1;
		fv2 = Stack[top].val;
		fv1 = fv2;
		top--;
	}
	if (n == 0)
		return 0;
	else if (n == 1)
		return 2 * x;
	else if (n > 1)
		return Stack[0].val;
}
//4.某汽车轮渡口，过江渡船每次能载十辆车过江,过江车辆分为客车类和货车类，上渡船有以下规定:同类车先到先上船；
//客车先于货车上船,且每上四辆客船，才允许放上一辆货船；若等待客车不足4辆，就以货车代替；若无货车等待，允许
//客车都上船，试着设计一个算法模拟渡口管理。
/*
void main()
{
	int n, x;
	printf("请输入n=\n");
	scanf_s("%d", &n);
	printf("请输入x=\n");
	scanf_s("%d", &x);
	int value=function(n, x);
	printf("函数计算结果为%d\n", value);
	system("pause");
}

void main()
{
	char ar[] ="(a+b)";
	Bracket_Match(ar);
	system("pause");
}

void main()
{
	int item;
	_SeqQueue bt;
	_SeqQueueInit(&bt);
	while (scanf_s("%d", &item), item != -1)
	{
		_SeqQueuePush(&bt, item);
	}
	_SeqQueuePrint(&bt);

	Revers(&bt);
	_SeqQueuePrint(&bt);
	system("pause");
}

void main()
{
	int item;
	CirQueue bt;
	CirQueueInit(&bt);
	while (scanf_s("%d", &item), item != -1)
	{
		EnCirQueuePush(&bt,item);
	}

	DeCirQueue(&bt);
	DeCirQueue(&bt);
	DeCirQueue(&bt);

	while (scanf_s("%d", &item), item != -1)
	{
		EnCirQueuePush(&bt, item);
	}
	Cir_Queue_Show(&bt);
	Cir_Queue_Show(&bt);
	system("pause");
}
*/