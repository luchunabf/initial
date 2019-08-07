#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void SelectSort(int* arr, int size)//其实是找i到末尾这个区间的最小值，然后放到i的位置处
{
	for (int i = 0; i < size - 1; ++i)
	{
		int minpos = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[j] < arr[minpos])
				minpos = j;
		}
		if (minpos != i)
		{
			Swap(&arr[minpos], &arr[i]);
		}
	}
}

void AdjustDown(int* arr, int size, int parent)
{
	int child = parent * 2 + 1;
	if (parent < size)
	{
		while (child < size)
		{
			if (child + 1 < size && arr[child] < arr[child + 1])
				child += 1;
			if (arr[parent] < arr[child])
			{
				Swap(&arr[parent], &arr[child]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				return;
		}
	}
}
void HeapSort(int* arr, int size)
{
	for (int nleaf = (size - 2) >> 1; nleaf >= 0; --nleaf)
		AdjustDown(arr, size, nleaf);
	for (int i = size - 1; i >= 0; --i)
	{
		Swap(&arr[0], &arr[i]);
		//AdjustDown(arr, size, 0);
		AdjustDown(arr, i, 0);//错误之处，这里i不能传成size【注意】
	}
}

int main()
{
	int arr[10] = { 5, 1, 8, 3, 9, 6, 7, 4, 2, 0 };
	//insertsort(arr, 10);
	//shellsort(arr, 10);
	//bubblesort(arr, 10);
	//SelectSort(arr, 10);
	HeapSort(arr, 10);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}