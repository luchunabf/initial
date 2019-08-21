#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
union Un
{
	int i;
	char c;
};
int checkSys()
{
	Un un;
	un.i = 1;
	return un.c;
	
}
int main()
{
	cout << checkSys() << endl;
	return 0;
}