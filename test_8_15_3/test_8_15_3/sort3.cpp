#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
#include <string.h>
#include <malloc.h>
using namespace std;

void MergeData(int* arr, int left, int mid, int right, int* temp)
{
	int begin1 = left, end1 = mid;
	int begin2 = mid, end2 = right;
	int Index = left;
	//其实就是三个while，第一个里面归并重合部分，后两个只走一个while，归并长出来的
	while (begin1 < end1 && begin2 < end2)
	{
		if (arr[begin1] < arr[begin2])
			temp[Index++] = arr[begin1++];
		else
			temp[Index++] = arr[begin2++];
	}

	while (begin1 < end1)
		temp[Index++] = arr[begin1++];
	while (begin2 < end2)
		temp[Index++] = arr[begin2++];
}

void _MergeSort(int* arr, int left,  int right, int* temp)
{
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
	int* temp = (int*)malloc(sizeof(int)*size);
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
	int arr[] = { 5, 1, 2, 9, 8, 4, 3, 7, 6, 0, 2, 8, 4, 5, 68, 71, 24, 65, 84, 34, 19, 22, 0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, len);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}
