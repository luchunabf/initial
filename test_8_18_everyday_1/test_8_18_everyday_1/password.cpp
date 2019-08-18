#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;//可以直接输入吗？可以的
	while (getline(cin, s))
	{
		//cin.get();
		string s1;
		for (size_t i = 0; i < s.size(); ++i)
		{
			if (s[i] >= '0' && s[i] <= '9')
				s1 += s[i];
		}
		for (auto e : s1)
			cout << e;
		cout << endl;
	}
	return 0;
}