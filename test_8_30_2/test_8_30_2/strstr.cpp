#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
//I
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		int index1 = 0;
		int index2 = 0;
		int index = index1;
		while (index1 != haystack.size() && index2 != needle.size())
		{

			while (index1 < haystack.size() && index2 < needle.size() && haystack[index1] == needle[index2])
			{
				index1++;
				index2++;
			}
			if (index2 == needle.size()) return index;
			if (index1 == haystack.size() && index2 != needle.size()) return -1;

			index++;
			index1 = index;
			index2 = 0;

		}
		return -1;
	}
};

int main()
{
	Solution s;
	string s1 = "abcdabbacd";
	string s2 = "abba";
	cout << s.strStr(s1, s2);
	return 0;
}


#if 0
//answer
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		int pos = haystack.find(needle);
		return pos;
	}
};
#endif