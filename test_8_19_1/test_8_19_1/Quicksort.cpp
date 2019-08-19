#define _CRT_SECURE_NO_WARNINGS 1
#include <assert.h>
#include <iostream>
using namespace std;
void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void InsertSort(int* arr, int left, int right)
{
	for (int i = left + 1; i < right; ++i)
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
int GetMidIndex(int* arr, int left, int right)
{
	int mid = left + ((right - left) >> 1);
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
	int mid = GetMidIndex(arr, left, right);
	Swap(arr[mid], arr[right - 1]);

	int key = arr[right - 1];
	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)
			begin++;
		while (begin < end && arr[end] >= key)
			end--;
		if (begin != end)
			Swap(arr[begin], arr[end]);
	}
	if (begin != right - 1)
		Swap(arr[begin], arr[right - 1]);
	return begin;	
}
void QuickSort(int* arr, int left, int right)
{
	//assert(arr);
	if (right - left < 16)
		InsertSort(arr, left, right);
	else
	{
		int div = partion(arr, left, right);
		QuickSort(arr, left, div);
		QuickSort(arr, div + 1, right);
	}
}
int main()
{
	int arr[] = { 58, 99, 21, 64, 74, 21, 81, 3, 4, 122, 54, 87, 51, 35, 98, 45, 21, 33, 100, 24, 67 };
	int len = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, len);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}