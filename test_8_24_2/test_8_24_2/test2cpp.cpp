#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <xtgmath.h>
using namespace std;

bool Fib(int a)
{
	for (int i = 2; i <= sqrt(a); ++i)
	{
		if (a % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int m;
	while (cin >> m)
	{
		cout << Fib(m) << endl;
	}
	return 0;
}