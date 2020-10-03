#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<malloc.h>
#include<stdbool.h>
#include<memory.h>
#include<assert.h>
#define CIR_QUEUE_CAPACITY 50
/////////////////////////////////////////////81ҳջ�Ͷ���///////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//1.��ϣ��ѭ�������е�Ԫ�ض��ܵõ����ã�����Ҫ����һ����־��tag,����tag��ֵΪ0����1�����ֶ�ͷָ��front�Ͷ�βָ��rear��ͬʱ�Ķ��е�
//״̬�������ǿգ����ű�д�˽ṹ��Ӧ����Ӻͳ����㷨.
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
		printf("��������\n");
		return;
	}
	else
	{
		psq->data[psq->rear] = x;
		psq->rear = (psq->rear + 1) % psq->capacity;
		psq->tag = 1;    //��һ��ŵ�����ȽϷ����߼������֮����Ŵ��ϣ�����ı�����������ٽ����жϣ���ָ����ͬλ��ʱ��
		                 //�Ͳ����������
	}
}
void DeCirQueue(CirQueue*psq)
{
	assert(psq != NULL);
	if (psq->front == psq->rear&&psq->tag==0)       //�����ùؿ�λ
	{
		printf("�����ѿ�\n");
		return;
	}

		else{
		psq->front = (psq->front + 1) % psq->capacity;
		psq->tag = 0;      //��ֹ�Ǹ�������еĳ�Ա�����ĳ��ӡ�
	}
}
void  Cir_Queue_Show(CirQueue*psq)
{
	assert(psq != NULL);
	if (psq->front == psq->rear&&psq->tag == 0) //��ʱ���в���Ϊ�գ�ֻ�Ƕ����������ڵ�һ�δ�ӡ֮�󽫱�־λ��Ϊ��0��
	{
		printf("����Ϊ��\n");
		return;
	}
	else
	{
		int i = psq->front;
		while (i != psq->rear||psq->tag==1) //�����Ĵ�ӡ�����ͻ�ʹ������Ԫ���ֳ�����
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
		printf("��������\n");
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
		printf("�����ѿ�\n");
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
		printf("ջ����\n");
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
		printf("ջ�ѿ�\n");
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
		printf("ջΪ�գ����ܳ�ջ\n");
		return;
	}
	//x = (char*)malloc(sizeof(char));
	*x = pst->data[pst->top - 1];
	pst->top--;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//2.Q��һ�����У�S��һ����ջ��ʵ�ֶ����е�Ԫ��ȫ���á�
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

//3.��������ջs1��s2��ģ��һ�����У���֪ջ��4�����㶨�����£�
//             push(S,x);               Ԫ��x��ջs
//             Pop(S,x);                S��ջ������Ӧ��ֵ����x
//             StackEmpty(s);           �ж�ջ�Ƿ�Ϊ��
//             StackOverflow(S);        �ж�ջ�Ƿ���
////////////////////////////////////////////////////////////////////////////////
//�������ջ��������ʵ�ָ����е�3�����㡣
//             Enqueue;                 ��Ԫ��x���
//             Dequeue;                 ���ӣ�������Ԫ��ֵ�洢��x��
//             QueueEmpty;              �ж϶����Ƿ�Ϊ��
 
void Enqueue()
{

}

void Dequeue()
{

}

void QueueEmpty()
{

}
////////////////////////////////////////////90ҳ�㷨��//////////////////////////////////////////////////////////
//1.����һ���㷨���ʽ�а���Բ���ţ������ţ������ţ��������������ţ���д�㷨���жϱ��ʽ�е������Ƿ���ԣ����ַ�
// "\0"��Ϊ�������ʽ�Ľ�����  �ҵ���ѽ������д���ˡ�ȱ���������������˳��ȷ����
//������㷨����д�д��ڴ�ֵ�봫��ַ������

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
		printf("����ƥ��\n");
		return true;
	}
	else
	{
		printf("���Ų�ƥ��\n");
		return false;
	}
}

//2.
//3.����һ��ջʵ�����µݹ麯���ķǵݹ�ʵ��
#define Maxise 100
int  function(int n,int x)
{
	struct Stack
	{
		int n;
		int val;
	}Stack[Maxise];
	int top = -1; //���ǿ��ٵĽṹ�������ָ�룬����ջ��ջ��ָ��,�����ջ�����Ƕ��˸�top�Ľṹ������
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
//4.ĳ�����ֶɿڣ������ɴ�ÿ������ʮ��������,����������Ϊ�ͳ���ͻ����࣬�϶ɴ������¹涨:ͬ�೵�ȵ����ϴ���
//�ͳ����ڻ����ϴ�,��ÿ�������ʹ������������һ�����������ȴ��ͳ�����4�������Ի������棻���޻����ȴ�������
//�ͳ����ϴ����������һ���㷨ģ��ɿڹ���
/*
void main()
{
	int n, x;
	printf("������n=\n");
	scanf_s("%d", &n);
	printf("������x=\n");
	scanf_s("%d", &x);
	int value=function(n, x);
	printf("����������Ϊ%d\n", value);
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