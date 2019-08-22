#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	//map<int, string> m;
	//m.insert(pair<int, string>(0,"张三"));
	//m.insert(make_pair(1, "李四"));
	//cout << m.size() << endl;

	//for (auto& e : m)
	//	cout << e.first << "--->" << e.second << endl;

	map<string, string> m;
	m.insert(pair<string, string>("zhangsan", "张三"));
	m.insert(make_pair("lisi", "李四"));
	cout << m.size() << endl;
	cout << m["zhangsan"] << endl;
	//cout << m[0] << endl; 不可
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	auto ret = m.insert(make_pair("lisi", "李4"));
	if (ret.second)
	{
		cout << "在map中" << endl;

	}
	else
	{
		cout << "已经存在" << ret.first->first << "--->" << ret.first->second << endl;
	}
	m.insert(make_pair("wangwu", "王五"));
	m.erase("lisi");
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	return 0;
}