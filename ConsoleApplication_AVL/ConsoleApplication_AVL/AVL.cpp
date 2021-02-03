#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<stack>
using namespace std;

template<class Type>
class AVLTree;

template<class Type>
class AVLNode
{
	friend class AVLTree<Type>;
public:
	AVLNode(Type d, AVLNode<Type>*left = nullptr, AVLNode<Type>*right=nullptr)
		:data(d), leftchild(left), rightchild(right), bf(0)
	{}
	~AVLNode()
	{}
private :
	Type data;
	AVLNode<Type>* leftchild;
	AVLNode<Type>* rightchild;
	int  bf;
};

template<class Type>
class AVLTree
{
public:
	AVLTree() :root(nullptr)
	{}
public:
	bool  Insert(const Type& key)
	{
		return Insert(root, key);
	}
	void AVLTreePrint()
	{
		AVLTreePrint(root);
	}
protected:
	bool Insert(AVLNode<Type>*& bt, const Type &x);
	void RotateR(AVLNode<Type>*& bt);
	void RotateLR(AVLNode<Type>*& bt);
	void RotateL(AVLNode<Type>*& bt);
	void RotateRL(AVLNode<Type>*& bt);
	void AVLTreePrint(AVLNode<Type>*bt);
private:
	AVLNode<Type>* root;
};

template<class Type>
void AVLTree<Type>::AVLTreePrint(AVLNode<Type>*bt)
{
	if (bt != nullptr)
	{
		AVLTreePrint(bt->leftchild);
		cout << bt->data << " ";
		AVLTreePrint(bt->rightchild);
	}
}
template<class Type>
void AVLTree<Type>::RotateR(AVLNode<Type>*& pt)
{
	AVLNode<Type>* subR = pt;
	pt = subR->leftchild;
	subR->leftchild = pt->rightchild;
	pt->rightchild = subR;
	pt->bf = subR->bf = 0;
}
template<class Type>
void AVLTree<Type>::RotateLR(AVLNode<Type>*& pt)
{
	AVLNode<Type>* subR = pt;
	AVLNode<Type>* subL= pt->leftchild;
	pt = subL->rightchild;
	subL->rightchild = pt->leftchild;
	pt->leftchild = subL;
	
	if (pt->bf == 0)
		subL->bf = 0;
	else if (pt->bf == -1)
		subL->bf = 0;
	else
		subL->bf = -1;
	subR->leftchild = pt->rightchild;
	pt->rightchild = subR;
	
	if (pt->bf == 0)
		subR->bf = 0;
	else if (pt->bf == -1)
		subR->bf =1;
	else
		subR->bf = 0;
	pt->bf = 0;
}

template<class Type>
void AVLTree<Type>::RotateL(AVLNode<Type>*& pt)
{
	AVLNode<Type>* subL = pt;
	pt = subL->rightchild;
	subL->rightchild = pt->leftchild;
	pt->leftchild = subL;
	pt->bf=subL->bf = 0;
}
template<class Type>
void AVLTree<Type>::RotateRL(AVLNode<Type>*& pt)
{
	AVLNode<Type>* subL = pt;
	AVLNode<Type>*subR = pt->rightchild;
	pt = subR->leftchild;

	subR->leftchild =pt->rightchild;
	pt->rightchild = subR;
	if (pt->bf == 0)
		subR->bf = 0;
	else if (pt->bf == -1)
		subR->bf = 1;
	else
		subR->bf = 0;
	subL->rightchild = pt->leftchild;
	pt->leftchild = subL;
	if (pt->bf == 0)
		subL->bf = 0;
	else if (pt->bf == -1)
		subL->bf = 0;
	else
		subL->bf = -1;
	pt->bf = 0;
}
template<class Type>
bool AVLTree<Type>::Insert(AVLNode<Type>*& bt, const Type& key)
{
	//1.按照BST的规则插入节点
	AVLNode<Type>* pr = nullptr;
	AVLNode<Type>* newnode = bt;
	stack<AVLNode<Type>*> st;
	while (newnode!= nullptr)
	{
		if (key == newnode->data)
			return false;
		pr = newnode;
		st.push(pr);
		if (key < newnode->data)
			newnode= newnode->leftchild;
		else
			newnode = newnode->rightchild;
	}   
	newnode = new AVLNode<Type>(key);
	if (pr == nullptr)
	{
		bt = newnode;
		return true;
	} 
	if (key < pr->data)
	{
		pr->leftchild = newnode;
	}
	else
	{
		pr->rightchild = newnode;
	}
	while (!st.empty())
	{
		pr = st.top();
		st.pop();
		if (newnode == pr->leftchild)
			pr->bf--;
		else
			pr->bf++;
		if (pr->bf == 0)
			break;
		if (pr->bf == 1 || pr->bf == -1)
			newnode = pr;
		else
		{
			if (newnode == pr->leftchild)
			{
				if (newnode->bf == -1)
					RotateR(pr);

				else
				{
					RotateLR(pr);
				}
			}
			else
			{
				if (newnode->bf == 1)
					RotateL(pr);

				else
					RotateRL(pr);
			}
			break;
		}
		
	}
	if (st.empty())
		bt = pr;
	else
	{
		AVLNode<Type>* ppr = st.top();
		if (key > ppr->data)
			ppr->rightchild = pr;
		else
			ppr->leftchild = pr;
	}
	return true;
}
int main()
{
	int ar[] = { 16, 3, 7, 3, 7, 11, 9, 21, 9, 18, 24, 15 };
	int n = sizeof(ar) / sizeof(ar[0]);
	AVLTree<int> avltree;
	for (int i = 0; i < n; i++)
	{
		avltree.Insert(ar[i]);
	}
	avltree.AVLTreePrint();
	system("pause");
};