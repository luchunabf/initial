#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <assert.h>
#include <iostream>
using namespace std;
//��ʶ�Դ���:Ҫ���Ӻ����м������鳤�ȣ���������������Ҫ������
int fib(int* arr)
{
	int len = sizeof(arr);
	int ele = sizeof(arr[0]);
	return len / ele;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int ret = fib(arr);
	cout << ret;
	return 0;
}