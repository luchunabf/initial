#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void Shellsort(int* arr, int size)
{
	for (int gap = size / 3 + 1; gap >= 1; --gap)
	{
		for (int i = gap; i < size; ++i)
		{
			int key = arr[i];
			int end = i - gap;
			while (end >= 0 && key < arr[end])
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = key;//加深记忆，该代码于多层循环的位置
		}
	}
}
int main()
{
	int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	Shellsort(arr, 10);
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
	return 0;
}