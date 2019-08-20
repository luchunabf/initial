#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;
void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void SelectSort(int* arr, int size)
{
	assert(arr);
	for (int i = 0; i < size - 1; ++i)
	{
		int minpos = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[j] < arr[minpos])
				minpos = j;			
		}
		if (minpos != i)
			Swap(arr[minpos], arr[i]);
	}
}
int main()
{
	int arr[] = { 5, 4, 3, 7, 9, 1, 6, 8, 2, 4, 0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, len);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}