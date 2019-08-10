#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
#if 0
void SelsectSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; ++i)//选择排序和冒泡排序的外循环次数一样
	{
		int minpos = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[j] < arr[minpos])
				minpos = j;
		}
		if (minpos != i)
			Swap(&arr[minpos], &arr[i]);
	}
}
#endif

void AdjustDown(int* arr, int size, int parent)
{
	int child = parent * 2 + 1;
	if (parent < size)/////////////////////////////if/while?,if记牢
	{
		while (child < size)
		{
			if (child + 1 < size && arr[child] < arr[child + 1])
				child += 1;
			if (arr[parent] < arr[child])
			{
				Swap(&arr[parent], &arr[child]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				return;
		}
	}
}
void HeapSort(int* arr, int size)
{
	int nleaf = (size - 2) >> 1;
	for (int i = nleaf; i >= 0; --i)
		AdjustDown(arr, size, i);
	for (int j = size - 1; j >= 0; --j)
	{
		Swap(&arr[j], &arr[0]);
		AdjustDown(arr, j, 0);
	}
}

int main()
{
	int arr[10] = { 5, 9, 3, 2, 6, 4, 8, 1, 0, 7 };
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	//SelsectSort(arr, 10);
	HeapSort(arr, 10);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}