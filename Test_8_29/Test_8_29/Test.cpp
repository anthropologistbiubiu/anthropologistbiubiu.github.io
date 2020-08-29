#include<iostream>
#include<string.h>
using namespace std;

/*
class Time
{
public:
	Time()
	{
		_year = 0;
		_month = 0;
		_day = 0;
		cout << "Time()" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

class String
{
public:
	String(const char* str ="jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << " ~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};

class Date
{
	friend bool operator==(const Date& d1,const Date& d2);
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year+1;
		_month = d._month+1;
		_day = d._day+1;
	}
public:
	void Printf()
	{ cout << _year << _month << _day << endl; }
private:
	int _year;
	int _month;
	int _day;	
};
bool operator==(const Date& d1, const Date& d2)
{
	return d1._year == d2._year
		&& d1._month == d2._month
		&& d1._day == d2._day;
}

class A
{
public:
	A(int data) :m_data(data)
	{
		m_count++;
	}
	~A()
	{
		m_count--;
	}
	int GetCount()
	{
		return m_count;
	}
private:
	int m_data;
	static int m_count;
};
int main()
{
	A a1(10);
	A a2(20);
	A a3(30);
	cout << a3.GetCount() << endl;
	a3.~A();
	cout << a2.GetCount() << endl;
	system("pause");
}
*/

/*
class A
{
public:
	A(int data) :m_data(data)
	{
		m_count++;
	}
	~A()
	{
		m_count--;
	}
	static int GetCount()  //静态函数不属于任何对象，其次静态函数只能访问静态成员。
	{
		return m_count;      //也不能调动普通方法
	}
	int GetNum()
	{
		return m_count;
	}
private:
	int m_data;
	static int m_count;
};
int A::m_count = 0; //静态成员变量只能在类外初始化，只拥有一个公共空间。
//静态成员变量在类的生命周期当中只有一份，可以供所有的对象共享。
int main()
{
	A a1(10);
	cout << A::GetCount() << endl;          //没有参数列表打印的则是函数名的地址
	A a2(20);
	cout << A::GetCount() << endl;
	A a3(30);
	cout << A::GetCount() << endl;
	cout << a3.GetNum() << endl;               //普通方法可以调动静态成员
	system("pause");
}
*/
/*根本原因：静态成员与静态方法没有this指针*/

/*
#define DEFAULT_CAPACITY 8
class Seqlist
{
public:
	Seqlist(int sz = DEFAULT_CAPACITY)
	{
		capacity = sz > DEFAULT_CAPACITY ? sz : DEFAULT_CAPACITY;
	}
private:
	int*base;
	int capacity;
	int size;
};


class Test
{
public:
	Test(int d = 10) :m_data(d)
	{}
private:
	int m_data = 0;        //缺省值
};

int main()
{
	Test t;
	return 0;
}


//对象只能访问共有成员和公有方法，不能直接访问保护和私有的成员和方法
//所以类中除了要有私有方法还要有访问私有数据的公有方法setdate()

/*友元函数*/
/*
class Test;
void fun(const Test& t);
class Test
{
	friend void fun(const Test& t);
public:
	Test(int data=10) :m_data(data)
	{}
	~Test()
	{
		cout << m_data << endl;
	}
	void SetDate(int x)
	{
		m_data = x;
	}
private:
	int m_data = 0;
};


void fun(const Test& t)
{
	cout << t.m_data << endl;
}
int main()
{
	Test test;
	test.SetDate(11);
	fun(test);
	system("pause");
	
}
*/
/*  友元类  */
/*
class B;
class A
{
	friend class B;
public:
	A(int a, int b) :m_a(a), m_b(b)
	{}
	void Print()
	{
		cout << m_a << " " << m_b << endl;
	}
private:
	int m_a;
	int m_b;
};

class B
{
public:
	B(int a = 1, int b = 2) :m_x(a), m_y(b)
	{}
	void fun(A& a)
	{
		a.m_a = m_x;
		a.m_b = m_y;
	}
private:
	int m_x;
	int m_y;
};
void main()
{
	A a(3, 5);
	a.Print();
	B b(10, 20);
	b.fun(a);
	a.Print();
	system("pause");

}
*/
/*内部类*/
/*
class A{
public:
	A(int data = 0) :m_data(data)
	{}
	class My_class
	{
	public:
		My_class(int date) :m_x(date)
		{}
		void  Show()
		{
			cout << m_x << endl;
		}
	private:
		int m_x = 0;
	};
private:
	int m_data;
};

void main()
{
	A::My_class my_class(10);
	my_class.Show();
	system("pause");
}
*/

/*运算符的重载*/
/*
class Complex
{
public:
	Complex(int real=0, int image=0) :m_real(real), m_image(image)
	{
		cout << "Create a obj" << " " << this << endl;
	}
	~Complex()
	{
		cout << "Free a obj" << " " << this << endl;
	}
	Complex(const Complex& c)
	{
		cout << "Copy Create a obj" << " " << this << endl;
		m_real = c.m_real;
		m_image = c.m_image;
	}
	void Print(const Complex& c)
	{
		cout << "(" << c.m_real << "," << c.m_image << ")" << endl;
	}
public:
	//重载为成员函数
	Complex operator+ (const Complex &c1)
	{
		//Complex temp(m_real + c1.m_real, m_image + c1.m_image);
		//return temp;
		return (m_real + c1.m_real, m_image + c1.m_image);
	}
	Complex& operator=(const Complex& c)            //赋值语句重载
	{
		cout <<"assign" << "  " << this << endl;
		if (this != &c)
		{
			m_real = c.m_real;
			m_image = c.m_image;
		}
		return *this;
	}

private:
	int m_real;
	int m_image;
};

int main()
{
	Complex c1(1, 2);
	c1.Print(c1);
	Complex c2(3, 4);
	c2.Print(c2);
  	Complex c = c1 + c2;
	c.Print(c);
	system("pause");
}
*/
 
/*
class Complex;

Complex operator+ (const Complex &c1, const Complex &c2);
Complex  operator- (const Complex& c1, const Complex& c2);
ostream& operator<< (ostream& output, const Complex& c);
istream& operator>> (istream& input, const Complex& c);
class Complex
{
	friend  Complex  operator+ (const Complex& c1, const Complex& c2);
	friend  Complex operator- (const Complex& c1, const Complex& c2);
	friend  ostream& operator<< (ostream& output, const Complex& c);
	friend  istream& operator>> (istream& input,  Complex& c);
public:
	Complex(int real = 0, int image = 0) :m_real(real), m_image(image)
	{}
	~Complex()
	{}
	Complex(const Complex& t)
	{
		m_real = t.m_real;
		m_image = t.m_image;
	}
private:
	int m_real;
    int m_image;
};

Complex  operator+ (const Complex& c1, const Complex& c2)
{
	return Complex(c1.m_real + c2.m_real, c1.m_image + c2.m_image);
}
 Complex operator- (const Complex & c1, const Complex& c2)
{
	 return Complex(c1.m_real - c2.m_real, c1.m_image - c2.m_image);
}

ostream& operator<< (ostream& output, const Complex& c)
{
	output << "(" << c.m_real << "," << c.m_image << ")" << endl;
	return output;
}

istream& operator>> (istream& input, Complex& c) //刚刚加上const 结果是无限循环。有待思考
{
	cout << "请输入 real image" << endl;
	input >> c.m_real >> c.m_image;
	return input;
}

void main()
{
	Complex c1;
	Complex c2;
	cin >> c1;
	cin >> c2;
	Complex c;
	c = c1 + c2;
	cout << c << endl;
	c = c1 - c2;
	cout << c << endl;
	system("pause");

}

*/


class String
{
	friend bool operator== (const String& c1, const String& c2);
public:
	String(char*name)
	{
		strcpy(m_name, name);
	}
private:
	char* m_name=(char*)malloc(sizeof(char)*10);
};
bool operator== (const String& c1, const String& c2)
{
	return strcmp(c1.m_name, c2.m_name)==0;
}


int main()
{
	String st1("hello");
	String st2("bool");
	if (st1 == st2)
		cout << "true " << endl;
	else
		cout << "false" << endl;
	system("pause");
}



