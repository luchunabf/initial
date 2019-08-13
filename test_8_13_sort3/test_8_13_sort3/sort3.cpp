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
const void BubbleSort(int* arr, const int size)
{
	assert(arr);
	for (int i = 0; i < size - 1; i++)
	{
		int Flag = 0;
		for (int j = 0; j < size - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr[j], arr[j + 1]);
				Flag = 1;
			}
		}
		if (Flag == 0)
			return;
	}
}

int GetMidIndex(int* arr, int left,/* int mid,*/ int right)//三数取中法不用传mid！！！！！！！！！！
{
	assert(arr);
	int mid = (right - left) >> 1;//只有这里right不用-1
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

int partion(int* arr, int left,  int right)
{
	int begin = left;
	int end = right - 1;
	int mid = GetMidIndex(arr, left, right);
	Swap(arr[mid],arr[right - 1]);

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

void QuickSort(int* arr, int size)
{

	int div = partion(arr, 0, size);
	partion(arr, 0, div);
	partion(arr, div + 1, size);
}











int main()
{
	int arr[] = { 5, 7, 6, 2, 9, 8, 4, 1, 3, 0 };
	//BubbleSort(arr, 10);
	QuickSort(arr, 10);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}