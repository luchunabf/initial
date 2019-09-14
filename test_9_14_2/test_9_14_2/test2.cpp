#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;

int main()
{
	map<string, string> m;
	m.insert(pair<string, string>("first", "zc"));
	m.insert(make_pair("second", "wc"));
	m.insert(make_pair("third", "vd"));

	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "-->" << it->second << endl;
		++it;
	}

	m.erase("third");

	it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "-->" << it->second << endl;
		++it;
	}
	
	cout << m["first"] << endl;//stringÒª¼Ó""

	/*for (auto e : m)
	{
	cout << e.first;
	}*/
	return 0;
}