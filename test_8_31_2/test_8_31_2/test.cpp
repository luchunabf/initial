#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int fib1(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
		{
			b = b - a;
		}
	}
	return b;
}

int fib2(int a, int b)
{
	while (a%b)
	{
		int ret = a;
		a = b;
		b = ret % b;
	}
	return b;
}

int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << fib1(a, b) << endl;
		cout << fib2(a, b) << endl;
	}
	return 0;
}