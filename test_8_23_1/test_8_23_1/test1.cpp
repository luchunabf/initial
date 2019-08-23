#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <set>
using namespace std;

#if 0
int main()
{
	int array[] = { 5, 9, 8, 7, 6, 4, 1, 3, 8, 1, 54, 7, 6, 4, 12, 3, 6, 9, 4 };
	set<int> s(array, array + sizeof(array) / sizeof(array[0]));
	cout << s.size() << endl;

	for (auto e : s)
		cout << e << " ";
	cout << endl;

	for (auto it = s.rbegin(); it != s.rend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}
#endif

int main()
{
	int array[] = { 5, 9, 8, 7, 6, 4, 1, 3, 8, 1, 54, 7, 6, 4, 12, 3, 6, 9, 4 };
	multiset<int> s(array, array + sizeof(array) / sizeof(array[0]));
	cout << s.size() << endl;

	for (auto e : s)
		cout << e << " ";
	cout << endl;

	for (auto it = s.rbegin(); it != s.rend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}