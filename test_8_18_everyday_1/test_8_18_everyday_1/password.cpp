#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;//����ֱ�������𣿿��Ե�
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