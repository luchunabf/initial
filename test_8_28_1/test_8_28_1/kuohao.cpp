#define _CRT_SECURE_NO_WARNINGS 1
#include <stack>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		stack<char> s1;
		if (s.empty()) return true;
		if (s.size() % 2 != 0) return false;
		for (int i = 0; i < s.size(); ++i)
		{
			//ջΪ��ʱ��ֱ���������ţ�������������ֳ�����û��ͨ��
			if (s1.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}'))
				return false;
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				s1.push(s[i]);
			else
			{
				if (s[i] - s1.top() == 1 || s[i] - s1.top() == 2)//�����ź������ŵ�ƥ�䷽ʽ���ǡ�
					s1.pop();
				else
					return false;
			}
		}
		//return s1.empty();
		if (s1.empty()) return true;
		else return false;
	}
};

int main()
{
	Solution a;
	string t{ "()[]{}" };
	cout << a.isValid(t);
	return 0;
}