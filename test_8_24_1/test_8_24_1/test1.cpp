#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

int Fib1(int a, int b)
{
	while (a%b)
	{
		int ret = a;
		a = b;
		b = ret%b;
	}
	return b;
}
int Fib2(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return b;
}
int Fib3(int a, int b)
{
	for (int i = a; i > 0; ++i)
	{
		if (a%i == 0 && b%i == 0)
			return i;
	}
	return 0;
}
int main()
{
	int a = 5, b = 10;
	cout << Fib1(a, b) << endl;
	cout << Fib2(a, b) << endl;
	cout << Fib3(a, b) << endl;

	return 0;
}