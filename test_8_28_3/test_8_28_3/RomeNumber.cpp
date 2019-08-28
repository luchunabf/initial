#define _CRT_SECURE_NO_WARNINGS 1
//罗马数字转数字





//从前往后一个一个遍历， 如果当前字符比后一个字符大或等的话，直接加
//如果当前字符比后一个字符小的话，直接减
//注意这样遍历只能遍历到倒数第二个字符（否则越界），最后一个字符直接加就OK
class Solution {
public:
	int romanToInt(string s) {
		int arr[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
		int arr1[] = { 1, 5, 10, 50, 100, 500, 1000 };
		int x = 0;
		for (int i = 0; i < s.size() - 1; ++i)
		{
			int m = 0, n = 0;
			while (s[i] != arr[m]) m++;
			while (s[i + 1] != arr[n]) n++;
			if (m >= n)
				x += arr1[m];
			else
				x -= arr1[m];
		}
		int m = 0;
		while (s[s.size() - 1] != arr[m]) m++;
		x += arr1[m];


		return x;
	}
};