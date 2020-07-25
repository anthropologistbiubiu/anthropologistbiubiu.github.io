#include"list.h"
int main()
{
	int select = 1;
	ElemType item, key, pos;
	DCListNode*p;
	DCList mylist;
	DCListInit(&mylist);
	while (select)
	{
		printf("***********************************\n");
		printf("*[1]push_back         [2]push_front\n");
		printf("*[3]show_list        [0]quit_system\n");
		printf("*[4]pop_back          [5]pop_front \n");
		printf("*[6]ValInsert        [7]DeleteByVal\n");
		printf("*[8]SListFind        [9]SListLength\n");
		printf("*[10]SListSort     [11]SListReverse\n");
		printf("*[12]SListClear    [13]SListDestroy\n");
		printf("***********************************\n");
		printf("请选择：");
		scanf_s("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入要插入的值[以-1结束]\n");
			while (scanf_s("%d", &item), item != -1)
			{
				DCListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("请输入要插入的值[以-1结束]\n");
			while (scanf_s("%d", &item), item != -1)
			{
				DCListPushFront(&mylist, item);
			}
			break;
		case 3:
			DCListShow(&mylist);
			break;
		case 4:
			DCListPopBack(&mylist);
			break;
		case 5:
			DCListPopFront(&mylist);
			break;
		case 6:
			//SListSort(&mylist);
			printf("请输入要插入的值->\n");
			scanf_s("%d", &item);
			DCListByValInsert(&mylist, item);
			break;
		case 7:
			printf("请输入要删除的值->\n");
			scanf_s("%d", &key);
			DCListDeleteByVal(&mylist, key);
			break;
		case 8:
			printf("请输入要查找的值\n");
			scanf_s("%d", &key);
		    p=DCListFind(&mylist, key);
			if (p !=mylist.head)
			{
				printf("您所查找的值为%d\n", p->data);
			}
			else
				printf("您所查找的值不在\n");
			//if (p == NULL)
			//	printf("您查找的值不存在\n");
			//else
			//	printf("你所要查找的值为：%d\n", p->data);
			break;
		case 9:
			printf("DCList len=%d\n", DCListLength(&mylist));
			break;
		case 10:
			DCListSort(&mylist);
			break;
		case 11:
			DCListReverse(&mylist);
			break;
		case 12:
			DCListClear(&mylist);
			printf("清除数据表成功\n");
			break;
		case 13:
			DCListDestroy(&mylist);
			printf("摧毁数据成功\n");
			break;
		}
	}
	printf("GoodBye........\n");
	return 0;
}