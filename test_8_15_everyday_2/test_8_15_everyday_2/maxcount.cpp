#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		int maxcount = 0;
		for (int i = 0; i < n; ++i)
		{
			int count = 1;
			int j = i;
			int k = i + 1;
			while (k < n)
			{
				if (v[j] <= v[k])
				{
					count += 1;
					j = k;
					k++;
				}
				else
				{
					k++;
				}
			}
			if (maxcount < count)
				maxcount = count;
		}
		cout << maxcount << endl;
	}
	return 0;
}