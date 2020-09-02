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
	BinTreeCreatByStr(&T, str);//给入字符串创建二叉树
	//BinTreeCreat(&T);//手动输入创建二叉树
	printf("非递归前序遍历————————————\n");
	PreOrder_NoR(&T);
	printf("非递归中序遍历————————————\n");
	InOrder_NoR(&T);
	printf("\n");
	printf("非递归后序遍历————————————\n");
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
	BinTreeCreatByStr(&T, str);//给入字符串创建二叉树
	BinTreeCreat(&T);//手动输入创建二叉树
	PreOrder(&T);
	printf("\n");
	InOrder(&T);
	printf("\n");
	PostOrder(&T);
	printf("\n");
	LevelOrder(&T);
	printf("\n");
	printf("二叉树的高度height=%d \n", BinTreeHeight(&T));
	printf("二叉树的节点数count=%d \n", BinTreeCount(&T));
	BinTreeNode*t = BinTreeFind(&T, key);
	if (t == NULL)
		printf("您所要查找的节点不在这棵树上.\n");
	printf("你所要查找的节点data=%c\n", t->data);
	BinTreeNode*p = BinTreeParant(&T, key);
	if (p == NULL)
		printf("您所要查找的节点的父节点不不存在.\n");
	else
		printf("父节点data=%c\n", p->data);
	BinTreeCopy(&T, &T1);
	printf("遍历T1.---------------------------------\n");
	PreOrder(&T1);
	printf("\n");
	InOrder(&T1);
	printf("\n");
	PostOrder(&T1);
	printf("\n");
	LevelOrder(&T1);
	printf("\n");
	printf("二叉树的高度height=%d \n", BinTreeHeight(&T1));
	printf("二叉树的节点数count=%d \n", BinTreeCount(&T1));
	printf("------------------------\n");
	BinTreeEqual(&T, &T1);
	if (BinTreeEqual(&T, &T1) == true)
		printf("Equal.\n");
	BinTreeDestroy(&T);
	system("pause");

}
*/


