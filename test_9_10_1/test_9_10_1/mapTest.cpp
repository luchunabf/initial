#define _CRT_SECURE_NO_WARNINGS 1
#include <map>
#include <string>
#include <iostream>
using namespace std;

#if 0
int main()
{
	map<string, string> m;

	m.insert(pair<string, string>("first", "张三"));
	m.insert(make_pair("second", "李四"));


	m["third"] = "王五";
	m["first"] = "钱六";


	m.erase("first");

	m.insert(pair<string, string>("first", "1"));

	map<string, string>::iterator it = m.begin();
	for (auto& e : m)
	{
		cout << e.first << "-->" << e.second << endl;
	}
	cout << endl;

	cout << "apple的count: " << m.count("apple") << endl;
	cout << "second的count: " << m.count("second") << endl;


	return 0;
}
#endif


int main()
{
	map<string, string> m;

	m.insert(pair<string, string>("first", "apple"));
	m.insert(make_pair("second", "peach"));
	m["third"] = "grape";

	/*map<string, string>::iterator it = m.begin();
	for (auto& e : m)
	{
		cout << e.first << "-->" << e.second << endl;
	}
	cout << m.count("first") << endl;

	m.erase("first");
	auto it1 = m.begin();
	for (auto& e : m)
	{
		cout << e.first << "-->" << e.second << endl;
	}
	cout << m.count("first");*/

	cout << "size =  " << m.size() << endl;
	map<string, string>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "-->" << it->second << endl;
		++it;
	}
	cout << endl;

	m.clear();

	auto it1 = m.begin();
	while (it1 != m.end())
	{
		cout << it1->first << "-->" << it1->second << endl;
		++it1;
	}
	cout << "size = " << m.size() << endl;
	
	
	return 0;
}
