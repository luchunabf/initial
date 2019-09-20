#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
#if 1
int a16To10(string s)
{
	if (s.size() > 2) return -1;
	int count = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] > 'F' || s[i] < '0')
			return -1;
		if (s[i] > '0' && s[i] < '9')
			count += (s[i] - '0') * pow(16, 1 - i);
		if (s[i] >= 'A' && s[i] <= 'F')
			count += (s[i] - '0') * pow(16, 1 - i);
	}
}



int main()
{
	string s1;
	while (getline(cin, s1))
	{
		string s2{ "8" };
		int count = 1;
		for (size_t i = 0; i < s1.size(); ++i)
		{
			if (s1[i] == ' ')
				++count;
		}
		s2 += count + '0';
		s2 += " 10 F1 ";
		s2 += s1;
		s2 += " ";
		//这里需要求十六进制累加和校验
		//1.遍历s1取出所有字节的程序运算（十六进制）
		//2.将十六进制转换成十进制进行累加
		//3.将累加和转换成十六进制
		//4.取出转换后的十六进制后两位，添加到s2中（注意空格）



		s2 += "E7";
		cout << s2 << endl;
	}
	return 0;
}
#endif