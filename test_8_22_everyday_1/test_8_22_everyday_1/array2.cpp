#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		vector<int> v;
		v.resize(256);
		//int Flag = 0;
		for (int i = 0; i < numbers.size(); ++i)
		{
			v[numbers[i]] += 1;
			if (v[numbers[i]] >(numbers.size() / 2))
			{
				//Flag = 1;
				return numbers[i];
				break;
			}
		}
		//if(Flag == 0)
		return 0;
	}
};

int main()
{
	vector<int> v{ 5, 3, 7, 8, 9, 5, 1, 2, 2, 2, 2, 2, 2, 2 };
	Solution s;
	s.MoreThanHalfNum_Solution(v);
	return 0;
}