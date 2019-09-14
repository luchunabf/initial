#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main()
{
	int N, M;
	while (cin >> N >> M)
	{
		for (int i = 0; i < M; ++i)
		{
			int a = 0, b=0, c=0;
			cin >> a >> b >> c;
			cout << a <<" " <<  b  << " " << c << endl;
		}
	}
	return 0;
}