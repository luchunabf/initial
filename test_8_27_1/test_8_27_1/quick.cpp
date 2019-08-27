#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	void Swap(int& a, int& b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	int GetMidIndex(vector<int>& v, int left, int right)
	{
		int mid = left + ((right - left) >> 1);
		if (v[left] < v[right - 1])
		{
			if (v[mid] < v[left])
				return left;
			else if (v[mid] > v[right - 1])
				return right - 1;
			else
				return mid;
		}
		else
		{
			if (v[mid] > v[left])
				return left;
			else if (v[mid] < v[right - 1])
				return right - 1;
			else
				return mid;
		}
	}
	int partion(vector<int>& v, int left, int right)
	{
		int begin = left;
		int end = right - 1;
		int mid = GetMidIndex(v, left, right);
		Swap(v[mid], v[right - 1]);
		int key = v[right - 1];
		while (begin < end)
		{
			while (begin < end && v[begin] <= key)
				begin++;
			while (begin < end && v[end] >= key)
				end--;
			if (begin != end)
				Swap(v[begin], v[end]);
		}
		if (begin != right - 1)
			Swap(v[begin], v[right - 1]);
		return begin;
	}
	void Quicksort(vector<int>& nums, int left, int right)
	{
		if (right - left > 1)
		{
			int div = partion(nums, left, right);
			Quicksort(nums, 0, div);
			Quicksort(nums, div + 1, right);
		}
	}
	vector<int> sortArray(vector<int>& nums) {
		int left = 0;
		int right = nums.size();
		Quicksort(nums, left, right);
		return nums;
	}
};

int main()
{
	Solution a;
	vector<int> v{ 5, 9, 8, 7, 6 };
	vector<int> v1{ 3, -1};
	a.sortArray(v);

	a.sortArray(v1);
	return 0;
}