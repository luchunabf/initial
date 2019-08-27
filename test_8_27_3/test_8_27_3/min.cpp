#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int minFunc1(int a, int b)
{
	while (a % b)
	{
		int ret = a;
		a = b;
		b = ret % b;
	}
	return b;
}
int minFunc2(int a, int b)
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
int minFunc3(int a, int b)
{
	for (int i = a; i >= 1; --i)
	{
		if (a % i == 0 && b % i == 0)
			return i;
	}
	return -1;
}
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << " minFunc1: " << minFunc1(a, b) << endl;
		cout << " minFunc2: " << minFunc1(a, b) << endl;
		cout << " minFunc3: " << minFunc1(a, b) << endl;
	}
	return 0;
}