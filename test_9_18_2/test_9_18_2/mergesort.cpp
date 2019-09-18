#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
using namespace std;

void MergeData(int* arr, int left, int mid, int right, int* temp)
{
	int begin1 = left, end1 = mid;
	int begin2 = mid, end2 = right;
	//int index = 0;/////////////////自己错误之处，不能写成0，写0则写死了，导致不能递归
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
	int* temp = (int*)malloc(sizeof(int)*size);
	if (nullptr == temp)
	{
		assert(0);
		return;
	}
	_MergeSort(arr, 0, size, temp);
	free(temp);
	temp = nullptr;
}

int main()
{
	int arr[] = { 5, 4, 7, 9, 8, 1, 3, 0, 2, 6 };
	MergeSort(arr, 10);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}