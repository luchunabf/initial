#define _CRT_SECURE_NO_WARNINGS 1
#include <stack>
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
	vector<int> sortArray(vector<int>& nums) {
		int left = 0;
		int right = nums.size();
		stack<int> s;
		s.push(right);
		s.push(left);
		while (!s.empty())
		{
			left = s.top();
			s.pop();
			right = s.top();
			s.pop();

			if (right - left > 1)
			{
				int div = partion(nums, left, right);

				s.push(right);
				s.push(div + 1);

				s.push(div);
				s.push(left);

			}
		}

		return nums;
	}
};

int main()
{
	//vector<int> v{ 3, -1 };
	vector<int> v{ 3, -1 ,54,37,9,46,7,34,0,24,54,87,64,37,18,97,11,35,66,442,54,87};
	Solution s;
	s.sortArray(v);
	for (auto e : v)
		cout << e << " ";
	cout << endl;
	return 0;
}