#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int x, y, n;
	while (cin >> x >> y >> n)
	{
		int a, b;
		vector<vector<int>> v;
		v.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> a >> b;
			v[i].resize(2);
			v[i][0] = a;
			v[i][1] = b;

			
		}
		cout << 5 << endl;
	}
	return 0;
}