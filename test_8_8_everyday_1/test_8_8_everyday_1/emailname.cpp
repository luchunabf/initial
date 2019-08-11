#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		cin.get();//////////////////我写的里面就差一个，cin>>n 之后的回车处理
		vector<string> v1;//可以用string放空格？可以
		v1.resize(n);
		for (int i = 0; i < n; ++i)
		{
			getline(cin, v1[i]);
		}
		vector<string> v2(n);
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
		{
			for (size_t j = 0; j < v1[i].size(); ++j)
			{
				if (v1[i][j] == ',' || v1[i][j] == ' ')
				{
					v[i] = 1;
					break;
				}

			}
		}
		for (int i = 0; i < n; ++i)
		{
			if (v[i] == 0)
				v2[i] = v1[i];
			else
				v2[i] = '"' + v1[i] + '"';//只有string才可以直接+
		}
		for (int i = 0; i < n - 1; ++i)
			cout << v2[i] << ", ";
		cout << v2[n - 1] << endl;
	}
	return 0;
}