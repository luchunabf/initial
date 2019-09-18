#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//#include <string.h>
using namespace std;

class Person
{
public:
	virtual void Tacket()
	{
		cout << "Person" << endl;
	}
//private:
//	int _data;
};

class Student : public Person
{
public:
	virtual void Tacket()
	{
		cout << "Student" << endl;
	}
};


void Func(Person& p)
{
	p.Tacket();
}

int main()
{
	/*Person p;
	Person* p1 = &p;
	p1->Tacket();

	Student s;
	p1 = &s;
	p1->Tacket();*/

	Person p;
	Func(p);

	Student s;
	Func(s);
	
	return 0;
}