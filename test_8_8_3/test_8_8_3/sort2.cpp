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
void SelectSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; ++i)
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
int main()
{
	int arr[10] = { 5, 3, 7, 6, 9, 4, 1, 0, 2, 8 };
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	SelectSort(arr, 10);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}


void SelectSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; ++i)
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
int main()
{
	int arr[10] = { 5, 3, 7, 6, 9, 4, 1, 0, 2, 8 };
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	SelectSort(arr, 10);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}


void SelectSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; ++i)
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
int main()
{
	int arr[10] = { 5, 3, 7, 6, 9, 4, 1, 0, 2, 8 };
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	SelectSort(arr, 10);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}


void SelectSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; ++i)
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
int main()
{
	int arr[10] = { 5, 3, 7, 6, 9, 4, 1, 0, 2, 8 };
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	SelectSort(arr, 10);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}


void AdjustDown(int* arr, int size, int parent)
{
	int child = parent * 2 + 1;
	if (parent < size)
	{
		while (child < size)
		{
			if (child + 1 < size && arr[child] < arr[child + 1])
				child++;
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
	int arr[10] = { 5, 3, 7, 6, 9, 4, 1, 0, 2, 8 };
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	HeapSort(arr, 10);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}
#endif

void AdjustDown(int* arr, int size, int parent)
{
	int child = parent * 2 + 1;
	if (parent < size)
	{
		while (child < size)
		{
			if (child + 1 < size && arr[child] < arr[child + 1])
				child++;
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
	int arr[10] = { 5, 3, 7, 6, 9, 4, 1, 0, 2, 8 };
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	HeapSort(arr, 10);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}