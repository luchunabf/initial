#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
using namespace std;

int sum(int a)
{
	int b = 0;
	static int c = 3;//��̬����֮��ʼ��һ�Σ����涼���������������
	b += 1;
	c += 2;
	return a + b + c;
}



int main()
{
	for (int i = 0; i < 5; ++i)
	{
		printf("%d\n", sum(i));
	}
	return 0;
}