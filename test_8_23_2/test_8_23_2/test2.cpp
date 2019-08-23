#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int fib1(int a, int b)
{
	while (a%b)
	{
		int ret = a;
		a = b; 
		b = ret % b;
	}
	return b;
}

int fib2(int a, int b)
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
int fib3(int a, int b)
{
	int t;
	for (int i = 1; i <= a; ++i)
	{
		if ((a%i == 0) && (b%i==0))
			t = i;
	}
	return t;
}

int main()
{
	int a = 10;
	int b = 5;
	cout << fib1(a, b) << endl;
	cout << fib2(a, b) << endl;
	cout << fib3(a, b) << endl;

	return 0;
}