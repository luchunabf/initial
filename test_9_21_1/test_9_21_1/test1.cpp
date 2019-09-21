#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int FrontCal(string& s)
{
	if (!s.empty())
	{
		stack<int> st;
		for (int i = s.size() - 1; i >= 0; --i)
		{
			if (s[i] >= '0' && s[i] <= '9')
				st.push(s[i] - '0');
			else if (s[i] == '+')
			{
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				int ret = a + b;
				st.push(ret);
			}
			else if ( s[i] == '-')
			{
				
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				int ret = a - b;
				st.push(ret);

			}
			else if (s[i] == '*')
			{
				
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				int ret = a * b;
				st.push(ret);

			}
		}
		return st.top();
	}
}

int main()
{
	string s("+*35-96");
	string s1("+-*4569");
	cout << FrontCal(s) << endl;;
	cout << FrontCal(s1) << endl;;

	return 0;
}



