#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;
const void InsertSort(int* arr, const int size)
{
	assert(arr != nullptr);
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
const void ShellSort(int* arr, const int size)
{
	assert(arr);
	int gap = size / 3 + 1;
	for (; gap >= 1; --gap)
	{
		for (int i = gap; i < size; ++i)
		{
			int key = arr[i];
			int end = i - gap;
			while (end >= 0 && arr[end] > key)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = key;
		}
	}
}
int main()
{
	int arr[] = { 5, 7, 6, 2, 9, 8, 1, 3, 4, 0 };
	//InsertSort(arr, 10);
	ShellSort(arr, 10);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}