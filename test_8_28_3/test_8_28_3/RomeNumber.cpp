#define _CRT_SECURE_NO_WARNINGS 1
//��������ת����





//��ǰ����һ��һ�������� �����ǰ�ַ��Ⱥ�һ���ַ����ȵĻ���ֱ�Ӽ�
//�����ǰ�ַ��Ⱥ�һ���ַ�С�Ļ���ֱ�Ӽ�
//ע����������ֻ�ܱ����������ڶ����ַ�������Խ�磩�����һ���ַ�ֱ�ӼӾ�OK
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