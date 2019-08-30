#define _CRT_SECURE_NO_WARNINGS 1
//删除数组中val的值
//我的（复杂）
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int begin = 0;
		int end = nums.size() - 1;
		if (nums.size() == 1)
		{
			if (nums[0] == val)
				return 0;
			else
				return 1;
		}
		while (begin < end)
		{
			while (begin < end && nums[begin] != val)
				begin++;
			while (end >= 0 && nums[end] == val)
				end--;
			if (end == 0 && begin == 0)
				return 0;
			if (begin < end)
			{
				int tmp = nums[begin];
				nums[begin] = nums[end];
				nums[end] = tmp;
			}
		}
		return end + 1;
	}
};
//答案【简单】
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int i = 0;
		for (int j = 0; j < nums.size(); ++j)
		{
			if (nums[j] != val)
			{
				nums[i] = nums[j];
				++i;
			}
		}
		return i;
	}
};