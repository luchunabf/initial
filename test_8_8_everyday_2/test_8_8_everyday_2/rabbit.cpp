#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//mine
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int count = 1;
//		while (--n)
//		{
//			count *= 2;
//		}
//		count << count;
//	}
//	return 0;
//}

//right
//#include <iostream>
//#include <cstdio>
//int main()
//{
//	long long n[91] = { 1, 2 };
//	for (int i = 2; i <= 90; i++)
//	{
//		n[i] = n[i - 1] + n[i - 2];
//	}
//	int d;
//	while (std::cin >> d)
//	{
//		printf("%lld\n", n[d - 1]);
//	}
//}
#include <iostream>
#include <cstdio>
int main()
{
	long long n[91] = {0, 1, 2 };
	for (int i = 3; i <= 90; i++)
	{
		n[i] = n[i - 1] + n[i - 2];
	}
	int d;
	while (std::cin >> d)
	{
		printf("%lld\n", n[d]);
	}
}