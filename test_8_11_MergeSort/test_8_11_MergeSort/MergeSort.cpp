#define _CRT_SECURE_NO_WARNINGS 1
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <iostream>
using namespace std;
//1.归并
void MergeData(int* arr, int left, int mid, int right, int* tmp)
{
	int begin1 = left, end1 = mid;
	int begin2 = mid, end2 = right;
	int index = left;
	while (begin1 < end1 && begin2 < end2)
	{
		if (arr[begin1] < arr[begin2])
			tmp[index++] = arr[begin1++];
		else
			tmp[index++] = arr[begin2++];
	}
	while (begin1 < end1)
		tmp[index++] = arr[begin1++];
	while (begin2 < end2)
		tmp[index++] = arr[begin2++];
}
//2.递归
void _MergeSort(int* arr, int left, int right, int* tmp)
{
	if (right - left > 1)
	{
		int mid = left + ((right - left) >> 1);
		_MergeSort(arr, left, mid, tmp);
		_MergeSort(arr, mid, right, tmp);
		MergeData(arr, left, mid, right, tmp);
		memcpy(arr + left, tmp + left, sizeof(int)*(right - left));//注意arr和tmp的相对位置
		//memcpy(tmp + left, arr + left, sizeof(int)*(right - left));//注意arr和tmp的相对位置
	}
}
//3.封装
void MergeSort(int* arr, int size)
{
	assert(1);
	//assert((size <= (sizeof(arr) / sizeof(arr[0]))));//在这里断言以下size，不能大于数组arr长度，越界
	int* tmp = (int*)malloc(sizeof(int)* size);
	if (nullptr == tmp)
	{
		assert(0);
		return;
	}
	_MergeSort(arr, 0, size, tmp);//加一个0

	free(tmp);
}

//非递归
void MergeSortNor(int* arr, int size)
{
	/*int len = sizeof(arr) / sizeof(arr[0]);
	if (size > len)
	{
	assert(0);
	return;
	}*/

	//assert((size <= (sizeof(arr) / sizeof(arr[0]))));//在这里断言以下size，不能大于数组arr长度，越界
	int* tmp = (int*)malloc(sizeof(int)* size);
	if (nullptr == tmp)
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
			int mid = i + gap;
			int right = mid + gap;
			if (mid >= size)
				mid = size;
			if (right >= size)
				right = size;
			MergeData(arr, left, mid, right, tmp);
		}
		memcpy(arr, tmp, sizeof(int)* size);//每次（全部）拷贝size元素到arr，直到最后一次arr完全有序
											//memcpy( a, b, len);把b给a拷贝len长度（单位：字节）
		gap *= 2;
	}

	free(tmp);
}
int main()
{
	int arr[] = { 5, 6, 8, 9, 1, 3, 7, 4, 2, 0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	MergeSort(arr, 10);//递归
	//MergeSortNor(arr, 10);//非递归
	for (auto e : arr)
		cout << e << " ";
	cout << endl;



	int len1 = sizeof(arr);
	return 0;
}