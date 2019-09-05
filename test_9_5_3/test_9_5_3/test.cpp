#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>

//程序虽然不会崩溃，但是达不到想要的答案。数组传参会退化成指针
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