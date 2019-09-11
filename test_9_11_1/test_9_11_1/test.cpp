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

int MyStrlen3(char* str)
{
	if (nullptr == str)
	{
		assert(0);
		return -1;
	}
	if (*str == '\0')
		return 0;
	return 1 + MyStrlen3(str + 1);
}

int main()
{
	char* str = "abc";
	cout << MyStrlen1(str) << endl;
	cout << MyStrlen2(str)<< endl;
	cout << MyStrlen3(str)<< endl;

	return 0;
}