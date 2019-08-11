#define _CRT_SECURE_NO_WARNINGS 1
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <iostream>
using namespace std;
//1.�鲢
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
//2.�ݹ�
void _MergeSort(int* arr, int left, int right, int* tmp)
{
	if (right - left > 1)
	{
		int mid = left + ((right - left) >> 1);
		_MergeSort(arr, left, mid, tmp);
		_MergeSort(arr, mid, right, tmp);
		MergeData(arr, left, mid, right, tmp);
		memcpy(arr + left, tmp + left, sizeof(int)*(right - left));//ע��arr��tmp�����λ��
		//memcpy(tmp + left, arr + left, sizeof(int)*(right - left));//ע��arr��tmp�����λ��
	}
}
//3.��װ
void MergeSort(int* arr, int size)
{
	assert(1);
	//assert((size <= (sizeof(arr) / sizeof(arr[0]))));//�������������size�����ܴ�������arr���ȣ�Խ��
	int* tmp = (int*)malloc(sizeof(int)* size);
	if (nullptr == tmp)
	{
		assert(0);
		return;
	}
	_MergeSort(arr, 0, size, tmp);//��һ��0

	free(tmp);
}

//�ǵݹ�
void MergeSortNor(int* arr, int size)
{
	/*int len = sizeof(arr) / sizeof(arr[0]);
	if (size > len)
	{
	assert(0);
	return;
	}*/

	//assert((size <= (sizeof(arr) / sizeof(arr[0]))));//�������������size�����ܴ�������arr���ȣ�Խ��
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
		memcpy(arr, tmp, sizeof(int)* size);//ÿ�Σ�ȫ��������sizeԪ�ص�arr��ֱ�����һ��arr��ȫ����
											//memcpy( a, b, len);��b��a����len���ȣ���λ���ֽڣ�
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
	MergeSort(arr, 10);//�ݹ�
	//MergeSortNor(arr, 10);//�ǵݹ�
	for (auto e : arr)
		cout << e << " ";
	cout << endl;



	int len1 = sizeof(arr);
	return 0;
}