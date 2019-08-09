#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void InsertSort(int* arr, int size)
{
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

int GetMidIndex(int* arr, int left, int right)//��סһ��ϸ��
{
	int mid = left + ((right - left) >> 1);
	if (arr[left] < arr[right - 1])
	{
		if (arr[mid] < arr[left])
			return left;
		else if (arr[mid] > arr[right - 1])
			return right - 1;////////////////����ȡ�з������ҵĻ� ���ص���right - 1���μǡ�
		else
			return mid;
	}
	else
	{
		if (arr[mid] > arr[left])
			return left;
		else if (arr[mid] < arr[right-1])
			return right-1;
		else
			return mid;
	}
}

int partion(int* arr, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int mid = GetMidIndex(arr, left, right);
	Swap(&arr[mid], &arr[right - 1]);

	int key = arr[right - 1];////////////////////////�����˰�
	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)
			begin++;
		while (begin < end && arr[end] >= key)
			end--;
		if (begin != end)
			Swap(&arr[begin], &arr[end]);
	}
	if (begin != right - 1)
		Swap(&arr[begin], &arr[right - 1]);

	return begin;
}

void QuickSort(int* arr, int left, int right)
{
	if ((right - left) < 16)
		InsertSort(arr, right - left);
	else
	{
		int div = partion(arr, left, right);
		QuickSort(arr, left, div);
		QuickSort(arr, div + 1, right);
	}
}



int main()
{
	int arr[10] = { 5, 9, 4, 6, 8, 1, 3, 7, 2, 0 };
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	//InsertSort(arr, 10);
	QuickSort(arr, 0, 10);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;

	return 0;
}