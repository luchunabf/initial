#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		//int count1 = 0;
		//int count2 = 0;
		vector<int> v1(256);
		vector<int> v2(256);
		for (size_t i = 0; i < s1.size(); ++i)
		{
			v1[s1[i]] += 1;
		}
		for (size_t i = 0; i < s2.size(); ++i)
		{
			v2[s2[i]] += 1;
		}

		for (int i = 0; i < 256; ++i)
		{
			if (v1[s1[i]] >= v2[s2[i]])
				continue;
			else
			{
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
	}
	return 0;
}