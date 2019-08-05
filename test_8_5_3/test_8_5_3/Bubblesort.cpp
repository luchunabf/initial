#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void Bubblesort(int* arr, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		int Flag = 0;
		for (int j = 0; j < size - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				Flag = 1;
			}
		}
		if (Flag == 0)
			return;
	}
}

int main()
{
	int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	Bubblesort(arr, 10);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}