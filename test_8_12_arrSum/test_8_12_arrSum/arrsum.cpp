#define _CRT_SECURE_NO_WARNINGS 1
//��������������
#include <iostream>
#include <vector>
using namespace std;
//һ�仰����count������������ĺͣ���count>=0 ��������Ԫ���������������Ӹ�count��
//								   ��count<0��,��count= v[i],���¼�
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
		int count = v[0];//count��maxcount��ʼ�����Ǵ������һ��Ԫ�أ��±�Ϊ0����ʼ��Ȼ������ӵڶ���Ԫ�أ��±�Ϊ1����ʼ������������
		int maxcount = v[0];
		//for (int i = 0; i < n; ++i)
		for (int i = 1; i < n; ++i)//����Ҫ��1��ʼ
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
//��������������
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