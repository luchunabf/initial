#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#if 0
class per
{
public:

	int _a;
};

int main()
{
	per m;
	m._a = 1;
	per* p = new per;
	p->_a = 2;
	return 0;
}
#endif
void  funA()
{
	char a[1024 * 1024 * 1024] = { 0 };
}
void  funB()
{
	char* a = new char[1024 * 1024 * 1024];
	delete[] a;
}


int func(int x)
{
	int count = 0;
	while (x)
	{
		count++;
		x = x&(x - 1);
		
	}
	return count;
}
int main()
{
	/*int n[][3] = { 10, 20, 30, 40, 50, 60 };
	int(*p)[3];
	p = n;
	cout << p[0][0] << "," << *(p[0] + 1) << "," << (*p)[2] << endl;
	return 0;*/
	int z = func(15);
	return 0;
}