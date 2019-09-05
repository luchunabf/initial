#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int> v, int key)
{
	if (v.empty())
		return -1;
	int left = 0; 
	int right = v.size() - 1;////////
	int mid;
	while (left <= right)///////
	{
		mid = left + ((right - left) >> 1);
		if (key < v[mid])
			right = mid - 1;
		else if (key > v[mid])
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}

int main()
{
	vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int ret = BinarySearch(v, 7);
	cout << ret << endl;
	return 0;
}