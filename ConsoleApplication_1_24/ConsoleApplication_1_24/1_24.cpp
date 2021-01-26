#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<set>
using namespace std;
//����Ҫ���� �����ռ�  const   ����   ��ģ��  
template<class Type>
class HashNode
{
public:
	HashNode(Type d = Type()) :data(d), link(nullptr)

	~HashNode()
	{}
private:
	Type data;
	HashNode* link;
};

template<class Type,size_t _N=13>
class HashTable
{
public:
	HashTable()
	{
		memset(_ht, 0, sizeof(HashNode<Type>*)*_N);
	}

private:
	HashNode<int>* _ht[_N];   //�е㿴����ʲô��˼����ϣ������ô�����ģ�����������ʲô������һ����ϣ����ָ������
};


namespace Myspace
{
	void fun()
	{
		cout << "This is fun 1" << endl;
	}
}

namespace Yourspace
{
	void fun()
	{
		cout << "this is fun 2 " << endl;
	}
}

//using Yourspace::fun;
using namespace Yourspace;  //����ռ�������Ϣ



//ȱʡ����  �����������߶��庯��ʱΪ�����Ĳ���ָ��һ��Ĭ��ֵ���ڵ��øú���
// ���û��ָ��ʵ�Σ���ʵ�β��ø�Ĭ��ֵ ��ȱʡ����ֻ�ܴ��ҵ������
/*
void TestFun(int a = 0)
{
	cout << a << endl;
}
void TestFun(int a, int b = 10, int c = 20) //��ȱʡ����
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}
void TestFun(int a = 10, int b = 20, int c = 30)//ȫȱʡ����
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

*/
void TestFun(int a, int b = 10, int c =20) //��ȱʡ����
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}
//����  
//1.�����ڶ���ʱ���뱻��ʼ��
//2.һ�����������ж������
//3.һ������һ������һ��ʵ�壬�ٲ�����������ʵ��
void  TestRef()
{
	int a = 10;
	int& b = a;
	cout << a << endl;
	cout << b << endl;
}
//ָ������� 
void PtrRef()
{
	int a = 10;
	int& b = a;
	int* p = &a;
	int*& q = p;

	int ar[10];
	int(&br)[10] = ar;  //���������  &�����ȼ�û��[]	//�κε����Ͳ��������������ó���
}

//������
void TestConstRef()
{
	const int a = 10;
	const int& ra = a;

	const double d = 12.34;
	const double& b = d;

	cout << ra << endl;
	cout << b << endl;
}
//���õ�ʹ�ó���
//1.����������
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
//2.����������ֵ

int& Add(int a, int b)
{
	int c = a + b;
	return c;
}
int Fun(const  int& a, const int& b)
{
	int result = a + b;
	return result;
}
void main()
{
	//Myspace::fun();    //���������Ʒ�
	//fun();
	//cout << endl;
	//TestFun(10);
	//TestFun(100,200);
	//cout << endl;
	TestRef(); 
	cout << endl;
	TestConstRef();
	int& ref = Add(1, 2);
	cout << ref << endl;
	int res = Fun(10, 20);
	cout << res << endl;
	system("pause");
}


