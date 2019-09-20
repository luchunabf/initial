#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

#if 0
bool In2(int n)
{
	int tmp = n;
	int count = 0;
	while (tmp)
	{
		tmp /= 10;
		++count;
	}
	for (int i = 1; i < count; ++i)
	{
		if (n / (pow(10, i)) == 2)
			return true;
	}
	return false;
}
#endif


#if 1
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		for (int i = 1; i <= n; ++i)
		{
			int tmp = i;
			while (tmp)
			{
				if (tmp % 10 == 2)
					++count;
				tmp /= 10;
			}
		}
		cout << count << endl;
		//printf("%d\n", count);
	}
	return 0;
}
#endif


//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int count = 0;
//		for (int i = 1; i <= n; ++i)
//		{
//			if (i % 2 == 0 || i / 10 == 2 || i / 100 == 2 || i / 1000 == 2)
//				++count;
//
//		}
//		cout << count << endl;
//	}
//	return 0;
//}



#if 0
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		for (int i = 1; i <= n; ++i)
		{
			int tmp = i;
			string s;
			while (tmp)
			{
				s += (tmp % 10) + '0';
				tmp /= 10;
			}
			for (size_t j = 0; j < s.size(); ++j)
			{
				if (s[j] == '2')
				{
					++count;
					//break;
				}
			}

		}
		cout << count << endl;
	}
	return 0;
}
#endif


