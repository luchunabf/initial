#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
#include <malloc.h>
using namespace std;

void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
//²åÈë
void InsertSort(int* arr, int size)
{
	if (nullptr == arr || size < 0)
	{
		assert(0);
		return;
	}
	for (int i = 1; i < size; ++i)
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
void InsertSort(int* arr, int left, int right)
{
	if (nullptr == arr || right < left)
	{
		assert(0);
		return;
	}
	for (int i = left + 1; i < right; ++i)//////////////////////////
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
//Ï£¶û
void ShellSort(int* arr, int size)
{
	if (nullptr == arr || size < 0)
	{
		assert(0);
		return;
	}
	int gap = size / 3 + 1;
	for (; gap >= 1; --gap)
	{
		for (int i = gap; i < size; ++i)
		{
			int key = arr[i];
			int end = i - gap;
			while (end >= 0 && arr[end] > key)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = key;
		}
	}
}
//Ñ¡Ôñ
void SelectSort(int* arr, int size)
{
	if (nullptr == arr || size < 0)
	{
		assert(0);
		return;
	}
	for (int i = 0; i < size - 1; i++)
	{
		int minpos = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[minpos] > arr[j])
				minpos = j;
		}
		if (minpos != i)
			Swap(arr[minpos], arr[i]);
	}
}
//¶Ñ
void AdjustDown(int* arr, int size, int parent)
{
	if (nullptr == arr || size < 0 || parent < 0 || parent > size)
	{
		assert(0);
		return;
	}
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && arr[child] < arr[child + 1])
			child++;
		if (arr[parent] < arr[child])
		{
			Swap(arr[parent], arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}
void HeapSort(int* arr, int size)
{
	if (nullptr == arr || size < 0)
	{
		assert(0);
		return;
	}
	int nleaf = (size - 2) >> 1;
	for (int i = nleaf; i >= 0; --i)
		AdjustDown(arr, size, i);
	for (int j = size - 1; j >= 0; --j)
	{
		Swap(arr[j], arr[0]);
		AdjustDown(arr, j, 0);
	}
}
//¿ìÅÅ
int GetMidIndex(int* arr, int left, int right)
{
	if (nullptr == arr || left > right)
	{
		assert(0);
		return -1;
	}
	int mid = left + ((right - left) >> 1);
	if (arr[left] < arr[right - 1])/////////////////
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
	if (nullptr == arr || right < left)
	{
		assert(0);
		return -1;
	}
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
			Swap(arr[begin], arr[end]);
	}
	if (begin != right - 1)
		Swap(arr[begin], arr[right - 1]);/////////////////////
	return begin;
}
void QuickSort(int* arr, int left, int right)
{
	if (nullptr == arr || right < left)
	{
		assert(0);
		return;
	}
	if (right - left < 16)
		InsertSort(arr, left, right);
	else
	{
		int div = partion(arr, left, right);
		QuickSort(arr, left, div);
		QuickSort(arr, div + 1, right);
	}
}
//¹é²¢
void MergeDate(int* arr, int left, int mid, int right, int* temp)
{
	if (nullptr == arr || left > right || nullptr == temp)
	{
		assert(0);
		return;
	}
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
	if (nullptr == arr || left > right || nullptr == temp)
	{
		assert(0);
		return;
	}
	if (right - left > 1)
	{
		int mid = left + ((right - left) >> 1);
		_MergeSort(arr, left, mid, temp);
		_MergeSort(arr, mid, right, temp);
		MergeDate(arr, left, mid, right, temp);
		memcpy(arr + left, temp + left, sizeof(int)*(right - left));
	}
}
void MergeSort(int* arr, int size)
{
	if (nullptr == arr || size < 0)
	{
		assert(0);
		return;
	}
	int* temp = (int*)malloc(sizeof(int)* size);
	if (nullptr == temp)
	{
		assert(0);
		return;
	}
	_MergeSort(arr, 0, size, temp);
	free(temp);
}

void MergeSortNor(int* arr, int size)
{
	if (nullptr == arr || size < 0)
	{
		assert(0);
		return;
	}
	int* temp = (int*)malloc(sizeof(int)* size);
	if (nullptr == temp)
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
			MergeDate(arr, left, mid, right, temp);
		}
		memcpy(arr, temp, sizeof(int)*size);
		gap *= 2;
	}
	
	free(temp);

}


int main()
{
	int arr[] = { 5, 4, 9, 8, 7, 1, 0, 3, 2, 6, 10, 13, 24, 23, 22, 21, 20, 19, 17, 18, 14, 16, 15, 11, 12 };
	int len = sizeof(arr) / sizeof(arr[0]);
	//InsertSort(arr, 0, len);
	//ShellSort(arr, len);
	//SelectSort(arr, len);
	//HeapSort(arr, len);
	//QuickSort(arr, 0, len);
	//MergeSort(arr, len);
	MergeSortNor(arr, len);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}