#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
using namespace std;

union Un
{
	char s;
	int i;
};
int main()
{
	Un un;
	un.i = 1;
	cout << (int)un.s << endl;
	return 0;
}