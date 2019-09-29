#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Person
{
public:
	virtual void F1() = 0;
	virtual void F2() = 0;
	virtual void F3() = 0;
};

class Student
{
public:
	void F1()
	{
		cout << "hello" << endl;
	}
	void F2()
	{
		cout << "world" << endl;
	}
};

int main()
{
	//Person p;
	Student s;
	s.F1();
	s.F2();
	return 0;
}