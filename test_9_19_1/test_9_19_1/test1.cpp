#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;

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
		if (arr[mid] < arr[right - 1])
			return right - 1;
		else if (arr[mid] > arr[left])
			return left;
		else
			return mid;
	}
}
int partion(int* arr, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int mid = GetMidIndex(arr, left, right);
	swap(arr[mid], arr[right - 1]);

	int key = arr[right - 1];
	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)
			begin++;
		while (begin < end && arr[end] >= key)
			end--;
		if (begin != end)
			swap(arr[begin], arr[end]);
	}
	if (begin != right - 1)
		swap(arr[begin], arr[right - 1]);

	return begin;
}

void QuickSort(int* arr, int left, int right)
{
	if (right - left > 1)
	{
		int div = partion(arr, left, right);
		QuickSort(arr, left, div);
		QuickSort(arr, div + 1, right);
	}
}


int main()
{
	int arr[] = { 5, 1, 3, 7, 9, 4, 6, 8, 2, 0 };
	QuickSort(arr, 0, 10);

	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}
