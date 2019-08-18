#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

template<class T>
T BinarySearch(vector<T> v, T val)
{
	T left = 0;
	T right = v.size() - 1;
	
	while (left < right)
	{
		T mid = left + ((right - left) >> 1);
		if (v[mid] == val)
			return mid;
		else if (v[mid] < val)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}
int main()
{
	vector<int> v{  1, 2, 3, 4, 5, 6, 7, 8, 9 };
	cout << BinarySearch(v, 3) << endl;
	return 0;
}

