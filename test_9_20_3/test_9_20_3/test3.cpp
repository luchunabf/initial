#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int begin, end, n;
	while (cin >> begin >> end >> n)
	{
		if (n < 2)
		{
			cout << 0 << endl;
			continue;
		}
		//��1:2:3 ��1�Ĵ�С����Ӧ�������2 �� 3 �Ĵ�С
		int count = 0;
		count += ((n - 1) / 3) * 6;
		if ((n - 1) % 3 == 1)
			count += 1;
		else if ((n - 1) % 3 == 2)
			count += 3;
		//Ȼ����������ֵ��С��������1:2:3 ��1�Ĵ�С��
		double m = end - begin;//����ܲ�ֵ
		double d = m / count;//��1:2:3 ��1�Ĵ�С
		double d2 = d * 2;//��1:2:3 ��2�Ĵ�С
		double d3 = d * 3;//��1:2:3 ��3�Ĵ�С
		//������������Ҫ�����������
		vector<double> v(n);
		v[0] = (double)begin;
		v[n - 1] = (double)end;
		for (int i = 1; i < n - 1; ++i)
		{
			if (i % 3 == 1)
				v[i] = v[i - 1] + d;
			else if (i % 3 == 2)
				v[i] = v[i - 1] + d2;
			else
				v[i] = v[i - 1] + d3;
		}
		//��������������鼴��
		for (int i = 0; i < v.size() - 1; ++i)
		{
			printf("%0.2lf,", v[i]);
		}
		printf("%0.2lf", v[n - 1]);
	}
	return 0;
}
