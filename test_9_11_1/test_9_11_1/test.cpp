#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

int MyStrlen1(char* str)
{
	if (nullptr == str)
	{
		assert(0);
		return -1;
	}
	int count = 0;
	while (*str)
	{
		++count;
		++str;
	}
	return count;
}


int MyStrlen2(char* str)
{
	if (nullptr == str)
	{
		assert(0);
		return -1;
	}
	char* p = str;
	while (*p)
	{
		
		++p;
	}
	return p-str;
}

int main()
{
	char* str = "abc";
	cout << MyStrlen1(str);
	cout << MyStrlen2(str);

	return 0;
}