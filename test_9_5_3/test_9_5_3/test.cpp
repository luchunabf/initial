#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>

//������Ȼ������������Ǵﲻ����Ҫ�Ĵ𰸡����鴫�λ��˻���ָ��
int Strlen(int* arr)
{
	return sizeof(arr) / sizeof(arr[0]);
}
int main()
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	std::cout << Strlen(arr1);
	return 0;
}