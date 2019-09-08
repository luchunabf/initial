#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

void AdjustDown(int* arr, int size, int parent)
{
	if (nullptr == arr)
	{
		assert(0);
		return;
	}
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && arr[child + 1] < arr[child])
			child += 1;
		if (arr[parent] > arr[child])
		{
			swap(arr[parent], arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}

void HeapSort(int* arr, int size)
{
	int LastNotLeaf = ((size - 2) >> 1);
	for (int i = LastNotLeaf; i >= 0; --i)
		AdjustDown(arr, size, i);
	for (int i = size - 1; i >= 0; --i)
	{
		swap(arr[0], arr[i]);
		AdjustDown(arr, i, 0);
	}
}
int main()
{
	int arr[] = { 5, 3, 8, 7, 9, 4, 6, 1, 8, 2, 0 };
	int lenth = sizeof(arr) / sizeof(arr[0]);
	cout << "before sort:" << endl;
	for (auto e : arr)
		cout << e << "-->";
	cout << endl;
	cout << "after sort:" << endl;
	HeapSort(arr, lenth);
	for (auto e : arr)
		cout << e << "-->";
	cout << endl;
	return 0;
}