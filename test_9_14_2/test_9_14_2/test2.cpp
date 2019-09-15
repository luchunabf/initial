#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
using namespace std;

#if 0
int main()
{
	map<string, string> m;
	m.insert(pair<string, string>("first", "zc"));
	m.insert(make_pair("second", "wc"));
	m.insert(make_pair("third", "vd"));

	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "-->" << it->second << endl;///////////////
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
#endif

int main()
{
	//set<string> s;
	/*s.insert("apple");
	s.insert("peach");
	s.insert("peer");

	auto it = s.begin();
	while (it != s.end())
	{
	cout << *it << endl;
	++it;
	}

	s.erase("peer");

	for (auto e : s)
	{
	cout << e << endl;
	}*/
	/*set<int> s;
	vector<int> v{ 5, 3, 4, 7, 9, 6, 1, 2, 8, 0 };
	for (int i = 0; i < v.size(); ++i)
	{
		s.insert(v[i]);
	}

	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;*/

	vector<int> v{ 5, 3, 4, 7, 9, 6, 1, 2, 8, 0 };
	set<int> s(v.begin(), v.end());
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	return 0;
}