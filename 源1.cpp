#include<iostream>
using namespace std;
#include<string>
#include"MyArray.hpp"
class Person
{
public:
	Person(){}
	Person(string name,int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};
ostream& operator<<(ostream &cout,Person &p)
{
	cout << p.m_name << p.m_age;
	return cout;
}
void test01()
{
	MyArray<int> arr1(5);
	MyArray<int> arr2(arr1);
	MyArray<int> arr3(10);
	arr3 = arr1;
	for (int i = 0; i < arr3.get_capacity(); i++)
	{
		arr3.Push_Back(i);
	}
	cout << "数组的容量：" << arr3.get_capacity() << endl;
	cout << "数组的大小：" << arr3.get_size() << endl;
	cout << arr3[0] << endl;
	MyArray<Person> arr4(6);
	Person p("孙悟空", 18);
	arr4.Push_Back(p);
	cout << arr4[0];
}
int main()
{
	test01();
}
