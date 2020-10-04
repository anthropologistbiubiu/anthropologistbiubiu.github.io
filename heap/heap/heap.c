#include"common.h"
#include"heap.h"
void main()
{
	int ar[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int n = sizeof(ar) / sizeof(ar[0]);
	heap minheap;
	HeapInit(&minheap, n);
	for (int i = 0; i < n; i++)
		MinHeapInsert(&minheap, ar[i]);
	HeapPrintf(&minheap);
	printf("\n");
	while (!HeapEmpty(&minheap))
	{
		printf("%d ", MinHeapRemove(&minheap));
	}
	printf("\n");
	HeapSort(&minheap, ar, n);
	printf("\n");
	HeapPrint(&minheap);
	system("pause");
}