#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<set>
using namespace std;
//下午要熟练 命名空间  const   引用   类模板  
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
	HashNode<int>* _ht[_N];   //有点看不懂什么意思，哈希表是怎么给出的，给出来的是什么，就是一个哈希结点的指针数组
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
using namespace Yourspace;  //引入空间所有信息



//缺省参数  就是声明或者定义函数时为函数的参数指定一个默认值，在调用该函数
// 如果没有指定实参，则实参采用该默认值 ，缺省参数只能从右到左给出
/*
void TestFun(int a = 0)
{
	cout << a << endl;
}
void TestFun(int a, int b = 10, int c = 20) //半缺省参数
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}
void TestFun(int a = 10, int b = 20, int c = 30)//全缺省参数
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

*/
void TestFun(int a, int b = 10, int c =20) //半缺省参数
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}
//引用  
//1.引用在定义时必须被初始化
//2.一个变量可以有多个引用
//3.一个引用一旦引用一个实体，再不能引用其他实体
void  TestRef()
{
	int a = 10;
	int& b = a;
	cout << a << endl;
	cout << b << endl;
}
//指针的引用 
void PtrRef()
{
	int a = 10;
	int& b = a;
	int* p = &a;
	int*& q = p;

	int ar[10];
	int(&br)[10] = ar;  //数组的引用  &的优先级没有[]	//任何的类型参数都可以有引用出现
}

//常引用
void TestConstRef()
{
	const int a = 10;
	const int& ra = a;

	const double d = 12.34;
	const double& b = d;

	cout << ra << endl;
	cout << b << endl;
}
//引用的使用场景
//1.引用做参数
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
//2.引用做返回值

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
	//Myspace::fun();    //作用域限制符
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


