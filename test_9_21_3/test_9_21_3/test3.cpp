#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T;
	while (cin >> T)
	{
		int n;
		vector<int> v0(T);
		for (int j = 0; j < T; ++j)
		{
			cin >> n;
			vector<int> v(n);
			int ret = 0;
			int count = 0;
			for (int i = 0; i < n; ++i)
			{
				cin >> v[i];
				if (v[i] >= ret)
				{
					count += 1;
				}
				ret += v[i];
			}
			v0[j] = count;
		}
		for (int i = 0; i < T; ++i)
		{
			cout << v0[i] << endl;
		}

	}
	return 0;
}