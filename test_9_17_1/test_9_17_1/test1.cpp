#define _CRT_SECURE_NO_WARNINGS 1
#include <map>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	map<string, int> m;
	m.insert(pair<string, int>("apple", 1));
	m.insert(make_pair("bnana", 2));

	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "-->" << it->second << endl;
		++it;
	}
	return 0;
}