#define _CRT_SECURE_NO_WARNINGS 1
#include <set>
#include <iostream>
using namespace std;

int main()
{
	int arr[] = { 5, 1, 3, 7, 9, 4, 8, 6, 2, 0 };
	set<int> s(arr, arr + 10);
	
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << endl;
		++it;
	}


	cout << s.size()<< endl;

	s.insert(31);
	s.insert(16);
	s.insert(30);

	cout << s.erase(12) << endl;

	cout << s.erase(31) << endl;
	cout << s.size() << endl;

	return 0;
}