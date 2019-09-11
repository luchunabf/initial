#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

int MyStrlen(char* str)
{
	int count = 0;
	while (*str)
	{
		++count;
		++str;
	}
	return count;
}

int main()
{
	char* str = "abc";
	cout << MyStrlen(str);
	return 0;
}