#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
void Insertsort(int* arr, int size)
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
	int arr[] = { 5, 9, 8, 7, 6, 1, 2, 3, 4, 7, 8, 5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Insertsort(arr, len);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}