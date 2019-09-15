#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Min(int W, int H)
{
	return (W / H) > (H / W) ? (H / W) : (W / H);
}


int Square(int W, int H)
{
	int ret = W * H;
	return ret;
}



void Swap(vector<int>& v1, vector<int>& v2)
{
	if (v1.size() != v2.size())
		return;
	vector<int> temp(v1);
	for (int i = 0; i < v1.size(); ++i)
	{
		v1[i] = v2[i];
		v2[i] = temp[i];
	}
}


int main()
{
	int N;
	while (cin >> N)
	{
		vector<vector<int>> v;
		v.resize(N);
		for (int i = 0; i < N; ++i)
		{
			int W, H;
			cin >> W >> H;
			v[i].resize(2);
			v[i][0] = W;
			v[i][1] = H;
		}

		for (size_t i = 0; i < v.size(); ++i)
		{
			int minSquare = i;
			for (size_t j = i + 1; j < v.size(); ++j)
			{
				if (Square(v[i][0], v[i][1]) < Square(v[j][0], v[j][1]))
					minSquare = i;
				else if (Square(v[i][0], v[i][1]) == Square(v[j][0], v[j][1]))
				{
					if (Min(v[i][0], v[i][1]) > Min(v[j][0], v[j][1]))
						minSquare = i;
					else if (Min(v[i][0], v[i][1]) == Min(v[j][0], v[j][1]))
					{
						if (v[i][0] < v[j][0])
							minSquare = i;
					}
				}
			}
			if (minSquare != i)
				Swap(v[i], v[minSquare]);
			
		}
		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i][0] << " " << v[i][1] << " ";
		}
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Min(int W, int H)
{
	return (W / H) > (H / W) ? (H / W) : (W / H);
}


int Square(int W, int H)
{
	int ret = W * H;
	return ret;
}



void Swap(vector<int>& v1, vector<int>& v2)
{
	if (v1.size() != v2.size())
		return;
	vector<int> temp(v1);
	for (int i = 0; i < v1.size(); ++i)
	{
		v1[i] = v2[i];
		v2[i] = temp[i];
	}
}


int main()
{
	int N;
	while (cin >> N)
	{
		vector<vector<int>> v;
		v.resize(N);
		for (int i = 0; i < N; ++i)
		{
			int W, H;
			cin >> W >> H;
			v[i].resize(2);
			v[i][0] = W;
			v[i][1] = H;
		}

		for (size_t i = 0; i < v.size(); ++i)
		{
			int minSquare = i;
			for (size_t j = i + 1; j < v.size(); ++j)
			{
				if ((v[i][0] * v[i][1]) < (v[j][0] * v[j][1]))
					minSquare = i;
				else if ((v[i][0] * v[i][1]) == (v[j][0] * v[j][1]))
				{
					if (Min(v[i][0], v[i][1]) > Min(v[j][0], v[j][1]))
						minSquare = i;
					else if (Min(v[i][0], v[i][1]) == Min(v[j][0], v[j][1]))
					{
						if (v[i][0] < v[j][0])
							minSquare = i;
						else
							minSquare = j;
					}
					else
						minSquare = j;
				}
				else
				{
					minSquare = j;
				}
			}
			if (minSquare != i)
				Swap(v[i], v[minSquare]);

		}
		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i][0] << " " << v[i][1] << " ";
		}
	}
	return 0;
}
#endif











#if 0
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Swap(vector<int>& v1, vector<int>& v2)
{
	if (v1.size() != v2.size())
		return;
	vector<int> temp(v1);
	for (int i = 0; i < v1.size(); ++i)
	{
		v1[i] = v2[i];
		v2[i] = temp[i];
	}
}

int main()
{
	int N, M;
	while (cin >> N >> M)
	{
		vector<vector<int>> v;
		v.resize(M);
		for (int i = 0; i < M; ++i)
		{
			int A, B, C;
			cin >> A >> B >> C;
			v[i].resize(3);
			v[i][0] = A;
			v[i][1] = B;
			v[i][2] = C;

			if (i % 2 == 0)
			{
				swap(v[i][0], v[i][2]);
			}
			else
			{
				swap(v[i][1], v[i][2]);
			}
			cout << v[i][0] << v[i][1] << v[i][2] << endl;
		}

	}
	return 0;
}


#endif





#if 0
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

bool IsPrime(int m, int n)
{
	if (m == 1 || n == 1)
		return true;
	for (int i = 2; i <= n/2; ++i)
	{
		if (m % i == 0 && n % i == 0)
			return false;
	}
	if (m % n == 0)
		return false;
	return true;
}

int SimpleCount(int n)
{
	int count = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (IsPrime(n, i))
			++count;
	}
	return count;
}

double F(int x)
{
	int ret = SimpleCount(x);
	double ret1 = ret / x;
	return ret1;
}

int main()
{
	int N;
	while (cin >> N)
	{
		double minFn = F(1);
		for (int i = 1; i <= N; ++i)
		{
			if (F(i) < minFn)
				minFn = F(i);
		}
		printf("%6lf\n", minFn);
	}
	return 0;
}
#endif

//#include <iostream>
//#include <stdio.h>
//#include <math.h>
//using namespace std;
//
//double F(int x)
//{
//	int ret = 2;
//	return (double)ret / x;
//}
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		cout << F(n);
//	}
//	return 0;
//}

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

bool IsPrime(int m, int n)
{
	if (m == 1 || n == 1)
		return true;
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (m % i == 0 && n % i == 0)
			return false;
	}
	if (m % n == 0 || n % m == 0)
		return false;
	return true;
}

int SimpleCount(int n)
{
	int count = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (IsPrime(n, i))
			++count;
	}
	return count;
}

double F(int x)
{
	double ret = (double)SimpleCount(x);
	double ret1 = ret / x;
	return ret1;////////////////////////这里出现的问题
}

int main()
{
	int N;
	while (cin >> N)
	{
		double minFn = F(1);
		for (int i = 1; i <= N; ++i)
		{
			if (F(i) < minFn)
				minFn = F(i);
			else
				continue;
		}
		printf("%6lf\n", minFn);
	}
	return 0;
}











#if 0
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<string> v;
	v.reserve(1000);
	while (1)
	{
		string s;
		while (getline(cin, s))//获取多行
		{
			if (s.empty())
				break;
			v.push_back(s);
		}
		cout << v[v.size() - 1] << endl;
		
	}
	return 0;
}
#endif