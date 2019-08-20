#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;
void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void AdjustDown(int* arr, int size, int parent)
{
	assert(arr);
	int child = parent * 2 + 1;
	if (parent < size)
	{
		while (child < size)
		{
			if (child + 1 < size && arr[child] < arr[child + 1])
				child++;
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

void HeapSort(int* arr, int size)
{
	assert(arr);
	int nleaf = (size - 2) >> 1;
	for (int i = nleaf; i >= 0; --i)
	{
		AdjustDown(arr, size, i);
	}
	for (int j = size - 1; j >= 0; --j)
	{
		Swap(arr[j], arr[0]);
		AdjustDown(arr, j, 0);
	}
}
int main()
{
	int arr[] = { 5, 4, 3, 7, 9, 1, 6, 8, 2, 4, 0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, len);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}