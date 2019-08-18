#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}



//三数取中法：寻找left mid right 的（数组）中间数
int GetMiddleIndex(int* array, int left, int right)
{
	int mid = left + ((right - left) >> 1);//left mid right 其中mid是left 和 right 的平均值
	if (array[left] < array[right - 1])//其实就是三个数之间比大小，return中间大小的那个数
	{
		if (array[mid] < array[left])//比左小，说明left是中间数
			return left;
		else if (array[mid] > array[right - 1])//比右大， 说明right - 1 是中间数 
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

int Partion(int* array, int left, int right) //返回值是key的下标（begin和end 重合处）
{
	int begin = left;
	int end = right - 1;
	int mid = GetMiddleIndex(array, left, right);
	Swap(&array[mid], &array[right - 1]);//三数取中法优化后将中间数放于数组末尾right-1处

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
			Swap(&array[begin], &array[end]);//这里交换的是begin和end下标对应的数组元素的交换，并不影响begin和end的位置
	}
	//走出循环以后begin和end必相等	重要：因为begin先走，而end后走,故当begin与end重合时，也就是出循环时，begin必定落在end上，
	//而此时end在比key大的区间的第一个元素处，然后就可以直接将重合的这个位置和key交换，就可以达到用基准值key将数组分为[左比其小][右比其大]的两个区间
	if (begin != right - 1)//将基准值放于begin和end的重合处
		Swap(&array[begin], &array[right - 1]);

	return begin;
}

#if 1
//非递归实现快排
//#include "stack.h"
void QuickSortNor(int* array, int size)
{
	int left = 0;
	int right = size;
	stack s;
	stackInit(&s);
	stackPush(&s, right);
	stackPush(&s, left);

	while (!stackEmpty(&s))
	{
		left = stackTop(&s);
		stackPop(&s);
		right = stackTop(&s);
		stackPop(&s);

		if (right - left > 1)
		{
			int div = Partion(array, left, right);

			// 保存右半部分区间
			stackPush(&s, right);
			stackPush(&s, div + 1);

			// 保存左半部分区间
			stackPush(&s, div);
			stackPush(&s, left);
		}
	}
}
#endif





int main()
{
	int arr[] = { 3, 4, 2, 9, 1, 7, 6, 0, 8, 5 };
	QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		printf("%d ", arr[i]);
	printf("\n");
	system("pause");
	return 0;
}
