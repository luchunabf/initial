#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	char str1[] = "abcd";
	char str2[] = "abcg";
	cout << memcmp(str1, str2, 4) << endl;
	return 0;
}