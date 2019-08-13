#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;
const void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}


const void SelectSort(int* arr, const int size)
{
	assert(arr);
	for (int i = 0; i < size - 1; i++)
	{
		int minpos = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[j] < arr[minpos])
				minpos = j;
		}
		if (minpos != i)
			Swap(arr[minpos], arr[i]);
	}
}


const void AdjustDown(int* arr, const int size, int parent)
{
	int child = parent * 2 + 1;
	if (parent < size)/////////////////////////这一层着实有点鸡肋（多余）
	{
		while (child < size)
		{
			if (child + 1 < size && arr[child] < arr[child + 1])
				child += 1;
			if (arr[parent] < arr[child])
			{
				Swap(arr[parent], arr[child]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				return;
		}
	}
}
const void HeapSort(int* arr, const int size)
{
	int nleaf = (size - 2) >> 1;
	for (int i = nleaf; i >= 0; --i)
		AdjustDown(arr, size, i);
	for (int j = size - 1; j >= 0; --j)
	{
		Swap(arr[j], arr[0]);
		AdjustDown(arr, j, 0);
	}
}

int main()
{
	int arr[] = { 5, 7, 6, 2, 9, 8, 1, 3, 0 ,4 };
	//SelectSort(arr, 10);
	HeapSort(arr, 10);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}