#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Person
{
public:
	virtual void Func()
	{
		cout << "Person::Func()" << endl;

	}

};

class Student : public Person
{
public:
	void Func()
	{
		cout << "Student::Func()" << endl;
	}
};

void Fun(Person& p)
{
	p.Func();
}

int main()
{
	Person p;
	Fun(p);

	Student s;
	Fun(s);

	return 0;
}