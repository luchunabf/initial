#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

int BinarySearch(const int* arr, int size, int key)
{
	if (nullptr == arr || size < 0)
	{
		assert(0);
		return 0;
	}
	int left = 0;
	int right = size - 1;
	int mid;
	while (left <= right)
	{
		mid = left + ((right - left) >> 1);
		if (key < arr[mid])
			right = mid - 1;
		else if (key > arr[mid])
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}


int main()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << BinarySearch(arr, size, 11) << endl;

	return 0;
}