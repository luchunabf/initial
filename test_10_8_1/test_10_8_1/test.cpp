#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class A
{
private:
	int _a;
};

class B
{
public:
	void F()
	{
		cout << a._a << endl;
	}
public:
	int _b;
	A a;
};

int main()
{
	B b;
	return 0;
}