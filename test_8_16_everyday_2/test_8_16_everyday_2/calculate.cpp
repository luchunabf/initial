//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		string s;
//		s.resize(n);
//		int count = 0;
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> s[i];
//			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
//				count++;
//		}
//
//		while (count--)
//		{
//			for (int i = 0; i < n; ++i)
//			{
//				if (s[i] == '+')
//				{
//					s[i - 2] = s[i - 2] + s[i - 1];
//					while (i + 1 < n)
//					{
//						s[i - 1] = s[i + 1];
//						i++;
//					}
//					s[i] = '0';
//					s[i + 1] = '0';
//					break;
//				}
//				else if (s[i] == '-')
//				{
//					s[i - 2] = s[i - 2] - s[i - 1];
//					while (i + 1 < n)
//					{
//						s[i - 1] = s[i + 1];
//						i++;
//					}
//					s[i] = '0';
//					s[i + 1] = '0';
//					break;
//				}
//				else if (s[i] == '*')
//				{
//					s[i - 2] = s[i - 2] * s[i - 1];
//					while (i + 1 < n)
//					{
//						s[i - 1] = s[i + 1];
//						i++;
//					}
//					s[i] = '0';
//					s[i + 1] = '0';
//					break;
//				}
//				else if (s[i] == '/')
//				{
//					s[i - 2] = s[i - 2] / s[i - 1];
//					while (i + 1 < n)
//					{
//						s[i - 1] = s[i + 1];
//						i++;
//					}
//					s[i] = '0';
//					s[i + 1] = '0';
//					break;
//				}
//			}
//		}
//		cout << (s[0] - 48) << endl;
//	}
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<char> v(5);
	cin >> v[0];
	cin >> v[1];
	cin >> v[2];
	cin >> v[3];
	cin >> v[4];
	for (auto e : v)
		cout << e << " ";
	/*int n;
	while (cin >> n)
	{
		vector<int> v;
		v.resize(n);
		int count = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
			if (v[i] == '+' || v[i] == '-' || v[i] == '*' || v[i] == '/')
				count++;
		}

		while (count--)
		{
			for (int i = 0; i < n; ++i)
			{
				if (v[i] == '+')
				{
					v[i - 2] = v[i - 2] + v[i - 1];
					while (i + 1 < n)
					{
						v[i - 1] = v[i + 1];
						i++;
					}
					v[i] = '0';
					v[i + 1] = '0';
					break;
				}
				else if (v[i] == '-')
				{
					v[i - 2] = v[i - 2] - v[i - 1];
					while (i + 1 < n)
					{
						v[i - 1] = v[i + 1];
						i++;
					}
					v[i] = '0';
					v[i + 1] = '0';
					break;
				}
				else if (v[i] == '*')
				{
					v[i - 2] = v[i - 2] * v[i - 1];
					while (i + 1 < n)
					{
						v[i - 1] = v[i + 1];
						i++;
					}
					v[i] = '0';
					v[i + 1] = '0';
					break;
				}
				else if (v[i] == '/')
				{
					v[i - 2] = v[i - 2] / v[i - 1];
					while (i + 1 < n)
					{
						v[i - 1] = v[i + 1];
						i++;
					}
					v[i] = '0';
					v[i + 1] = '0';
					break;
				}
			}
		}
		cout << v[0] << endl;
	}*/
	return 0;
}


