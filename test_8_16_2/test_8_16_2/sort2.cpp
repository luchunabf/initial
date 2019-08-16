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
int GetMidIndex(int* arr, int left, int right)
{
	if (nullptr == arr || left > right || left < 0)
	{
		assert(0);
		return 0;
	}
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
	if (right > left)
	{
		int div = partion(arr, left, right);
		QuickSort(arr, left, div);
		QuickSort(arr, div + 1, right);
	}

}

int main()
{
	int arr[] = { 3, 4, 2, 9, 1, 7, 6, 0, 8, 5 };
	QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]));
	for (auto e : arr)
		cout << e << " ";
	cout << endl;


	return 0;
}
