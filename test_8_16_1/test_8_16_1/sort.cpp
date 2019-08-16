#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;

void MergeData(int* arr, int left, int mid, int right, int* temp)
{
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
	if (right - left > 1)
	{
		int mid = left + ((right - left) >> 1);
		_MergeSort(arr, left, mid, temp);
		_MergeSort(arr, mid, right, temp);
		MergeData(arr, left, mid, right, temp);
		memcpy(arr + left, temp + left, sizeof(int)*(right - left));
	}
}
void MergeSort(int* arr, int size)
{
	int* temp = (int*)malloc(sizeof(int) * size);
	if (nullptr == temp || nullptr == arr || size < 0)
	{
		assert(0);
		return;
	}
	_MergeSort(arr, 0, size, temp);
	free(temp);
}


void MergeSortNor(int* arr, int size)
{
	int* temp = (int*)malloc(sizeof(int)*size);
	if (nullptr == temp || nullptr == arr || size < 0)
	{
		assert(0);
		return;
	}
	int gap = 1;
	while (gap < size)
	{
		for (int i = 0; i < size; i += gap * 2)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;
			if (mid > size)
				mid = size;
			if (right > size)
				right = size;
			MergeData(arr, left, mid, right, temp);
		}
		memcpy(arr, temp, sizeof(int)* size);
		gap *= 2;
	}
	
	free(temp);
}



int main()
{
	int arr[] = { 5, 6, 8, 7, 1, 9, 23, 4, 1, 5, 87, 6, 59, 87, 11, 44, 22, 33, 67, 49, 35, 0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	//MergeSort(arr, len);
	MergeSortNor(arr, len);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}