#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	//map<int, string> m;
	//m.insert(pair<int, string>(0,"����"));
	//m.insert(make_pair(1, "����"));
	//cout << m.size() << endl;

	//for (auto& e : m)
	//	cout << e.first << "--->" << e.second << endl;

	map<string, string> m;
	m.insert(pair<string, string>("zhangsan", "����"));
	m.insert(make_pair("lisi", "����"));
	cout << m.size() << endl;
	cout << m["zhangsan"] << endl;
	//cout << m[0] << endl; ����
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	auto ret = m.insert(make_pair("lisi", "��4"));
	if (ret.second)
	{
		cout << "��map��" << endl;

	}
	else
	{
		cout << "�Ѿ�����" << ret.first->first << "--->" << ret.first->second << endl;
	}
	m.insert(make_pair("wangwu", "����"));
	m.erase("lisi");
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	return 0;
}