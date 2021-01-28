#include<iostream>
#include<vld.h>
using namespace std;

template<class Type>
class BST;     //如何声明为友元类


template<class Type>
class BSTNode
{
	friend  class BST<Type>;
public:
	BSTNode(Type d, BSTNode<Type>*left = nullptr, BSTNode<Type>*right = nullptr)
		:data(d), leftchild(left), rightchild(right)
	{}
private:
	Type data;
	BSTNode<Type>* leftchild;
	BSTNode<Type>* rightchild;
};

template<class Type>
class BST
{
public:
	BST() :root(nullptr)
	{}
	BST(Type ar[], int n) :root(nullptr)
	{
		for (int i = 0; i < n; i++)
		{
			Insert(ar[i]);
		}
	}
public:
	bool Insert(const Type& x)
	{
		return Insert(root, x);
	}
	//中序遍历
	void Sort()
	{
		Sort(root);
	}
	//求二插搜索树的最值
	Type Min()
	{
		return Min(root);
	}
	Type Max()
	{
		return Max(root);
	}
	void MakeEmpty()
	{
		MakeEmpty(root);
	}
	BSTNode<Type>* Search(const Type& key)
	{
		return  Search(root, key);
	}
	void Remove(const Type& key)
	{
		Remove(root, key);
	}
protected:
	bool Insert(BSTNode<Type>*& t, const Type &x)
	{
		if (t == nullptr)
		{
			t = new BSTNode<Type>(x);
			return true;
		}
		else if (x < t->data)
		{
			Insert(t->leftchild, x);
		}
		else if (x>t->data)
		{
			Insert(t->rightchild, x);
		}
		else
		{
			return false;
		}
	}
	void Sort(BSTNode<Type>*& t)
	{
		if (t != nullptr)
		{
			Sort(t->leftchild);
			cout << t->data << " ";
			Sort(t->rightchild);
		}
	}
	Type& Min(BSTNode<Type>*pt)
	{
		while(pt->leftchild!= nullptr)
		{
			pt = pt->leftchild;
		}
		return pt->data;
	}
	Type& Max(BSTNode<Type>* pt)
	{
		while (pt->rightchild != bullptr)
		{
			pt = pt->rightchild;
		}
		return pt->data;
	}
	void MakeEmpty(BSTNode<Type>*& t)
	{
		if (t != nullptr)
		{
			MakeEmpty(t->leftchild);
			MakeEmpty(t->rightchild);
			delete t;
		}
	}
	BSTNode<Type>* Search(BSTNode<Type>* bt,const Type& key)
	{
		if (bt == nullptr)
			return nullptr;
		if (bt->data == key)
			return bt;
		else if (bt->data > key)
			Search(bt->leftchild,key);
		else
			Search(bt->rightchild,key);
	}
	void Remove(BSTNode<Type>*& bt, const Type& key)
	{
		if (bt != nullptr)
		{
			if (bt->data > key)
				Remove(bt->leftchild, key);
			else if (bt->data < key)
				Remove(bt->rightchild, key);
			else
			{
				BSTNode<Type>* pt = nullptr;
				if (bt->leftchild == nullptr&&bt->rightchild == nullptr)
				{
					delete bt;
					bt = nullptr;
				}
				else if (bt->leftchild != nullptr&&pt->rightchild == nullptr)
				{
					pt = bt;
					bt = pt->leftchild;
					delete pt;
				}
				else if (bt->rightchild != nullptr&&bt->leftchild == nullptr)
				{
					pt = bt;
					bt = pt->rightchild;
					delete pt;
				}
				else if (bt->leftchild&&bt->rightchild)
				{
					pt = bt->leftchild;
					while (pt->rightchild)
					{
						pt = pt->rightchild;
					}
					bt->data = pt->data;
					Remove(bt->leftchild, pt->data);
				}
			}
		}
		
	}
private:
	BSTNode<Type>* root;
};

int main()
{
	int arr[] = { 53, 78, 65, 17, 87, 9, 81, 45, 23 ,100,0};
	int n = sizeof(arr) / sizeof(arr[0]);
	BST<int> bst(arr,n);
	bst.Sort();
	cout<<"Min="<<bst.Min()<<endl;  //这里都没有接收值，是怎么直接得出的
	bst.Remove(65);
	bst.Sort();
	system("pause");
}
/*
int main()
{
	int arr[] = { 53,78,65,17,87,9,81,45,23};
	int n = sizeof(arr) /sizeof(arr[0]);
	BST<int> bst;
	for (int i = 0; i < n; i++)
	{
		bst.Insert(arr[i]);
	}
	bst.Sort();
	cout << endl;
	return 0;
	system("pause");
}
*/