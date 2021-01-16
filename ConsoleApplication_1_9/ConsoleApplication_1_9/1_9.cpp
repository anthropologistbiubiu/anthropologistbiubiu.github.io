#include<iostream>
#include<list>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
void Swap(int &x,int &y)
{
	int temp = x;
	x = y;
	y = temp;
}
void main()
{
	stack<char> st;
	st.push('A');
	st.push('B');
	st.push('C');
	st.push('D');
	st.push('E');
	st.push('F');
	st.push('G');
	st.push('H');
	cout << "st.top="<< st.top() << endl;
	queue<char> Q;
	Q.push('A');
	Q.push('B');
	Q.push('C');
	Q.push('D');
	Q.push('E');
	Q.push('F');
	Q.push('G');
	system("pause");
}

/*
void main()
{
	vector<int> iv = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> iv1 = { 12, 13, 14, 15, 16 };
	iv.push_back(11);
	iv.insert(iv.begin(), 0);
	cout << iv.size() << endl;
	iv.swap(iv1);
	vector<int>::iterator it = iv.begin();
	while (it != iv.end())
	{
		cout << *it << " ";
		it++;
	}
	for (int i = 0; i < iv1.size(); i++)
	{
		cout << iv[i] << " ";

	}
	cout << endl;
	auto it1= iv.rbegin();
	while (it1!= iv.rend())
	{
		cout << *it1 << " ";
		it++;
	}
	cout << endl;

	system("pause");
}
*/
/*
void main()
{
	string st1;
	string st2("hello,bit");
	string st3(st2);
	string st4(10, '#');
	cout << st3 << endl;
	cout << "size " << st2.size() << endl;
	cout << "legth " << st2.length() << endl;
	cout << "capacity " << st2.capacity() << endl;
	system("pause");
}
*/
/*
void main()
{
	list<int> list1;
	list<int> lt2(10,5);
	list<int> lt3 = lt2;
	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	list<int>lt4(ar, ar + 10);
	list<int>lt5(lt4.begin(), lt4.end());
	list<int>lt6 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	list<int>::iterator it = lt6.begin();
	while (it != lt6.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	auto it1 = lt6.begin();
	while (it1 != lt6.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	//·´Ïòµü´úÆ÷
	auto it2 = lt6.end();
	it2--;
	while (it2 != lt6.begin())
	{
		cout << *it2 << " ";
		it2--;
	}
	cout << *it2;
	cout << endl;

	list<int>::reverse_iterator rit = lt6.rbegin();
	while (rit != lt6.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

	auto pos = find(lt6.begin(), lt6.end(), 8);
	lt6.insert(pos, 0);

	system("pause");
}
*/
