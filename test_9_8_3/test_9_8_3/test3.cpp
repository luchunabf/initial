#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>
using namespace std;


int main()
{
	int arr[] = { 5, 3, 8, 7, 9, 4, 6, 1, 8, 2, 0 };
	int lenth = sizeof(arr) / sizeof(arr[0]);
	cout << "before sort:" << endl;
	for (auto e : arr)
		cout << e << "-->";
	cout << endl;
	cout << "after sort:" << endl;
	//HeapSort(arr, lenth);
	//sort(arr, arr + lenth, less<int>());
	//sort(arr, arr + lenth, greater<int>());
	//sort(arr, arr + lenth);
	for (auto e : arr)
		cout << e << "-->";
	cout << endl;
	return 0;
}