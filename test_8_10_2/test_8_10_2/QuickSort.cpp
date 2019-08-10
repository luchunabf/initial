#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//快排的所有区间左闭右开
void InsertSort(int* arr, int size);

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int GetMidIndex(int* arr, int left, int right)
{
	int mid = left + ((right - left) >> 1);//////////【仅这里】right要不要-1(其实不重要）：不需要
	if (arr[left] < arr[right-1])///////////////////【这里】是right-1 老是忘
	{
		if (arr[mid] < arr[left])
			return left;
		else if (arr[mid] > arr[right-1])
			return right-1;
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

	int key = arr[right - 1];////////////////key 一般直接取元素，不取下标
	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)// 是<=  别忘了=
			begin++;
		while (begin < end && arr[end] >= key)
			end--;
		if (begin != end)
			Swap(&arr[begin], &arr[end]);//////该交换不影响begin和end下标位置
	}
	if (begin != right - 1)/////////////能出循环则begin和end必重合（begin先走）
		Swap(&arr[begin], &arr[right-1]);

	return begin;////////别再忘了返回值
}
void QuickSort(int* arr, int left, int right)
{
	if (right - left < 16)
		InsertSort(arr, right - left);
	else
	{
		int div = partion(arr, left, right);
		QuickSort(arr, left, div);
		QuickSort(arr, div + 1, right);//不加1也行，就是效率不如加1高，会重复把div的值去比较排序
	}
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

int main()
{
	int arr[10] = { 5, 9, 3, 2, 6, 4, 8, 1, 0, 7 };
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	//SelsectSort(arr, 10);
	//HeapSort(arr, 10);
	QuickSort(arr, 0, 10);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}