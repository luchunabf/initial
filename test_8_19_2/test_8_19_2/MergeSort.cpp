#define _CRT_SECURE_NO_WARNINGS 1
#include <assert.h>
#include <iostream>
using namespace std;
void MergeData(int* arr, int left, int mid, int right, int* temp)
{
	assert(arr);
	int begin1 = left, end1 = mid;
	int begin2 = mid, end2 = right;
	int index = left;
	while (begin1 < end1 && begin2 < end2)
	{
		if (arr[begin1] < arr[begin2])
			temp[index++] = arr[begin1++];
		else
			temp[index++] = arr[begin2++];
	}
	while (begin1 < end1)
		temp[index++] = arr[begin1++];
	while (begin2 < end2)
		temp[index++] = arr[begin2++];
}
void _MergeSort(int* arr, int left, int right, int* temp)
{
	assert(arr);
	if (right - left > 1)
	{
		int mid = left + ((right - left) >> 1);
		_MergeSort(arr, left, mid, temp);
		_MergeSort(arr, mid, right, temp);
		MergeData(arr, left, mid, right, temp);
		memcpy(arr + left, temp + left, sizeof(int)* (right - left));
	}
}
void MergeSort(int* arr, int size)
{
	assert(arr);
	int* temp = (int*)malloc(sizeof(int)* size);
	if (nullptr == temp)
	{
		assert(0);
		return;
	}
	_MergeSort(arr, 0, size, temp);
	free(temp);
}

int main()
{
	int arr[] = { 58, 99, 21, 64, 74, 21, 81, 3, 4, 122, 54, 87, 51, 35, 98, 45, 21, 33, 100, 24, 67 };
	int len = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, len);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}