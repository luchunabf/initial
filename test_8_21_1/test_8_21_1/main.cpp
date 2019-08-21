#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

double fibs(int a, int n)
{
	if (n == 1)
		return a;
	return a*fibs(a, n - 1);
}
int main()
{
	int a, n;
	while (cin >> a >> n)
	{
		double ret = fibs(a, n);
		cout << ret << endl;
	}
	return 0;
}