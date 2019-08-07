#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void selectsort(int* arr, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		int minpos = i;
		for (int j = i + 1; j <= size - 1; ++j)
		{
			if (arr[j] < arr[minpos])
			{
				//int tmp = arr[j];
				//arr[j] = arr[minpos];
				//arr[minpos] = tmp;
				minpos = j;
			}
		}
		if (minpos != i)
		{
			int temp = arr[minpos];
			arr[minpos] = arr[i];
			arr[i] = temp;
		}
	}
}
int main()
{
	int arr[10] = { 5, 1, 8, 3, 9, 6, 7, 4, 2, 0 };
	//insertsort(arr, 10);
	//shellsort(arr, 10);
	//bubblesort(arr, 10);
	selectsort(arr, 10);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}