#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void AdjustDown(int* arr, int size, int parent)
{
	int child = parent * 2 + 1;//´Ó0¿ªÊ¼
	if (parent < size)
	{
		while (child < size)
		{
			if (child + 1 < size && arr[child] > arr[child + 1])
				child += 1;
			if (arr[parent] > arr[child])
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
	for (int nleaf = (size - 2) >> 1; nleaf >= 0; --nleaf)
		AdjustDown(arr, size, nleaf);
	for (int i = size - 1; i >= 0; --i)
	{
		Swap(&arr[0], &arr[i]);
		AdjustDown(arr, i, 0);
	}
}

int main()
{
	int arr[10] = { 5, 1, 8, 3, 9, 6, 7, 4, 2, 0 };
	//InsertSort(arr, 10);
	//ShellSort(arr, 10);
	//BubbleSort(arr, 10);
	//selectsort(arr, 10);
	HeapSort(arr, 10);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}