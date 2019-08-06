#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
using namespace std;
int f1(int n)
{
	int a[100005];
	a[1] = 1;
	a[2] = 2;
	for (int i = 3; i <= 100000; ++i)
		a[i] = (a[i - 2] + a[i - 1]) % 1000000;
	return a[n];
}

size_t f2(size_t n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	size_t left = 1;
	size_t right = 2;
	size_t result = 0;
	while (n - 2)
	{
		result = left + right;
		left = right;
		right = result;
		n--;
	}
	return right%1000000;
}

//size_t f3(int n)
//{
//	if (n == 0 || n == 1)
//		return 1;
//	int left = 1;
//	int right = 1;
//	int result = 0;
//	for (int i = 2; i <= n; ++i)
//	{
//		size_t result = left + right;
//		left = right;
//		right = result;
//	}
//	return right % 1000000;
//}

size_t f4(size_t n)
{
	if (n == 0 || n == 1)
		return 1;
	return f4(n - 2) + f4(n - 1);
}



int main()
{
	int n;
	//cin >> n;
	while (cin >> n)
	{
		printf("%6d\n", f1(n));
		printf("%6d\n", f2(n));
		//printf("%6d\n", f3(n));
		printf("%6d\n", f4(n)%1000000);
	}

	return 0;
}