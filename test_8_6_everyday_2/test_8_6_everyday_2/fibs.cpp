#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
using namespace std;

#if 1
size_t fibs(size_t n)
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
		n -= 1;
	}
	//for (int i = 3; i <= n; i++)
	//{
	//	result = left + right;
	//	left = right;
	//	right = result;
	//}
	return (result % 1000000);
}
int main()
{
	size_t n;
	while (cin >> n)
	{
		size_t ret = fibs(n);
		if (n<30)
			cout << ret << endl;
		else
			//cout << ret % 1000000 << endl;
			printf("%06d\n", ret);
	}
	return 0;
}
#endif


#if 0
int a[100005];
int main()
{
	int n;
	a[1] = 1;
	a[2] = 2;
	for (int i = 3; i <= 100000; i++)
		a[i] = (a[i - 1] + a[i - 2]) % 1000000;
	while (scanf("%d", &n) != EOF)
	{
		if (n >= 30)
			printf("%06d\n", a[n]);
		else
			printf("%d\n", a[n]);
	}
	return 0;
}
#endif

//int main()
//{
//	int a = 6789;
//	printf("%06d\n", a);
//	return 0;
//}