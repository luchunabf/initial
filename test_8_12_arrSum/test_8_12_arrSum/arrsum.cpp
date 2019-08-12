#define _CRT_SECURE_NO_WARNINGS 1
//连续子数组最大和
#include <iostream>
#include <vector>
using namespace std;
//一句话，用count保存连续数组的和，当count>=0 不管数组元素正负，无条件加给count，
//								   当count<0了,让count= v[i],重新加
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		int count = v[0];//count和maxcount初始化都是从数组第一个元素（下标为0）开始，然后数组从第二个元素（下标为1）开始遍历整个数组
		int maxcount = v[0];
		//for (int i = 0; i < n; ++i)
		for (int i = 1; i < n; ++i)//这里要从1开始
		{
			if (count >= 0)
			{
				count += v[i];
			}
			else
			{
				count = v[i];
			}
			if (maxcount < count)
				maxcount = count;
		}
		cout << maxcount << endl;
	}
	return 0;
}




#define _CRT_SECURE_NO_WARNINGS 1
//连续子数组最大和
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		int count = v[0];
		int maxcount = v[0];
		for (int i = 1; i < n; ++i)
		{
			count = (count >= 0) ? count + v[i] : v[i];
			maxcount = count < maxcount ? maxcount : count;
		}
		cout << maxcount << endl;
	}
	return 0;
}