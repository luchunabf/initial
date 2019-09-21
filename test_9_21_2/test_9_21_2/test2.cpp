#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<size_t> v1(n);
		for (size_t i = 0; i < n; ++i)
		{
			cin >> v1[i];
		}
		vector<size_t> v2(m);
		for (int i = 0; i < m; ++i)
		{
			cin >> v2[i];
		}
		vector<int> v3(m, 0);
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (v1[j] == v2[i])
					v3[i]++;
			}
		}
		for (int i = 0; i < m; ++i)
		{
			cout << v3[i] << endl;
		}
	}
	return 0;
}
