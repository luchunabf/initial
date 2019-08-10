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
void AdjustDown(int* arr, int size, int parent)
{
	int child = parent * 2 + 1;
	if (parent < size)
	{
		while (child < size)/////////////////注意这层循环，别再忘了
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
#endif

void InsertSort(int* arr, int size);
int GetMidIndex(int* arr, int left, int right)
{
	int mid = left + ((right - left) >> 1);/////////////////////?
	if (arr[left] < arr[right - 1])
	{
		if (arr[mid] < arr[left])
			return left;
		else if (arr[mid] > arr[right - 1])
			return right - 1;
		else
			return mid;
	}
	else
	{
		if (arr[mid] > arr[left])
			return left;
		else if (arr[mid] < arr[right - 1])
			return right - 1;
		else
			return mid;
	}
}
int partion(int* arr, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int mid = GetMidIndex(arr, left, right);//////////传right，不是right - 1
	Swap(&arr[mid], &arr[right - 1]);

	int key = arr[right - 1];
	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)
			begin++;
		while (begin < end && arr[end] >= key)
			end--;
		if (begin != end)
			Swap(&arr[begin], &arr[end]);
	}
	if (begin != right - 1)
		Swap(&arr[begin], &arr[right - 1]);
	return begin;
}
void QuickSort(int* arr, int left, int right)
{
	if (right - left < 5)
		InsertSort(arr, right - left);
	else
	{
		int div = partion(arr, left, right);
		QuickSort(arr, 0, div);
		QuickSort(arr, div + 1, right);
	}
}
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

int main()
{
	int arr[10] = { 5, 3, 6, 8, 4, 2, 7, 9, 1, 0 };
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	//HeapSort(arr, 10);
	QuickSort(arr, 0, 10);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}