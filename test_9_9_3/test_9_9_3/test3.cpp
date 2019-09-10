#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#if 0
void InsertSort(int* arr, int size)
{
	for (int i = size - 1; i >= 0; --i)
	{
		int key = arr[i];
		int begin = i + 1;
		while (begin < size && arr[begin] < key)
		{
			arr[begin - 1] = arr[begin];
			begin++;
		}
		arr[begin - 1] = key;
	}
}
#endif

void InsertSort(int* arr, int size)
{
	for (int i = 1; i < size; ++i)
	{
		int key = arr[i];
		int end = i - 1;
		while (end >= 0 && arr[end] < key)
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = key;
	}
}
int main()
{
	int arr[] = { 5, 1, 3, 4, 9, 7, 8, 2, 6, 0 };
	InsertSort(arr, 10);
	for (auto e : arr)
		cout << e << "-->";
	cout << endl;
	return 0;
}