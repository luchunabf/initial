#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int CheckSys()
{
	int i = 1;
	if (*(char*)&i)
		return 1;
	else
		return 0;
}


int check_sys()
{
	union Un
	{
		int i;
		char c;
	}un;
	un.i = 1;
	return un.c;

}
int main()
{
	if (CheckSys())
		cout << "小端" << endl;
	else
		cout << "大端" << endl;

	return 0;
}


