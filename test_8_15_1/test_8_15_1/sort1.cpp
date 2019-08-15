#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void InsertSort1(int* arr, int size)
{
	for (int i = 1; i < size; ++i)
	{
		int key = arr[i];
		int end = i - 1;
		while (end >= 0 && arr[end] > key)
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = key;
	}
}

void InsertSort2(int* arr, int left, int right)
{
	for (int i = left + 1; i < right; ++i)
	{
		int key = arr[i];
		int end = i - 1;
		while (end >= 0 && arr[end] > key)
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = key;
	}
}

int main()
{
	int arr[] = { 5, 3, 2, 8, 7, 4, 9, 6, 1, 0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	//InsertSort1(arr, len);
	InsertSort2(arr, 0, len);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}