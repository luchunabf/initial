#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int begin, end, n;
	while (cin >> begin >> end >> n)
	{
		if (n < 2)
		{
			cout << 0 << endl;
			continue;
		}
		//求1:2:3 中1的大小，对应可以求出2 和 3 的大小
		int count = 0;
		count += ((n - 1) / 3) * 6;
		if ((n - 1) % 3 == 1)
			count += 1;
		else if ((n - 1) % 3 == 2)
			count += 3;
		//然后求出区间差值最小比例（求1:2:3 中1的大小）
		double m = end - begin;//求出总差值
		double d = m / count;//求1:2:3 中1的大小
		double d2 = d * 2;//求1:2:3 中2的大小
		double d3 = d * 3;//求1:2:3 中3的大小
		//用数组来保存要输出的所有数
		vector<double> v(n);
		v[0] = (double)begin;
		v[n - 1] = (double)end;
		for (int i = 1; i < n - 1; ++i)
		{
			if (i % 3 == 1)
				v[i] = v[i - 1] + d;
			else if (i % 3 == 2)
				v[i] = v[i - 1] + d2;
			else
				v[i] = v[i - 1] + d3;
		}
		//遍历输出整个数组即可
		for (int i = 0; i < v.size() - 1; ++i)
		{
			printf("%0.2lf,", v[i]);
		}
		printf("%0.2lf", v[n - 1]);
	}
	return 0;
}
