#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

char* charZip(char* str,int size)
{
	if (nullptr == str)
		return nullptr;
	char* p = new char[size + 1];
	p[0] = str[0];
	int index1 = 1;
	int index2 = 1;
	while (index1 != size)
	{
		int count = 1;
		while (str[index1] && (str[index1 - 1] == str[index1]))
		{
			++count;
			++index1;
		}
		p[index2] = count + '0';//Ä¬ÈÏ²»³¬¹ý9
		index1++;
		index2++;
		if (str[index1])
		{
			p[index2] = str[index1];
			index2++;
			index1++;
		}
	}
	str = p;
	delete[] p;
	return str;
}
int main()
{
	char* str = "aaaabbbcccc";
	int len = strlen(str);
	char* p = charZip(str, len);
	printf("%s\n", p);
	return 0;
}