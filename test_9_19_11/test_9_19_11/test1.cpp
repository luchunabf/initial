#define _CRT_SECURE_NO_WARNINGS 1

#if 1
#include <iostream>
using namespace std;

size_t FibN(size_t n)
{
	if (n == 1)
		return 1;
	return n*(FibN(n - 1));
}
size_t minCount(size_t n)
{
	size_t sum = FibN(n);
	while (sum % 10 == 0)
	{
		sum /= 10;
	}
	return sum % 10;
}



int main()
{
	size_t n;
	while (cin >> n)
	{
		cout << minCount(n);
	}
	return 0;
}
#endif





#if 0
#include <iostream>
using namespace std;

size_t LastNotZero(size_t n)
{
	size_t count = 1;
	size_t sum = 1;
	while (count <= n)
	{
		sum *= count;
		++count;
	}
	while (sum % 10 == 0)
	{
		sum /= 10;
	}
	return sum % 10;
}



int main()
{
	size_t n;
	while (cin >> n)
	{
		cout << LastNotZero(n) << endl;
	}
	return 0;
}
#endif



#if 0
#include <iostream>
using namespace std;

size_t MinCount(size_t n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	size_t count = 1;
	size_t  i = 2;
	while (i <= n)
	{
		count *= i;
		++i;
	}
	return count;
}

int main()
{
	size_t n;
	while (cin >> n)
	{
		cout << MinCount(n) << endl;
	}
	return 0;
}
#endif


#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<vector<int>> v;
		v.resize(m);
		for (int i = 0; i < v.size(); ++i)
		{
			v[i].resize(n);
			int a, b;
			cin >> a >> b;
			v[i][0] = a;
			v[i][1] = b;
		}
		int s, m;
		cin >> s >> m;
		if ((s < 1 || s > n) && (m < 1 || m > n))
			cout << 0 << endl;


	}
	return 0;
}
#endif