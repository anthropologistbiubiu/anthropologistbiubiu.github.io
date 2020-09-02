#include"common.h"
#include"tree.h"
/*
void main()
{
	SeqBinTree sbt;
	SeqBinTreeInit(&sbt);
	char ar[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	int n = sizeof(ar) / sizeof(ar[0]);
	BinTreeInsert(&sbt, ar, n);
	SeqBinTreePrint(&sbt);
	system("pause");
}

void main()
{
	char key = 'E';
	BinTree T, T1;
	const char*str = "ABC##DE##F##G#H##";
	BinTreeInit(&T);
	//BinTreeInit(&T1);
	BinTreeCreatByStr(&T, str);//�����ַ�������������
	//BinTreeCreat(&T);//�ֶ����봴��������
	printf("�ǵݹ�ǰ�����������������������������\n");
	PreOrder_NoR(&T);
	printf("�ǵݹ��������������������������������\n");
	InOrder_NoR(&T);
	printf("\n");
	printf("�ǵݹ�������������������������������\n");
	PostOrder_NoR(&T);
	printf("\n");
	system("pause");
}
*/
void main()
{
	BinTree bt;
	BinTreeInit(&bt);
	BinTreeCreat(&bt);
	system("pause");
}
/*
void main()
{
	char key = 'E';
	BinTree T, T1;
	const char*str = "ABC##DE##F##G#H##";
	BinTreeInit(&T);
	BinTreeInit(&T1);
	BinTreeCreatByStr(&T, str);//�����ַ�������������
	BinTreeCreat(&T);//�ֶ����봴��������
	PreOrder(&T);
	printf("\n");
	InOrder(&T);
	printf("\n");
	PostOrder(&T);
	printf("\n");
	LevelOrder(&T);
	printf("\n");
	printf("�������ĸ߶�height=%d \n", BinTreeHeight(&T));
	printf("�������Ľڵ���count=%d \n", BinTreeCount(&T));
	BinTreeNode*t = BinTreeFind(&T, key);
	if (t == NULL)
		printf("����Ҫ���ҵĽڵ㲻���������.\n");
	printf("����Ҫ���ҵĽڵ�data=%c\n", t->data);
	BinTreeNode*p = BinTreeParant(&T, key);
	if (p == NULL)
		printf("����Ҫ���ҵĽڵ�ĸ��ڵ㲻������.\n");
	else
		printf("���ڵ�data=%c\n", p->data);
	BinTreeCopy(&T, &T1);
	printf("����T1.---------------------------------\n");
	PreOrder(&T1);
	printf("\n");
	InOrder(&T1);
	printf("\n");
	PostOrder(&T1);
	printf("\n");
	LevelOrder(&T1);
	printf("\n");
	printf("�������ĸ߶�height=%d \n", BinTreeHeight(&T1));
	printf("�������Ľڵ���count=%d \n", BinTreeCount(&T1));
	printf("------------------------\n");
	BinTreeEqual(&T, &T1);
	if (BinTreeEqual(&T, &T1) == true)
		printf("Equal.\n");
	BinTreeDestroy(&T);
	system("pause");

}
*/


