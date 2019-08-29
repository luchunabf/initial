#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <iostream>
using namespace std;

void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 1) return nums.size();
		if (nums.size() == 2)
		{
			if (nums[0] == nums[1]) return 1;
			else
				return 2;
		}
		int index1 = 1;
		while ((index1 < nums.size()) && nums[index1] != nums[index1 - 1]) index1++;
		if (index1 == nums.size()) return nums.size();
		int key = nums[index1];
		int index2 = index1 + 1;

		while (index2 < nums.size())
		{
			while (index2 < nums.size() && nums[index2] == key)
				index2++;
			if (index2 == nums.size()) return index1;
			key = nums[index2];
			Swap(nums[index1], nums[index2]);
			index1++;
			index2++;
		}
		return index1;

	}
};
int main()
{
	vector<int> v{ 1, 2, 3 };
	Solution s;
	cout << s.removeDuplicates(v);
	return 0;
}