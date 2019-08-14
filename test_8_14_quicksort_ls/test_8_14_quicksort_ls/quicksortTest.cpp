#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//void Swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//void  InsertSort(int* arr, int size)
//{
//	for (int i = 1; i < size; ++i)
//	{
//		int key = arr[i];
//		int end = i - 1;
//		while (end >= 0 && arr[end] > key)
//		{
//			arr[end + 1] = arr[end];
//			end--;
//		}
//		arr[end + 1] = key;
//	}
//}


void PrintArray(int* array, int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");
}

void Swap(int* pLeft, int* pRight)
{
	int temp = *pLeft;
	*pLeft = *pRight;
	*pRight = temp;
}

void InsertSort(int* array, int left, int right)
{
	for (int i = left + 1; i < right; ++i)
	{
		// 待插入元素
		int key = array[i];

		// 找key的插入位置：与前面已经排序好的元素从后往前比较
		int end = i - 1;
		while (end >= 0 && key < array[end])
		{
			array[end + 1] = array[end];
			end -= 1;
		}

		// 插入元素
		array[end + 1] = key;
	}
}

int GetMiddleIndex(int* array, int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (array[left] < array[right - 1])
	{
		if (array[mid] < array[left])
			return left;
		else if (array[mid] > array[right - 1])
			return right - 1;
		else
			return mid;
	}
	else
	{
		if (array[mid] > array[left])
			return left;
		else if (array[mid] < array[right - 1])
			return right - 1;
		else
			return mid;
	}
}

// [left, right)
int Partion1(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int mid = GetMiddleIndex(array, left, right);
	Swap(&array[mid], &array[right - 1]);

	int key = array[right - 1];

	while (begin < end)
	{
		// 从左往右找比基准值大的元素，找到之后停止
		while (begin < end && array[begin] <= key)
			begin++;

		// 从右往左找比基准值小的元素，找到之后停止
		while (begin < end && array[end] >= key)
			end--;

		if (begin != end)
			Swap(&array[begin], &array[end]);
	}

	if (begin != right - 1)
		Swap(&array[begin], &array[right - 1]);

	return begin;
}

int Partion2(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int mid = GetMiddleIndex(array, left, right);
	Swap(&array[mid], &array[right - 1]);

	int key = array[right - 1];

	while (begin < end)
	{
		// 从前往后找比基准值大的元素，找到后填充end位置的坑
		while (begin < end && array[begin] <= key)
			begin++;

		// 填充end位置的坑
		if (begin < end)
		{
			array[end] = array[begin];
			end--;
		}

		// 从后往前找比基准值小的元素，找到后填充begin位置的坑
		while (begin < end && array[end] >= key)
			end--;

		if (begin < end)
		{
			array[begin] = array[end];
			begin++;
		}
	}

	array[begin] = key;
	return begin;
}

int Partion3(int* array, int left, int right)
{
	int cur = left;
	int prev = cur - 1;
	int mid = GetMiddleIndex(array, left, right);
	Swap(&array[mid], &array[right - 1]);
	int key = array[right - 1];


	while (cur < right)
	{
		if (array[cur] < key && ++prev != cur)
			Swap(&array[cur], &array[prev]);

		++cur;
	}

	if (++prev != right)
		Swap(&array[prev], &array[right - 1]);

	return prev;
}

void QuickSort(int* array, int left, int right)
{

	if ((right - left) < 16)
		//InsertSort(array, right - left);
		InsertSort(array, left, right);//此时要用到递归，当下面第二层的QuickSort(array, div + 1, right);传来时，必须区分left，right
									   //否则，要是直接传两个参数，第二个参数按照(right - left)传参时
									   //插入排序中默认按照下标全从0开始到right - left
									   //这时，排序的话会出错，后半段排不进去插入排序而直接出递归
									   //所以，必须在插入排序(InsertSort)中指明要传的区间left，right.
	else
	{
		// 按照基准值将区间分割成左右两部分
		// 左侧小于基准值 基准值 右侧大于基准值
		int div = Partion1(array, left, right);
		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}

	//if (right - left > 1)
	//{
	//	int div = Partion1(array, left, right);
	//	QuickSort(array, left, div);
	//	QuickSort(array, div + 1, right);
	//}


	//int div;
	//if (right - left > 16)
	//{
	//	div = Partion1(array, left, right);
	//	QuickSort(array, left, div);
	//	QuickSort(array, div + 1, right);
	//}
	//else
	//	InsertSort(array, right - left);
}
#include <string.h>
int main()
{
	int arr[] = { 5, 6, 7, 3, 9, 1, 2, 0, 4, 8, 22, 99, 66, 88, 55, 77, 33, 44, 11, 12, 56, 98, 74, 29, 31 };
	int len = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, len);
	//for (auto e : arr)
	//	cout << e << " ";
	PrintArray(arr,len);
	cout << endl;
	return 0;
}