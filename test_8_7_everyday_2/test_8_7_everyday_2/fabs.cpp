#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//size_t fibs(int n)
//{
//	int a[81];
//	//if(n == 0 || n == 1)
//	a[0] = 0;
//	a[1] = 1;
//	a[2] = 1;
//	for (int i = 3; i < 81; ++i)
//	{
//		a[i] = a[i - 2] + a[i - 1];
//	}
//	return a[n];
//}

int fibs(int n)
{
	if (n == 1 || n == 2)
		return 1;
	return fibs(n - 2) + fibs(n - 1);
}
int main()
{
	//int n;
	//while (cin >> n)
	//	cout << fibs(n) << endl;
	int m, n;
	while (cin >> m >> n)
	{
		int count = 0;
		for (int i = m; i <= n; ++i)
			count += fibs(i);
		cout << count << endl;
	}
	return 0;
}