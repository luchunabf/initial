#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void InsertSort(int* arr, int size)
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

void ShellSort(int* arr, int size)
{
	for (int gap = size / 3 + 1; gap >= 1; gap--)
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

void BubbleSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		int Flag = 0;
		for (int j = 0; j < size - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				Flag = 1;
			}
		}
		if (Flag == 0)
			return;
	}
}
int main()
{
	int arr[10] = { 5, 1, 8, 3, 9, 6, 7, 4, 2, 0 };
	//InsertSort(arr, 10);
	//ShellSort(arr, 10);
	BubbleSort(arr, 10);
	//selectsort(arr, 10);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}