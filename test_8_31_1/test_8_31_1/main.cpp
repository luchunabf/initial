#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void Shellsort(int* arr, int size)
{
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
	int arr[] = { 5, 3, 6, 7, 3, 2, 1, 8, 9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Shellsort(arr, len);
	for (auto e : arr)
		cout << e << " ";
	return 0;
}