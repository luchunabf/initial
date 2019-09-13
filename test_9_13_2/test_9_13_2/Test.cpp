#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


enum Color
{
	red,
	yellow = 5,
	green
};



int main()
{
	Color c = green;
	//c = 5;
	cout << sizeof(Color) << endl;
	cout << c << endl;
	return 0;
}