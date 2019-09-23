#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Person
{
public:
	virtual void Func()
	{
		cout << "Person::Func" << endl;
	}
};
class Child : public Person
{
public:
	void Func()
	{
		cout << "Child::Func" << endl;
	}
};

void F(Person& p)
{
	p.Func();
}
int main()
{
	Person p;
	F(p);
	Child c;
	F(c);
	return 0;
}