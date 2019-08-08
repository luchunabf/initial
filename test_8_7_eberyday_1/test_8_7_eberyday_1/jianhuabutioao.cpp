#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int count = 0;
		int cur1 = 0;
		int cur2 = 0;
		int cur = 0;
		while (cur < s1.size())
		{
			while (cur2 < s2.size() && cur1 < s1.size() && s1[cur1] == s2[cur2])//两个指针（下标）都不能越界
			{
				cur1++;
				cur2++;
			}
			if (cur2 == s2.size())
			{
				++count;
				cur = cur1;
				cur2 = 0;
			}
			else
			{
				cur2 = 0;
				cur++;
				cur1 = cur;
			}
		}
		cout << count << endl;
	}
	return 0;
}