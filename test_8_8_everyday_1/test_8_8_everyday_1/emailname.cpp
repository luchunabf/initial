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
		cin.get();//////////////////��д������Ͳ�һ����cin>>n ֮��Ļس�����
		vector<string> v1;//������string�ſո񣿿���
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
				v2[i] = '"' + v1[i] + '"';//ֻ��string�ſ���ֱ��+
		}
		for (int i = 0; i < n - 1; ++i)
			cout << v2[i] << ", ";
		cout << v2[n - 1] << endl;
	}
	return 0;
}